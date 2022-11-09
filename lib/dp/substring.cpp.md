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
  bundledCode: "#line 1 \"lib/dp/substring.cpp\"\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\n// |S| \u306B\u304A\u3051\u308B\u3001\u9023\u7D9A\u3057\u306A\
    \u3044\u90E8\u5206\u6587\u5B57\u5217\u306E\u7A2E\u985E\u3092 m \u3067\u5272\u3063\
    \u305F\u4F59\u308A\u3092\u8FD4\u3057\u307E\u3059\u3002O(|S|)\nlong long substring(const\
    \ string &s, long long m){\n    int n = (int) s.size();\n\n    vector<vector<int>>\
    \ next(n + 1, vector<int>(26, n));\n    for(int i = n - 1; i >= 0; i--){\n   \
    \     next[i] = next[i + 1];\n        next[i][s[i] - 'a'] = i;\n    }\n\n    vector<long\
    \ long> dp(n + 1, 0);\n    dp[0] = 1;\n    for(int i = 0; i < n; ++i){\n     \
    \   for(int j = 0; j < 26; ++j){\n            if(next[i][j] >= n) continue;\n\
    \            dp[next[i][j] + 1] += dp[i];\n            dp[next[i][j] + 1] %= m;\n\
    \        }\n    }\n\n    long long res = 0;\n    for(int i = 0; i <= n; ++i){\n\
    \        res += dp[i]; res %= m;\n    }\n    return res;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// |S| \u306B\u304A\u3051\
    \u308B\u3001\u9023\u7D9A\u3057\u306A\u3044\u90E8\u5206\u6587\u5B57\u5217\u306E\
    \u7A2E\u985E\u3092 m \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u8FD4\u3057\u307E\
    \u3059\u3002O(|S|)\nlong long substring(const string &s, long long m){\n    int\
    \ n = (int) s.size();\n\n    vector<vector<int>> next(n + 1, vector<int>(26, n));\n\
    \    for(int i = n - 1; i >= 0; i--){\n        next[i] = next[i + 1];\n      \
    \  next[i][s[i] - 'a'] = i;\n    }\n\n    vector<long long> dp(n + 1, 0);\n  \
    \  dp[0] = 1;\n    for(int i = 0; i < n; ++i){\n        for(int j = 0; j < 26;\
    \ ++j){\n            if(next[i][j] >= n) continue;\n            dp[next[i][j]\
    \ + 1] += dp[i];\n            dp[next[i][j] + 1] %= m;\n        }\n    }\n\n \
    \   long long res = 0;\n    for(int i = 0; i <= n; ++i){\n        res += dp[i];\
    \ res %= m;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/dp/substring.cpp
  requiredBy: []
  timestamp: '2022-09-23 04:24:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/dp/substring.cpp
layout: document
redirect_from:
- /library/lib/dp/substring.cpp
- /library/lib/dp/substring.cpp.html
title: lib/dp/substring.cpp
---
