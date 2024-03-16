---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/modcalc.md
    document_title: Mod Calculation
    links: []
  bundledCode: "#line 2 \"lib/math/modcalc.hpp\"\n\n/**\n * @brief Mod Calculation\n\
    \ * @docs docs/math/modcalc.md\n */\n\nnamespace modcalc{\n\n    template <typename\
    \ T>\n    T modpow(T x, T n, const T &m){\n        T ret = 1 % m;\n        x %=\
    \ m;\n        while(n > 0){\n            if(n & 1) (ret *= x) %= m;\n        \
    \    (x *= x) %= m;\n            n >>= 1;\n        }\n        return ret;\n  \
    \  }\n\n    template <typename T>\n    T modinv(T a, T m){\n        T b = m, u\
    \ = 1, v = 0;\n        while(b){\n            T t = a / b;\n            a -= t\
    \ * b; swap(a, b);\n            u -= t * v; swap(u, v);\n        }\n        u\
    \ %= m;\n        if (u < 0) u += m;\n        return u;\n    }\n\n    template\
    \ <typename T>\n    T modarithmeticsum(T a, T d, T n, T m){\n        T m2 = m\
    \ * 2;\n        a %= m2, n %= m2, d %= m2;\n        T b = (n + m2 - 1) * d % m2;\n\
    \        return ((n * (a * 2 + b) % m2) / 2) % m;\n    }\n\n    template <typename\
    \ T>\n    T modgeometricsum(T a, T r, T n, T m){\n        a %= m;\n        if(r\
    \ == 1){\n            n %= m;\n            return a * n % m;\n        }\n    \
    \    return a * (modpow(r, n, m) + m - 1) % m * modinv(r - 1, m) % m;\n    }\n\
    \n    template <typename T>\n    T modgeometricsum2(T a, T r, T n, T m){\n   \
    \     a %= m;\n        if(r == 1){\n            n %= m;\n            return a\
    \ * n % m;\n        }\n        T ret = 0;\n        T x = 1 % m;\n        T sum\
    \ = 0;\n        for(int i = 0; n > 0; ++i){\n            if(n & 1){\n        \
    \        (ret += x * modpow(r, sum, m) % m) %= m;\n                sum |= 1LL\
    \ << i;\n            }\n            (x += x * modpow(r, 1LL << i, m) % m) %= m;\n\
    \            n >>= 1;\n        }\n        return a * ret % m;\n    }\n}\n"
  code: "#pragma once\n\n/**\n * @brief Mod Calculation\n * @docs docs/math/modcalc.md\n\
    \ */\n\nnamespace modcalc{\n\n    template <typename T>\n    T modpow(T x, T n,\
    \ const T &m){\n        T ret = 1 % m;\n        x %= m;\n        while(n > 0){\n\
    \            if(n & 1) (ret *= x) %= m;\n            (x *= x) %= m;\n        \
    \    n >>= 1;\n        }\n        return ret;\n    }\n\n    template <typename\
    \ T>\n    T modinv(T a, T m){\n        T b = m, u = 1, v = 0;\n        while(b){\n\
    \            T t = a / b;\n            a -= t * b; swap(a, b);\n            u\
    \ -= t * v; swap(u, v);\n        }\n        u %= m;\n        if (u < 0) u += m;\n\
    \        return u;\n    }\n\n    template <typename T>\n    T modarithmeticsum(T\
    \ a, T d, T n, T m){\n        T m2 = m * 2;\n        a %= m2, n %= m2, d %= m2;\n\
    \        T b = (n + m2 - 1) * d % m2;\n        return ((n * (a * 2 + b) % m2)\
    \ / 2) % m;\n    }\n\n    template <typename T>\n    T modgeometricsum(T a, T\
    \ r, T n, T m){\n        a %= m;\n        if(r == 1){\n            n %= m;\n \
    \           return a * n % m;\n        }\n        return a * (modpow(r, n, m)\
    \ + m - 1) % m * modinv(r - 1, m) % m;\n    }\n\n    template <typename T>\n \
    \   T modgeometricsum2(T a, T r, T n, T m){\n        a %= m;\n        if(r ==\
    \ 1){\n            n %= m;\n            return a * n % m;\n        }\n       \
    \ T ret = 0;\n        T x = 1 % m;\n        T sum = 0;\n        for(int i = 0;\
    \ n > 0; ++i){\n            if(n & 1){\n                (ret += x * modpow(r,\
    \ sum, m) % m) %= m;\n                sum |= 1LL << i;\n            }\n      \
    \      (x += x * modpow(r, 1LL << i, m) % m) %= m;\n            n >>= 1;\n   \
    \     }\n        return a * ret % m;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/modcalc.hpp
  requiredBy: []
  timestamp: '2024-03-17 05:01:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/modcalc.hpp
layout: document
redirect_from:
- /library/lib/math/modcalc.hpp
- /library/lib/math/modcalc.hpp.html
title: Mod Calculation
---
## Mod Calculation

### 概要

Mod に関する計算のアルゴリズムの詰め合わせです。

#### 使い方

- `modcalc::modpow(x, n, m)`: $x^n$ (mod. m) を計算します。
- `modcalc::modinv(a, m)`: $a$ の逆元 (mod. m) を計算します。
- `modcalc::modarithmeticsum(a, d, n, m)`: 初項 $a$, 公差 $d$, 項数 $n$ の等差数列の和 (mod. m) を計算します。（任意 mod で計算できます）
- `modcalc::modgeometricsum(a, r, n, m)`: 初項 $a$, 公比 $r$, 項数 $n$ の等比数列の和 (mod. m) を計算します。（素数 mod のみで計算できます）
- `modcalc::modgeometricsum2(a, r, n, m)`: 初項 $a$, 公比 $r$, 項数 $n$ の等比数列の和 (mod. m) を計算します。（任意 mod で計算できます）

#### 計算量

- `modcalc::modpow(x, n, m)`: $\mathrm{O}(\log n)$
- `modcalc::modinv(a, m)`: $\mathrm{O}(\log m)$
- `modcalc::modarithmeticsum(a, d, n, m)`: $\mathrm{O}(1)$
- `modcalc::modgeometricsum(a, r, n, m)`: $\mathrm{O}(\log nm)$
- `modcalc::modgeometricsum2(a, r, n, m)`: $\mathrm{O}(\log n^2)$