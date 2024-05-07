# mbedtlsStu/chapter02/03random/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("gen_entropy" LANGUAGES C)

find_package(MbedTLS PATHS "${CMAKE_CURRENT_LIST_DIR}/../../mbedtlsLib/")
add_executable(${PROJECT_NAME} gen_entropy.c)
target_link_libraries(${PROJECT_NAME} PUBLIC 
    MbedTLS::mbedcrypto
    MbedTLS::mbedtls
    # MbedTLS::mbedx509
)