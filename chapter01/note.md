# chapter01
## 00cipherSuiteDefault
- 默认配置下打印支持的加密算法,输出如下：
```sh
Available Ciphersuite:
  [001] TLS-ECDHE-RSA-WITH-CHACHA20-POLY1305-SHA256
  [002] TLS-ECDHE-ECDSA-WITH-CHACHA20-POLY1305-SHA256
  [003] TLS-DHE-RSA-WITH-CHACHA20-POLY1305-SHA256
  [004] TLS-ECDHE-ECDSA-WITH-AES-256-GCM-SHA384
  [005] TLS-ECDHE-RSA-WITH-AES-256-GCM-SHA384
  [006] TLS-DHE-RSA-WITH-AES-256-GCM-SHA384
  [007] TLS-ECDHE-ECDSA-WITH-AES-256-CCM
  [008] TLS-DHE-RSA-WITH-AES-256-CCM
  [009] TLS-ECDHE-ECDSA-WITH-AES-256-CBC-SHA384
  [010] TLS-ECDHE-RSA-WITH-AES-256-CBC-SHA384
  [011] TLS-DHE-RSA-WITH-AES-256-CBC-SHA256
  [012] TLS-ECDHE-ECDSA-WITH-AES-256-CBC-SHA
  [013] TLS-ECDHE-RSA-WITH-AES-256-CBC-SHA
  [014] TLS-DHE-RSA-WITH-AES-256-CBC-SHA
  [015] TLS-ECDHE-ECDSA-WITH-AES-256-CCM-8
  [016] TLS-DHE-RSA-WITH-AES-256-CCM-8
  [017] TLS-ECDHE-ECDSA-WITH-CAMELLIA-256-GCM-SHA384
  [018] TLS-ECDHE-RSA-WITH-CAMELLIA-256-GCM-SHA384
  [019] TLS-DHE-RSA-WITH-CAMELLIA-256-GCM-SHA384
  [020] TLS-ECDHE-ECDSA-WITH-CAMELLIA-256-CBC-SHA384
  [021] TLS-ECDHE-RSA-WITH-CAMELLIA-256-CBC-SHA384
  [022] TLS-DHE-RSA-WITH-CAMELLIA-256-CBC-SHA256
  [023] TLS-DHE-RSA-WITH-CAMELLIA-256-CBC-SHA
  [024] TLS-ECDHE-ECDSA-WITH-ARIA-256-GCM-SHA384
  [025] TLS-ECDHE-RSA-WITH-ARIA-256-GCM-SHA384
  [026] TLS-DHE-RSA-WITH-ARIA-256-GCM-SHA384
  [027] TLS-ECDHE-ECDSA-WITH-ARIA-256-CBC-SHA384
  [028] TLS-ECDHE-RSA-WITH-ARIA-256-CBC-SHA384
  [029] TLS-DHE-RSA-WITH-ARIA-256-CBC-SHA384
  [030] TLS-ECDHE-ECDSA-WITH-AES-128-GCM-SHA256
  [031] TLS-ECDHE-RSA-WITH-AES-128-GCM-SHA256
  [032] TLS-DHE-RSA-WITH-AES-128-GCM-SHA256
  [033] TLS-ECDHE-ECDSA-WITH-AES-128-CCM
  [034] TLS-DHE-RSA-WITH-AES-128-CCM
  [035] TLS-ECDHE-ECDSA-WITH-AES-128-CBC-SHA256
  [036] TLS-ECDHE-RSA-WITH-AES-128-CBC-SHA256
  [037] TLS-DHE-RSA-WITH-AES-128-CBC-SHA256
  [038] TLS-ECDHE-ECDSA-WITH-AES-128-CBC-SHA
  [039] TLS-ECDHE-RSA-WITH-AES-128-CBC-SHA
  [040] TLS-DHE-RSA-WITH-AES-128-CBC-SHA
  [041] TLS-ECDHE-ECDSA-WITH-AES-128-CCM-8
  [042] TLS-DHE-RSA-WITH-AES-128-CCM-8
  [043] TLS-ECDHE-ECDSA-WITH-CAMELLIA-128-GCM-SHA256
  [044] TLS-ECDHE-RSA-WITH-CAMELLIA-128-GCM-SHA256
  [045] TLS-DHE-RSA-WITH-CAMELLIA-128-GCM-SHA256
  [046] TLS-ECDHE-ECDSA-WITH-CAMELLIA-128-CBC-SHA256
  [047] TLS-ECDHE-RSA-WITH-CAMELLIA-128-CBC-SHA256
  [048] TLS-DHE-RSA-WITH-CAMELLIA-128-CBC-SHA256
  [049] TLS-DHE-RSA-WITH-CAMELLIA-128-CBC-SHA
  [050] TLS-ECDHE-ECDSA-WITH-ARIA-128-GCM-SHA256
  [051] TLS-ECDHE-RSA-WITH-ARIA-128-GCM-SHA256
  [052] TLS-DHE-RSA-WITH-ARIA-128-GCM-SHA256
  [053] TLS-ECDHE-ECDSA-WITH-ARIA-128-CBC-SHA256
  [054] TLS-ECDHE-RSA-WITH-ARIA-128-CBC-SHA256
  [055] TLS-DHE-RSA-WITH-ARIA-128-CBC-SHA256
  [056] TLS-ECDHE-PSK-WITH-CHACHA20-POLY1305-SHA256
  [057] TLS-DHE-PSK-WITH-CHACHA20-POLY1305-SHA256
  [058] TLS-DHE-PSK-WITH-AES-256-GCM-SHA384
  [059] TLS-DHE-PSK-WITH-AES-256-CCM
  [060] TLS-ECDHE-PSK-WITH-AES-256-CBC-SHA384
  [061] TLS-DHE-PSK-WITH-AES-256-CBC-SHA384
  [062] TLS-ECDHE-PSK-WITH-AES-256-CBC-SHA
  [063] TLS-DHE-PSK-WITH-AES-256-CBC-SHA
  [064] TLS-DHE-PSK-WITH-CAMELLIA-256-GCM-SHA384
  [065] TLS-ECDHE-PSK-WITH-CAMELLIA-256-CBC-SHA384
  [066] TLS-DHE-PSK-WITH-CAMELLIA-256-CBC-SHA384
  [067] TLS-DHE-PSK-WITH-AES-256-CCM-8
  [068] TLS-DHE-PSK-WITH-ARIA-256-GCM-SHA384
  [069] TLS-ECDHE-PSK-WITH-ARIA-256-CBC-SHA384
  [070] TLS-DHE-PSK-WITH-ARIA-256-CBC-SHA384
  [071] TLS-DHE-PSK-WITH-AES-128-GCM-SHA256
  [072] TLS-DHE-PSK-WITH-AES-128-CCM
  [073] TLS-ECDHE-PSK-WITH-AES-128-CBC-SHA256
  [074] TLS-DHE-PSK-WITH-AES-128-CBC-SHA256
  [075] TLS-ECDHE-PSK-WITH-AES-128-CBC-SHA
  [076] TLS-DHE-PSK-WITH-AES-128-CBC-SHA
  [077] TLS-DHE-PSK-WITH-CAMELLIA-128-GCM-SHA256
  [078] TLS-DHE-PSK-WITH-CAMELLIA-128-CBC-SHA256
  [079] TLS-ECDHE-PSK-WITH-CAMELLIA-128-CBC-SHA256
  [080] TLS-DHE-PSK-WITH-AES-128-CCM-8
  [081] TLS-DHE-PSK-WITH-ARIA-128-GCM-SHA256
  [082] TLS-ECDHE-PSK-WITH-ARIA-128-CBC-SHA256
  [083] TLS-DHE-PSK-WITH-ARIA-128-CBC-SHA256
  [084] TLS-RSA-WITH-AES-256-GCM-SHA384
  [085] TLS-RSA-WITH-AES-256-CCM
  [086] TLS-RSA-WITH-AES-256-CBC-SHA256
  [087] TLS-RSA-WITH-AES-256-CBC-SHA
  [088] TLS-ECDH-RSA-WITH-AES-256-GCM-SHA384
  [089] TLS-ECDH-RSA-WITH-AES-256-CBC-SHA384
  [090] TLS-ECDH-RSA-WITH-AES-256-CBC-SHA
  [091] TLS-ECDH-ECDSA-WITH-AES-256-GCM-SHA384
  [092] TLS-ECDH-ECDSA-WITH-AES-256-CBC-SHA384
  [093] TLS-ECDH-ECDSA-WITH-AES-256-CBC-SHA
  [094] TLS-RSA-WITH-AES-256-CCM-8
  [095] TLS-RSA-WITH-CAMELLIA-256-GCM-SHA384
  [096] TLS-RSA-WITH-CAMELLIA-256-CBC-SHA256
  [097] TLS-RSA-WITH-CAMELLIA-256-CBC-SHA
  [098] TLS-ECDH-RSA-WITH-CAMELLIA-256-GCM-SHA384
  [099] TLS-ECDH-RSA-WITH-CAMELLIA-256-CBC-SHA384
  [100] TLS-ECDH-ECDSA-WITH-CAMELLIA-256-GCM-SHA384
  [101] TLS-ECDH-ECDSA-WITH-CAMELLIA-256-CBC-SHA384
  [102] TLS-ECDH-ECDSA-WITH-ARIA-256-GCM-SHA384
  [103] TLS-ECDH-RSA-WITH-ARIA-256-GCM-SHA384
  [104] TLS-RSA-WITH-ARIA-256-GCM-SHA384
  [105] TLS-ECDH-ECDSA-WITH-ARIA-256-CBC-SHA384
  [106] TLS-ECDH-RSA-WITH-ARIA-256-CBC-SHA384
  [107] TLS-RSA-WITH-ARIA-256-CBC-SHA384
  [108] TLS-RSA-WITH-AES-128-GCM-SHA256
  [109] TLS-RSA-WITH-AES-128-CCM
  [110] TLS-RSA-WITH-AES-128-CBC-SHA256
  [111] TLS-RSA-WITH-AES-128-CBC-SHA
  [112] TLS-ECDH-RSA-WITH-AES-128-GCM-SHA256
  [113] TLS-ECDH-RSA-WITH-AES-128-CBC-SHA256
  [114] TLS-ECDH-RSA-WITH-AES-128-CBC-SHA
  [115] TLS-ECDH-ECDSA-WITH-AES-128-GCM-SHA256
  [116] TLS-ECDH-ECDSA-WITH-AES-128-CBC-SHA256
  [117] TLS-ECDH-ECDSA-WITH-AES-128-CBC-SHA
  [118] TLS-RSA-WITH-AES-128-CCM-8
  [119] TLS-RSA-WITH-CAMELLIA-128-GCM-SHA256
  [120] TLS-RSA-WITH-CAMELLIA-128-CBC-SHA256
  [121] TLS-RSA-WITH-CAMELLIA-128-CBC-SHA
  [122] TLS-ECDH-RSA-WITH-CAMELLIA-128-GCM-SHA256
  [123] TLS-ECDH-RSA-WITH-CAMELLIA-128-CBC-SHA256
  [124] TLS-ECDH-ECDSA-WITH-CAMELLIA-128-GCM-SHA256
  [125] TLS-ECDH-ECDSA-WITH-CAMELLIA-128-CBC-SHA256
  [126] TLS-ECDH-ECDSA-WITH-ARIA-128-GCM-SHA256
  [127] TLS-ECDH-RSA-WITH-ARIA-128-GCM-SHA256
  [128] TLS-RSA-WITH-ARIA-128-GCM-SHA256
  [129] TLS-ECDH-ECDSA-WITH-ARIA-128-CBC-SHA256
  [130] TLS-ECDH-RSA-WITH-ARIA-128-CBC-SHA256
  [131] TLS-RSA-WITH-ARIA-128-CBC-SHA256
  [132] TLS-RSA-PSK-WITH-CHACHA20-POLY1305-SHA256
  [133] TLS-RSA-PSK-WITH-AES-256-GCM-SHA384
  [134] TLS-RSA-PSK-WITH-AES-256-CBC-SHA384
  [135] TLS-RSA-PSK-WITH-AES-256-CBC-SHA
  [136] TLS-RSA-PSK-WITH-CAMELLIA-256-GCM-SHA384
  [137] TLS-RSA-PSK-WITH-CAMELLIA-256-CBC-SHA384
  [138] TLS-RSA-PSK-WITH-ARIA-256-GCM-SHA384
  [139] TLS-RSA-PSK-WITH-ARIA-256-CBC-SHA384
  [140] TLS-RSA-PSK-WITH-AES-128-GCM-SHA256
  [141] TLS-RSA-PSK-WITH-AES-128-CBC-SHA256
  [142] TLS-RSA-PSK-WITH-AES-128-CBC-SHA
  [143] TLS-RSA-PSK-WITH-CAMELLIA-128-GCM-SHA256
  [144] TLS-RSA-PSK-WITH-CAMELLIA-128-CBC-SHA256
  [145] TLS-RSA-PSK-WITH-ARIA-128-GCM-SHA256
  [146] TLS-RSA-PSK-WITH-ARIA-128-CBC-SHA256
  [147] TLS-PSK-WITH-CHACHA20-POLY1305-SHA256
  [148] TLS-PSK-WITH-AES-256-GCM-SHA384
  [149] TLS-PSK-WITH-AES-256-CCM
  [150] TLS-PSK-WITH-AES-256-CBC-SHA384
  [151] TLS-PSK-WITH-AES-256-CBC-SHA
  [152] TLS-PSK-WITH-CAMELLIA-256-GCM-SHA384
  [153] TLS-PSK-WITH-CAMELLIA-256-CBC-SHA384
  [154] TLS-PSK-WITH-AES-256-CCM-8
  [155] TLS-PSK-WITH-ARIA-256-GCM-SHA384
  [156] TLS-PSK-WITH-ARIA-256-CBC-SHA384
  [157] TLS-PSK-WITH-AES-128-GCM-SHA256
  [158] TLS-PSK-WITH-AES-128-CCM
  [159] TLS-PSK-WITH-AES-128-CBC-SHA256
  [160] TLS-PSK-WITH-AES-128-CBC-SHA
  [161] TLS-PSK-WITH-CAMELLIA-128-GCM-SHA256
  [162] TLS-PSK-WITH-CAMELLIA-128-CBC-SHA256
  [163] TLS-PSK-WITH-AES-128-CCM-8
  [164] TLS-PSK-WITH-ARIA-128-GCM-SHA256
  [165] TLS-PSK-WITH-ARIA-128-CBC-SHA256
```
## 01cipherSuiteMini
- 往往在实际工程中，处于对硬件平台(单片机)算力和资源的综合考虑，需要手动灵活的配置工程。裁剪不必要的加密组件，减少硬件存储开销；
- 从最小加密套件开始配置是一个好的方法，在最小配置的基础上根据项目实际需求进行配置，避免"粗枝大叶"、"不求甚解"的愚蠢的行为，追求按需配置，优雅的处理实际问题=>此乃明智的处理思路，彰显工程的"专业性"。
- 本工程的编译方法是个个例，由于调整了工程的加密套件的配置文件。想到达到预期的效果,需要依赖源码进行编译。
- 注意配置MBEDTLS_SOURCE_DIR变量到实际的源代码路径
- 最小配置下打印支持的加密算法,输出如下：
```sh
Available Ciphersuite:
  [001] TLS-ECDHE-ECDSA-WITH-AES-256-GCM-SHA384
  [002] TLS-ECDHE-ECDSA-WITH-AES-128-GCM-SHA256
```