#include "mbedtls/build_info.h"

#if defined(MBEDTLS_PLATFORM_C)
#    include "mbedtls/platform.h"
#else
#    include <stdio.h>
#    include <stdlib.h>
#    define mbedtls_fprintf fprintf
#    define mbedtls_printf printf
#    define mbedtls_snprintf snprintf
#    define mbedtls_exit exit
#    define MBEDTLS_EXIT_SUCCESS EXIT_SUCCESS
#    define MBEDTLS_EXIT_FAILURE EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */

#include "mbedtls/rsa.h"
#include "mbedtls/md.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *f;
    int ret = 1;
    int exit_code = MBEDTLS_EXIT_FAILURE;
    size_t i;
    mbedtls_rsa_context rsa;
    unsigned char hash[32];
    unsigned char buf[MBEDTLS_MPI_MAX_SIZE];
    char filename[512];
    mbedtls_mpi N, P, Q, D, E, DP, DQ, QP;
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    const char *pers = "rsa_sign";

    mbedtls_ctr_drbg_init(&ctr_drbg);
    mbedtls_entropy_init(&entropy);

    ret = mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy, (const unsigned char *)pers, strlen(pers));
    if (ret != 0) {
        mbedtls_printf(" failed\n  ! mbedtls_ctr_drbg_seed returned %d\n", ret);
        goto exit;
    }

    mbedtls_rsa_init(&rsa);

    mbedtls_mpi_init(&N);
    mbedtls_mpi_init(&P);
    mbedtls_mpi_init(&Q);
    mbedtls_mpi_init(&D);
    mbedtls_mpi_init(&E);
    mbedtls_mpi_init(&DP);
    mbedtls_mpi_init(&DQ);
    mbedtls_mpi_init(&QP);

    if (argc != 2) {
        mbedtls_printf("usage: rsa_sign <filename>\n");

#if defined(_WIN32)
        mbedtls_printf("\n");
#endif

        goto exit;
    }

    mbedtls_printf("\n  . Reading private key from rsa_priv.txt");
    fflush(stdout);

    if ((f = fopen("rsa_priv.txt", "rb")) == NULL) {
        mbedtls_printf(" failed\n  ! Could not open rsa_priv.txt\n"
                       "  ! Please run rsa_genkey first\n\n");
        goto exit;
    }

    if ((ret = mbedtls_mpi_read_file(&N, 16, f)) != 0 || (ret = mbedtls_mpi_read_file(&E, 16, f)) != 0 || (ret = mbedtls_mpi_read_file(&D, 16, f)) != 0 || (ret = mbedtls_mpi_read_file(&P, 16, f)) != 0
        || (ret = mbedtls_mpi_read_file(&Q, 16, f)) != 0 || (ret = mbedtls_mpi_read_file(&DP, 16, f)) != 0 || (ret = mbedtls_mpi_read_file(&DQ, 16, f)) != 0
        || (ret = mbedtls_mpi_read_file(&QP, 16, f)) != 0) {
        mbedtls_printf(" failed\n  ! mbedtls_mpi_read_file returned %d\n\n", ret);
        fclose(f);
        goto exit;
    }
    fclose(f);

    if ((ret = mbedtls_rsa_import(&rsa, &N, &P, &Q, &D, &E)) != 0) {
        mbedtls_printf(" failed\n  ! mbedtls_rsa_import returned %d\n\n", ret);
        goto exit;
    }

    if ((ret = mbedtls_rsa_complete(&rsa)) != 0) {
        mbedtls_printf(" failed\n  ! mbedtls_rsa_complete returned %d\n\n", ret);
        goto exit;
    }

    mbedtls_printf("\n  . Checking the private key");
    fflush(stdout);
    if ((ret = mbedtls_rsa_check_privkey(&rsa)) != 0) {
        mbedtls_printf(" failed\n  ! mbedtls_rsa_check_privkey failed with -0x%0x\n", (unsigned int)-ret);
        goto exit;
    }

    /* Compute the SHA-256 hash of the input file, then calculate the RSA signature of the hash. */
    mbedtls_printf("\n . Generating the RSA/SHA-256 signature");
    fflush(stdout);

    if ((ret = mbedtls_md_file(mbedtls_md_info_from_type(MBEDTLS_MD_SHA256), argv[1], hash)) != 0) {
        mbedtls_printf(" failed\n ! Could not open or read %s\n\n", argv[1]);
        goto exit;
    }

    if ((ret = mbedtls_rsa_pkcs1_sign(&rsa, mbedtls_ctr_drbg_random, &ctr_drbg, MBEDTLS_MD_SHA256, 32, hash, buf)) != 0) {
        mbedtls_printf(" failed\n ! mbedtls_rsa_pkcs1_sign returned -0x%0x\n\n", (unsigned int)-ret);
        goto exit;
    }

    /* Write the signature into <filename>.sig */
    mbedtls_snprintf(filename, sizeof(filename), "%s.sig", argv[1]);

    if ((f = fopen(filename, "wb+")) == NULL) {
        mbedtls_printf(" failed\n ! Could not create %s\n\n", argv[1]);
        goto exit;
    }

    for (i = 0; i < rsa.MBEDTLS_PRIVATE(len); i++)
        mbedtls_fprintf(f, "%02X%s", buf[i], (i + 1) % 16 == 0 ? "\r\n" : " ");

    fclose(f);
    mbedtls_printf("\n . Done (created \"%s\")\n\n", filename);
    exit_code = MBEDTLS_EXIT_SUCCESS;

exit:

    mbedtls_rsa_free(&rsa);
    mbedtls_mpi_free(&N);
    mbedtls_mpi_free(&P);
    mbedtls_mpi_free(&Q);
    mbedtls_mpi_free(&D);
    mbedtls_mpi_free(&E);
    mbedtls_mpi_free(&DP);
    mbedtls_mpi_free(&DQ);
    mbedtls_mpi_free(&QP);
    mbedtls_ctr_drbg_free(&ctr_drbg);
    mbedtls_entropy_free(&entropy);

#if defined(_WIN32)
    mbedtls_printf("  + Press Enter to exit this program.\n");
    fflush(stdout);
    getchar();
#endif

    mbedtls_exit(exit_code);
}
/*
. Reading private key from rsa_priv.txt
  . Checking the private key
  . Generating the RSA/SHA-256 signature failed
  ! mbedtls_rsa_pkcs1_sign returned -0x4080
*/
// 解决办法参考如下：
// https://github.com/Mbed-TLS/mbedtls/issues/5419
// https://github.com/Mbed-TLS/mbedtls/pull/5423/files/43643f62bae362f4454cb2b314789770e5d867ec#diff-b5b613e0b0e6f2a8d16b979d1127474f795b9850c02386999d2e768eb0f01697R54