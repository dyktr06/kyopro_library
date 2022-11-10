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
  bundledCode: "#line 2 \"lib/math/baby-step_giant-step.hpp\"\n\n// x^k \u2261 y (mod\
    \ m) \u3068\u306A\u308B\u6700\u5C0F\u306E k \u3092\u6C42\u3081\u307E\u3059 : O(\u221A\
    M log M)\nlong long BabyStepGiantStep(long long x, long long y, long long m){\n\
    \    map<long long, long long> mp;\n\n    // Baby Step\n    long long z = 1, sq\
    \ = sqrtl(m) + 1;\n    for(int i = 0; i < sq; i++){\n        z *= x;\n       \
    \ z %= m;\n        mp[z] = i + 1;\n        if(mp.count(y) != 0) return mp[y];\n\
    \    }\n\n    // Giant Step\n    long long b = m, u = 1, v = 0;\n    while (b)\
    \ {\n        long long t = z / b;\n        z -= t * b; swap(z, b);\n        u\
    \ -= t * v; swap(u, v);\n    }\n    u %= m;\n    if (u < 0) u += m;\n\n    for(int\
    \ i = 1; i <= sq; i++){\n        y *= u;\n        y %= m;\n        if(mp.count(y)\
    \ != 0) return mp[y] + i * sq;\n    }\n    return -1;\n}\n"
  code: "#pragma once\n\n// x^k \u2261 y (mod m) \u3068\u306A\u308B\u6700\u5C0F\u306E\
    \ k \u3092\u6C42\u3081\u307E\u3059 : O(\u221AM log M)\nlong long BabyStepGiantStep(long\
    \ long x, long long y, long long m){\n    map<long long, long long> mp;\n\n  \
    \  // Baby Step\n    long long z = 1, sq = sqrtl(m) + 1;\n    for(int i = 0; i\
    \ < sq; i++){\n        z *= x;\n        z %= m;\n        mp[z] = i + 1;\n    \
    \    if(mp.count(y) != 0) return mp[y];\n    }\n\n    // Giant Step\n    long\
    \ long b = m, u = 1, v = 0;\n    while (b) {\n        long long t = z / b;\n \
    \       z -= t * b; swap(z, b);\n        u -= t * v; swap(u, v);\n    }\n    u\
    \ %= m;\n    if (u < 0) u += m;\n\n    for(int i = 1; i <= sq; i++){\n       \
    \ y *= u;\n        y %= m;\n        if(mp.count(y) != 0) return mp[y] + i * sq;\n\
    \    }\n    return -1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/baby-step_giant-step.hpp
  requiredBy: []
  timestamp: '2022-11-11 06:59:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/baby-step_giant-step.hpp
layout: document
redirect_from:
- /library/lib/math/baby-step_giant-step.hpp
- /library/lib/math/baby-step_giant-step.hpp.html
title: lib/math/baby-step_giant-step.hpp
---
