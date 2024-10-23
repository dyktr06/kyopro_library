---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/minimum_diameter_spanning_tree.test.cpp
    title: test/library_checker/graph/minimum_diameter_spanning_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://www.slideshare.net/slideshow/ss-17402143/17402143
  bundledCode: "#line 2 \"lib/graph/minimum_diameter_spanning_tree.hpp\"\n\n// \u53C2\
    \u8003: https://www.slideshare.net/slideshow/ss-17402143/17402143\nstruct MinimumDiameterSpanningTree{\n\
    \n    const long long INF = 0x1fffffffffffffff;\n\n    struct Edge{\n        int\
    \ from, to;\n        long long cost;\n        int id;\n    };\n\n    int V, E;\n\
    \    vector<vector<Edge>> G;\n    long long tree_diameter = INF;\n    vector<int>\
    \ tree_edge;\n\n    MinimumDiameterSpanningTree(int n) : V(n), E(0), G(n) { }\n\
    \n    void add_edge(int u, int v, long long cost){\n        // \u9014\u4E2D\u306E\
    \u8A08\u7B97\u3067\u5206\u6BCD\u304C 2 \u306B\u306A\u308B\u305F\u3081 2 \u500D\
    \u3057\u3066\u3044\u308B\n        G[u].push_back({u, v, cost * 2, E});\n     \
    \   G[v].push_back({v, u, cost * 2, E});\n        E++;\n    }\n\n    void build(){\n\
    \        if(V == 1){\n            tree_diameter = 0;\n            return;\n  \
    \      }\n\n        using P = pair<long long, int>;\n\n        // \u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\u6CD5\u3067\u5168\u70B9\u5BFE\u9593\u306E\u6700\u77ED\
    \u8DDD\u96E2\u3092\u6C42\u3081\u308B\n        vector<vector<long long>> dist(V,\
    \ vector<long long>(V, INF));\n        for(int i = 0; i < V; i++){\n         \
    \   priority_queue<P, vector<P>, greater<>> q;\n            dist[i][i] = 0;\n\
    \            q.emplace(0, i);\n            while(q.size()){\n                auto\
    \ [c, at] = q.top();\n                q.pop();\n                if(c > dist[i][at])\
    \ continue;\n                for(auto &[_, to, t, id] : G[at]){\n            \
    \        if(dist[i][to] > c + t){\n                        dist[i][to] = c + t;\n\
    \                        q.emplace(dist[i][to], to);\n                    }\n\
    \                }\n            }\n        }\n\n        vector<long long> midpoint(E,\
    \ INF);\n        Edge min_edge;\n        for(int from = 0; from < V; from++){\n\
    \            long long diameter = INF;\n            for(auto &[_, to, cost, id]\
    \ : G[from]){\n                if(from > to) continue;\n\n                vector<P>\
    \ lines(V);\n                for(int i = 0; i < V; i++){\n                   \
    \ lines[i] = {dist[from][i], i};\n                }\n                sort(lines.rbegin(),\
    \ lines.rend());\n\n                // \u8FBA\u306E\u9593\u3067\u3001\u76F4\u5F84\
    \u304C\u6700\u5927\u5024\u306B\u306A\u308B\u70B9\n                vector<long\
    \ long> mid(V);\n                for(int i = 0; i < V; i++){\n               \
    \     mid[i] = min(cost, max(0LL, (dist[to][i] - dist[from][i] + cost) / 2));\n\
    \                }\n                // \u8FBA\u4E0A\u306E\u70B9 t \u3068\u9802\
    \u70B9 i \u3068\u306E\u8DDD\u96E2\n                auto f = [&](int i, int t){\n\
    \                    return min(dist[from][i] + t, dist[to][i] + (cost - t));\n\
    \                };\n                long long cur = 0;\n                for(int\
    \ i = 0; i < V; i++){\n                    auto [d_i, at_i] = lines[i];\n    \
    \                if(diameter > f(at_i, cur)){\n                        diameter\
    \ = f(at_i, cur);\n                        midpoint[id] = cur;\n             \
    \       }\n                    bool found = false;\n                    for(int\
    \ j = i + 1; j < V; j++){\n                        auto [d_j, at_j] = lines[j];\n\
    \                        if(mid[at_i] < mid[at_j] && f(at_i, mid[at_j]) < f(at_j,\
    \ mid[at_j])){\n                            int nxt = mid[at_i] + (dist[from][at_i]\
    \ - dist[from][at_j]) / 2;\n                            cur = nxt;\n         \
    \                   found = true;\n                            i = j - 1;\n  \
    \                          break;\n                        }\n               \
    \     }\n                    if(!found){\n                        if(diameter\
    \ > f(at_i, cost)){\n                            diameter = f(at_i, cost);\n \
    \                           midpoint[id] = cost;\n                        }\n\
    \                        break;\n                    }\n                }\n  \
    \              if(tree_diameter > diameter){\n                    tree_diameter\
    \ = diameter;\n                    min_edge = {from, to, cost, id};\n        \
    \        }\n            }\n        }\n\n        // \u6700\u5C0F\u76F4\u5F84\u5168\
    \u57DF\u6728\u306E\u69CB\u7BC9\n        {\n            priority_queue<P, vector<P>,\
    \ greater<>> q;\n            vector<long long> ndist(V, INF);\n            ndist[min_edge.from]\
    \ = midpoint[min_edge.id];\n            ndist[min_edge.to] = min_edge.cost - midpoint[min_edge.id];\n\
    \            q.emplace(ndist[min_edge.from], min_edge.from);\n            q.emplace(ndist[min_edge.to],\
    \ min_edge.to);\n            vector<int> edge_id(V, -1);\n            edge_id[min_edge.from]\
    \ = min_edge.id;\n            while(q.size()){\n                auto [c, at] =\
    \ q.top();\n                q.pop();\n                if(c > ndist[at]) continue;\n\
    \                if(edge_id[at] != -1){\n                    tree_edge.push_back(edge_id[at]);\n\
    \                }\n                for(auto &[_, to, t, id] : G[at]){\n     \
    \               if(ndist[to] > c + t){\n                        ndist[to] = c\
    \ + t;\n                        edge_id[to] = id;\n                        q.emplace(ndist[to],\
    \ to);\n                    }\n                }\n            }\n        }\n \
    \   }\n\n    vector<int> get(){\n        return tree_edge;\n    }\n\n    long\
    \ long getTreeDiameter(){\n        return tree_diameter;\n    }\n};\n"
  code: "#pragma once\n\n// \u53C2\u8003: https://www.slideshare.net/slideshow/ss-17402143/17402143\n\
    struct MinimumDiameterSpanningTree{\n\n    const long long INF = 0x1fffffffffffffff;\n\
    \n    struct Edge{\n        int from, to;\n        long long cost;\n        int\
    \ id;\n    };\n\n    int V, E;\n    vector<vector<Edge>> G;\n    long long tree_diameter\
    \ = INF;\n    vector<int> tree_edge;\n\n    MinimumDiameterSpanningTree(int n)\
    \ : V(n), E(0), G(n) { }\n\n    void add_edge(int u, int v, long long cost){\n\
    \        // \u9014\u4E2D\u306E\u8A08\u7B97\u3067\u5206\u6BCD\u304C 2 \u306B\u306A\
    \u308B\u305F\u3081 2 \u500D\u3057\u3066\u3044\u308B\n        G[u].push_back({u,\
    \ v, cost * 2, E});\n        G[v].push_back({v, u, cost * 2, E});\n        E++;\n\
    \    }\n\n    void build(){\n        if(V == 1){\n            tree_diameter =\
    \ 0;\n            return;\n        }\n\n        using P = pair<long long, int>;\n\
    \n        // \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\u3067\u5168\u70B9\u5BFE\
    \u9593\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\n        vector<vector<long\
    \ long>> dist(V, vector<long long>(V, INF));\n        for(int i = 0; i < V; i++){\n\
    \            priority_queue<P, vector<P>, greater<>> q;\n            dist[i][i]\
    \ = 0;\n            q.emplace(0, i);\n            while(q.size()){\n         \
    \       auto [c, at] = q.top();\n                q.pop();\n                if(c\
    \ > dist[i][at]) continue;\n                for(auto &[_, to, t, id] : G[at]){\n\
    \                    if(dist[i][to] > c + t){\n                        dist[i][to]\
    \ = c + t;\n                        q.emplace(dist[i][to], to);\n            \
    \        }\n                }\n            }\n        }\n\n        vector<long\
    \ long> midpoint(E, INF);\n        Edge min_edge;\n        for(int from = 0; from\
    \ < V; from++){\n            long long diameter = INF;\n            for(auto &[_,\
    \ to, cost, id] : G[from]){\n                if(from > to) continue;\n\n     \
    \           vector<P> lines(V);\n                for(int i = 0; i < V; i++){\n\
    \                    lines[i] = {dist[from][i], i};\n                }\n     \
    \           sort(lines.rbegin(), lines.rend());\n\n                // \u8FBA\u306E\
    \u9593\u3067\u3001\u76F4\u5F84\u304C\u6700\u5927\u5024\u306B\u306A\u308B\u70B9\
    \n                vector<long long> mid(V);\n                for(int i = 0; i\
    \ < V; i++){\n                    mid[i] = min(cost, max(0LL, (dist[to][i] - dist[from][i]\
    \ + cost) / 2));\n                }\n                // \u8FBA\u4E0A\u306E\u70B9\
    \ t \u3068\u9802\u70B9 i \u3068\u306E\u8DDD\u96E2\n                auto f = [&](int\
    \ i, int t){\n                    return min(dist[from][i] + t, dist[to][i] +\
    \ (cost - t));\n                };\n                long long cur = 0;\n     \
    \           for(int i = 0; i < V; i++){\n                    auto [d_i, at_i]\
    \ = lines[i];\n                    if(diameter > f(at_i, cur)){\n            \
    \            diameter = f(at_i, cur);\n                        midpoint[id] =\
    \ cur;\n                    }\n                    bool found = false;\n     \
    \               for(int j = i + 1; j < V; j++){\n                        auto\
    \ [d_j, at_j] = lines[j];\n                        if(mid[at_i] < mid[at_j] &&\
    \ f(at_i, mid[at_j]) < f(at_j, mid[at_j])){\n                            int nxt\
    \ = mid[at_i] + (dist[from][at_i] - dist[from][at_j]) / 2;\n                 \
    \           cur = nxt;\n                            found = true;\n          \
    \                  i = j - 1;\n                            break;\n          \
    \              }\n                    }\n                    if(!found){\n   \
    \                     if(diameter > f(at_i, cost)){\n                        \
    \    diameter = f(at_i, cost);\n                            midpoint[id] = cost;\n\
    \                        }\n                        break;\n                 \
    \   }\n                }\n                if(tree_diameter > diameter){\n    \
    \                tree_diameter = diameter;\n                    min_edge = {from,\
    \ to, cost, id};\n                }\n            }\n        }\n\n        // \u6700\
    \u5C0F\u76F4\u5F84\u5168\u57DF\u6728\u306E\u69CB\u7BC9\n        {\n          \
    \  priority_queue<P, vector<P>, greater<>> q;\n            vector<long long> ndist(V,\
    \ INF);\n            ndist[min_edge.from] = midpoint[min_edge.id];\n         \
    \   ndist[min_edge.to] = min_edge.cost - midpoint[min_edge.id];\n            q.emplace(ndist[min_edge.from],\
    \ min_edge.from);\n            q.emplace(ndist[min_edge.to], min_edge.to);\n \
    \           vector<int> edge_id(V, -1);\n            edge_id[min_edge.from] =\
    \ min_edge.id;\n            while(q.size()){\n                auto [c, at] = q.top();\n\
    \                q.pop();\n                if(c > ndist[at]) continue;\n     \
    \           if(edge_id[at] != -1){\n                    tree_edge.push_back(edge_id[at]);\n\
    \                }\n                for(auto &[_, to, t, id] : G[at]){\n     \
    \               if(ndist[to] > c + t){\n                        ndist[to] = c\
    \ + t;\n                        edge_id[to] = id;\n                        q.emplace(ndist[to],\
    \ to);\n                    }\n                }\n            }\n        }\n \
    \   }\n\n    vector<int> get(){\n        return tree_edge;\n    }\n\n    long\
    \ long getTreeDiameter(){\n        return tree_diameter;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/minimum_diameter_spanning_tree.hpp
  requiredBy: []
  timestamp: '2024-10-24 01:29:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/minimum_diameter_spanning_tree.test.cpp
documentation_of: lib/graph/minimum_diameter_spanning_tree.hpp
layout: document
redirect_from:
- /library/lib/graph/minimum_diameter_spanning_tree.hpp
- /library/lib/graph/minimum_diameter_spanning_tree.hpp.html
title: lib/graph/minimum_diameter_spanning_tree.hpp
---
