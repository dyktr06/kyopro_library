---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/rho.hpp
    title: Pollard's Rho
  - icon: ':heavy_check_mark:'
    path: lib/others/random.hpp
    title: "Random (\u4E71\u6570\u751F\u6210)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/primitive_root.test.cpp
    title: test/library_checker/math/primitive_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/primitive_root.md
    document_title: "Primitive Root (\u539F\u5B50\u6839)"
    links: []
  bundledCode: "#line 2 \"lib/math/primitive_root.hpp\"\n\n/**\n * @brief Primitive\
    \ Root (\u539F\u5B50\u6839)\n * @docs docs/math/primitive_root.md\n */\n\n#line\
    \ 2 \"lib/math/rho.hpp\"\n\n/**\n * @brief Pollard's Rho\n * @docs docs/math/rho.md\n\
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
    \        return ret;\n    }\n}\n#line 2 \"lib/others/random.hpp\"\n\n/**\n * @brief\
    \ Random (\u4E71\u6570\u751F\u6210)\n * @docs docs/others/random.md\n */\n\nstruct\
    \ RandomNumber{\n    int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    \    uniform_int_distribution<long long> p;\n    mt19937_64 rnd;\n\n    RandomNumber(long\
    \ long l = 0, long long r = 0){\n        rnd = mt19937_64(seed);\n        p =\
    \ uniform_int_distribution<long long>(l, r);\n    }\n\n    long long get(){\n\
    \        return p(rnd);\n    }\n};\n#line 10 \"lib/math/primitive_root.hpp\"\n\
    \nlong long primitiveRoot(long long p){\n    auto modpow = [](__int128_t x, long\
    \ long n, const long long &m){\n        __int128_t ret = 1 % m;\n        x %=\
    \ m;\n        while(n > 0){\n            if(n & 1) (ret *= x) %= m;\n        \
    \    (x *= x) %= m;\n            n >>= 1;\n        }\n        return ret;\n  \
    \  };\n\n    RandomNumber rnd(1, p - 1);\n    vector<unsigned long long> f = Rho::factorize(p\
    \ - 1);\n    while(true){\n        long long a = rnd.get();\n        bool is_ok\
    \ = true;\n        for(auto x : f){\n            if(modpow(a, (p - 1) / x, p)\
    \ == 1){\n                is_ok = false;\n                break;\n           \
    \ }\n        }\n        if(is_ok){\n            return a;\n        }\n    }\n\
    }\n"
  code: "#pragma once\n\n/**\n * @brief Primitive Root (\u539F\u5B50\u6839)\n * @docs\
    \ docs/math/primitive_root.md\n */\n\n#include \"../math/rho.hpp\"\n#include \"\
    ../others/random.hpp\"\n\nlong long primitiveRoot(long long p){\n    auto modpow\
    \ = [](__int128_t x, long long n, const long long &m){\n        __int128_t ret\
    \ = 1 % m;\n        x %= m;\n        while(n > 0){\n            if(n & 1) (ret\
    \ *= x) %= m;\n            (x *= x) %= m;\n            n >>= 1;\n        }\n \
    \       return ret;\n    };\n\n    RandomNumber rnd(1, p - 1);\n    vector<unsigned\
    \ long long> f = Rho::factorize(p - 1);\n    while(true){\n        long long a\
    \ = rnd.get();\n        bool is_ok = true;\n        for(auto x : f){\n       \
    \     if(modpow(a, (p - 1) / x, p) == 1){\n                is_ok = false;\n  \
    \              break;\n            }\n        }\n        if(is_ok){\n        \
    \    return a;\n        }\n    }\n}\n"
  dependsOn:
  - lib/math/rho.hpp
  - lib/others/random.hpp
  isVerificationFile: false
  path: lib/math/primitive_root.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/primitive_root.test.cpp
documentation_of: lib/math/primitive_root.hpp
layout: document
redirect_from:
- /library/lib/math/primitive_root.hpp
- /library/lib/math/primitive_root.hpp.html
title: "Primitive Root (\u539F\u5B50\u6839)"
---
## Primitive Root (原子根)

#### 概要

素数 $p$ における原子根を $1$ つ求めます。

#### 計算量

- $\mathrm{O}(p^{1/4})$