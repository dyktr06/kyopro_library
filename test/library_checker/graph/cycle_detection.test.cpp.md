---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/graph/dijkstra.hpp
    title: "Dijkstra's Algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: lib/graph/scc.hpp
    title: "Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"test/library_checker/graph/cycle_detection.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/dijkstra.hpp\"\n\
    \n/**\n * @brief Dijkstra's Algorithm (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\
    )\n * @docs docs/graph/dijkstra.md\n */\n\ntemplate <typename T>\nvector<long\
    \ long> dijkstra(const vector<vector<array<long long, 2>>> &G, T x){\n    const\
    \ long long INF = 0x1fffffffffffffff;\n    vector<long long> cost((int) G.size(),\
    \ INF);\n    using P = pair<long long, long long>;\n    priority_queue<P, vector<P>,\
    \ greater<>> q;\n    cost[x] = 0;\n    q.emplace(0, x);\n\n    while(q.size()){\n\
    \        auto [c, at] = q.top();\n        q.pop();\n        if(c > cost[at]) continue;\n\
    \        for(auto &[to, t] : G[at]){\n            if(cost[to] > c + t){\n    \
    \            cost[to] = c + t;\n                q.emplace(cost[to], to);\n   \
    \         }\n        }\n    }\n    return cost;\n}\n\npair<long long, vector<pair<int,\
    \ int>>> shortest_path(const vector<vector<array<long long, 2>>> &G, int s, int\
    \ t){\n    const long long INF = 0x1fffffffffffffff;\n    vector<long long> cost((int)\
    \ G.size(), INF);\n    vector<int> par((int) G.size(), -1);\n    using P = pair<long\
    \ long, long long>;\n    priority_queue<P, vector<P>, greater<>> q;\n    cost[s]\
    \ = 0;\n    par[s] = -1;\n    q.emplace(0, s);\n\n    while(q.size()){\n     \
    \   auto [c, at] = q.top();\n        q.pop();\n        if(c > cost[at]) continue;\n\
    \        for(auto &[to, t] : G[at]){\n            if(cost[to] > c + t){\n    \
    \            par[to] = at;\n                cost[to] = c + t;\n              \
    \  q.emplace(cost[to], to);\n            }\n        }\n    }\n\n    if(cost[t]\
    \ == INF){\n        return {-1, {}};\n    }\n    vector<pair<int, int>> path;\n\
    \    int now = t;\n    while(par[now] != -1){\n        path.emplace_back(par[now],\
    \ now);\n        now = par[now];\n    }\n    reverse(path.begin(), path.end());\n\
    \n    return {cost[t], path};\n}\n#line 2 \"lib/graph/scc.hpp\"\n\n/**\n * @brief\
    \ Strongly Connected Component (\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)\n\
    \ * @docs docs/graph/scc.md\n */\n\ntemplate <typename T>\nstruct SCC{\n    int\
    \ siz;\n    vector<vector<T>> G_reverse;\n    vector<bool> check;\n    vector<int>\
    \ memo;\n    vector<T> s;\n    vector<vector<T>> result;\n\n    SCC(const vector<vector<T>>\
    \ &G) : G_reverse((int) G.size()), check((int) G.size()){\n        siz = (int)\
    \ G.size();\n        for(int i = 0; i < siz; ++i){\n            for(const auto\
    \ &x : G[i]){\n                G_reverse[x].emplace_back(i);\n            }\n\
    \        }\n\n        for(int i = 0; i < siz; ++i){\n            if(!check[i]){\n\
    \                dfs(G, i);\n            }\n        }\n        reverse(memo.begin(),\
    \ memo.end());\n\n        for(int i = 0; i < siz; ++i) check[i] = false;\n   \
    \     for(const auto &x : memo){\n            if(!check[x]){\n               \
    \ s = {};\n                dfs2(G_reverse, x);\n                result.emplace_back(s);\n\
    \            }\n        }\n    }\n\n    void dfs(const vector<vector<T>> &G, int\
    \ curr){\n        check[curr] = true;\n        for(const auto &x : G[curr]){\n\
    \            if(check[x]){\n                continue;\n            }\n       \
    \     dfs(G, x);\n        }\n        memo.emplace_back(curr);\n    }\n\n    void\
    \ dfs2(const vector<vector<T>> &G, int curr){\n        s.emplace_back(curr);\n\
    \        check[curr] = true;\n        for(const auto &x : G[curr]){\n        \
    \    if(check[x]){\n                continue;\n            }\n            dfs2(G,\
    \ x);\n        }\n    }\n\n    vector<vector<T>> get() const {\n        return\
    \ result;\n    }\n};\n#line 7 \"test/library_checker/graph/cycle_detection.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n   \
    \ \n    int n, m; cin >> n >> m;\n    vector<int> u(m), v(m);\n    map<pair<int,\
    \ int>, int> e;\n    for(int i = 0; i < m; i++){\n        cin >> u[i] >> v[i];\n\
    \        e[{u[i], v[i]}] = i;\n    }\n    vector<vector<int>> G(n);\n    vector<vector<array<long\
    \ long, 2>>> G2(n);\n    for(int i = 0; i < m; i++){\n        G[u[i]].push_back(v[i]);\n\
    \        G2[u[i]].push_back({v[i], 1});\n    }\n\n    SCC<int> scc(G);\n    vector<int>\
    \ ans;\n    for(auto &s : scc.get()){\n        int sizs = s.size();\n        if(sizs\
    \ == 1) continue;\n        auto [w1, e1] = shortest_path(G2, s[0], s[1]);\n  \
    \      auto [w2, e2] = shortest_path(G2, s[1], s[0]);\n        for(auto [a, b]\
    \ : e1){\n            ans.push_back(e[{a, b}]);\n        }\n        for(auto [a,\
    \ b] : e2){\n            ans.push_back(e[{a, b}]);\n        }\n        break;\n\
    \    }\n    \n    int siz = ans.size();\n    if(siz == 0){\n        cout << -1\
    \ << \"\\n\";\n        return 0;\n    }\n    cout << siz << \"\\n\";\n    for(int\
    \ i = 0; i < siz; i++){\n        cout << ans[i] << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/dijkstra.hpp\"\
    \n#include \"../../../lib/graph/scc.hpp\"\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    \n    int n, m; cin >> n >> m;\n    vector<int> u(m),\
    \ v(m);\n    map<pair<int, int>, int> e;\n    for(int i = 0; i < m; i++){\n  \
    \      cin >> u[i] >> v[i];\n        e[{u[i], v[i]}] = i;\n    }\n    vector<vector<int>>\
    \ G(n);\n    vector<vector<array<long long, 2>>> G2(n);\n    for(int i = 0; i\
    \ < m; i++){\n        G[u[i]].push_back(v[i]);\n        G2[u[i]].push_back({v[i],\
    \ 1});\n    }\n\n    SCC<int> scc(G);\n    vector<int> ans;\n    for(auto &s :\
    \ scc.get()){\n        int sizs = s.size();\n        if(sizs == 1) continue;\n\
    \        auto [w1, e1] = shortest_path(G2, s[0], s[1]);\n        auto [w2, e2]\
    \ = shortest_path(G2, s[1], s[0]);\n        for(auto [a, b] : e1){\n         \
    \   ans.push_back(e[{a, b}]);\n        }\n        for(auto [a, b] : e2){\n   \
    \         ans.push_back(e[{a, b}]);\n        }\n        break;\n    }\n    \n\
    \    int siz = ans.size();\n    if(siz == 0){\n        cout << -1 << \"\\n\";\n\
    \        return 0;\n    }\n    cout << siz << \"\\n\";\n    for(int i = 0; i <\
    \ siz; i++){\n        cout << ans[i] << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/graph/dijkstra.hpp
  - lib/graph/scc.hpp
  isVerificationFile: true
  path: test/library_checker/graph/cycle_detection.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/cycle_detection.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/cycle_detection.test.cpp
- /verify/test/library_checker/graph/cycle_detection.test.cpp.html
title: test/library_checker/graph/cycle_detection.test.cpp
---
