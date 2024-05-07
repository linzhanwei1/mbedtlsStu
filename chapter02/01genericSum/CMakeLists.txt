# mbedtlsStu/chapter02/01genericSum/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("genericSum" LANGUAGES C)

find_package(MbedTLS PATHS "${CMAKE_CURRENT_LIST_DIR}/../../mbedtlsLib/")
add_executable(${PROJECT_NAME} generic_sum.c)
target_link_libraries(${PROJECT_NAME} PUBLIC 
    MbedTLS::mbedcrypto
    MbedTLS::mbedtls
    # MbedTLS::mbedx509
)