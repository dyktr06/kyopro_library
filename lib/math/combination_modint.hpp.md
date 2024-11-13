---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/math/pow_sum.hpp
    title: lib/math/pow_sum.hpp
  - icon: ':heavy_check_mark:'
    path: lib/polynomial/taylor_shift.hpp
    title: Taylor Shift
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
    title: test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/combination_modint.hpp\"\n\n#include <vector>\n\
    \ntemplate <typename T>\nstruct Combination{\n    std::vector<T> memo, memoinv,\
    \ inv;\n    Combination(const int N) : memo(N + 1), memoinv(N + 1), inv(N + 1){\n\
    \        T m = -1;\n        long long mod = (m.val + 1LL);\n        memo[0] =\
    \ memo[1] = 1;\n        memoinv[0] = memoinv[1] = 1;\n        inv[1] = 1;\n  \
    \      for(int i = 2; i <= N; ++i){\n            memo[i] = memo[i - 1] * i;\n\
    \            inv[i] = mod - inv[mod % i] * (mod / i);\n            memoinv[i]\
    \ = memoinv[i - 1] * inv[i];\n        }\n    }\n    inline T fact(const int n)\
    \ const {\n        return memo[n];\n    }\n    inline T factinv(const int n) const\
    \ {\n        return memoinv[n];\n    }\n    inline T ncr(const int n, const int\
    \ r) const {\n        if(n < r || r < 0) return 0;\n        return (memo[n] *\
    \ memoinv[r]) * memoinv[n - r];\n    }\n    inline T npr(const int n, const int\
    \ r) const {\n        if(n < r || r < 0) return 0;\n        return memo[n] * memoinv[n\
    \ - r];\n    }\n    // \u91CD\u8907\u7D44\u307F\u5408\u308F\u305B\n    inline\
    \ T nhr(const int n, const int r) const {\n        if(n == 0 && r == 0) return\
    \ 1;\n        return ncr(n + r - 1, r);\n    }\n    // \u30DC\u30FC\u30EB\u306E\
    \u6570\u3001\u4E00\u500B\u4EE5\u4E0A\u5FC5\u8981\u306A\u7BB1\u306E\u6570\u3001\
    \u5236\u9650\u304C\u306A\u3044\u7BB1\u306E\u6570 (\u7BB1\u533A\u5225\u3042\u308A\
    )\n    // a = 0 \u306E\u5834\u5408\u306F\u91CD\u8907\u7D44\u307F\u5408\u308F\u305B\
    \n    inline T choose(const int n, const int a, const int b = 0) const {\n   \
    \     if(n == 0) return !a;\n        return ncr(n + b - 1, a + b - 1);\n    }\n\
    \    // +1 n \u500B, -1 m \u500B, \u7D2F\u7A4D\u548C >= 0\n    inline T cataran(const\
    \ int n, const int m) const {\n        return ncr(n + m, n) - ncr(n + m, n - 1);\n\
    \    }\n    // +1 n \u500B, -1 m \u500B, \u7D2F\u7A4D\u548C > -k\n    inline T\
    \ cataran(const int n, const int m, const int k) const {\n        if(m < k) return\
    \ ncr(n + m, n);\n        if(m < n + k) return ncr(n + m, n) - ncr(n + m, m -\
    \ k);\n        return 0;\n    }\n    // +1 n \u500B, -1 m \u500B, \u7D2F\u7A4D\
    \u548C < +k\n    inline T cataran2(const int n, const int m, const int k) const\
    \ {\n        return cataran(m, n, k);\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <typename T>\nstruct Combination{\n\
    \    std::vector<T> memo, memoinv, inv;\n    Combination(const int N) : memo(N\
    \ + 1), memoinv(N + 1), inv(N + 1){\n        T m = -1;\n        long long mod\
    \ = (m.val + 1LL);\n        memo[0] = memo[1] = 1;\n        memoinv[0] = memoinv[1]\
    \ = 1;\n        inv[1] = 1;\n        for(int i = 2; i <= N; ++i){\n          \
    \  memo[i] = memo[i - 1] * i;\n            inv[i] = mod - inv[mod % i] * (mod\
    \ / i);\n            memoinv[i] = memoinv[i - 1] * inv[i];\n        }\n    }\n\
    \    inline T fact(const int n) const {\n        return memo[n];\n    }\n    inline\
    \ T factinv(const int n) const {\n        return memoinv[n];\n    }\n    inline\
    \ T ncr(const int n, const int r) const {\n        if(n < r || r < 0) return 0;\n\
    \        return (memo[n] * memoinv[r]) * memoinv[n - r];\n    }\n    inline T\
    \ npr(const int n, const int r) const {\n        if(n < r || r < 0) return 0;\n\
    \        return memo[n] * memoinv[n - r];\n    }\n    // \u91CD\u8907\u7D44\u307F\
    \u5408\u308F\u305B\n    inline T nhr(const int n, const int r) const {\n     \
    \   if(n == 0 && r == 0) return 1;\n        return ncr(n + r - 1, r);\n    }\n\
    \    // \u30DC\u30FC\u30EB\u306E\u6570\u3001\u4E00\u500B\u4EE5\u4E0A\u5FC5\u8981\
    \u306A\u7BB1\u306E\u6570\u3001\u5236\u9650\u304C\u306A\u3044\u7BB1\u306E\u6570\
    \ (\u7BB1\u533A\u5225\u3042\u308A)\n    // a = 0 \u306E\u5834\u5408\u306F\u91CD\
    \u8907\u7D44\u307F\u5408\u308F\u305B\n    inline T choose(const int n, const int\
    \ a, const int b = 0) const {\n        if(n == 0) return !a;\n        return ncr(n\
    \ + b - 1, a + b - 1);\n    }\n    // +1 n \u500B, -1 m \u500B, \u7D2F\u7A4D\u548C\
    \ >= 0\n    inline T cataran(const int n, const int m) const {\n        return\
    \ ncr(n + m, n) - ncr(n + m, n - 1);\n    }\n    // +1 n \u500B, -1 m \u500B,\
    \ \u7D2F\u7A4D\u548C > -k\n    inline T cataran(const int n, const int m, const\
    \ int k) const {\n        if(m < k) return ncr(n + m, n);\n        if(m < n +\
    \ k) return ncr(n + m, n) - ncr(n + m, m - k);\n        return 0;\n    }\n   \
    \ // +1 n \u500B, -1 m \u500B, \u7D2F\u7A4D\u548C < +k\n    inline T cataran2(const\
    \ int n, const int m, const int k) const {\n        return cataran(m, n, k);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/combination_modint.hpp
  requiredBy:
  - lib/math/pow_sum.hpp
  - lib/polynomial/taylor_shift.hpp
  timestamp: '2024-11-03 23:33:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/polynomial/polynomial_taylor_shift.test.cpp
documentation_of: lib/math/combination_modint.hpp
layout: document
redirect_from:
- /library/lib/math/combination_modint.hpp
- /library/lib/math/combination_modint.hpp.html
title: lib/math/combination_modint.hpp
---
