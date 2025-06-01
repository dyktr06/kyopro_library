---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/range_parallel_union_find.hpp
    title: Range Parallel Union-Find
  - icon: ':warning:'
    path: lib/graph/T_join.hpp
    title: T-join Problem
  - icon: ':heavy_check_mark:'
    path: lib/graph/manhattanMST.hpp
    title: Manhattan MST
  - icon: ':heavy_check_mark:'
    path: lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp
    title: lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/range_parallel_unionfind.test.cpp
    title: test/library_checker/data_structure/range_parallel_unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/unionfind.test.cpp
    title: test/library_checker/data_structure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/manhattanmst.test.cpp
    title: test/library_checker/geometry/manhattanmst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/cycle_detection_undirected.test.cpp
    title: test/library_checker/graph/cycle_detection_undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/minimum_spanning_tree.test.cpp
    title: test/library_checker/graph/minimum_spanning_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
    title: test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/union_find.md
    document_title: Union-Find
    links: []
  bundledCode: "#line 2 \"lib/data_structure/union_find.hpp\"\n\n/**\n * @brief Union-Find\n\
    \ * @docs docs/data_structure/union_find.md\n */\n\n#include <vector>\n#include\
    \ <cassert>\n\nstruct UnionFind{\n    int V;\n    std::vector<int> par;\n    std::vector<int>\
    \ edg;\n\n    UnionFind(const int N) : V(N), par(N), edg(N){\n        for(int\
    \ i = 0; i < N; ++i){\n            par[i] = -1;\n            edg[i] = 0;\n   \
    \     }\n    }\n\n    int root(int x){\n        assert(0 <= x && x < V);\n   \
    \     if(par[x] < 0) return x;\n        return par[x] = root(par[x]);\n    }\n\
    \n    int unite(int x, int y){\n        int rx = root(x);\n        int ry = root(y);\n\
    \        if(rx == ry){\n            edg[rx]++;\n            return rx;\n     \
    \   }\n        if(-par[rx] < -par[ry]) std::swap(rx, ry);\n        par[rx] = par[rx]\
    \ + par[ry];\n        par[ry] = rx;\n        edg[rx] += edg[ry] + 1;\n       \
    \ return rx;\n    }\n\n    bool same(int x, int y){\n        int rx = root(x);\n\
    \        int ry = root(y);\n        return rx == ry;\n    }\n\n    long long size(int\
    \ x){\n        return -par[root(x)];\n    }\n\n    long long edge(int x){\n  \
    \      return edg[root(x)];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Union-Find\n * @docs docs/data_structure/union_find.md\n\
    \ */\n\n#include <vector>\n#include <cassert>\n\nstruct UnionFind{\n    int V;\n\
    \    std::vector<int> par;\n    std::vector<int> edg;\n\n    UnionFind(const int\
    \ N) : V(N), par(N), edg(N){\n        for(int i = 0; i < N; ++i){\n          \
    \  par[i] = -1;\n            edg[i] = 0;\n        }\n    }\n\n    int root(int\
    \ x){\n        assert(0 <= x && x < V);\n        if(par[x] < 0) return x;\n  \
    \      return par[x] = root(par[x]);\n    }\n\n    int unite(int x, int y){\n\
    \        int rx = root(x);\n        int ry = root(y);\n        if(rx == ry){\n\
    \            edg[rx]++;\n            return rx;\n        }\n        if(-par[rx]\
    \ < -par[ry]) std::swap(rx, ry);\n        par[rx] = par[rx] + par[ry];\n     \
    \   par[ry] = rx;\n        edg[rx] += edg[ry] + 1;\n        return rx;\n    }\n\
    \n    bool same(int x, int y){\n        int rx = root(x);\n        int ry = root(y);\n\
    \        return rx == ry;\n    }\n\n    long long size(int x){\n        return\
    \ -par[root(x)];\n    }\n\n    long long edge(int x){\n        return edg[root(x)];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/union_find.hpp
  requiredBy:
  - lib/graph/T_join.hpp
  - lib/graph/manhattanMST.hpp
  - lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp
  - lib/data_structure/range_parallel_union_find.hpp
  timestamp: '2024-11-18 03:54:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/cycle_detection_undirected.test.cpp
  - test/library_checker/graph/minimum_spanning_tree.test.cpp
  - test/library_checker/data_structure/range_parallel_unionfind.test.cpp
  - test/library_checker/data_structure/unionfind.test.cpp
  - test/library_checker/geometry/manhattanmst.test.cpp
  - test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
documentation_of: lib/data_structure/union_find.hpp
layout: document
redirect_from:
- /library/lib/data_structure/union_find.hpp
- /library/lib/data_structure/union_find.hpp.html
title: Union-Find
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
- `root(x)`: 償却 $\mathrm{O}(\alpha(N))$ (アッカーマンの逆関数)
- `unite(x, y)`: 償却 $\mathrm{O}(\alpha(N))$
- `same(x, y)`: 償却 $\mathrm{O}(\alpha(N))$
- `size(x)`: 償却 $\mathrm{O}(\alpha(N))$
- `edge(x)`: 償却 $\mathrm{O}(\alpha(N))$
