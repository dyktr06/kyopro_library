---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/math/primitive_root.hpp
    title: "Primitive Root (\u539F\u5B50\u6839)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/factorize.test.cpp
    title: test/library_checker/number_theory/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/primality_test.test.cpp
    title: test/library_checker/number_theory/primality_test.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/primitive_root.test.cpp
    title: test/library_checker/number_theory/primitive_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_888.test.cpp
    title: test/yukicoder/yuki_888.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/rho.md
    document_title: Pollard's Rho
    links: []
  bundledCode: "#line 2 \"lib/math/rho.hpp\"\n\n/**\n * @brief Pollard's Rho\n * @docs\
    \ docs/math/rho.md\n */\n\nnamespace Rho{\n    unsigned long long mul(unsigned\
    \ long long a, unsigned long long b, const unsigned long long mod) {\n       \
    \ long long ret = a * b - mod * (unsigned long long)(1.0L / mod * a * b);\n  \
    \      return ret + mod * (ret < 0) - mod * (ret >= (long long) mod);\n    }\n\
    \n    bool rabin_miller(unsigned long long n){\n        switch(n){\n        case\
    \ 0: // fall-through\n        case 1: return false;\n        case 2: return true;\n\
    \        }\n\n        if(n % 2 == 0) return false;\n        vector<long long>\
    \ A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n        unsigned long\
    \ long s = 0, d = n - 1;\n        while(d % 2 == 0){\n            s++;\n     \
    \       d >>= 1;\n        }\n\n        auto modpow = [](unsigned long long x,\
    \ unsigned long long e, const unsigned long long mod) -> unsigned long long {\n\
    \            unsigned long long ret = 1 % mod;\n            x %= mod;\n      \
    \      while(e > 0){\n                if(e & 1) ret = mul(ret, x, mod);\n    \
    \            x = mul(x, x, mod);\n                e >>= 1;\n            }\n  \
    \          return ret;\n        };\n\n        for(auto a : A){\n            if(a\
    \ % n == 0) return true;\n            unsigned long long t, x = modpow(a, d, n);\n\
    \            if(x != 1){\n                for(t = 0; t < s; ++t){\n          \
    \          if(x == n - 1) break;\n                    x = mul(x, x, n);\n    \
    \            }\n                if(t == s) return false;\n            }\n    \
    \    }\n        return true;\n    }\n\n    mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());\n\
    \    unsigned long long FindFactor(unsigned long long n) {\n        if(n == 1\
    \ || rabin_miller(n)) return n;\n        if(n % 2 == 0) return 2;\n        unsigned\
    \ long long c = 1, x = 0, y = 0, t = 0, prod = 2, x0 = 1, q;\n        auto f =\
    \ [&](unsigned long long X) { return mul(X, X, n) + c;};\n\n        while(t++\
    \ % 128 or __gcd(prod, n) == 1) {\n            if(x == y) c = rng() % (n - 1)\
    \ + 1, x = x0, y = f(x);\n            if((q = mul(prod, max(x, y) - min(x, y),\
    \ n))) prod = q;\n            x = f(x), y = f(f(y));\n        }\n        return\
    \ __gcd(prod, n);\n    }\n\n    vector<unsigned long long> factorize(unsigned\
    \ long long x) {\n        if(x == 1) return {};\n        unsigned long long a\
    \ = FindFactor(x), b = x / a;\n        if(a == x) return {a};\n        vector<unsigned\
    \ long long> L = factorize(a), R = factorize(b);\n        L.insert(L.end(), R.begin(),\
    \ R.end());\n        return L;\n    }\n\n    vector<unsigned long long> divisor(unsigned\
    \ long long x){\n        vector<unsigned long long> factor = Rho::factorize(x);\n\
    \        map<unsigned long long, int> countFactor;\n        for(auto x : factor){\n\
    \            if(countFactor.count(x) == 0) countFactor[x] = 0;\n            countFactor[x]++;\n\
    \        }\n        vector<unsigned long long> ret = {1};\n        for(auto [x,\
    \ cnt] : countFactor){\n            int n = ret.size();\n            for(int i\
    \ = 0; i < n; ++i){\n                unsigned long long z = ret[i];\n        \
    \        for(int j = 0; j < cnt; ++j){\n                    z *= x;\n        \
    \            ret.push_back(z);\n                }\n            }\n        }\n\
    \        return ret;\n    }\n}\n"
  code: "#pragma once\n\n/**\n * @brief Pollard's Rho\n * @docs docs/math/rho.md\n\
    \ */\n\nnamespace Rho{\n    unsigned long long mul(unsigned long long a, unsigned\
    \ long long b, const unsigned long long mod) {\n        long long ret = a * b\
    \ - mod * (unsigned long long)(1.0L / mod * a * b);\n        return ret + mod\
    \ * (ret < 0) - mod * (ret >= (long long) mod);\n    }\n\n    bool rabin_miller(unsigned\
    \ long long n){\n        switch(n){\n        case 0: // fall-through\n       \
    \ case 1: return false;\n        case 2: return true;\n        }\n\n        if(n\
    \ % 2 == 0) return false;\n        vector<long long> A = {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022};\n        unsigned long long s = 0, d = n - 1;\n\
    \        while(d % 2 == 0){\n            s++;\n            d >>= 1;\n        }\n\
    \n        auto modpow = [](unsigned long long x, unsigned long long e, const unsigned\
    \ long long mod) -> unsigned long long {\n            unsigned long long ret =\
    \ 1 % mod;\n            x %= mod;\n            while(e > 0){\n               \
    \ if(e & 1) ret = mul(ret, x, mod);\n                x = mul(x, x, mod);\n   \
    \             e >>= 1;\n            }\n            return ret;\n        };\n\n\
    \        for(auto a : A){\n            if(a % n == 0) return true;\n         \
    \   unsigned long long t, x = modpow(a, d, n);\n            if(x != 1){\n    \
    \            for(t = 0; t < s; ++t){\n                    if(x == n - 1) break;\n\
    \                    x = mul(x, x, n);\n                }\n                if(t\
    \ == s) return false;\n            }\n        }\n        return true;\n    }\n\
    \n    mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());\n\
    \    unsigned long long FindFactor(unsigned long long n) {\n        if(n == 1\
    \ || rabin_miller(n)) return n;\n        if(n % 2 == 0) return 2;\n        unsigned\
    \ long long c = 1, x = 0, y = 0, t = 0, prod = 2, x0 = 1, q;\n        auto f =\
    \ [&](unsigned long long X) { return mul(X, X, n) + c;};\n\n        while(t++\
    \ % 128 or __gcd(prod, n) == 1) {\n            if(x == y) c = rng() % (n - 1)\
    \ + 1, x = x0, y = f(x);\n            if((q = mul(prod, max(x, y) - min(x, y),\
    \ n))) prod = q;\n            x = f(x), y = f(f(y));\n        }\n        return\
    \ __gcd(prod, n);\n    }\n\n    vector<unsigned long long> factorize(unsigned\
    \ long long x) {\n        if(x == 1) return {};\n        unsigned long long a\
    \ = FindFactor(x), b = x / a;\n        if(a == x) return {a};\n        vector<unsigned\
    \ long long> L = factorize(a), R = factorize(b);\n        L.insert(L.end(), R.begin(),\
    \ R.end());\n        return L;\n    }\n\n    vector<unsigned long long> divisor(unsigned\
    \ long long x){\n        vector<unsigned long long> factor = Rho::factorize(x);\n\
    \        map<unsigned long long, int> countFactor;\n        for(auto x : factor){\n\
    \            if(countFactor.count(x) == 0) countFactor[x] = 0;\n            countFactor[x]++;\n\
    \        }\n        vector<unsigned long long> ret = {1};\n        for(auto [x,\
    \ cnt] : countFactor){\n            int n = ret.size();\n            for(int i\
    \ = 0; i < n; ++i){\n                unsigned long long z = ret[i];\n        \
    \        for(int j = 0; j < cnt; ++j){\n                    z *= x;\n        \
    \            ret.push_back(z);\n                }\n            }\n        }\n\
    \        return ret;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/rho.hpp
  requiredBy:
  - lib/math/primitive_root.hpp
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_888.test.cpp
  - test/library_checker/number_theory/factorize.test.cpp
  - test/library_checker/number_theory/primitive_root.test.cpp
  - test/library_checker/number_theory/primality_test.test.cpp
documentation_of: lib/math/rho.hpp
layout: document
redirect_from:
- /library/lib/math/rho.hpp
- /library/lib/math/rho.hpp.html
title: Pollard's Rho
---
## Pollard's Rho

#### 使い方

- `Rho::rabin_miller(N)`: $N$ が素数かどうかを判定します。
- `Rho::factorize(N)`: $N$ について素因数分解をします。
- `Rho::divisor(N)`: $N$ の約数を列挙します。

#### 計算量

- `Rho::rabin_miller(N)`: $\mathrm{O}(\log N)$
- `Rho::factorize(N)`: $\mathrm{O}(N^{1/4})$
- `Rho::divisor(N)`: $\mathrm{O}(N^{1/4} + d)$ ($d$ は約数の個数)
