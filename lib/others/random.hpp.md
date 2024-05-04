---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: lib/math/primitive_root.hpp
    title: "Primitive Root (\u539F\u5B50\u6839)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/primitive_root.test.cpp
    title: test/library_checker/math/primitive_root.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/others/random.md
    document_title: "Random (\u4E71\u6570\u751F\u6210)"
    links: []
  bundledCode: "#line 2 \"lib/others/random.hpp\"\n\n/**\n * @brief Random (\u4E71\
    \u6570\u751F\u6210)\n * @docs docs/others/random.md\n */\n\nstruct RandomNumber{\n\
    \    int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    \    uniform_int_distribution<long long> p;\n    mt19937_64 rnd;\n\n    RandomNumber(long\
    \ long l = 0, long long r = 0){\n        rnd = mt19937_64(seed);\n        p =\
    \ uniform_int_distribution<long long>(l, r);\n    }\n\n    long long get(){\n\
    \        return p(rnd);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Random (\u4E71\u6570\u751F\u6210)\n * @docs\
    \ docs/others/random.md\n */\n\nstruct RandomNumber{\n    int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    \    uniform_int_distribution<long long> p;\n    mt19937_64 rnd;\n\n    RandomNumber(long\
    \ long l = 0, long long r = 0){\n        rnd = mt19937_64(seed);\n        p =\
    \ uniform_int_distribution<long long>(l, r);\n    }\n\n    long long get(){\n\
    \        return p(rnd);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/random.hpp
  requiredBy:
  - lib/math/primitive_root.hpp
  timestamp: '2024-03-21 04:22:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/primitive_root.test.cpp
documentation_of: lib/others/random.hpp
layout: document
redirect_from:
- /library/lib/others/random.hpp
- /library/lib/others/random.hpp.html
title: "Random (\u4E71\u6570\u751F\u6210)"
---
## Random (乱数生成)

#### 概要

乱数の生成の仕方が分からなくなるので作りました。

#### 使い方

- `RandomNumber(l, r)`: 閉区間 $[l, r]$ （整数）の乱数テーブルを構築します。
- `get()`: 乱数を $1$ つ取得します。