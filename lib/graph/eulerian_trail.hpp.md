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
    _deprecated_at_docs: docs/graph/eulerian_trail.md
    document_title: "Eulerian Trail (\u30AA\u30A4\u30E9\u30FC\u5C0F\u9053)"
    links:
    - https://kokiymgch.hatenablog.com/entry/2017/12/07/193238
  bundledCode: "#line 2 \"lib/graph/eulerian_trail.hpp\"\n\n/**\n * @brief Eulerian\
    \ Trail (\u30AA\u30A4\u30E9\u30FC\u5C0F\u9053)\n * @docs docs/graph/eulerian_trail.md\n\
    \ * @see https://kokiymgch.hatenablog.com/entry/2017/12/07/193238\n */\n\nstruct\
    \ EulerianTrail{\n    struct Edge{\n        int from, to, id;\n    };\n    int\
    \ V;\n    int E = 0;\n    bool directed;\n    vector<vector<Edge>> G;\n    vector<int>\
    \ deg;\n    EulerianTrail(int n, bool directed = true) : V(n), directed(directed)\
    \ {\n        G.resize(V);\n        deg.resize(V);\n    }\n\n    void add_edge(int\
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
  code: "#pragma once\n\n/**\n * @brief Eulerian Trail (\u30AA\u30A4\u30E9\u30FC\u5C0F\
    \u9053)\n * @docs docs/graph/eulerian_trail.md\n * @see https://kokiymgch.hatenablog.com/entry/2017/12/07/193238\n\
    \ */\n\nstruct EulerianTrail{\n    struct Edge{\n        int from, to, id;\n \
    \   };\n    int V;\n    int E = 0;\n    bool directed;\n    vector<vector<Edge>>\
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
  timestamp: '2024-10-31 23:51:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/eulerian_trail_directed.test.cpp
  - test/library_checker/graph/eulerian_trail_undirected.test.cpp
documentation_of: lib/graph/eulerian_trail.hpp
layout: document
redirect_from:
- /library/lib/graph/eulerian_trail.hpp
- /library/lib/graph/eulerian_trail.hpp.html
title: "Eulerian Trail (\u30AA\u30A4\u30E9\u30FC\u5C0F\u9053)"
---
## Eulerian Trail (オイラー小道)

#### 概要

グラフについて、オイラー小道を求めます。

#### 使い方

- `EulerianTrail(n, directed)`: コンストラクタ (n は頂点数、directed は有向かどうか)
- `add_edge(u, v)`: 頂点 $u$ から 頂点 $v$ に辺を追加します。
- `build()`: オイラー小道の計算を行います。存在しない場合は false が返ってきます。
- `getVertex()`: オイラー小道の頂点列を返します。
- `getEdge()`: オイラー小道の辺の列を返します。

#### 計算量

- `EulerianTrail(n, directed)`: $\mathrm{O}(n)$
- `add_edge(u, v)`: $\mathrm{O}(1)$

以降は、頂点数を $V$、追加された辺の数を $E$ とします。

- `build()`: $\mathrm{O}(E + V)$
- `getVertex()`: $\mathrm{O}(V)$
- `getEdge()`: $\mathrm{O}(E)$
