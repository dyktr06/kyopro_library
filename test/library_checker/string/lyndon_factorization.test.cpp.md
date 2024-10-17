---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/lyndon_factorization.hpp
    title: lib/string/lyndon_factorization.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lyndon_factorization
    links:
    - https://judge.yosupo.jp/problem/lyndon_factorization
  bundledCode: "#line 1 \"test/library_checker/string/lyndon_factorization.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lyndon_factorization\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/string/lyndon_factorization.hpp\"\
    \n\ntemplate <typename T>\nvector<int> lyndon_factorization(const T &s){\n   \
    \ int n = s.size();\n    vector<int> ans = {0};\n    int l = 0;\n    while(l <\
    \ n){\n        // [l, ?) \u306E\u6700\u9577\u306E Lyndon \u6587\u5B57\u5217\u3092\
    \u898B\u3064\u3051\u308B\n        int i = l, j = l + 1;\n        while(s[i] <=\
    \ s[j] && j < n){\n            if(s[i] == s[j]) i++;\n            else i = l;\n\
    \            j++;\n        }\n        // (j - i) \u304C\u5468\u671F\u3067\u3001\
    [l, j) \u304C\u305D\u306E\u5468\u671F\u306E\u7E70\u308A\u8FD4\u3057\n        int\
    \ repet = (j - l) / (j - i);\n        for(int d = 0; d < repet; d++){\n      \
    \      l += j - i;\n            ans.push_back(l);\n        }\n    }\n    return\
    \ ans;\n}\n#line 6 \"test/library_checker/string/lyndon_factorization.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   string s; cin >> s;\n    auto ans = lyndon_factorization(s);\n    int len\
    \ = ans.size();\n    for(int i = 0; i < len; i++){\n        if(i >= 1) cout <<\
    \ ' ';\n        cout << ans[i];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lyndon_factorization\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/string/lyndon_factorization.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   string s; cin >> s;\n    auto ans = lyndon_factorization(s);\n    int len\
    \ = ans.size();\n    for(int i = 0; i < len; i++){\n        if(i >= 1) cout <<\
    \ ' ';\n        cout << ans[i];\n    }\n}\n"
  dependsOn:
  - lib/string/lyndon_factorization.hpp
  isVerificationFile: true
  path: test/library_checker/string/lyndon_factorization.test.cpp
  requiredBy: []
  timestamp: '2024-10-17 18:05:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/string/lyndon_factorization.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/string/lyndon_factorization.test.cpp
- /verify/test/library_checker/string/lyndon_factorization.test.cpp.html
title: test/library_checker/string/lyndon_factorization.test.cpp
---
