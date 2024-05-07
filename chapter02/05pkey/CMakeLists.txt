# mbedtlsStu/chapter02/05pkey/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("pkey" LANGUAGES C)

find_package(MbedTLS PATHS "${CMAKE_CURRENT_LIST_DIR}/../../mbedtlsLib/")

# Example RSA key generation program
add_executable(rsa_genkey rsa_genkey.c)
target_link_libraries(rsa_genkey PUBLIC MbedTLS::mbedcrypto MbedTLS::mbedtls)

# RSA simple data encryption program
add_executable(rsa_encrypt rsa_encrypt.c)
target_link_libraries(rsa_encrypt PUBLIC MbedTLS::mbedcrypto MbedTLS::mbedtls)

# RSA simple decryption program
add_executable(rsa_decrypt rsa_decrypt.c)
target_link_libraries(rsa_decrypt PUBLIC MbedTLS::mbedcrypto MbedTLS::mbedtls)

# RSA/SHA-256 signature creation program
add_executable(rsa_sign rsa_sign.c)
target_link_libraries(rsa_sign PUBLIC MbedTLS::mbedcrypto MbedTLS::mbedtls)

# RSA/SHA-256 signature verification program
add_executable(rsa_verify rsa_verify.c)
target_link_libraries(rsa_verify PUBLIC MbedTLS::mbedcrypto MbedTLS::mbedtls)