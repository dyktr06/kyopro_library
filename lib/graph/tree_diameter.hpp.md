---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/grl_5_a.test.cpp
    title: test/aoj/grl/grl_5_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/tree_diameter.md
    document_title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
    links: []
  bundledCode: "#line 2 \"lib/graph/tree_diameter.hpp\"\n\n/**\n * @brief Tree Diameter\
    \ (\u6728\u306E\u76F4\u5F84)\n * @docs docs/graph/tree_diameter.md\n */\n\ntemplate\
    \ <typename T>\nstruct TreeDiameter{\n    using Graph = vector<vector<pair<int,\
    \ T>>>;\n    Graph G;\n    vector<T> dist, dist2;\n    int V, root;\n    T diam\
    \ = -1;\n    pair<int, int> ep;\n\n    TreeDiameter(int n) : V(n){\n        G.resize(n);\n\
    \    }\n\n    void add_edge(int u, int v, T w = 1){\n        G[u].emplace_back(v,\
    \ w);\n        G[v].emplace_back(u, w);\n    }\n\n    void build(int _root = 0){\n\
    \        root = _root;\n        dist.assign(V, -1); dist2.assign(V, -1);\n   \
    \     dfs(G, root, -1, 0);\n        T mx = 0;\n        for(int i = 0; i < V; i++){\n\
    \            if(mx < dist[i]){\n                mx = dist[i];\n              \
    \  ep.first = i;\n            }\n        }\n\n        dfs2(G, ep.first, -1, 0);\n\
    \        for(int i = 0; i < V; i++){\n            if(diam < dist2[i]){\n     \
    \           diam = dist2[i];\n                ep.second = i;\n            }\n\
    \        }\n    }\n\n    void dfs(const Graph &G, int v, int p, T d){\n      \
    \  dist[v] = d;\n        for(auto [e, w] : G[v]){\n            if(e != p) dfs(G,\
    \ e, v, d + w);\n        }\n    }\n\n    void dfs2(const Graph &G, int v, int\
    \ p, T d){\n        dist2[v] = d;\n        for(auto [e, w] : G[v]){\n        \
    \    if(e != p) dfs2(G, e, v, d + w);\n        }\n    }\n\n    T diameter(){\n\
    \        return diam;\n    }\n\n    pair<int, int> endpoint(){\n        return\
    \ ep;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Tree Diameter (\u6728\u306E\u76F4\u5F84)\n\
    \ * @docs docs/graph/tree_diameter.md\n */\n\ntemplate <typename T>\nstruct TreeDiameter{\n\
    \    using Graph = vector<vector<pair<int, T>>>;\n    Graph G;\n    vector<T>\
    \ dist, dist2;\n    int V, root;\n    T diam = -1;\n    pair<int, int> ep;\n\n\
    \    TreeDiameter(int n) : V(n){\n        G.resize(n);\n    }\n\n    void add_edge(int\
    \ u, int v, T w = 1){\n        G[u].emplace_back(v, w);\n        G[v].emplace_back(u,\
    \ w);\n    }\n\n    void build(int _root = 0){\n        root = _root;\n      \
    \  dist.assign(V, -1); dist2.assign(V, -1);\n        dfs(G, root, -1, 0);\n  \
    \      T mx = 0;\n        for(int i = 0; i < V; i++){\n            if(mx < dist[i]){\n\
    \                mx = dist[i];\n                ep.first = i;\n            }\n\
    \        }\n\n        dfs2(G, ep.first, -1, 0);\n        for(int i = 0; i < V;\
    \ i++){\n            if(diam < dist2[i]){\n                diam = dist2[i];\n\
    \                ep.second = i;\n            }\n        }\n    }\n\n    void dfs(const\
    \ Graph &G, int v, int p, T d){\n        dist[v] = d;\n        for(auto [e, w]\
    \ : G[v]){\n            if(e != p) dfs(G, e, v, d + w);\n        }\n    }\n\n\
    \    void dfs2(const Graph &G, int v, int p, T d){\n        dist2[v] = d;\n  \
    \      for(auto [e, w] : G[v]){\n            if(e != p) dfs2(G, e, v, d + w);\n\
    \        }\n    }\n\n    T diameter(){\n        return diam;\n    }\n\n    pair<int,\
    \ int> endpoint(){\n        return ep;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2024-07-07 17:27:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl/grl_5_a.test.cpp
documentation_of: lib/graph/tree_diameter.hpp
layout: document
redirect_from:
- /library/lib/graph/tree_diameter.hpp
- /library/lib/graph/tree_diameter.hpp.html
title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
---
## Tree Diameter (木の直径)

#### 概要

木の直径を求めます。

最初は直径のパスを全て求める設計にしようと思いましたが、端点のみで妥協しています。

#### 使い方

- `TreeDiamiter(n)`: コンストラクタ (n は頂点数)
- `add_edge(u, v)`: 頂点 $u$ から 頂点 $v$ に無向辺を追加します。
- `build()`: 重軽分解を行います。
- `diameter()`: 木の直径の長さを求めます（辺の本数）
- `endpoint()`: 木の直径の端の頂点を求めます。

#### 計算量

頂点数を $V$ とします。
- `TreeDiamiter(n)`: $\mathrm{O}(V)$
- `add_edge(u, v)`: $\mathrm{O}(1)$
- `build()`: $\mathrm{O}(V)$
- `diameter()`: $\mathrm{O}(1)$
- `endpoint()`: $\mathrm{O}(1)$
