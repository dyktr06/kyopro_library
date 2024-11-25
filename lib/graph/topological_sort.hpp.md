---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/graph/reachable_query.hpp
    title: lib/graph/reachable_query.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/topological_sort.md
    document_title: Topological Sort
    links: []
  bundledCode: "#line 2 \"lib/graph/topological_sort.hpp\"\n\n/**\n * @brief Topological\
    \ Sort\n * @docs docs/graph/topological_sort.md\n */\n\n#include <vector>\n#include\
    \ <queue>\n\ntemplate <typename T>\nstd::vector<T> topological_sort(const std::vector<std::vector<T>>\
    \ &G){\n    int siz = (int) G.size();\n    std::vector<int> indegree(siz);\n \
    \   for(int i = 0; i < siz; i++){\n        for(auto x : G[i]){\n            indegree[x]++;\n\
    \        }\n    }\n\n    std::priority_queue<int, std::vector<int>, std::greater<int>>\
    \ heap;\n    for(int i = 0; i < siz; i++){\n        if(indegree[i] == 0){\n  \
    \          heap.push(i);\n        }\n    }\n\n    std::vector<T> res;\n    while(!heap.empty()){\n\
    \        int node = heap.top();\n        heap.pop();\n        res.push_back(node);\n\
    \        for(auto x : G[node]){\n            indegree[x]--;\n            if(indegree[x]\
    \ == 0){\n                heap.push(x);\n            }\n        }\n    }\n   \
    \ return res;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Topological Sort\n * @docs docs/graph/topological_sort.md\n\
    \ */\n\n#include <vector>\n#include <queue>\n\ntemplate <typename T>\nstd::vector<T>\
    \ topological_sort(const std::vector<std::vector<T>> &G){\n    int siz = (int)\
    \ G.size();\n    std::vector<int> indegree(siz);\n    for(int i = 0; i < siz;\
    \ i++){\n        for(auto x : G[i]){\n            indegree[x]++;\n        }\n\
    \    }\n\n    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;\n\
    \    for(int i = 0; i < siz; i++){\n        if(indegree[i] == 0){\n          \
    \  heap.push(i);\n        }\n    }\n\n    std::vector<T> res;\n    while(!heap.empty()){\n\
    \        int node = heap.top();\n        heap.pop();\n        res.push_back(node);\n\
    \        for(auto x : G[node]){\n            indegree[x]--;\n            if(indegree[x]\
    \ == 0){\n                heap.push(x);\n            }\n        }\n    }\n   \
    \ return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/topological_sort.hpp
  requiredBy:
  - lib/graph/reachable_query.hpp
  timestamp: '2024-11-25 23:10:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/lib/graph/topological_sort.hpp
- /library/lib/graph/topological_sort.hpp.html
title: Topological Sort
---
## Topological Sort

#### 概要

トポロジカルソートで辞書順最小のものを求めます。

#### 計算量

頂点数を $V$、辺の数を $E$ とすると、$\mathrm{O}(E + V \log V)$