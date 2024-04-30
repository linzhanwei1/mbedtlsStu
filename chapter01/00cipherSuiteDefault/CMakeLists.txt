# mbedtlsStu/chapter01/00cipherSuiteDefault/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("ciphersuite_list_default")

find_package(MbedTLS PATHS "${CMAKE_CURRENT_LIST_DIR}/../../mbedtlsLib/")
add_executable(${PROJECT_NAME} ciphersuite_list_default.c)
target_link_libraries(${PROJECT_NAME} PUBLIC 
    MbedTLS::mbedcrypto
    MbedTLS::mbedtls
    # MbedTLS::mbedx509
)
