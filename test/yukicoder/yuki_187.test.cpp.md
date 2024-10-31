---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/math/crt.hpp
    title: "Chinese Remainder Theorem (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/187
    links:
    - https://yukicoder.me/problems/no/187
  bundledCode: "#line 1 \"test/yukicoder/yuki_187.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/187\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/crt.hpp\"\
    \n\n/**\n * @brief Chinese Remainder Theorem (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\
    )\n * @docs docs/math/crt.md\n */\n\nnamespace CRT{\n    inline long long mod(long\
    \ long a, long long m){\n        return (a % m + m) % m;\n    }\n\n    long long\
    \ extGCD(long long a, long long b, long long &x, long long &y){\n        if(b\
    \ == 0){\n            x = 1;\n            y = 0;\n            return a;\n    \
    \    }\n        long long d = extGCD(b, a % b, y, x);\n        y -= a / b * x;\n\
    \        return d;\n    }\n\n    pair<long long, long long> chineseRem(const vector<long\
    \ long> &b, const vector<long long> &m) {\n        long long r = 0, M = 1;\n \
    \       for(int i = 0; i < (int) b.size(); i++){\n            long long p, q;\n\
    \            long long d = extGCD(M, m[i], p, q);\n            if((b[i] - r) %\
    \ d != 0) return {0, -1};\n            long long tmp = (b[i] - r) / d * p % (m[i]\
    \ / d);\n            r += M * tmp;\n            M *= m[i] / d;\n        }\n  \
    \      r %= M;\n        if(r < 0) r += M;\n        return {r, M};\n    }\n\n \
    \   // not coprime\n    long long preGarner(vector<long long> &b, vector<long\
    \ long> &m, const long long MOD){\n        long long res = 1;\n        int n =\
    \ b.size();\n        for(int i = 0; i < n; i++){\n            for(int j = 0; j\
    \ < i; j++){\n                long long g = gcd(m[i], m[j]);\n               \
    \ if((b[i] - b[j]) % g != 0) return -1;\n                m[i] /= g, m[j] /= g;\n\
    \                // gcd \u306E\u5206\u3060\u3051\u88AB\u3063\u3066\u308B\u306E\
    \u3067\u632F\u308A\u5206\u3051\u308B\n                long long gi = gcd(m[i],\
    \ g), gj = g / gi;\n                do{\n                    g = gcd(gi, gj);\n\
    \                    gi *= g, gj /= g;\n                }while(g != 1);\n    \
    \            m[i] *= gi, m[j] *= gj;\n                b[i] %= m[i], b[j] %= m[j];\n\
    \            }\n        }\n        for(auto x : m) (res *= x) %= MOD;\n      \
    \  return res;\n    }\n\n    long long garner(const vector<long long> &b, const\
    \ vector<long long> &m, const long long MOD){\n        vector<long long> tm =\
    \ m;\n        tm.push_back(MOD);\n        auto inv = [&](long long a, long long\
    \ m) -> long long {\n            long long x, y;\n            extGCD(a, m, x,\
    \ y);\n            return mod(x, m);\n        };\n        int n = b.size();\n\
    \        vector<long long> coeffs(n + 1, 1), constants(n + 1, 0);\n        for(int\
    \ i = 0; i < n; i++){\n            // solve \"coeffs[i] * t[i] + constants[i]\
    \ = b[i] (mod. m[i])\n            long long t = mod((b[i] - constants[i]) * inv(coeffs[i],\
    \ tm[i]), tm[i]);\n            for(int j = i + 1; j < n + 1; j++){\n         \
    \       (constants[j] += t * coeffs[j]) %= tm[j];\n                (coeffs[j]\
    \ *= tm[i]) %= tm[j];\n            }\n        }\n        return constants[n];\n\
    \    }\n}\n#line 6 \"test/yukicoder/yuki_187.test.cpp\"\n\nconst long long MOD\
    \ = 1000000007;\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int n; cin >> n;\n    vector<long long> x(n), y(n);\n    int all_zero =\
    \ 1;\n    for(int i = 0; i < n; i++){\n        cin >> x[i] >> y[i];\n        if(x[i]\
    \ != 0) all_zero = 0;\n    }\n\n    long long l = CRT::preGarner(x, y, MOD);\n\
    \    if(l == -1) cout << -1 << \"\\n\";\n    else if(all_zero) cout << l << \"\
    \\n\";\n    else cout << CRT::garner(x, y, MOD) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/187\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../lib/math/crt.hpp\"\n\nconst long long\
    \ MOD = 1000000007;\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int n; cin >> n;\n    vector<long long> x(n), y(n);\n    int all_zero =\
    \ 1;\n    for(int i = 0; i < n; i++){\n        cin >> x[i] >> y[i];\n        if(x[i]\
    \ != 0) all_zero = 0;\n    }\n\n    long long l = CRT::preGarner(x, y, MOD);\n\
    \    if(l == -1) cout << -1 << \"\\n\";\n    else if(all_zero) cout << l << \"\
    \\n\";\n    else cout << CRT::garner(x, y, MOD) << \"\\n\";\n}\n"
  dependsOn:
  - lib/math/crt.hpp
  isVerificationFile: true
  path: test/yukicoder/yuki_187.test.cpp
  requiredBy: []
  timestamp: '2024-10-18 01:54:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/yuki_187.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki_187.test.cpp
- /verify/test/yukicoder/yuki_187.test.cpp.html
title: test/yukicoder/yuki_187.test.cpp
---