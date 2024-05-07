#include "mbedtls/build_info.h"
#if defined(MBEDTLS_PLATFORM_C)
#    include "mbedtls/platform.h"
#else
#    include <stdlib.h>
#    include <stdio.h>
#    define mbedtls_printf printf
#    define mbedtls_exit exit
#    define MBEDTLS_EXIT_SUCCESS EXIT_SUCCESS
#    define MBEDTLS_EXIT_FAILURE EXIT_FAILURE
#endif

#include "mbedtls/md5.h"

int main(void)
{
    int i, ret;
    unsigned char digest[16];
    char str[] = "Hello, world!";

    mbedtls_printf("\n MD5('%s') = ", str);
    if ((ret = mbedtls_md5((unsigned char *)str, 13, digest)) != 0)
        mbedtls_exit(MBEDTLS_EXIT_FAILURE);

    for (i = 0; i < 16; i++)
        mbedtls_printf("%02x", digest[i]);

    mbedtls_printf("\n\n");

#if defined(_WIN32)
    mbedtls_printf(" Press Enter to exit this program.\n");
    fflush(stdout);
    getchar();
#endif

    mbedtls_exit(MBEDTLS_EXIT_SUCCESS);
}