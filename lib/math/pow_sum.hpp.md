---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/pow_sum.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Combination{\n    vector<T> memo, memoinv, inv;\n    Combination(const int N)\
    \ : memo(N + 1), memoinv(N + 1), inv(N + 1){\n        T m = -1;\n        long\
    \ long mod = (m.val + 1LL);\n        memo[0] = memo[1] = 1;\n        memoinv[0]\
    \ = memoinv[1] = 1;\n        inv[1] = 1;\n        for(int i = 2; i <= N; ++i){\n\
    \            memo[i] = memo[i - 1] * i;\n            inv[i] = mod - inv[mod %\
    \ i] * (mod / i);\n            memoinv[i] = memoinv[i - 1] * inv[i];\n       \
    \ }\n    }\n    inline T fact(const long long n) const {\n        return memo[n];\n\
    \    }\n    inline T factinv(const long long n) const {\n        return memoinv[n];\n\
    \    }\n    inline T ncr(const long long n, const long long r) const {\n     \
    \   if(n < r || r < 0) return 0;\n        return (memo[n] * memoinv[r]) * memoinv[n\
    \ - r];\n    }\n    inline T npr(const long long n, const long long r) const {\n\
    \        if(n < r || r < 0) return 0;\n        return memo[n] * memoinv[n - r];\n\
    \    }\n    inline T nhr(const long long n, const long long r) const {\n     \
    \   if(n == 0 && r == 0) return 1;\n        return ncr(n + r - 1, r);\n    }\n\
    };\n\ntemplate <typename T>\nT pow_sum(long long n, long long k){\n    long long\
    \ d = k + 1;\n    vector<vector<T>> f(d + 1, vector<T>(2));\n    for(int j = 0;\
    \ j < 2; j++){\n        for(int i = 0; i < d + 1; i++){\n            if(i > 0\
    \ && j == 0){\n                f[i][0] = i;\n                f[i][0] = f[i][0].pow(k);\n\
    \            }\n            if(i > 0 && j > 0){\n                f[i][j] = f[i\
    \ - 1][j] + f[i][j - 1];\n            }\n        }\n    }\n\n    Combination<T>\
    \ comb(d);\n    vector<T> l(d + 1, 1), r(d + 1, 1);\n    for(int i = 0; i < d;\
    \ i++){\n        l[i + 1] = l[i] * (n - i);\n        r[i + 1] = r[i] * (n - (d\
    \ - i)); \n    }\n    T ans = 0;\n    for(int i = 0; i < d + 1; i++){\n      \
    \  T s = f[i][1];\n        // mul(n - x_j) (j != i)\n        s *= l[i];\n    \
    \    s *= r[d - i];\n        // i! * (d - i)! * (-1)^{d - i}\n        s *= comb.factinv(i);\n\
    \        s *= comb.factinv(d - i);\n        if((d - i) % 2) s *= -1;\n       \
    \ ans += s;\n    }\n    return ans;\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Combination{\n    vector<T>\
    \ memo, memoinv, inv;\n    Combination(const int N) : memo(N + 1), memoinv(N +\
    \ 1), inv(N + 1){\n        T m = -1;\n        long long mod = (m.val + 1LL);\n\
    \        memo[0] = memo[1] = 1;\n        memoinv[0] = memoinv[1] = 1;\n      \
    \  inv[1] = 1;\n        for(int i = 2; i <= N; ++i){\n            memo[i] = memo[i\
    \ - 1] * i;\n            inv[i] = mod - inv[mod % i] * (mod / i);\n          \
    \  memoinv[i] = memoinv[i - 1] * inv[i];\n        }\n    }\n    inline T fact(const\
    \ long long n) const {\n        return memo[n];\n    }\n    inline T factinv(const\
    \ long long n) const {\n        return memoinv[n];\n    }\n    inline T ncr(const\
    \ long long n, const long long r) const {\n        if(n < r || r < 0) return 0;\n\
    \        return (memo[n] * memoinv[r]) * memoinv[n - r];\n    }\n    inline T\
    \ npr(const long long n, const long long r) const {\n        if(n < r || r < 0)\
    \ return 0;\n        return memo[n] * memoinv[n - r];\n    }\n    inline T nhr(const\
    \ long long n, const long long r) const {\n        if(n == 0 && r == 0) return\
    \ 1;\n        return ncr(n + r - 1, r);\n    }\n};\n\ntemplate <typename T>\n\
    T pow_sum(long long n, long long k){\n    long long d = k + 1;\n    vector<vector<T>>\
    \ f(d + 1, vector<T>(2));\n    for(int j = 0; j < 2; j++){\n        for(int i\
    \ = 0; i < d + 1; i++){\n            if(i > 0 && j == 0){\n                f[i][0]\
    \ = i;\n                f[i][0] = f[i][0].pow(k);\n            }\n           \
    \ if(i > 0 && j > 0){\n                f[i][j] = f[i - 1][j] + f[i][j - 1];\n\
    \            }\n        }\n    }\n\n    Combination<T> comb(d);\n    vector<T>\
    \ l(d + 1, 1), r(d + 1, 1);\n    for(int i = 0; i < d; i++){\n        l[i + 1]\
    \ = l[i] * (n - i);\n        r[i + 1] = r[i] * (n - (d - i)); \n    }\n    T ans\
    \ = 0;\n    for(int i = 0; i < d + 1; i++){\n        T s = f[i][1];\n        //\
    \ mul(n - x_j) (j != i)\n        s *= l[i];\n        s *= r[d - i];\n        //\
    \ i! * (d - i)! * (-1)^{d - i}\n        s *= comb.factinv(i);\n        s *= comb.factinv(d\
    \ - i);\n        if((d - i) % 2) s *= -1;\n        ans += s;\n    }\n    return\
    \ ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/pow_sum.hpp
  requiredBy: []
  timestamp: '2024-01-24 14:03:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/pow_sum.hpp
layout: document
redirect_from:
- /library/lib/math/pow_sum.hpp
- /library/lib/math/pow_sum.hpp.html
title: lib/math/pow_sum.hpp
---
