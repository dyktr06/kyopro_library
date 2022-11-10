---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/dp/substring.hpp
    title: lib/dp/substring.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_subsequences
    links:
    - https://judge.yosupo.jp/problem/number_of_subsequences
  bundledCode: "#line 1 \"test/library_checker/dp/number_of_subsequences.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/dp/substring.hpp\"\
    \n\n/*\n    \u6587\u5B57\u5217 s \u306B\u304A\u3051\u308B\u3001\u9023\u7D9A\u3057\
    \u306A\u3044\u90E8\u5206\u6587\u5B57\u5217\u306E\u7A2E\u985E\u3092 m \u3067\u5272\
    \u3063\u305F\u4F59\u308A\u3092\u8FD4\u3057\u307E\u3059\u3002(\u7A7A\u6587\u5B57\
    \u5217\u3092\u542B\u3080) O(|S|)\n*/\nlong long substrings(const string &s, const\
    \ long long &m){\n    int n = (int) s.size();\n\n    vector<vector<int>> next(n\
    \ + 1, vector<int>(26, n));\n    for(int i = n - 1; i >= 0; i--){\n        next[i]\
    \ = next[i + 1];\n        next[i][s[i] - 'a'] = i;\n    }\n\n    vector<long long>\
    \ dp(n + 1, 0);\n    dp[0] = 1;\n    for(int i = 0; i < n; ++i){\n        for(int\
    \ j = 0; j < 26; ++j){\n            if(next[i][j] >= n) continue;\n          \
    \  dp[next[i][j] + 1] += dp[i];\n            dp[next[i][j] + 1] %= m;\n      \
    \  }\n    }\n\n    long long res = 0;\n    for(int i = 0; i <= n; ++i){\n    \
    \    res += dp[i]; res %= m;\n    }\n    return res;\n}\n\n/*\n    s \u306B\u304A\
    \u3051\u308B\u3001\u9023\u7D9A\u3057\u306A\u3044\u90E8\u5206\u6587\u5B57\u5217\
    \u306E\u7A2E\u985E\u3092 m \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u8FD4\u3057\
    \u307E\u3059\u3002O(|S| log |S|)\n*/\ntemplate <typename T>\nlong long subsequences(const\
    \ vector<T> &s, const long long &m){\n    int n = (int) s.size();\n    map<T,\
    \ int> mp;\n    vector<long long> dp(n + 1);\n    dp[0] = 1;\n    for(int i =\
    \ 0; i < n; i++){\n        if(mp.count(s[i]) != 0){\n            dp[i + 1] = dp[i]\
    \ * 2 + m - dp[mp[s[i]]];\n        }else{\n            dp[i + 1] = dp[i] * 2;\n\
    \        }\n        dp[i + 1] %= m;\n        mp[s[i]] = i; \n    }\n    return\
    \ dp[n];\n}\n#line 6 \"test/library_checker/dp/number_of_subsequences.test.cpp\"\
    \n\nconstexpr long long MOD = 998244353;\n\nint main(){\n    int n; cin >> n;\n\
    \    vector<int> a(n);\n    for(int i = 0; i < n; i++){\n        cin >> a[i];\n\
    \    }\n    long long ans = subsequences(a, MOD) + MOD - 1;\n    ans %= MOD;\n\
    \    cout << ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/dp/substring.hpp\"\
    \n\nconstexpr long long MOD = 998244353;\n\nint main(){\n    int n; cin >> n;\n\
    \    vector<int> a(n);\n    for(int i = 0; i < n; i++){\n        cin >> a[i];\n\
    \    }\n    long long ans = subsequences(a, MOD) + MOD - 1;\n    ans %= MOD;\n\
    \    cout << ans << \"\\n\";\n}"
  dependsOn:
  - lib/dp/substring.hpp
  isVerificationFile: true
  path: test/library_checker/dp/number_of_subsequences.test.cpp
  requiredBy: []
  timestamp: '2022-11-11 04:34:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/dp/number_of_subsequences.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/dp/number_of_subsequences.test.cpp
- /verify/test/library_checker/dp/number_of_subsequences.test.cpp.html
title: test/library_checker/dp/number_of_subsequences.test.cpp
---
