---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/enumerate_quotients.test.cpp
    title: test/library_checker/math/enumerate_quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/enumerate_quotients.md
    document_title: "Primitive Root (\u539F\u5B50\u6839)"
    links: []
  bundledCode: "#line 2 \"lib/math/enumerate_quotients.hpp\"\n\n/**\n * @brief Primitive\
    \ Root (\u539F\u5B50\u6839)\n * @docs docs/math/enumerate_quotients.md\n */\n\n\
    template <typename T>\nvector<tuple<T, T, T>> enumerate_quotients(const T &n){\n\
    \    vector<tuple<T, T, T>> res;\n    for(T l = 1; l <= n;){\n        const T\
    \ quotient = n / l;\n        const T r = n / quotient + 1;\n\n        // [l, r)\n\
    \        res.emplace_back(l, r, quotient);\n        l = r;\n    }\n    return\
    \ res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Primitive Root (\u539F\u5B50\u6839)\n * @docs\
    \ docs/math/enumerate_quotients.md\n */\n\ntemplate <typename T>\nvector<tuple<T,\
    \ T, T>> enumerate_quotients(const T &n){\n    vector<tuple<T, T, T>> res;\n \
    \   for(T l = 1; l <= n;){\n        const T quotient = n / l;\n        const T\
    \ r = n / quotient + 1;\n\n        // [l, r)\n        res.emplace_back(l, r, quotient);\n\
    \        l = r;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/enumerate_quotients.hpp
  requiredBy: []
  timestamp: '2024-03-21 03:54:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/enumerate_quotients.test.cpp
documentation_of: lib/math/enumerate_quotients.hpp
layout: document
redirect_from:
- /library/lib/math/enumerate_quotients.hpp
- /library/lib/math/enumerate_quotients.hpp.html
title: "Primitive Root (\u539F\u5B50\u6839)"
---
## Enumerate Quotients (商列挙)

#### 概要

正整数 $N$ について、$1 \leq x \leq N$ における $\lfloor N / x \rfloor$ （商）としてあり得る値を列挙します。

また、その商となる $x$ の区間も同時に取得します。

#### 計算量

- $\mathrm{O}(\sqrt{N})$