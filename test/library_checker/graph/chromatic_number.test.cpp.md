---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/chromatic_number.hpp
    title: lib/graph/chromatic_number.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"test/library_checker/graph/chromatic_number.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/chromatic_number.hpp\"\
    \n\nint chromaticNumber(vector<vector<int>> &G) {\n    int n = G.size();\n   \
    \ vector<int> adj(n);\n    for(int i = 0; i < n; i++){\n        for(auto &j :\
    \ G[i]){\n            adj[i] |= 1 << j;\n        }\n    }\n\n    // dp[S] ...\
    \ S \u306E\u90E8\u5206\u96C6\u5408\u3067\u72EC\u7ACB\u306A\u3082\u306E\u306E\u500B\
    \u6570\n    vector<int> dp(1 << n, 0);\n    dp[0] = 1;\n    for(int S = 1; S <\
    \ (1 << n); S++){\n        int i = __builtin_ctz(S);\n        dp[S] = dp[S ^ (1\
    \ << i)] + dp[(S ^ (1 << i)) & (~adj[i])];\n    }\n\n    // \u5305\u9664\u539F\
    \u7406 (https://www.slideshare.net/wata_orz/ss-12131479)\n    vector<int> cnt((1\
    \ << n) + 1, 0);\n    for(int S = 0; S < (1 << n); S++){\n        cnt[dp[S]] +=\
    \ __builtin_parity(S) ? 1 : -1;\n    }\n\n    vector<pair<long long, long long>>\
    \ f;\n    for(int i = 0; i <= (1 << n); i++){\n        if(cnt[i] != 0){\n    \
    \        f.emplace_back(i, cnt[i]);\n        }\n    }\n\n    int ans = n;\n  \
    \  constexpr long long MODS[] = {1000000007, 1000000009, 1000000021};\n    for(int\
    \ i = 0; i < 3; i++){\n        auto nf = f;\n        for(int k = 1; k <= n; k++){\n\
    \            if(ans <= k) break;\n            // k \u5F69\u8272\u3059\u308B\u901A\
    \u308A\u6570\n            long long sum = 0;\n            for(auto &[x, y] : nf){\n\
    \                sum += (y = y * x % MODS[i]);\n                sum %= MODS[i];\n\
    \            }\n            if(sum != 0) ans = min(ans, k);\n        }\n    }\n\
    \    return ans;\n}\n#line 6 \"test/library_checker/graph/chromatic_number.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    int n, m; cin >> n >> m;\n    vector<vector<int>> G(n);\n    for(int i =\
    \ 0; i < m; i++) {\n        int u, v; cin >> u >> v;\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n    cout << chromaticNumber(G) << '\\n';\n\
    }\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/chromatic_number.hpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    int n, m; cin >> n >> m;\n    vector<vector<int>> G(n);\n    for(int i =\
    \ 0; i < m; i++) {\n        int u, v; cin >> u >> v;\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n    cout << chromaticNumber(G) << '\\n';\n\
    }\n\n"
  dependsOn:
  - lib/graph/chromatic_number.hpp
  isVerificationFile: true
  path: test/library_checker/graph/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2024-10-21 04:45:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/chromatic_number.test.cpp
- /verify/test/library_checker/graph/chromatic_number.test.cpp.html
title: test/library_checker/graph/chromatic_number.test.cpp
---
