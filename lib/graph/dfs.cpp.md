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
  bundledCode: "#line 1 \"lib/graph/dfs.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nint n;\nvector<vector<int>> G;\n\n// DFS\nvoid dfs(int curr, int prev\
    \ = -1){\n\n    if(prev == -1){\n\n    }else{\n\n    }\n\n    for(auto x : G[curr]){\n\
    \        if(x == prev){\n            continue;\n        }\n        dfs(x, curr);\n\
    \    }\n}\n\nvector<int> depth;\n\n// \u30B9\u30BF\u30FC\u30C8\u3092\u57FA\u6E96\
    \u3068\u3059\u308B\u4ED6\u306E\u9802\u70B9\u306E\u6DF1\u3055\u3092\u6C42\u3081\
    \u307E\u3059 (\u30B0\u30E9\u30D5\u304C\u6728\u3067\u306A\u3044\u3068\u4F7F\u3048\
    \u306A\u3044) : O(N)\ntemplate <typename T>\nvoid getDepth(T curr, T prev = -1)\
    \ {\n    if(prev == -1){\n        depth[curr] = 0;\n    }\n \n    for(auto x :\
    \ G[curr]){\n        if(x == prev){\n            continue;\n        }\n      \
    \  depth[x] = depth[curr] + 1;\n        getDepth(x, curr);\n    }\n    return;\n\
    }\n\n// example\nint main(){\n    cin >> n;\n    G = vector<vector<int>>(n);\n\
    \n    for(int i = 0; i < n - 1; i++){\n        int a, b;\n        cin >> a >>\
    \ b;\n        a--, b--;\n        G[a].push_back(b);\n        G[b].push_back(a);\n\
    \    }\n    dfs(0, -1);\n    return;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nint n;\nvector<vector<int>>\
    \ G;\n\n// DFS\nvoid dfs(int curr, int prev = -1){\n\n    if(prev == -1){\n\n\
    \    }else{\n\n    }\n\n    for(auto x : G[curr]){\n        if(x == prev){\n \
    \           continue;\n        }\n        dfs(x, curr);\n    }\n}\n\nvector<int>\
    \ depth;\n\n// \u30B9\u30BF\u30FC\u30C8\u3092\u57FA\u6E96\u3068\u3059\u308B\u4ED6\
    \u306E\u9802\u70B9\u306E\u6DF1\u3055\u3092\u6C42\u3081\u307E\u3059 (\u30B0\u30E9\
    \u30D5\u304C\u6728\u3067\u306A\u3044\u3068\u4F7F\u3048\u306A\u3044) : O(N)\ntemplate\
    \ <typename T>\nvoid getDepth(T curr, T prev = -1) {\n    if(prev == -1){\n  \
    \      depth[curr] = 0;\n    }\n \n    for(auto x : G[curr]){\n        if(x ==\
    \ prev){\n            continue;\n        }\n        depth[x] = depth[curr] + 1;\n\
    \        getDepth(x, curr);\n    }\n    return;\n}\n\n// example\nint main(){\n\
    \    cin >> n;\n    G = vector<vector<int>>(n);\n\n    for(int i = 0; i < n -\
    \ 1; i++){\n        int a, b;\n        cin >> a >> b;\n        a--, b--;\n   \
    \     G[a].push_back(b);\n        G[b].push_back(a);\n    }\n    dfs(0, -1);\n\
    \    return;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/dfs.cpp
  requiredBy: []
  timestamp: '2022-09-04 03:09:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/dfs.cpp
layout: document
redirect_from:
- /library/lib/graph/dfs.cpp
- /library/lib/graph/dfs.cpp.html
title: lib/graph/dfs.cpp
---
