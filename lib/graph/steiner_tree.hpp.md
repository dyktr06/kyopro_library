---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/steiner_tree.hpp\"\n\ntemplate <typename T>\n\
    struct SteinerTree{\nprivate:\n    int V, t;\n    vector<int> last_terminal;\n\
    \    vector<vector<array<T, 2>>> G;\n    vector<vector<T>> dp;\n    const T INF\
    \ = numeric_limits<T>::max() / 3;\n    using PP = pair<T, int>;\n\npublic:\n \
    \   SteinerTree(int node_size) : V(node_size), G(V){}\n\n    void add_edge(int\
    \ u, int v, T cost){\n        G[u].push_back({v, cost}), G[v].push_back({u, cost});\n\
    \    }\n\n    void build(vector<int> &terminal){\n        t = (int) terminal.size();\n\
    \        last_terminal = terminal;\n        if(t == 0) return;\n        dp.resize((1\
    \ << t), vector<T>(V, INF));\n        for(int i = 0; i < t; i++){\n          \
    \  dp[(1 << i)][terminal[i]] = 0;\n        }\n        for(int i = 1; i < (1 <<\
    \ t); i++){\n            for(int j = 0; j < V; j++){\n                // subset\n\
    \                for(int k = i; k > 0; k = (k - 1) & i){\n                   \
    \ dp[i][j] = min(dp[i][j], dp[k][j] + dp[i ^ k][j]);\n                }\n    \
    \        }\n\n            priority_queue<PP, vector<PP>, greater<PP>> que;\n \
    \           for(int j = 0; j < V; j++){\n                que.emplace(dp[i][j],\
    \ j);\n            }\n\n            while(!que.empty()){\n                PP p\
    \ = que.top();\n                que.pop();\n                int v = p.second;\n\
    \                if(dp[i][v] < p.first) continue;\n                for(auto &[to,\
    \ cost] : G[v]){\n                    if(dp[i][to] > dp[i][v] + cost){\n     \
    \                   dp[i][to] = dp[i][v] + cost;\n                        que.emplace(dp[i][to],\
    \ to);\n                    }\n                }\n            }\n        }\n \
    \   }\n\n    T get(int i = -1){\n        if(i == -1) return dp[(1 << t) - 1][last_terminal[0]];\n\
    \        return dp[(1 << t) - 1][i];\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct SteinerTree{\nprivate:\n  \
    \  int V, t;\n    vector<int> last_terminal;\n    vector<vector<array<T, 2>>>\
    \ G;\n    vector<vector<T>> dp;\n    const T INF = numeric_limits<T>::max() /\
    \ 3;\n    using PP = pair<T, int>;\n\npublic:\n    SteinerTree(int node_size)\
    \ : V(node_size), G(V){}\n\n    void add_edge(int u, int v, T cost){\n       \
    \ G[u].push_back({v, cost}), G[v].push_back({u, cost});\n    }\n\n    void build(vector<int>\
    \ &terminal){\n        t = (int) terminal.size();\n        last_terminal = terminal;\n\
    \        if(t == 0) return;\n        dp.resize((1 << t), vector<T>(V, INF));\n\
    \        for(int i = 0; i < t; i++){\n            dp[(1 << i)][terminal[i]] =\
    \ 0;\n        }\n        for(int i = 1; i < (1 << t); i++){\n            for(int\
    \ j = 0; j < V; j++){\n                // subset\n                for(int k =\
    \ i; k > 0; k = (k - 1) & i){\n                    dp[i][j] = min(dp[i][j], dp[k][j]\
    \ + dp[i ^ k][j]);\n                }\n            }\n\n            priority_queue<PP,\
    \ vector<PP>, greater<PP>> que;\n            for(int j = 0; j < V; j++){\n   \
    \             que.emplace(dp[i][j], j);\n            }\n\n            while(!que.empty()){\n\
    \                PP p = que.top();\n                que.pop();\n             \
    \   int v = p.second;\n                if(dp[i][v] < p.first) continue;\n    \
    \            for(auto &[to, cost] : G[v]){\n                    if(dp[i][to] >\
    \ dp[i][v] + cost){\n                        dp[i][to] = dp[i][v] + cost;\n  \
    \                      que.emplace(dp[i][to], to);\n                    }\n  \
    \              }\n            }\n        }\n    }\n\n    T get(int i = -1){\n\
    \        if(i == -1) return dp[(1 << t) - 1][last_terminal[0]];\n        return\
    \ dp[(1 << t) - 1][i];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/steiner_tree.hpp
  requiredBy: []
  timestamp: '2024-08-11 14:50:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/steiner_tree.hpp
layout: document
redirect_from:
- /library/lib/graph/steiner_tree.hpp
- /library/lib/graph/steiner_tree.hpp.html
title: lib/graph/steiner_tree.hpp
---
