---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/bellman_ford.hpp
    title: lib/graph/bellman_ford.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/aoj/grl/grl_1_b.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/bellman_ford.hpp\"\
    \n\n// \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5 : O(VE)\ntemplate\
    \ <typename T>\nvector<long long> bellman_ford(vector<T> E, int n, int x){\n \
    \   const long long INF = 0x1fffffffffffffff;\n    vector<long long> cost(n, INF);\n\
    \    cost[x] = 0;\n    for(int i = 0; i < n - 1; i++){\n        for(auto [from,\
    \ to, t] : E){\n            if(cost[from] == INF) continue;\n            cost[to]\
    \ = min(cost[to], cost[from] + t);\n        }\n    }\n    for(auto [from, to,\
    \ t] : E){\n        if(cost[from] == INF) continue;\n        if(cost[from] + t\
    \ < cost[to]) return vector<long long>();\n    }\n    return cost;\n}\n#line 6\
    \ \"test/aoj/grl/grl_1_b.test.cpp\"\n\nint n, m, r;\nvector<array<long long, 3>>\
    \ E;\n\nint main(){\n    cin >> n >> m >> r;\n    E = vector<array<long long,\
    \ 3>>();\n\n    for(int i = 0; i < m; i++){\n        int a, b, c;\n        cin\
    \ >> a >> b >> c;\n        // a -> b : cost c\n        E.push_back({a, b, c});\n\
    \    }\n    \n    vector<long long> ans = bellman_ford(E, n, r);\n    if(ans.empty()){\n\
    \        cout << \"NEGATIVE CYCLE\" << \"\\n\";\n    }else{\n        for(int i\
    \ = 0; i < n; i++){\n            if(ans[i] >= 0x1fffffffffffffff){\n         \
    \       cout << \"INF\" << \"\\n\";\n            }else{\n                cout\
    \ << ans[i] << \"\\n\";\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/bellman_ford.hpp\"\
    \n\nint n, m, r;\nvector<array<long long, 3>> E;\n\nint main(){\n    cin >> n\
    \ >> m >> r;\n    E = vector<array<long long, 3>>();\n\n    for(int i = 0; i <\
    \ m; i++){\n        int a, b, c;\n        cin >> a >> b >> c;\n        // a ->\
    \ b : cost c\n        E.push_back({a, b, c});\n    }\n    \n    vector<long long>\
    \ ans = bellman_ford(E, n, r);\n    if(ans.empty()){\n        cout << \"NEGATIVE\
    \ CYCLE\" << \"\\n\";\n    }else{\n        for(int i = 0; i < n; i++){\n     \
    \       if(ans[i] >= 0x1fffffffffffffff){\n                cout << \"INF\" <<\
    \ \"\\n\";\n            }else{\n                cout << ans[i] << \"\\n\";\n \
    \           }\n        }\n    }\n}"
  dependsOn:
  - lib/graph/bellman_ford.hpp
  isVerificationFile: true
  path: test/aoj/grl/grl_1_b.test.cpp
  requiredBy: []
  timestamp: '2022-11-11 02:51:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl/grl_1_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/grl_1_b.test.cpp
- /verify/test/aoj/grl/grl_1_b.test.cpp.html
title: test/aoj/grl/grl_1_b.test.cpp
---
