---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/unionfind_1.test.cpp
    title: test/library_checker/data_structure/unionfind_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/dynamic_union_find.hpp\"\n\n/*\n    DynamicUnionFind(n)\
    \ : Union-Find \u6728\u3092\u30B5\u30A4\u30BAn\u3067\u69CB\u7BC9\n    \u8A08\u7B97\
    \u91CF : O(a(n)) -> \u30A2\u30C3\u30AB\u30FC\u30DE\u30F3\u306E\u9006\u95A2\u6570\
    \n    root(x) : \u96C6\u5408 x \u306E\u6839\u3092\u53D6\u5F97\u3057\u307E\u3059\
    \u3002\n    unite(x, y) : \u96C6\u5408 x \u3068 y \u3092\u4F75\u5408\u3057\u307E\
    \u3059\u3002\n    same(x, y) : \u96C6\u5408 x \u3068 \u96C6\u5408 y \u304C\u7B49\
    \u3057\u3044\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3057\u307E\u3059\u3002\
    \n    size(x) : x \u3092\u542B\u3080\u96C6\u5408\u306E\u5927\u304D\u3055\u3092\
    \u53D6\u5F97\u3057\u307E\u3059\u3002\n*/\n\ntemplate <typename T>\nstruct DynamicUnionFind{\n\
    \    unordered_map<T, T> par, siz;\n\n    DynamicUnionFind(){\n    }\n\n    void\
    \ init(const T &x){\n        par[x] = x;\n        siz[x] = 1;\n    }\n\n    T\
    \ root(const T &x){\n        if(par.find(x) == par.end()){\n            init(x);\n\
    \        }\n        if(par[x] == x) return x;\n        return par[x] = root(par[x]);\n\
    \    }\n\n    void unite(const T &x, const T &y){\n        if(par.find(x) == par.end()){\n\
    \            init(x);\n        }\n        if(par.find(y) == par.end()){\n    \
    \        init(y);\n        }\n        int rx = root(x);\n        int ry = root(y);\n\
    \        if(size(rx) < size(ry)) swap(rx, ry);\n        par[rx] = ry;\n      \
    \  siz[ry] += siz[rx];\n    }\n\n    bool same(const T &x, const T &y){\n    \
    \    int rx = root(x);\n        int ry = root(y);\n        return rx == ry;\n\
    \    }\n\n    T size(const T &x){\n        if(par.find(x) == par.end()){\n   \
    \         init(x);\n        }\n        return siz[root(x)];\n    }\n};\n"
  code: "#pragma once\n\n/*\n    DynamicUnionFind(n) : Union-Find \u6728\u3092\u30B5\
    \u30A4\u30BAn\u3067\u69CB\u7BC9\n    \u8A08\u7B97\u91CF : O(a(n)) -> \u30A2\u30C3\
    \u30AB\u30FC\u30DE\u30F3\u306E\u9006\u95A2\u6570\n    root(x) : \u96C6\u5408 x\
    \ \u306E\u6839\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\n    unite(x, y) : \u96C6\
    \u5408 x \u3068 y \u3092\u4F75\u5408\u3057\u307E\u3059\u3002\n    same(x, y) :\
    \ \u96C6\u5408 x \u3068 \u96C6\u5408 y \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\
    \u304B\u3092\u5224\u5B9A\u3057\u307E\u3059\u3002\n    size(x) : x \u3092\u542B\
    \u3080\u96C6\u5408\u306E\u5927\u304D\u3055\u3092\u53D6\u5F97\u3057\u307E\u3059\
    \u3002\n*/\n\ntemplate <typename T>\nstruct DynamicUnionFind{\n    unordered_map<T,\
    \ T> par, siz;\n\n    DynamicUnionFind(){\n    }\n\n    void init(const T &x){\n\
    \        par[x] = x;\n        siz[x] = 1;\n    }\n\n    T root(const T &x){\n\
    \        if(par.find(x) == par.end()){\n            init(x);\n        }\n    \
    \    if(par[x] == x) return x;\n        return par[x] = root(par[x]);\n    }\n\
    \n    void unite(const T &x, const T &y){\n        if(par.find(x) == par.end()){\n\
    \            init(x);\n        }\n        if(par.find(y) == par.end()){\n    \
    \        init(y);\n        }\n        int rx = root(x);\n        int ry = root(y);\n\
    \        if(size(rx) < size(ry)) swap(rx, ry);\n        par[rx] = ry;\n      \
    \  siz[ry] += siz[rx];\n    }\n\n    bool same(const T &x, const T &y){\n    \
    \    int rx = root(x);\n        int ry = root(y);\n        return rx == ry;\n\
    \    }\n\n    T size(const T &x){\n        if(par.find(x) == par.end()){\n   \
    \         init(x);\n        }\n        return siz[root(x)];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/dynamic_union_find.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/unionfind_1.test.cpp
documentation_of: lib/data_structure/dynamic_union_find.hpp
layout: document
redirect_from:
- /library/lib/data_structure/dynamic_union_find.hpp
- /library/lib/data_structure/dynamic_union_find.hpp.html
title: lib/data_structure/dynamic_union_find.hpp
---
