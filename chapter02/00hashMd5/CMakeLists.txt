# mbedtlsStu/chapter02/00hashMd5/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("hello" LANGUAGES C)

find_package(MbedTLS PATHS "${CMAKE_CURRENT_LIST_DIR}/../../mbedtlsLib/")
add_executable(${PROJECT_NAME} hello.c)
target_link_libraries(${PROJECT_NAME} PUBLIC 
    MbedTLS::mbedcrypto
    MbedTLS::mbedtls
    # MbedTLS::mbedx509
)