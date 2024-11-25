---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/graph/topological_sort.hpp
    title: Topological Sort
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/reachable_query.hpp\"\n\n#line 2 \"lib/graph/topological_sort.hpp\"\
    \n\n/**\n * @brief Topological Sort\n * @docs docs/graph/topological_sort.md\n\
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
    \ return res;\n}\n#line 4 \"lib/graph/reachable_query.hpp\"\n\ntemplate <typename\
    \ T>\nvector<bool> reachable_query(const vector<vector<T>> &G, const vector<pair<T,\
    \ T>> &query){\n    int n = G.size(), q = query.size();\n    vector<T> ord = topological_sort(G);\n\
    \    vector<bool> res(q);\n    for(int l = 0; l < q; l += 64){\n        int r\
    \ = min(q, l + 64);\n        vector<long long> dp(n);\n        for(int k = l;\
    \ k < r; k++){\n            auto [a, b] = query[k];\n            dp[a] |= 1LL\
    \ << (k - l);\n        }\n        for(auto &idx : ord){\n            for(auto\
    \ &to : G[idx]){\n                dp[to] |= dp[idx];\n            }\n        }\n\
    \        for(int k = l; k < r; k++){\n            auto [a, b] = query[k];\n  \
    \          res[k] = (dp[b] >> (k - l)) & 1;\n        }\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n\n#include \"../graph/topological_sort.hpp\";\n\ntemplate <typename\
    \ T>\nvector<bool> reachable_query(const vector<vector<T>> &G, const vector<pair<T,\
    \ T>> &query){\n    int n = G.size(), q = query.size();\n    vector<T> ord = topological_sort(G);\n\
    \    vector<bool> res(q);\n    for(int l = 0; l < q; l += 64){\n        int r\
    \ = min(q, l + 64);\n        vector<long long> dp(n);\n        for(int k = l;\
    \ k < r; k++){\n            auto [a, b] = query[k];\n            dp[a] |= 1LL\
    \ << (k - l);\n        }\n        for(auto &idx : ord){\n            for(auto\
    \ &to : G[idx]){\n                dp[to] |= dp[idx];\n            }\n        }\n\
    \        for(int k = l; k < r; k++){\n            auto [a, b] = query[k];\n  \
    \          res[k] = (dp[b] >> (k - l)) & 1;\n        }\n    }\n    return res;\n\
    }\n"
  dependsOn:
  - lib/graph/topological_sort.hpp
  isVerificationFile: false
  path: lib/graph/reachable_query.hpp
  requiredBy: []
  timestamp: '2024-11-25 23:10:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/reachable_query.hpp
layout: document
redirect_from:
- /library/lib/graph/reachable_query.hpp
- /library/lib/graph/reachable_query.hpp.html
title: lib/graph/reachable_query.hpp
---
