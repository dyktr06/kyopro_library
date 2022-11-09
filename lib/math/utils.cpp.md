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
  bundledCode: "#line 1 \"lib/math/utils.cpp\"\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\n// a\u304B\u3089b\u307E\u3067\u306E\u548C\u3092\u3082\u3068\
    \u3081\u307E\u3059 : O(1)\ntemplate <typename T>\nlong long sum(T a, T b){\n \
    \   long long res = ((b - a + 1) * (a + b)) / 2;\n    return res;\n}\n\n// x^n\u3092\
    \u3082\u3068\u3081\u307E\u3059 : O(logN)\ntemplate <typename T>\nT intpow(T x,\
    \ T n){\n    T ret = 1;\n    while(n > 0) {\n        if(n & 1) (ret *= x);\n \
    \       (x *= x);\n        n >>= 1;\n    }\n    return ret;\n}\n\n// \u521D\u9805\
    \ a, \u516C\u5DEE d, \u9805\u6570 n \u306E\u7B49\u5DEE\u6570\u5217\u306E\u548C\
    \u3092\u8A08\u7B97\u3057\u307E\u3059 : O(1)\ntemplate <typename T>\nT arithmeticsum(T\
    \ a, T d, T n){\n    return n * (a * 2 + (n - 1) * d) / 2;\n}\n\n// \u521D\u9805\
    \ a, \u516C\u6BD4 r, \u9805\u6570 n \u306E\u7B49\u6BD4\u6570\u5217\u306E\u548C\
    \u3092\u8A08\u7B97\u3057\u307E\u3059 : O(1)\ntemplate <typename T>\nT geometricsum(T\
    \ a, T r, T n){\n    if(r == 1){\n        return a * n;\n    }\n    return a *\
    \ (intpow(r, n) - 1) / (r - 1);\n}\n\n// a \u3092 b \u3067\u5272\u3063\u305F\u6B63\
    \u306E\u3042\u307E\u308A\u3092\u6C42\u3081\u307E\u3059 : O(1)\ntemplate <typename\
    \ T>\nT getReminder(T a, T b){\n    if(b == 0) return -1;\n    if(a >= 0 && b\
    \ > 0){\n        return a % b;\n    }else if(a < 0 && b > 0){\n        return\
    \ ((a % b) + b) % b;\n    }else if(a >= 0 && b < 0){\n        return a % b;\n\
    \    }else{\n        return (abs(b) - abs(a % b)) % b;\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// a\u304B\u3089b\u307E\
    \u3067\u306E\u548C\u3092\u3082\u3068\u3081\u307E\u3059 : O(1)\ntemplate <typename\
    \ T>\nlong long sum(T a, T b){\n    long long res = ((b - a + 1) * (a + b)) /\
    \ 2;\n    return res;\n}\n\n// x^n\u3092\u3082\u3068\u3081\u307E\u3059 : O(logN)\n\
    template <typename T>\nT intpow(T x, T n){\n    T ret = 1;\n    while(n > 0) {\n\
    \        if(n & 1) (ret *= x);\n        (x *= x);\n        n >>= 1;\n    }\n \
    \   return ret;\n}\n\n// \u521D\u9805 a, \u516C\u5DEE d, \u9805\u6570 n \u306E\
    \u7B49\u5DEE\u6570\u5217\u306E\u548C\u3092\u8A08\u7B97\u3057\u307E\u3059 : O(1)\n\
    template <typename T>\nT arithmeticsum(T a, T d, T n){\n    return n * (a * 2\
    \ + (n - 1) * d) / 2;\n}\n\n// \u521D\u9805 a, \u516C\u6BD4 r, \u9805\u6570 n\
    \ \u306E\u7B49\u6BD4\u6570\u5217\u306E\u548C\u3092\u8A08\u7B97\u3057\u307E\u3059\
    \ : O(1)\ntemplate <typename T>\nT geometricsum(T a, T r, T n){\n    if(r == 1){\n\
    \        return a * n;\n    }\n    return a * (intpow(r, n) - 1) / (r - 1);\n\
    }\n\n// a \u3092 b \u3067\u5272\u3063\u305F\u6B63\u306E\u3042\u307E\u308A\u3092\
    \u6C42\u3081\u307E\u3059 : O(1)\ntemplate <typename T>\nT getReminder(T a, T b){\n\
    \    if(b == 0) return -1;\n    if(a >= 0 && b > 0){\n        return a % b;\n\
    \    }else if(a < 0 && b > 0){\n        return ((a % b) + b) % b;\n    }else if(a\
    \ >= 0 && b < 0){\n        return a % b;\n    }else{\n        return (abs(b) -\
    \ abs(a % b)) % b;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/utils.cpp
  requiredBy: []
  timestamp: '2022-09-19 02:02:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/utils.cpp
layout: document
redirect_from:
- /library/lib/math/utils.cpp
- /library/lib/math/utils.cpp.html
title: lib/math/utils.cpp
---
