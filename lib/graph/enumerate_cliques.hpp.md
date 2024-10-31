---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/enumerate_cliques.test.cpp
    title: test/library_checker/graph/enumerate_cliques.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/minimum_diameter_spanning_tree.md
    document_title: "Enumerate Cliques (\u30AF\u30EA\u30FC\u30AF\u306E\u5217\u6319\
      )"
    links:
    - https://www.slideshare.net/wata_orz/ss-12131479
  bundledCode: "#line 2 \"lib/graph/enumerate_cliques.hpp\"\n\n/**\n * @brief Enumerate\
    \ Cliques (\u30AF\u30EA\u30FC\u30AF\u306E\u5217\u6319)\n * @docs docs/graph/minimum_diameter_spanning_tree.md\n\
    \ * @see https://www.slideshare.net/wata_orz/ss-12131479\n */\n\nvector<vector<int>>\
    \ enumerateCliques(vector<vector<int>> &G){\n    int n = G.size();\n    vector<pair<int,\
    \ int>> deg(n);\n    for(int i = 0; i < n; i++){\n        deg[i] = {(int) G[i].size(),\
    \ i};\n    }\n\n    vector<vector<bool>> adj(n, vector<bool>(n));\n    for(int\
    \ i = 0; i < n; i++){\n        for(auto &j : G[i]){\n            adj[i][j] = adj[j][i]\
    \ = true;\n        }\n    }\n\n    // \u6B21\u6570\u304C \u221A2m \u672A\u6E80\
    \u304B\u3069\u3046\u304B\u3067\u5834\u5408\u5206\u3051 -> \u6B21\u6570\u304C\u4F4E\
    \u3044\u9802\u70B9\u304B\u3089\u51E6\u7406\u3092\u3057\u3066\u3082\u5341\u5206\
    \u9AD8\u901F (O(2^(\u221A2m) * n^2))\n    sort(deg.begin(), deg.end());\n    vector<vector<int>>\
    \ res;\n    for(int i = 0; i < n; i++){\n        int cur = deg[i].second;\n  \
    \      vector<int> nxt;\n        for(int j = 0; j < n; j++){\n            if(adj[cur][j]){\n\
    \                nxt.push_back(j);\n            }\n        }\n        int d =\
    \ nxt.size();\n        for(int bit = 0; bit < (1 << d); bit++){\n            vector<int>\
    \ s = {cur};\n            for(int j = 0; j < d; j++){\n                if(bit\
    \ & (1 << j)){\n                    s.push_back(nxt[j]);\n                }\n\
    \            }\n            bool is_ok = true;\n            for(auto x : s){\n\
    \                for(auto y : s){\n                    if(x == y) continue;\n\
    \                    if(adj[x][y] == 0){\n                        is_ok = false;\n\
    \                    }\n                }\n            }\n            if(is_ok){\n\
    \                res.push_back(s);\n            }\n        }\n        for(int\
    \ j = 0; j < d; j++){\n            adj[cur][nxt[j]] = adj[nxt[j]][cur] = false;\n\
    \        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Enumerate Cliques (\u30AF\u30EA\u30FC\u30AF\
    \u306E\u5217\u6319)\n * @docs docs/graph/minimum_diameter_spanning_tree.md\n *\
    \ @see https://www.slideshare.net/wata_orz/ss-12131479\n */\n\nvector<vector<int>>\
    \ enumerateCliques(vector<vector<int>> &G){\n    int n = G.size();\n    vector<pair<int,\
    \ int>> deg(n);\n    for(int i = 0; i < n; i++){\n        deg[i] = {(int) G[i].size(),\
    \ i};\n    }\n\n    vector<vector<bool>> adj(n, vector<bool>(n));\n    for(int\
    \ i = 0; i < n; i++){\n        for(auto &j : G[i]){\n            adj[i][j] = adj[j][i]\
    \ = true;\n        }\n    }\n\n    // \u6B21\u6570\u304C \u221A2m \u672A\u6E80\
    \u304B\u3069\u3046\u304B\u3067\u5834\u5408\u5206\u3051 -> \u6B21\u6570\u304C\u4F4E\
    \u3044\u9802\u70B9\u304B\u3089\u51E6\u7406\u3092\u3057\u3066\u3082\u5341\u5206\
    \u9AD8\u901F (O(2^(\u221A2m) * n^2))\n    sort(deg.begin(), deg.end());\n    vector<vector<int>>\
    \ res;\n    for(int i = 0; i < n; i++){\n        int cur = deg[i].second;\n  \
    \      vector<int> nxt;\n        for(int j = 0; j < n; j++){\n            if(adj[cur][j]){\n\
    \                nxt.push_back(j);\n            }\n        }\n        int d =\
    \ nxt.size();\n        for(int bit = 0; bit < (1 << d); bit++){\n            vector<int>\
    \ s = {cur};\n            for(int j = 0; j < d; j++){\n                if(bit\
    \ & (1 << j)){\n                    s.push_back(nxt[j]);\n                }\n\
    \            }\n            bool is_ok = true;\n            for(auto x : s){\n\
    \                for(auto y : s){\n                    if(x == y) continue;\n\
    \                    if(adj[x][y] == 0){\n                        is_ok = false;\n\
    \                    }\n                }\n            }\n            if(is_ok){\n\
    \                res.push_back(s);\n            }\n        }\n        for(int\
    \ j = 0; j < d; j++){\n            adj[cur][nxt[j]] = adj[nxt[j]][cur] = false;\n\
    \        }\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/enumerate_cliques.hpp
  requiredBy: []
  timestamp: '2024-10-31 23:51:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/enumerate_cliques.test.cpp
documentation_of: lib/graph/enumerate_cliques.hpp
layout: document
redirect_from:
- /library/lib/graph/enumerate_cliques.hpp
- /library/lib/graph/enumerate_cliques.hpp.html
title: "Enumerate Cliques (\u30AF\u30EA\u30FC\u30AF\u306E\u5217\u6319)"
---
## Minimum Diameter Spanning Tree (最小直径全域木)

#### 概要

グラフについて、最小直径全域木を求めます。

#### 使い方

- `MinimumDiameterSpanningTree(n)`: コンストラクタ (n は頂点数)
- `add_edge(u, v, cost)`: 頂点 $u$ から 頂点 $v$ にコスト cost の無向辺を追加します。
- `build()`: 最小直径全域木の計算を行います。
- `get()`: 最小直径全域木の辺を返します。（辺を追加した順番で番号が振られたものが返ってきます）
- `getTreeDiamater()`: 最小直径全域木の直径を返します。

#### 計算量

- `MinimumDiameterSpanningTree(n)`: $\mathrm{O}(n)$
- `add_edge(u, v, cost)`: $\mathrm{O}(1)$

以降は、頂点数を $V$、追加された辺の数を $E$ とします。

- `build()`: $\mathrm{O}(EV \log V)$
- `get()`: $\mathrm{O}(V)$
- `getTreeDiamater()`: $\mathrm{O}(1)$
