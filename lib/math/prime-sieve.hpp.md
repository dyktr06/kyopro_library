---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/enumerate_primes.test.cpp
    title: test/library_checker/math/enumerate_primes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/prime-sieve.md
    document_title: "Prime Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
      \u7BE9)"
    links: []
  bundledCode: "#line 2 \"lib/math/prime-sieve.hpp\"\n\n/**\n * @brief Prime Sieve\
    \ (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)\n * @docs docs/math/prime-sieve.md\n\
    \ */\n\ntemplate <typename T>\nstruct PrimeSieve{\n    int n, half;\n    vector<bool>\
    \ sieve;\n    vector<T> prime_list;\n    // sieve[i] ... 2 * i + 1\n\n    PrimeSieve(T\
    \ _n) : n(_n){\n        init();\n    }\n\n    void init(){\n        if(n < 2){\n\
    \            return;\n        }\n        half = (n + 1) / 2;\n        sieve.assign(half,\
    \ true);\n        sieve[0] = false;\n        prime_list.emplace_back(2);\n   \
    \     for(long long i = 1; 2 * i + 1 <= n; ++i){\n            if(!sieve[i]) continue;\n\
    \            T p = 2 * i + 1;\n            prime_list.emplace_back(p);\n     \
    \       for(long long j = 2 * i * (i + 1); j < half; j += p){\n              \
    \  sieve[j] = false;\n            }\n        }\n    }\n\n    bool isPrime(T x){\n\
    \        if(x == 2) return true;\n        if(x % 2 == 0) return false;\n     \
    \   return sieve[x / 2];\n    }\n\n    T getPrimeCount(){\n        return prime_list.size();\n\
    \    }\n\n    T getKthPrime(int k){\n        return prime_list[k];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Prime Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\
    \u30CD\u30B9\u306E\u7BE9)\n * @docs docs/math/prime-sieve.md\n */\n\ntemplate\
    \ <typename T>\nstruct PrimeSieve{\n    int n, half;\n    vector<bool> sieve;\n\
    \    vector<T> prime_list;\n    // sieve[i] ... 2 * i + 1\n\n    PrimeSieve(T\
    \ _n) : n(_n){\n        init();\n    }\n\n    void init(){\n        if(n < 2){\n\
    \            return;\n        }\n        half = (n + 1) / 2;\n        sieve.assign(half,\
    \ true);\n        sieve[0] = false;\n        prime_list.emplace_back(2);\n   \
    \     for(long long i = 1; 2 * i + 1 <= n; ++i){\n            if(!sieve[i]) continue;\n\
    \            T p = 2 * i + 1;\n            prime_list.emplace_back(p);\n     \
    \       for(long long j = 2 * i * (i + 1); j < half; j += p){\n              \
    \  sieve[j] = false;\n            }\n        }\n    }\n\n    bool isPrime(T x){\n\
    \        if(x == 2) return true;\n        if(x % 2 == 0) return false;\n     \
    \   return sieve[x / 2];\n    }\n\n    T getPrimeCount(){\n        return prime_list.size();\n\
    \    }\n\n    T getKthPrime(int k){\n        return prime_list[k];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/prime-sieve.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/enumerate_primes.test.cpp
documentation_of: lib/math/prime-sieve.hpp
layout: document
redirect_from:
- /library/lib/math/prime-sieve.hpp
- /library/lib/math/prime-sieve.hpp.html
title: "Prime Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
---
## Prime Sieve (エラトステネスの篩)

#### 概要

エラトステネスの篩により素数判定などを行うライブラリです。

$2$ の倍数は省略するといった高速化を行っています。

#### 使い方

- `PrimeSieve(N)`: $N$ 以下の正整数について、エラトステネスの篩を行います。
- `isPrime(x)`: $x$ について素数判定を行います。
- `getPrimeCount()`: $N$ 以下の素数の個数を求めます。
- `getKthPrime()`: $K$ 番目の素数を求めます。(0-indexed なことに注意)

#### 計算量

- `PrimeSieve(N)`: $\mathrm{O}(N \log \log N)$
- `isPrime(x)`: $\mathrm{O}(1)$
- `getPrimeCount()`: $\mathrm{O}(1)$
- `getKthPrime()`: $\mathrm{O}(1)$