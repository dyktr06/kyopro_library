---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/grl/grl_4_b.test.cpp
    title: test/aoj/grl/grl_4_b.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/topologocal_sort.hpp\"\n\n// \u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3067\u8F9E\u66F8\u9806\u6700\u5C0F\u306E\
    \u3082\u306E\u3092\u6C42\u3081\u307E\u3059: O(E + VlogV)\ntemplate <typename T>\n\
    vector<T> topological_sort(const vector<vector<T>> &G){\n    int siz = (int) G.size();\n\
    \    vector<int> indegree(siz);\n    for(int i = 0; i < siz; i++){\n        for(auto\
    \ x : G[i]){\n            indegree[x]++;\n        }\n    }\n\n    priority_queue<int,\
    \ vector<int>, greater<int>> heap;\n    for(int i = 0; i < siz; i++){\n      \
    \  if(indegree[i] == 0){\n            heap.push(i);\n        }\n    }\n\n    vector<T>\
    \ res;\n    while(!heap.empty()){\n        int node = heap.top();\n        heap.pop();\n\
    \        res.push_back(node);\n        for(auto x : G[node]){\n            indegree[x]--;\n\
    \            if(indegree[x] == 0){\n                heap.push(x);\n          \
    \  }\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n// \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
    \u3067\u8F9E\u66F8\u9806\u6700\u5C0F\u306E\u3082\u306E\u3092\u6C42\u3081\u307E\
    \u3059: O(E + VlogV)\ntemplate <typename T>\nvector<T> topological_sort(const\
    \ vector<vector<T>> &G){\n    int siz = (int) G.size();\n    vector<int> indegree(siz);\n\
    \    for(int i = 0; i < siz; i++){\n        for(auto x : G[i]){\n            indegree[x]++;\n\
    \        }\n    }\n\n    priority_queue<int, vector<int>, greater<int>> heap;\n\
    \    for(int i = 0; i < siz; i++){\n        if(indegree[i] == 0){\n          \
    \  heap.push(i);\n        }\n    }\n\n    vector<T> res;\n    while(!heap.empty()){\n\
    \        int node = heap.top();\n        heap.pop();\n        res.push_back(node);\n\
    \        for(auto x : G[node]){\n            indegree[x]--;\n            if(indegree[x]\
    \ == 0){\n                heap.push(x);\n            }\n        }\n    }\n   \
    \ return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/topologocal_sort.hpp
  requiredBy: []
  timestamp: '2022-11-11 03:58:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/grl/grl_4_b.test.cpp
documentation_of: lib/graph/topologocal_sort.hpp
layout: document
redirect_from:
- /library/lib/graph/topologocal_sort.hpp
- /library/lib/graph/topologocal_sort.hpp.html
title: lib/graph/topologocal_sort.hpp
---
