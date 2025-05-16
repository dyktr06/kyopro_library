---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/data_structure/priority_queue.hpp
    title: "Eraseable Priority Queue (\u524A\u9664\u53EF\u80FD\u512A\u5148\u5EA6\u4ED8\
      \u304D\u30AD\u30E5\u30FC)"
  - icon: ':question:'
    path: lib/data_structure/union_find.hpp
    title: Union-Find
  - icon: ':x:'
    path: lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp
    title: lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions
  bundledCode: "#line 1 \"test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions\"\
    \n#include <iostream>\n\n#line 2 \"lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp\"\
    \n\n#line 4 \"lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp\"\
    \n#include <vector>\n#include <queue>\n#line 2 \"lib/data_structure/union_find.hpp\"\
    \n\n/**\n * @brief Union-Find\n * @docs docs/data_structure/union_find.md\n */\n\
    \n#line 9 \"lib/data_structure/union_find.hpp\"\n#include <cassert>\n\nstruct\
    \ UnionFind{\n    int V;\n    std::vector<int> par;\n    std::vector<int> edg;\n\
    \n    UnionFind(const int N) : V(N), par(N), edg(N){\n        for(int i = 0; i\
    \ < N; ++i){\n            par[i] = -1;\n            edg[i] = 0;\n        }\n \
    \   }\n\n    int root(int x){\n        assert(0 <= x && x < V);\n        if(par[x]\
    \ < 0) return x;\n        return par[x] = root(par[x]);\n    }\n\n    int unite(int\
    \ x, int y){\n        int rx = root(x);\n        int ry = root(y);\n        if(rx\
    \ == ry){\n            edg[rx]++;\n            return rx;\n        }\n       \
    \ if(-par[rx] < -par[ry]) std::swap(rx, ry);\n        par[rx] = par[rx] + par[ry];\n\
    \        par[ry] = rx;\n        edg[rx] += edg[ry] + 1;\n        return rx;\n\
    \    }\n\n    bool same(int x, int y){\n        int rx = root(x);\n        int\
    \ ry = root(y);\n        return rx == ry;\n    }\n\n    long long size(int x){\n\
    \        return -par[root(x)];\n    }\n\n    long long edge(int x){\n        return\
    \ edg[root(x)];\n    }\n};\n#line 2 \"lib/data_structure/priority_queue.hpp\"\n\
    \n/**\n * @brief Eraseable Priority Queue (\u524A\u9664\u53EF\u80FD\u512A\u5148\
    \u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)\n */\n\n#line 9 \"lib/data_structure/priority_queue.hpp\"\
    \n\ntemplate <typename T>\nstruct PriorityQueue{\n    std::priority_queue<T> q,\
    \ removed_q;\n\n    PriorityQueue(){ }\n\n    void normalize(){\n        while(!q.empty()\
    \ && !removed_q.empty()){\n            if(q.top() == removed_q.top()){\n     \
    \           q.pop();\n                removed_q.pop();\n            } else{\n\
    \                break;\n            }\n        }\n    }\n\n    void push(const\
    \ T &x){\n        q.push(x);\n    }\n\n    void erase(const T &x){\n        removed_q.push(x);\n\
    \    }\n\n    size_t size(){\n        return q.size() - removed_q.size();\n  \
    \  }\n\n    bool empty(){\n        return (size() == 0);\n    }\n\n    T top(){\n\
    \        normalize();\n        assert(!q.empty());\n        return q.top();\n\
    \    }\n};\n#line 8 \"lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp\"\
    \n\ntemplate <typename T>\nstruct fraction{\n    T p, q; // long long or BigInt\n\
    \    fraction(T P = 0, T Q = 1) : p(P), q(Q){}\n    inline bool operator==(const\
    \ fraction &other) const {\n        return p * other.q == other.p * q;\n    }\n\
    \    inline bool operator<(const fraction &other) const {\n        if(p == 0 &&\
    \ q == 0) return true;\n        if(other.p == 0 && other.q == 0) return false;\n\
    \        return p * other.q < other.p * q;\n    }\n};\n\ntemplate <typename T>\n\
    std::pair<T, std::vector<int>> rootedTreeTopologicalOrderWithMinimumInversions(const\
    \ std::vector<int> &par, const std::vector<T> &zero, const std::vector<T> &one){\n\
    \    std::vector<int> G = par;\n    int n = G.size();\n    UnionFind uf(n);\n\
    \    PriorityQueue<std::pair<fraction<T>, int>> pq;\n    std::vector<T> inv(n);\n\
    \    std::vector<fraction<T>> fv(n);\n    std::vector<std::deque<int>> p(n);\n\
    \    for(int i = 0; i < n; ++i){\n        fv[i] = {zero[i], one[i]};\n       \
    \ p[i].push_back(i);\n        if(i >= 1) pq.push({fv[i], i});\n    }\n    while(pq.size()){\n\
    \        auto [f, idx] = pq.top();\n        pq.erase(pq.top());\n        int r\
    \ = uf.root(idx);\n        if(G[r] == -1) continue;\n        int prv = uf.root(G[r]);\n\
    \        int nxt = uf.unite(r, prv);\n        G[nxt] = G[prv];\n        inv[nxt]\
    \ += fv[prv].q * fv[r].p;\n        {\n            if(p[r].size() < p[prv].size()){\n\
    \                while(!p[r].empty()){\n                    int x = p[r].front();\n\
    \                    p[r].pop_front();\n                    p[prv].push_back(x);\n\
    \                }\n                if(prv != nxt) std::swap(p[prv], p[nxt]);\n\
    \            }else{\n                while(!p[prv].empty()){\n               \
    \     int x = p[prv].back();\n                    p[prv].pop_back();\n       \
    \             p[r].push_front(x);\n                }\n                if(r !=\
    \ nxt) std::swap(p[r], p[nxt]);\n            }\n        }\n        std::pair<fraction<T>,\
    \ int> nf = {fv[prv], prv};\n        int from = prv;\n        if(nxt == prv) from\
    \ = r;\n        inv[nxt] += inv[from];\n        fv[nxt].p += fv[from].p;\n   \
    \     fv[nxt].q += fv[from].q;\n        if(G[nxt] != -1){\n            pq.erase(nf);\n\
    \            pq.push({fv[nxt], nxt});\n        }\n    }\n    std::vector<int>\
    \ res;\n    while(!p[uf.root(0)].empty()){\n        int x = p[uf.root(0)].front();\n\
    \        p[uf.root(0)].pop_front();\n        res.push_back(x);\n    }\n    return\
    \ {inv[uf.root(0)], res};\n}\n#line 5 \"test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n\n    int n; cin >> n;\n    vector<int> par(n, -1);\n  \
    \  vector<long long> c(n), d(n);\n    for(int i = 1; i < n; ++i){\n        cin\
    \ >> par[i];\n    }\n    for(int i = 0; i < n; ++i){\n        cin >> c[i];\n \
    \   }\n    for(int i = 0; i < n; ++i){\n        cin >> d[i];\n    }\n    auto\
    \ [x, p] = rootedTreeTopologicalOrderWithMinimumInversions(par, c, d);\n    cout\
    \ << x << \"\\n\";\n    for(int i = 0; i < n; ++i){\n        cout << p[i] << \"\
    \ \\n\"[i == n - 1];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions\"\
    \n#include <iostream>\n\n#include \"../../../lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp\"\
    \n\nusing namespace std;\n\nint main(){\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n\n    int n; cin >> n;\n    vector<int> par(n, -1);\n  \
    \  vector<long long> c(n), d(n);\n    for(int i = 1; i < n; ++i){\n        cin\
    \ >> par[i];\n    }\n    for(int i = 0; i < n; ++i){\n        cin >> c[i];\n \
    \   }\n    for(int i = 0; i < n; ++i){\n        cin >> d[i];\n    }\n    auto\
    \ [x, p] = rootedTreeTopologicalOrderWithMinimumInversions(par, c, d);\n    cout\
    \ << x << \"\\n\";\n    for(int i = 0; i < n; ++i){\n        cout << p[i] << \"\
    \ \\n\"[i == n - 1];\n    }\n}\n"
  dependsOn:
  - lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp
  - lib/data_structure/union_find.hpp
  - lib/data_structure/priority_queue.hpp
  isVerificationFile: true
  path: test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
  requiredBy: []
  timestamp: '2025-05-17 03:06:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
- /verify/test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp.html
title: test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
---
