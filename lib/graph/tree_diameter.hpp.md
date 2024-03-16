---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/tree_diameter.hpp\"\n\n/*  \n    diameter(): \u76F4\
    \u5F84\u306E\u9577\u3055\u3092\u6C42\u3081\u307E\u3059\u3002\n    endpoint():\
    \ \u76F4\u5F84\u306E\u7AEF\u306E\u9802\u70B9\u3092\u6C42\u3081\u307E\u3059\u3002\
    \n*/\n\nstruct TreeDiamiter{\n    using Graph = vector<vector<int>>;\n    Graph\
    \ G;\n    vector<int> dist, dist2;\n    int V, root, diam = -1;\n    pair<int,\
    \ int> ep;\n\n    TreeDiamiter(int n) : V(n){\n        G.resize(n);\n    }\n\n\
    \    void add_edge(int u, int v){\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n\n    void build(int _root = 0){\n        root = _root;\n        dist.assign(V,\
    \ -1); dist2.assign(V, -1);\n        dfs(G, root, -1, 0);\n        int mx = 0;\n\
    \        for(int i = 0; i < V; i++){\n            if(mx < dist[i]){\n        \
    \        mx = dist[i];\n                ep.first = i;\n            }\n       \
    \ }\n\n        dfs2(G, ep.first, -1, 0);\n        for(int i = 0; i < V; i++){\n\
    \            if(diam < dist2[i]){\n                diam = dist2[i];\n        \
    \        ep.second = i;\n            }\n        }\n    }\n\n    void dfs(const\
    \ Graph &G, int v, int p, int d){\n        dist[v] = d;\n        for(auto e :\
    \ G[v]){\n            if(e != p) dfs(G, e, v, d + 1);\n        }\n    }\n\n  \
    \  void dfs2(const Graph &G, int v, int p, int d){\n        dist2[v] = d;\n  \
    \      for(auto e : G[v]){\n            if(e != p) dfs2(G, e, v, d + 1);\n   \
    \     }\n    }\n\n    int diameter(){\n        return diam;\n    }\n\n    pair<int,\
    \ int> endpoint(){\n        return ep;\n    }\n};\n"
  code: "#pragma once\n\n/*  \n    diameter(): \u76F4\u5F84\u306E\u9577\u3055\u3092\
    \u6C42\u3081\u307E\u3059\u3002\n    endpoint(): \u76F4\u5F84\u306E\u7AEF\u306E\
    \u9802\u70B9\u3092\u6C42\u3081\u307E\u3059\u3002\n*/\n\nstruct TreeDiamiter{\n\
    \    using Graph = vector<vector<int>>;\n    Graph G;\n    vector<int> dist, dist2;\n\
    \    int V, root, diam = -1;\n    pair<int, int> ep;\n\n    TreeDiamiter(int n)\
    \ : V(n){\n        G.resize(n);\n    }\n\n    void add_edge(int u, int v){\n \
    \       G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n\n    void\
    \ build(int _root = 0){\n        root = _root;\n        dist.assign(V, -1); dist2.assign(V,\
    \ -1);\n        dfs(G, root, -1, 0);\n        int mx = 0;\n        for(int i =\
    \ 0; i < V; i++){\n            if(mx < dist[i]){\n                mx = dist[i];\n\
    \                ep.first = i;\n            }\n        }\n\n        dfs2(G, ep.first,\
    \ -1, 0);\n        for(int i = 0; i < V; i++){\n            if(diam < dist2[i]){\n\
    \                diam = dist2[i];\n                ep.second = i;\n          \
    \  }\n        }\n    }\n\n    void dfs(const Graph &G, int v, int p, int d){\n\
    \        dist[v] = d;\n        for(auto e : G[v]){\n            if(e != p) dfs(G,\
    \ e, v, d + 1);\n        }\n    }\n\n    void dfs2(const Graph &G, int v, int\
    \ p, int d){\n        dist2[v] = d;\n        for(auto e : G[v]){\n           \
    \ if(e != p) dfs2(G, e, v, d + 1);\n        }\n    }\n\n    int diameter(){\n\
    \        return diam;\n    }\n\n    pair<int, int> endpoint(){\n        return\
    \ ep;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '2024-03-17 05:00:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/tree_diameter.hpp
layout: document
redirect_from:
- /library/lib/graph/tree_diameter.hpp
- /library/lib/graph/tree_diameter.hpp.html
title: lib/graph/tree_diameter.hpp
---
