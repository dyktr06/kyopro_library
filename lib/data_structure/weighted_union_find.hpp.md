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
    links: []
  bundledCode: "#line 2 \"lib/data_structure/weighted_union_find.hpp\"\n\n/* \n  \
    \  WeightedUnionFind(n) : Union-Find \u6728\u3092\u30B5\u30A4\u30BAn\u3067\u69CB\
    \u7BC9\n    \u8A08\u7B97\u91CF : O(a(n)) -> \u30A2\u30C3\u30AB\u30FC\u30DE\u30F3\
    \u306E\u9006\u95A2\u6570\n    root(x) : \u96C6\u5408 x \u306E\u6839\u3092\u53D6\
    \u5F97\u3057\u307E\u3059\u3002\n    unite(x, y) : \u96C6\u5408 x \u3068 y \u3092\
    \u4F75\u5408\u3057\u307E\u3059\u3002\n    same(x, y) : \u96C6\u5408 x \u3068 \u96C6\
    \u5408 y \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3057\
    \u307E\u3059\u3002\n    size(x) : x \u3092\u542B\u3080\u96C6\u5408\u306E\u5927\
    \u304D\u3055\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\n*/\n\ntemplate <typename\
    \ T>\nstruct WeightedUnionFind{\n    vector<int> par, rank, siz;\n    vector<T>\
    \ diff_weight;\n\n    WeightedUnionFind(const int &N, const T &e = 0) : par(N),\
    \ rank(N), siz(N), diff_weight(N){\n        for(int i = 0; i < N; ++i){\n    \
    \        par[i] = i;\n            rank[i] = 0;\n            siz[i] = 1;\n    \
    \        diff_weight[i] = e;\n        }\n    }\n\n    int root(const int &x){\n\
    \        if(par[x] == x){\n            return x;\n        }\n        int rx =\
    \ root(par[x]);\n        diff_weight[x] += diff_weight[par[x]];\n        return\
    \ par[x] = rx;\n    }\n\n    T weight(const int &x){\n        root(x);\n     \
    \   return diff_weight[x];\n    }\n\n    T diff(const int &x, const int &y){\n\
    \        return weight(y) - weight(x);\n    }\n\n    void unite(const int &x,\
    \ const int &y, T &w){\n        w += weight(x);\n        w -= weight(y);\n\n \
    \       int rx = root(x);\n        int ry = root(y);\n        if(rx == ry) return;\n\
    \n        if(rank[rx] < rank[ry]){\n            swap(rx, ry);\n            w =\
    \ -w;\n        }\n\n        par[ry] = rx;\n        siz[rx] += siz[ry];\n     \
    \   diff_weight[ry] = w;\n        if(rank[rx] == rank[ry]) ++rank[rx];\n    }\n\
    \n    bool same(const int &x, const int &y){\n        int rx = root(x);\n    \
    \    int ry = root(y);\n        return rx == ry;\n    }\n\n    int size(const\
    \ int &x){\n        return siz[root(x)];\n    }\n};\n"
  code: "#pragma once\n\n/* \n    WeightedUnionFind(n) : Union-Find \u6728\u3092\u30B5\
    \u30A4\u30BAn\u3067\u69CB\u7BC9\n    \u8A08\u7B97\u91CF : O(a(n)) -> \u30A2\u30C3\
    \u30AB\u30FC\u30DE\u30F3\u306E\u9006\u95A2\u6570\n    root(x) : \u96C6\u5408 x\
    \ \u306E\u6839\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\n    unite(x, y) : \u96C6\
    \u5408 x \u3068 y \u3092\u4F75\u5408\u3057\u307E\u3059\u3002\n    same(x, y) :\
    \ \u96C6\u5408 x \u3068 \u96C6\u5408 y \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\
    \u304B\u3092\u5224\u5B9A\u3057\u307E\u3059\u3002\n    size(x) : x \u3092\u542B\
    \u3080\u96C6\u5408\u306E\u5927\u304D\u3055\u3092\u53D6\u5F97\u3057\u307E\u3059\
    \u3002\n*/\n\ntemplate <typename T>\nstruct WeightedUnionFind{\n    vector<int>\
    \ par, rank, siz;\n    vector<T> diff_weight;\n\n    WeightedUnionFind(const int\
    \ &N, const T &e = 0) : par(N), rank(N), siz(N), diff_weight(N){\n        for(int\
    \ i = 0; i < N; ++i){\n            par[i] = i;\n            rank[i] = 0;\n   \
    \         siz[i] = 1;\n            diff_weight[i] = e;\n        }\n    }\n\n \
    \   int root(const int &x){\n        if(par[x] == x){\n            return x;\n\
    \        }\n        int rx = root(par[x]);\n        diff_weight[x] += diff_weight[par[x]];\n\
    \        return par[x] = rx;\n    }\n\n    T weight(const int &x){\n        root(x);\n\
    \        return diff_weight[x];\n    }\n\n    T diff(const int &x, const int &y){\n\
    \        return weight(y) - weight(x);\n    }\n\n    void unite(const int &x,\
    \ const int &y, T &w){\n        w += weight(x);\n        w -= weight(y);\n\n \
    \       int rx = root(x);\n        int ry = root(y);\n        if(rx == ry) return;\n\
    \n        if(rank[rx] < rank[ry]){\n            swap(rx, ry);\n            w =\
    \ -w;\n        }\n\n        par[ry] = rx;\n        siz[rx] += siz[ry];\n     \
    \   diff_weight[ry] = w;\n        if(rank[rx] == rank[ry]) ++rank[rx];\n    }\n\
    \n    bool same(const int &x, const int &y){\n        int rx = root(x);\n    \
    \    int ry = root(y);\n        return rx == ry;\n    }\n\n    int size(const\
    \ int &x){\n        return siz[root(x)];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/weighted_union_find.hpp
  requiredBy: []
  timestamp: '2022-11-18 02:29:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl/dsl_1_b.test.cpp
documentation_of: lib/data_structure/weighted_union_find.hpp
layout: document
redirect_from:
- /library/lib/data_structure/weighted_union_find.hpp
- /library/lib/data_structure/weighted_union_find.hpp.html
title: lib/data_structure/weighted_union_find.hpp
---
