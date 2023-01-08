---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/z_algorithm.test.cpp
    title: test/library_checker/string/z_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/z_algorithm.md
    document_title: Z Algorithm
    links: []
  bundledCode: "#line 2 \"lib/string/z_algorithm.hpp\"\n\n/**\n * @brief Z Algorithm\n\
    \ * @docs docs/string/z_algorithm.md\n */\n\ntemplate <typename T>\nvector<int>\
    \ z_algorithm(const T &s) {\n    int n = s.size();\n    vector<int> res(n, 0);\n\
    \    for(int i = 1, j = 0; i < n; ++i){\n        if(i + res[i - j] < j + res[j]){\n\
    \            res[i] = res[i - j];\n        }else{\n            res[i] = max(j\
    \ + res[j] - i, 0);\n            while(i + res[i] < n && s[i + res[i]] == s[res[i]])\
    \ ++res[i];\n            j = i;\n        }\n    }\n    res[0] = n;\n    return\
    \ res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Z Algorithm\n * @docs docs/string/z_algorithm.md\n\
    \ */\n\ntemplate <typename T>\nvector<int> z_algorithm(const T &s) {\n    int\
    \ n = s.size();\n    vector<int> res(n, 0);\n    for(int i = 1, j = 0; i < n;\
    \ ++i){\n        if(i + res[i - j] < j + res[j]){\n            res[i] = res[i\
    \ - j];\n        }else{\n            res[i] = max(j + res[j] - i, 0);\n      \
    \      while(i + res[i] < n && s[i + res[i]] == s[res[i]]) ++res[i];\n       \
    \     j = i;\n        }\n    }\n    res[0] = n;\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2023-01-09 04:41:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/z_algorithm.test.cpp
documentation_of: lib/string/z_algorithm.hpp
layout: document
redirect_from:
- /library/lib/string/z_algorithm.hpp
- /library/lib/string/z_algorithm.hpp.html
title: Z Algorithm
---
## Z Algorithm

#### 概要

文字列 $S$ のそれぞれの $i \: (1 \leq i \leq \lvert S\lvert)$ について、$S[1] + S[2] + ...$ と $S[i] + S[i + 1] + ...$ の最長共通接頭辞の長さ を求めます。

#### 計算量

$\mathrm{O}(\lvert S\lvert)$