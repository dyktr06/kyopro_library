---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/graph/dijkstra.hpp
    title: "Dijkstra's Algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/library_checker/tree/tree_diameter.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/graph/dijkstra.hpp\"\n\n/**\n * @brief Dijkstra's\
    \ Algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\n * @docs docs/graph/dijkstra.md\n\
    \ */\n\ntemplate <typename T>\nvector<long long> dijkstra(const vector<vector<array<long\
    \ long, 2>>> &G, T x){\n    const long long INF = 0x1fffffffffffffff;\n    vector<long\
    \ long> cost((int) G.size(), INF);\n    using P = pair<long long, long long>;\n\
    \    priority_queue<P, vector<P>, greater<>> q;\n    cost[x] = 0;\n    q.emplace(0,\
    \ x);\n\n    while(q.size()){\n        auto [c, at] = q.top();\n        q.pop();\n\
    \        if(c > cost[at]) continue;\n        for(auto &[to, t] : G[at]){\n   \
    \         if(cost[to] > c + t){\n                cost[to] = c + t;\n         \
    \       q.emplace(cost[to], to);\n            }\n        }\n    }\n    return\
    \ cost;\n}\n\npair<long long, vector<pair<int, int>>> shortest_path(const vector<vector<array<long\
    \ long, 2>>> &G, int s, int t){\n    const long long INF = 0x1fffffffffffffff;\n\
    \    vector<long long> cost((int) G.size(), INF);\n    vector<int> par((int) G.size(),\
    \ -1);\n    using P = pair<long long, long long>;\n    priority_queue<P, vector<P>,\
    \ greater<>> q;\n    cost[s] = 0;\n    par[s] = -1;\n    q.emplace(0, s);\n\n\
    \    while(q.size()){\n        auto [c, at] = q.top();\n        q.pop();\n   \
    \     if(c > cost[at]) continue;\n        for(auto &[to, t] : G[at]){\n      \
    \      if(cost[to] > c + t){\n                par[to] = at;\n                cost[to]\
    \ = c + t;\n                q.emplace(cost[to], to);\n            }\n        }\n\
    \    }\n\n    if(cost[t] == INF){\n        return {-1, {}};\n    }\n    vector<pair<int,\
    \ int>> path;\n    for(int now = t; par[now] != -1; now = par[now]){\n       \
    \ path.emplace_back(par[now], now);\n    }\n    reverse(path.begin(), path.end());\n\
    \n    return {cost[t], path};\n}\n#line 6 \"test/library_checker/tree/tree_diameter.test.cpp\"\
    \n\nvector<vector<array<long long, 2>>> G;\n\nint n, m;\n\nint main(){\n    cin\
    \ >> n;\n    G.resize(n);\n    for(int i = 0; i < n - 1; i++){\n        int a,\
    \ b, c; cin >> a >> b >> c;\n        G[a].push_back({b, c});\n        G[b].push_back({a,\
    \ c});\n    }\n    vector<long long> cost = dijkstra(G, 0);\n    int s, t;\n \
    \   long long mx1 = -1, mx2 = -1;\n    for(int i = 0; i < n; i++){\n        if(cost[i]\
    \ >= mx1){\n            mx1 = cost[i];\n            s = i;\n        }\n    }\n\
    \    vector<long long> cost2 = dijkstra(G, s);\n    for(int i = 0; i < n; i++){\n\
    \        if(cost2[i] >= mx2){\n            mx2 = cost2[i];\n            t = i;\n\
    \        }\n    }\n    pair<long long, vector<pair<int, int>>> p = shortest_path(G,\
    \ s, t);\n    vector<int> e;\n    for(auto [u, v] : p.second){\n        if(!e.size()\
    \ || e.back() != u){\n            e.push_back(u);\n        }\n        e.push_back(v);\n\
    \    }\n    cout << p.first << \" \" << (int) e.size() << \"\\n\";\n    for(auto\
    \ x : e){\n        cout << x << \" \";\n    }\n    cout << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/dijkstra.hpp\"\
    \n\nvector<vector<array<long long, 2>>> G;\n\nint n, m;\n\nint main(){\n    cin\
    \ >> n;\n    G.resize(n);\n    for(int i = 0; i < n - 1; i++){\n        int a,\
    \ b, c; cin >> a >> b >> c;\n        G[a].push_back({b, c});\n        G[b].push_back({a,\
    \ c});\n    }\n    vector<long long> cost = dijkstra(G, 0);\n    int s, t;\n \
    \   long long mx1 = -1, mx2 = -1;\n    for(int i = 0; i < n; i++){\n        if(cost[i]\
    \ >= mx1){\n            mx1 = cost[i];\n            s = i;\n        }\n    }\n\
    \    vector<long long> cost2 = dijkstra(G, s);\n    for(int i = 0; i < n; i++){\n\
    \        if(cost2[i] >= mx2){\n            mx2 = cost2[i];\n            t = i;\n\
    \        }\n    }\n    pair<long long, vector<pair<int, int>>> p = shortest_path(G,\
    \ s, t);\n    vector<int> e;\n    for(auto [u, v] : p.second){\n        if(!e.size()\
    \ || e.back() != u){\n            e.push_back(u);\n        }\n        e.push_back(v);\n\
    \    }\n    cout << p.first << \" \" << (int) e.size() << \"\\n\";\n    for(auto\
    \ x : e){\n        cout << x << \" \";\n    }\n    cout << \"\\n\";\n}"
  dependsOn:
  - lib/graph/dijkstra.hpp
  isVerificationFile: true
  path: test/library_checker/tree/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2024-10-21 21:40:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/tree/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/tree/tree_diameter.test.cpp
- /verify/test/library_checker/tree/tree_diameter.test.cpp.html
title: test/library_checker/tree/tree_diameter.test.cpp
---
