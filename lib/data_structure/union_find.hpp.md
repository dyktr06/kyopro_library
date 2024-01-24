---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/manhattanMST.hpp
    title: Manhattan MST
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/unionfind.test.cpp
    title: test/library_checker/data_structure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/cycle_detection_undirected.test.cpp
    title: test/library_checker/graph/cycle_detection_undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/manhattanmst.test.cpp
    title: test/library_checker/graph/manhattanmst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/minimum_spanning_tree.test.cpp
    title: test/library_checker/graph/minimum_spanning_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/union_find.md
    document_title: Union Find
    links: []
  bundledCode: "#line 2 \"lib/data_structure/union_find.hpp\"\n\n/**\n * @brief Union\
    \ Find\n * @docs docs/data_structure/union_find.md\n */\n\nstruct UnionFind{\n\
    \    vector<int> par;\n    vector<int> edg;\n\n    UnionFind(int N) : par(N),\
    \ edg(N){\n        for(int i = 0; i < N; ++i){\n            par[i] = -1;\n   \
    \         edg[i] = 0;\n        }\n    }\n\n    int root(int x){\n        if(par[x]\
    \ < 0) return x;\n        return par[x] = root(par[x]);\n    }\n\n    void unite(int\
    \ x, int y){\n        int rx = root(x);\n        int ry = root(y);\n        if(rx\
    \ == ry){\n            edg[rx]++;\n            return;\n        }\n        par[ry]\
    \ = par[rx] + par[ry];\n        par[rx] = ry;\n        edg[ry] += edg[rx] + 1;\n\
    \    }\n\n    bool same(int x, int y){\n        int rx = root(x);\n        int\
    \ ry = root(y);\n        return rx == ry;\n    }\n\n    long long size(int x){\n\
    \        return -par[root(x)];\n    }\n\n    long long edge(int x){\n        return\
    \ edg[root(x)];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Union Find\n * @docs docs/data_structure/union_find.md\n\
    \ */\n\nstruct UnionFind{\n    vector<int> par;\n    vector<int> edg;\n\n    UnionFind(int\
    \ N) : par(N), edg(N){\n        for(int i = 0; i < N; ++i){\n            par[i]\
    \ = -1;\n            edg[i] = 0;\n        }\n    }\n\n    int root(int x){\n \
    \       if(par[x] < 0) return x;\n        return par[x] = root(par[x]);\n    }\n\
    \n    void unite(int x, int y){\n        int rx = root(x);\n        int ry = root(y);\n\
    \        if(rx == ry){\n            edg[rx]++;\n            return;\n        }\n\
    \        par[ry] = par[rx] + par[ry];\n        par[rx] = ry;\n        edg[ry]\
    \ += edg[rx] + 1;\n    }\n\n    bool same(int x, int y){\n        int rx = root(x);\n\
    \        int ry = root(y);\n        return rx == ry;\n    }\n\n    long long size(int\
    \ x){\n        return -par[root(x)];\n    }\n\n    long long edge(int x){\n  \
    \      return edg[root(x)];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/union_find.hpp
  requiredBy:
  - lib/graph/manhattanMST.hpp
  timestamp: '2023-05-21 17:12:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/unionfind.test.cpp
  - test/library_checker/graph/minimum_spanning_tree.test.cpp
  - test/library_checker/graph/manhattanmst.test.cpp
  - test/library_checker/graph/cycle_detection_undirected.test.cpp
documentation_of: lib/data_structure/union_find.hpp
layout: document
redirect_from:
- /library/lib/data_structure/union_find.hpp
- /library/lib/data_structure/union_find.hpp.html
title: Union Find
---
## Union Find

#### 使い方

- `UnionFind(N)`: 要素数 N の Union Find を構築します。
- `root(x)`: 集合 x の根を取得します。
- `unite(x, y)`: 集合 x と y を併合します。
- `same(x, y)`: x と y の属する集合が等しいかどうかを判定します。
- `size(x)`: x の属する集合の大きさを取得します。
- `edge(x)`: x の属する集合に張られている辺の本数を取得します。

#### 計算量

- `UnionFind(N)`: $\mathrm{O}(N)$
- `root(x)`: 償却 $\alpha(N)$ (アッカーマンの逆関数)
- `unite(x, y)`: 償却 $\alpha(N)$
- `same(x, y)`: 償却 $\alpha(N)$
- `size(x)`: 償却 $\alpha(N)$
- `edge(x)`: 償却 $\alpha(N)$