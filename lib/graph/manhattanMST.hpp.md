---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/data_structure/union_find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/manhattanmst.test.cpp
    title: test/library_checker/graph/manhattanmst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/manhattanMST.md
    document_title: Manhattan MST
    links: []
  bundledCode: "#line 2 \"lib/graph/manhattanMST.hpp\"\n\n#line 2 \"lib/data_structure/union_find.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n\n/**\n * @brief Union Find\n * @docs\
    \ docs/data_structure/union_find.md\n */\n\nstruct UnionFind{\n    int V;\n  \
    \  std::vector<int> par;\n    std::vector<int> edg;\n\n    UnionFind(int N) :\
    \ V(N), par(N), edg(N){\n        for(int i = 0; i < N; ++i){\n            par[i]\
    \ = -1;\n            edg[i] = 0;\n        }\n    }\n\n    int root(int x){\n \
    \       assert(0 <= x && x < V);\n        if(par[x] < 0) return x;\n        return\
    \ par[x] = root(par[x]);\n    }\n\n    int unite(int x, int y){\n        int rx\
    \ = root(x);\n        int ry = root(y);\n        if(rx == ry){\n            edg[rx]++;\n\
    \            return rx;\n        }\n        if(-par[rx] < -par[ry]) std::swap(rx,\
    \ ry);\n        par[rx] = par[rx] + par[ry];\n        par[ry] = rx;\n        edg[rx]\
    \ += edg[ry] + 1;\n        return rx;\n    }\n\n    bool same(int x, int y){\n\
    \        int rx = root(x);\n        int ry = root(y);\n        return rx == ry;\n\
    \    }\n\n    long long size(int x){\n        return -par[root(x)];\n    }\n\n\
    \    long long edge(int x){\n        return edg[root(x)];\n    }\n};\n#line 4\
    \ \"lib/graph/manhattanMST.hpp\"\n\n/**\n * @brief Manhattan MST\n * @docs docs/graph/manhattanMST.md\n\
    \ */\n\ntemplate <typename T>\nvector<pair<int, int>> manhattanMST(vector<T> x,\
    \ vector<T> y){\n    int n = x.size();\n    vector<tuple<T, int, int>> edge;\n\
    \    edge.reserve(4 * n);\n    vector<int> idx(n);\n    iota(idx.begin(), idx.end(),\
    \ 0);\n    for(int s = 0; s < 2; ++s){\n        for(int t = 0; t < 2; ++t){\n\
    \            sort(idx.begin(), idx.end(), [&](const int i, const int j) {\n  \
    \              return x[i] + y[i] < x[j] + y[j];\n            });\n          \
    \  map<T, int, greater<>> map;\n            for(const int i : idx){\n        \
    \        for(auto iter = map.lower_bound(y[i]); iter != map.end(); iter = map.erase(iter)){\n\
    \                    const int j = iter->second;\n                    const T\
    \ dx = x[i] - x[j];\n                    const T dy = y[i] - y[j];\n         \
    \           if(dy > dx) break;\n                    edge.emplace_back(dx + dy,\
    \ i, j);\n                }\n                map[y[i]] = i;\n            }\n \
    \           swap(x, y);\n        }\n        for(int i = 0; i < n; ++i) {\n   \
    \         x[i] *= -1;\n        }\n    }\n    sort(edge.begin(), edge.end());\n\
    \    UnionFind dsu(n);\n    vector<pair<int, int>> used;\n    used.reserve(n -\
    \ 1);\n    for(const auto &[c, i, j] : edge){\n        if(!dsu.same(i, j)){\n\
    \            used.emplace_back(i, j);\n            dsu.unite(i, j);\n        }\n\
    \    }\n    return used;\n}\n"
  code: "#pragma once\n\n#include \"../data_structure/union_find.hpp\"\n\n/**\n *\
    \ @brief Manhattan MST\n * @docs docs/graph/manhattanMST.md\n */\n\ntemplate <typename\
    \ T>\nvector<pair<int, int>> manhattanMST(vector<T> x, vector<T> y){\n    int\
    \ n = x.size();\n    vector<tuple<T, int, int>> edge;\n    edge.reserve(4 * n);\n\
    \    vector<int> idx(n);\n    iota(idx.begin(), idx.end(), 0);\n    for(int s\
    \ = 0; s < 2; ++s){\n        for(int t = 0; t < 2; ++t){\n            sort(idx.begin(),\
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
    \ int>> used;\n    used.reserve(n - 1);\n    for(const auto &[c, i, j] : edge){\n\
    \        if(!dsu.same(i, j)){\n            used.emplace_back(i, j);\n        \
    \    dsu.unite(i, j);\n        }\n    }\n    return used;\n}\n"
  dependsOn:
  - lib/data_structure/union_find.hpp
  isVerificationFile: false
  path: lib/graph/manhattanMST.hpp
  requiredBy: []
  timestamp: '2024-10-31 17:18:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/manhattanmst.test.cpp
documentation_of: lib/graph/manhattanMST.hpp
layout: document
redirect_from:
- /library/lib/graph/manhattanMST.hpp
- /library/lib/graph/manhattanMST.hpp.html
title: Manhattan MST
---
## Manhattan MST

#### 概要

二次元平面上の $N$ 個 の頂点におけるマンハッタン距離での最小全域木を求めます。

(マンハッタン距離において最も近い 2 点を探したいときなどに使えます。)

#### 計算量

- $\mathrm{O}(N \log N)$