# mbedtlsStu/chapter00/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(first)

set(MbedTLS_DIR "${CMAKE_CURRENT_LIST_DIR}/../mbedtlsLib/")

find_package(MbedTLS PATHS ${MbedTLS_DIR})

if(MbedTLS_DIR)
    message(STATUS "find MbedTLS success.")
else()
    message(WARNING "find MbedTLS failed.")
endif()

add_executable(${PROJECT_NAME} first.c)
target_link_libraries(${PROJECT_NAME} PUBLIC MbedTLS::mbedcrypto)