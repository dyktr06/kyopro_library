---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_184.test.cpp
    title: test/yukicoder/yuki_184.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/binarybasis.md
    document_title: Binary Basis
    links: []
  bundledCode: "#line 2 \"lib/math/binarybasis.hpp\"\n\n/**\n * @brief Binary Basis\n\
    \ * @docs docs/math/binarybasis.md\n */\n\ntemplate <typename T>\nstruct BinaryBasis{\n\
    \n    vector<T> basis, original;\n    BinaryBasis(const vector<T>& vec){\n   \
    \     for(auto x : vec){\n            T y = x;\n            for(auto z : basis){\n\
    \                y = min(y, y ^ z);\n            }\n            if(y > 0){\n \
    \               basis.push_back(y);\n                original.push_back(x);\n\
    \            }\n        }\n        normalize();\n    }\n\n    void add(const T\
    \ &x){\n        T y = x;\n        for(auto z : basis){\n            y = min(y,\
    \ y ^ z);\n        }\n        if(y > 0){\n            basis.push_back(y);\n  \
    \          original.push_back(x);\n        }\n    }\n\n    void normalize(){\n\
    \        sort(basis.begin(), basis.end());\n        for(int i = 0; i < (int) basis.size();\
    \ ++i){\n            for(int j = 0; j < i; ++j){\n                basis[i] = min(basis[i],\
    \ basis[i] ^ basis[j]);\n            }\n        }\n    }\n\n    bool exist(const\
    \ T &x){\n        T y = x;\n        for(auto z : basis){\n            y = min(y,\
    \ y ^ z);\n        }\n        return y == 0;\n    }\n\n    T kth_element(const\
    \ long long &k){\n        T res = 0;\n        for(int i = 0; i < (int) basis.size();\
    \ ++i){\n            if(k & (1LL << i)){\n                res ^= basis[i];\n \
    \           }\n        }\n        return res;\n    }\n\n    size_t size(){\n \
    \       return basis.size();\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Binary Basis\n * @docs docs/math/binarybasis.md\n\
    \ */\n\ntemplate <typename T>\nstruct BinaryBasis{\n\n    vector<T> basis, original;\n\
    \    BinaryBasis(const vector<T>& vec){\n        for(auto x : vec){\n        \
    \    T y = x;\n            for(auto z : basis){\n                y = min(y, y\
    \ ^ z);\n            }\n            if(y > 0){\n                basis.push_back(y);\n\
    \                original.push_back(x);\n            }\n        }\n        normalize();\n\
    \    }\n\n    void add(const T &x){\n        T y = x;\n        for(auto z : basis){\n\
    \            y = min(y, y ^ z);\n        }\n        if(y > 0){\n            basis.push_back(y);\n\
    \            original.push_back(x);\n        }\n    }\n\n    void normalize(){\n\
    \        sort(basis.begin(), basis.end());\n        for(int i = 0; i < (int) basis.size();\
    \ ++i){\n            for(int j = 0; j < i; ++j){\n                basis[i] = min(basis[i],\
    \ basis[i] ^ basis[j]);\n            }\n        }\n    }\n\n    bool exist(const\
    \ T &x){\n        T y = x;\n        for(auto z : basis){\n            y = min(y,\
    \ y ^ z);\n        }\n        return y == 0;\n    }\n\n    T kth_element(const\
    \ long long &k){\n        T res = 0;\n        for(int i = 0; i < (int) basis.size();\
    \ ++i){\n            if(k & (1LL << i)){\n                res ^= basis[i];\n \
    \           }\n        }\n        return res;\n    }\n\n    size_t size(){\n \
    \       return basis.size();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/binarybasis.hpp
  requiredBy: []
  timestamp: '2023-05-01 02:14:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_184.test.cpp
documentation_of: lib/math/binarybasis.hpp
layout: document
redirect_from:
- /library/lib/math/binarybasis.hpp
- /library/lib/math/binarybasis.hpp.html
title: Binary Basis
---
## Binary Basis

#### 概要

数の集合に対する XOR 基底を求めます。

#### 使い方

- `BinaryBasis(vec)`: 集合 vec について、XOR 基底を求めます。
- `add(x)`: $x$ を基底の集合に追加します。
- `exist(x)`: 基底の集合の中から XOR を繰り返して $x$ を作れるかどうかを判定します。
- `normalize()`: 基底の集合を整理します。
- `kth_element(k)`: 基底から生成できる数の集合の $k$ 番目を取得します。(0-indexed なことに注意)
- `size(x)`: 基底の集合の大きさを取得します。

#### 計算量

集合の中の最大値を $A$ とします。

- `BinaryBasis(vec)`: vec の要素数を $N$ とすると、$\mathrm{O}(N \log A)$
- `add(x)`: $\mathrm{O}(\log A)$
- `exist(x)`: $\mathrm{O}(\log A)$
- `normalize()`: $\mathrm{O}(\log^2 A)$
- `kth_element(k)`: $\mathrm{O}(\log A)$
- `size(x)`: $\mathrm{O}(1)$