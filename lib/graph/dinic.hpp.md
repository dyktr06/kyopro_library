---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/bipartitematching.test.cpp
    title: test/library_checker/graph/bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/dinic.md
    document_title: Dinic's Algorithm
    links: []
  bundledCode: "#line 2 \"lib/graph/dinic.hpp\"\n\n/**\n * @brief Dinic's Algorithm\n\
    \ * @docs docs/graph/dinic.md\n */\n\ntemplate<typename T>\nstruct Dinic{\nprivate:\n\
    \    int V;\n    vector<int> level, iter;\n\n    void bfs(int s, int t){\n   \
    \     fill(level.begin(), level.end(), -1);\n        level[s] = 0;\n        queue<int>\
    \ q;\n        q.push(s);\n        while(!(q.empty())){\n            int f = q.front();\n\
    \            q.pop();\n            for(auto &e : G[f]){\n                if(e.cap\
    \ > 0 && level[e.to] < 0){\n                    level[e.to] = level[f] + 1;\n\
    \                    if(e.to == t) return;\n                    q.push(e.to);\n\
    \                }\n            }\n        }\n    }\n\n    T dfs(int v, int t,\
    \ T f){\n        if(v == t){\n            return f;\n        }\n        for(int\
    \ &i = iter[v]; i < (int) G[v].size(); i++){\n            edge &e = G[v][i];\n\
    \            if(e.cap > 0 && level[v] < level[e.to]){\n                T d = dfs(e.to,\
    \ t, min(f, e.cap));\n                if(d > 0){\n                    e.cap -=\
    \ d;\n                    e.flow += d;\n                    G[e.to][e.rev].cap\
    \ += d;\n                    G[e.to][e.rev].flow -= d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\n\
    public:\n    struct edge{\n        int to, rev;\n        T cap, flow = 0;\n  \
    \  };\n    vector<vector<edge>> G;\n\n    Dinic(const int n) : V(n), level(n),\
    \ iter(n), G(n){}\n\n    void add_edge(int from, int to, T cap){\n        G[from].push_back({to,\
    \ (int) G[to].size(), cap});\n        G[to].push_back({from, (int) G[from].size()\
    \ - 1, (T) 0});\n    }\n\n    T flow(int s, int t){\n        T flow = 0;\n   \
    \     while(true){\n            bfs(s, t);\n            if(level[t] < 0) return\
    \ flow;\n            fill(iter.begin(), iter.end(), 0);\n            T f;\n  \
    \          while((f = dfs(s, t, numeric_limits<T>::max())) > 0){\n           \
    \     flow += f;\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Dinic's Algorithm\n * @docs docs/graph/dinic.md\n\
    \ */\n\ntemplate<typename T>\nstruct Dinic{\nprivate:\n    int V;\n    vector<int>\
    \ level, iter;\n\n    void bfs(int s, int t){\n        fill(level.begin(), level.end(),\
    \ -1);\n        level[s] = 0;\n        queue<int> q;\n        q.push(s);\n   \
    \     while(!(q.empty())){\n            int f = q.front();\n            q.pop();\n\
    \            for(auto &e : G[f]){\n                if(e.cap > 0 && level[e.to]\
    \ < 0){\n                    level[e.to] = level[f] + 1;\n                   \
    \ if(e.to == t) return;\n                    q.push(e.to);\n                }\n\
    \            }\n        }\n    }\n\n    T dfs(int v, int t, T f){\n        if(v\
    \ == t){\n            return f;\n        }\n        for(int &i = iter[v]; i <\
    \ (int) G[v].size(); i++){\n            edge &e = G[v][i];\n            if(e.cap\
    \ > 0 && level[v] < level[e.to]){\n                T d = dfs(e.to, t, min(f, e.cap));\n\
    \                if(d > 0){\n                    e.cap -= d;\n               \
    \     e.flow += d;\n                    G[e.to][e.rev].cap += d;\n           \
    \         G[e.to][e.rev].flow -= d;\n                    return d;\n         \
    \       }\n            }\n        }\n        return 0;\n    }\n\npublic:\n   \
    \ struct edge{\n        int to, rev;\n        T cap, flow = 0;\n    };\n    vector<vector<edge>>\
    \ G;\n\n    Dinic(const int n) : V(n), level(n), iter(n), G(n){}\n\n    void add_edge(int\
    \ from, int to, T cap){\n        G[from].push_back({to, (int) G[to].size(), cap});\n\
    \        G[to].push_back({from, (int) G[from].size() - 1, (T) 0});\n    }\n\n\
    \    T flow(int s, int t){\n        T flow = 0;\n        while(true){\n      \
    \      bfs(s, t);\n            if(level[t] < 0) return flow;\n            fill(iter.begin(),\
    \ iter.end(), 0);\n            T f;\n            while((f = dfs(s, t, numeric_limits<T>::max()))\
    \ > 0){\n                flow += f;\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/dinic.hpp
  requiredBy: []
  timestamp: '2024-11-01 00:31:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/bipartitematching.test.cpp
documentation_of: lib/graph/dinic.hpp
layout: document
redirect_from:
- /library/lib/graph/dinic.hpp
- /library/lib/graph/dinic.hpp.html
title: Dinic's Algorithm
---
## Dinic's Algorithm

#### 概要

グラフについて、最大流を求めます。

#### 使い方

- `Dinic(n)`: コンストラクタ (n は頂点数)
- `add_edge(from, to, cap)`: 頂点 from から 頂点 to に最大容量 cap の有向辺を追加します。
- `flow(s, t)`: 頂点 $s$ から 頂点 $t$ の最大流の流量を求めます。

#### 計算量

- `Dinic(n)`: $\mathrm{O}(n)$
- `add_edge(from, to, cap)`: $\mathrm{O}(1)$

以降は、頂点数を $V$、追加された辺の数を $E$ とします。

- `flow(s, t, f)`: $\mathrm{O}(V^2 E)$
