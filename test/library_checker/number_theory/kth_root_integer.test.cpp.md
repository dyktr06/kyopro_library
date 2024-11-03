---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/kth_root_integer.hpp
    title: lib/math/kth_root_integer.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_integer
    links:
    - https://judge.yosupo.jp/problem/kth_root_integer
  bundledCode: "#line 1 \"test/library_checker/number_theory/kth_root_integer.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/kth_root_integer.hpp\"\
    \n\nunsigned long long kthRoot(unsigned long long a, unsigned long long k){\n\
    \    unsigned long long tmp = powl(a, (long double) 1 / (long double) k);\n  \
    \  unsigned long long res = 0;\n    vector<unsigned long long> border = {tmp -\
    \ 1, tmp, tmp + 1};\n    for(auto x : border){\n        if(x == 0) continue;\n\
    \        unsigned long long curr = a;\n        for(int i = 0; i < (int) k; i++){\n\
    \            curr /= x;\n        }\n        if(curr >= 1) res = max(res, x);\n\
    \    }\n    return res;\n}\n#line 6 \"test/library_checker/number_theory/kth_root_integer.test.cpp\"\
    \n\nint main(){\n    int T; cin >> T;\n    while(T--){\n        unsigned long\
    \ long a, k; cin >> a >> k;\n        cout << kthRoot(a, k) << \"\\n\";\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/kth_root_integer.hpp\"\
    \n\nint main(){\n    int T; cin >> T;\n    while(T--){\n        unsigned long\
    \ long a, k; cin >> a >> k;\n        cout << kthRoot(a, k) << \"\\n\";\n    }\n\
    }"
  dependsOn:
  - lib/math/kth_root_integer.hpp
  isVerificationFile: true
  path: test/library_checker/number_theory/kth_root_integer.test.cpp
  requiredBy: []
  timestamp: '2024-11-04 03:12:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/number_theory/kth_root_integer.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/number_theory/kth_root_integer.test.cpp
- /verify/test/library_checker/number_theory/kth_root_integer.test.cpp.html
title: test/library_checker/number_theory/kth_root_integer.test.cpp
---
