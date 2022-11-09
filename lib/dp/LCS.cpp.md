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
  bundledCode: "#line 1 \"lib/dp/LCS.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n// \u6587\u5B57\u5217 s \u3068\u6587\u5B57\u5217 t \u306E\u6700\u9577\
    \u5171\u901A\u90E8\u5206\u5217\u3092\u6C42\u3081\u307E\u3059 : O(|s||t|)\nstring\
    \ LCS(const string &s, const string &t){\n    int n = s.size(), m = t.size();\n\
    \    vector<vector<int>> memo(n + 1, vector<int>(m + 1));\n    for(int i = 0;\
    \ i < n; i++){\n        for(int j = 0; j < m; j++){\n            if(s[i] == t[j]){\n\
    \                memo[i + 1][j + 1] = memo[i][j] + 1;\n            }else{\n  \
    \              memo[i + 1][j + 1] = max(memo[i][j + 1], memo[i + 1][j]);\n   \
    \         }\n        }\n    }\n\n    // \u5FA9\u5143\n    string res = \"\";\n\
    \    int i = n - 1, j = m - 1;\n    while(0 <= i && 0 <= j){\n        if(s[i]\
    \ == t[j]){\n            res += s[i];\n            i--; j--;\n        }else if(memo[i\
    \ + 1][j + 1] == memo[i][j + 1]){\n            i--;\n        }else if(memo[i +\
    \ 1][j + 1] == memo[i + 1][j]){\n            j--;\n        }\n    }\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\n// example (EDPC-F)\nint main(){\n    string\
    \ s, t; cin >> s >> t;\n    cout << LCS(s, t) << \"\\n\";\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// \u6587\u5B57\u5217\
    \ s \u3068\u6587\u5B57\u5217 t \u306E\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\
    \u3092\u6C42\u3081\u307E\u3059 : O(|s||t|)\nstring LCS(const string &s, const\
    \ string &t){\n    int n = s.size(), m = t.size();\n    vector<vector<int>> memo(n\
    \ + 1, vector<int>(m + 1));\n    for(int i = 0; i < n; i++){\n        for(int\
    \ j = 0; j < m; j++){\n            if(s[i] == t[j]){\n                memo[i +\
    \ 1][j + 1] = memo[i][j] + 1;\n            }else{\n                memo[i + 1][j\
    \ + 1] = max(memo[i][j + 1], memo[i + 1][j]);\n            }\n        }\n    }\n\
    \n    // \u5FA9\u5143\n    string res = \"\";\n    int i = n - 1, j = m - 1;\n\
    \    while(0 <= i && 0 <= j){\n        if(s[i] == t[j]){\n            res += s[i];\n\
    \            i--; j--;\n        }else if(memo[i + 1][j + 1] == memo[i][j + 1]){\n\
    \            i--;\n        }else if(memo[i + 1][j + 1] == memo[i + 1][j]){\n \
    \           j--;\n        }\n    }\n    reverse(res.begin(), res.end());\n   \
    \ return res;\n}\n\n// example (EDPC-F)\nint main(){\n    string s, t; cin >>\
    \ s >> t;\n    cout << LCS(s, t) << \"\\n\";\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/dp/LCS.cpp
  requiredBy: []
  timestamp: '2022-09-23 04:24:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dp/LCS.cpp
layout: document
redirect_from:
- /library/lib/dp/LCS.cpp
- /library/lib/dp/LCS.cpp.html
title: lib/dp/LCS.cpp
---
