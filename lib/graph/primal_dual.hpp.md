---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/assignment_problem.hpp
    title: lib/graph/assignment_problem.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/assignment.test.cpp
    title: test/library_checker/graph/assignment.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/graph/primal_dual.hpp\"\n\ntemplate <typename flow_t,\
    \ typename cost_t>\nstruct PrimalDual{\n    struct Edge{\n        int from, to;\n\
    \        flow_t cap, flow;\n        cost_t cost;\n        int rev;\n        bool\
    \ is_rev;\n    };\n    int V;\n    vector<vector<Edge>> G;\n    vector<cost_t>\
    \ potential, min_cost;\n    vector<int> prev_v, prev_e;\n    const cost_t INF;\n\
    \    PrimalDual(int n) : V(n), G(n), INF(numeric_limits<cost_t>::max() / 3) {}\n\
    \n    void add_edge(int from, int to, flow_t cap, cost_t cost){\n        G[from].push_back(Edge{from,\
    \ to, cap, 0, cost, (int) G[to].size(), false});\n        G[to].push_back(Edge{to,\
    \ from, 0, cap, -cost, (int) G[from].size() - 1, true});\n    }\n\n    cost_t\
    \ flow(int s, int t, flow_t f){\n        assert(0 <= s && s < V && 0 <= t && t\
    \ < V);\n        assert(0 <= f);\n        cost_t ret = 0;\n        using P = pair<cost_t,\
    \ int>;\n        priority_queue<P, vector<P>, greater<P>> pq;\n        potential.assign(V,\
    \ 0);\n        prev_v.assign(V, -1);\n        prev_e.assign(V, -1);\n        while(f\
    \ > 0){\n            // s-t \u30D1\u30B9\u3092\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\
    \u6CD5\u3067\u63A2\u7D22\n            min_cost.assign(V, INF);\n            pq.emplace(0,\
    \ s);\n            min_cost[s] = 0;\n            while(pq.size()){\n         \
    \       auto [c, at] = pq.top();\n                pq.pop();\n                if(min_cost[at]\
    \ < c) continue;\n                for(int i = 0; i < (int) G[at].size(); i++){\n\
    \                    auto &e = G[at][i];\n                    // \u975E\u8CA0\u306B\
    \u3059\u308B\u305F\u3081\u306B\u3001cost'(at, e.to) = cost(at, e.to) + potential[at]\
    \ - potential[e.to] \u3068\u3059\u308B\n                    // min_cost'[at] +\
    \ cost'(at, e.to) >= min_cost'[e.to]\n                    // <=> (min_cost'[at]\
    \ + potential[at]) + cost(at, e.to) >= (min_cost[e.to] + potential[e.to])\n  \
    \                  cost_t next_cost = min_cost[at] + e.cost + potential[at] -\
    \ potential[e.to];\n                    if(e.cap > 0 && next_cost < min_cost[e.to]){\n\
    \                        min_cost[e.to] = next_cost;\n                       \
    \ prev_v[e.to] = at;\n                        prev_e[e.to] = i;\n            \
    \            pq.emplace(min_cost[e.to], e.to);\n                    }\n      \
    \          }\n            }\n            if(min_cost[t] == INF){\n           \
    \     return -1;\n            }\n            // \u30D5\u30ED\u30FC\u3092\u6D41\
    \u3059\n            flow_t addflow = f;\n            for(int i = t; i != s; i\
    \ = prev_v[i]){\n                addflow = min(addflow, G[prev_v[i]][prev_e[i]].cap);\n\
    \            }\n            f -= addflow;\n            ret += addflow * (min_cost[t]\
    \ + potential[t]);\n            for(int i = t; i != s; i = prev_v[i]){\n     \
    \           auto &e = G[prev_v[i]][prev_e[i]];\n                e.cap -= addflow;\n\
    \                e.flow += addflow;\n                G[i][e.rev].cap += addflow;\n\
    \                G[i][e.rev].flow -= addflow;\n            }\n\n            //\
    \ \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u66F4\u65B0\n            for(int\
    \ i = 0; i < V; i++){\n                potential[i] += min_cost[i];\n        \
    \    }\n        }\n        return ret;\n    }\n\n    vector<Edge> edges(){\n \
    \       vector<Edge> ret;\n        for(int i = 0; i < V; i++){\n            for(auto\
    \ &e : G[i]){\n                if(e.is_rev) continue;\n                ret.push_back(e);\n\
    \            }\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename flow_t, typename cost_t>\nstruct PrimalDual{\n\
    \    struct Edge{\n        int from, to;\n        flow_t cap, flow;\n        cost_t\
    \ cost;\n        int rev;\n        bool is_rev;\n    };\n    int V;\n    vector<vector<Edge>>\
    \ G;\n    vector<cost_t> potential, min_cost;\n    vector<int> prev_v, prev_e;\n\
    \    const cost_t INF;\n    PrimalDual(int n) : V(n), G(n), INF(numeric_limits<cost_t>::max()\
    \ / 3) {}\n\n    void add_edge(int from, int to, flow_t cap, cost_t cost){\n \
    \       G[from].push_back(Edge{from, to, cap, 0, cost, (int) G[to].size(), false});\n\
    \        G[to].push_back(Edge{to, from, 0, cap, -cost, (int) G[from].size() -\
    \ 1, true});\n    }\n\n    cost_t flow(int s, int t, flow_t f){\n        assert(0\
    \ <= s && s < V && 0 <= t && t < V);\n        assert(0 <= f);\n        cost_t\
    \ ret = 0;\n        using P = pair<cost_t, int>;\n        priority_queue<P, vector<P>,\
    \ greater<P>> pq;\n        potential.assign(V, 0);\n        prev_v.assign(V, -1);\n\
    \        prev_e.assign(V, -1);\n        while(f > 0){\n            // s-t \u30D1\
    \u30B9\u3092\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\u3067\u63A2\u7D22\n   \
    \         min_cost.assign(V, INF);\n            pq.emplace(0, s);\n          \
    \  min_cost[s] = 0;\n            while(pq.size()){\n                auto [c, at]\
    \ = pq.top();\n                pq.pop();\n                if(min_cost[at] < c)\
    \ continue;\n                for(int i = 0; i < (int) G[at].size(); i++){\n  \
    \                  auto &e = G[at][i];\n                    // \u975E\u8CA0\u306B\
    \u3059\u308B\u305F\u3081\u306B\u3001cost'(at, e.to) = cost(at, e.to) + potential[at]\
    \ - potential[e.to] \u3068\u3059\u308B\n                    // min_cost'[at] +\
    \ cost'(at, e.to) >= min_cost'[e.to]\n                    // <=> (min_cost'[at]\
    \ + potential[at]) + cost(at, e.to) >= (min_cost[e.to] + potential[e.to])\n  \
    \                  cost_t next_cost = min_cost[at] + e.cost + potential[at] -\
    \ potential[e.to];\n                    if(e.cap > 0 && next_cost < min_cost[e.to]){\n\
    \                        min_cost[e.to] = next_cost;\n                       \
    \ prev_v[e.to] = at;\n                        prev_e[e.to] = i;\n            \
    \            pq.emplace(min_cost[e.to], e.to);\n                    }\n      \
    \          }\n            }\n            if(min_cost[t] == INF){\n           \
    \     return -1;\n            }\n            // \u30D5\u30ED\u30FC\u3092\u6D41\
    \u3059\n            flow_t addflow = f;\n            for(int i = t; i != s; i\
    \ = prev_v[i]){\n                addflow = min(addflow, G[prev_v[i]][prev_e[i]].cap);\n\
    \            }\n            f -= addflow;\n            ret += addflow * (min_cost[t]\
    \ + potential[t]);\n            for(int i = t; i != s; i = prev_v[i]){\n     \
    \           auto &e = G[prev_v[i]][prev_e[i]];\n                e.cap -= addflow;\n\
    \                e.flow += addflow;\n                G[i][e.rev].cap += addflow;\n\
    \                G[i][e.rev].flow -= addflow;\n            }\n\n            //\
    \ \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u66F4\u65B0\n            for(int\
    \ i = 0; i < V; i++){\n                potential[i] += min_cost[i];\n        \
    \    }\n        }\n        return ret;\n    }\n\n    vector<Edge> edges(){\n \
    \       vector<Edge> ret;\n        for(int i = 0; i < V; i++){\n            for(auto\
    \ &e : G[i]){\n                if(e.is_rev) continue;\n                ret.push_back(e);\n\
    \            }\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/primal_dual.hpp
  requiredBy:
  - lib/graph/assignment_problem.hpp
  timestamp: '2024-10-21 21:40:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/assignment.test.cpp
documentation_of: lib/graph/primal_dual.hpp
layout: document
redirect_from:
- /library/lib/graph/primal_dual.hpp
- /library/lib/graph/primal_dual.hpp.html
title: lib/graph/primal_dual.hpp
---
