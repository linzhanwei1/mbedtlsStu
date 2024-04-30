# mbedtlsStu
## 概述
- mbedtls是一个优秀的开源加密组件，广泛的应用在嵌入式领域。
- 通过本仓库，学习加密套件的使用方法，提供基础的参考资料；
- 记录关键的构建和使用技巧，提供开发指导；
- 个人能力有限，难免有疏漏错误之处，还望读者批评指正。
## 环境部署
- 环境依赖
    + Ubuntu20.4
    + mbedtls_3.0.0
    + cmake version 3.29.2
    + ninja 1.10.0
- mbedtls源码下载
```sh
git clone https://github.com/Mbed-TLS/mbedtls.git
```
- 切换分支
```sh
cd mbedtls
git checkout tags/mbedtls-3.0.0 -b mbedtls-3.0.0
git branch
```
- 使用CMake构建库文件
```sh
cd ..
mkdir mbedtlsBuild
cmake -S mbedtls -B mbedtlsBuild -D USE_SHARED_MBEDTLS_LIBRARY=On -G Ninja
cmake --build mbedtlsBuild/
```
- 使用CMake构建APIdoc(注意生成后在mbedtls源码目录"xxx/mbedtls/apidoc/")
```sh
cmake --build mbedtlsBuild/ --target apidoc
```sh
- 安装mbedtls库文件到指定目录(我安装到了本仓库的"mbedtls/lib/")
```sh
cmake --install mbedtlsBuild --prefix=../mbedtlsStu/mbedtlsLib
```
## 测试mbedtlsLib库
- 详情参见 [chapter00章节代码](./chapter00/)
```sh
cd chapter00
cmake -B build
cmake --build build
./build/first
```

> 控制台输出如下信息，可见基本的学习环境已经搭建完成:<br>
>  MD5('Hello, mbedtls!') = a7bc1487286213a47830f767913f2a93

- 仓库当前的目录拓扑
```sh
.
├── chapter00
│   ├── CMakeLists.txt
│   └── first.c
├── LICENSE
├── mbedtlsLib
│   ├── bin
│   │   ├── benchmark
│   │   ├── cert_app
│   │   ├── cert_req
│   │   ├── cert_write
│   │   ├── crl_app
│   │   ├── crypt_and_hash
│   │   ├── crypto_examples
│   │   ├── dh_client
│   │   ├── dh_genprime
│   │   ├── dh_server
│   │   ├── dtls_client
│   │   ├── dtls_server
│   │   ├── ecdh_curve25519
│   │   ├── ecdsa
│   │   ├── gen_entropy
│   │   ├── generic_sum
│   │   ├── gen_key
│   │   ├── gen_random_ctr_drbg
│   │   ├── hello
│   │   ├── key_app
│   │   ├── key_app_writer
│   │   ├── key_ladder_demo
│   │   ├── key_ladder_demo.sh
│   │   ├── mini_client
│   │   ├── mpi_demo
│   │   ├── pem2der
│   │   ├── pk_decrypt
│   │   ├── pk_encrypt
│   │   ├── pk_sign
│   │   ├── pk_verify
│   │   ├── psa_constant_names
│   │   ├── query_compile_time_config
│   │   ├── req_app
│   │   ├── rsa_decrypt
│   │   ├── rsa_encrypt
│   │   ├── rsa_genkey
│   │   ├── rsa_sign
│   │   ├── rsa_sign_pss
│   │   ├── rsa_verify
│   │   ├── rsa_verify_pss
│   │   ├── selftest
│   │   ├── ssl_client1
│   │   ├── ssl_client2
│   │   ├── ssl_context_info
│   │   ├── ssl_fork_server
│   │   ├── ssl_mail_client
│   │   ├── ssl_pthread_server
│   │   ├── ssl_server
│   │   ├── ssl_server2
│   │   ├── strerror
│   │   ├── udp_proxy
│   │   └── zeroize
│   ├── cmake
│   │   ├── MbedTLSConfig.cmake
│   │   ├── MbedTLSConfigVersion.cmake
│   │   ├── MbedTLSTargets.cmake
│   │   └── MbedTLSTargets-noconfig.cmake
│   ├── include
│   │   ├── mbedtls
│   │   └── psa
│   └── lib
│       ├── libmbedcrypto.a
│       ├── libmbedcrypto.so -> libmbedcrypto.so.10
│       ├── libmbedcrypto.so.10 -> libmbedcrypto.so.3.0.0
│       ├── libmbedcrypto.so.3.0.0
│       ├── libmbedtls.a
│       ├── libmbedtls.so -> libmbedtls.so.16
│       ├── libmbedtls.so.16 -> libmbedtls.so.3.0.0
│       ├── libmbedtls.so.3.0.0
│       ├── libmbedx509.a
│       ├── libmbedx509.so -> libmbedx509.so.4
│       ├── libmbedx509.so.3.0.0
│       └── libmbedx509.so.4 -> libmbedx509.so.3.0.0
└── README.md
```