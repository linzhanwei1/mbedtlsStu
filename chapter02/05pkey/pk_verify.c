#include "mbedtls/build_info.h"

#if defined(MBEDTLS_PLATFORM_C)
#    include "mbedtls/platform.h"
#else
#    include <stdio.h>
#    include <stdlib.h>
#    define mbedtls_snprintf snprintf
#    define mbedtls_printf printf
#    define mbedtls_exit exit
#    define MBEDTLS_EXIT_SUCCESS EXIT_SUCCESS
#    define MBEDTLS_EXIT_FAILURE EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */

#include "mbedtls/error.h"
#include "mbedtls/md.h"
#include "mbedtls/pk.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *f;
    int ret = 1;
    int exit_code = MBEDTLS_EXIT_FAILURE;
    size_t i;
    mbedtls_pk_context pk;
    unsigned char hash[32];
    unsigned char buf[MBEDTLS_PK_SIGNATURE_MAX_SIZE];
    char filename[512];

    mbedtls_pk_init(&pk);

    if (argc != 3) {
        mbedtls_printf("usage: mbedtls_pk_verify <key_file> <filename>\n");

#if defined(_WIN32)
        mbedtls_printf("\n");
#endif

        goto exit;
    }

    mbedtls_printf("\n  . Reading public key from '%s'", argv[1]);
    fflush(stdout);

    if ((ret = mbedtls_pk_parse_public_keyfile(&pk, argv[1])) != 0) {
        mbedtls_printf(" failed\n  ! mbedtls_pk_parse_public_keyfile returned -0x%04x\n", (unsigned int)-ret);
        goto exit;
    }

    /* Extract the signature from the file */
    mbedtls_snprintf(filename, sizeof(filename), "%s.sig", argv[2]);

    if ((f = fopen(filename, "rb")) == NULL) {
        mbedtls_printf("\n  ! Could not open %s\n\n", filename);
        goto exit;
    }

    i = fread(buf, 1, sizeof(buf), f);
    fclose(f);

    /* Compute the SHA-256 hash of the input file and verify the signature */
    mbedtls_printf("\n  . Verifying the SHA-256 signature");
    fflush(stdout);

    if ((ret = mbedtls_md_file(mbedtls_md_info_from_type(MBEDTLS_MD_SHA256), argv[2], hash)) != 0) {
        mbedtls_printf(" failed\n  ! Could not open or read %s\n\n", argv[2]);
        goto exit;
    }

    if ((ret = mbedtls_pk_verify(&pk, MBEDTLS_MD_SHA256, hash, 0, buf, i)) != 0) {
        mbedtls_printf(" failed\n  ! mbedtls_pk_verify returned -0x%04x\n", (unsigned int)-ret);
        goto exit;
    }

    mbedtls_printf("\n  . OK (the signature is valid)\n\n");

    exit_code = MBEDTLS_EXIT_SUCCESS;

exit:
    mbedtls_pk_free(&pk);

#if defined(MBEDTLS_ERROR_C)
    if (exit_code != MBEDTLS_EXIT_SUCCESS) {
        mbedtls_strerror(ret, (char *)buf, sizeof(buf));
        mbedtls_printf("  !  Last error was: %s\n", buf);
    }
#endif

#if defined(_WIN32)
    mbedtls_printf("  + Press Enter to exit this program.\n");
    fflush(stdout);
    getchar();
#endif

    mbedtls_exit(exit_code);
}