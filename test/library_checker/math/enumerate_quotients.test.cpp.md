---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/enumerate_quotients.hpp
    title: lib/math/enumerate_quotients.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"test/library_checker/math/enumerate_quotients.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/enumerate_quotients.hpp\"\
    \n\ntemplate <typename T>\nvector<tuple<T, T, T>> enumerate_quotients(const T\
    \ &n){\n    vector<tuple<T, T, T>> res;\n    for(T l = 1; l <= n;){\n        const\
    \ T quotient = n / l;\n        const T r = n / quotient + 1;\n\n        // [l,\
    \ r)\n        res.emplace_back(l, r, quotient);\n        l = r;\n    }\n    return\
    \ res;\n}\n#line 6 \"test/library_checker/math/enumerate_quotients.test.cpp\"\n\
    \nint main(){\n    long long n; cin >> n;\n    vector<tuple<long long, long long,\
    \ long long>> a = enumerate_quotients(n);\n    reverse(a.begin(), a.end());\n\
    \    cout << (int) a.size() << \"\\n\";\n    for(auto [l, r, q] : a){\n      \
    \  cout << q << \" \";\n    }\n    cout << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/enumerate_quotients.hpp\"\
    \n\nint main(){\n    long long n; cin >> n;\n    vector<tuple<long long, long\
    \ long, long long>> a = enumerate_quotients(n);\n    reverse(a.begin(), a.end());\n\
    \    cout << (int) a.size() << \"\\n\";\n    for(auto [l, r, q] : a){\n      \
    \  cout << q << \" \";\n    }\n    cout << \"\\n\";\n}"
  dependsOn:
  - lib/math/enumerate_quotients.hpp
  isVerificationFile: true
  path: test/library_checker/math/enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2023-05-14 14:52:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/math/enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/enumerate_quotients.test.cpp
- /verify/test/library_checker/math/enumerate_quotients.test.cpp.html
title: test/library_checker/math/enumerate_quotients.test.cpp
---
