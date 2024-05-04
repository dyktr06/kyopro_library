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
    links: []
  bundledCode: "#line 2 \"lib/graph/dinic.hpp\"\n\ntemplate<typename T>\nstruct Dinic{\n\
    private:\n    int V;\n    vector<int> level, iter;\n\n    void bfs(int s, int\
    \ t){\n        fill(level.begin(), level.end(), -1);\n        level[s] = 0;\n\
    \        queue<int> q;\n        q.push(s);\n        while(!(q.empty())){\n   \
    \         int f = q.front();\n            q.pop();\n            for(auto &e :\
    \ G[f]){\n                if(e.cap > 0 && level[e.to] < 0){\n                \
    \    level[e.to] = level[f] + 1;\n                    if(e.to == t) return;\n\
    \                    q.push(e.to);\n                }\n            }\n       \
    \ }\n    }\n\n    T dfs(int v, int t, T f){\n        if(v == t){\n           \
    \ return f;\n        }\n        for(int &i = iter[v]; i < (int) G[v].size(); i++){\n\
    \            edge &e = G[v][i];\n            if(e.cap > 0 && level[v] < level[e.to]){\n\
    \                T d = dfs(e.to, t, min(f, e.cap));\n                if(d > 0){\n\
    \                    e.cap -= d;\n                    e.flow += d;\n         \
    \           G[e.to][e.rev].cap += d;\n                    G[e.to][e.rev].flow\
    \ -= d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n\npublic:\n    struct edge{\n        int to,\
    \ rev;\n        T cap, flow = 0;\n    };\n    vector<vector<edge>> G;\n\n    Dinic(const\
    \ int n) : V(n), level(n), iter(n), G(n){}\n\n    void add_edge(int from, int\
    \ to, T cap){\n        G[from].push_back({to, (int) G[to].size(), cap});\n   \
    \     G[to].push_back({from, (int) G[from].size() - 1, (T) 0});\n    }\n\n   \
    \ T flow(int s, int t){\n        T flow = 0;\n        while(true){\n         \
    \   bfs(s, t);\n            if(level[t] < 0) return flow;\n            fill(iter.begin(),\
    \ iter.end(), 0);\n            T f;\n            while((f = dfs(s, t, numeric_limits<T>::max()))\
    \ > 0){\n                flow += f;\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n\ntemplate<typename T>\nstruct Dinic{\nprivate:\n    int V;\n\
    \    vector<int> level, iter;\n\n    void bfs(int s, int t){\n        fill(level.begin(),\
    \ level.end(), -1);\n        level[s] = 0;\n        queue<int> q;\n        q.push(s);\n\
    \        while(!(q.empty())){\n            int f = q.front();\n            q.pop();\n\
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
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/bipartitematching.test.cpp
documentation_of: lib/graph/dinic.hpp
layout: document
redirect_from:
- /library/lib/graph/dinic.hpp
- /library/lib/graph/dinic.hpp.html
title: lib/graph/dinic.hpp
---