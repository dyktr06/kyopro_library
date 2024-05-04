---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/dp/substring.hpp
    title: Count Substrings
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_subsequences
    links:
    - https://judge.yosupo.jp/problem/number_of_subsequences
  bundledCode: "#line 1 \"test/library_checker/dp/number_of_subsequences.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/dp/substring.hpp\"\
    \n\n/**\n * @brief Count Substrings\n * @docs docs/dp/substring.md\n */\n\nlong\
    \ long substrings(const string &s, const long long &m){\n    int n = (int) s.size();\n\
    \n    vector<vector<int>> next(n + 1, vector<int>(26, n));\n    for(int i = n\
    \ - 1; i >= 0; i--){\n        next[i] = next[i + 1];\n        next[i][s[i] - 'a']\
    \ = i;\n    }\n\n    vector<long long> dp(n + 1, 0);\n    dp[0] = 1;\n    for(int\
    \ i = 0; i < n; ++i){\n        for(int j = 0; j < 26; ++j){\n            if(next[i][j]\
    \ >= n) continue;\n            dp[next[i][j] + 1] += dp[i];\n            dp[next[i][j]\
    \ + 1] %= m;\n        }\n    }\n\n    long long res = 0;\n    for(int i = 0; i\
    \ <= n; ++i){\n        res += dp[i]; res %= m;\n    }\n    return res;\n}\n\n\
    template <typename T>\nlong long subsequences(const vector<T> &s, const long long\
    \ &m){\n    int n = (int) s.size();\n    map<T, int> mp;\n    vector<long long>\
    \ dp(n + 1);\n    dp[0] = 1;\n    for(int i = 0; i < n; i++){\n        if(mp.count(s[i])\
    \ != 0){\n            dp[i + 1] = dp[i] * 2 + m - dp[mp[s[i]]];\n        } else{\n\
    \            dp[i + 1] = dp[i] * 2;\n        }\n        dp[i + 1] %= m;\n    \
    \    mp[s[i]] = i;\n    }\n    return dp[n];\n}\n#line 6 \"test/library_checker/dp/number_of_subsequences.test.cpp\"\
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
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/dp/number_of_subsequences.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/dp/number_of_subsequences.test.cpp
- /verify/test/library_checker/dp/number_of_subsequences.test.cpp.html
title: test/library_checker/dp/number_of_subsequences.test.cpp
---
