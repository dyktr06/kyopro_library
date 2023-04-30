---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/string/calc-next.md
    document_title: calc-next
    links: []
  bundledCode: "#line 2 \"lib/string/calc-next.hpp\"\n\n/**\n * @brief calc-next\n\
    \ * @docs docs/string/calc-next.md\n */\n\nvector<vector<int>> calc_next(const\
    \ string &s) {\n    int n = (int) s.size();\n\n    vector<vector<int>> res(n +\
    \ 1, vector<int>(26, n));\n\n    for(int i = n - 1; i >= 0; i--){\n        res[i]\
    \ = res[i + 1];\n        res[i][s[i] - 'a'] = i;\n    }\n    return res;\n}\n\n\
    vector<vector<int>> calc_prev(const string &s) {\n    int n = (int) s.size();\n\
    \n    vector<vector<int>> res(n + 1, vector<int>(26, -1));\n\n    for(int i =\
    \ 0; i < n; i++){\n        if(i >= 1) res[i] = res[i - 1];\n        res[i][s[i]\
    \ - 'a'] = i;\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief calc-next\n * @docs docs/string/calc-next.md\n\
    \ */\n\nvector<vector<int>> calc_next(const string &s) {\n    int n = (int) s.size();\n\
    \n    vector<vector<int>> res(n + 1, vector<int>(26, n));\n\n    for(int i = n\
    \ - 1; i >= 0; i--){\n        res[i] = res[i + 1];\n        res[i][s[i] - 'a']\
    \ = i;\n    }\n    return res;\n}\n\nvector<vector<int>> calc_prev(const string\
    \ &s) {\n    int n = (int) s.size();\n\n    vector<vector<int>> res(n + 1, vector<int>(26,\
    \ -1));\n\n    for(int i = 0; i < n; i++){\n        if(i >= 1) res[i] = res[i\
    \ - 1];\n        res[i][s[i] - 'a'] = i;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/calc-next.hpp
  requiredBy: []
  timestamp: '2023-05-01 02:14:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/string/calc-next.hpp
layout: document
redirect_from:
- /library/lib/string/calc-next.hpp
- /library/lib/string/calc-next.hpp.html
title: calc-next
---
## calc-next

#### 概要

文字列 $S$ において、ある地点からある文字が次にどの地点に出てくるかを計算します。

#### 計算量

$\mathrm{O}(\lvert S\lvert)$