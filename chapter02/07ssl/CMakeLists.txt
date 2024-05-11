# mbedtlsStu/chapter02/07ssl/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("x509" LANGUAGES C)

function(add_app name)
    add_executable(${name} "${name}.c")
    target_link_libraries(${name} PUBLIC MbedTLS::mbedcrypto MbedTLS::mbedtls)
endfunction()

find_package(MbedTLS PATHS "${CMAKE_CURRENT_LIST_DIR}/../../mbedtlsLib/")

# Minimal SSL client, used for memory measurements.
add_app(mini_client)

# SSL server demonstration program
add_executable(ssl_server ssl_server.c certs.c)
target_link_libraries(ssl_server PUBLIC MbedTLS::mbedcrypto MbedTLS::mbedtls)

# SSL client demonstration program
add_executable(ssl_client1 ssl_client1.c certs.c)
target_link_libraries(ssl_client1 PUBLIC MbedTLS::mbedcrypto MbedTLS::mbedtls)
