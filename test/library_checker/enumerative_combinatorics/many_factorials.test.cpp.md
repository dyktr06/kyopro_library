---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/factorial.hpp
    title: lib/math/factorial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_factorials
    links:
    - https://judge.yosupo.jp/problem/many_factorials
  bundledCode: "#line 1 \"test/library_checker/enumerative_combinatorics/many_factorials.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/many_factorials\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/factorial.hpp\"\n\
    \nlong long factorial_998244353(int n){\n    const int BLOCK = 10000000;\n   \
    \ constexpr long long memo[] = {1, 295201906, 160030060, 957629942, 545208507,\
    \ 213689172, 760025067, 939830261, 506268060, 39806322, 808258749, 440133909,\
    \ 686156489, 741797144, 390377694, 12629586, 544711799, 104121967, 495867250,\
    \ 421290700, 117153405, 57084755, 202713771, 675932866, 79781699, 956276337, 652678397,\
    \ 35212756, 655645460, 468129309, 761699708, 533047427, 287671032, 206068022,\
    \ 50865043, 144980423, 111276893, 259415897, 444094191, 593907889, 573994984,\
    \ 892454686, 566073550, 128761001, 888483202, 251718753, 548033568, 428105027,\
    \ 742756734, 546182474, 62402409, 102052166, 826426395, 159186619, 926316039,\
    \ 176055335, 51568171, 414163604, 604947226, 681666415, 511621808, 924112080,\
    \ 265769800, 955559118, 763148293, 472709375, 19536133, 860830935, 290471030,\
    \ 851685235, 242726978, 169855231, 612759169, 599797734, 961628039, 953297493,\
    \ 62806842, 37844313, 909741023, 689361523, 887890124, 380694152, 669317759, 367270918,\
    \ 806951470, 843736533, 377403437, 945260111, 786127243, 80918046, 875880304,\
    \ 364983542, 623250998, 598764068, 804930040, 24257676, 214821357, 791011898,\
    \ 954947696, 183092975};\n    if(n >= 998244353){\n        return 0;\n    }\n\
    \    int d = n / BLOCK;\n    long long res = memo[d];\n    for(int i = d * BLOCK\
    \ + 1; i <= n; ++i){\n        res = res * i % 998244353;\n    }\n    return res;\n\
    }\n\ntemplate <typename T>\nstruct ManyFactorials{\n    const T BLOCK, MOD;\n\
    \    vector<T> memo;\n    ManyFactorials(const T MOD) : BLOCK((T) ((sqrtl(MOD)\
    \ + 49) / 50)), MOD(MOD){\n        setup();\n    }\n\n    void setup(){\n    \
    \    memo = {1};\n        T cur = 1;\n        for(T i = 1; i < MOD; ++i){\n  \
    \          cur = cur * i % MOD;\n            if(i % BLOCK == 0){\n           \
    \     memo.push_back(cur);\n            }\n        }\n    }\n\n    T factorial(T\
    \ n){\n        if(n >= MOD){\n            return 0;\n        }\n        T d =\
    \ n / BLOCK;\n        T res = memo[d];\n        for(T i = d * BLOCK + 1; i <=\
    \ n; ++i){\n            res = res * i % MOD;\n        }\n        return res;\n\
    \    }\n};\n#line 6 \"test/library_checker/enumerative_combinatorics/many_factorials.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   ManyFactorials<long long> fact(998244353LL);\n    int t;\n    cin >> t;\n\
    \    while(t--){\n        int n; cin >> n;\n        cout << fact.factorial(n)\
    \ << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_factorials\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/factorial.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   ManyFactorials<long long> fact(998244353LL);\n    int t;\n    cin >> t;\n\
    \    while(t--){\n        int n; cin >> n;\n        cout << fact.factorial(n)\
    \ << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/math/factorial.hpp
  isVerificationFile: true
  path: test/library_checker/enumerative_combinatorics/many_factorials.test.cpp
  requiredBy: []
  timestamp: '2024-10-21 22:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/enumerative_combinatorics/many_factorials.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/enumerative_combinatorics/many_factorials.test.cpp
- /verify/test/library_checker/enumerative_combinatorics/many_factorials.test.cpp.html
title: test/library_checker/enumerative_combinatorics/many_factorials.test.cpp
---
