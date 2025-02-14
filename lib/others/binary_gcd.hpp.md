---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binary GCD
    links: []
  bundledCode: "#line 2 \"lib/others/binary_gcd.hpp\"\n\n/**\n * @brief Binary GCD\n\
    \ */\n\ntemplate <typename T>\nT binary_gcd(T a, T b) {\n    unsigned long long\
    \ x = a < 0 ? -a : a, y = b < 0 ? -b : b;\n    if(!x || !y) return x + y;\n  \
    \  int n = __builtin_ctzll(x), m = __builtin_ctzll(y);\n    x >>= n, y >>= m;\n\
    \    while(x != y){\n        if(x > y){\n            x = (x - y) >> __builtin_ctzll(x\
    \ - y);\n        } else{\n            y = (y - x) >> __builtin_ctzll(y - x);\n\
    \        }\n    }\n    return x << (n > m ? m : n);\n}\n"
  code: "#pragma once\n\n/**\n * @brief Binary GCD\n */\n\ntemplate <typename T>\n\
    T binary_gcd(T a, T b) {\n    unsigned long long x = a < 0 ? -a : a, y = b < 0\
    \ ? -b : b;\n    if(!x || !y) return x + y;\n    int n = __builtin_ctzll(x), m\
    \ = __builtin_ctzll(y);\n    x >>= n, y >>= m;\n    while(x != y){\n        if(x\
    \ > y){\n            x = (x - y) >> __builtin_ctzll(x - y);\n        } else{\n\
    \            y = (y - x) >> __builtin_ctzll(y - x);\n        }\n    }\n    return\
    \ x << (n > m ? m : n);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/binary_gcd.hpp
  requiredBy: []
  timestamp: '2025-02-14 23:44:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/binary_gcd.hpp
layout: document
redirect_from:
- /library/lib/others/binary_gcd.hpp
- /library/lib/others/binary_gcd.hpp.html
title: Binary GCD
---
