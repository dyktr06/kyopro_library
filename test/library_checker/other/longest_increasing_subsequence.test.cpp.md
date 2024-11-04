---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/dp/LIS.hpp
    title: Longest Increasing Subsequence
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/library_checker/other/longest_increasing_subsequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/dp/LIS.hpp\"\
    \n\n/**\n * @brief Longest Increasing Subsequence\n * @docs docs/dp/LIS.md\n */\n\
    \ntemplate <typename T>\nint LIS(vector<T> a, bool is_strong = true){\n    const\
    \ long long INF = 0x1fffffffffffffff;\n    int n = (int) a.size();\n    vector<long\
    \ long> dp(n, INF);\n    for(int i = 0; i < n; ++i){\n        if(is_strong) *lower_bound(dp.begin(),\
    \ dp.end(), a[i]) = a[i];\n        else *upper_bound(dp.begin(), dp.end(), a[i])\
    \ = a[i];\n    }\n    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n\
    }\n\ntemplate <typename T>\nvector<int> construct_LIS(vector<T> a, bool is_strong\
    \ = true){\n    const long long INF = 0x1fffffffffffffff;\n    int n = (int) a.size();\n\
    \    vector<long long> dp(n, INF);\n    vector<vector<int>> idx(n);\n    for(int\
    \ i = 0; i < n; ++i){\n        if(is_strong){\n            auto iter = lower_bound(dp.begin(),\
    \ dp.end(), a[i]);\n            *iter = a[i];\n            idx[(int) (iter - dp.begin())].emplace_back(i);\n\
    \        } else{\n            auto iter = upper_bound(dp.begin(), dp.end(), a[i]);\n\
    \            *iter = a[i];\n            idx[(int) (iter - dp.begin())].emplace_back(i);\n\
    \        }\n    }\n    int k = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n\
    \    vector<int> res;\n    int now = n;\n    for(int i = k - 1; i >= 0; --i){\n\
    \        auto iter = upper_bound(idx[i].begin(), idx[i].end(), now);\n       \
    \ iter--;\n        now = *iter;\n        res.push_back(now);\n    }\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n#line 6 \"test/library_checker/other/longest_increasing_subsequence.test.cpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    vector<int> a(n);\n    for(int i =\
    \ 0; i < n; i++){\n        cin >> a[i];\n    }\n    vector<int> LIS = construct_LIS(a);\n\
    \    cout << (int) LIS.size() << \"\\n\";\n    for(auto x : LIS){\n        cout\
    \ << x << \" \";\n    }\n    cout << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/dp/LIS.hpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    vector<int> a(n);\n    for(int i =\
    \ 0; i < n; i++){\n        cin >> a[i];\n    }\n    vector<int> LIS = construct_LIS(a);\n\
    \    cout << (int) LIS.size() << \"\\n\";\n    for(auto x : LIS){\n        cout\
    \ << x << \" \";\n    }\n    cout << \"\\n\";\n}"
  dependsOn:
  - lib/dp/LIS.hpp
  isVerificationFile: true
  path: test/library_checker/other/longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2024-11-04 03:12:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/other/longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/other/longest_increasing_subsequence.test.cpp
- /verify/test/library_checker/other/longest_increasing_subsequence.test.cpp.html
title: test/library_checker/other/longest_increasing_subsequence.test.cpp
---
