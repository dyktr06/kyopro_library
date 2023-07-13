---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/combination.hpp
    title: "Combination (\u4E8C\u9805\u4FC2\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/117
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "#line 1 \"test/yukicoder/yuki_117.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/117\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/combination.hpp\"\
    \n\n/**\n * @brief Combination (\u4E8C\u9805\u4FC2\u6570)\n * @docs docs/math/combination.md\n\
    \ */\n\nstruct Combination{\n    vector<long long> memo, memoinv, inv;\n    const\
    \ long long mod;\n    Combination(const int &N, const long long &m) : memo(N +\
    \ 1), memoinv(N + 1), inv(N + 1), mod(m){\n        memo[0] = memo[1] = 1;\n  \
    \      memoinv[0] = memoinv[1] = 1;\n        inv[1] = 1;\n        for(int i =\
    \ 2; i <= N; ++i){\n            memo[i] = memo[i - 1] * i % mod;\n           \
    \ inv[i] = mod - inv[mod % i] * (m / i) % mod;\n            memoinv[i] = memoinv[i\
    \ - 1] * inv[i] % mod;\n        }\n    }\n    inline long long fact(const long\
    \ long &n) const {\n        return memo[n];\n    }\n    inline long long factinv(const\
    \ long long &n) const {\n        return memoinv[n];\n    }\n    inline long long\
    \ ncr(const long long &n, const long long &r) const {\n        if(n < r || r <\
    \ 0) return 0;\n        return (memo[n] * memoinv[r] % mod) * memoinv[n - r] %\
    \ mod;\n    }\n    inline long long npr(const long long &n, const long long &r)\
    \ const {\n        if(n < r || r < 0) return 0;\n        return (memo[n] % mod)\
    \ * memoinv[n - r] % mod;\n    }\n    inline long long nhr(const long long &n,\
    \ const long long &r) const {\n        if(n == 0 && r == 0) return 1;\n      \
    \  return ncr(n + r - 1, r);\n    }\n};\n\nstruct CombinationByPascal{\n    vector<vector<long\
    \ long>> memo;\n    const long long mod;\n    CombinationByPascal(const int &N,\
    \ const long long &m) : mod(m){\n        memo.assign(N + 1, vector<long long>(N\
    \ + 1));\n        memo[0][0] = 1;\n        for(int i = 1; i <= N; ++i){\n    \
    \        memo[i][0] = 1;\n            for(int j = 1; j <= N; ++j){\n         \
    \       memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j]);\n                if(memo[i][j]\
    \ >= mod) memo[i][j] -= mod;\n            }\n        }\n    }\n    inline long\
    \ long ncr(const int &n, const int &r) const {\n        if(n < r || r < 0) return\
    \ 0;\n        return memo[n][r];\n    }\n};\n#line 6 \"test/yukicoder/yuki_117.test.cpp\"\
    \n\nconst long long MOD = 1000000007;\n\nint main(){\n    int t; cin >> t;\n \
    \   Combination comb(2000000, MOD);\n\n    while(t--){\n        char s[10];\n\
    \        int n, k;\n        scanf(\"%1s(%d,%d)\", s, &n, &k);\n\t\tlong long ans\
    \ = 0;\n\t\tif(s[0] == 'C') ans = comb.ncr(n, k);\n\t\telse if(s[0] == 'P') ans\
    \ = comb.npr(n, k);\n\t\telse if(s[0] == 'H') ans = comb.nhr(n, k);\n\t\tcout\
    \ << ans << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/117\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../lib/math/combination.hpp\"\n\nconst long\
    \ long MOD = 1000000007;\n\nint main(){\n    int t; cin >> t;\n    Combination\
    \ comb(2000000, MOD);\n\n    while(t--){\n        char s[10];\n        int n,\
    \ k;\n        scanf(\"%1s(%d,%d)\", s, &n, &k);\n\t\tlong long ans = 0;\n\t\t\
    if(s[0] == 'C') ans = comb.ncr(n, k);\n\t\telse if(s[0] == 'P') ans = comb.npr(n,\
    \ k);\n\t\telse if(s[0] == 'H') ans = comb.nhr(n, k);\n\t\tcout << ans << endl;\n\
    \    }\n}"
  dependsOn:
  - lib/math/combination.hpp
  isVerificationFile: true
  path: test/yukicoder/yuki_117.test.cpp
  requiredBy: []
  timestamp: '2023-07-14 01:49:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/yuki_117.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki_117.test.cpp
- /verify/test/yukicoder/yuki_117.test.cpp.html
title: test/yukicoder/yuki_117.test.cpp
---
