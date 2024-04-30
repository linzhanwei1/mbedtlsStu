# mbedtlsStu/chapter01/01cipherSuiteMini/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("ciphersuite_list_mini")

# 依赖工程源代码 ../../../download/mbedtls/library/
set(MBEDTLS_SOURCE_DIR "../../../download/mbedtls/")
aux_source_directory("${MBEDTLS_SOURCE_DIR}/library/" MBEDTLS_SOURCE)
set(SOURCES ${CMAKE_CURRENT_LIST_DIR}/ciphersuite_list_mini.c ${MBEDTLS_SOURCE})

add_executable(${PROJECT_NAME} ${SOURCES})
# coustom mbedtls config file
target_compile_definitions(${PROJECT_NAME} PRIVATE MBEDTLS_CONFIG_FILE=<config-suite-b.h>)
target_include_directories(${PROJECT_NAME} PRIVATE "./" "${MBEDTLS_SOURCE_DIR}/include")
