---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/math/baby-step_giant-step.hpp
    title: Baby-step giant-step
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/library_checker/math/discrete_logarithm_mod.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/baby-step_giant-step.hpp\"\
    \n\n/**\n * @brief Baby-step giant-step\n * @docs docs/math/baby-step_giant-step.md\n\
    \ */\n\nlong long babyStepGiantStep(long long x, long long y, long long m){\n\
    \    auto inv = [](long long a, long long m) -> long long {\n        long long\
    \ b = m, u = 1, v = 0;\n        while(b){\n            long long t = a / b;\n\
    \            a -= t * b; swap(a, b);\n            u -= t * v; swap(u, v);\n  \
    \      }\n        u %= m;\n        if(u < 0) u += m;\n        return u;\n    };\n\
    \n    if((x %= m) < 0) x += m;\n    if((y %= m) < 0) y += m;\n\n    long long\
    \ offset, g, r = 1 % m;\n    for(offset = 0; (g = gcd(x, m)) > 1; ++offset){\n\
    \        if(y % g){\n            if(r == y) return offset;\n            return\
    \ -1;\n        }\n        y /= g;\n        m /= g;\n        (r *= (x / g)) %=\
    \ m;\n    }\n\n    if(m == 1) return offset;\n    (y *= inv(r, m)) %= m;\n\n \
    \   unordered_map<long long, long long> mp;\n    // Baby Step\n    long long z\
    \ = 1, sq = sqrtl(m) + 1;\n    for(int i = 0; i < sq; i++){\n        mp[z] = i;\n\
    \        if(mp.count(y) != 0) return offset + mp[y];\n        z *= x;\n      \
    \  z %= m;\n    }\n\n    // Giant Step\n    long long u = inv(z, m);\n    for(int\
    \ i = 1; i <= sq; i++){\n        (y *= u) %= m;\n        if(mp.count(y) != 0)\
    \ return offset + mp[y] + i * sq;\n    }\n    return -1;\n}\n\nlong long babyStepGiantStepP(long\
    \ long x, long long y, long long m){\n    auto inv = [](long long a, long long\
    \ m) -> long long {\n        long long b = m, u = 1, v = 0;\n        while(b){\n\
    \            long long t = a / b;\n            a -= t * b; swap(a, b);\n     \
    \       u -= t * v; swap(u, v);\n        }\n        u %= m;\n        if(u < 0)\
    \ u += m;\n        return u;\n    };\n\n    if((x %= m) < 0) x += m;\n    if((y\
    \ %= m) < 0) y += m;\n\n    long long offset, g, r = 1 % m;\n    for(offset =\
    \ 0; (g = gcd(x, m)) > 1; ++offset){\n        if(y % g && offset != 0){\n    \
    \        if(r == y) return offset;\n            return -1;\n        }\n      \
    \  y /= g;\n        m /= g;\n        (r *= (x / g)) %= m;\n    }\n\n    if(m ==\
    \ 1) return offset;\n    (y *= inv(r, m)) %= m;\n\n    unordered_map<long long,\
    \ long long> mp;\n    // Baby Step\n    long long z = 1, sq = sqrtl(m) + 1;\n\
    \    for(int i = 0; i < sq; i++){\n        mp[z] = i;\n        if(mp.count(y)\
    \ != 0 && offset + mp[y]) return offset + mp[y];\n        z *= x;\n        z %=\
    \ m;\n    }\n\n    // Giant Step\n    long long u = inv(z, m);\n    for(int i\
    \ = 1; i <= sq; i++){\n        (y *= u) %= m;\n        if(mp.count(y) != 0) return\
    \ offset + mp[y] + i * sq;\n    }\n    return -1;\n}\n#line 6 \"test/library_checker/math/discrete_logarithm_mod.test.cpp\"\
    \n\nint main(){\n    int t; cin >> t;\n    while(t--){\n        long long x, y,\
    \ m; cin >> x >> y >> m;\n        cout << babyStepGiantStep(x, y, m) << \"\\n\"\
    ;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/baby-step_giant-step.hpp\"\
    \n\nint main(){\n    int t; cin >> t;\n    while(t--){\n        long long x, y,\
    \ m; cin >> x >> y >> m;\n        cout << babyStepGiantStep(x, y, m) << \"\\n\"\
    ;\n    }\n}"
  dependsOn:
  - lib/math/baby-step_giant-step.hpp
  isVerificationFile: true
  path: test/library_checker/math/discrete_logarithm_mod.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/math/discrete_logarithm_mod.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/discrete_logarithm_mod.test.cpp
- /verify/test/library_checker/math/discrete_logarithm_mod.test.cpp.html
title: test/library_checker/math/discrete_logarithm_mod.test.cpp
---
