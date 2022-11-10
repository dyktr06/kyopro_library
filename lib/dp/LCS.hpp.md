---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1_10_c.test.cpp
    title: test/aoj/alds1/alds1_10_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/dp/LCS.hpp\"\n\n// \u6587\u5B57\u5217 s \u3068\u6587\
    \u5B57\u5217 t \u306E\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\u3092\u6C42\u3081\
    \u307E\u3059 : O(|s||t|)\nstring LCS(const string &s, const string &t){\n    int\
    \ n = s.size(), m = t.size();\n    vector<vector<int>> memo(n + 1, vector<int>(m\
    \ + 1));\n    for(int i = 0; i < n; i++){\n        for(int j = 0; j < m; j++){\n\
    \            if(s[i] == t[j]){\n                memo[i + 1][j + 1] = memo[i][j]\
    \ + 1;\n            }else{\n                memo[i + 1][j + 1] = max(memo[i][j\
    \ + 1], memo[i + 1][j]);\n            }\n        }\n    }\n\n    // \u5FA9\u5143\
    \n    string res = \"\";\n    int i = n - 1, j = m - 1;\n    while(0 <= i && 0\
    \ <= j){\n        if(s[i] == t[j]){\n            res += s[i];\n            i--;\
    \ j--;\n        }else if(memo[i + 1][j + 1] == memo[i][j + 1]){\n            i--;\n\
    \        }else if(memo[i + 1][j + 1] == memo[i + 1][j]){\n            j--;\n \
    \       }\n    }\n    reverse(res.begin(), res.end());\n    return res;\n}\n"
  code: "#pragma once\n\n// \u6587\u5B57\u5217 s \u3068\u6587\u5B57\u5217 t \u306E\
    \u6700\u9577\u5171\u901A\u90E8\u5206\u5217\u3092\u6C42\u3081\u307E\u3059 : O(|s||t|)\n\
    string LCS(const string &s, const string &t){\n    int n = s.size(), m = t.size();\n\
    \    vector<vector<int>> memo(n + 1, vector<int>(m + 1));\n    for(int i = 0;\
    \ i < n; i++){\n        for(int j = 0; j < m; j++){\n            if(s[i] == t[j]){\n\
    \                memo[i + 1][j + 1] = memo[i][j] + 1;\n            }else{\n  \
    \              memo[i + 1][j + 1] = max(memo[i][j + 1], memo[i + 1][j]);\n   \
    \         }\n        }\n    }\n\n    // \u5FA9\u5143\n    string res = \"\";\n\
    \    int i = n - 1, j = m - 1;\n    while(0 <= i && 0 <= j){\n        if(s[i]\
    \ == t[j]){\n            res += s[i];\n            i--; j--;\n        }else if(memo[i\
    \ + 1][j + 1] == memo[i][j + 1]){\n            i--;\n        }else if(memo[i +\
    \ 1][j + 1] == memo[i + 1][j]){\n            j--;\n        }\n    }\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/dp/LCS.hpp
  requiredBy: []
  timestamp: '2022-11-11 04:34:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/alds1/alds1_10_c.test.cpp
documentation_of: lib/dp/LCS.hpp
layout: document
redirect_from:
- /library/lib/dp/LCS.hpp
- /library/lib/dp/LCS.hpp.html
title: lib/dp/LCS.hpp
---
