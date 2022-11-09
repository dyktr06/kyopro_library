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
  bundledCode: "#line 1 \"lib/graph/bellman_ford.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nint n, m, r;\nvector<array<long long, 3>> E;\n\n// \u30D9\
    \u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5 : O(VE)\ntemplate <typename T>\n\
    vector<long long> bellman_ford(T x){\n    const long long INF = 0x1fffffffffffffff;\n\
    \    vector<long long> cost(n, INF);\n    cost[x] = 0;\n    for(int i = 0; i <\
    \ n - 1; i++){\n        for(auto [from, to, t] : E){\n            if(cost[from]\
    \ == INF) continue;\n            cost[to] = min(cost[to], cost[from] + t);\n \
    \       }\n    }\n    for(auto [from, to, t] : E){\n        if(cost[from] == INF)\
    \ continue;\n        if(cost[from] + t < cost[to]) return vector<long long>();\n\
    \    }\n    return cost;\n}\n\n// example (AOJ GRL_1_B)\nint main(){\n    cin\
    \ >> n >> m >> r;\n    E = vector<array<long long, 3>>();\n\n    for(int i = 0;\
    \ i < m; i++){\n        int a, b, c;\n        cin >> a >> b >> c;\n        //\
    \ a -> b : cost c\n        E.push_back({a, b, c});\n    }\n    \n    vector<long\
    \ long> ans = bellman_ford(r);\n    if(ans.empty()){\n        cout << \"NEGATIVE\
    \ CYCLE\" << \"\\n\";\n    }else{\n        for(int i = 0; i < n; i++){\n     \
    \       if(ans[i] >= 0x1fffffffffffffff){\n                cout << \"INF\" <<\
    \ \"\\n\";\n            }else{\n                cout << ans[i] << \"\\n\";\n \
    \           }\n        }\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\nint n, m, r;\nvector<array<long\
    \ long, 3>> E;\n\n// \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5 :\
    \ O(VE)\ntemplate <typename T>\nvector<long long> bellman_ford(T x){\n    const\
    \ long long INF = 0x1fffffffffffffff;\n    vector<long long> cost(n, INF);\n \
    \   cost[x] = 0;\n    for(int i = 0; i < n - 1; i++){\n        for(auto [from,\
    \ to, t] : E){\n            if(cost[from] == INF) continue;\n            cost[to]\
    \ = min(cost[to], cost[from] + t);\n        }\n    }\n    for(auto [from, to,\
    \ t] : E){\n        if(cost[from] == INF) continue;\n        if(cost[from] + t\
    \ < cost[to]) return vector<long long>();\n    }\n    return cost;\n}\n\n// example\
    \ (AOJ GRL_1_B)\nint main(){\n    cin >> n >> m >> r;\n    E = vector<array<long\
    \ long, 3>>();\n\n    for(int i = 0; i < m; i++){\n        int a, b, c;\n    \
    \    cin >> a >> b >> c;\n        // a -> b : cost c\n        E.push_back({a,\
    \ b, c});\n    }\n    \n    vector<long long> ans = bellman_ford(r);\n    if(ans.empty()){\n\
    \        cout << \"NEGATIVE CYCLE\" << \"\\n\";\n    }else{\n        for(int i\
    \ = 0; i < n; i++){\n            if(ans[i] >= 0x1fffffffffffffff){\n         \
    \       cout << \"INF\" << \"\\n\";\n            }else{\n                cout\
    \ << ans[i] << \"\\n\";\n            }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/bellman_ford.cpp
  requiredBy: []
  timestamp: '2022-09-22 01:58:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/bellman_ford.cpp
layout: document
redirect_from:
- /library/lib/graph/bellman_ford.cpp
- /library/lib/graph/bellman_ford.cpp.html
title: lib/graph/bellman_ford.cpp
---
