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
  bundledCode: "#line 1 \"lib/graph/warshall_floyd.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nconst long long INF = 0x1fffffffffffffff;\n\nint n,\
    \ m;\nvector<vector<long long>> d;\n\n// \u30EF\u2015\u30B7\u30E3\u30EB\u30D5\u30ED\
    \u30A4\u30C9\u6CD5\u3067\u5168\u9802\u70B9\u9593\u306E\u6700\u77ED\u8DDD\u96E2\
    \u3092\u6C42\u3081\u307E\u3059 : (O(n^3))\ntemplate <typename T>\nvoid warshall_floyd(T\
    \ n) { // n\u306F\u9802\u70B9\u6570\n    for(int i = 0; i < n; i++)          //\
    \ \u7D4C\u7531\u3059\u308B\u9802\u70B9\n        for(int j = 0; j < n; j++)   \
    \   // \u958B\u59CB\u9802\u70B9\n            for(int k = 0; k < n; k++)  // \u7D42\
    \u7AEF\n                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);\n}\n\n// example\n\
    int main(){\n    cin >> n >> m;\n    d = vector<vector<long long>>(n, vector<long\
    \ long>(n, INF));\n\n    for(int i = 0; i < m; i++){\n        int a, b, c;\n \
    \       cin >> a >> b >> c;\n        a--, b--;\n        d[a][b] = c;\n       \
    \ d[b][a] = c;\n    }\n    return;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nconst long long INF =\
    \ 0x1fffffffffffffff;\n\nint n, m;\nvector<vector<long long>> d;\n\n// \u30EF\u2015\
    \u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\u3067\u5168\u9802\u70B9\u9593\
    \u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u307E\u3059 : (O(n^3))\ntemplate\
    \ <typename T>\nvoid warshall_floyd(T n) { // n\u306F\u9802\u70B9\u6570\n    for(int\
    \ i = 0; i < n; i++)          // \u7D4C\u7531\u3059\u308B\u9802\u70B9\n      \
    \  for(int j = 0; j < n; j++)      // \u958B\u59CB\u9802\u70B9\n            for(int\
    \ k = 0; k < n; k++)  // \u7D42\u7AEF\n                d[j][k] = min(d[j][k],\
    \ d[j][i] + d[i][k]);\n}\n\n// example\nint main(){\n    cin >> n >> m;\n    d\
    \ = vector<vector<long long>>(n, vector<long long>(n, INF));\n\n    for(int i\
    \ = 0; i < m; i++){\n        int a, b, c;\n        cin >> a >> b >> c;\n     \
    \   a--, b--;\n        d[a][b] = c;\n        d[b][a] = c;\n    }\n    return;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/warshall_floyd.cpp
  requiredBy: []
  timestamp: '2022-08-24 06:05:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/warshall_floyd.cpp
layout: document
redirect_from:
- /library/lib/graph/warshall_floyd.cpp
- /library/lib/graph/warshall_floyd.cpp.html
title: lib/graph/warshall_floyd.cpp
---
