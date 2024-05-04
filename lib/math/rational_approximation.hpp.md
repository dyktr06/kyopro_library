---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/math/fraction.hpp
    title: Fraction
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/rational_approximation.test.cpp
    title: test/library_checker/math/rational_approximation.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/rational_approximation.md
    document_title: "Rational Approximation (\u6709\u7406\u6570\u8FD1\u4F3C)"
    links: []
  bundledCode: "#line 2 \"lib/math/rational_approximation.hpp\"\n\n/**\n * @brief\
    \ Rational Approximation (\u6709\u7406\u6570\u8FD1\u4F3C)\n * @docs docs/math/rational_approximation.md\n\
    \ */\n\n#line 2 \"lib/math/fraction.hpp\"\n\n/**\n * @brief Fraction\n * @docs\
    \ docs/math/fraction.md\n */\n\ntemplate <typename T>\nstruct fraction{\n    T\
    \ p, q; // long long or BigInt\n    fraction(T P = 0, T Q = 1) : p(P), q(Q){\n\
    \        normalize();\n    }\n    void normalize(){\n        T g = __gcd(p, q);\n\
    \        p /= g, q /= g;\n        if(q < 0) p *= -1, q *= -1;\n    }\n    inline\
    \ bool operator==(const fraction &other) const {\n        return p * other.q ==\
    \ other.p * q;\n    }\n    inline bool operator!=(const fraction &other) const\
    \ {\n        return p * other.q != other.p * q;\n    }\n    inline bool operator<(const\
    \ fraction &other) const {\n        return p * other.q < other.p * q;\n    }\n\
    \    inline bool operator<=(const fraction &other) const {\n        return p *\
    \ other.q <= other.p * q;\n    }\n    inline bool operator>(const fraction &other)\
    \ const {\n        return p * other.q > other.p * q;\n    }\n    inline bool operator>=(const\
    \ fraction &other) const {\n        return p * other.q >= other.p * q;\n    }\n\
    \    inline fraction operator+(const fraction &other) const { return fraction(p\
    \ * other.q + q * other.p, q * other.q); }\n    inline fraction operator-(const\
    \ fraction &other) const { return fraction(p * other.q - q * other.p, q * other.q);\
    \ }\n    inline fraction operator*(const fraction &other) const { return fraction(p\
    \ * other.p, q * other.q); }\n    inline fraction operator/(const fraction &other)\
    \ const { return fraction(p * other.q, q * other.p); }\n    inline fraction &operator+=(const\
    \ fraction &rhs) noexcept {\n        *this = *this + rhs;\n        return *this;\n\
    \    }\n    inline fraction &operator-=(const fraction &rhs) noexcept {\n    \
    \    *this = *this - rhs;\n        return *this;\n    }\n    inline fraction &operator*=(const\
    \ fraction &rhs) noexcept {\n        *this = *this * rhs;\n        return *this;\n\
    \    }\n    inline fraction &operator/=(const fraction &rhs) noexcept {\n    \
    \    *this = *this / rhs;\n        return *this;\n    }\n    friend inline istream\
    \ &operator>>(istream &is, fraction &x) noexcept {\n        is >> x.p;\n     \
    \   x.q = 1;\n        return is;\n    }\n    friend inline ostream &operator<<(ostream\
    \ &os, const fraction &x) noexcept { return os << x.p << \"/\" << x.q; }\n};\n\
    #line 9 \"lib/math/rational_approximation.hpp\"\n\ntemplate <typename T>\npair<fraction<T>,\
    \ fraction<T>> rationalApproximation(T n, fraction<T> p){\n    fraction<T> a(0,\
    \ 1), b(1, 0);\n    fraction<T> x(0, 1), y(1, 0);\n    bool ok_left = true, ok_right\
    \ = true;\n    while(ok_left && ok_right){\n        fraction<T> m(a.p + b.p, a.q\
    \ + b.q);\n        if(p < m){\n            T ok = 0, ng = n;\n            while(ng\
    \ - ok > 1){\n                T mid = (ok + ng) / 2;\n                fraction<T>\
    \ m2(a.p * mid + b.p, a.q * mid + b.q);\n                if(p < m2 && m2.p <=\
    \ n && m2.q <= n){\n                    ok = mid;\n                    m = m2;\n\
    \                } else{\n                    ng = mid;\n                }\n \
    \           }\n            b = m;\n            if(m.p <= n && m.q <= n){\n   \
    \             y = m;\n            } else{\n                ok_left = false;\n\
    \            }\n        } else{\n            T ok = 0, ng = n;\n            while(ng\
    \ - ok > 1){\n                T mid = (ok + ng) / 2;\n                fraction<T>\
    \ m2(a.p + b.p * mid, a.q + b.q * mid);\n                if(p >= m2 && m2.p <=\
    \ n && m2.q <= n){\n                    ok = mid;\n                    m = m2;\n\
    \                } else{\n                    ng = mid;\n                }\n \
    \           }\n            a = m;\n            if(m.p <= n && m.q <= n){\n   \
    \             x = m;\n            } else{\n                ok_right = false;\n\
    \            }\n        }\n    }\n    return make_pair(x, y);\n}\n"
  code: "#pragma once\n\n/**\n * @brief Rational Approximation (\u6709\u7406\u6570\
    \u8FD1\u4F3C)\n * @docs docs/math/rational_approximation.md\n */\n\n#include \"\
    ../math/fraction.hpp\"\n\ntemplate <typename T>\npair<fraction<T>, fraction<T>>\
    \ rationalApproximation(T n, fraction<T> p){\n    fraction<T> a(0, 1), b(1, 0);\n\
    \    fraction<T> x(0, 1), y(1, 0);\n    bool ok_left = true, ok_right = true;\n\
    \    while(ok_left && ok_right){\n        fraction<T> m(a.p + b.p, a.q + b.q);\n\
    \        if(p < m){\n            T ok = 0, ng = n;\n            while(ng - ok\
    \ > 1){\n                T mid = (ok + ng) / 2;\n                fraction<T> m2(a.p\
    \ * mid + b.p, a.q * mid + b.q);\n                if(p < m2 && m2.p <= n && m2.q\
    \ <= n){\n                    ok = mid;\n                    m = m2;\n       \
    \         } else{\n                    ng = mid;\n                }\n        \
    \    }\n            b = m;\n            if(m.p <= n && m.q <= n){\n          \
    \      y = m;\n            } else{\n                ok_left = false;\n       \
    \     }\n        } else{\n            T ok = 0, ng = n;\n            while(ng\
    \ - ok > 1){\n                T mid = (ok + ng) / 2;\n                fraction<T>\
    \ m2(a.p + b.p * mid, a.q + b.q * mid);\n                if(p >= m2 && m2.p <=\
    \ n && m2.q <= n){\n                    ok = mid;\n                    m = m2;\n\
    \                } else{\n                    ng = mid;\n                }\n \
    \           }\n            a = m;\n            if(m.p <= n && m.q <= n){\n   \
    \             x = m;\n            } else{\n                ok_right = false;\n\
    \            }\n        }\n    }\n    return make_pair(x, y);\n}\n"
  dependsOn:
  - lib/math/fraction.hpp
  isVerificationFile: false
  path: lib/math/rational_approximation.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/rational_approximation.test.cpp
documentation_of: lib/math/rational_approximation.hpp
layout: document
redirect_from:
- /library/lib/math/rational_approximation.hpp
- /library/lib/math/rational_approximation.hpp.html
title: "Rational Approximation (\u6709\u7406\u6570\u8FD1\u4F3C)"
---
## Rational Approximation (有理数近似)

#### 概要

分子、分母がともに $N$ 以下である既約分数において、分数 $p$ 以下で最大のものと $p$ より大きいもので最小のものを求めます。

見つからなかった場合には、$0/1$, $1/0$ がそれぞれ返り値となります。

#### 計算量

- $\mathrm{O}(\log N)$