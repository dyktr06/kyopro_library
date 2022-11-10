---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/math/crt.hpp
    title: lib/math/crt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/186
    links:
    - https://yukicoder.me/problems/no/186
  bundledCode: "#line 1 \"test/yukicoder/yuki_186.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/186\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/crt.hpp\"\
    \n\n// CRT::extGCD(a, b, x, y) : ax + by = gcd(a, b) \u3068\u306A\u308B x, y \u3092\
    \u6C42\u3081\u307E\u3059 : O(log a)\n// CRT::ChineseRem(b, m) : \u4E2D\u56FD\u5270\
    \u4F59\u5B9A\u7406\u3001\u8FD4\u308A\u5024\u3092 (r, m) \u3068\u3059\u308B\u3068\
    \u89E3\u306F x \u2261 r (mod. m)\u3001\u89E3\u306A\u3057\u306E\u5834\u5408\u306F\
    \ (0, -1) \u3092\u8FD4\u3057\u307E\u3059\nnamespace CRT{\n    long long extGCD(long\
    \ long a, long long b, long long &x, long long &y){\n        if(b == 0){\n   \
    \         x = 1;\n            y = 0;\n            return a;\n        }\n     \
    \   long long d = extGCD(b, a % b, y, x);\n        y -= a / b * x;\n        return\
    \ d;\n    }\n\n    pair<long long, long long> ChineseRem(const vector<long long>\
    \ &b, const vector<long long> &m) {\n        long long r = 0, M = 1;\n       \
    \ for(int i = 0; i < (int) b.size(); i++){\n            long long p, q;\n    \
    \        long long d = extGCD(M, m[i], p, q);\n            if((b[i] - r) % d !=\
    \ 0) return {0, -1};\n            long long tmp = (b[i] - r) / d * p % (m[i] /\
    \ d);\n            r += M * tmp;\n            M *= m[i] / d;\n        }\n    \
    \    r %= M;\n        if(r < 0) r += M;\n        return {r, M};\n    }\n}\n#line\
    \ 6 \"test/yukicoder/yuki_186.test.cpp\"\n\nint main(){\n    vector<long long>\
    \ b(3), m(3);\n    int cnt = 0;\n    for(int i = 0; i < 3; i++){\n        cin\
    \ >> b[i] >> m[i];\n        if(b[i] == 0) cnt++;\n    }\n    pair<long long, long\
    \ long> p = CRT::ChineseRem(b, m);\n    if(p.second == -1){\n        cout << -1\
    \ << \"\\n\";\n    }else if(cnt == 3){\n        cout << p.second << \"\\n\";\n\
    \    }else{\n        cout << p.first << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/186\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../lib/math/crt.hpp\"\n\nint main(){\n \
    \   vector<long long> b(3), m(3);\n    int cnt = 0;\n    for(int i = 0; i < 3;\
    \ i++){\n        cin >> b[i] >> m[i];\n        if(b[i] == 0) cnt++;\n    }\n \
    \   pair<long long, long long> p = CRT::ChineseRem(b, m);\n    if(p.second ==\
    \ -1){\n        cout << -1 << \"\\n\";\n    }else if(cnt == 3){\n        cout\
    \ << p.second << \"\\n\";\n    }else{\n        cout << p.first << \"\\n\";\n \
    \   }\n}"
  dependsOn:
  - lib/math/crt.hpp
  isVerificationFile: true
  path: test/yukicoder/yuki_186.test.cpp
  requiredBy: []
  timestamp: '2022-11-11 02:31:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/yuki_186.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki_186.test.cpp
- /verify/test/yukicoder/yuki_186.test.cpp.html
title: test/yukicoder/yuki_186.test.cpp
---
