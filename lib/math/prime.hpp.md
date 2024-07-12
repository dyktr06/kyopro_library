---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1_1_c.test.cpp
    title: test/aoj/alds1/alds1_1_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ntl/ntl_1_a.test.cpp
    title: test/aoj/ntl/ntl_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_888_1.test.cpp
    title: test/yukicoder/yuki_888_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/prime.md
    document_title: "\u7D20\u6570\u5224\u5B9A\u3001\u7D04\u6570\u5217\u6319"
    links: []
  bundledCode: "#line 2 \"lib/math/prime.hpp\"\n\n/**\n * @brief \u7D20\u6570\u5224\
    \u5B9A\u3001\u7D04\u6570\u5217\u6319\n * @docs docs/math/prime.md\n */\n\nnamespace\
    \ prime{\n\n    template <typename T>\n    bool isPrime(T n){\n        switch(n)\
    \ {\n        case 0: // fall-through\n        case 1: return false;\n        case\
    \ 2: return true;\n        }\n\n        if(n % 2 == 0) return false;\n\n     \
    \   for(T i = 3; i * i <= n; i += 2){\n            if(n % i == 0){\n         \
    \       return false;\n            }\n        }\n        return true;\n    }\n\
    \n    template <typename T>\n    vector<pair<T, T>> factorize(T n) {\n       \
    \ vector<pair<T, T>> ret;\n        for(T i = 2; i * i <= n; i++) {\n         \
    \   if(n % i != 0) continue;\n            T tmp = 0;\n            while(n % i\
    \ == 0) {\n                tmp++;\n                n /= i;\n            }\n  \
    \          ret.push_back(make_pair(i, tmp));\n        }\n        if(n != 1) ret.push_back(make_pair(n,\
    \ 1));\n        return ret;\n    }\n\n    template <typename T>\n    vector<T>\
    \ divisor(T n){\n        T rt = sqrt(n);\n        vector<T> res, resB;\n     \
    \   for(T i = 1; i * i <= n; i++){\n            if(n % i == 0){\n            \
    \    res.push_back(i);\n                T j = n / i;\n                if(j !=\
    \ rt){\n                    resB.push_back(j);\n                }\n          \
    \  }\n        }\n        for(int i = (int) resB.size() - 1; i >= 0; i--){\n  \
    \          res.push_back(resB[i]);\n        }\n        return res;\n    }\n\n\
    \    template <typename T>\n    vector<T> sieve(T n){\n        vector<T> c(n +\
    \ 1);\n        for(int i = 2; i <= n; i++){\n            if(c[i] != 0) continue;\n\
    \            for(int j = i; j <= n; j += i){\n                c[j] += 1;\n   \
    \         }\n        }\n        return c;\n    }\n}\n"
  code: "#pragma once\n\n/**\n * @brief \u7D20\u6570\u5224\u5B9A\u3001\u7D04\u6570\
    \u5217\u6319\n * @docs docs/math/prime.md\n */\n\nnamespace prime{\n\n    template\
    \ <typename T>\n    bool isPrime(T n){\n        switch(n) {\n        case 0: //\
    \ fall-through\n        case 1: return false;\n        case 2: return true;\n\
    \        }\n\n        if(n % 2 == 0) return false;\n\n        for(T i = 3; i *\
    \ i <= n; i += 2){\n            if(n % i == 0){\n                return false;\n\
    \            }\n        }\n        return true;\n    }\n\n    template <typename\
    \ T>\n    vector<pair<T, T>> factorize(T n) {\n        vector<pair<T, T>> ret;\n\
    \        for(T i = 2; i * i <= n; i++) {\n            if(n % i != 0) continue;\n\
    \            T tmp = 0;\n            while(n % i == 0) {\n                tmp++;\n\
    \                n /= i;\n            }\n            ret.push_back(make_pair(i,\
    \ tmp));\n        }\n        if(n != 1) ret.push_back(make_pair(n, 1));\n    \
    \    return ret;\n    }\n\n    template <typename T>\n    vector<T> divisor(T\
    \ n){\n        T rt = sqrt(n);\n        vector<T> res, resB;\n        for(T i\
    \ = 1; i * i <= n; i++){\n            if(n % i == 0){\n                res.push_back(i);\n\
    \                T j = n / i;\n                if(j != rt){\n                \
    \    resB.push_back(j);\n                }\n            }\n        }\n       \
    \ for(int i = (int) resB.size() - 1; i >= 0; i--){\n            res.push_back(resB[i]);\n\
    \        }\n        return res;\n    }\n\n    template <typename T>\n    vector<T>\
    \ sieve(T n){\n        vector<T> c(n + 1);\n        for(int i = 2; i <= n; i++){\n\
    \            if(c[i] != 0) continue;\n            for(int j = i; j <= n; j +=\
    \ i){\n                c[j] += 1;\n            }\n        }\n        return c;\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/prime.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_888_1.test.cpp
  - test/aoj/ntl/ntl_1_a.test.cpp
  - test/aoj/alds1/alds1_1_c.test.cpp
documentation_of: lib/math/prime.hpp
layout: document
redirect_from:
- /library/lib/math/prime.hpp
- /library/lib/math/prime.hpp.html
title: "\u7D20\u6570\u5224\u5B9A\u3001\u7D04\u6570\u5217\u6319"
---
## 素数判定、約数列挙

### 概要

素数判定、約数列挙などのアルゴリズムの詰め合わせです。

数が大きい場合には Pollard's Rho の使用を推奨します。

#### 使い方

- `prime::isPrime(N)`: $N$ が素数かどうかを判定します。
- `prime::factrize(N)`: $N$ について素因数分解をします。
- `prime::divisor(N)`: $N$ の約数を昇順に列挙します。
- `prime::sieve(N)`: $2$ から $N$ までの素因数の個数を返します。(エラトステネスのふるい)

#### 計算量

- `prime::isPrime(N)`: $\mathrm{O}(\sqrt N)$
- `prime::factrize(N)`: $\mathrm{O}(\sqrt N)$
- `prime::divisor(N)`: $\mathrm{O}(\sqrt N)$
- `prime::sieve(N)`: $\mathrm{O}(N \log \log N)$