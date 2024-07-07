---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/tree_diameter.hpp
    title: "Tree Diameter (\u6728\u306E\u76F4\u5F84)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "#line 1 \"test/aoj/grl/grl_5_a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/tree_diameter.hpp\"\
    \n\n/**\n * @brief Tree Diameter (\u6728\u306E\u76F4\u5F84)\n * @docs docs/graph/tree_diameter.md\n\
    \ */\n\ntemplate <typename T>\nstruct TreeDiameter{\n    using Graph = vector<vector<pair<int,\
    \ T>>>;\n    Graph G;\n    vector<T> dist, dist2;\n    int V, root;\n    T diam\
    \ = -1;\n    pair<int, int> ep;\n\n    TreeDiameter(int n) : V(n){\n        G.resize(n);\n\
    \    }\n\n    void add_edge(int u, int v, T w = 1){\n        G[u].emplace_back(v,\
    \ w);\n        G[v].emplace_back(u, w);\n    }\n\n    void build(int _root = 0){\n\
    \        root = _root;\n        dist.assign(V, -1); dist2.assign(V, -1);\n   \
    \     dfs(G, root, -1, 0);\n        T mx = 0;\n        for(int i = 0; i < V; i++){\n\
    \            if(mx < dist[i]){\n                mx = dist[i];\n              \
    \  ep.first = i;\n            }\n        }\n\n        dfs2(G, ep.first, -1, 0);\n\
    \        for(int i = 0; i < V; i++){\n            if(diam < dist2[i]){\n     \
    \           diam = dist2[i];\n                ep.second = i;\n            }\n\
    \        }\n    }\n\n    void dfs(const Graph &G, int v, int p, T d){\n      \
    \  dist[v] = d;\n        for(auto [e, w] : G[v]){\n            if(e != p) dfs(G,\
    \ e, v, d + w);\n        }\n    }\n\n    void dfs2(const Graph &G, int v, int\
    \ p, T d){\n        dist2[v] = d;\n        for(auto [e, w] : G[v]){\n        \
    \    if(e != p) dfs2(G, e, v, d + w);\n        }\n    }\n\n    T diameter(){\n\
    \        return diam;\n    }\n\n    pair<int, int> endpoint(){\n        return\
    \ ep;\n    }\n};\n#line 6 \"test/aoj/grl/grl_5_a.test.cpp\"\n\nint main(){\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n; cin >> n;\n\
    \    TreeDiameter<int> td(n);\n    for(int i = 0; i < n - 1; i++){\n        int\
    \ u, v, w; cin >> u >> v >> w;\n        td.add_edge(u, v, w);\n    }\n    td.build();\n\
    \    cout << td.diameter() << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/tree_diameter.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n; cin >> n;\n    TreeDiameter<int> td(n);\n    for(int i = 0; i < n -\
    \ 1; i++){\n        int u, v, w; cin >> u >> v >> w;\n        td.add_edge(u, v,\
    \ w);\n    }\n    td.build();\n    cout << td.diameter() << \"\\n\";\n}\n"
  dependsOn:
  - lib/graph/tree_diameter.hpp
  isVerificationFile: true
  path: test/aoj/grl/grl_5_a.test.cpp
  requiredBy: []
  timestamp: '2024-07-07 17:27:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl/grl_5_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/grl_5_a.test.cpp
- /verify/test/aoj/grl/grl_5_a.test.cpp.html
title: test/aoj/grl/grl_5_a.test.cpp
---
