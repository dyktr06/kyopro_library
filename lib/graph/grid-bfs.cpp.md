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
  bundledCode: "#line 1 \"lib/graph/grid-bfs.cpp\"\n#include <bits/stdc++.h>\n \n\
    using namespace std;\n\nvector<int> dx = {0, 1, 0, -1};\nvector<int> dy = {1,\
    \ 0, -1, 0};\n\n// \u4E8C\u6B21\u5143\u30B0\u30EA\u30C3\u30C9\u4E0A\u3067\u3001\
    \u30B9\u30BF\u30FC\u30C8\u304B\u3089\u5404\u30DE\u30B9\u3078\u306E\u6700\u77ED\
    \u8DDD\u96E2\u3092\u6C42\u3081\u307E\u3059 : O(HW)\n// '.' -> \u79FB\u52D5\u53EF\
    \u80FD\u3001'#' -> \u79FB\u52D5\u4E0D\u53EF\nvector<vector<int>> bfs(const vector<string>\
    \ &s, int sx = 0, int sy = 0){\n    int h = s.size(), w = s[0].size();\n    deque<tuple<int,\
    \ int, int>> dq;\n    dq.push_back(make_tuple(0, sx, sy));\n    vector<vector<int>>\
    \ d(h, vector<int>(w, -1));\n    while (!dq.empty()){\n        int dd = get<0>(dq.front());\n\
    \        int x = get<1>(dq.front());\n        int y = get<2>(dq.front());\n  \
    \      dq.pop_front();\n        if(d[x][y] == -1){\n            d[x][y] = dd;\n\
    \            for(int i = 0; i < 4; i++){\n                int x2 = x + dx[i];\n\
    \                int y2 = y + dy[i];\n                if(0 <= x2 && x2 < h &&\
    \ 0 <= y2 && y2 < w){\n                    if(s[x2][y2] == '.'){\n           \
    \             // \u512A\u5148\u7684\u306B\u898B\u308B\u304B\u3069\u3046\u304B\u3067\
    \u524D\u306B\u5165\u308C\u308B\u304B\u5F8C\u308D\u306B\u5165\u308C\u308B\u304B\
    \u3092\u6C7A\u3081\u308B\n                        dq.push_back(make_tuple(dd +\
    \ 1, x2, y2));\n                    }\n                }\n            }\n    \
    \    }\n    }\n    return d;\n}\n\n// example\nint main(){\n    int h, w;\n  \
    \  cin >> h >> w;\n    vector<string> s(h);\n    for(int i = 0; i < h; i++){\n\
    \        cin >> s[i];\n    }\n    vector<vector<int>> ans = bfs(s, 0, 0);\n  \
    \  cout << ans[h - 1][w - 1] << \"\\n\";\n}\n"
  code: "#include <bits/stdc++.h>\n \nusing namespace std;\n\nvector<int> dx = {0,\
    \ 1, 0, -1};\nvector<int> dy = {1, 0, -1, 0};\n\n// \u4E8C\u6B21\u5143\u30B0\u30EA\
    \u30C3\u30C9\u4E0A\u3067\u3001\u30B9\u30BF\u30FC\u30C8\u304B\u3089\u5404\u30DE\
    \u30B9\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u307E\u3059 : O(HW)\n\
    // '.' -> \u79FB\u52D5\u53EF\u80FD\u3001'#' -> \u79FB\u52D5\u4E0D\u53EF\nvector<vector<int>>\
    \ bfs(const vector<string> &s, int sx = 0, int sy = 0){\n    int h = s.size(),\
    \ w = s[0].size();\n    deque<tuple<int, int, int>> dq;\n    dq.push_back(make_tuple(0,\
    \ sx, sy));\n    vector<vector<int>> d(h, vector<int>(w, -1));\n    while (!dq.empty()){\n\
    \        int dd = get<0>(dq.front());\n        int x = get<1>(dq.front());\n \
    \       int y = get<2>(dq.front());\n        dq.pop_front();\n        if(d[x][y]\
    \ == -1){\n            d[x][y] = dd;\n            for(int i = 0; i < 4; i++){\n\
    \                int x2 = x + dx[i];\n                int y2 = y + dy[i];\n  \
    \              if(0 <= x2 && x2 < h && 0 <= y2 && y2 < w){\n                 \
    \   if(s[x2][y2] == '.'){\n                        // \u512A\u5148\u7684\u306B\
    \u898B\u308B\u304B\u3069\u3046\u304B\u3067\u524D\u306B\u5165\u308C\u308B\u304B\
    \u5F8C\u308D\u306B\u5165\u308C\u308B\u304B\u3092\u6C7A\u3081\u308B\n         \
    \               dq.push_back(make_tuple(dd + 1, x2, y2));\n                  \
    \  }\n                }\n            }\n        }\n    }\n    return d;\n}\n\n\
    // example\nint main(){\n    int h, w;\n    cin >> h >> w;\n    vector<string>\
    \ s(h);\n    for(int i = 0; i < h; i++){\n        cin >> s[i];\n    }\n    vector<vector<int>>\
    \ ans = bfs(s, 0, 0);\n    cout << ans[h - 1][w - 1] << \"\\n\";\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/grid-bfs.cpp
  requiredBy: []
  timestamp: '2022-11-10 01:38:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/grid-bfs.cpp
layout: document
redirect_from:
- /library/lib/graph/grid-bfs.cpp
- /library/lib/graph/grid-bfs.cpp.html
title: lib/graph/grid-bfs.cpp
---
