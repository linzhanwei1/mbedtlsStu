#include "mbedtls/build_info.h"

#if defined(MBEDTLS_PLATFORM_C)
#    include "mbedtls/platform.h"
#else
#    include <stdio.h>
#    include <stdlib.h>
#    define mbedtls_fprintf fprintf
#    define mbedtls_printf printf
#    define mbedtls_exit exit
#    define MBEDTLS_EXIT_SUCCESS EXIT_SUCCESS
#    define MBEDTLS_EXIT_FAILURE EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */

#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_RSA_C) && defined(MBEDTLS_ENTROPY_C) && defined(MBEDTLS_FS_IO) && defined(MBEDTLS_CTR_DRBG_C)
#    include "mbedtls/rsa.h"
#    include "mbedtls/entropy.h"
#    include "mbedtls/ctr_drbg.h"

#    include <string.h>
#endif

int main(int argc, char *argv[])
{
    FILE *f;
    int ret = 1;
    int exit_code = MBEDTLS_EXIT_FAILURE;
    size_t i;
    mbedtls_rsa_context rsa;
    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    unsigned char input[1024];
    unsigned char buf[512];
    const char *pers = "rsa_encrypt";
    mbedtls_mpi N, E;

    if (argc != 2) {
        mbedtls_printf("usage: rsa_encrypt <string of max 100 characters>\n");
#if defined(_WIN32)
        mbedtls_printf("\n");
#endif
        mbedtls_exit(exit_code);
    }

    mbedtls_printf("\n  . Seeding the random number generator...");
    fflush(stdout);

    mbedtls_mpi_init(&N);
    mbedtls_mpi_init(&E);
    mbedtls_rsa_init(&rsa);
    mbedtls_ctr_drbg_init(&ctr_drbg);
    mbedtls_entropy_init(&entropy);

    if ((ret = mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy, (const unsigned char *)pers, strlen(pers))) != 0) {
        mbedtls_printf(" failed\n  ! mbedtls_ctr_drbg_seed returned %d\n", ret);
        goto exit;
    }

    mbedtls_printf("\n . Reading public key from rsa_pub.txt");
    fflush(stdout);

    if ((f = fopen("rsa_pub.txt", "rb")) == NULL) {
        mbedtls_printf(" failed\n ! Could not open rsa_pub.txt\n ! Please run ras_genkey first\n\n");
        goto exit;
    }

    if ((ret = mbedtls_mpi_read_file(&N, 16, f)) != 0 || (ret = mbedtls_mpi_read_file(&E, 16, f)) != 0) {
        mbedtls_printf(" failed\n ! mbedtls_rsa_import returned %d\n\n", ret);
        fclose(f);
        goto exit;
    }

    if ((ret = mbedtls_rsa_import(&rsa, &N, NULL, NULL, NULL, &E)) != 0) {
        mbedtls_printf(" failed\n ! mbedtls_rsa_import returned %d\n\n", ret);
        goto exit;
    }

    if (strlen(argv[1]) > 100) {
        mbedtls_printf(" Input data larger than 100 characters.\n\n");
        goto exit;
    }

    memcpy(input, argv[1], strlen(argv[1]));

    /* Calculate the RSA encryption of the hash. */
    mbedtls_printf("\n . Generating the RSA encrypted value");
    fflush(stdout);

    ret = mbedtls_rsa_pkcs1_encrypt(&rsa, mbedtls_ctr_drbg_random, &ctr_drbg, strlen(argv[1]), input, buf);
    if (ret != 0) {
        mbedtls_printf(" failed\n ! mbedtls_rsa_pkcs1_encrypt returned %d\n\n", ret);
        goto exit;
    }

    /* Write the signature into result-enc.txt */
    if ((f = fopen("result-enc.txt", "wb+")) == NULL) {
        mbedtls_printf(" failed\n ! Could not create %s\n\n", "result_enc.txt");
        goto exit;
    }

    for (i = 0; i < rsa.MBEDTLS_PRIVATE(len); i++)
        mbedtls_fprintf(f, "%02X%s", buf[i], (i + 1) % 16 == 0 ? "\r\n" : " ");

    fclose(f);
    mbedtls_printf("\n . Done (created \"%s\")\n\n", "result-enc.txt");
    exit_code = MBEDTLS_EXIT_SUCCESS;

exit:
    mbedtls_mpi_free(&N);
    mbedtls_mpi_free(&E);
    mbedtls_ctr_drbg_free(&ctr_drbg);
    mbedtls_entropy_free(&entropy);
    mbedtls_rsa_free(&rsa);

#if defined(_WIN32)
    mbedtls_printf("  + Press Enter to exit this program.\n");
    fflush(stdout);
    getchar();
#endif
    mbedtls_exit(exit_code);
}