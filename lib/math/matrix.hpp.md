---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_product.test.cpp
    title: test/library_checker/matrix/matrix_product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/matrix.md
    document_title: Matrix
    links: []
  bundledCode: "#line 2 \"lib/math/matrix.hpp\"\n\n/**\n * @brief Matrix\n * @docs\
    \ docs/math/matrix.md\n */\n\nvector<vector<long long>> matrixpow(vector<vector<long\
    \ long>> a, long long n, long long m){\n\n    int siz = a.size();\n    vector<vector<long\
    \ long>> b(siz, vector<long long>(siz, 0));\n    for(int i = 0; i < siz; i++)\
    \ b[i][i] = 1;\n\n    auto mul = [](vector<vector<long long>> a, vector<vector<long\
    \ long>> b, long long m) -> vector<vector<long long>> {\n        vector<vector<long\
    \ long>> res((int) a.size(), vector<long long>(b[0].size()));\n        for(int\
    \ i = 0; i < (int) a.size(); i++){\n            for(int k = 0; k < (int) b.size();\
    \ k++){\n                for(int j = 0; j < (int) b[0].size(); j++){\n       \
    \             res[i][j] += a[i][k] * b[k][j];\n                    res[i][j] %=\
    \ m;\n                }\n            }\n        }\n        return res;\n    };\n\
    \n    while(n > 0){\n        if(n & 1) b = mul(b, a, m);\n        a = mul(a, a,\
    \ m);\n        n >>= 1;\n    }\n    return b;\n}\n\n// \u884C\u5217\u306E\u7A4D\
    \ (mod. m) \u3092\u8A08\u7B97\u3057\u307E\u3059\u3002: O(N^3)\nvector<vector<long\
    \ long>> mul(vector<vector<long long>> a, vector<vector<long long>> b, long long\
    \ m){\n    vector<vector<long long>> res((int) a.size(), vector<long long>(b[0].size()));\n\
    \    for(int i = 0; i < (int) a.size(); i++){\n        for(int k = 0; k < (int)\
    \ b.size(); k++){\n            for(int j = 0; j < (int) b[0].size(); j++){\n \
    \               res[i][j] += a[i][k] * b[k][j];\n                res[i][j] %=\
    \ m;\n            }\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Matrix\n * @docs docs/math/matrix.md\n */\n\
    \nvector<vector<long long>> matrixpow(vector<vector<long long>> a, long long n,\
    \ long long m){\n\n    int siz = a.size();\n    vector<vector<long long>> b(siz,\
    \ vector<long long>(siz, 0));\n    for(int i = 0; i < siz; i++) b[i][i] = 1;\n\
    \n    auto mul = [](vector<vector<long long>> a, vector<vector<long long>> b,\
    \ long long m) -> vector<vector<long long>> {\n        vector<vector<long long>>\
    \ res((int) a.size(), vector<long long>(b[0].size()));\n        for(int i = 0;\
    \ i < (int) a.size(); i++){\n            for(int k = 0; k < (int) b.size(); k++){\n\
    \                for(int j = 0; j < (int) b[0].size(); j++){\n               \
    \     res[i][j] += a[i][k] * b[k][j];\n                    res[i][j] %= m;\n \
    \               }\n            }\n        }\n        return res;\n    };\n\n \
    \   while(n > 0){\n        if(n & 1) b = mul(b, a, m);\n        a = mul(a, a,\
    \ m);\n        n >>= 1;\n    }\n    return b;\n}\n\n// \u884C\u5217\u306E\u7A4D\
    \ (mod. m) \u3092\u8A08\u7B97\u3057\u307E\u3059\u3002: O(N^3)\nvector<vector<long\
    \ long>> mul(vector<vector<long long>> a, vector<vector<long long>> b, long long\
    \ m){\n    vector<vector<long long>> res((int) a.size(), vector<long long>(b[0].size()));\n\
    \    for(int i = 0; i < (int) a.size(); i++){\n        for(int k = 0; k < (int)\
    \ b.size(); k++){\n            for(int j = 0; j < (int) b[0].size(); j++){\n \
    \               res[i][j] += a[i][k] * b[k][j];\n                res[i][j] %=\
    \ m;\n            }\n        }\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/matrix.hpp
  requiredBy: []
  timestamp: '2023-01-23 12:51:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/matrix/matrix_product.test.cpp
documentation_of: lib/math/matrix.hpp
layout: document
redirect_from:
- /library/lib/math/matrix.hpp
- /library/lib/math/matrix.hpp.html
title: Matrix
---
## Matrix

#### 概要

行列についての関数をまとめています。

#### 使い方

- `matrixpow(a, n, m)`: 行列 $a$ の $n$ 乗 (mod. m) を求めます。
- `mul(a, b, m)`: 行列 $a$ と $b$ の行列積 (mod. m) を求めます。

#### 計算量

行列のサイズを $N \times N$ とします。

- `matrixpow(a, n, m)`: $\mathrm{O}(N^3 \log n)$
- `mul(a, b, m)`: $\mathrm{O}(N^3)$