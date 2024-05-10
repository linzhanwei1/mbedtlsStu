# mbedtlsStu/chapter02/05pkey/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project("pkey" LANGUAGES C)

function(add_app name)
    add_executable(${name} "${name}.c")
    target_link_libraries(${name} PUBLIC MbedTLS::mbedcrypto MbedTLS::mbedtls)
endfunction()

find_package(MbedTLS PATHS "${CMAKE_CURRENT_LIST_DIR}/../../mbedtlsLib/")

# Example RSA key generation program
add_app(rsa_genkey)

# RSA simple data encryption program
add_app(rsa_encrypt)

# RSA simple decryption program
add_app(rsa_decrypt)

# RSA/SHA-256 signature creation program
add_app(rsa_sign)

# RSA/SHA-256 signature verification program
add_app(rsa_verify)

# Key generation application
add_app(gen_key)

# Key reading application
add_app(key_app)

# Key writing application
add_app(key_app_writer)

# RSA simple data encryption program
add_app(pk_encrypt)

# Public key-based simple decryption program
add_app(pk_decrypt)

# Public key-based signature creation program
add_app(pk_sign)

# Public key-based signature verification program
add_app(pk_verify)

# RSASSA-PSS/SHA-256 signature creation program
add_app(rsa_sign_pass)

# RSASSA-PSS/SHA-256 signature verification program
add_app(rsa_verify_pass)

# Diffie-Hellman-Merkle key exchange (prime generation)
add_app(dh_genprime)

# Diffie-Hellman-Merkle key exchange (server side)
add_app(dh_server)

# Diffie-Hellman-Merkle key exchange (client side)
add_app(dh_client)

# Example ECDSA program
add_app(ecdsa)