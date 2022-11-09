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
  bundledCode: "#line 1 \"lib/math/fraction.cpp\"\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\n// \u5206\u6570(p/q) \u306E\u69CB\u9020\u4F53\nstruct fraction{\n\
    \    long long p, q; // long long or __int128_t\n    fraction(long long P = 0,\
    \ long long Q = 1): p(P), q(Q){\n        normalize();\n    }\n    void normalize(){\n\
    \        long long g = __gcd(p, q);\n        p /= g, q /= g;\n        if(q < 0)\
    \ p *= -1, q *= -1;\n    }\n    inline bool operator<(const fraction &other) const\
    \ {\n        return p * other.q < other.p * q;\n    }\n    inline bool operator<=(const\
    \ fraction &other) const {\n        return p * other.q <= other.p * q;\n    }\n\
    \    inline fraction operator+(const fraction &other) const { return fraction(p\
    \ * other.q + q * other.p, q * other.q); }\n    inline fraction operator-(const\
    \ fraction &other) const { return fraction(p * other.q - q * other.p, q * other.q);\
    \ }\n    inline fraction operator*(const fraction &other) const { return fraction(p\
    \ * other.p, q * other.q); }\n    inline fraction operator/(const fraction &other)\
    \ const { return fraction(p * other.q, q * other.p); }\n};\n\nvoid example(){\n\
    \    int n; cin >> n;\n    vector<fraction> k(n);\n    k[0] = fraction(10, 3);\
    \ // 10/3\n    k[1] = fraction(24, 7); // 24/7\n    if(k[0] < k[1]){\n       \
    \ // \n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// \u5206\u6570(p/q)\
    \ \u306E\u69CB\u9020\u4F53\nstruct fraction{\n    long long p, q; // long long\
    \ or __int128_t\n    fraction(long long P = 0, long long Q = 1): p(P), q(Q){\n\
    \        normalize();\n    }\n    void normalize(){\n        long long g = __gcd(p,\
    \ q);\n        p /= g, q /= g;\n        if(q < 0) p *= -1, q *= -1;\n    }\n \
    \   inline bool operator<(const fraction &other) const {\n        return p * other.q\
    \ < other.p * q;\n    }\n    inline bool operator<=(const fraction &other) const\
    \ {\n        return p * other.q <= other.p * q;\n    }\n    inline fraction operator+(const\
    \ fraction &other) const { return fraction(p * other.q + q * other.p, q * other.q);\
    \ }\n    inline fraction operator-(const fraction &other) const { return fraction(p\
    \ * other.q - q * other.p, q * other.q); }\n    inline fraction operator*(const\
    \ fraction &other) const { return fraction(p * other.p, q * other.q); }\n    inline\
    \ fraction operator/(const fraction &other) const { return fraction(p * other.q,\
    \ q * other.p); }\n};\n\nvoid example(){\n    int n; cin >> n;\n    vector<fraction>\
    \ k(n);\n    k[0] = fraction(10, 3); // 10/3\n    k[1] = fraction(24, 7); // 24/7\n\
    \    if(k[0] < k[1]){\n        // \n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/fraction.cpp
  requiredBy: []
  timestamp: '2022-11-08 22:18:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/fraction.cpp
layout: document
redirect_from:
- /library/lib/math/fraction.cpp
- /library/lib/math/fraction.cpp.html
title: lib/math/fraction.cpp
---
