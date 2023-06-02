---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/binomial_coefficient_prime_mod.test.cpp
    title: test/library_checker/math/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp
    title: test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_117.test.cpp
    title: test/yukicoder/yuki_117.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/combination.md
    document_title: "Combination (\u4E8C\u9805\u4FC2\u6570)"
    links: []
  bundledCode: "#line 2 \"lib/math/combination.hpp\"\n\n/**\n * @brief Combination\
    \ (\u4E8C\u9805\u4FC2\u6570)\n * @docs docs/math/combination.md\n */\n\nstruct\
    \ Combination{\n    vector<long long> memo, memoinv, inv;\n    const long long\
    \ mod;\n    Combination(const int &N, const long long &m) : memo(N + 1), memoinv(N\
    \ + 1), inv(N + 1), mod(m){\n        memo[0] = memo[1] = 1;\n        memoinv[0]\
    \ = memoinv[1] = 1;\n        inv[1] = 1;\n        for(int i = 2; i <= N; ++i){\n\
    \            memo[i] = memo[i - 1] * i % mod;\n            inv[i] = mod - inv[mod\
    \ % i] * (m / i) % mod;\n            memoinv[i] = memoinv[i - 1] * inv[i] % mod;\n\
    \        }\n    }\n    inline long long fact(const long long &n) const {\n   \
    \     return memo[n];\n    }\n    inline long long factinv(const long long &n)\
    \ const {\n        return memoinv[n];\n    }\n    inline long long ncr(const long\
    \ long &n, const long long &r) const {\n        if(n < r || r < 0) return 0;\n\
    \        return (memo[n] * memoinv[r] % mod) * memoinv[n - r] % mod;\n    }\n\
    \    inline long long npr(const long long &n, const long long &r) const {\n  \
    \      if(n < r || r < 0) return 0;\n        return (memo[n] % mod) * memoinv[n\
    \ - r] % mod;\n    }\n    inline long long nhr(const long long &n, const long\
    \ long &r) const {\n        if(n == 0 && r == 0) return 1;\n        return ncr(n\
    \ + r - 1, r);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Combination (\u4E8C\u9805\u4FC2\u6570)\n *\
    \ @docs docs/math/combination.md\n */\n\nstruct Combination{\n    vector<long\
    \ long> memo, memoinv, inv;\n    const long long mod;\n    Combination(const int\
    \ &N, const long long &m) : memo(N + 1), memoinv(N + 1), inv(N + 1), mod(m){\n\
    \        memo[0] = memo[1] = 1;\n        memoinv[0] = memoinv[1] = 1;\n      \
    \  inv[1] = 1;\n        for(int i = 2; i <= N; ++i){\n            memo[i] = memo[i\
    \ - 1] * i % mod;\n            inv[i] = mod - inv[mod % i] * (m / i) % mod;\n\
    \            memoinv[i] = memoinv[i - 1] * inv[i] % mod;\n        }\n    }\n \
    \   inline long long fact(const long long &n) const {\n        return memo[n];\n\
    \    }\n    inline long long factinv(const long long &n) const {\n        return\
    \ memoinv[n];\n    }\n    inline long long ncr(const long long &n, const long\
    \ long &r) const {\n        if(n < r || r < 0) return 0;\n        return (memo[n]\
    \ * memoinv[r] % mod) * memoinv[n - r] % mod;\n    }\n    inline long long npr(const\
    \ long long &n, const long long &r) const {\n        if(n < r || r < 0) return\
    \ 0;\n        return (memo[n] % mod) * memoinv[n - r] % mod;\n    }\n    inline\
    \ long long nhr(const long long &n, const long long &r) const {\n        if(n\
    \ == 0 && r == 0) return 1;\n        return ncr(n + r - 1, r);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/combination.hpp
  requiredBy: []
  timestamp: '2023-01-25 06:41:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_117.test.cpp
  - test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp
  - test/library_checker/math/binomial_coefficient_prime_mod.test.cpp
documentation_of: lib/math/combination.hpp
layout: document
redirect_from:
- /library/lib/math/combination.hpp
- /library/lib/math/combination.hpp.html
title: "Combination (\u4E8C\u9805\u4FC2\u6570)"
---
## Combination (二項係数)

#### 使い方

制約: $m$ が素数でないと使えないため注意。

- `Combination(N, m)`: $N$ までの二項係数 (mod. m) を前計算します。
- `fact(n)`: $n!$ を求めます。
- `factinv(n)`: $n!$ の逆元を求めます。
- `ncr(n, r)`: $nCr$ を求めます。
- `npr(n, r)`: $nPr$ を求めます。
- `nhr(n, r)`: $nHr$ を求めます。

#### 計算量

- `Combination(N, m)`: $\mathrm{O}(N)$
- `fact(n)`: $\mathrm{O}(1)$
- `factinv(n)`: $\mathrm{O}(1)$
- `ncr(n, r)`: $\mathrm{O}(1)$
- `npr(n, r)`: $\mathrm{O}(1)$
- `nhr(n, r)`: $\mathrm{O}(1)$