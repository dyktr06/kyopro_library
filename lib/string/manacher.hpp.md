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
    _deprecated_at_docs: docs/string/manacher.md
    document_title: Manacher
    links: []
  bundledCode: "#line 2 \"lib/string/manacher.hpp\"\n\n/**\n * @brief Manacher\n *\
    \ @docs docs/string/manacher.md\n */\n\ntemplate <typename T>\nvector<int> manacher(const\
    \ T &s){\n    int n = s.size();\n    vector<int> rad(n);\n    int i = 0, j = 0;\n\
    \    while(i < n){\n        while(i - j >= 0 && i + j < (int) s.size() && s[i\
    \ - j] == s[i + j]){\n            j++;\n        }\n        rad[i] = j;\n     \
    \   int k = 1;\n        while(i - k >= 0 && i + k < n && k + rad[i - k] < j){\n\
    \            rad[i + k] = rad[i - k];\n            k++;\n        }\n        i\
    \ += k;\n        j -= k;\n    }\n    return rad;\n}\n\nstruct PalindromeCheck{\n\
    \    const string s;\n    string t;\n    int n;\n    vector<int> mana;\n\n   \
    \ PalindromeCheck(const string &str) : s(str){\n        n = s.size();\n      \
    \  t = \"$\";\n        for(int i = 0; i < n; i++){\n            t += s[i];\n \
    \           t += \"$\";\n        }\n        mana = manacher(t);\n    }\n\n   \
    \ // [l, r)\n    bool isPalindrome(int l, int r) const {\n        int mid = l\
    \ + r;\n        return r * 2 - mid - 1 < mana[mid];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Manacher\n * @docs docs/string/manacher.md\n\
    \ */\n\ntemplate <typename T>\nvector<int> manacher(const T &s){\n    int n =\
    \ s.size();\n    vector<int> rad(n);\n    int i = 0, j = 0;\n    while(i < n){\n\
    \        while(i - j >= 0 && i + j < (int) s.size() && s[i - j] == s[i + j]){\n\
    \            j++;\n        }\n        rad[i] = j;\n        int k = 1;\n      \
    \  while(i - k >= 0 && i + k < n && k + rad[i - k] < j){\n            rad[i +\
    \ k] = rad[i - k];\n            k++;\n        }\n        i += k;\n        j -=\
    \ k;\n    }\n    return rad;\n}\n\nstruct PalindromeCheck{\n    const string s;\n\
    \    string t;\n    int n;\n    vector<int> mana;\n\n    PalindromeCheck(const\
    \ string &str) : s(str){\n        n = s.size();\n        t = \"$\";\n        for(int\
    \ i = 0; i < n; i++){\n            t += s[i];\n            t += \"$\";\n     \
    \   }\n        mana = manacher(t);\n    }\n\n    // [l, r)\n    bool isPalindrome(int\
    \ l, int r) const {\n        int mid = l + r;\n        return r * 2 - mid - 1\
    \ < mana[mid];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/manacher.hpp
  requiredBy: []
  timestamp: '2024-04-07 03:10:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: lib/string/manacher.hpp
layout: document
redirect_from:
- /library/lib/string/manacher.hpp
- /library/lib/string/manacher.hpp.html
title: Manacher
---
## Manacher

#### 概要

文字列 $S$ のそれぞれの $i \: (0 \leq i < \lvert S\lvert)$ について、$S[i]$ を中心とする最長回文の半径を求めます。

#### 計算量

$\mathrm{O}(\lvert S\lvert)$