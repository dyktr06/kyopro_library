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
  bundledCode: "#line 1 \"lib/graph/topologocal_sort.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n// \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
    \u3067\u8F9E\u66F8\u9806\u6700\u5C0F\u306E\u3082\u306E\u3092\u6C42\u3081\u307E\
    \u3059: O(E + VlogV)\ntemplate <typename T>\nvector<T> topological_sort(vector<vector<T>>\
    \ G){\n    int siz = (int) G.size();\n    vector<int> indegree(siz);\n    for(int\
    \ i = 0; i < siz; i++){\n        for(auto x : G[i]){\n            indegree[x]++;\n\
    \        }\n    }\n\n    priority_queue<int, vector<int>, greater<int>> heap;\n\
    \    for(int i = 0; i < siz; i++){\n        if(indegree[i] == 0){\n          \
    \  heap.push(i);\n        }\n    }\n\n    vector<T> res;\n    while(!heap.empty()){\n\
    \        int node = heap.top();\n        heap.pop();\n        res.push_back(node);\n\
    \        for(auto x : G[node]){\n            indegree[x]--;\n            if(indegree[x]\
    \ == 0){\n                heap.push(x);\n            }\n        }\n    }\n   \
    \ return res;\n}\n\nint n, m;\nvector<vector<int>> G;\n\n// example\nint main(){\n\
    \    cin >> n >> m;\n    G.resize(n);\n    for(int i = 0; i < m; i++){\n     \
    \   int a, b; cin >> a >> b; a--; b--;\n        G[a].push_back(b);\n    }\n  \
    \  vector<int> tsort = topological_sort(G);\n    for(auto x : tsort){\n      \
    \  cout << x << \" \";\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// \u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3067\u8F9E\u66F8\u9806\u6700\u5C0F\u306E\
    \u3082\u306E\u3092\u6C42\u3081\u307E\u3059: O(E + VlogV)\ntemplate <typename T>\n\
    vector<T> topological_sort(vector<vector<T>> G){\n    int siz = (int) G.size();\n\
    \    vector<int> indegree(siz);\n    for(int i = 0; i < siz; i++){\n        for(auto\
    \ x : G[i]){\n            indegree[x]++;\n        }\n    }\n\n    priority_queue<int,\
    \ vector<int>, greater<int>> heap;\n    for(int i = 0; i < siz; i++){\n      \
    \  if(indegree[i] == 0){\n            heap.push(i);\n        }\n    }\n\n    vector<T>\
    \ res;\n    while(!heap.empty()){\n        int node = heap.top();\n        heap.pop();\n\
    \        res.push_back(node);\n        for(auto x : G[node]){\n            indegree[x]--;\n\
    \            if(indegree[x] == 0){\n                heap.push(x);\n          \
    \  }\n        }\n    }\n    return res;\n}\n\nint n, m;\nvector<vector<int>> G;\n\
    \n// example\nint main(){\n    cin >> n >> m;\n    G.resize(n);\n    for(int i\
    \ = 0; i < m; i++){\n        int a, b; cin >> a >> b; a--; b--;\n        G[a].push_back(b);\n\
    \    }\n    vector<int> tsort = topological_sort(G);\n    for(auto x : tsort){\n\
    \        cout << x << \" \";\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/topologocal_sort.cpp
  requiredBy: []
  timestamp: '2022-08-06 06:32:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/topologocal_sort.cpp
layout: document
redirect_from:
- /library/lib/graph/topologocal_sort.cpp
- /library/lib/graph/topologocal_sort.cpp.html
title: lib/graph/topologocal_sort.cpp
---
