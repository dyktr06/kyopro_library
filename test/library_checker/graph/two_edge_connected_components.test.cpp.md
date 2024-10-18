---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/lowlink.hpp
    title: lib/graph/lowlink.hpp
  - icon: ':heavy_check_mark:'
    path: lib/graph/two_edge_connected_components.hpp
    title: lib/graph/two_edge_connected_components.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/library_checker/graph/two_edge_connected_components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/two_edge_connected_components.hpp\"\
    \n\n#line 2 \"lib/graph/lowlink.hpp\"\n\nstruct LowLink{\n    struct Edge{\n \
    \       int from, to, id;\n    };\n    vector<vector<Edge>> G;\n    int V = 0,\
    \ E = 0;\n    vector<bool> used;\n    vector<int> ord, low;\n    vector<int> reachable;\n\
    \    vector<pair<int, int>> bridges; // \u6A4B\n    vector<int> articulations;\
    \ // \u95A2\u7BC0\u70B9\n    vector<bool> is_bridge, is_articulation;\n\n    LowLink(const\
    \ int node_size) : V(node_size){\n        G.resize(V);\n    }\n\n    void add_edge(int\
    \ from, int to){\n        G[from].push_back({from, to, E});\n        G[to].push_back({to,\
    \ from, E});\n        E++;\n    }\n\n    void build(){\n        used.assign(G.size(),\
    \ 0);\n        ord.assign(G.size(), 0);\n        low.assign(G.size(), 0);\n  \
    \      reachable.assign(G.size(), -1);\n        is_bridge.assign(E, false);\n\
    \        is_articulation.assign(V, false);\n\n        int k = 0;\n        for(int\
    \ i = 0; i < (int) G.size(); i++){\n            if(!used[i]) dfs(i, -1, k);\n\
    \        }\n    }\n\n    void dfs(int cur, int prv, int &k){\n        used[cur]\
    \ = true;\n        ord[cur] = k++;\n        low[cur] = ord[cur];\n        bool\
    \ flag_articulation = false;\n        int child_count = 0; // DFS \u6728\u306E\
    \u5B50\u306E\u6570\n\n        bool is_multiple = false;\n        for(auto &edge\
    \ : G[cur]){\n            if(edge.to == prv && !is_multiple){\n              \
    \  is_multiple = true;\n                continue;\n            }\n           \
    \ if(!used[edge.to]){\n                child_count++;\n                dfs(edge.to,\
    \ cur, k);\n                low[cur] = min(low[cur], low[edge.to]);\n        \
    \        if(prv != -1 && ord[cur] <= low[edge.to]){\n                    flag_articulation\
    \ = true;\n                }\n                if(ord[cur] < low[edge.to]){\n \
    \                   bridges.emplace_back(min(cur, edge.to), max(cur, edge.to));\n\
    \                    is_bridge[edge.id] = true;\n                }\n         \
    \   }else{ // \u5F8C\u9000\u8FBA\n                low[cur] = min(low[cur], ord[edge.to]);\n\
    \            }\n        }\n        if(prv == -1 && child_count >= 2) flag_articulation\
    \ = true;\n        if(flag_articulation){\n            articulations.push_back(cur);\n\
    \            is_articulation[cur] = true;\n        }\n    }\n};\n#line 4 \"lib/graph/two_edge_connected_components.hpp\"\
    \n\nstruct TwoEdgeConnectedComponents : LowLink{\n    using super = LowLink;\n\
    \n    vector<vector<int>> result;\n\n    TwoEdgeConnectedComponents(const int\
    \ node_size) : super(node_size){}\n\n    void build(){\n        super::build();\n\
    \        vector<bool> visited(V, false);\n        vector<int> v;\n        auto\
    \ dfs = [&](auto &self, int cur) -> void {\n            visited[cur] = true;\n\
    \            v.push_back(cur);\n            for(auto &edge : G[cur]){\n      \
    \          if(visited[edge.to]) continue;\n                if(!is_bridge[edge.id]){\n\
    \                    self(self, edge.to);\n                }\n            }\n\
    \        };\n        for(int i = 0; i < V; i++){\n            if(!visited[i]){\n\
    \                v.clear();\n                dfs(dfs, i);\n                result.push_back(v);\n\
    \            }\n        }\n    }\n\n    vector<vector<int>> get(){\n        return\
    \ result;\n    }\n};\n#line 6 \"test/library_checker/graph/two_edge_connected_components.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n, m; cin >> n >> m;\n    vector<vector<int>> G(n);\n    TwoEdgeConnectedComponents\
    \ tecc(n);\n    for(int i = 0; i < m; i++){\n        int a, b; cin >> a >> b;\n\
    \        tecc.add_edge(a, b);\n    }\n    tecc.build();\n    auto ans = tecc.get();\n\
    \    cout << ans.size() << '\\n';\n    for(auto &x : ans){\n        cout << x.size();\n\
    \        for(auto &y : x){\n            cout << ' ' << y;\n        }\n       \
    \ cout << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/two_edge_connected_components.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n, m; cin >> n >> m;\n    vector<vector<int>> G(n);\n    TwoEdgeConnectedComponents\
    \ tecc(n);\n    for(int i = 0; i < m; i++){\n        int a, b; cin >> a >> b;\n\
    \        tecc.add_edge(a, b);\n    }\n    tecc.build();\n    auto ans = tecc.get();\n\
    \    cout << ans.size() << '\\n';\n    for(auto &x : ans){\n        cout << x.size();\n\
    \        for(auto &y : x){\n            cout << ' ' << y;\n        }\n       \
    \ cout << '\\n';\n    }\n}\n"
  dependsOn:
  - lib/graph/two_edge_connected_components.hpp
  - lib/graph/lowlink.hpp
  isVerificationFile: true
  path: test/library_checker/graph/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2024-10-19 01:09:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/two_edge_connected_components.test.cpp
- /verify/test/library_checker/graph/two_edge_connected_components.test.cpp.html
title: test/library_checker/graph/two_edge_connected_components.test.cpp
---
