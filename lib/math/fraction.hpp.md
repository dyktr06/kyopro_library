---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_1464.test.cpp
    title: test/yukicoder/yuki_1464.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/fraction.md
    document_title: Fraction
    links: []
  bundledCode: "#line 2 \"lib/math/fraction.hpp\"\n\n/**\n * @brief Fraction\n * @docs\
    \ docs/math/fraction.md\n */\n\nstruct fraction{\n    long long p, q; // long\
    \ long or __int128_t\n    fraction(long long P = 0, long long Q = 1): p(P), q(Q){\n\
    \        normalize();\n    }\n    void normalize(){\n        long long g = __gcd(p,\
    \ q);\n        p /= g, q /= g;\n        if(q < 0) p *= -1, q *= -1;\n    }\n \
    \   inline bool operator==(const fraction &other) const {\n        return p *\
    \ other.q == other.p * q;\n    }\n    inline bool operator!=(const fraction &other)\
    \ const {\n        return p * other.q != other.p * q;\n    }\n    inline bool\
    \ operator<(const fraction &other) const {\n        return p * other.q < other.p\
    \ * q;\n    }\n    inline bool operator<=(const fraction &other) const {\n   \
    \     return p * other.q <= other.p * q;\n    }\n    inline fraction operator+(const\
    \ fraction &other) const { return fraction(p * other.q + q * other.p, q * other.q);\
    \ }\n    inline fraction operator-(const fraction &other) const { return fraction(p\
    \ * other.q - q * other.p, q * other.q); }\n    inline fraction operator*(const\
    \ fraction &other) const { return fraction(p * other.p, q * other.q); }\n    inline\
    \ fraction operator/(const fraction &other) const { return fraction(p * other.q,\
    \ q * other.p); }\n    inline fraction& operator+=(const fraction& rhs) noexcept\
    \ {\n        *this = *this + rhs;\n        return *this;\n    }\n    inline fraction&\
    \ operator-=(const fraction& rhs) noexcept {\n        *this = *this - rhs;\n \
    \       return *this;\n    }\n    inline fraction& operator*=(const fraction&\
    \ rhs) noexcept {\n        *this = *this * rhs;\n        return *this;\n    }\n\
    \    inline fraction& operator/=(const fraction& rhs) noexcept {\n        *this\
    \ = *this / rhs;\n        return *this;\n    }\n    friend inline istream& operator>>(istream&\
    \ is, fraction& x) noexcept {\n        is >> x.p;\n        x.q = 1;\n        return\
    \ is;\n    }\n    friend inline ostream& operator<<(ostream& os, const fraction&\
    \ x) noexcept { return os << x.p << \"/\" << x.q; }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Fraction\n * @docs docs/math/fraction.md\n\
    \ */\n\nstruct fraction{\n    long long p, q; // long long or __int128_t\n   \
    \ fraction(long long P = 0, long long Q = 1): p(P), q(Q){\n        normalize();\n\
    \    }\n    void normalize(){\n        long long g = __gcd(p, q);\n        p /=\
    \ g, q /= g;\n        if(q < 0) p *= -1, q *= -1;\n    }\n    inline bool operator==(const\
    \ fraction &other) const {\n        return p * other.q == other.p * q;\n    }\n\
    \    inline bool operator!=(const fraction &other) const {\n        return p *\
    \ other.q != other.p * q;\n    }\n    inline bool operator<(const fraction &other)\
    \ const {\n        return p * other.q < other.p * q;\n    }\n    inline bool operator<=(const\
    \ fraction &other) const {\n        return p * other.q <= other.p * q;\n    }\n\
    \    inline fraction operator+(const fraction &other) const { return fraction(p\
    \ * other.q + q * other.p, q * other.q); }\n    inline fraction operator-(const\
    \ fraction &other) const { return fraction(p * other.q - q * other.p, q * other.q);\
    \ }\n    inline fraction operator*(const fraction &other) const { return fraction(p\
    \ * other.p, q * other.q); }\n    inline fraction operator/(const fraction &other)\
    \ const { return fraction(p * other.q, q * other.p); }\n    inline fraction& operator+=(const\
    \ fraction& rhs) noexcept {\n        *this = *this + rhs;\n        return *this;\n\
    \    }\n    inline fraction& operator-=(const fraction& rhs) noexcept {\n    \
    \    *this = *this - rhs;\n        return *this;\n    }\n    inline fraction&\
    \ operator*=(const fraction& rhs) noexcept {\n        *this = *this * rhs;\n \
    \       return *this;\n    }\n    inline fraction& operator/=(const fraction&\
    \ rhs) noexcept {\n        *this = *this / rhs;\n        return *this;\n    }\n\
    \    friend inline istream& operator>>(istream& is, fraction& x) noexcept {\n\
    \        is >> x.p;\n        x.q = 1;\n        return is;\n    }\n    friend inline\
    \ ostream& operator<<(ostream& os, const fraction& x) noexcept { return os <<\
    \ x.p << \"/\" << x.q; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/fraction.hpp
  requiredBy: []
  timestamp: '2023-05-02 19:05:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_1464.test.cpp
documentation_of: lib/math/fraction.hpp
layout: document
redirect_from:
- /library/lib/math/fraction.hpp
- /library/lib/math/fraction.hpp.html
title: Fraction
---
## Fraction

#### 概要

有理数を管理する構造体です。

四則演算と比較などの簡単なものしか実装していません。