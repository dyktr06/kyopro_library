---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/bipartite_matching.hpp
    title: lib/graph/bipartite_matching.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
  bundledCode: "#line 1 \"test/aoj/grl/grl_7_a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/bipartite_matching.hpp\"\
    \n\ntemplate <typename T>\nstruct BipartiteMatching{\n    vector<vector<T>> G;\n\
    \    vector<T> alive, match, used;\n    int timestamp;\n\n    BipartiteMatching(int\
    \ n){\n        G.resize(n);\n        alive.assign(n, 1);\n        match.assign(n,\
    \ -1);\n        used.assign(n, 0);\n        timestamp = 0;\n    }\n\n    void\
    \ add_edge(int u, int v){\n        G[u].push_back(v);\n        G[v].push_back(u);\n\
    \    }\n\n    bool dfs(int v){\n        used[v] = timestamp;\n        for(auto\
    \ &x : G[v]){\n            int y = match[x];\n            if(alive[x] == 0) continue;\n\
    \            if(y == -1 || (used[y] != timestamp && dfs(y))){\n              \
    \  match[v] = x;\n                match[x] = v;\n                return true;\n\
    \            }\n        }\n        return false;\n    }\n\n    int bipartite_matching(){\n\
    \        int res = 0;\n        for(int i = 0; i < (int) G.size(); i++){\n    \
    \        if(alive[i] == 0) continue;\n            if(match[i] == -1){\n      \
    \          ++timestamp;\n                res += dfs(i);\n            }\n     \
    \   }\n        return res;\n    }\n};\n#line 6 \"test/aoj/grl/grl_7_a.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int x, y, e; cin >> x >> y >> e;\n    BipartiteMatching<int> bm(x + y);\n\
    \    for(int i = 0; i < e; i++){\n        int u, v; cin >> u >> v;\n        bm.add_edge(u,\
    \ v + x);\n    }\n    cout << bm.bipartite_matching() << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/bipartite_matching.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int x, y, e; cin >> x >> y >> e;\n    BipartiteMatching<int> bm(x + y);\n\
    \    for(int i = 0; i < e; i++){\n        int u, v; cin >> u >> v;\n        bm.add_edge(u,\
    \ v + x);\n    }\n    cout << bm.bipartite_matching() << \"\\n\";\n}\n"
  dependsOn:
  - lib/graph/bipartite_matching.hpp
  isVerificationFile: true
  path: test/aoj/grl/grl_7_a.test.cpp
  requiredBy: []
  timestamp: '2024-05-06 22:18:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl/grl_7_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/grl_7_a.test.cpp
- /verify/test/aoj/grl/grl_7_a.test.cpp.html
title: test/aoj/grl/grl_7_a.test.cpp
---
