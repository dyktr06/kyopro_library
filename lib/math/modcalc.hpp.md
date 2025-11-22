---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ntl/ntl_1_b.test.cpp
    title: test/aoj/ntl/ntl_1_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/number_theory/sqrt_mod.test.cpp
    title: test/library_checker/number_theory/sqrt_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/modcalc.md
    document_title: Mod Calculation
    links:
    - https://37zigen.com/tonelli-shanks-algorithm/
  bundledCode: "#line 2 \"lib/math/modcalc.hpp\"\n\n/**\n * @brief Mod Calculation\n\
    \ * @docs docs/math/modcalc.md\n */\n\nnamespace modcalc{\n    using i64 = long\
    \ long;\n\n    i64 modpow(i64 x, i64 n, const i64 &m){\n        i64 ret = 1 %\
    \ m;\n        x %= m;\n        while(n > 0){\n            if(n & 1) (ret *= x)\
    \ %= m;\n            (x *= x) %= m;\n            n >>= 1;\n        }\n       \
    \ return ret;\n    }\n\n    i64 modinv(i64 a, const i64 m){\n        i64 b = m,\
    \ u = 1, v = 0;\n        while(b){\n            i64 t = a / b;\n            a\
    \ -= t * b; std::swap(a, b);\n            u -= t * v; std::swap(u, v);\n     \
    \   }\n        u %= m;\n        if(u < 0) u += m;\n        return u;\n    }\n\n\
    \    i64 modarithmeticsum(i64 a, i64 d, i64 n, const i64 m){\n        i64 m2 =\
    \ m * 2;\n        a %= m2, n %= m2, d %= m2;\n        i64 b = (n + m2 - 1) * d\
    \ % m2;\n        return ((n * (a * 2 + b) % m2) / 2) % m;\n    }\n\n    i64 modgeometricsum(i64\
    \ a, i64 r, i64 n, const i64 m){\n        a %= m;\n        if(r == 1){\n     \
    \       n %= m;\n            return a * n % m;\n        }\n        return a *\
    \ (modpow(r, n, m) + m - 1) % m * modinv(r - 1, m) % m;\n    }\n\n    i64 modgeometricsum2(i64\
    \ a, i64 r, i64 n, const i64 m){\n        a %= m;\n        if(r == 1){\n     \
    \       n %= m;\n            return a * n % m;\n        }\n        i64 ret = 0;\n\
    \        i64 x = 1 % m;\n        i64 sum = 0;\n        for(int i = 0; n > 0; ++i){\n\
    \            if(n & 1){\n                (ret += x * modpow(r, sum, m) % m) %=\
    \ m;\n                sum |= 1LL << i;\n            }\n            (x += x * modpow(r,\
    \ 1LL << i, m) % m) %= m;\n            n >>= 1;\n        }\n        return a *\
    \ ret % m;\n    }\n\n    // https://37zigen.com/tonelli-shanks-algorithm/\n  \
    \  i64 modsqrt(i64 a, const i64 p){\n        a %= p;\n        if(a <= 1) return\
    \ a;\n        // \u30AA\u30A4\u30E9\u30FC\u306E\u898F\u6E96\n        if(modpow(a,\
    \ (p - 1) / 2, p) != 1) return -1;\n        i64 b = 1;\n        while(modpow(b,\
    \ (p - 1) / 2, p) == 1) b++;\n        // p - 1 = m 2^e\n        i64 m = p - 1,\
    \ e = 0;\n        while(m % 2 == 0) m >>= 1, e++;\n        // x = a^((m + 1) /\
    \ 2) (mod p)\n        i64 x = modpow(a, (m - 1) / 2, p);\n        // y = a^{-1}\
    \ x^2 (mod p)\n        i64 y = a * x % p * x % p;\n        (x *= a) %= p;\n  \
    \      i64 z = modpow(b, m, p);\n        while(y != 1){\n            i64 j = 0,\
    \ t = y;\n            while(t != 1){\n                (t *= t) %= p;\n       \
    \         j++;\n            }\n            // e - j \u30D3\u30C3\u30C8\u76EE\u304C\
    \ 1\n            z = modpow(z, 1LL << (e - j - 1), p);\n            (x *= z) %=\
    \ p;\n            (z *= z) %= p;\n            (y *= z) %= p;\n            e =\
    \ j;\n        }\n        return x;\n    }\n}\n"
  code: "#pragma once\n\n/**\n * @brief Mod Calculation\n * @docs docs/math/modcalc.md\n\
    \ */\n\nnamespace modcalc{\n    using i64 = long long;\n\n    i64 modpow(i64 x,\
    \ i64 n, const i64 &m){\n        i64 ret = 1 % m;\n        x %= m;\n        while(n\
    \ > 0){\n            if(n & 1) (ret *= x) %= m;\n            (x *= x) %= m;\n\
    \            n >>= 1;\n        }\n        return ret;\n    }\n\n    i64 modinv(i64\
    \ a, const i64 m){\n        i64 b = m, u = 1, v = 0;\n        while(b){\n    \
    \        i64 t = a / b;\n            a -= t * b; std::swap(a, b);\n          \
    \  u -= t * v; std::swap(u, v);\n        }\n        u %= m;\n        if(u < 0)\
    \ u += m;\n        return u;\n    }\n\n    i64 modarithmeticsum(i64 a, i64 d,\
    \ i64 n, const i64 m){\n        i64 m2 = m * 2;\n        a %= m2, n %= m2, d %=\
    \ m2;\n        i64 b = (n + m2 - 1) * d % m2;\n        return ((n * (a * 2 + b)\
    \ % m2) / 2) % m;\n    }\n\n    i64 modgeometricsum(i64 a, i64 r, i64 n, const\
    \ i64 m){\n        a %= m;\n        if(r == 1){\n            n %= m;\n       \
    \     return a * n % m;\n        }\n        return a * (modpow(r, n, m) + m -\
    \ 1) % m * modinv(r - 1, m) % m;\n    }\n\n    i64 modgeometricsum2(i64 a, i64\
    \ r, i64 n, const i64 m){\n        a %= m;\n        if(r == 1){\n            n\
    \ %= m;\n            return a * n % m;\n        }\n        i64 ret = 0;\n    \
    \    i64 x = 1 % m;\n        i64 sum = 0;\n        for(int i = 0; n > 0; ++i){\n\
    \            if(n & 1){\n                (ret += x * modpow(r, sum, m) % m) %=\
    \ m;\n                sum |= 1LL << i;\n            }\n            (x += x * modpow(r,\
    \ 1LL << i, m) % m) %= m;\n            n >>= 1;\n        }\n        return a *\
    \ ret % m;\n    }\n\n    // https://37zigen.com/tonelli-shanks-algorithm/\n  \
    \  i64 modsqrt(i64 a, const i64 p){\n        a %= p;\n        if(a <= 1) return\
    \ a;\n        // \u30AA\u30A4\u30E9\u30FC\u306E\u898F\u6E96\n        if(modpow(a,\
    \ (p - 1) / 2, p) != 1) return -1;\n        i64 b = 1;\n        while(modpow(b,\
    \ (p - 1) / 2, p) == 1) b++;\n        // p - 1 = m 2^e\n        i64 m = p - 1,\
    \ e = 0;\n        while(m % 2 == 0) m >>= 1, e++;\n        // x = a^((m + 1) /\
    \ 2) (mod p)\n        i64 x = modpow(a, (m - 1) / 2, p);\n        // y = a^{-1}\
    \ x^2 (mod p)\n        i64 y = a * x % p * x % p;\n        (x *= a) %= p;\n  \
    \      i64 z = modpow(b, m, p);\n        while(y != 1){\n            i64 j = 0,\
    \ t = y;\n            while(t != 1){\n                (t *= t) %= p;\n       \
    \         j++;\n            }\n            // e - j \u30D3\u30C3\u30C8\u76EE\u304C\
    \ 1\n            z = modpow(z, 1LL << (e - j - 1), p);\n            (x *= z) %=\
    \ p;\n            (z *= z) %= p;\n            (y *= z) %= p;\n            e =\
    \ j;\n        }\n        return x;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/modcalc.hpp
  requiredBy: []
  timestamp: '2024-11-03 20:15:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/number_theory/sqrt_mod.test.cpp
  - test/aoj/ntl/ntl_1_b.test.cpp
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