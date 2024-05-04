---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_and_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/utils.hpp\"\n\n// a\u304B\u3089b\u307E\u3067\u306E\
    \u548C\u3092\u3082\u3068\u3081\u307E\u3059 : O(1)\ntemplate <typename T>\nlong\
    \ long sum(T a, T b){\n    long long res = ((b - a + 1) * (a + b)) / 2;\n    return\
    \ res;\n}\n\n// x^n\u3092\u3082\u3068\u3081\u307E\u3059 : O(logN)\ntemplate <typename\
    \ T>\nT intpow(T x, int n){\n    T ret = 1;\n    while(n > 0) {\n        if(n\
    \ & 1) (ret *= x);\n        (x *= x);\n        n >>= 1;\n    }\n    return ret;\n\
    }\n\n// \u521D\u9805 a, \u516C\u5DEE d, \u9805\u6570 n \u306E\u7B49\u5DEE\u6570\
    \u5217\u306E\u548C\u3092\u8A08\u7B97\u3057\u307E\u3059 : O(1)\ntemplate <typename\
    \ T>\nT arithmeticsum(T a, T d, T n){\n    return n * (a * 2 + (n - 1) * d) /\
    \ 2;\n}\n\n// \u521D\u9805 a, \u516C\u6BD4 r, \u9805\u6570 n \u306E\u7B49\u6BD4\
    \u6570\u5217\u306E\u548C\u3092\u8A08\u7B97\u3057\u307E\u3059 : O(1)\ntemplate\
    \ <typename T>\nT geometricsum(T a, T r, T n){\n    if(r == 1){\n        return\
    \ a * n;\n    }\n    return a * (intpow(r, n) - 1) / (r - 1);\n}\n\n// a \u3092\
    \ b \u3067\u5272\u3063\u305F\u6B63\u306E\u3042\u307E\u308A\u3092\u6C42\u3081\u307E\
    \u3059 : O(1)\ntemplate <typename T>\nT getReminder(T a, T b){\n    if(b == 0)\
    \ return -1;\n    if(a >= 0 && b > 0){\n        return a % b;\n    } else if(a\
    \ < 0 && b > 0){\n        return ((a % b) + b) % b;\n    } else if(a >= 0 && b\
    \ < 0){\n        return a % b;\n    } else{\n        return (abs(b) - abs(a %\
    \ b)) % b;\n    }\n}\n\n// x \u306E\u90E8\u5206\u96C6\u5408\u3092\u5217\u6319\u3057\
    \u307E\u3059\u3002\ntemplate <typename T>\nvector<T> getSubmask(T x){\n    vector<T>\
    \ submask;\n    for(T i = x; ; i = (i - 1) & x){\n        submask.push_back(i);\n\
    \        if(i == 0) break;\n    }\n    sort(submask.begin(), submask.end());\n\
    \    return submask;\n}\n"
  code: "#pragma once\n\n// a\u304B\u3089b\u307E\u3067\u306E\u548C\u3092\u3082\u3068\
    \u3081\u307E\u3059 : O(1)\ntemplate <typename T>\nlong long sum(T a, T b){\n \
    \   long long res = ((b - a + 1) * (a + b)) / 2;\n    return res;\n}\n\n// x^n\u3092\
    \u3082\u3068\u3081\u307E\u3059 : O(logN)\ntemplate <typename T>\nT intpow(T x,\
    \ int n){\n    T ret = 1;\n    while(n > 0) {\n        if(n & 1) (ret *= x);\n\
    \        (x *= x);\n        n >>= 1;\n    }\n    return ret;\n}\n\n// \u521D\u9805\
    \ a, \u516C\u5DEE d, \u9805\u6570 n \u306E\u7B49\u5DEE\u6570\u5217\u306E\u548C\
    \u3092\u8A08\u7B97\u3057\u307E\u3059 : O(1)\ntemplate <typename T>\nT arithmeticsum(T\
    \ a, T d, T n){\n    return n * (a * 2 + (n - 1) * d) / 2;\n}\n\n// \u521D\u9805\
    \ a, \u516C\u6BD4 r, \u9805\u6570 n \u306E\u7B49\u6BD4\u6570\u5217\u306E\u548C\
    \u3092\u8A08\u7B97\u3057\u307E\u3059 : O(1)\ntemplate <typename T>\nT geometricsum(T\
    \ a, T r, T n){\n    if(r == 1){\n        return a * n;\n    }\n    return a *\
    \ (intpow(r, n) - 1) / (r - 1);\n}\n\n// a \u3092 b \u3067\u5272\u3063\u305F\u6B63\
    \u306E\u3042\u307E\u308A\u3092\u6C42\u3081\u307E\u3059 : O(1)\ntemplate <typename\
    \ T>\nT getReminder(T a, T b){\n    if(b == 0) return -1;\n    if(a >= 0 && b\
    \ > 0){\n        return a % b;\n    } else if(a < 0 && b > 0){\n        return\
    \ ((a % b) + b) % b;\n    } else if(a >= 0 && b < 0){\n        return a % b;\n\
    \    } else{\n        return (abs(b) - abs(a % b)) % b;\n    }\n}\n\n// x \u306E\
    \u90E8\u5206\u96C6\u5408\u3092\u5217\u6319\u3057\u307E\u3059\u3002\ntemplate <typename\
    \ T>\nvector<T> getSubmask(T x){\n    vector<T> submask;\n    for(T i = x; ; i\
    \ = (i - 1) & x){\n        submask.push_back(i);\n        if(i == 0) break;\n\
    \    }\n    sort(submask.begin(), submask.end());\n    return submask;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/utils.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/bitwise_and_convolution.test.cpp
  - test/library_checker/convolution/bitwise_xor_convolution.test.cpp
documentation_of: lib/math/utils.hpp
layout: document
redirect_from:
- /library/lib/math/utils.hpp
- /library/lib/math/utils.hpp.html
title: lib/math/utils.hpp
---
