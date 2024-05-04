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
    _deprecated_at_docs: docs/graph/warshall_floyd.md
    document_title: "Floyd-Warshall Algorithm (\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\
      \u30ED\u30A4\u30C9\u6CD5)"
    links: []
  bundledCode: "#line 2 \"lib/graph/warshall_floyd.hpp\"\n\n/**\n * @brief Floyd-Warshall\
    \ Algorithm (\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5)\n *\
    \ @docs docs/graph/warshall_floyd.md\n */\n\ntemplate <typename T>\nvoid warshall_floyd(vector<vector<T>>\
    \ &d, const T &INF) {\n    int n = d.size();\n    for(int i = 0; i < n; i++){\n\
    \        for(int j = 0; j < n; j++){\n            for(int k = 0; k < n; k++){\n\
    \                if(d[j][i] == INF || d[i][k] == INF) continue;\n            \
    \    d[j][k] = min(d[j][k], d[j][i] + d[i][k]);\n            }\n        }\n  \
    \  }\n}\n"
  code: "#pragma once\n\n/**\n * @brief Floyd-Warshall Algorithm (\u30EF\u30FC\u30B7\
    \u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5)\n * @docs docs/graph/warshall_floyd.md\n\
    \ */\n\ntemplate <typename T>\nvoid warshall_floyd(vector<vector<T>> &d, const\
    \ T &INF) {\n    int n = d.size();\n    for(int i = 0; i < n; i++){\n        for(int\
    \ j = 0; j < n; j++){\n            for(int k = 0; k < n; k++){\n             \
    \   if(d[j][i] == INF || d[i][k] == INF) continue;\n                d[j][k] =\
    \ min(d[j][k], d[j][i] + d[i][k]);\n            }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl/grl_1_c.test.cpp
documentation_of: lib/graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/lib/graph/warshall_floyd.hpp
- /library/lib/graph/warshall_floyd.hpp.html
title: "Floyd-Warshall Algorithm (\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\
  \u30C9\u6CD5)"
---
## Floyd-Warshall Algorithm (ワーシャルフロイド法)

#### 概要

全頂点間の最短経路問題を解くことができるアルゴリズムです。

#### 使い方

- `warshall_floyd(d, INF)`: 隣接行列 $d$ における、全頂点間の最短距離を求めます。(INF は到達不可能な距離とする。)

#### 計算量

頂点数を $V$ とすると、$\mathrm{O}(V^3)$