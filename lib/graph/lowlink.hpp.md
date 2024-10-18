---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/biconnected_components.hpp
    title: lib/graph/biconnected_components.hpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/two_edge_connected_components.hpp
    title: lib/graph/two_edge_connected_components.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/biconnected_components.test.cpp
    title: test/library_checker/graph/biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/two_edge_connected_components.test.cpp
    title: test/library_checker/graph/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/lowlink.hpp\"\n\nstruct LowLink{\n    struct Edge{\n\
    \        int from, to, id;\n    };\n    vector<vector<Edge>> G;\n    int V = 0,\
    \ E = 0;\n    vector<bool> used;\n    vector<int> ord, low;\n    vector<int> reachable;\n\
    \    vector<pair<int, int>> bridges; // \u6A4B\n    vector<int> articulations;\
    \ // \u95A2\u7BC0\u70B9\n    vector<bool> is_bridge, is_articulation;\n\n    LowLink(const\
    \ int node_size) : V(node_size){\n        G.resize(V);\n    }\n\n    void add_edge(int\
    \ from, int to){\n        G[from].push_back({from, to, E});\n        G[to].push_back({to,\
    \ from, E});\n        E++;\n    }\n\n    void build(){\n        used.assign(G.size(),\
    \ 0);\n        ord.assign(G.size(), 0);\n        low.assign(G.size(), 0);\n  \
    \      reachable.assign(G.size(), -1);\n        is_bridge.assign(E, false);\n\
    \        is_articulation.assign(V, false);\n\n        int k = 0;\n        for(int\
    \ i = 0; i < (int) G.size(); i++){\n            if(!used[i]) dfs(i, -1, k);\n\
    \        }\n    }\n\n    void dfs(int cur, int prv, int &k){\n        used[cur]\
    \ = true;\n        ord[cur] = k++;\n        low[cur] = ord[cur];\n        bool\
    \ flag_articulation = false;\n        int child_count = 0; // DFS \u6728\u306E\
    \u5B50\u306E\u6570\n\n        bool is_multiple = false;\n        for(auto &edge\
    \ : G[cur]){\n            if(edge.to == prv && !is_multiple){\n              \
    \  is_multiple = true;\n                continue;\n            }\n           \
    \ if(!used[edge.to]){\n                child_count++;\n                dfs(edge.to,\
    \ cur, k);\n                low[cur] = min(low[cur], low[edge.to]);\n        \
    \        if(prv != -1 && ord[cur] <= low[edge.to]){\n                    flag_articulation\
    \ = true;\n                }\n                if(ord[cur] < low[edge.to]){\n \
    \                   bridges.emplace_back(min(cur, edge.to), max(cur, edge.to));\n\
    \                    is_bridge[edge.id] = true;\n                }\n         \
    \   }else{ // \u5F8C\u9000\u8FBA\n                low[cur] = min(low[cur], ord[edge.to]);\n\
    \            }\n        }\n        if(prv == -1 && child_count >= 2) flag_articulation\
    \ = true;\n        if(flag_articulation){\n            articulations.push_back(cur);\n\
    \            is_articulation[cur] = true;\n        }\n    }\n};\n"
  code: "#pragma once\n\nstruct LowLink{\n    struct Edge{\n        int from, to,\
    \ id;\n    };\n    vector<vector<Edge>> G;\n    int V = 0, E = 0;\n    vector<bool>\
    \ used;\n    vector<int> ord, low;\n    vector<int> reachable;\n    vector<pair<int,\
    \ int>> bridges; // \u6A4B\n    vector<int> articulations; // \u95A2\u7BC0\u70B9\
    \n    vector<bool> is_bridge, is_articulation;\n\n    LowLink(const int node_size)\
    \ : V(node_size){\n        G.resize(V);\n    }\n\n    void add_edge(int from,\
    \ int to){\n        G[from].push_back({from, to, E});\n        G[to].push_back({to,\
    \ from, E});\n        E++;\n    }\n\n    void build(){\n        used.assign(G.size(),\
    \ 0);\n        ord.assign(G.size(), 0);\n        low.assign(G.size(), 0);\n  \
    \      reachable.assign(G.size(), -1);\n        is_bridge.assign(E, false);\n\
    \        is_articulation.assign(V, false);\n\n        int k = 0;\n        for(int\
    \ i = 0; i < (int) G.size(); i++){\n            if(!used[i]) dfs(i, -1, k);\n\
    \        }\n    }\n\n    void dfs(int cur, int prv, int &k){\n        used[cur]\
    \ = true;\n        ord[cur] = k++;\n        low[cur] = ord[cur];\n        bool\
    \ flag_articulation = false;\n        int child_count = 0; // DFS \u6728\u306E\
    \u5B50\u306E\u6570\n\n        bool is_multiple = false;\n        for(auto &edge\
    \ : G[cur]){\n            if(edge.to == prv && !is_multiple){\n              \
    \  is_multiple = true;\n                continue;\n            }\n           \
    \ if(!used[edge.to]){\n                child_count++;\n                dfs(edge.to,\
    \ cur, k);\n                low[cur] = min(low[cur], low[edge.to]);\n        \
    \        if(prv != -1 && ord[cur] <= low[edge.to]){\n                    flag_articulation\
    \ = true;\n                }\n                if(ord[cur] < low[edge.to]){\n \
    \                   bridges.emplace_back(min(cur, edge.to), max(cur, edge.to));\n\
    \                    is_bridge[edge.id] = true;\n                }\n         \
    \   }else{ // \u5F8C\u9000\u8FBA\n                low[cur] = min(low[cur], ord[edge.to]);\n\
    \            }\n        }\n        if(prv == -1 && child_count >= 2) flag_articulation\
    \ = true;\n        if(flag_articulation){\n            articulations.push_back(cur);\n\
    \            is_articulation[cur] = true;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/lowlink.hpp
  requiredBy:
  - lib/graph/biconnected_components.hpp
  - lib/graph/two_edge_connected_components.hpp
  timestamp: '2024-10-19 01:09:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/biconnected_components.test.cpp
  - test/library_checker/graph/two_edge_connected_components.test.cpp
documentation_of: lib/graph/lowlink.hpp
layout: document
redirect_from:
- /library/lib/graph/lowlink.hpp
- /library/lib/graph/lowlink.hpp.html
title: lib/graph/lowlink.hpp
---
