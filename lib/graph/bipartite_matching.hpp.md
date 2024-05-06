---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/grl_7_a.test.cpp
    title: test/aoj/grl/grl_7_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/bipartite_matching.hpp\"\n\ntemplate <typename\
    \ T>\nstruct BipartiteMatching{\n    vector<vector<T>> G;\n    vector<T> alive,\
    \ match, used;\n    int timestamp;\n\n    BipartiteMatching(int n){\n        G.resize(n);\n\
    \        alive.assign(n, 1);\n        match.assign(n, -1);\n        used.assign(n,\
    \ 0);\n        timestamp = 0;\n    }\n\n    void add_edge(int u, int v){\n   \
    \     G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n    bool dfs(int\
    \ v){\n        used[v] = timestamp;\n        for(auto &x : G[v]){\n          \
    \  int y = match[x];\n            if(alive[x] == 0) continue;\n            if(y\
    \ == -1 || (used[y] != timestamp && dfs(y))){\n                match[v] = x;\n\
    \                match[x] = v;\n                return true;\n            }\n\
    \        }\n        return false;\n    }\n\n    int bipartite_matching(){\n  \
    \      int res = 0;\n        for(int i = 0; i < (int) G.size(); i++){\n      \
    \      if(alive[i] == 0) continue;\n            if(match[i] == -1){\n        \
    \        ++timestamp;\n                res += dfs(i);\n            }\n       \
    \ }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct BipartiteMatching{\n    vector<vector<T>>\
    \ G;\n    vector<T> alive, match, used;\n    int timestamp;\n\n    BipartiteMatching(int\
    \ n){\n        G.resize(n);\n        alive.assign(n, 1);\n        match.assign(n,\
    \ -1);\n        used.assign(n, 0);\n        timestamp = 0;\n    }\n\n    void\
    \ add_edge(int u, int v){\n        G[u].push_back(v);\n        G[v].push_back(u);\n\
    \    }\n\n    bool dfs(int v){\n        used[v] = timestamp;\n        for(auto\
    \ &x : G[v]){\n            int y = match[x];\n            if(alive[x] == 0) continue;\n\
    \            if(y == -1 || (used[y] != timestamp && dfs(y))){\n              \
    \  match[v] = x;\n                match[x] = v;\n                return true;\n\
    \            }\n        }\n        return false;\n    }\n\n    int bipartite_matching(){\n\
    \        int res = 0;\n        for(int i = 0; i < (int) G.size(); i++){\n    \
    \        if(alive[i] == 0) continue;\n            if(match[i] == -1){\n      \
    \          ++timestamp;\n                res += dfs(i);\n            }\n     \
    \   }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/bipartite_matching.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/grl/grl_7_a.test.cpp
documentation_of: lib/graph/bipartite_matching.hpp
layout: document
redirect_from:
- /library/lib/graph/bipartite_matching.hpp
- /library/lib/graph/bipartite_matching.hpp.html
title: lib/graph/bipartite_matching.hpp
---
