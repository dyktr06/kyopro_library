---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/convolution/divisor_zeta_mobius_transform.hpp
    title: lib/convolution/divisor_zeta_mobius_transform.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/prime_sieve.hpp
    title: "Prime Sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/lcm_convolution.test.cpp
    title: test/library_checker/convolution/lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/convolution/lcm_convolution.hpp\"\n\n#line 2 \"lib/convolution/divisor_zeta_mobius_transform.hpp\"\
    \n\n#line 2 \"lib/math/prime_sieve.hpp\"\n\n/**\n * @brief Prime Sieve (\u30A8\
    \u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)\n * @docs docs/math/prime-sieve.md\n\
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
    \    }\n\n    T getKthPrime(int k){\n        return prime_list[k];\n    }\n};\n\
    #line 4 \"lib/convolution/divisor_zeta_mobius_transform.hpp\"\n\ntemplate <typename\
    \ T>\nvoid divisor_zeta_transform(vector<T> &a){\n    int n = a.size() - 1;\n\
    \    PrimeSieve<int> sieve(n);\n    for(int d = 2; d <= n; d++){\n        if(sieve.isPrime(d)){\n\
    \            for(int i = 1; i * d <= n; i++){\n                a[i * d] += a[i];\n\
    \            }\n        }\n    }\n}\n\ntemplate <typename T>\nvoid divisor_reversed_zeta_transform(vector<T>\
    \ &a){\n    int n = a.size() - 1;\n    PrimeSieve<int> sieve(n);\n    for(int\
    \ d = 2; d <= n; d++){\n        if(sieve.isPrime(d)){\n            for(int i =\
    \ n / d; i >= 1; i--){\n                a[i] += a[i * d];\n            }\n   \
    \     }\n    }\n}\n\ntemplate <typename T>\nvoid divisor_mobius_transform(vector<T>\
    \ &a){\n    int n = a.size() - 1;\n    PrimeSieve<int> sieve(n);\n    for(int\
    \ d = 2; d <= n; d++){\n        if(sieve.isPrime(d)){\n            for(int i =\
    \ n / d; i >= 1; i--){\n                a[i * d] -= a[i];\n            }\n   \
    \     }\n    }\n}\n\ntemplate <typename T>\nvoid divisor_reversed_mobius_transform(vector<T>\
    \ &a){\n    int n = a.size() - 1;\n    PrimeSieve<int> sieve(n);\n    for(int\
    \ d = 2; d <= n; d++){\n        if(sieve.isPrime(d)){\n            for(int i =\
    \ 1; i * d <= n; i++){\n                a[i] -= a[i * d];\n            }\n   \
    \     }\n    }\n}\n#line 4 \"lib/convolution/lcm_convolution.hpp\"\n\ntemplate\
    \ <typename T>\nvector<T> lcm_convolution(vector<T> f, vector<T> g){\n    const\
    \ int n = (int) f.size();\n    assert(f.size() == g.size());\n    assert(1 <=\
    \ n);\n    divisor_zeta_transform(f);\n    divisor_zeta_transform(g);\n    for(int\
    \ i = 1; i < n; ++i){\n        f[i] *= g[i];\n    }\n    divisor_mobius_transform(f);\n\
    \    return f;\n}\n"
  code: "#pragma once\n\n#include \"../convolution/divisor_zeta_mobius_transform.hpp\"\
    \n\ntemplate <typename T>\nvector<T> lcm_convolution(vector<T> f, vector<T> g){\n\
    \    const int n = (int) f.size();\n    assert(f.size() == g.size());\n    assert(1\
    \ <= n);\n    divisor_zeta_transform(f);\n    divisor_zeta_transform(g);\n   \
    \ for(int i = 1; i < n; ++i){\n        f[i] *= g[i];\n    }\n    divisor_mobius_transform(f);\n\
    \    return f;\n}\n"
  dependsOn:
  - lib/convolution/divisor_zeta_mobius_transform.hpp
  - lib/math/prime_sieve.hpp
  isVerificationFile: false
  path: lib/convolution/lcm_convolution.hpp
  requiredBy: []
  timestamp: '2024-10-21 22:27:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/lcm_convolution.test.cpp
documentation_of: lib/convolution/lcm_convolution.hpp
layout: document
redirect_from:
- /library/lib/convolution/lcm_convolution.hpp
- /library/lib/convolution/lcm_convolution.hpp.html
title: lib/convolution/lcm_convolution.hpp
---
