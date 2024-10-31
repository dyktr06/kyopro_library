---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/lyndon_factorization.test.cpp
    title: test/library_checker/string/lyndon_factorization.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/lyndon_factorization.md
    document_title: Lyndon Factorization
    links:
    - https://qiita.com/nakashi18/items/66882bd6e0127174267a
  bundledCode: "#line 2 \"lib/string/lyndon_factorization.hpp\"\n\n/**\n * @brief\
    \ Lyndon Factorization\n * @docs docs/string/lyndon_factorization.md\n * @see\
    \ https://qiita.com/nakashi18/items/66882bd6e0127174267a\n */\n\ntemplate <typename\
    \ T>\nvector<int> lyndon_factorization(const T &s){\n    int n = s.size();\n \
    \   vector<int> ans = {0};\n    int l = 0;\n    while(l < n){\n        // [l,\
    \ ?) \u306E\u6700\u9577\u306E Lyndon \u6587\u5B57\u5217\u3092\u898B\u3064\u3051\
    \u308B\n        int i = l, j = l + 1;\n        while(s[i] <= s[j] && j < n){\n\
    \            if(s[i] == s[j]) i++;\n            else i = l;\n            j++;\n\
    \        }\n        // (j - i) \u304C\u5468\u671F\u3067\u3001[l, j) \u304C\u305D\
    \u306E\u5468\u671F\u306E\u7E70\u308A\u8FD4\u3057\n        int repet = (j - l)\
    \ / (j - i);\n        for(int d = 0; d < repet; d++){\n            l += j - i;\n\
    \            ans.push_back(l);\n        }\n    }\n    return ans;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Lyndon Factorization\n * @docs docs/string/lyndon_factorization.md\n\
    \ * @see https://qiita.com/nakashi18/items/66882bd6e0127174267a\n */\n\ntemplate\
    \ <typename T>\nvector<int> lyndon_factorization(const T &s){\n    int n = s.size();\n\
    \    vector<int> ans = {0};\n    int l = 0;\n    while(l < n){\n        // [l,\
    \ ?) \u306E\u6700\u9577\u306E Lyndon \u6587\u5B57\u5217\u3092\u898B\u3064\u3051\
    \u308B\n        int i = l, j = l + 1;\n        while(s[i] <= s[j] && j < n){\n\
    \            if(s[i] == s[j]) i++;\n            else i = l;\n            j++;\n\
    \        }\n        // (j - i) \u304C\u5468\u671F\u3067\u3001[l, j) \u304C\u305D\
    \u306E\u5468\u671F\u306E\u7E70\u308A\u8FD4\u3057\n        int repet = (j - l)\
    \ / (j - i);\n        for(int d = 0; d < repet; d++){\n            l += j - i;\n\
    \            ans.push_back(l);\n        }\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/lyndon_factorization.hpp
  requiredBy: []
  timestamp: '2024-10-31 22:40:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/lyndon_factorization.test.cpp
documentation_of: lib/string/lyndon_factorization.hpp
layout: document
redirect_from:
- /library/lib/string/lyndon_factorization.hpp
- /library/lib/string/lyndon_factorization.hpp.html
title: Lyndon Factorization
---
## Lyndon Factorization

#### 概要

文字列 $S$ について、Lyndon 分解を行います。

#### 計算量

$\mathrm{O}(\lvert S\lvert)$
