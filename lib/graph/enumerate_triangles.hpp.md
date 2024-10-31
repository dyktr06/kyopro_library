---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/enumerate_triangles.test.cpp
    title: test/library_checker/graph/enumerate_triangles.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://www.slideshare.net/slideshow/trianguler/38443802
  bundledCode: "#line 2 \"lib/graph/enumerate_triangles.hpp\"\n\n// \u53C2\u8003:\
    \ https://www.slideshare.net/slideshow/trianguler/38443802\nvector<array<int,\
    \ 3>> enumerateTriangles(vector<vector<int>> &G){\n    int n = G.size();\n   \
    \ vector<vector<int>> DAG(n);\n    for(int i = 0; i < n; i++){\n        for(auto\
    \ &j : G[i]){\n            pair<int, int> p = {(int) G[i].size(), i}, q = {(int)\
    \ G[j].size(), j};\n            if(p < q){\n                DAG[i].push_back(j);\n\
    \            }\n        }\n    }\n\n    vector<array<int, 3>> res;\n    vector<int>\
    \ edge(n);\n    for(int i = 0; i < n; i++){\n        for(auto j : DAG[i]){\n \
    \           for(auto k : DAG[i]){\n                edge[k]++;\n            }\n\
    \            for(auto k : DAG[j]){\n                if(edge[k]){\n           \
    \         res.push_back({i, j, k});\n                }\n            }\n      \
    \      for(auto k : DAG[i]){\n                edge[k]--;\n            }\n    \
    \    }\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n// \u53C2\u8003: https://www.slideshare.net/slideshow/trianguler/38443802\n\
    vector<array<int, 3>> enumerateTriangles(vector<vector<int>> &G){\n    int n =\
    \ G.size();\n    vector<vector<int>> DAG(n);\n    for(int i = 0; i < n; i++){\n\
    \        for(auto &j : G[i]){\n            pair<int, int> p = {(int) G[i].size(),\
    \ i}, q = {(int) G[j].size(), j};\n            if(p < q){\n                DAG[i].push_back(j);\n\
    \            }\n        }\n    }\n\n    vector<array<int, 3>> res;\n    vector<int>\
    \ edge(n);\n    for(int i = 0; i < n; i++){\n        for(auto j : DAG[i]){\n \
    \           for(auto k : DAG[i]){\n                edge[k]++;\n            }\n\
    \            for(auto k : DAG[j]){\n                if(edge[k]){\n           \
    \         res.push_back({i, j, k});\n                }\n            }\n      \
    \      for(auto k : DAG[i]){\n                edge[k]--;\n            }\n    \
    \    }\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/enumerate_triangles.hpp
  requiredBy: []
  timestamp: '2024-10-21 04:45:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/enumerate_triangles.test.cpp
documentation_of: lib/graph/enumerate_triangles.hpp
layout: document
redirect_from:
- /library/lib/graph/enumerate_triangles.hpp
- /library/lib/graph/enumerate_triangles.hpp.html
title: lib/graph/enumerate_triangles.hpp
---
