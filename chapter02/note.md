# chapter02
- 单向散列函数是一类满足密码学算法安全属性的特殊散列函数。输入数据通常称为消息，输出数据通常称为消息摘要或简称为摘要，可以用来检测消息的完整性。
## 00hashMd5
```c
MD5('Hello, world!') = 6cd3556deb0da54bca060b4c39479839
```
## 01genericSum
```sh
genericSum MD5 message.txt > out.txt
genericSum MD5 -c out.txt
```
## 02aes
```sh
crypt_and_hash 0 inputPlaintext ciphertext AES-128-CBC MD5 1234567890
crypt_and_hash 1 ciphertext outputPlaintext AES-128-CBC MD5 1234567890
```
## 03random
```sh
gen_entropy out.txt
hexdump -C -n 64 out.txt
00000000  1d 9f 35 f2 84 ce 4b f7  4b 92 fe 39 bc e6 d9 52  |..5...K.K..9...R|
00000010  6d 01 ff f0 9b 0f 8d 77  79 c0 55 c4 f8 20 1c 60  |m......wy.U.. .`|
00000020  de c2 10 f5 65 a0 d5 35  6e b5 2d e9 7f 08 f3 49  |....e..5n.-....I|
00000030  5d c2 a9 05 0c 53 5d 66  12 f1 81 87 da 41 d0 e6  |]....S]f.....A..|
```
04 ctrDrbg
```sh
gen_random_ctr_drbg out.txt
hexdump -C -n 64 out.txt
00000000  58 5c 36 ce a5 b0 af ea  21 78 f1 02 7f a3 b7 58  |X\6.....!x.....X|
00000010  c8 5f 4b 5d b4 86 75 50  aa 9c ed 19 82 a7 2c ea  |._K]..uP......,.|
00000020  32 4a 1e cb f5 a3 7a e4  f7 0e 02 1f ca 67 32 83  |2J....z......g2.|
00000030  94 f5 e4 11 73 44 71 25  5c ff cb 0a 4b 73 0b 6c  |....sDq%\...Ks.l|
hexdump -C -n 64 seedfile
00000000  75 43 e5 20 39 c4 ba 6e  0b 0d 31 7e 05 64 29 7e  |uC. 9..n..1~.d)~|
00000010  23 55 d6 1d 73 bf a7 31  84 f6 fe 93 60 e0 62 58  |#U..s..1....`.bX|
00000020  48 a2 d6 b9 7f 70 c0 d6  08 eb 4e 3e f1 bf 97 09  |H....p....N>....|
00000030  ab 4d 96 1b a2 e2 6c ee  10 8f 4d 33 07 de 6b da  |.M....l...M3..k.|
```
05 pkey
- 生成rsa公私钥
```sh
05pkey$ ./build/rsa_genkey
  . Seeding the random number generator... ok
  . Generating the RSA key [ 2048-bit ]... ok
  . Exporting the public  key in rsa_pub.txt.... ok
  . Exporting the private key in rsa_priv.txt... ok
```
- rsa加密
```sh
./build/rsa_encrypt 1234567890
 . Seeding the random number generator...
 . Reading public key from rsa_pub.txt
 . Generating the RSA encrypted value
 . Done (created "result-enc.txt")
```
- rsa解密
```sh
./build/rsa_decrypt
 . Seeding the random number generator...
 . Reading private key from rsa_priv.txt
 . Decrypting the encrypted data
 . OK
```
- rsa签名(签一下公钥)
```sh
./build/rsa_sign rsa_pub.txt
  . Reading private key from rsa_priv.txt
  . Checking the private key
  . Generating the RSA/SHA-256 signature
  . Done (created "rsa_pub.txt.sig")
```
- 验签公钥
```sh
./build/rsa_verify rsa_pub.txt
  . Reading public key from rsa_pub.txt
  . Verifying the RSA/SHA-256 signature
  . OK (the signature is valid)
```

- 生成私钥(默认PEM格式)
```sh
./build/gen_key
. Seeding the random number generator...
  . Generating the private key ... ok
  . Key information:
  . Writing key to file... ok
```
- 解析私钥
```sh
./build/key_app mode=private

 . Loading the private key ... ok
  . Key information    ...
```
- 使用密钥对生成公钥或私钥(pem||der)
```sh
./build/key_app_writer mode=private output_mode=private output_file=rsaPrivateKey.pem

  . Loading the private key ... ok
  . Key information    ...
```
```sh
./build/key_app_writer mode=private output_mode=public output_file=rsaPublicKey.pem

  . Loading the private key ... ok
  . Key information    ...
```
- 使用pk封装的接口加密
```sh
./build/pk_encrypt rsaPublicKey.pem abcd

  . Seeding the random number generator...
  . Reading public key from 'rsaPublicKey.pem'
  . Generating the encrypted value
  . Done (created "result-enc.txt")
```
- 使用pk封装的接口解密
```sh
./build/pk_decrypt rsaPrivateKey.pem 

  . Seeding the random number generator...
  . Reading private key from 'rsaPrivateKey.pem'
  . Decrypting the encrypted data
  . OK

The decrypted result is: 'abcd'
```
- 使用pk封装的接口签名
```sh
./build/pk_sign rsaPrivateKey.pem rsaPublicKey.pem 

  . Seeding the random number generator...
  . Reading private key from 'rsaPrivateKey.pem'
 . Generating the SHA-256 signature
  . Done (created "rsaPublicKey.pem.sig")
```
- 使用pk封装的接口验签
```sh
./build/pk_verify rsaPublicKey.pem rsaPublicKey.pem

  . Reading public key from 'rsaPublicKey.pem'
  . Verifying the SHA-256 signature
  . OK (the signature is valid)
```
- 使用PKCS #1 v2.1填充方案的rsa签名
```sh
./build/rsa_sign_pass keyfile.key rsa_pub.txt
  . Seeding the random number generator...
  . Reading private key from 'keyfile.key'
  . Generating the RSA/SHA-256 signature
  . Done (created "rsa_pub.txt.sig")
```
- 使用PKCS #1 v2.1填充方案验签
```sh
./build/rsa_verify_pass rsaPublicKey.pem rsa_pub.txt

  . Reading public key from 'rsaPublicKey.pem'
  . Verifying the RSA/SHA-256 signature
  . OK (the signature is valid)
```