---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/T_join.hpp\"\n\n#line 2 \"lib/data_structure/union_find.hpp\"\
    \n\n/**\n * @brief Union Find\n * @docs docs/data_structure/union_find.md\n */\n\
    \nstruct UnionFind{\n    vector<int> par;\n    vector<int> edg;\n\n    UnionFind(int\
    \ N) : par(N), edg(N){\n        for(int i = 0; i < N; ++i){\n            par[i]\
    \ = -1;\n            edg[i] = 0;\n        }\n    }\n\n    int root(int x){\n \
    \       if(par[x] < 0) return x;\n        return par[x] = root(par[x]);\n    }\n\
    \n    int unite(int x, int y){\n        int rx = root(x);\n        int ry = root(y);\n\
    \        if(rx == ry){\n            edg[rx]++;\n            return rx;\n     \
    \   }\n        if(-par[rx] < -par[ry]) swap(rx, ry);\n        par[rx] = par[rx]\
    \ + par[ry];\n        par[ry] = rx;\n        edg[rx] += edg[ry] + 1;\n       \
    \ return rx;\n    }\n\n    bool same(int x, int y){\n        int rx = root(x);\n\
    \        int ry = root(y);\n        return rx == ry;\n    }\n\n    long long size(int\
    \ x){\n        return -par[root(x)];\n    }\n\n    long long edge(int x){\n  \
    \      return edg[root(x)];\n    }\n};\n#line 4 \"lib/graph/T_join.hpp\"\n\nvector<pair<int,\
    \ int>> T_join(vector<pair<int, int>> &edges, vector<bool> &b){\n    const int\
    \ n = b.size();\n    UnionFind uf(n);\n    vector<vector<int>> G(n);\n    for(auto\
    \ [x, y] : edges){\n        if(!uf.same(x, y)){\n            uf.unite(x, y);\n\
    \            G[x].emplace_back(y);\n            G[y].emplace_back(x);\n      \
    \  }\n    }\n\n    vector<bool> d = b;\n    vector<pair<int, int>> ans;\n    auto\
    \ dfs = [&](auto &self, int curr, int prv) -> int {\n        int cd = d[curr];\n\
    \        for(auto nxt : G[curr]){\n            if(nxt == prv) continue;\n    \
    \        int nd = self(self, nxt, curr);\n            if(nd){\n              \
    \  cd ^= 1;\n                ans.emplace_back(curr, nxt);\n            }\n   \
    \     }\n        return d[curr] = cd;\n    };\n    for(int i = 0; i < n; i++){\n\
    \        if(uf.root(i) == i){\n            dfs(dfs, i, -1);\n        }\n    }\n\
    \    int sum = 0;\n    for(auto x : d) sum += x;\n    return (sum == 0 ? ans :\
    \ vector<pair<int, int>>());\n}\n"
  code: "#pragma once\n\n#include \"../data_structure/union_find.hpp\"\n\nvector<pair<int,\
    \ int>> T_join(vector<pair<int, int>> &edges, vector<bool> &b){\n    const int\
    \ n = b.size();\n    UnionFind uf(n);\n    vector<vector<int>> G(n);\n    for(auto\
    \ [x, y] : edges){\n        if(!uf.same(x, y)){\n            uf.unite(x, y);\n\
    \            G[x].emplace_back(y);\n            G[y].emplace_back(x);\n      \
    \  }\n    }\n\n    vector<bool> d = b;\n    vector<pair<int, int>> ans;\n    auto\
    \ dfs = [&](auto &self, int curr, int prv) -> int {\n        int cd = d[curr];\n\
    \        for(auto nxt : G[curr]){\n            if(nxt == prv) continue;\n    \
    \        int nd = self(self, nxt, curr);\n            if(nd){\n              \
    \  cd ^= 1;\n                ans.emplace_back(curr, nxt);\n            }\n   \
    \     }\n        return d[curr] = cd;\n    };\n    for(int i = 0; i < n; i++){\n\
    \        if(uf.root(i) == i){\n            dfs(dfs, i, -1);\n        }\n    }\n\
    \    int sum = 0;\n    for(auto x : d) sum += x;\n    return (sum == 0 ? ans :\
    \ vector<pair<int, int>>());\n}\n"
  dependsOn:
  - lib/data_structure/union_find.hpp
  isVerificationFile: false
  path: lib/graph/T_join.hpp
  requiredBy: []
  timestamp: '2024-08-11 14:50:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/T_join.hpp
layout: document
redirect_from:
- /library/lib/graph/T_join.hpp
- /library/lib/graph/T_join.hpp.html
title: lib/graph/T_join.hpp
---
