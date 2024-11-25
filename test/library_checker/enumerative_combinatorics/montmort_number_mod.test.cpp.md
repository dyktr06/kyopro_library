---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/enumerative_combinatorics/montmort_number.hpp
    title: "Montmort Number (\u30E2\u30F3\u30E2\u30FC\u30EB\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/montmort_number_mod
    links:
    - https://judge.yosupo.jp/problem/montmort_number_mod
  bundledCode: "#line 1 \"test/library_checker/enumerative_combinatorics/montmort_number_mod.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/montmort_number_mod\"\n#include\
    \ <iostream>\n\n#line 2 \"lib/enumerative_combinatorics/montmort_number.hpp\"\n\
    \n/**\n * @brief Montmort Number (\u30E2\u30F3\u30E2\u30FC\u30EB\u6570)\n */\n\
    \n#include <vector>\n#include <cassert>\n\nstd::vector<long long> montmortNumber(const\
    \ int n, const int m){\n    // n \u756A\u76EE\u306B\u7F6E\u304F\u5024\u306F 1\
    \ - n - 1\n    // i \u3092\u7F6E\u3044\u305F\u3068\u3057\u3066\u3001i \u756A\u76EE\
    \u304C n \u304B\u3069\u3046\u304B\u3067\u5834\u5408\u5206\u3051\n    // i \u756A\
    \u76EE\u304C n -> dp_{n - 2} \u901A\u308A\n    // i \u756A\u76EE\u304C n \u3067\
    \u306A\u3044 -> dp_{n - 1} \u901A\u308A\n    // dp_n = (n - 1) * (dp_{n - 1} +\
    \ dp_{n - 2}) \u3092\u5F97\u308B\n    assert(n >= 1);\n    if(n == 1) return {0,\
    \ 1 % m};\n    std::vector<long long> dp(n + 1);\n    dp[1] = 0;\n    dp[2] =\
    \ 1 % m;\n    for(int i = 3; i <= n; i++){\n        dp[i] = dp[i - 1] + dp[i -\
    \ 2];\n        (dp[i] *= i - 1) %= m;\n    }\n    return dp;\n}\n#line 5 \"test/library_checker/enumerative_combinatorics/montmort_number_mod.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n\n    int n, m; cin >> n >> m;\n    auto res = montmortNumber(n,\
    \ m);\n    for(int i = 1; i <= n; i++){\n        cout << res[i] << (i == n ? '\\\
    n' : ' ');\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/montmort_number_mod\"\n\
    #include <iostream>\n\n#include \"../../../lib/enumerative_combinatorics/montmort_number.hpp\"\
    \n\nusing namespace std;\n\nint main(){\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n\n    int n, m; cin >> n >> m;\n    auto res = montmortNumber(n,\
    \ m);\n    for(int i = 1; i <= n; i++){\n        cout << res[i] << (i == n ? '\\\
    n' : ' ');\n    }\n}\n"
  dependsOn:
  - lib/enumerative_combinatorics/montmort_number.hpp
  isVerificationFile: true
  path: test/library_checker/enumerative_combinatorics/montmort_number_mod.test.cpp
  requiredBy: []
  timestamp: '2024-11-25 16:56:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/enumerative_combinatorics/montmort_number_mod.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/enumerative_combinatorics/montmort_number_mod.test.cpp
- /verify/test/library_checker/enumerative_combinatorics/montmort_number_mod.test.cpp.html
title: test/library_checker/enumerative_combinatorics/montmort_number_mod.test.cpp
---
