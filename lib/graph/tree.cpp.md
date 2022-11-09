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
  bundledCode: "#line 1 \"lib/graph/tree.cpp\"\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\n/*  \n    TreeLibrary(G, root): \u6728 G \u306B\u5BFE\u3059\
    \u308B\u6839\u3092 root \u69D8\u3005\u306A\u3082\u306E\u3092\u6C42\u3081\u308B\
    \u69CB\u9020\u4F53\n    lca(u, v): u \u3068 v \u306E LCA \u3092\u6C42\u3081\u307E\
    \u3059\u3002\u8A08\u7B97\u91CF O(logn)\n    la(u, v): u \u3068 v \u306E LA \u3092\
    \u6C42\u3081\u307E\u3059\u3002\u8A08\u7B97\u91CF O(logn)\n    diameter(): \u76F4\
    \u5F84\u306E\u9577\u3055\u3092\u6C42\u3081\u307E\u3059\u3002\n    endpoint():\
    \ \u76F4\u5F84\u306E\u7AEF\u306E\u9802\u70B9\u3092\u6C42\u3081\u307E\u3059\u3002\
    \n    getDist(u, v): u \u3068 v \u306E\u8DDD\u96E2\u3092\u6C42\u3081\u307E\u3059\
    \u3002\u8A08\u7B97\u91CF O(logn)\n    isOnPath(u, v, a): a \u304C u \u3068 v \u306E\
    \u30D1\u30B9\u4E0A\u306B\u3042\u308B\u304B\u3069\u3046\u304B\u3092\u6C42\u3081\
    \u307E\u3059\u3002\u8A08\u7B97\u91CF O(logn)\n    \u524D\u51E6\u7406 : O(nlogn),\
    \ O(nlogn)\u7A7A\u9593\n*/\n\ntemplate <typename T>\nstruct TreeLibrary{\n   \
    \ using Graph = vector<vector<T>>;\n    vector<vector<int>> parent;  // parent[k][u]:=\
    \ u \u306E 2^k \u5148\u306E\u89AA\n    vector<int> dist, dist2;\n    int V, root,\
    \ diam = -1;\n    pair<int, int> ep;\n    TreeLibrary(const Graph &G, int root_\
    \ = 0): root(root_){ init(G); }\n\n    void init(const Graph &G){\n        V =\
    \ G.size();\n        int K = 1;\n        while ((1 << K) < V) K++;\n        parent.assign(K,\
    \ vector<int>(V, -1));\n        dist.assign(V, -1); dist2.assign(V, -1);\n   \
    \     dfs(G, root, -1, 0);\n        for(int k = 0; k + 1 < K; k++){\n        \
    \    for(int v = 0; v < V; v++){\n                if(parent[k][v] < 0){\n    \
    \                parent[k + 1][v] = -1;\n                }else{\n            \
    \        parent[k + 1][v] = parent[k][parent[k][v]];\n                }\n    \
    \        }\n        }\n\n        int mx = 0;\n        for(int i = 0; i < V; i++){\n\
    \            if(mx < dist[i]){\n                mx = dist[i];\n              \
    \  ep.first = i;\n            }\n        }\n \n        dfs2(G, ep.first, -1, 0);\n\
    \        for(int i = 0; i < V; i++){\n            if(diam < dist2[i]){\n     \
    \           diam = dist2[i];\n                ep.second = i;\n            }\n\
    \        }\n    }\n    \n    // \u6839\u304B\u3089\u306E\u8DDD\u96E2\u30681\u3064\
    \u5148\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B\n    void dfs(const Graph &G,\
    \ int v, int p, int d){\n        parent[0][v] = p;\n        dist[v] = d;\n   \
    \     for (auto e : G[v]){\n            if(e != p) dfs(G, e, v, d + 1);\n    \
    \    }\n    }\n    \n    void dfs2(const Graph &G, int v, int p, int d){\n   \
    \     dist2[v] = d;\n        for(auto e : G[v]){\n            if(e != p) dfs2(G,\
    \ e, v, d + 1);\n        }\n    }\n\n    int lca(int u, int v){\n        if (dist[u]\
    \ < dist[v]) swap(u, v);  // u \u306E\u65B9\u304C\u6DF1\u3044\u3068\u3059\u308B\
    \n        int K = parent.size();\n        // LCA \u307E\u3067\u306E\u8DDD\u96E2\
    \u3092\u540C\u3058\u306B\u3059\u308B\n        for (int k = 0; k < K; k++) {\n\
    \            if ((dist[u] - dist[v]) >> k & 1) {\n                u = parent[k][u];\n\
    \            }\n        }\n        // \u4E8C\u5206\u63A2\u7D22\u3067 LCA \u3092\
    \u6C42\u3081\u308B\n        if(u == v) return u;\n        for(int k = K - 1; k\
    \ >= 0; k--){\n            if(parent[k][u] != parent[k][v]){\n               \
    \ u = parent[k][u];\n                v = parent[k][v];\n            }\n      \
    \  }\n        return parent[0][u];\n    }\n\n    int la(int u, int d){\n     \
    \   if(getDist(u, root) < d){\n            return -1;\n        }\n        // \u4E8C\
    \u5206\u63A2\u7D22\u3067 LA \u3092\u6C42\u3081\u308B\n        int K = parent.size();\n\
    \        for(int k = K - 1; k >= 0; k--){\n            if(d & (1 << k)){\n   \
    \             u = parent[k][u];\n            }\n        }\n        return u;\n\
    \    }\n\n    int diameter(){\n        return diam;\n    }\n \n    pair<int, int>\
    \ endpoint(){\n        return ep;\n    }\n\n    int getDist(int u, int v){\n \
    \       return dist[u] + dist[v] - 2 * dist[lca(u, v)];\n    }\n\n    bool isOnPath(int\
    \ u, int v, int a){\n        return getDist(u, a) + getDist(a, v) == getDist(u,\
    \ v);\n    }\n};\n\n// example (\u5178\u578B90 003)\nint main(){\n    int n; cin\
    \ >> n;\n    vector<vector<int>> G(n);\n    for(int i = 0; i < n - 1; i++){\n\
    \        int a, b; cin >> a >> b; a--; b--;\n        G[a].push_back(b);\n    \
    \    G[b].push_back(a);\n    }\n    TreeLibrary t(G);\n    cout << t.diam + 1\
    \ << \"\\n\";\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n/*  \n    TreeLibrary(G,\
    \ root): \u6728 G \u306B\u5BFE\u3059\u308B\u6839\u3092 root \u69D8\u3005\u306A\
    \u3082\u306E\u3092\u6C42\u3081\u308B\u69CB\u9020\u4F53\n    lca(u, v): u \u3068\
    \ v \u306E LCA \u3092\u6C42\u3081\u307E\u3059\u3002\u8A08\u7B97\u91CF O(logn)\n\
    \    la(u, v): u \u3068 v \u306E LA \u3092\u6C42\u3081\u307E\u3059\u3002\u8A08\
    \u7B97\u91CF O(logn)\n    diameter(): \u76F4\u5F84\u306E\u9577\u3055\u3092\u6C42\
    \u3081\u307E\u3059\u3002\n    endpoint(): \u76F4\u5F84\u306E\u7AEF\u306E\u9802\
    \u70B9\u3092\u6C42\u3081\u307E\u3059\u3002\n    getDist(u, v): u \u3068 v \u306E\
    \u8DDD\u96E2\u3092\u6C42\u3081\u307E\u3059\u3002\u8A08\u7B97\u91CF O(logn)\n \
    \   isOnPath(u, v, a): a \u304C u \u3068 v \u306E\u30D1\u30B9\u4E0A\u306B\u3042\
    \u308B\u304B\u3069\u3046\u304B\u3092\u6C42\u3081\u307E\u3059\u3002\u8A08\u7B97\
    \u91CF O(logn)\n    \u524D\u51E6\u7406 : O(nlogn), O(nlogn)\u7A7A\u9593\n*/\n\n\
    template <typename T>\nstruct TreeLibrary{\n    using Graph = vector<vector<T>>;\n\
    \    vector<vector<int>> parent;  // parent[k][u]:= u \u306E 2^k \u5148\u306E\u89AA\
    \n    vector<int> dist, dist2;\n    int V, root, diam = -1;\n    pair<int, int>\
    \ ep;\n    TreeLibrary(const Graph &G, int root_ = 0): root(root_){ init(G); }\n\
    \n    void init(const Graph &G){\n        V = G.size();\n        int K = 1;\n\
    \        while ((1 << K) < V) K++;\n        parent.assign(K, vector<int>(V, -1));\n\
    \        dist.assign(V, -1); dist2.assign(V, -1);\n        dfs(G, root, -1, 0);\n\
    \        for(int k = 0; k + 1 < K; k++){\n            for(int v = 0; v < V; v++){\n\
    \                if(parent[k][v] < 0){\n                    parent[k + 1][v] =\
    \ -1;\n                }else{\n                    parent[k + 1][v] = parent[k][parent[k][v]];\n\
    \                }\n            }\n        }\n\n        int mx = 0;\n        for(int\
    \ i = 0; i < V; i++){\n            if(mx < dist[i]){\n                mx = dist[i];\n\
    \                ep.first = i;\n            }\n        }\n \n        dfs2(G, ep.first,\
    \ -1, 0);\n        for(int i = 0; i < V; i++){\n            if(diam < dist2[i]){\n\
    \                diam = dist2[i];\n                ep.second = i;\n          \
    \  }\n        }\n    }\n    \n    // \u6839\u304B\u3089\u306E\u8DDD\u96E2\u3068\
    1\u3064\u5148\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B\n    void dfs(const Graph\
    \ &G, int v, int p, int d){\n        parent[0][v] = p;\n        dist[v] = d;\n\
    \        for (auto e : G[v]){\n            if(e != p) dfs(G, e, v, d + 1);\n \
    \       }\n    }\n    \n    void dfs2(const Graph &G, int v, int p, int d){\n\
    \        dist2[v] = d;\n        for(auto e : G[v]){\n            if(e != p) dfs2(G,\
    \ e, v, d + 1);\n        }\n    }\n\n    int lca(int u, int v){\n        if (dist[u]\
    \ < dist[v]) swap(u, v);  // u \u306E\u65B9\u304C\u6DF1\u3044\u3068\u3059\u308B\
    \n        int K = parent.size();\n        // LCA \u307E\u3067\u306E\u8DDD\u96E2\
    \u3092\u540C\u3058\u306B\u3059\u308B\n        for (int k = 0; k < K; k++) {\n\
    \            if ((dist[u] - dist[v]) >> k & 1) {\n                u = parent[k][u];\n\
    \            }\n        }\n        // \u4E8C\u5206\u63A2\u7D22\u3067 LCA \u3092\
    \u6C42\u3081\u308B\n        if(u == v) return u;\n        for(int k = K - 1; k\
    \ >= 0; k--){\n            if(parent[k][u] != parent[k][v]){\n               \
    \ u = parent[k][u];\n                v = parent[k][v];\n            }\n      \
    \  }\n        return parent[0][u];\n    }\n\n    int la(int u, int d){\n     \
    \   if(getDist(u, root) < d){\n            return -1;\n        }\n        // \u4E8C\
    \u5206\u63A2\u7D22\u3067 LA \u3092\u6C42\u3081\u308B\n        int K = parent.size();\n\
    \        for(int k = K - 1; k >= 0; k--){\n            if(d & (1 << k)){\n   \
    \             u = parent[k][u];\n            }\n        }\n        return u;\n\
    \    }\n\n    int diameter(){\n        return diam;\n    }\n \n    pair<int, int>\
    \ endpoint(){\n        return ep;\n    }\n\n    int getDist(int u, int v){\n \
    \       return dist[u] + dist[v] - 2 * dist[lca(u, v)];\n    }\n\n    bool isOnPath(int\
    \ u, int v, int a){\n        return getDist(u, a) + getDist(a, v) == getDist(u,\
    \ v);\n    }\n};\n\n// example (\u5178\u578B90 003)\nint main(){\n    int n; cin\
    \ >> n;\n    vector<vector<int>> G(n);\n    for(int i = 0; i < n - 1; i++){\n\
    \        int a, b; cin >> a >> b; a--; b--;\n        G[a].push_back(b);\n    \
    \    G[b].push_back(a);\n    }\n    TreeLibrary t(G);\n    cout << t.diam + 1\
    \ << \"\\n\";\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/tree.cpp
  requiredBy: []
  timestamp: '2022-09-04 03:09:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/tree.cpp
layout: document
redirect_from:
- /library/lib/graph/tree.cpp
- /library/lib/graph/tree.cpp.html
title: lib/graph/tree.cpp
---
