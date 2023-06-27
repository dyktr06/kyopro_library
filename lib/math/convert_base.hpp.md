---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_2087.test.cpp
    title: test/yukicoder/yuki_2087.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/convert_base.md
    document_title: Convert Base
    links: []
  bundledCode: "#line 2 \"lib/math/convert_base.hpp\"\n\n/**\n * @brief Convert Base\n\
    \ * @docs docs/math/convert_base.md\n */\n\ntemplate<typename T>\nstring convertBase(T\
    \ x, int b) {\n    string res;\n    T t = 1, k = abs(b);\n    while(x){\n    \
    \    T num = (x * t) % k;\n        if(num < 0) num += k;\n        res += num +\
    \ (num < 10 ? 48 : 87);\n        x -= num * t;\n        x /= k;\n        t *=\
    \ b / k;\n    }\n    if(res.empty()) res = '0';\n    reverse(res.begin(), res.end());\n\
    \    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Convert Base\n * @docs docs/math/convert_base.md\n\
    \ */\n\ntemplate<typename T>\nstring convertBase(T x, int b) {\n    string res;\n\
    \    T t = 1, k = abs(b);\n    while(x){\n        T num = (x * t) % k;\n     \
    \   if(num < 0) num += k;\n        res += num + (num < 10 ? 48 : 87);\n      \
    \  x -= num * t;\n        x /= k;\n        t *= b / k;\n    }\n    if(res.empty())\
    \ res = '0';\n    reverse(res.begin(), res.end());\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/convert_base.hpp
  requiredBy: []
  timestamp: '2023-06-28 01:14:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_2087.test.cpp
documentation_of: lib/math/convert_base.hpp
layout: document
redirect_from:
- /library/lib/math/convert_base.hpp
- /library/lib/math/convert_base.hpp.html
title: Convert Base
---
## Convert Base

#### 概要

10 進数での $x$ を $b$ 進数に変換します。

#### 計算量

- $\mathrm{O}(\log x)$