---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/graph/topological_sort.hpp
    title: Topological Sort
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
  bundledCode: "#line 1 \"test/aoj/grl/grl_4_b.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/topological_sort.hpp\"\
    \n\n/**\n * @brief Topological Sort\n * @docs docs/graph/topological_sort.md\n\
    \ */\n\ntemplate <typename T>\nvector<T> topological_sort(const vector<vector<T>>\
    \ &G){\n    int siz = (int) G.size();\n    vector<int> indegree(siz);\n    for(int\
    \ i = 0; i < siz; i++){\n        for(auto x : G[i]){\n            indegree[x]++;\n\
    \        }\n    }\n\n    priority_queue<int, vector<int>, greater<int>> heap;\n\
    \    for(int i = 0; i < siz; i++){\n        if(indegree[i] == 0){\n          \
    \  heap.push(i);\n        }\n    }\n\n    vector<T> res;\n    while(!heap.empty()){\n\
    \        int node = heap.top();\n        heap.pop();\n        res.push_back(node);\n\
    \        for(auto x : G[node]){\n            indegree[x]--;\n            if(indegree[x]\
    \ == 0){\n                heap.push(x);\n            }\n        }\n    }\n   \
    \ return res;\n}\n#line 6 \"test/aoj/grl/grl_4_b.test.cpp\"\n\nint main(){\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n, m; cin >>\
    \ n >> m;\n    vector<vector<int>> G(n);\n    for(int i = 0; i < m; i++){\n  \
    \      int u, v; cin >> u >> v;\n        G[u].push_back(v);\n    }\n    for(auto\
    \ x : topological_sort(G)) cout << x << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/topological_sort.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n, m; cin >> n >> m;\n    vector<vector<int>> G(n);\n    for(int i = 0;\
    \ i < m; i++){\n        int u, v; cin >> u >> v;\n        G[u].push_back(v);\n\
    \    }\n    for(auto x : topological_sort(G)) cout << x << \"\\n\";\n}\n"
  dependsOn:
  - lib/graph/topological_sort.hpp
  isVerificationFile: true
  path: test/aoj/grl/grl_4_b.test.cpp
  requiredBy: []
  timestamp: '2024-03-21 02:21:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/grl/grl_4_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/grl_4_b.test.cpp
- /verify/test/aoj/grl/grl_4_b.test.cpp.html
title: test/aoj/grl/grl_4_b.test.cpp
---
