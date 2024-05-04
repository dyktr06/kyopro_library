---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl_1_b_1.test.cpp
    title: test/aoj/dsl/dsl_1_b_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/dynamic_weighted_union_find.hpp\"\n\n\
    template <typename T>\nstruct DynamicWeightedUnionFind{\n    map<long long, long\
    \ long> par, rank, siz;\n    map<T, T> diff_weight;\n    T e;\n\n    DynamicWeightedUnionFind(const\
    \ T &_e = 0) : e(_e){\n    }\n\n    void init(const T &x){\n        par[x] = x;\n\
    \        rank[x] = 0;\n        siz[x] = 1;\n        diff_weight[x] = e;\n    }\n\
    \n    int root(const int x){\n        if(par.find(x) == par.end()){\n        \
    \    init(x);\n        }\n        if(par[x] == x){\n            return x;\n  \
    \      }\n        int rx = root(par[x]);\n        diff_weight[x] += diff_weight[par[x]];\n\
    \        return par[x] = rx;\n    }\n\n    T weight(const int x){\n        root(x);\n\
    \        return diff_weight[x];\n    }\n\n    T diff(const int x, const int y){\n\
    \        return weight(y) - weight(x);\n    }\n\n    void unite(const int x, const\
    \ int y, T w){\n        if(par.find(x) == par.end()){\n            init(x);\n\
    \        }\n        if(par.find(y) == par.end()){\n            init(y);\n    \
    \    }\n        w += weight(x);\n        w -= weight(y);\n\n        int rx = root(x);\n\
    \        int ry = root(y);\n        if(rx == ry) return;\n\n        if(rank[rx]\
    \ < rank[ry]){\n            swap(rx, ry);\n            w = -w;\n        }\n\n\
    \        par[ry] = rx;\n        siz[rx] += siz[ry];\n        diff_weight[ry] =\
    \ w;\n        if(rank[rx] == rank[ry]) ++rank[rx];\n    }\n\n    bool same(const\
    \ int x, const int y){\n        int rx = root(x);\n        int ry = root(y);\n\
    \        return rx == ry;\n    }\n\n    int size(const int x){\n        return\
    \ siz[root(x)];\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct DynamicWeightedUnionFind{\n\
    \    map<long long, long long> par, rank, siz;\n    map<T, T> diff_weight;\n \
    \   T e;\n\n    DynamicWeightedUnionFind(const T &_e = 0) : e(_e){\n    }\n\n\
    \    void init(const T &x){\n        par[x] = x;\n        rank[x] = 0;\n     \
    \   siz[x] = 1;\n        diff_weight[x] = e;\n    }\n\n    int root(const int\
    \ x){\n        if(par.find(x) == par.end()){\n            init(x);\n        }\n\
    \        if(par[x] == x){\n            return x;\n        }\n        int rx =\
    \ root(par[x]);\n        diff_weight[x] += diff_weight[par[x]];\n        return\
    \ par[x] = rx;\n    }\n\n    T weight(const int x){\n        root(x);\n      \
    \  return diff_weight[x];\n    }\n\n    T diff(const int x, const int y){\n  \
    \      return weight(y) - weight(x);\n    }\n\n    void unite(const int x, const\
    \ int y, T w){\n        if(par.find(x) == par.end()){\n            init(x);\n\
    \        }\n        if(par.find(y) == par.end()){\n            init(y);\n    \
    \    }\n        w += weight(x);\n        w -= weight(y);\n\n        int rx = root(x);\n\
    \        int ry = root(y);\n        if(rx == ry) return;\n\n        if(rank[rx]\
    \ < rank[ry]){\n            swap(rx, ry);\n            w = -w;\n        }\n\n\
    \        par[ry] = rx;\n        siz[rx] += siz[ry];\n        diff_weight[ry] =\
    \ w;\n        if(rank[rx] == rank[ry]) ++rank[rx];\n    }\n\n    bool same(const\
    \ int x, const int y){\n        int rx = root(x);\n        int ry = root(y);\n\
    \        return rx == ry;\n    }\n\n    int size(const int x){\n        return\
    \ siz[root(x)];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/dynamic_weighted_union_find.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl/dsl_1_b_1.test.cpp
documentation_of: lib/data_structure/dynamic_weighted_union_find.hpp
layout: document
redirect_from:
- /library/lib/data_structure/dynamic_weighted_union_find.hpp
- /library/lib/data_structure/dynamic_weighted_union_find.hpp.html
title: lib/data_structure/dynamic_weighted_union_find.hpp
---
