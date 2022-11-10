---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/shortest_path.test.cpp
    title: test/library_checker/graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/tree_diameter.test.cpp
    title: test/library_checker/tree/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/dijkstra.hpp\"\n\n// \u30C0\u30A4\u30AF\u30B9\u30C8\
    \u30E9\u6CD5 : O(ElogV)\ntemplate <typename T>\nvector<long long> dijkstra(const\
    \ vector<vector<array<long long, 2>>> &G, T x){\n    const long long INF = 0x1fffffffffffffff;\n\
    \    vector<long long> cost((int) G.size(), INF);\n    using P = pair<long long,\
    \ long long>;\n    priority_queue<P, vector<P>, greater<>> q;\n    cost[x] = 0;\n\
    \    q.emplace(0, x);\n    \n    while(q.size()){\n        auto [c, at] = q.top();\n\
    \        q.pop();\n        if(c > cost[at]) continue;\n        for(auto& [to,\
    \ t] : G[at]){\n            if(cost[to] > c + t){\n                cost[to] =\
    \ c + t;\n                q.emplace(cost[to], to);\n            }\n        }\n\
    \    }\n    return cost;\n}\n\n// s \u304B\u3089 t \u3078\u306E\u6700\u77ED\u30D1\
    \u30B9\u3092\u6C42\u3081\u307E\u3059 : O(ElogV)\npair<long long, vector<pair<int,\
    \ int>>> shortest_path(const vector<vector<array<long long, 2>>> &G, int s, int\
    \ t){\n    const long long INF = 0x1fffffffffffffff;\n    vector<long long> cost((int)\
    \ G.size(), INF);\n    vector<int> par((int) G.size(), -1);\n    using P = pair<long\
    \ long, long long>;\n    priority_queue<P, vector<P>, greater<>> q;\n    cost[s]\
    \ = 0;\n    par[s] = -1;\n    q.emplace(0, s);\n\n    while(q.size()){\n     \
    \   auto [c, at] = q.top();\n        q.pop();\n        if(c > cost[at]) continue;\n\
    \        for(auto& [to, t] : G[at]){\n            if(cost[to] > c + t){\n    \
    \            par[to] = at;\n                cost[to] = c + t;\n              \
    \  q.emplace(cost[to], to);\n            }\n        }\n    }\n\n    if(cost[t]\
    \ == INF){\n        return {-1, {}};\n    }\n    vector<pair<int, int>> path;\n\
    \    int now = t;\n    while(par[now] != -1){\n        path.push_back({par[now],\
    \ now});\n        now = par[now];\n    }\n    reverse(path.begin(), path.end());\n\
    \n    return {cost[t], path};\n}\n"
  code: "#pragma once\n\n// \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5 : O(ElogV)\n\
    template <typename T>\nvector<long long> dijkstra(const vector<vector<array<long\
    \ long, 2>>> &G, T x){\n    const long long INF = 0x1fffffffffffffff;\n    vector<long\
    \ long> cost((int) G.size(), INF);\n    using P = pair<long long, long long>;\n\
    \    priority_queue<P, vector<P>, greater<>> q;\n    cost[x] = 0;\n    q.emplace(0,\
    \ x);\n    \n    while(q.size()){\n        auto [c, at] = q.top();\n        q.pop();\n\
    \        if(c > cost[at]) continue;\n        for(auto& [to, t] : G[at]){\n   \
    \         if(cost[to] > c + t){\n                cost[to] = c + t;\n         \
    \       q.emplace(cost[to], to);\n            }\n        }\n    }\n    return\
    \ cost;\n}\n\n// s \u304B\u3089 t \u3078\u306E\u6700\u77ED\u30D1\u30B9\u3092\u6C42\
    \u3081\u307E\u3059 : O(ElogV)\npair<long long, vector<pair<int, int>>> shortest_path(const\
    \ vector<vector<array<long long, 2>>> &G, int s, int t){\n    const long long\
    \ INF = 0x1fffffffffffffff;\n    vector<long long> cost((int) G.size(), INF);\n\
    \    vector<int> par((int) G.size(), -1);\n    using P = pair<long long, long\
    \ long>;\n    priority_queue<P, vector<P>, greater<>> q;\n    cost[s] = 0;\n \
    \   par[s] = -1;\n    q.emplace(0, s);\n\n    while(q.size()){\n        auto [c,\
    \ at] = q.top();\n        q.pop();\n        if(c > cost[at]) continue;\n     \
    \   for(auto& [to, t] : G[at]){\n            if(cost[to] > c + t){\n         \
    \       par[to] = at;\n                cost[to] = c + t;\n                q.emplace(cost[to],\
    \ to);\n            }\n        }\n    }\n\n    if(cost[t] == INF){\n        return\
    \ {-1, {}};\n    }\n    vector<pair<int, int>> path;\n    int now = t;\n    while(par[now]\
    \ != -1){\n        path.push_back({par[now], now});\n        now = par[now];\n\
    \    }\n    reverse(path.begin(), path.end());\n\n    return {cost[t], path};\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-11-11 02:13:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/tree/tree_diameter.test.cpp
  - test/library_checker/graph/shortest_path.test.cpp
documentation_of: lib/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/lib/graph/dijkstra.hpp
- /library/lib/graph/dijkstra.hpp.html
title: lib/graph/dijkstra.hpp
---
