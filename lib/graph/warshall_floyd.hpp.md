---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/grl_1_c.test.cpp
    title: test/aoj/grl/grl_1_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/warshall_floyd.hpp\"\n\n/*\n    \u30EF\u2015\u30B7\
    \u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\u3067\u5168\u9802\u70B9\u9593\u306E\
    \u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u307E\u3059 : (O(n^3))\n*/\ntemplate\
    \ <typename T>\nvoid warshall_floyd(vector<vector<T>> &d, T INF) {\n    int n\
    \ = d.size();\n    for(int i = 0; i < n; i++){\n        for(int j = 0; j < n;\
    \ j++){\n            for(int k = 0; k < n; k++){\n                if(d[j][i] ==\
    \ INF || d[i][k] == INF) continue;\n                d[j][k] = min(d[j][k], d[j][i]\
    \ + d[i][k]);\n            }\n        }\n    }\n}\n"
  code: "#pragma once\n\n/*\n    \u30EF\u2015\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\
    \u6CD5\u3067\u5168\u9802\u70B9\u9593\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\
    \u3081\u307E\u3059 : (O(n^3))\n*/\ntemplate <typename T>\nvoid warshall_floyd(vector<vector<T>>\
    \ &d, T INF) {\n    int n = d.size();\n    for(int i = 0; i < n; i++){\n     \
    \   for(int j = 0; j < n; j++){\n            for(int k = 0; k < n; k++){\n   \
    \             if(d[j][i] == INF || d[i][k] == INF) continue;\n               \
    \ d[j][k] = min(d[j][k], d[j][i] + d[i][k]);\n            }\n        }\n    }\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2022-11-11 04:52:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl/grl_1_c.test.cpp
documentation_of: lib/graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/lib/graph/warshall_floyd.hpp
- /library/lib/graph/warshall_floyd.hpp.html
title: lib/graph/warshall_floyd.hpp
---
