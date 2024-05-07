# mbedtlsStu/chapter02/02aes/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("crypt_and_hash" LANGUAGES C)

find_package(MbedTLS PATHS "${CMAKE_CURRENT_LIST_DIR}/../../mbedtlsLib/")
add_executable(${PROJECT_NAME} crypt_and_hash.c)
target_link_libraries(${PROJECT_NAME} PUBLIC 
    MbedTLS::mbedcrypto
    MbedTLS::mbedtls
    # MbedTLS::mbedx509
)