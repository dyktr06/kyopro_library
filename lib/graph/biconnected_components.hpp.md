---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/lowlink.hpp
    title: lib/graph/lowlink.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/biconnected_components.test.cpp
    title: test/library_checker/graph/biconnected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/biconnected_components.hpp\"\n\n#line 2 \"lib/graph/lowlink.hpp\"\
    \n\nstruct LowLink{\n    struct Edge{\n        int from, to, id;\n    };\n   \
    \ vector<vector<Edge>> G;\n    int V = 0, E = 0;\n    vector<bool> used;\n   \
    \ vector<int> ord, low;\n    vector<int> reachable;\n    vector<pair<int, int>>\
    \ bridges; // \u6A4B\n    vector<int> articulations; // \u95A2\u7BC0\u70B9\n \
    \   vector<bool> is_bridge, is_articulation;\n\n    LowLink(const int node_size)\
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
    \            is_articulation[cur] = true;\n        }\n    }\n};\n#line 4 \"lib/graph/biconnected_components.hpp\"\
    \n\nstruct BiconnectedComponents : LowLink{\n    using super = LowLink;\n\n  \
    \  vector<vector<Edge>> edge_result;\n    vector<vector<int>> result;\n\n    BiconnectedComponents(const\
    \ int node_size) : super(node_size){}\n\n    void build(){\n        super::build();\n\
    \        vector<bool> visited(V, false);\n        vector<Edge> edges;\n      \
    \  // \u8FBA\u30D9\u30FC\u30B9\u3067\u5206\u89E3\n        auto dfs = [&](auto\
    \ &self, int cur, int prv) -> void {\n            visited[cur] = true;\n     \
    \       bool is_multiple = false;\n            for(auto &edge : G[cur]){\n   \
    \             if(edge.to == prv && !is_multiple){\n                    is_multiple\
    \ = true;\n                    continue;\n                }\n                if(!visited[edge.to]\
    \ || ord[edge.to] < ord[cur]){\n                    edges.emplace_back(edge);\n\
    \                }\n                if(!visited[edge.to]){\n                 \
    \   self(self, edge.to, cur);\n                    if(ord[cur] <= low[edge.to]){\n\
    \                        edge_result.push_back({});\n                        while(true){\n\
    \                            auto edgeb = edges.back();\n                    \
    \        edge_result.back().push_back(edgeb);\n                            edges.pop_back();\n\
    \                            if(edge.id == edgeb.id) break;\n                \
    \        }\n                    }\n                }\n            }\n        };\n\
    \        for(int i = 0; i < V; i++){\n            if(!visited[i]){\n         \
    \       dfs(dfs, i, -1);\n            }\n        }\n\n        vector<bool> used(V),\
    \ is_exist(V);\n        for(auto &x : edge_result){\n            vector<int> v;\n\
    \            for(auto &y : x){\n                if(!is_exist[y.from]) v.push_back(y.from);\n\
    \                if(!is_exist[y.to]) v.push_back(y.to);\n                is_exist[y.from]\
    \ = true;\n                is_exist[y.to] = true;\n                used[y.from]\
    \ = true;\n                used[y.to] = true;\n            }\n            for(auto\
    \ &y : x){\n                is_exist[y.from] = false;\n                is_exist[y.to]\
    \ = false;\n            }\n            result.push_back(v);\n        }\n     \
    \   for(int i = 0; i < V; i++){\n            if(!used[i]){\n                result.push_back({i});\n\
    \            }\n        }\n    }\n\n    vector<vector<int>> get(){\n        return\
    \ result;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../graph/lowlink.hpp\"\n\nstruct BiconnectedComponents\
    \ : LowLink{\n    using super = LowLink;\n\n    vector<vector<Edge>> edge_result;\n\
    \    vector<vector<int>> result;\n\n    BiconnectedComponents(const int node_size)\
    \ : super(node_size){}\n\n    void build(){\n        super::build();\n       \
    \ vector<bool> visited(V, false);\n        vector<Edge> edges;\n        // \u8FBA\
    \u30D9\u30FC\u30B9\u3067\u5206\u89E3\n        auto dfs = [&](auto &self, int cur,\
    \ int prv) -> void {\n            visited[cur] = true;\n            bool is_multiple\
    \ = false;\n            for(auto &edge : G[cur]){\n                if(edge.to\
    \ == prv && !is_multiple){\n                    is_multiple = true;\n        \
    \            continue;\n                }\n                if(!visited[edge.to]\
    \ || ord[edge.to] < ord[cur]){\n                    edges.emplace_back(edge);\n\
    \                }\n                if(!visited[edge.to]){\n                 \
    \   self(self, edge.to, cur);\n                    if(ord[cur] <= low[edge.to]){\n\
    \                        edge_result.push_back({});\n                        while(true){\n\
    \                            auto edgeb = edges.back();\n                    \
    \        edge_result.back().push_back(edgeb);\n                            edges.pop_back();\n\
    \                            if(edge.id == edgeb.id) break;\n                \
    \        }\n                    }\n                }\n            }\n        };\n\
    \        for(int i = 0; i < V; i++){\n            if(!visited[i]){\n         \
    \       dfs(dfs, i, -1);\n            }\n        }\n\n        vector<bool> used(V),\
    \ is_exist(V);\n        for(auto &x : edge_result){\n            vector<int> v;\n\
    \            for(auto &y : x){\n                if(!is_exist[y.from]) v.push_back(y.from);\n\
    \                if(!is_exist[y.to]) v.push_back(y.to);\n                is_exist[y.from]\
    \ = true;\n                is_exist[y.to] = true;\n                used[y.from]\
    \ = true;\n                used[y.to] = true;\n            }\n            for(auto\
    \ &y : x){\n                is_exist[y.from] = false;\n                is_exist[y.to]\
    \ = false;\n            }\n            result.push_back(v);\n        }\n     \
    \   for(int i = 0; i < V; i++){\n            if(!used[i]){\n                result.push_back({i});\n\
    \            }\n        }\n    }\n\n    vector<vector<int>> get(){\n        return\
    \ result;\n    }\n};\n"
  dependsOn:
  - lib/graph/lowlink.hpp
  isVerificationFile: false
  path: lib/graph/biconnected_components.hpp
  requiredBy: []
  timestamp: '2024-10-19 01:49:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/biconnected_components.test.cpp
documentation_of: lib/graph/biconnected_components.hpp
layout: document
redirect_from:
- /library/lib/graph/biconnected_components.hpp
- /library/lib/graph/biconnected_components.hpp.html
title: lib/graph/biconnected_components.hpp
---