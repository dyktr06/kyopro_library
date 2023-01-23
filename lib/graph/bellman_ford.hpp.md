---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/grl_1_b.test.cpp
    title: test/aoj/grl/grl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/bellman_ford.md
    document_title: "Bellman-Ford Algorithm (\u30D9\u30EB\u30DE\u30F3-\u30D5\u30A9\
      \u30FC\u30C9\u6CD5)"
    links: []
  bundledCode: "#line 2 \"lib/graph/bellman_ford.hpp\"\n\n/**\n * @brief Bellman-Ford\
    \ Algorithm (\u30D9\u30EB\u30DE\u30F3-\u30D5\u30A9\u30FC\u30C9\u6CD5)\n * @docs\
    \ docs/graph/bellman_ford.md\n */\n\ntemplate <typename T>\nvector<long long>\
    \ bellman_ford(const vector<T> &E, const int &n, const int &x){\n    const long\
    \ long INF = 0x1fffffffffffffff;\n    vector<long long> cost(n, INF);\n    cost[x]\
    \ = 0;\n    for(int i = 0; i < n - 1; i++){\n        for(auto [from, to, t] :\
    \ E){\n            if(cost[from] == INF) continue;\n            cost[to] = min(cost[to],\
    \ cost[from] + t);\n        }\n    }\n    for(auto [from, to, t] : E){\n     \
    \   if(cost[from] == INF) continue;\n        if(cost[from] + t < cost[to]) return\
    \ vector<long long>();\n    }\n    return cost;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Bellman-Ford Algorithm (\u30D9\u30EB\u30DE\
    \u30F3-\u30D5\u30A9\u30FC\u30C9\u6CD5)\n * @docs docs/graph/bellman_ford.md\n\
    \ */\n\ntemplate <typename T>\nvector<long long> bellman_ford(const vector<T>\
    \ &E, const int &n, const int &x){\n    const long long INF = 0x1fffffffffffffff;\n\
    \    vector<long long> cost(n, INF);\n    cost[x] = 0;\n    for(int i = 0; i <\
    \ n - 1; i++){\n        for(auto [from, to, t] : E){\n            if(cost[from]\
    \ == INF) continue;\n            cost[to] = min(cost[to], cost[from] + t);\n \
    \       }\n    }\n    for(auto [from, to, t] : E){\n        if(cost[from] == INF)\
    \ continue;\n        if(cost[from] + t < cost[to]) return vector<long long>();\n\
    \    }\n    return cost;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2023-01-23 11:19:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl/grl_1_b.test.cpp
documentation_of: lib/graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/lib/graph/bellman_ford.hpp
- /library/lib/graph/bellman_ford.hpp.html
title: "Bellman-Ford Algorithm (\u30D9\u30EB\u30DE\u30F3-\u30D5\u30A9\u30FC\u30C9\u6CD5\
  )"
---
## Bellman-Ford Algorithm (ベルマン-フォード法)

#### 概要

単一始点最短経路問題を解くことができるアルゴリズムです。

重みが負であった場合でも負の閉路を検出することができます。

#### 使い方

- `bellman_ford(E, n, x)`: 頂点数が $n$ である辺集合 $E$ における $x$ を始点とするそれぞれの頂点への最短距離を求めます。

#### 計算量

頂点数を $V$、辺の数を $E$ とすると、$\mathrm{O}(EV)$