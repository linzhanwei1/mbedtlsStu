# mbedtlsStu/chapter02/04ctrDrbg/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("gen_random_ctr_drbg" LANGUAGES C)

find_package(MbedTLS PATHS "${CMAKE_CURRENT_LIST_DIR}/../../mbedtlsLib/")
add_executable(${PROJECT_NAME} gen_random_ctr_drbg.c)
target_link_libraries(${PROJECT_NAME} PUBLIC 
    MbedTLS::mbedcrypto
    MbedTLS::mbedtls
    # MbedTLS::mbedx509
)