---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl_1_b.test.cpp
    title: test/aoj/dsl/dsl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/weighted_union_find.md
    document_title: Weighted Union Find
    links: []
  bundledCode: "#line 2 \"lib/data_structure/weighted_union_find.hpp\"\n\n/**\n *\
    \ @brief Weighted Union Find\n * @docs docs/data_structure/weighted_union_find.md\n\
    \ */\n\ntemplate <typename T>\nstruct WeightedUnionFind{\n    vector<int> par,\
    \ rank, siz;\n    vector<T> diff_weight;\n\n    WeightedUnionFind(const int N,\
    \ const T &e = 0) : par(N), rank(N), siz(N), diff_weight(N){\n        for(int\
    \ i = 0; i < N; ++i){\n            par[i] = i;\n            rank[i] = 0;\n   \
    \         siz[i] = 1;\n            diff_weight[i] = e;\n        }\n    }\n\n \
    \   int root(const int x){\n        if(par[x] == x){\n            return x;\n\
    \        }\n        int rx = root(par[x]);\n        diff_weight[x] += diff_weight[par[x]];\n\
    \        return par[x] = rx;\n    }\n\n    T weight(const int x){\n        root(x);\n\
    \        return diff_weight[x];\n    }\n\n    T diff(const int x, const int y){\n\
    \        return weight(y) - weight(x);\n    }\n\n    void unite(const int x, const\
    \ int y, T w){\n        w += weight(x);\n        w -= weight(y);\n\n        int\
    \ rx = root(x);\n        int ry = root(y);\n        if(rx == ry) return;\n\n \
    \       if(rank[rx] < rank[ry]){\n            swap(rx, ry);\n            w = -w;\n\
    \        }\n\n        par[ry] = rx;\n        siz[rx] += siz[ry];\n        diff_weight[ry]\
    \ = w;\n        if(rank[rx] == rank[ry]) ++rank[rx];\n    }\n\n    bool same(const\
    \ int x, const int y){\n        int rx = root(x);\n        int ry = root(y);\n\
    \        return rx == ry;\n    }\n\n    int size(const int x){\n        return\
    \ siz[root(x)];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Weighted Union Find\n * @docs docs/data_structure/weighted_union_find.md\n\
    \ */\n\ntemplate <typename T>\nstruct WeightedUnionFind{\n    vector<int> par,\
    \ rank, siz;\n    vector<T> diff_weight;\n\n    WeightedUnionFind(const int N,\
    \ const T &e = 0) : par(N), rank(N), siz(N), diff_weight(N){\n        for(int\
    \ i = 0; i < N; ++i){\n            par[i] = i;\n            rank[i] = 0;\n   \
    \         siz[i] = 1;\n            diff_weight[i] = e;\n        }\n    }\n\n \
    \   int root(const int x){\n        if(par[x] == x){\n            return x;\n\
    \        }\n        int rx = root(par[x]);\n        diff_weight[x] += diff_weight[par[x]];\n\
    \        return par[x] = rx;\n    }\n\n    T weight(const int x){\n        root(x);\n\
    \        return diff_weight[x];\n    }\n\n    T diff(const int x, const int y){\n\
    \        return weight(y) - weight(x);\n    }\n\n    void unite(const int x, const\
    \ int y, T w){\n        w += weight(x);\n        w -= weight(y);\n\n        int\
    \ rx = root(x);\n        int ry = root(y);\n        if(rx == ry) return;\n\n \
    \       if(rank[rx] < rank[ry]){\n            swap(rx, ry);\n            w = -w;\n\
    \        }\n\n        par[ry] = rx;\n        siz[rx] += siz[ry];\n        diff_weight[ry]\
    \ = w;\n        if(rank[rx] == rank[ry]) ++rank[rx];\n    }\n\n    bool same(const\
    \ int x, const int y){\n        int rx = root(x);\n        int ry = root(y);\n\
    \        return rx == ry;\n    }\n\n    int size(const int x){\n        return\
    \ siz[root(x)];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/weighted_union_find.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
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
- `root(x)`: $\mathrm{O}(\log N)$
- `diff(x, y)`: $\mathrm{O}(\log N)$
- `unite(x, y, w)`: $\mathrm{O}(\log N)$
- `same(x, y)`: $\mathrm{O}(\log N)$
- `size(x)`: $\mathrm{O}(\log N)$
