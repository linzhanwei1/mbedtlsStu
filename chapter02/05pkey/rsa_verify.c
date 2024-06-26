#include "mbedtls/build_info.h"

#if defined(MBEDTLS_PLATFORM_C)
#    include "mbedtls/platform.h"
#else
#    include <stdio.h>
#    include <stdlib.h>
#    define mbedtls_printf printf
#    define mbedtls_snprintf snprintf
#    define mbedtls_exit exit
#    define MBEDTLS_EXIT_SUCCESS EXIT_SUCCESS
#    define MBEDTLS_EXIT_FAILURE EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */

#include "mbedtls/rsa.h"
#include "mbedtls/md.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *f;
    int ret = 1;
    unsigned c;
    int exit_code = MBEDTLS_EXIT_FAILURE;
    size_t i;
    mbedtls_rsa_context rsa;
    unsigned char hash[32];
    unsigned char buf[MBEDTLS_MPI_MAX_SIZE];
    char filename[512];

    mbedtls_rsa_init(&rsa);

    if (argc != 2) {
        mbedtls_printf("usage: rsa_verify <filename>\n");

#if defined(_WIN32)
        mbedtls_printf("\n");
#endif

        goto exit;
    }

    mbedtls_printf("\n  . Reading public key from rsa_pub.txt");
    fflush(stdout);

    if ((f = fopen("rsa_pub.txt", "rb")) == NULL) {
        mbedtls_printf(" failed\n  ! Could not open rsa_pub.txt\n"
                       "  ! Please run rsa_genkey first\n\n");
        goto exit;
    }

    if ((ret = mbedtls_mpi_read_file(&rsa.MBEDTLS_PRIVATE(N), 16, f)) != 0 || (ret = mbedtls_mpi_read_file(&rsa.MBEDTLS_PRIVATE(E), 16, f)) != 0) {
        mbedtls_printf(" failed\n  ! mbedtls_mpi_read_file returned %d\n\n", ret);
        fclose(f);
        goto exit;
    }

    rsa.MBEDTLS_PRIVATE(len) = (mbedtls_mpi_bitlen(&rsa.MBEDTLS_PRIVATE(N)) + 7) >> 3;
    fclose(f);

    /* Extract the RSA  signature from the text file */
    mbedtls_snprintf(filename, sizeof(filename), "%s.sig", argv[1]);

    if ((f = fopen(filename, "rb")) == NULL) {
        mbedtls_printf("\n  ! Could not open %s\n\n", filename);
        goto exit;
    }

    i = 0;
    while (fscanf(f, "%02X", (unsigned int *)&c) > 0 && i < (int)sizeof(buf))
        buf[i++] = (unsigned char)c;
    printf("%02x", c);

    fclose(f);

    if (i != rsa.MBEDTLS_PRIVATE(len)) {
        mbedtls_printf("\n  ! Invalid RSA signature format\n\n");
        goto exit;
    }

    /* Compute the SHA-256 hash of the input file and verify the signature */
    mbedtls_printf("\n  . Verifying the RSA/SHA-256 signature");
    fflush(stdout);

    if ((ret = mbedtls_md_file(mbedtls_md_info_from_type(MBEDTLS_MD_SHA256), argv[1], hash)) != 0) {
        mbedtls_printf(" failed\n  ! Could not open or read %s\n\n", argv[1]);
        goto exit;
    }

    if ((ret = mbedtls_rsa_pkcs1_verify(&rsa, MBEDTLS_MD_SHA256, 32, hash, buf)) != 0) {
        mbedtls_printf(" failed\n  ! mbedtls_rsa_pkcs1_verify returned -0x%0x\n\n", (unsigned int)-ret);
        goto exit;
    }

    mbedtls_printf("\n  . OK (the signature is valid)\n\n");

    exit_code = MBEDTLS_EXIT_SUCCESS;

exit:

    mbedtls_rsa_free(&rsa);

#if defined(_WIN32)
    mbedtls_printf("  + Press Enter to exit this program.\n");
    fflush(stdout);
    getchar();
#endif

    mbedtls_exit(exit_code);
}