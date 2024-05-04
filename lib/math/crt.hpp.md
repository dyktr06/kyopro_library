---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/yuki_186.test.cpp
    title: test/yukicoder/yuki_186.test.cpp
  - icon: ':x:'
    path: test/yukicoder/yuki_2119.test.cpp
    title: test/yukicoder/yuki_2119.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/crt.md
    document_title: "Chinese Remainder Theorem (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\
      )"
    links: []
  bundledCode: "#line 2 \"lib/math/crt.hpp\"\n\n/**\n * @brief Chinese Remainder Theorem\
    \ (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)\n * @docs docs/math/crt.md\n */\n\nnamespace\
    \ CRT{\n    long long extGCD(long long a, long long b, long long &x, long long\
    \ &y){\n        if(b == 0){\n            x = 1;\n            y = 0;\n        \
    \    return a;\n        }\n        long long d = extGCD(b, a % b, y, x);\n   \
    \     y -= a / b * x;\n        return d;\n    }\n\n    pair<long long, long long>\
    \ chineseRem(const vector<long long> &b, const vector<long long> &m) {\n     \
    \   long long r = 0, M = 1;\n        for(int i = 0; i < (int) b.size(); i++){\n\
    \            long long p, q;\n            long long d = extGCD(M, m[i], p, q);\n\
    \            if((b[i] - r) % d != 0) return {0, -1};\n            long long tmp\
    \ = (b[i] - r) / d * p % (m[i] / d);\n            r += M * tmp;\n            M\
    \ *= m[i] / d;\n        }\n        r %= M;\n        if(r < 0) r += M;\n      \
    \  return {r, M};\n    }\n}\n"
  code: "#pragma once\n\n/**\n * @brief Chinese Remainder Theorem (\u4E2D\u56FD\u5270\
    \u4F59\u5B9A\u7406)\n * @docs docs/math/crt.md\n */\n\nnamespace CRT{\n    long\
    \ long extGCD(long long a, long long b, long long &x, long long &y){\n       \
    \ if(b == 0){\n            x = 1;\n            y = 0;\n            return a;\n\
    \        }\n        long long d = extGCD(b, a % b, y, x);\n        y -= a / b\
    \ * x;\n        return d;\n    }\n\n    pair<long long, long long> chineseRem(const\
    \ vector<long long> &b, const vector<long long> &m) {\n        long long r = 0,\
    \ M = 1;\n        for(int i = 0; i < (int) b.size(); i++){\n            long long\
    \ p, q;\n            long long d = extGCD(M, m[i], p, q);\n            if((b[i]\
    \ - r) % d != 0) return {0, -1};\n            long long tmp = (b[i] - r) / d *\
    \ p % (m[i] / d);\n            r += M * tmp;\n            M *= m[i] / d;\n   \
    \     }\n        r %= M;\n        if(r < 0) r += M;\n        return {r, M};\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/crt.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/yuki_186.test.cpp
  - test/yukicoder/yuki_2119.test.cpp
documentation_of: lib/math/crt.hpp
layout: document
redirect_from:
- /library/lib/math/crt.hpp
- /library/lib/math/crt.hpp.html
title: "Chinese Remainder Theorem (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)"
---
## Chinese Remainder Theorem (中国剰余定理)

#### 使い方

- `CRT::extGCD(a, b, x, y)`: $ax + by =$ gcd($a, b$) となる $x, y$ を求めます。
- `CRT::ChineseRem(b, m)`: 中国剰余定理の計算を行います。返り値を (r, m) とすると解は x ≡ r (mod. m)、解なしの場合は (0, -1) を返します。

注意: lcmのオーバーフローに注意する。

#### 計算量

- `CRT::extGCD(a, b, x, y)`: $\mathrm{O}(\log a)$
- `CRT::ChineseRem(b, m)`: $\mathrm{O}(N \log \mathrm{lcm}(m))$ (配列の長さを $N$ とする)