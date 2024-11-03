---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/enumerative_combinatorics/number_of_subsequences.test.cpp
    title: test/library_checker/enumerative_combinatorics/number_of_subsequences.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dp/substring.md
    document_title: Count Substrings
    links: []
  bundledCode: "#line 2 \"lib/dp/substring.hpp\"\n\n/**\n * @brief Count Substrings\n\
    \ * @docs docs/dp/substring.md\n */\n\nlong long substrings(const string &s, const\
    \ long long &m){\n    int n = (int) s.size();\n\n    vector<vector<int>> next(n\
    \ + 1, vector<int>(26, n));\n    for(int i = n - 1; i >= 0; i--){\n        next[i]\
    \ = next[i + 1];\n        next[i][s[i] - 'a'] = i;\n    }\n\n    vector<long long>\
    \ dp(n + 1, 0);\n    dp[0] = 1;\n    for(int i = 0; i < n; ++i){\n        for(int\
    \ j = 0; j < 26; ++j){\n            if(next[i][j] >= n) continue;\n          \
    \  dp[next[i][j] + 1] += dp[i];\n            dp[next[i][j] + 1] %= m;\n      \
    \  }\n    }\n\n    long long res = 0;\n    for(int i = 0; i <= n; ++i){\n    \
    \    res += dp[i]; res %= m;\n    }\n    return res;\n}\n\ntemplate <typename\
    \ T>\nlong long subsequences(const vector<T> &s, const long long &m){\n    int\
    \ n = (int) s.size();\n    map<T, int> mp;\n    vector<long long> dp(n + 1);\n\
    \    dp[0] = 1;\n    for(int i = 0; i < n; i++){\n        if(mp.count(s[i]) !=\
    \ 0){\n            dp[i + 1] = dp[i] * 2 + m - dp[mp[s[i]]];\n        } else{\n\
    \            dp[i + 1] = dp[i] * 2;\n        }\n        dp[i + 1] %= m;\n    \
    \    mp[s[i]] = i;\n    }\n    return dp[n];\n}\n"
  code: "#pragma once\n\n/**\n * @brief Count Substrings\n * @docs docs/dp/substring.md\n\
    \ */\n\nlong long substrings(const string &s, const long long &m){\n    int n\
    \ = (int) s.size();\n\n    vector<vector<int>> next(n + 1, vector<int>(26, n));\n\
    \    for(int i = n - 1; i >= 0; i--){\n        next[i] = next[i + 1];\n      \
    \  next[i][s[i] - 'a'] = i;\n    }\n\n    vector<long long> dp(n + 1, 0);\n  \
    \  dp[0] = 1;\n    for(int i = 0; i < n; ++i){\n        for(int j = 0; j < 26;\
    \ ++j){\n            if(next[i][j] >= n) continue;\n            dp[next[i][j]\
    \ + 1] += dp[i];\n            dp[next[i][j] + 1] %= m;\n        }\n    }\n\n \
    \   long long res = 0;\n    for(int i = 0; i <= n; ++i){\n        res += dp[i];\
    \ res %= m;\n    }\n    return res;\n}\n\ntemplate <typename T>\nlong long subsequences(const\
    \ vector<T> &s, const long long &m){\n    int n = (int) s.size();\n    map<T,\
    \ int> mp;\n    vector<long long> dp(n + 1);\n    dp[0] = 1;\n    for(int i =\
    \ 0; i < n; i++){\n        if(mp.count(s[i]) != 0){\n            dp[i + 1] = dp[i]\
    \ * 2 + m - dp[mp[s[i]]];\n        } else{\n            dp[i + 1] = dp[i] * 2;\n\
    \        }\n        dp[i + 1] %= m;\n        mp[s[i]] = i;\n    }\n    return\
    \ dp[n];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/dp/substring.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/enumerative_combinatorics/number_of_subsequences.test.cpp
documentation_of: lib/dp/substring.hpp
layout: document
redirect_from:
- /library/lib/dp/substring.hpp
- /library/lib/dp/substring.hpp.html
title: Count Substrings
---
## Count Substrings

#### 概要

配列における、連続するとは限らない部分列の種類数を数え上げます。

#### 使い方

- `substrings(s, m)`: 文字列 $s$ における、連続しない部分文字列の種類数を $m$ で割った余りを返します。(空文字列を含む)
- `subsequences(s, m)`: 列 $s$ における、連続するとは限らない部分列の種類数を $m$ で割った余りを返します。

#### 計算量

配列の要素数を $N$ とする。
- `substrings(s, m)`: $\mathrm{O}(N)$
- `subsequences(s, m)`: $\mathrm{O}(N \log N)$