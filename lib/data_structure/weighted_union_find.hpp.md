---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl_1_b.test.cpp
    title: test/aoj/dsl/dsl_1_b.test.cpp
  - icon: ':x:'
    path: test/library_checker/data_structure/unionfind_with_potential.test.cpp
    title: test/library_checker/data_structure/unionfind_with_potential.test.cpp
  - icon: ':x:'
    path: test/library_checker/data_structure/unionfind_with_potential_non_commutative_group.test.cpp
    title: test/library_checker/data_structure/unionfind_with_potential_non_commutative_group.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/data_structure/weighted_union_find.md
    document_title: Weighted Union Find
    links: []
  bundledCode: "#line 2 \"lib/data_structure/weighted_union_find.hpp\"\n\n/**\n *\
    \ @brief Weighted Union Find\n * @docs docs/data_structure/weighted_union_find.md\n\
    \ */\n\n#include <vector>\n#include <cassert>\n\ntemplate <typename T>\nstruct\
    \ WeightedUnionFind{\n    int V;\n    std::vector<int> par;\n    std::vector<T>\
    \ diff_weight;\n    T ex;\n\n    WeightedUnionFind(const int N, const T &e = 0)\
    \ : V(N), par(N), diff_weight(N), ex(e){\n        for(int i = 0; i < N; ++i){\n\
    \            par[i] = -1;\n            diff_weight[i] = e;\n        }\n    }\n\
    \n    int root(const int x){\n        assert(0 <= x && x < V);\n        if(par[x]\
    \ < 0){\n            return x;\n        }\n        int px = par[x];\n        int\
    \ rx = root(par[x]);\n        diff_weight[x] = diff_weight[x] + diff_weight[px];\n\
    \        return par[x] = rx;\n    }\n\n    T weight(const int x){\n        root(x);\n\
    \        return diff_weight[x];\n    }\n\n    T diff(const int x, const int y){\n\
    \        return weight(x) - weight(y);\n    }\n\n    void unite(const int x, const\
    \ int y, const T &w){\n        int tx = x, ty = y;\n        T tw = w;\n      \
    \  int rx = root(x), ry = root(y);\n        if(rx == ry) return;\n\n        if(par[rx]\
    \ < par[ry]){\n            std::swap(rx, ry);\n            std::swap(tx, ty);\n\
    \            tw = ex - tw;\n        }\n\n        par[ry] = par[rx] + par[ry];\n\
    \        par[rx] = ry;\n        diff_weight[rx] = ex - diff_weight[tx] + tw +\
    \ diff_weight[ty];\n    }\n\n    bool same(const int x, const int y){\n      \
    \  return root(x) == root(y);\n    }\n\n    int size(const int x){\n        return\
    \ -par[root(x)];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Weighted Union Find\n * @docs docs/data_structure/weighted_union_find.md\n\
    \ */\n\n#include <vector>\n#include <cassert>\n\ntemplate <typename T>\nstruct\
    \ WeightedUnionFind{\n    int V;\n    std::vector<int> par;\n    std::vector<T>\
    \ diff_weight;\n    T ex;\n\n    WeightedUnionFind(const int N, const T &e = 0)\
    \ : V(N), par(N), diff_weight(N), ex(e){\n        for(int i = 0; i < N; ++i){\n\
    \            par[i] = -1;\n            diff_weight[i] = e;\n        }\n    }\n\
    \n    int root(const int x){\n        assert(0 <= x && x < V);\n        if(par[x]\
    \ < 0){\n            return x;\n        }\n        int px = par[x];\n        int\
    \ rx = root(par[x]);\n        diff_weight[x] = diff_weight[x] + diff_weight[px];\n\
    \        return par[x] = rx;\n    }\n\n    T weight(const int x){\n        root(x);\n\
    \        return diff_weight[x];\n    }\n\n    T diff(const int x, const int y){\n\
    \        return weight(x) - weight(y);\n    }\n\n    void unite(const int x, const\
    \ int y, const T &w){\n        int tx = x, ty = y;\n        T tw = w;\n      \
    \  int rx = root(x), ry = root(y);\n        if(rx == ry) return;\n\n        if(par[rx]\
    \ < par[ry]){\n            std::swap(rx, ry);\n            std::swap(tx, ty);\n\
    \            tw = ex - tw;\n        }\n\n        par[ry] = par[rx] + par[ry];\n\
    \        par[rx] = ry;\n        diff_weight[rx] = ex - diff_weight[tx] + tw +\
    \ diff_weight[ty];\n    }\n\n    bool same(const int x, const int y){\n      \
    \  return root(x) == root(y);\n    }\n\n    int size(const int x){\n        return\
    \ -par[root(x)];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/weighted_union_find.hpp
  requiredBy: []
  timestamp: '2024-11-15 16:06:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/data_structure/unionfind_with_potential.test.cpp
  - test/library_checker/data_structure/unionfind_with_potential_non_commutative_group.test.cpp
  - test/aoj/dsl/dsl_1_b.test.cpp
documentation_of: lib/data_structure/weighted_union_find.hpp
layout: document
redirect_from:
- /library/lib/data_structure/weighted_union_find.hpp
- /library/lib/data_structure/weighted_union_find.hpp.html
title: Weighted Union Find
---
## Weighted Union Find

#### 使い方

- `WeightedUnionFind(N)`: 要素数 N の Weighted Union Find を構築します。
- `root(x)`: 集合 x の根を取得します。
- `diff(x, y)`: x と y の重みの差を取得します。
- `unite(x, y, w)`: 集合 x と y について、重みが w として併合します。
- `same(x, y)`: x と y の属する集合が等しいかどうかを判定します。
- `size(x)`: x の属する集合の大きさを取得します。

#### 計算量

- `WeightedUnionFind(N)`: $\mathrm{O}(N)$
- `root(x)`: 償却 $\mathrm{O}(\alpha(N))$ (アッカーマンの逆関数)
- `diff(x, y)`: 償却 $\mathrm{O}(\alpha(N))$
- `unite(x, y, w)`: 償却 $\mathrm{O}(\alpha(N))$
- `same(x, y)`: 償却 $\mathrm{O}(\alpha(N))$
- `size(x)`: 償却 $\mathrm{O}(\alpha(N))$
