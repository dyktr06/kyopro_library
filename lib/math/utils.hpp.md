---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/convolution/bitwise_and_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_and_convolution.test.cpp
  - icon: ':x:'
    path: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/utils.hpp\"\n\n// \u521D\u9805 a, \u516C\u5DEE\
    \ d, \u9805\u6570 n \u306E\u7B49\u5DEE\u6570\u5217\u306E\u548C\u3092\u8A08\u7B97\
    \u3057\u307E\u3059 : O(1)\ntemplate <typename T>\nT arithmeticsum(T a, T d, T\
    \ n){\n    return n * (a * 2 + (n - 1) * d) / 2;\n}\n\n// \u521D\u9805 a, \u516C\
    \u6BD4 r, \u9805\u6570 n \u306E\u7B49\u6BD4\u6570\u5217\u306E\u548C\u3092\u8A08\
    \u7B97\u3057\u307E\u3059 : O(1)\ntemplate <typename T>\nT geometricsum(T a, T\
    \ r, T n){\n    if(r == 1){\n        return a * n;\n    }\n    return a * (intpow(r,\
    \ n) - 1) / (r - 1);\n}\n\n// x \u306E\u90E8\u5206\u96C6\u5408\u3092\u5217\u6319\
    \u3057\u307E\u3059\u3002\ntemplate <typename T>\nvector<T> getSubmask(T x){\n\
    \    vector<T> submask;\n    for(T i = x; ; i = (i - 1) & x){\n        submask.push_back(i);\n\
    \        if(i == 0) break;\n    }\n    sort(submask.begin(), submask.end());\n\
    \    return submask;\n}\n"
  code: "#pragma once\n\n// \u521D\u9805 a, \u516C\u5DEE d, \u9805\u6570 n \u306E\u7B49\
    \u5DEE\u6570\u5217\u306E\u548C\u3092\u8A08\u7B97\u3057\u307E\u3059 : O(1)\ntemplate\
    \ <typename T>\nT arithmeticsum(T a, T d, T n){\n    return n * (a * 2 + (n -\
    \ 1) * d) / 2;\n}\n\n// \u521D\u9805 a, \u516C\u6BD4 r, \u9805\u6570 n \u306E\u7B49\
    \u6BD4\u6570\u5217\u306E\u548C\u3092\u8A08\u7B97\u3057\u307E\u3059 : O(1)\ntemplate\
    \ <typename T>\nT geometricsum(T a, T r, T n){\n    if(r == 1){\n        return\
    \ a * n;\n    }\n    return a * (intpow(r, n) - 1) / (r - 1);\n}\n\n// x \u306E\
    \u90E8\u5206\u96C6\u5408\u3092\u5217\u6319\u3057\u307E\u3059\u3002\ntemplate <typename\
    \ T>\nvector<T> getSubmask(T x){\n    vector<T> submask;\n    for(T i = x; ; i\
    \ = (i - 1) & x){\n        submask.push_back(i);\n        if(i == 0) break;\n\
    \    }\n    sort(submask.begin(), submask.end());\n    return submask;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/utils.hpp
  requiredBy: []
  timestamp: '2024-09-08 16:34:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  - test/library_checker/convolution/bitwise_and_convolution.test.cpp
documentation_of: lib/math/utils.hpp
layout: document
redirect_from:
- /library/lib/math/utils.hpp
- /library/lib/math/utils.hpp.html
title: lib/math/utils.hpp
---
