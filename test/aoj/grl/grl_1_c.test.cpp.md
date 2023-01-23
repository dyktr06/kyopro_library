---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/warshall_floyd.hpp
    title: "Floyd-Warshall Algorithm (\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\
      \u30C9\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/aoj/grl/grl_1_c.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/warshall_floyd.hpp\"\
    \n\n/**\n * @brief Floyd-Warshall Algorithm (\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\
    \u30ED\u30A4\u30C9\u6CD5)\n * @docs docs/graph/warshall_floyd.md\n */\n\ntemplate\
    \ <typename T>\nvoid warshall_floyd(vector<vector<T>> &d, const T &INF) {\n  \
    \  int n = d.size();\n    for(int i = 0; i < n; i++){\n        for(int j = 0;\
    \ j < n; j++){\n            for(int k = 0; k < n; k++){\n                if(d[j][i]\
    \ == INF || d[i][k] == INF) continue;\n                d[j][k] = min(d[j][k],\
    \ d[j][i] + d[i][k]);\n            }\n        }\n    }\n}\n#line 6 \"test/aoj/grl/grl_1_c.test.cpp\"\
    \n\nconst long long INF = 0x1fffffffffffffff;\n\nint main(){\n    int n, m; cin\
    \ >> n >> m;\n    vector<vector<long long>> d(n, vector<long long>(n, INF));\n\
    \n    for(int i = 0; i < n; i++){\n        d[i][i] = 0;\n    }\n    for(int i\
    \ = 0; i < m; i++){\n        int a, b, c;\n        cin >> a >> b >> c;\n     \
    \   d[a][b] = c;\n    }\n\n    warshall_floyd(d, INF);\n    for(int i = 0; i <\
    \ n; i++){\n        if(d[i][i] < 0){\n            cout << \"NEGATIVE CYCLE\" <<\
    \ \"\\n\";\n            return 0;\n        }\n    }\n    for(int i = 0; i < n;\
    \ i++){\n        for(int j = 0; j < n; j++){\n            if(j >= 1) cout << \"\
    \ \";\n            if(d[i][j] == INF){\n                cout << \"INF\";\n   \
    \         }else{\n                cout << d[i][j];\n            }\n        }\n\
    \        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/warshall_floyd.hpp\"\
    \n\nconst long long INF = 0x1fffffffffffffff;\n\nint main(){\n    int n, m; cin\
    \ >> n >> m;\n    vector<vector<long long>> d(n, vector<long long>(n, INF));\n\
    \n    for(int i = 0; i < n; i++){\n        d[i][i] = 0;\n    }\n    for(int i\
    \ = 0; i < m; i++){\n        int a, b, c;\n        cin >> a >> b >> c;\n     \
    \   d[a][b] = c;\n    }\n\n    warshall_floyd(d, INF);\n    for(int i = 0; i <\
    \ n; i++){\n        if(d[i][i] < 0){\n            cout << \"NEGATIVE CYCLE\" <<\
    \ \"\\n\";\n            return 0;\n        }\n    }\n    for(int i = 0; i < n;\
    \ i++){\n        for(int j = 0; j < n; j++){\n            if(j >= 1) cout << \"\
    \ \";\n            if(d[i][j] == INF){\n                cout << \"INF\";\n   \
    \         }else{\n                cout << d[i][j];\n            }\n        }\n\
    \        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/graph/warshall_floyd.hpp
  isVerificationFile: true
  path: test/aoj/grl/grl_1_c.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 11:19:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl/grl_1_c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/grl_1_c.test.cpp
- /verify/test/aoj/grl/grl_1_c.test.cpp.html
title: test/aoj/grl/grl_1_c.test.cpp
---
