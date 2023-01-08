---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/z_algorithm.hpp
    title: Z Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/library_checker/string/z_algorithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/string/z_algorithm.hpp\"\n\n/**\n * @brief\
    \ Z Algorithm\n * @docs docs/string/z_algorithm.md\n */\n\ntemplate <typename\
    \ T>\nvector<int> z_algorithm(const T &s) {\n    int n = s.size();\n    vector<int>\
    \ res(n, 0);\n    for(int i = 1, j = 0; i < n; ++i){\n        if(i + res[i - j]\
    \ < j + res[j]){\n            res[i] = res[i - j];\n        }else{\n         \
    \   res[i] = max(j + res[j] - i, 0);\n            while(i + res[i] < n && s[i\
    \ + res[i]] == s[res[i]]) ++res[i];\n            j = i;\n        }\n    }\n  \
    \  res[0] = n;\n    return res;\n}\n#line 6 \"test/library_checker/string/z_algorithm.test.cpp\"\
    \n\nint main(){\n    string s; cin >> s;\n    vector<int> z = z_algorithm(s);\n\
    \    int n = s.size();\n    for(int i = 0; i < n; i++){\n        if(i >= 1) cout\
    \ << \" \";\n        cout << z[i];\n    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/string/z_algorithm.hpp\"\
    \n\nint main(){\n    string s; cin >> s;\n    vector<int> z = z_algorithm(s);\n\
    \    int n = s.size();\n    for(int i = 0; i < n; i++){\n        if(i >= 1) cout\
    \ << \" \";\n        cout << z[i];\n    }\n    cout << endl;\n}"
  dependsOn:
  - lib/string/z_algorithm.hpp
  isVerificationFile: true
  path: test/library_checker/string/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-01-09 04:41:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/string/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/string/z_algorithm.test.cpp
- /verify/test/library_checker/string/z_algorithm.test.cpp.html
title: test/library_checker/string/z_algorithm.test.cpp
---
