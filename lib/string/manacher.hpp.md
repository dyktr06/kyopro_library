---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/enumerate_palindromes.test.cpp
    title: test/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/string/manacher.hpp\"\n\n// \u305D\u308C\u305E\u308C\
    \u306E i (1 <= i <= |S|) \u306B\u3064\u3044\u3066\u3001S[i] \u3092\u4E2D\u5FC3\
    \u3068\u3059\u308B\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84\u3092\u6C42\u3081\
    \u307E\u3059\u3002 : O(|S|) \ntemplate <typename T>\nvector<int> manacher(const\
    \ T &s){\n    int n = s.size();\n    vector<int> rad(n);\n    int i = 0, j = 0;\n\
    \    while(i < n){\n        while(i - j >= 0 && i + j < s.size() && s[i - j] ==\
    \ s[i + j]){\n            j++;\n        }\n        rad[i] = j;\n        int k\
    \ = 1;\n        while(i - k >= 0 && i + k < n && k + rad[i - k] < j){\n      \
    \      rad[i + k] = rad[i - k];\n            k++;\n        }\n        i += k;\n\
    \        j -= k;\n    }\n    return rad;\n}\n"
  code: "#pragma once\n\n// \u305D\u308C\u305E\u308C\u306E i (1 <= i <= |S|) \u306B\
    \u3064\u3044\u3066\u3001S[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u56DE\
    \u6587\u306E\u534A\u5F84\u3092\u6C42\u3081\u307E\u3059\u3002 : O(|S|) \ntemplate\
    \ <typename T>\nvector<int> manacher(const T &s){\n    int n = s.size();\n   \
    \ vector<int> rad(n);\n    int i = 0, j = 0;\n    while(i < n){\n        while(i\
    \ - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]){\n            j++;\n \
    \       }\n        rad[i] = j;\n        int k = 1;\n        while(i - k >= 0 &&\
    \ i + k < n && k + rad[i - k] < j){\n            rad[i + k] = rad[i - k];\n  \
    \          k++;\n        }\n        i += k;\n        j -= k;\n    }\n    return\
    \ rad;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/manacher.hpp
  requiredBy: []
  timestamp: '2022-11-10 08:53:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: lib/string/manacher.hpp
layout: document
redirect_from:
- /library/lib/string/manacher.hpp
- /library/lib/string/manacher.hpp.html
title: lib/string/manacher.hpp
---
