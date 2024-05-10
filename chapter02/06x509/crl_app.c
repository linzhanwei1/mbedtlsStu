#include "mbedtls/build_info.h"

#if defined(MBEDTLS_PLATFORM_C)
#    include "mbedtls/platform.h"
#else
#    include <stdio.h>
#    include <stdlib.h>
#    define mbedtls_printf printf
#    define mbedtls_exit exit
#    define MBEDTLS_EXIT_SUCCESS EXIT_SUCCESS
#    define MBEDTLS_EXIT_FAILURE EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */

#include "mbedtls/x509_crl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DFL_FILENAME "crl.pem"
#define DFL_DEBUG_LEVEL 0

#define USAGE                                                                                                                                                                                          \
    "\n usage: crl_app param=<>...\n"                                                                                                                                                                  \
    "\n acceptable parameters:\n"                                                                                                                                                                      \
    "    filename=%%s         default: crl.pem\n"                                                                                                                                                      \
    "\n"

/* global options */
struct options {
    const char *filename; /* filename of the certificate file     */
} opt;

int main(int argc, char *argv[])
{
    int ret = 1;
    int exit_code = MBEDTLS_EXIT_FAILURE;
    unsigned char buf[100000];
    mbedtls_x509_crl crl;
    int i;
    char *p, *q;

    /* Set to sane values */
    mbedtls_x509_crl_init(&crl);

    if (argc == 0) {
    usage:
        mbedtls_printf(USAGE);
        goto exit;
    }

    opt.filename = DFL_FILENAME;

    for (i = 1; i < argc; i++) {
        p = argv[i];
        if ((q = strchr(p, '=')) == NULL)
            goto usage;
        *q++ = '\0';

        if (strcmp(p, "filename") == 0)
            opt.filename = q;
        else
            goto usage;
    }

    /* 1.1 Load the CRL */
    mbedtls_printf("\n  . Loading the CRL ...");
    fflush(stdout);

    ret = mbedtls_x509_crl_parse_file(&crl, opt.filename);
    if (ret != 0) {
        mbedtls_printf(" failed\n  !  mbedtls_x509_crl_parse_file returned %d\n\n", ret);
        mbedtls_x509_crl_free(&crl);
        goto exit;
    }
    mbedtls_printf(" ok\n");

    /* 1.2 Print the CRL */
    mbedtls_printf("  . CRL information    ...\n");
    ret = mbedtls_x509_crl_info((char *)buf, sizeof(buf) - 1, "      ", &crl);
    if (ret == -1) {
        mbedtls_printf(" failed\n  !  mbedtls_x509_crl_info returned %d\n\n", ret);
        mbedtls_x509_crl_free(&crl);
        goto exit;
    }

    mbedtls_printf("%s\n", buf);

    exit_code = MBEDTLS_EXIT_SUCCESS;

exit:
    mbedtls_x509_crl_free(&crl);

#if defined(_WIN32)
    mbedtls_printf("  + Press Enter to exit this program.\n");
    fflush(stdout);
    getchar();
#endif

    mbedtls_exit(exit_code);
}