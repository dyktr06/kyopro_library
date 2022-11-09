---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/graph/dijkstra.cpp\"\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\nint n, m;\nvector<vector<array<long long, 2>>> G;\n\n// \u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5 : O(ElogV)\ntemplate <typename T>\nvector<long\
    \ long> dijkstra(T x){\n    const long long INF = 0x1fffffffffffffff;\n    vector<long\
    \ long> cost((int) G.size(), INF);\n    using P = pair<long long, long long>;\n\
    \    priority_queue<P, vector<P>, greater<>> q;\n    cost[x] = 0;\n    q.emplace(0,\
    \ x);\n    \n    while(q.size()){\n        auto [c, at] = q.top();\n        q.pop();\n\
    \        if(c > cost[at]) continue;\n        for(auto& [to, t] : G[at]){\n   \
    \         if(cost[to] > c + t){\n                cost[to] = c + t;\n         \
    \       q.emplace(cost[to], to);\n            }\n        }\n    }\n    return\
    \ cost;\n}\n\n// s \u304B\u3089 t \u3078\u306E\u6700\u77ED\u30D1\u30B9\u3092\u6C42\
    \u3081\u307E\u3059 : O(ElogV)\npair<long long, vector<pair<int, int>>> shortestPath(int\
    \ s, int t){\n    const long long INF = 0x1fffffffffffffff;\n    vector<long long>\
    \ cost((int) G.size(), INF);\n    vector<int> par((int) G.size(), -1);\n    using\
    \ P = pair<long long, long long>;\n    priority_queue<P, vector<P>, greater<>>\
    \ q;\n    cost[s] = 0;\n    par[s] = -1;\n    q.emplace(0, s);\n\n    while(q.size()){\n\
    \        auto [c, at] = q.top();\n        q.pop();\n        if(c > cost[at]) continue;\n\
    \        for(auto& [to, t] : G[at]){\n            if(cost[to] > c + t){\n    \
    \            par[to] = at;\n                cost[to] = c + t;\n              \
    \  q.emplace(cost[to], to);\n            }\n        }\n    }\n\n    if(cost[t]\
    \ == INF){\n        return {-1, {}};\n    }\n    vector<pair<int, int>> path;\n\
    \    int now = t;\n    while(par[now] != -1){\n        path.push_back({par[now],\
    \ now});\n        now = par[now];\n    }\n    reverse(path.begin(), path.end());\n\
    \n    return {cost[t], path};\n}\n\n// example\nint main(){\n    cin >> n >> m;\n\
    \    G = vector<vector<array<long long, 2>>>(n);\n\n    for(int i = 0; i < m;\
    \ i++){\n        int a, b, c;\n        cin >> a >> b >> c;\n        a--, b--;\n\
    \        G[a].push_back({b, c});\n        G[b].push_back({a, c});\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nint n, m;\nvector<vector<array<long\
    \ long, 2>>> G;\n\n// \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5 : O(ElogV)\n\
    template <typename T>\nvector<long long> dijkstra(T x){\n    const long long INF\
    \ = 0x1fffffffffffffff;\n    vector<long long> cost((int) G.size(), INF);\n  \
    \  using P = pair<long long, long long>;\n    priority_queue<P, vector<P>, greater<>>\
    \ q;\n    cost[x] = 0;\n    q.emplace(0, x);\n    \n    while(q.size()){\n   \
    \     auto [c, at] = q.top();\n        q.pop();\n        if(c > cost[at]) continue;\n\
    \        for(auto& [to, t] : G[at]){\n            if(cost[to] > c + t){\n    \
    \            cost[to] = c + t;\n                q.emplace(cost[to], to);\n   \
    \         }\n        }\n    }\n    return cost;\n}\n\n// s \u304B\u3089 t \u3078\
    \u306E\u6700\u77ED\u30D1\u30B9\u3092\u6C42\u3081\u307E\u3059 : O(ElogV)\npair<long\
    \ long, vector<pair<int, int>>> shortestPath(int s, int t){\n    const long long\
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
    }\n\n// example\nint main(){\n    cin >> n >> m;\n    G = vector<vector<array<long\
    \ long, 2>>>(n);\n\n    for(int i = 0; i < m; i++){\n        int a, b, c;\n  \
    \      cin >> a >> b >> c;\n        a--, b--;\n        G[a].push_back({b, c});\n\
    \        G[b].push_back({a, c});\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2022-11-08 22:18:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/dijkstra.cpp
layout: document
redirect_from:
- /library/lib/graph/dijkstra.cpp
- /library/lib/graph/dijkstra.cpp.html
title: lib/graph/dijkstra.cpp
---
