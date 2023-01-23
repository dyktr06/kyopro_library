---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1_10_c.test.cpp
    title: test/aoj/alds1/alds1_10_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dp/LCS.md
    document_title: Longest Common Subsequence
    links: []
  bundledCode: "#line 2 \"lib/dp/LCS.hpp\"\n\n/**\n * @brief Longest Common Subsequence\n\
    \ * @docs docs/dp/LCS.md\n */\n\nstring LCS(const string &s, const string &t){\n\
    \    int n = s.size(), m = t.size();\n    vector<vector<int>> memo(n + 1, vector<int>(m\
    \ + 1));\n    for(int i = 0; i < n; i++){\n        for(int j = 0; j < m; j++){\n\
    \            if(s[i] == t[j]){\n                memo[i + 1][j + 1] = memo[i][j]\
    \ + 1;\n            }else{\n                memo[i + 1][j + 1] = max(memo[i][j\
    \ + 1], memo[i + 1][j]);\n            }\n        }\n    }\n\n    // \u5FA9\u5143\
    \n    string res = \"\";\n    int i = n - 1, j = m - 1;\n    while(0 <= i && 0\
    \ <= j){\n        if(s[i] == t[j]){\n            res += s[i];\n            i--;\
    \ j--;\n        }else if(memo[i + 1][j + 1] == memo[i][j + 1]){\n            i--;\n\
    \        }else if(memo[i + 1][j + 1] == memo[i + 1][j]){\n            j--;\n \
    \       }\n    }\n    reverse(res.begin(), res.end());\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Longest Common Subsequence\n * @docs docs/dp/LCS.md\n\
    \ */\n\nstring LCS(const string &s, const string &t){\n    int n = s.size(), m\
    \ = t.size();\n    vector<vector<int>> memo(n + 1, vector<int>(m + 1));\n    for(int\
    \ i = 0; i < n; i++){\n        for(int j = 0; j < m; j++){\n            if(s[i]\
    \ == t[j]){\n                memo[i + 1][j + 1] = memo[i][j] + 1;\n          \
    \  }else{\n                memo[i + 1][j + 1] = max(memo[i][j + 1], memo[i + 1][j]);\n\
    \            }\n        }\n    }\n\n    // \u5FA9\u5143\n    string res = \"\"\
    ;\n    int i = n - 1, j = m - 1;\n    while(0 <= i && 0 <= j){\n        if(s[i]\
    \ == t[j]){\n            res += s[i];\n            i--; j--;\n        }else if(memo[i\
    \ + 1][j + 1] == memo[i][j + 1]){\n            i--;\n        }else if(memo[i +\
    \ 1][j + 1] == memo[i + 1][j]){\n            j--;\n        }\n    }\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/dp/LCS.hpp
  requiredBy: []
  timestamp: '2023-01-23 12:51:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/alds1/alds1_10_c.test.cpp
documentation_of: lib/dp/LCS.hpp
layout: document
redirect_from:
- /library/lib/dp/LCS.hpp
- /library/lib/dp/LCS.hpp.html
title: Longest Common Subsequence
---
## Longest Common Subsequence

#### 概要

文字列 $S$ と文字列 $T$ の最長共通部分列を求めます。

#### 計算量

$\mathrm{O}(\lvert S\lvert \lvert T\lvert)$