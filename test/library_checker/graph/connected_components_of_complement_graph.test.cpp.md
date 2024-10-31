---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/connected_components_of_complement_graph.hpp
    title: "Connected Components of Complement Graph (\u88DC\u30B0\u30E9\u30D5\u306E\
      \u9023\u7D50\u6210\u5206\u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/connected_components_of_complement_graph
    links:
    - https://judge.yosupo.jp/problem/connected_components_of_complement_graph
  bundledCode: "#line 1 \"test/library_checker/graph/connected_components_of_complement_graph.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/connected_components_of_complement_graph\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/connected_components_of_complement_graph.hpp\"\
    \n\n/**\n * @brief Connected Components of Complement Graph (\u88DC\u30B0\u30E9\
    \u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3)\n * @docs docs/graph/connected_components_of_complement_graph.md\n\
    \ */\n\ntemplate <typename T>\nvector<vector<int>> connectedComponentsOfComplementGraph(vector<vector<T>>\
    \ &G){\n    int n = (int) G.size();\n    vector<vector<int>> ans;\n    vector<bool>\
    \ used(n, false), reach(n, true);\n    vector<int> s(n);\n    iota(s.begin(),\
    \ s.end(), 0);\n    for(int i = 0; i < n; i++){\n        if(used[i]) continue;\n\
    \        vector<int> v;\n        queue<int> q;\n        q.push(i);\n        while(!q.empty()){\n\
    \            int x = q.front(); q.pop();\n            if(used[x]) continue;\n\
    \            used[x] = true;\n            v.push_back(x);\n            for(auto\
    \ y : G[x]){\n                reach[y] = false;\n            }\n            vector<int>\
    \ ts;\n            while(!s.empty()){\n                if(reach[s.back()]){\n\
    \                    q.push(s.back());\n                } else{\n            \
    \        ts.push_back(s.back());\n                }\n                s.pop_back();\n\
    \            }\n            swap(s, ts);\n            for(auto y : G[x]){\n  \
    \              reach[y] = true;\n            }\n        }\n        ans.push_back(v);\n\
    \    }\n    return ans;\n}\n#line 6 \"test/library_checker/graph/connected_components_of_complement_graph.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n, m; cin >> n >> m;\n    vector<vector<int>> G(n);\n    for(int i = 0;\
    \ i < m; i++){\n        int a, b; cin >> a >> b;\n        G[a].push_back(b);\n\
    \        G[b].push_back(a);\n    }\n\n    vector<vector<int>> ans = connectedComponentsOfComplementGraph(G);\n\
    \    cout << ans.size() << \"\\n\";\n    for(auto &v : ans){\n        cout <<\
    \ v.size() << \" \";\n        for(auto x : v){\n            cout << x << \" \"\
    ;\n        }\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/connected_components_of_complement_graph\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/connected_components_of_complement_graph.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int n, m; cin >> n >> m;\n    vector<vector<int>> G(n);\n    for(int i = 0;\
    \ i < m; i++){\n        int a, b; cin >> a >> b;\n        G[a].push_back(b);\n\
    \        G[b].push_back(a);\n    }\n\n    vector<vector<int>> ans = connectedComponentsOfComplementGraph(G);\n\
    \    cout << ans.size() << \"\\n\";\n    for(auto &v : ans){\n        cout <<\
    \ v.size() << \" \";\n        for(auto x : v){\n            cout << x << \" \"\
    ;\n        }\n        cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/graph/connected_components_of_complement_graph.hpp
  isVerificationFile: true
  path: test/library_checker/graph/connected_components_of_complement_graph.test.cpp
  requiredBy: []
  timestamp: '2024-11-01 00:31:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/connected_components_of_complement_graph.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/connected_components_of_complement_graph.test.cpp
- /verify/test/library_checker/graph/connected_components_of_complement_graph.test.cpp.html
title: test/library_checker/graph/connected_components_of_complement_graph.test.cpp
---
