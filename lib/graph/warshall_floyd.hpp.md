---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/grl/grl_1_c.test.cpp
    title: test/aoj/grl/grl_1_c.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/warshall_floyd.hpp\"\n\n// \u30EF\u2015\u30B7\u30E3\
    \u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\u3067\u5168\u9802\u70B9\u9593\u306E\u6700\
    \u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u307E\u3059 : (O(n^3))\ntemplate <typename\
    \ T>\nvoid warshall_floyd(vector<vector<T>> &d, int n) { // n\u306F\u9802\u70B9\
    \u6570\n    for(int i = 0; i < n; i++)          // \u7D4C\u7531\u3059\u308B\u9802\
    \u70B9\n        for(int j = 0; j < n; j++)      // \u958B\u59CB\u9802\u70B9\n\
    \            for(int k = 0; k < n; k++)  // \u7D42\u7AEF\n                d[j][k]\
    \ = min(d[j][k], d[j][i] + d[i][k]);\n}\n"
  code: "#pragma once\n\n// \u30EF\u2015\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\
    \u6CD5\u3067\u5168\u9802\u70B9\u9593\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\
    \u3081\u307E\u3059 : (O(n^3))\ntemplate <typename T>\nvoid warshall_floyd(vector<vector<T>>\
    \ &d, int n) { // n\u306F\u9802\u70B9\u6570\n    for(int i = 0; i < n; i++)  \
    \        // \u7D4C\u7531\u3059\u308B\u9802\u70B9\n        for(int j = 0; j < n;\
    \ j++)      // \u958B\u59CB\u9802\u70B9\n            for(int k = 0; k < n; k++)\
    \  // \u7D42\u7AEF\n                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2022-11-11 03:58:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/grl/grl_1_c.test.cpp
documentation_of: lib/graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/lib/graph/warshall_floyd.hpp
- /library/lib/graph/warshall_floyd.hpp.html
title: lib/graph/warshall_floyd.hpp
---
