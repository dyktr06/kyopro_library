---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: Union-Find
  - icon: ':heavy_check_mark:'
    path: lib/graph/dijkstra.hpp
    title: "Dijkstra's Algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection_undirected
    links:
    - https://judge.yosupo.jp/problem/cycle_detection_undirected
  bundledCode: "#line 1 \"test/library_checker/graph/cycle_detection_undirected.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/union_find.hpp\"\
    \n\n/**\n * @brief Union-Find\n * @docs docs/data_structure/union_find.md\n */\n\
    \n#line 10 \"lib/data_structure/union_find.hpp\"\n\nstruct UnionFind{\n    int\
    \ V;\n    std::vector<int> par;\n    std::vector<int> edg;\n\n    UnionFind(const\
    \ int N) : V(N), par(N), edg(N){\n        for(int i = 0; i < N; ++i){\n      \
    \      par[i] = -1;\n            edg[i] = 0;\n        }\n    }\n\n    int root(int\
    \ x){\n        assert(0 <= x && x < V);\n        if(par[x] < 0) return x;\n  \
    \      return par[x] = root(par[x]);\n    }\n\n    int unite(int x, int y){\n\
    \        int rx = root(x);\n        int ry = root(y);\n        if(rx == ry){\n\
    \            edg[rx]++;\n            return rx;\n        }\n        if(-par[rx]\
    \ < -par[ry]) std::swap(rx, ry);\n        par[rx] = par[rx] + par[ry];\n     \
    \   par[ry] = rx;\n        edg[rx] += edg[ry] + 1;\n        return rx;\n    }\n\
    \n    bool same(int x, int y){\n        int rx = root(x);\n        int ry = root(y);\n\
    \        return rx == ry;\n    }\n\n    long long size(int x){\n        return\
    \ -par[root(x)];\n    }\n\n    long long edge(int x){\n        return edg[root(x)];\n\
    \    }\n};\n#line 2 \"lib/graph/dijkstra.hpp\"\n\n/**\n * @brief Dijkstra's Algorithm\
    \ (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)\n * @docs docs/graph/dijkstra.md\n\
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
    \n    return {cost[t], path};\n}\n#line 7 \"test/library_checker/graph/cycle_detection_undirected.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n   \
    \ \n    int n, m; cin >> n >> m;\n    vector<int> u(m), v(m);\n    map<pair<int,\
    \ int>, int> e;\n    for(int i = 0; i < m; i++){\n        cin >> u[i] >> v[i];\n\
    \        e[{u[i], v[i]}] = i;\n        e[{v[i], u[i]}] = i;\n    }\n    vector<vector<array<long\
    \ long, 2>>> G(n);\n    UnionFind uf(n);\n    vector<int> ansv, anse;\n    for(int\
    \ i = 0; i < m; i++){\n        if(uf.same(u[i], v[i])){\n            auto [w,\
    \ path] = shortest_path(G, u[i], v[i]);\n            ansv.push_back(u[i]);\n \
    \           for(auto [x, y] : path){\n                ansv.push_back(y);\n   \
    \             anse.push_back(e[{x, y}]);\n            }\n            anse.push_back(i);\n\
    \            break;\n        }\n        uf.unite(u[i], v[i]);\n        G[u[i]].push_back({v[i],\
    \ 1});\n        G[v[i]].push_back({u[i], 1});\n    }\n    \n    int siz = ansv.size();\n\
    \    if(siz == 0){\n        cout << -1 << \"\\n\";\n        return 0;\n    }\n\
    \    cout << siz << \"\\n\";\n    for(int i = 0; i < siz; i++){\n        cout\
    \ << ansv[i] << \" \\n\"[i == siz - 1];\n    }\n    for(int i = 0; i < siz; i++){\n\
    \        cout << anse[i] << \" \\n\"[i == siz - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/union_find.hpp\"\
    \n#include \"../../../lib/graph/dijkstra.hpp\"\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    \n    int n, m; cin >> n >> m;\n    vector<int> u(m),\
    \ v(m);\n    map<pair<int, int>, int> e;\n    for(int i = 0; i < m; i++){\n  \
    \      cin >> u[i] >> v[i];\n        e[{u[i], v[i]}] = i;\n        e[{v[i], u[i]}]\
    \ = i;\n    }\n    vector<vector<array<long long, 2>>> G(n);\n    UnionFind uf(n);\n\
    \    vector<int> ansv, anse;\n    for(int i = 0; i < m; i++){\n        if(uf.same(u[i],\
    \ v[i])){\n            auto [w, path] = shortest_path(G, u[i], v[i]);\n      \
    \      ansv.push_back(u[i]);\n            for(auto [x, y] : path){\n         \
    \       ansv.push_back(y);\n                anse.push_back(e[{x, y}]);\n     \
    \       }\n            anse.push_back(i);\n            break;\n        }\n   \
    \     uf.unite(u[i], v[i]);\n        G[u[i]].push_back({v[i], 1});\n        G[v[i]].push_back({u[i],\
    \ 1});\n    }\n    \n    int siz = ansv.size();\n    if(siz == 0){\n        cout\
    \ << -1 << \"\\n\";\n        return 0;\n    }\n    cout << siz << \"\\n\";\n \
    \   for(int i = 0; i < siz; i++){\n        cout << ansv[i] << \" \\n\"[i == siz\
    \ - 1];\n    }\n    for(int i = 0; i < siz; i++){\n        cout << anse[i] <<\
    \ \" \\n\"[i == siz - 1];\n    }\n}"
  dependsOn:
  - lib/data_structure/union_find.hpp
  - lib/graph/dijkstra.hpp
  isVerificationFile: true
  path: test/library_checker/graph/cycle_detection_undirected.test.cpp
  requiredBy: []
  timestamp: '2024-11-18 03:54:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/cycle_detection_undirected.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/cycle_detection_undirected.test.cpp
- /verify/test/library_checker/graph/cycle_detection_undirected.test.cpp.html
title: test/library_checker/graph/cycle_detection_undirected.test.cpp
---
