---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: lib/data_structure/union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/manhattanmst].test.cpp
    title: test/library_checker/graph/manhattanmst].test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/manhattanMST.hpp\"\n\n#line 2 \"lib/data_structure/union_find.hpp\"\
    \n\n/* \n    UnionFind(n) : Union-Find \u6728\u3092\u30B5\u30A4\u30BAn\u3067\u69CB\
    \u7BC9\n    \u8A08\u7B97\u91CF : O(a(n)) -> \u30A2\u30C3\u30AB\u30FC\u30DE\u30F3\
    \u306E\u9006\u95A2\u6570\n    root(x) : \u96C6\u5408 x \u306E\u6839\u3092\u53D6\
    \u5F97\u3057\u307E\u3059\u3002\n    unite(x, y) : \u96C6\u5408 x \u3068 y \u3092\
    \u4F75\u5408\u3057\u307E\u3059\u3002\n    same(x, y) : \u96C6\u5408 x \u3068 \u96C6\
    \u5408 y \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3057\
    \u307E\u3059\u3002\n    size(x) : x \u3092\u542B\u3080\u96C6\u5408\u306E\u5927\
    \u304D\u3055\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\n    edge(x) : x \u3092\
    \u542B\u3080\u96C6\u5408\u306B\u8CBC\u3089\u308C\u3066\u3044\u308B\u8FBA\u306E\
    \u672C\u6570\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\n*/\n\n// Union-Find \u6728\
    \u306E\u5B9F\u88C5\nstruct UnionFind {\n    vector<int> par;\n    vector<int>\
    \ siz;\n    vector<int> edg;\n\n    UnionFind(int N) : par(N), siz(N), edg(N)\
    \ {\n        for(int i = 0; i < N; ++i){\n            par[i] = i;\n          \
    \  siz[i] = 1;\n            edg[i] = 0;\n        }\n    }\n\n    int root(int\
    \ x) {\n        if (par[x] == x) return x;\n        return par[x] = root(par[x]);\n\
    \    }\n\n    void unite(int x, int y) {\n        int rx = root(x);\n        int\
    \ ry = root(y);\n        if (rx == ry){\n            edg[rx]++;\n            return;\n\
    \        }\n        par[rx] = ry;\n        siz[ry] += siz[rx];\n        edg[ry]\
    \ += edg[rx] + 1;\n    }\n\n    bool same(int x, int y){\n        int rx = root(x);\n\
    \        int ry = root(y);\n        return rx == ry;\n    }\n\n    long long size(int\
    \ x){\n        return siz[root(x)];\n    }\n\n    long long edge(int x){\n   \
    \     return edg[root(x)];\n    }\n};\n#line 4 \"lib/graph/manhattanMST.hpp\"\n\
    \n/*\n    \u4E8C\u6B21\u5143\u5E73\u9762\u4E0A\u306E N \u500B \u306E\u9802\u70B9\
    \u306B\u304A\u3051\u308B\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3067\
    \u306E\u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u307E\u3059\u3002\n*/\n\
    \ntemplate <typename T>\nvector<pair<int, int>> manhattanMST(vector<T> x, vector<T>\
    \ y){\n    int n = x.size();\n    vector<tuple<T, int, int>> edge;\n    edge.reserve(4\
    \ * n);\n    vector<int> idx(n);\n    iota(idx.begin(), idx.end(), 0);\n    for(int\
    \ s = 0; s < 2; ++s){\n        for(int t = 0; t < 2; ++t){\n            sort(idx.begin(),\
    \ idx.end(), [&](const int i, const int j) {\n                return x[i] + y[i]\
    \ < x[j] + y[j];\n            });\n            map<T, int, greater<>> map;\n \
    \           for(const int i : idx){\n                for(auto iter = map.lower_bound(y[i]);\
    \ iter != map.end(); iter = map.erase(iter)){\n                    const int j\
    \ = iter->second;\n                    const T dx = x[i] - x[j];\n           \
    \         const T dy = y[i] - y[j];\n                    if(dy > dx) break;\n\
    \                    edge.emplace_back(dx + dy, i, j);\n                }\n  \
    \              map[y[i]] = i;\n            }\n            swap(x, y);\n      \
    \  }\n        for(int i = 0; i < n; ++i) {\n            x[i] *= -1;\n        }\n\
    \    }\n    sort(edge.begin(), edge.end());\n    UnionFind dsu(n);\n    vector<pair<int,\
    \ int>> used;\n    used.reserve(n - 1);\n    for(const auto& [c, i, j] : edge){\n\
    \        if(!dsu.same(i, j)){\n            used.emplace_back(i, j);\n        \
    \    dsu.unite(i, j);\n        }\n    }\n    return used;\n}\n"
  code: "#pragma once\n\n#include \"../data_structure/union_find.hpp\"\n\n/*\n   \
    \ \u4E8C\u6B21\u5143\u5E73\u9762\u4E0A\u306E N \u500B \u306E\u9802\u70B9\u306B\
    \u304A\u3051\u308B\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3067\u306E\
    \u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u307E\u3059\u3002\n*/\n\ntemplate\
    \ <typename T>\nvector<pair<int, int>> manhattanMST(vector<T> x, vector<T> y){\n\
    \    int n = x.size();\n    vector<tuple<T, int, int>> edge;\n    edge.reserve(4\
    \ * n);\n    vector<int> idx(n);\n    iota(idx.begin(), idx.end(), 0);\n    for(int\
    \ s = 0; s < 2; ++s){\n        for(int t = 0; t < 2; ++t){\n            sort(idx.begin(),\
    \ idx.end(), [&](const int i, const int j) {\n                return x[i] + y[i]\
    \ < x[j] + y[j];\n            });\n            map<T, int, greater<>> map;\n \
    \           for(const int i : idx){\n                for(auto iter = map.lower_bound(y[i]);\
    \ iter != map.end(); iter = map.erase(iter)){\n                    const int j\
    \ = iter->second;\n                    const T dx = x[i] - x[j];\n           \
    \         const T dy = y[i] - y[j];\n                    if(dy > dx) break;\n\
    \                    edge.emplace_back(dx + dy, i, j);\n                }\n  \
    \              map[y[i]] = i;\n            }\n            swap(x, y);\n      \
    \  }\n        for(int i = 0; i < n; ++i) {\n            x[i] *= -1;\n        }\n\
    \    }\n    sort(edge.begin(), edge.end());\n    UnionFind dsu(n);\n    vector<pair<int,\
    \ int>> used;\n    used.reserve(n - 1);\n    for(const auto& [c, i, j] : edge){\n\
    \        if(!dsu.same(i, j)){\n            used.emplace_back(i, j);\n        \
    \    dsu.unite(i, j);\n        }\n    }\n    return used;\n}"
  dependsOn:
  - lib/data_structure/union_find.hpp
  isVerificationFile: false
  path: lib/graph/manhattanMST.hpp
  requiredBy: []
  timestamp: '2022-12-26 03:19:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/manhattanmst].test.cpp
documentation_of: lib/graph/manhattanMST.hpp
layout: document
redirect_from:
- /library/lib/graph/manhattanMST.hpp
- /library/lib/graph/manhattanMST.hpp.html
title: lib/graph/manhattanMST.hpp
---
