---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/graph/warshall_floyd.hpp
    title: lib/graph/warshall_floyd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/aoj/grl/grl_1_c.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/warshall_floyd.hpp\"\
    \n\n// \u30EF\u2015\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\u3067\u5168\
    \u9802\u70B9\u9593\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u307E\u3059\
    \ : (O(n^3))\ntemplate <typename T>\nvoid warshall_floyd(vector<vector<T>> &d,\
    \ int n) { // n\u306F\u9802\u70B9\u6570\n    for(int i = 0; i < n; i++)      \
    \    // \u7D4C\u7531\u3059\u308B\u9802\u70B9\n        for(int j = 0; j < n; j++)\
    \      // \u958B\u59CB\u9802\u70B9\n            for(int k = 0; k < n; k++)  //\
    \ \u7D42\u7AEF\n                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);\n}\n\
    #line 6 \"test/aoj/grl/grl_1_c.test.cpp\"\n\nconst long long INF = 0x1fffffffffffffff;\n\
    \nint main(){\n    int n, m; cin >> n >> m;\n    vector<vector<long long>> d(n,\
    \ vector<long long>(n, INF));\n\n    for(int i = 0; i < n; i++){\n        d[i][i]\
    \ = 0;\n    }\n    for(int i = 0; i < m; i++){\n        int a, b, c;\n       \
    \ cin >> a >> b >> c;\n        d[a][b] = c;\n    }\n\n    warshall_floyd(d, n);\n\
    \    for(int i = 0; i < n; i++){\n        for(int j = 0; j < n; j++){\n      \
    \      if(j >= 1) cout << \" \";\n            if(d[i][j] == INF){\n          \
    \      cout << \"INF\";\n            }else{\n                cout << d[i][j];\n\
    \            }\n        }\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/warshall_floyd.hpp\"\
    \n\nconst long long INF = 0x1fffffffffffffff;\n\nint main(){\n    int n, m; cin\
    \ >> n >> m;\n    vector<vector<long long>> d(n, vector<long long>(n, INF));\n\
    \n    for(int i = 0; i < n; i++){\n        d[i][i] = 0;\n    }\n    for(int i\
    \ = 0; i < m; i++){\n        int a, b, c;\n        cin >> a >> b >> c;\n     \
    \   d[a][b] = c;\n    }\n\n    warshall_floyd(d, n);\n    for(int i = 0; i < n;\
    \ i++){\n        for(int j = 0; j < n; j++){\n            if(j >= 1) cout << \"\
    \ \";\n            if(d[i][j] == INF){\n                cout << \"INF\";\n   \
    \         }else{\n                cout << d[i][j];\n            }\n        }\n\
    \        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/graph/warshall_floyd.hpp
  isVerificationFile: true
  path: test/aoj/grl/grl_1_c.test.cpp
  requiredBy: []
  timestamp: '2022-11-11 03:58:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/grl/grl_1_c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/grl_1_c.test.cpp
- /verify/test/aoj/grl/grl_1_c.test.cpp.html
title: test/aoj/grl/grl_1_c.test.cpp
---
