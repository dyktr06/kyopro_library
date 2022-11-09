---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/math/modcalc.cpp\"\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\n// mod. m \u3067\u306E x^n \u3092\u8A08\u7B97\u3057\u307E\u3059\
    \ : O(logn)\ntemplate <typename T>\nT modpow(T x, T n, const T &m){\n    T ret\
    \ = 1 % m;\n    x %= m;\n    while(n > 0){\n        if(n & 1) (ret *= x) %= m;\n\
    \        (x *= x) %= m;\n        n >>= 1;\n    }\n    return ret;\n}\n\n// mod.\
    \ m \u3067\u306E a \u306E\u9006\u5143 a^{-1} \u3092\u8A08\u7B97\u3057\u307E\u3059\
    \ : O(logm)\ntemplate <typename T>\nT modinv(T a, T m){\n    T b = m, u = 1, v\
    \ = 0;\n    while(b){\n        T t = a / b;\n        a -= t * b; swap(a, b);\n\
    \        u -= t * v; swap(u, v);\n    }\n    u %= m;\n    if (u < 0) u += m;\n\
    \    return u;\n}\n\n// mod. m \u3067\u306E\u521D\u9805 a, \u516C\u5DEE d, \u9805\
    \u6570 n \u306E\u7B49\u5DEE\u6570\u5217\u306E\u548C\u3092\u8A08\u7B97\u3057\u307E\
    \u3059 : O(logm)\ntemplate <typename T>\nT modarithmeticsum(T a, T d, T n, T m){\n\
    \    a %= m, n %= m, d %= m;\n    T b = (n - 1) * d % m;\n    return n * (a *\
    \ 2 + b) % m * modinv((T) 2, m) % m;\n}\n\n// mod. m \u3067\u306E\u521D\u9805\
    \ a, \u516C\u6BD4 r, \u9805\u6570 n \u306E\u7B49\u6BD4\u6570\u5217\u306E\u548C\
    \u3092\u8A08\u7B97\u3057\u307E\u3059 : O(log(nm))\ntemplate <typename T>\nT modgeometricsum(T\
    \ a, T r, T n, T m){\n    a %= m;\n    if(r == 1){\n        n %= m;\n        return\
    \ a * n % m;\n    }\n    return a * (modpow(r, n, m) + m - 1) % m * modinv(r -\
    \ 1, m) % m;\n}\n\n// mod. m \u3067\u306E\u4E8C\u9805\u4FC2\u6570\u306A\u3069\u3092\
    \u9AD8\u901F\u3067\u8A08\u7B97\u3057\u307E\u3059 : O(N)\nstruct Combination{\n\
    \    vector<long long> memo, memoinv, inv;\n    long long mod;\n\n    Combination(int\
    \ N, long long m) : memo(N + 1), memoinv(N + 1), inv(N + 1){\n        mod = m;\n\
    \        memo[0] = memo[1] = 1;\n        memoinv[0] = memoinv[1] = 1;\n      \
    \  inv[1] = 1;\n        for(int i = 2; i <= N; i++){\n            memo[i] = memo[i\
    \ - 1] * i % mod;\n            inv[i] = mod - inv[mod % i] * (m / i) % mod;\n\
    \            memoinv[i] = memoinv[i - 1] * inv[i] % mod;\n        }\n    }\n\n\
    \    long long fact(long long n){\n        return memo[n];\n    }\n\n    long\
    \ long factinv(long long n){\n        return memoinv[n];\n    }\n\n    long long\
    \ ncr(long long n, long long r){\n        if(n < r || r < 0) return 0;\n     \
    \   return (memo[n] * memoinv[r] % mod) * memoinv[n - r] % mod;\n    }\n\n   \
    \ long long npr(long long n, long long r){\n        if(n < r || r < 0) return\
    \ 0;\n        return (memo[n] % mod) * memoinv[n - r] % mod;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// mod. m \u3067\u306E\
    \ x^n \u3092\u8A08\u7B97\u3057\u307E\u3059 : O(logn)\ntemplate <typename T>\n\
    T modpow(T x, T n, const T &m){\n    T ret = 1 % m;\n    x %= m;\n    while(n\
    \ > 0){\n        if(n & 1) (ret *= x) %= m;\n        (x *= x) %= m;\n        n\
    \ >>= 1;\n    }\n    return ret;\n}\n\n// mod. m \u3067\u306E a \u306E\u9006\u5143\
    \ a^{-1} \u3092\u8A08\u7B97\u3057\u307E\u3059 : O(logm)\ntemplate <typename T>\n\
    T modinv(T a, T m){\n    T b = m, u = 1, v = 0;\n    while(b){\n        T t =\
    \ a / b;\n        a -= t * b; swap(a, b);\n        u -= t * v; swap(u, v);\n \
    \   }\n    u %= m;\n    if (u < 0) u += m;\n    return u;\n}\n\n// mod. m \u3067\
    \u306E\u521D\u9805 a, \u516C\u5DEE d, \u9805\u6570 n \u306E\u7B49\u5DEE\u6570\u5217\
    \u306E\u548C\u3092\u8A08\u7B97\u3057\u307E\u3059 : O(logm)\ntemplate <typename\
    \ T>\nT modarithmeticsum(T a, T d, T n, T m){\n    a %= m, n %= m, d %= m;\n \
    \   T b = (n - 1) * d % m;\n    return n * (a * 2 + b) % m * modinv((T) 2, m)\
    \ % m;\n}\n\n// mod. m \u3067\u306E\u521D\u9805 a, \u516C\u6BD4 r, \u9805\u6570\
    \ n \u306E\u7B49\u6BD4\u6570\u5217\u306E\u548C\u3092\u8A08\u7B97\u3057\u307E\u3059\
    \ : O(log(nm))\ntemplate <typename T>\nT modgeometricsum(T a, T r, T n, T m){\n\
    \    a %= m;\n    if(r == 1){\n        n %= m;\n        return a * n % m;\n  \
    \  }\n    return a * (modpow(r, n, m) + m - 1) % m * modinv(r - 1, m) % m;\n}\n\
    \n// mod. m \u3067\u306E\u4E8C\u9805\u4FC2\u6570\u306A\u3069\u3092\u9AD8\u901F\
    \u3067\u8A08\u7B97\u3057\u307E\u3059 : O(N)\nstruct Combination{\n    vector<long\
    \ long> memo, memoinv, inv;\n    long long mod;\n\n    Combination(int N, long\
    \ long m) : memo(N + 1), memoinv(N + 1), inv(N + 1){\n        mod = m;\n     \
    \   memo[0] = memo[1] = 1;\n        memoinv[0] = memoinv[1] = 1;\n        inv[1]\
    \ = 1;\n        for(int i = 2; i <= N; i++){\n            memo[i] = memo[i - 1]\
    \ * i % mod;\n            inv[i] = mod - inv[mod % i] * (m / i) % mod;\n     \
    \       memoinv[i] = memoinv[i - 1] * inv[i] % mod;\n        }\n    }\n\n    long\
    \ long fact(long long n){\n        return memo[n];\n    }\n\n    long long factinv(long\
    \ long n){\n        return memoinv[n];\n    }\n\n    long long ncr(long long n,\
    \ long long r){\n        if(n < r || r < 0) return 0;\n        return (memo[n]\
    \ * memoinv[r] % mod) * memoinv[n - r] % mod;\n    }\n\n    long long npr(long\
    \ long n, long long r){\n        if(n < r || r < 0) return 0;\n        return\
    \ (memo[n] % mod) * memoinv[n - r] % mod;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/modcalc.cpp
  requiredBy: []
  timestamp: '2022-11-10 01:07:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/modcalc.cpp
layout: document
redirect_from:
- /library/lib/math/modcalc.cpp
- /library/lib/math/modcalc.cpp.html
title: lib/math/modcalc.cpp
---
