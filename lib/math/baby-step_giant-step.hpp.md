---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/baby-step_giant-step.hpp\"\n\n/*\n    x^k \u2261\
    \ y (mod m) \u3068\u306A\u308B\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570 k \u3092\
    \u6C42\u3081\u307E\u3059 : O(\u221AM)\n*/\n\nlong long babyStepGiantStep(long\
    \ long x, long long y, long long m){\n    auto inv = [](long long a, long long\
    \ m) -> long long {\n        long long b = m, u = 1, v = 0;\n        while(b){\n\
    \            long long t = a / b;\n            a -= t * b; swap(a, b);\n     \
    \       u -= t * v; swap(u, v);\n        }\n        u %= m;\n        if (u < 0)\
    \ u += m;\n        return u;\n    };\n\n    if((x %= m) < 0) x += m;\n    if((y\
    \ %= m) < 0) y += m;\n\n    long long offset, g, r = 1 % m;\n    for(offset =\
    \ 0; (g = gcd(x, m)) > 1; ++offset){\n        if(y % g){\n            if(r ==\
    \ y) return offset;\n            return -1;\n        }\n        y /= g;\n    \
    \    m /= g;\n        (r *= (x / g)) %= m;\n    }\n\n    if(m == 1) return offset;\n\
    \    (y *= inv(r, m)) %= m;\n    \n    unordered_map<long long, long long> mp;\n\
    \    // Baby Step\n    long long z = 1, sq = sqrtl(m) + 1;\n    for(int i = 0;\
    \ i < sq; i++){\n        mp[z] = i;\n        if(mp.count(y) != 0) return offset\
    \ + mp[y];\n        z *= x;\n        z %= m;\n    }\n\n    // Giant Step\n   \
    \ long long u = inv(z, m);\n    for(int i = 1; i <= sq; i++){\n        (y *= u)\
    \ %= m;\n        if(mp.count(y) != 0) return offset + mp[y] + i * sq;\n    }\n\
    \    return -1;\n}\n"
  code: "#pragma once\n\n/*\n    x^k \u2261 y (mod m) \u3068\u306A\u308B\u6700\u5C0F\
    \u306E\u975E\u8CA0\u6574\u6570 k \u3092\u6C42\u3081\u307E\u3059 : O(\u221AM)\n\
    */\n\nlong long babyStepGiantStep(long long x, long long y, long long m){\n  \
    \  auto inv = [](long long a, long long m) -> long long {\n        long long b\
    \ = m, u = 1, v = 0;\n        while(b){\n            long long t = a / b;\n  \
    \          a -= t * b; swap(a, b);\n            u -= t * v; swap(u, v);\n    \
    \    }\n        u %= m;\n        if (u < 0) u += m;\n        return u;\n    };\n\
    \n    if((x %= m) < 0) x += m;\n    if((y %= m) < 0) y += m;\n\n    long long\
    \ offset, g, r = 1 % m;\n    for(offset = 0; (g = gcd(x, m)) > 1; ++offset){\n\
    \        if(y % g){\n            if(r == y) return offset;\n            return\
    \ -1;\n        }\n        y /= g;\n        m /= g;\n        (r *= (x / g)) %=\
    \ m;\n    }\n\n    if(m == 1) return offset;\n    (y *= inv(r, m)) %= m;\n   \
    \ \n    unordered_map<long long, long long> mp;\n    // Baby Step\n    long long\
    \ z = 1, sq = sqrtl(m) + 1;\n    for(int i = 0; i < sq; i++){\n        mp[z] =\
    \ i;\n        if(mp.count(y) != 0) return offset + mp[y];\n        z *= x;\n \
    \       z %= m;\n    }\n\n    // Giant Step\n    long long u = inv(z, m);\n  \
    \  for(int i = 1; i <= sq; i++){\n        (y *= u) %= m;\n        if(mp.count(y)\
    \ != 0) return offset + mp[y] + i * sq;\n    }\n    return -1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/baby-step_giant-step.hpp
  requiredBy: []
  timestamp: '2022-12-24 18:31:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
documentation_of: lib/math/baby-step_giant-step.hpp
layout: document
redirect_from:
- /library/lib/math/baby-step_giant-step.hpp
- /library/lib/math/baby-step_giant-step.hpp.html
title: lib/math/baby-step_giant-step.hpp
---
