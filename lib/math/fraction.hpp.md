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
  bundledCode: "#line 2 \"lib/math/fraction.hpp\"\n\n/*\n    \u5206\u6570(p/q) \u306E\
    \u69CB\u9020\u4F53\n*/\nstruct fraction{\n    long long p, q; // long long or\
    \ __int128_t\n    fraction(long long P = 0, long long Q = 1): p(P), q(Q){\n  \
    \      normalize();\n    }\n    void normalize(){\n        long long g = __gcd(p,\
    \ q);\n        p /= g, q /= g;\n        if(q < 0) p *= -1, q *= -1;\n    }\n \
    \   inline bool operator<(const fraction &other) const {\n        return p * other.q\
    \ < other.p * q;\n    }\n    inline bool operator<=(const fraction &other) const\
    \ {\n        return p * other.q <= other.p * q;\n    }\n    inline fraction operator+(const\
    \ fraction &other) const { return fraction(p * other.q + q * other.p, q * other.q);\
    \ }\n    inline fraction operator-(const fraction &other) const { return fraction(p\
    \ * other.q - q * other.p, q * other.q); }\n    inline fraction operator*(const\
    \ fraction &other) const { return fraction(p * other.p, q * other.q); }\n    inline\
    \ fraction operator/(const fraction &other) const { return fraction(p * other.q,\
    \ q * other.p); }\n};\n"
  code: "#pragma once\n\n/*\n    \u5206\u6570(p/q) \u306E\u69CB\u9020\u4F53\n*/\n\
    struct fraction{\n    long long p, q; // long long or __int128_t\n    fraction(long\
    \ long P = 0, long long Q = 1): p(P), q(Q){\n        normalize();\n    }\n   \
    \ void normalize(){\n        long long g = __gcd(p, q);\n        p /= g, q /=\
    \ g;\n        if(q < 0) p *= -1, q *= -1;\n    }\n    inline bool operator<(const\
    \ fraction &other) const {\n        return p * other.q < other.p * q;\n    }\n\
    \    inline bool operator<=(const fraction &other) const {\n        return p *\
    \ other.q <= other.p * q;\n    }\n    inline fraction operator+(const fraction\
    \ &other) const { return fraction(p * other.q + q * other.p, q * other.q); }\n\
    \    inline fraction operator-(const fraction &other) const { return fraction(p\
    \ * other.q - q * other.p, q * other.q); }\n    inline fraction operator*(const\
    \ fraction &other) const { return fraction(p * other.p, q * other.q); }\n    inline\
    \ fraction operator/(const fraction &other) const { return fraction(p * other.q,\
    \ q * other.p); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/fraction.hpp
  requiredBy: []
  timestamp: '2022-11-11 07:14:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/fraction.hpp
layout: document
redirect_from:
- /library/lib/math/fraction.hpp
- /library/lib/math/fraction.hpp.html
title: lib/math/fraction.hpp
---