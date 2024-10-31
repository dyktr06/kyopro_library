---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/maximum_independent_set.hpp
    title: "Maximum Independent Set (\u6700\u5927\u72EC\u7ACB\u96C6\u5408)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/library_checker/graph/maximum_independent_set.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/maximum_independent_set.hpp\"\
    \n\n/**\n * @brief Maximum Independent Set (\u6700\u5927\u72EC\u7ACB\u96C6\u5408\
    )\n */\n\nvector<int> maximumIndependentSet(vector<vector<int>> &G, int loop =\
    \ 100000){\n    const int MAX_V = 64;\n    int n = G.size();\n    assert(n <=\
    \ MAX_V);\n    vector<bitset<MAX_V>> g(n);\n    for(int i = 0; i < n; i++){\n\
    \        for(auto &v : G[i]){\n            g[i][v] = 1;\n        }\n    }\n\n\
    \    auto random_shuffle = [](vector<int> &p){\n        int n = p.size();\n  \
    \      for(int i = n; i > 1; i--){\n            int a = i - 1;\n            int\
    \ b = rand() % i;\n            swap(p[a], p[b]);\n        }\n    };\n\n    vector<int>\
    \ ans;\n    bitset<MAX_V> used, emp;\n    vector<int> p(n);\n    iota(p.begin(),\
    \ p.end(), 0);\n    for(int k = 0; k < loop; k++){\n        random_shuffle(p);\n\
    \        vector<int> res;\n        for(int i = 0; i < n; i++){\n            if(used[p[i]])\
    \ continue;\n            res.push_back(p[i]);\n            used |= g[p[i]];\n\
    \        }\n        if(ans.size() < res.size()){\n            swap(ans, res);\n\
    \        }\n        used &= emp;\n    }\n    return ans;\n}\n#line 6 \"test/library_checker/graph/maximum_independent_set.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n \
    \   int n, m; cin >> n >> m;\n    vector<vector<int>> G(n);\n    for(int i = 0;\
    \ i < m; i++){\n        int u, v; cin >> u >> v;\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n\n    vector<int> ans = maximumIndependentSet(G);\n\
    \    cout << ans.size() << '\\n';\n    for(auto &v : ans){\n        cout << v\
    \ << \" \";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/maximum_independent_set.hpp\"\
    \n\nint main(){\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n \
    \   int n, m; cin >> n >> m;\n    vector<vector<int>> G(n);\n    for(int i = 0;\
    \ i < m; i++){\n        int u, v; cin >> u >> v;\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n\n    vector<int> ans = maximumIndependentSet(G);\n\
    \    cout << ans.size() << '\\n';\n    for(auto &v : ans){\n        cout << v\
    \ << \" \";\n    }\n}\n"
  dependsOn:
  - lib/graph/maximum_independent_set.hpp
  isVerificationFile: true
  path: test/library_checker/graph/maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2024-10-31 23:51:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/maximum_independent_set.test.cpp
- /verify/test/library_checker/graph/maximum_independent_set.test.cpp.html
title: test/library_checker/graph/maximum_independent_set.test.cpp
---
