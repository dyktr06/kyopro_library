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
    \ modcalc{\n    using i64 = long long;\n\n    i64 modpow(i64 x, i64 n, const i64\
    \ &m){\n        i64 ret = 1 % m;\n        x %= m;\n        while(n > 0){\n   \
    \         if(n & 1) (ret *= x) %= m;\n            (x *= x) %= m;\n           \
    \ n >>= 1;\n        }\n        return ret;\n    }\n\n    i64 modinv(i64 a, const\
    \ i64 m){\n        i64 b = m, u = 1, v = 0;\n        while(b){\n            i64\
    \ t = a / b;\n            a -= t * b; std::swap(a, b);\n            u -= t * v;\
    \ std::swap(u, v);\n        }\n        u %= m;\n        if(u < 0) u += m;\n  \
    \      return u;\n    }\n\n    i64 modarithmeticsum(i64 a, i64 d, i64 n, const\
    \ i64 m){\n        i64 m2 = m * 2;\n        a %= m2, n %= m2, d %= m2;\n     \
    \   i64 b = (n + m2 - 1) * d % m2;\n        return ((n * (a * 2 + b) % m2) / 2)\
    \ % m;\n    }\n\n    i64 modgeometricsum(i64 a, i64 r, i64 n, const i64 m){\n\
    \        a %= m;\n        if(r == 1){\n            n %= m;\n            return\
    \ a * n % m;\n        }\n        return a * (modpow(r, n, m) + m - 1) % m * modinv(r\
    \ - 1, m) % m;\n    }\n\n    i64 modgeometricsum2(i64 a, i64 r, i64 n, const i64\
    \ m){\n        a %= m;\n        if(r == 1){\n            n %= m;\n           \
    \ return a * n % m;\n        }\n        i64 ret = 0;\n        i64 x = 1 % m;\n\
    \        i64 sum = 0;\n        for(int i = 0; n > 0; ++i){\n            if(n &\
    \ 1){\n                (ret += x * modpow(r, sum, m) % m) %= m;\n            \
    \    sum |= 1LL << i;\n            }\n            (x += x * modpow(r, 1LL << i,\
    \ m) % m) %= m;\n            n >>= 1;\n        }\n        return a * ret % m;\n\
    \    }\n\n    // https://37zigen.com/tonelli-shanks-algorithm/\n    i64 modsqrt(i64\
    \ a, const i64 p){\n        a %= p;\n        if(a <= 1) return a;\n        //\
    \ \u30AA\u30A4\u30E9\u30FC\u306E\u898F\u6E96\n        if(modpow(a, (p - 1) / 2,\
    \ p) != 1) return -1;\n        i64 b = 1;\n        while(modpow(b, (p - 1) / 2,\
    \ p) == 1) b++;\n        // p - 1 = m 2^e\n        i64 m = p - 1, e = 0;\n   \
    \     while(m % 2 == 0) m >>= 1, e++;\n        // x = a^((m + 1) / 2) (mod p)\n\
    \        i64 x = modpow(a, (m - 1) / 2, p);\n        // y = a^{-1} x^2 (mod p)\n\
    \        i64 y = a * x % p * x % p;\n        (x *= a) %= p;\n        i64 z = modpow(b,\
    \ m, p);\n        while(y != 1){\n            i64 j = 0, t = y;\n            while(t\
    \ != 1){\n                (t *= t) %= p;\n                j++;\n            }\n\
    \            // e - j \u30D3\u30C3\u30C8\u76EE\u304C 1\n            z = modpow(z,\
    \ 1LL << (e - j - 1), p);\n            (x *= z) %= p;\n            (z *= z) %=\
    \ p;\n            (y *= z) %= p;\n            e = j;\n        }\n        return\
    \ x;\n    }\n}\n#line 6 \"test/aoj/ntl/ntl_1_b.test.cpp\"\n\nint main(){\n   \
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
  timestamp: '2024-11-03 20:15:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ntl/ntl_1_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ntl/ntl_1_b.test.cpp
- /verify/test/aoj/ntl/ntl_1_b.test.cpp.html
title: test/aoj/ntl/ntl_1_b.test.cpp
---
