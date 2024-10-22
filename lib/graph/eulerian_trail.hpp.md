---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/eulerian_trail_directed.test.cpp
    title: test/library_checker/graph/eulerian_trail_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/eulerian_trail_undirected.test.cpp
    title: test/library_checker/graph/eulerian_trail_undirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/eulerian_trail.hpp\"\n\nstruct EulerianTrail{\n\
    \    struct Edge{\n        int from, to, id;\n    };\n    int V;\n    int E =\
    \ 0;\n    bool directed;\n    vector<vector<Edge>> G;\n    vector<int> deg;\n\
    \    EulerianTrail(int n, bool directed = true) : V(n), directed(directed) {\n\
    \        G.resize(V);\n        deg.resize(V);\n    }\n\n    void add_edge(int\
    \ u, int v){\n        if(directed){\n            G[u].push_back({u, v, E});\n\
    \            deg[u]++;\n            deg[v]--;\n        }else{\n            G[u].push_back({u,\
    \ v, E});\n            G[v].push_back({v, u, E});\n            deg[u]++;\n   \
    \         deg[v]++;\n        }\n        E++;\n    }\n\n    vector<int> trail_v,\
    \ trail_e;\n\n    bool build(){\n        int s = -1, t = -1;\n        if(directed){\n\
    \            for(int i = 0; i < V; i++){\n                if(abs(deg[i]) > 1){\n\
    \                    return false;\n                }else if(deg[i] == 1){\n \
    \                   if(s != -1) return false;\n                    s = i;\n  \
    \              }else if(deg[i] == -1){\n                    t = i;\n         \
    \       }\n            }\n        }else{\n            for(int i = 0; i < V; i++){\n\
    \                if(deg[i] % 2){\n                    if(s == -1){\n         \
    \               s = i;\n                    }else if(t == -1){\n             \
    \           t = i;\n                    }else{\n                        return\
    \ false;\n                    }\n                }\n            }\n        }\n\
    \        if(s == -1){\n            s = 0;\n            for(int i = 0; i < V; i++){\n\
    \                if(!G[i].empty()){\n                    s = i;\n            \
    \        break;\n                }\n            }\n        }\n        if(t ==\
    \ -1) t = s;\n\n        trail_e.clear();\n        trail_v.clear();\n\n       \
    \ vector<bool> used(E);\n        auto dfs = [&](auto &self, int cur) -> void {\n\
    \            while(G[cur].size()){\n                auto e = G[cur].back();\n\
    \                 G[cur].pop_back();\n                if(used[e.id]){\n      \
    \              continue;\n                }\n                used[e.id] = true;\n\
    \                self(self, e.to);\n                trail_e.push_back(e.id);\n\
    \            }\n            trail_v.push_back(cur);\n        };\n        dfs(dfs,\
    \ s);\n        reverse(trail_v.begin(), trail_v.end());\n        reverse(trail_e.begin(),\
    \ trail_e.end());\n        if((int) trail_e.size() != E){\n            trail_v.clear();\n\
    \            trail_e.clear();\n            return false;\n        }\n        return\
    \ true;\n    }\n\n    vector<int> getVertex(){\n        return trail_v;\n    }\n\
    \n    vector<int> getEdge(){\n        return trail_e;\n    }\n};\n"
  code: "#pragma once\n\nstruct EulerianTrail{\n    struct Edge{\n        int from,\
    \ to, id;\n    };\n    int V;\n    int E = 0;\n    bool directed;\n    vector<vector<Edge>>\
    \ G;\n    vector<int> deg;\n    EulerianTrail(int n, bool directed = true) : V(n),\
    \ directed(directed) {\n        G.resize(V);\n        deg.resize(V);\n    }\n\n\
    \    void add_edge(int u, int v){\n        if(directed){\n            G[u].push_back({u,\
    \ v, E});\n            deg[u]++;\n            deg[v]--;\n        }else{\n    \
    \        G[u].push_back({u, v, E});\n            G[v].push_back({v, u, E});\n\
    \            deg[u]++;\n            deg[v]++;\n        }\n        E++;\n    }\n\
    \n    vector<int> trail_v, trail_e;\n\n    bool build(){\n        int s = -1,\
    \ t = -1;\n        if(directed){\n            for(int i = 0; i < V; i++){\n  \
    \              if(abs(deg[i]) > 1){\n                    return false;\n     \
    \           }else if(deg[i] == 1){\n                    if(s != -1) return false;\n\
    \                    s = i;\n                }else if(deg[i] == -1){\n       \
    \             t = i;\n                }\n            }\n        }else{\n     \
    \       for(int i = 0; i < V; i++){\n                if(deg[i] % 2){\n       \
    \             if(s == -1){\n                        s = i;\n                 \
    \   }else if(t == -1){\n                        t = i;\n                    }else{\n\
    \                        return false;\n                    }\n              \
    \  }\n            }\n        }\n        if(s == -1){\n            s = 0;\n   \
    \         for(int i = 0; i < V; i++){\n                if(!G[i].empty()){\n  \
    \                  s = i;\n                    break;\n                }\n   \
    \         }\n        }\n        if(t == -1) t = s;\n\n        trail_e.clear();\n\
    \        trail_v.clear();\n\n        vector<bool> used(E);\n        auto dfs =\
    \ [&](auto &self, int cur) -> void {\n            while(G[cur].size()){\n    \
    \            auto e = G[cur].back();\n                 G[cur].pop_back();\n  \
    \              if(used[e.id]){\n                    continue;\n              \
    \  }\n                used[e.id] = true;\n                self(self, e.to);\n\
    \                trail_e.push_back(e.id);\n            }\n            trail_v.push_back(cur);\n\
    \        };\n        dfs(dfs, s);\n        reverse(trail_v.begin(), trail_v.end());\n\
    \        reverse(trail_e.begin(), trail_e.end());\n        if((int) trail_e.size()\
    \ != E){\n            trail_v.clear();\n            trail_e.clear();\n       \
    \     return false;\n        }\n        return true;\n    }\n\n    vector<int>\
    \ getVertex(){\n        return trail_v;\n    }\n\n    vector<int> getEdge(){\n\
    \        return trail_e;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/eulerian_trail.hpp
  requiredBy: []
  timestamp: '2024-10-22 15:19:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/eulerian_trail_directed.test.cpp
  - test/library_checker/graph/eulerian_trail_undirected.test.cpp
documentation_of: lib/graph/eulerian_trail.hpp
layout: document
redirect_from:
- /library/lib/graph/eulerian_trail.hpp
- /library/lib/graph/eulerian_trail.hpp.html
title: lib/graph/eulerian_trail.hpp
---
