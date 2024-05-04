---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/yuki_2087.test.cpp
    title: test/yukicoder/yuki_2087.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/convert_base.md
    document_title: "Convert Base (\u9032\u6570\u5909\u63DB)"
    links: []
  bundledCode: "#line 2 \"lib/math/convert_base.hpp\"\n\n/**\n * @brief Convert Base\
    \ (\u9032\u6570\u5909\u63DB)\n * @docs docs/math/convert_base.md\n */\n\ntemplate<typename\
    \ T>\nstring convertBase(T x, int b) {\n    string res;\n    T t = 1, k = abs(b);\n\
    \    while(x){\n        T num = (x * t) % k;\n        if(num < 0) num += k;\n\
    \        res += num + (num < 10 ? 48 : 87);\n        x -= num * t;\n        x\
    \ /= k;\n        t *= b / k;\n    }\n    if(res.empty()) res = '0';\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Convert Base (\u9032\u6570\u5909\u63DB)\n\
    \ * @docs docs/math/convert_base.md\n */\n\ntemplate<typename T>\nstring convertBase(T\
    \ x, int b) {\n    string res;\n    T t = 1, k = abs(b);\n    while(x){\n    \
    \    T num = (x * t) % k;\n        if(num < 0) num += k;\n        res += num +\
    \ (num < 10 ? 48 : 87);\n        x -= num * t;\n        x /= k;\n        t *=\
    \ b / k;\n    }\n    if(res.empty()) res = '0';\n    reverse(res.begin(), res.end());\n\
    \    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/convert_base.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/yuki_2087.test.cpp
documentation_of: lib/math/convert_base.hpp
layout: document
redirect_from:
- /library/lib/math/convert_base.hpp
- /library/lib/math/convert_base.hpp.html
title: "Convert Base (\u9032\u6570\u5909\u63DB)"
---
## Convert Base (進数変換)

#### 概要

10 進数での $x$ を $b$ 進数に変換します。

#### 計算量

- $\mathrm{O}(\log x)$