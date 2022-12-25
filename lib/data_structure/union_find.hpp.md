---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/manhattanMST.hpp
    title: lib/graph/manhattanMST.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/unionfind.test.cpp
    title: test/library_checker/data_structure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/manhattanmst].test.cpp
    title: test/library_checker/graph/manhattanmst].test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/union_find.hpp\"\n\n/* \n    UnionFind(n)\
    \ : Union-Find \u6728\u3092\u30B5\u30A4\u30BAn\u3067\u69CB\u7BC9\n    \u8A08\u7B97\
    \u91CF : O(a(n)) -> \u30A2\u30C3\u30AB\u30FC\u30DE\u30F3\u306E\u9006\u95A2\u6570\
    \n    root(x) : \u96C6\u5408 x \u306E\u6839\u3092\u53D6\u5F97\u3057\u307E\u3059\
    \u3002\n    unite(x, y) : \u96C6\u5408 x \u3068 y \u3092\u4F75\u5408\u3057\u307E\
    \u3059\u3002\n    same(x, y) : \u96C6\u5408 x \u3068 \u96C6\u5408 y \u304C\u7B49\
    \u3057\u3044\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3057\u307E\u3059\u3002\
    \n    size(x) : x \u3092\u542B\u3080\u96C6\u5408\u306E\u5927\u304D\u3055\u3092\
    \u53D6\u5F97\u3057\u307E\u3059\u3002\n    edge(x) : x \u3092\u542B\u3080\u96C6\
    \u5408\u306B\u8CBC\u3089\u308C\u3066\u3044\u308B\u8FBA\u306E\u672C\u6570\u3092\
    \u53D6\u5F97\u3057\u307E\u3059\u3002\n*/\n\n// Union-Find \u6728\u306E\u5B9F\u88C5\
    \nstruct UnionFind {\n    vector<int> par;\n    vector<int> siz;\n    vector<int>\
    \ edg;\n\n    UnionFind(int N) : par(N), siz(N), edg(N) {\n        for(int i =\
    \ 0; i < N; ++i){\n            par[i] = i;\n            siz[i] = 1;\n        \
    \    edg[i] = 0;\n        }\n    }\n\n    int root(int x) {\n        if (par[x]\
    \ == x) return x;\n        return par[x] = root(par[x]);\n    }\n\n    void unite(int\
    \ x, int y) {\n        int rx = root(x);\n        int ry = root(y);\n        if\
    \ (rx == ry){\n            edg[rx]++;\n            return;\n        }\n      \
    \  par[rx] = ry;\n        siz[ry] += siz[rx];\n        edg[ry] += edg[rx] + 1;\n\
    \    }\n\n    bool same(int x, int y){\n        int rx = root(x);\n        int\
    \ ry = root(y);\n        return rx == ry;\n    }\n\n    long long size(int x){\n\
    \        return siz[root(x)];\n    }\n\n    long long edge(int x){\n        return\
    \ edg[root(x)];\n    }\n};\n"
  code: "#pragma once\n\n/* \n    UnionFind(n) : Union-Find \u6728\u3092\u30B5\u30A4\
    \u30BAn\u3067\u69CB\u7BC9\n    \u8A08\u7B97\u91CF : O(a(n)) -> \u30A2\u30C3\u30AB\
    \u30FC\u30DE\u30F3\u306E\u9006\u95A2\u6570\n    root(x) : \u96C6\u5408 x \u306E\
    \u6839\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\n    unite(x, y) : \u96C6\u5408\
    \ x \u3068 y \u3092\u4F75\u5408\u3057\u307E\u3059\u3002\n    same(x, y) : \u96C6\
    \u5408 x \u3068 \u96C6\u5408 y \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\
    \u3092\u5224\u5B9A\u3057\u307E\u3059\u3002\n    size(x) : x \u3092\u542B\u3080\
    \u96C6\u5408\u306E\u5927\u304D\u3055\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\
    \n    edge(x) : x \u3092\u542B\u3080\u96C6\u5408\u306B\u8CBC\u3089\u308C\u3066\
    \u3044\u308B\u8FBA\u306E\u672C\u6570\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\
    \n*/\n\n// Union-Find \u6728\u306E\u5B9F\u88C5\nstruct UnionFind {\n    vector<int>\
    \ par;\n    vector<int> siz;\n    vector<int> edg;\n\n    UnionFind(int N) : par(N),\
    \ siz(N), edg(N) {\n        for(int i = 0; i < N; ++i){\n            par[i] =\
    \ i;\n            siz[i] = 1;\n            edg[i] = 0;\n        }\n    }\n\n \
    \   int root(int x) {\n        if (par[x] == x) return x;\n        return par[x]\
    \ = root(par[x]);\n    }\n\n    void unite(int x, int y) {\n        int rx = root(x);\n\
    \        int ry = root(y);\n        if (rx == ry){\n            edg[rx]++;\n \
    \           return;\n        }\n        par[rx] = ry;\n        siz[ry] += siz[rx];\n\
    \        edg[ry] += edg[rx] + 1;\n    }\n\n    bool same(int x, int y){\n    \
    \    int rx = root(x);\n        int ry = root(y);\n        return rx == ry;\n\
    \    }\n\n    long long size(int x){\n        return siz[root(x)];\n    }\n\n\
    \    long long edge(int x){\n        return edg[root(x)];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/union_find.hpp
  requiredBy:
  - lib/graph/manhattanMST.hpp
  timestamp: '2022-11-18 02:29:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/manhattanmst].test.cpp
  - test/library_checker/data_structure/unionfind.test.cpp
documentation_of: lib/data_structure/union_find.hpp
layout: document
redirect_from:
- /library/lib/data_structure/union_find.hpp
- /library/lib/data_structure/union_find.hpp.html
title: lib/data_structure/union_find.hpp
---
