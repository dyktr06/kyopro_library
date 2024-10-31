---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/enumerate_triangles.test.cpp
    title: test/library_checker/graph/enumerate_triangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Enumerate Triangles
    links:
    - https://www.slideshare.net/slideshow/trianguler/38443802
  bundledCode: "#line 2 \"lib/graph/enumerate_triangles.hpp\"\n\n/**\n * @brief Enumerate\
    \ Triangles\n * @see https://www.slideshare.net/slideshow/trianguler/38443802\n\
    \ */\n\nvector<array<int, 3>> enumerateTriangles(vector<vector<int>> &G){\n  \
    \  int n = G.size();\n    vector<vector<int>> DAG(n);\n    for(int i = 0; i <\
    \ n; i++){\n        for(auto &j : G[i]){\n            pair<int, int> p = {(int)\
    \ G[i].size(), i}, q = {(int) G[j].size(), j};\n            if(p < q){\n     \
    \           DAG[i].push_back(j);\n            }\n        }\n    }\n\n    vector<array<int,\
    \ 3>> res;\n    vector<int> edge(n);\n    for(int i = 0; i < n; i++){\n      \
    \  for(auto j : DAG[i]){\n            for(auto k : DAG[i]){\n                edge[k]++;\n\
    \            }\n            for(auto k : DAG[j]){\n                if(edge[k]){\n\
    \                    res.push_back({i, j, k});\n                }\n          \
    \  }\n            for(auto k : DAG[i]){\n                edge[k]--;\n        \
    \    }\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Enumerate Triangles\n * @see https://www.slideshare.net/slideshow/trianguler/38443802\n\
    \ */\n\nvector<array<int, 3>> enumerateTriangles(vector<vector<int>> &G){\n  \
    \  int n = G.size();\n    vector<vector<int>> DAG(n);\n    for(int i = 0; i <\
    \ n; i++){\n        for(auto &j : G[i]){\n            pair<int, int> p = {(int)\
    \ G[i].size(), i}, q = {(int) G[j].size(), j};\n            if(p < q){\n     \
    \           DAG[i].push_back(j);\n            }\n        }\n    }\n\n    vector<array<int,\
    \ 3>> res;\n    vector<int> edge(n);\n    for(int i = 0; i < n; i++){\n      \
    \  for(auto j : DAG[i]){\n            for(auto k : DAG[i]){\n                edge[k]++;\n\
    \            }\n            for(auto k : DAG[j]){\n                if(edge[k]){\n\
    \                    res.push_back({i, j, k});\n                }\n          \
    \  }\n            for(auto k : DAG[i]){\n                edge[k]--;\n        \
    \    }\n        }\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/enumerate_triangles.hpp
  requiredBy: []
  timestamp: '2024-10-31 23:51:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/enumerate_triangles.test.cpp
documentation_of: lib/graph/enumerate_triangles.hpp
layout: document
redirect_from:
- /library/lib/graph/enumerate_triangles.hpp
- /library/lib/graph/enumerate_triangles.hpp.html
title: Enumerate Triangles
---
