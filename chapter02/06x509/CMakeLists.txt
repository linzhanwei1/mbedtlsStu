# mbedtlsStu/chapter02/06x509/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("x509" LANGUAGES C)

function(add_app name)
    add_executable(${name} "${name}.c")
    target_link_libraries(${name} PUBLIC MbedTLS::mbedcrypto MbedTLS::mbedtls)
endfunction()

find_package(MbedTLS PATHS "${CMAKE_CURRENT_LIST_DIR}/../../mbedtlsLib/")

# Certificate generation and signing
add_app(cert_write)

# Certificate reading application
add_app(cert_app)

# CRL reading application
add_app(crl_app)

# Certificate request generation
add_app(cert_req)

# Certificate request reading application
add_app(req_app)