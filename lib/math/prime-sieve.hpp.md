---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/enumerate_primes.test.cpp
    title: test/library_checker/math/enumerate_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/prime-sieve.hpp\"\n\ntemplate <typename T>\nstruct\
    \ PrimeSieve{\n    int n, half;\n    vector<bool> sieve;\n    vector<T> prime_list;\n\
    \    // sieve[i] ... 2 * i + 1\n\n    PrimeSieve(T _n) : n(_n){\n        init();\n\
    \    }\n\n    void init(){\n        if(n < 2){\n            return;\n        }\n\
    \        half = (n + 1) / 2;\n        sieve.assign(half, true);\n        sieve[0]\
    \ = false;\n        prime_list.emplace_back(2);\n        for(long long i = 1;\
    \ 2 * i + 1 <= n; ++i){\n            if(!sieve[i]) continue;\n            T p\
    \ = 2 * i + 1;\n            prime_list.emplace_back(p);\n            for(long\
    \ long j = 2 * i * (i + 1); j < half; j += p){\n                sieve[j] = false;\n\
    \            }\n        }\n    }\n\n    bool isPrime(T x){\n        if(x == 2)\
    \ return true;\n        if(x % 2 == 0) return false;\n        return sieve[x /\
    \ 2];\n    }\n\n    T getPrimeCount(){\n        return prime_list.size();\n  \
    \  }\n\n    T getKthPrime(int k){\n        return prime_list[k];\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct PrimeSieve{\n    int n, half;\n\
    \    vector<bool> sieve;\n    vector<T> prime_list;\n    // sieve[i] ... 2 * i\
    \ + 1\n\n    PrimeSieve(T _n) : n(_n){\n        init();\n    }\n\n    void init(){\n\
    \        if(n < 2){\n            return;\n        }\n        half = (n + 1) /\
    \ 2;\n        sieve.assign(half, true);\n        sieve[0] = false;\n        prime_list.emplace_back(2);\n\
    \        for(long long i = 1; 2 * i + 1 <= n; ++i){\n            if(!sieve[i])\
    \ continue;\n            T p = 2 * i + 1;\n            prime_list.emplace_back(p);\n\
    \            for(long long j = 2 * i * (i + 1); j < half; j += p){\n         \
    \       sieve[j] = false;\n            }\n        }\n    }\n\n    bool isPrime(T\
    \ x){\n        if(x == 2) return true;\n        if(x % 2 == 0) return false;\n\
    \        return sieve[x / 2];\n    }\n\n    T getPrimeCount(){\n        return\
    \ prime_list.size();\n    }\n\n    T getKthPrime(int k){\n        return prime_list[k];\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/prime-sieve.hpp
  requiredBy: []
  timestamp: '2022-12-17 18:00:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/enumerate_primes.test.cpp
documentation_of: lib/math/prime-sieve.hpp
layout: document
redirect_from:
- /library/lib/math/prime-sieve.hpp
- /library/lib/math/prime-sieve.hpp.html
title: lib/math/prime-sieve.hpp
---
