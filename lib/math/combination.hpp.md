---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/binomial_coefficient_prime_mod.test.cpp
    title: test/library_checker/math/binomial_coefficient_prime_mod.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp
    title: test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp
  - icon: ':x:'
    path: test/yukicoder/yuki_117.test.cpp
    title: test/yukicoder/yuki_117.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ + r - 1, r);\n    }\n};\n\nstruct CombinationByPascal{\n    vector<vector<long\
    \ long>> memo;\n    const long long mod;\n    CombinationByPascal(const int &N,\
    \ const long long &m) : mod(m){\n        memo.assign(N + 1, vector<long long>(N\
    \ + 1));\n        memo[0][0] = 1;\n        for(int i = 1; i <= N; ++i){\n    \
    \        memo[i][0] = 1;\n            for(int j = 1; j <= N; ++j){\n         \
    \       memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j]);\n                if(memo[i][j]\
    \ >= mod) memo[i][j] -= mod;\n            }\n        }\n    }\n    inline long\
    \ long ncr(const int &n, const int &r) const {\n        if(n < r || r < 0) return\
    \ 0;\n        return memo[n][r];\n    }\n};\n"
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
    \ == 0 && r == 0) return 1;\n        return ncr(n + r - 1, r);\n    }\n};\n\n\
    struct CombinationByPascal{\n    vector<vector<long long>> memo;\n    const long\
    \ long mod;\n    CombinationByPascal(const int &N, const long long &m) : mod(m){\n\
    \        memo.assign(N + 1, vector<long long>(N + 1));\n        memo[0][0] = 1;\n\
    \        for(int i = 1; i <= N; ++i){\n            memo[i][0] = 1;\n         \
    \   for(int j = 1; j <= N; ++j){\n                memo[i][j] = (memo[i - 1][j\
    \ - 1] + memo[i - 1][j]);\n                if(memo[i][j] >= mod) memo[i][j] -=\
    \ mod;\n            }\n        }\n    }\n    inline long long ncr(const int &n,\
    \ const int &r) const {\n        if(n < r || r < 0) return 0;\n        return\
    \ memo[n][r];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/combination.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/yuki_117.test.cpp
  - test/library_checker/math/binomial_coefficient_prime_mod.test.cpp
  - test/library_checker/math/binomial_coefficient_prime_mod_1.test.cpp
documentation_of: lib/math/combination.hpp
layout: document
redirect_from:
- /library/lib/math/combination.hpp
- /library/lib/math/combination.hpp.html
title: "Combination (\u4E8C\u9805\u4FC2\u6570)"
---
## Combination (二項係数)

#### 概要

二項係数を求めるライブラリです。

#### 使い方

$m$ が素数でないと使えないため注意。

- `Combination(N, m)`: $N$ までの二項係数 (mod. m) を前計算します。
- `fact(n)`: $n!$ を求めます。
- `factinv(n)`: $n!$ の逆元を求めます。
- `ncr(n, r)`: $nCr$ を求めます。
- `npr(n, r)`: $nPr$ を求めます。
- `nhr(n, r)`: $nHr$ を求めます。

以下のものは $m$ が素数でなくても使えますが、上述のものよりも計算量が悪いです。

- `CombinationByPascal(N, m)`: $N$ までの二項係数 (mod. m) を前計算します。
- `ncr(n, r)`: $nCr$ を求めます。

#### 計算量

- `Combination(N, m)`: $\mathrm{O}(N)$
- `fact(n)`: $\mathrm{O}(1)$
- `factinv(n)`: $\mathrm{O}(1)$
- `ncr(n, r)`: $\mathrm{O}(1)$
- `npr(n, r)`: $\mathrm{O}(1)$
- `nhr(n, r)`: $\mathrm{O}(1)$

CombinationByPascal についての計算量

- `CombinationByPascal(N, m)`: $\mathrm{O}(N^2)$
- `ncr(n, r)`: $\mathrm{O}(1)$