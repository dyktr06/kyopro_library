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
  bundledCode: "#line 1 \"lib/math/crt.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n// CRT::extGCD(a, b, x, y) : ax + by = gcd(a, b) \u3068\u306A\u308B\
    \ x, y \u3092\u6C42\u3081\u307E\u3059 : O(log a)\n// CRT::ChineseRem(b, m) : \u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\u3001\u8FD4\u308A\u5024\u3092 (r, m) \u3068\u3059\
    \u308B\u3068\u89E3\u306F x \u2261 r (mod. m)\u3001\u89E3\u306A\u3057\u306E\u5834\
    \u5408\u306F (0, -1) \u3092\u8FD4\u3057\u307E\u3059\nnamespace CRT{\n    long\
    \ long extGCD(long long a, long long b, long long &x, long long &y){\n       \
    \ if(b == 0){\n            x = 1;\n            y = 0;\n            return a;\n\
    \        }\n        long long d = extGCD(b, a % b, y, x);\n        y -= a / b\
    \ * x;\n        return d;\n    }\n\n    pair<long long, long long> ChineseRem(const\
    \ vector<long long> &b, const vector<long long> &m) {\n        long long r = 0,\
    \ M = 1;\n        for(int i = 0; i < (int) b.size(); i++){\n            long long\
    \ p, q;\n            long long d = extGCD(M, m[i], p, q);\n            if((b[i]\
    \ - r) % d != 0) return {0, -1};\n            long long tmp = (b[i] - r) / d *\
    \ p % (m[i] / d);\n            r += M * tmp;\n            M *= m[i] / d;\n   \
    \     }\n        r %= M;\n        if(r < 0) r += M;\n        return {r, M};\n\
    \    }\n}\n\n// example (\u4E2D\u83EF\u98A8 (Easy) (yukicoder))\nint main(){\n\
    \    vector<long long> b(3), m(3);\n    int cnt = 0;\n    for(int i = 0; i < 3;\
    \ i++){\n        cin >> b[i] >> m[i];\n        if(b[i] == 0) cnt++;\n    }\n \
    \   pair<long long, long long> p = CRT::ChineseRem(b, m);\n    if(p.second ==\
    \ -1){\n        cout << -1 << endl;\n    }else if(cnt == 3){\n        cout <<\
    \ p.second << endl;\n    }else{\n        cout << p.first << endl;\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// CRT::extGCD(a, b,\
    \ x, y) : ax + by = gcd(a, b) \u3068\u306A\u308B x, y \u3092\u6C42\u3081\u307E\
    \u3059 : O(log a)\n// CRT::ChineseRem(b, m) : \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\
    \u3001\u8FD4\u308A\u5024\u3092 (r, m) \u3068\u3059\u308B\u3068\u89E3\u306F x \u2261\
    \ r (mod. m)\u3001\u89E3\u306A\u3057\u306E\u5834\u5408\u306F (0, -1) \u3092\u8FD4\
    \u3057\u307E\u3059\nnamespace CRT{\n    long long extGCD(long long a, long long\
    \ b, long long &x, long long &y){\n        if(b == 0){\n            x = 1;\n \
    \           y = 0;\n            return a;\n        }\n        long long d = extGCD(b,\
    \ a % b, y, x);\n        y -= a / b * x;\n        return d;\n    }\n\n    pair<long\
    \ long, long long> ChineseRem(const vector<long long> &b, const vector<long long>\
    \ &m) {\n        long long r = 0, M = 1;\n        for(int i = 0; i < (int) b.size();\
    \ i++){\n            long long p, q;\n            long long d = extGCD(M, m[i],\
    \ p, q);\n            if((b[i] - r) % d != 0) return {0, -1};\n            long\
    \ long tmp = (b[i] - r) / d * p % (m[i] / d);\n            r += M * tmp;\n   \
    \         M *= m[i] / d;\n        }\n        r %= M;\n        if(r < 0) r += M;\n\
    \        return {r, M};\n    }\n}\n\n// example (\u4E2D\u83EF\u98A8 (Easy) (yukicoder))\n\
    int main(){\n    vector<long long> b(3), m(3);\n    int cnt = 0;\n    for(int\
    \ i = 0; i < 3; i++){\n        cin >> b[i] >> m[i];\n        if(b[i] == 0) cnt++;\n\
    \    }\n    pair<long long, long long> p = CRT::ChineseRem(b, m);\n    if(p.second\
    \ == -1){\n        cout << -1 << endl;\n    }else if(cnt == 3){\n        cout\
    \ << p.second << endl;\n    }else{\n        cout << p.first << endl;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/crt.cpp
  requiredBy: []
  timestamp: '2022-10-19 13:56:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/crt.cpp
layout: document
redirect_from:
- /library/lib/math/crt.cpp
- /library/lib/math/crt.cpp.html
title: lib/math/crt.cpp
---
