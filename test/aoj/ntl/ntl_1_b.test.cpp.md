---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/modcalc.hpp
    title: Mod Calculation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/aoj/ntl/ntl_1_b.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/modcalc.hpp\"\
    \n\n/**\n * @brief Mod Calculation\n * @docs docs/math/modcalc.md\n */\n\nnamespace\
    \ modcalc{\n\n    template <typename T>\n    T modpow(T x, T n, const T &m){\n\
    \        T ret = 1 % m;\n        x %= m;\n        while(n > 0){\n            if(n\
    \ & 1) (ret *= x) %= m;\n            (x *= x) %= m;\n            n >>= 1;\n  \
    \      }\n        return ret;\n    }\n\n    template <typename T>\n    T modinv(T\
    \ a, T m){\n        T b = m, u = 1, v = 0;\n        while(b){\n            T t\
    \ = a / b;\n            a -= t * b; swap(a, b);\n            u -= t * v; swap(u,\
    \ v);\n        }\n        u %= m;\n        if(u < 0) u += m;\n        return u;\n\
    \    }\n\n    template <typename T>\n    T modarithmeticsum(T a, T d, T n, T m){\n\
    \        T m2 = m * 2;\n        a %= m2, n %= m2, d %= m2;\n        T b = (n +\
    \ m2 - 1) * d % m2;\n        return ((n * (a * 2 + b) % m2) / 2) % m;\n    }\n\
    \n    template <typename T>\n    T modgeometricsum(T a, T r, T n, T m){\n    \
    \    a %= m;\n        if(r == 1){\n            n %= m;\n            return a *\
    \ n % m;\n        }\n        return a * (modpow(r, n, m) + m - 1) % m * modinv(r\
    \ - 1, m) % m;\n    }\n\n    template <typename T>\n    T modgeometricsum2(T a,\
    \ T r, T n, T m){\n        a %= m;\n        if(r == 1){\n            n %= m;\n\
    \            return a * n % m;\n        }\n        T ret = 0;\n        T x = 1\
    \ % m;\n        T sum = 0;\n        for(int i = 0; n > 0; ++i){\n            if(n\
    \ & 1){\n                (ret += x * modpow(r, sum, m) % m) %= m;\n          \
    \      sum |= 1LL << i;\n            }\n            (x += x * modpow(r, 1LL <<\
    \ i, m) % m) %= m;\n            n >>= 1;\n        }\n        return a * ret %\
    \ m;\n    }\n}\n#line 6 \"test/aoj/ntl/ntl_1_b.test.cpp\"\n\nint main(){\n   \
    \ ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    long long m, n; cin\
    \ >> m >> n;\n    cout << modcalc::modpow(m, n, 1000000007LL) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/modcalc.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   long long m, n; cin >> m >> n;\n    cout << modcalc::modpow(m, n, 1000000007LL)\
    \ << \"\\n\";\n}\n"
  dependsOn:
  - lib/math/modcalc.hpp
  isVerificationFile: true
  path: test/aoj/ntl/ntl_1_b.test.cpp
  requiredBy: []
  timestamp: '2024-05-06 22:04:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ntl/ntl_1_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ntl/ntl_1_b.test.cpp
- /verify/test/aoj/ntl/ntl_1_b.test.cpp.html
title: test/aoj/ntl/ntl_1_b.test.cpp
---
