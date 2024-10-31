---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/steiner_tree.md
    document_title: "Steiner Tree (\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\u6728)"
    links:
    - https://www.slideshare.net/wata_orz/ss-12131479
  bundledCode: "#line 2 \"lib/graph/steiner_tree.hpp\"\n\n/**\n * @brief Steiner Tree\
    \ (\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\u6728)\n * @docs docs/graph/steiner_tree.md\n\
    \ * @see https://www.slideshare.net/wata_orz/ss-12131479\n */\n\ntemplate <typename\
    \ T>\nstruct SteinerTree{\nprivate:\n    int V, t;\n    vector<int> last_terminal;\n\
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
  code: "#pragma once\n\n/**\n * @brief Steiner Tree (\u30B7\u30E5\u30BF\u30A4\u30CA\
    \u30FC\u6728)\n * @docs docs/graph/steiner_tree.md\n * @see https://www.slideshare.net/wata_orz/ss-12131479\n\
    \ */\n\ntemplate <typename T>\nstruct SteinerTree{\nprivate:\n    int V, t;\n\
    \    vector<int> last_terminal;\n    vector<vector<array<T, 2>>> G;\n    vector<vector<T>>\
    \ dp;\n    const T INF = numeric_limits<T>::max() / 3;\n    using PP = pair<T,\
    \ int>;\n\npublic:\n    SteinerTree(int node_size) : V(node_size), G(V){}\n\n\
    \    void add_edge(int u, int v, T cost){\n        G[u].push_back({v, cost}),\
    \ G[v].push_back({u, cost});\n    }\n\n    void build(vector<int> &terminal){\n\
    \        t = (int) terminal.size();\n        last_terminal = terminal;\n     \
    \   if(t == 0) return;\n        dp.resize((1 << t), vector<T>(V, INF));\n    \
    \    for(int i = 0; i < t; i++){\n            dp[(1 << i)][terminal[i]] = 0;\n\
    \        }\n        for(int i = 1; i < (1 << t); i++){\n            for(int j\
    \ = 0; j < V; j++){\n                // subset\n                for(int k = i;\
    \ k > 0; k = (k - 1) & i){\n                    dp[i][j] = min(dp[i][j], dp[k][j]\
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
  timestamp: '2024-10-31 23:51:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/steiner_tree.hpp
layout: document
redirect_from:
- /library/lib/graph/steiner_tree.hpp
- /library/lib/graph/steiner_tree.hpp.html
title: "Steiner Tree (\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\u6728)"
---
## Steiner Tree (シュタイナー木)

#### 概要

重みがついたグラフに対して最小シュタイナー木のコストを求めます。

#### 使い方

- `SteinerTree(node_size)`: コンストラクタ (node_size は頂点数)
- `add_edge(u, v, cost)`: 頂点 $u$ から 頂点 $v$ に重み cost の無向辺を追加します。
- `build(terminal)`: ターミナルを terminal として、最小シュタイナー木のコストの計算を行います。
- `get(i)`: ターミナルに加えて、頂点 $i$ を含んだ最小シュタイナー木のコストを求めます。(-1 の場合は何も含まない)

#### 計算量

頂点数を $V$、辺の数を $E$、ターミナルの数を $t$ とすると、$\mathrm{O}(V 3^t + (V + E) 2^t \log V)$
