---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/manacher.hpp
    title: lib/string/manacher.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/string/manacher.hpp\"\
    \n\n// \u305D\u308C\u305E\u308C\u306E i (1 <= i <= |S|) \u306B\u3064\u3044\u3066\
    \u3001S[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u56DE\u6587\u306E\u534A\
    \u5F84\u3092\u6C42\u3081\u307E\u3059\u3002 : O(|S|) \ntemplate <typename T>\n\
    vector<int> manacher(const T &s){\n    int n = s.size();\n    vector<int> rad(n);\n\
    \    int i = 0, j = 0;\n    while(i < n){\n        while(i - j >= 0 && i + j <\
    \ s.size() && s[i - j] == s[i + j]){\n            j++;\n        }\n        rad[i]\
    \ = j;\n        int k = 1;\n        while(i - k >= 0 && i + k < n && k + rad[i\
    \ - k] < j){\n            rad[i + k] = rad[i - k];\n            k++;\n       \
    \ }\n        i += k;\n        j -= k;\n    }\n    return rad;\n}\n#line 6 \"test/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n\nint main(){\n    string s; cin >> s;\n    int n = s.size();\n    string t\
    \ = \"\";\n    for(int i = 0; i < n; i++){\n        t += s[i];\n        if(i <\
    \ n - 1) t += '$';\n    }\n    vector<int> m1 = manacher(s), m2 = manacher(t);\n\
    \    for(int i = 0; i < 2 * n - 1; i++){\n        int ans;\n        if(i % 2 ==\
    \ 0){\n            ans = 2 * m1[i / 2] - 1;\n        }else{\n            ans =\
    \ m2[i] / 2 * 2;\n        }\n        if(i >= 1) cout << \" \";\n        cout <<\
    \ ans;\n    }\n    cout << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/string/manacher.hpp\"\
    \n\nint main(){\n    string s; cin >> s;\n    int n = s.size();\n    string t\
    \ = \"\";\n    for(int i = 0; i < n; i++){\n        t += s[i];\n        if(i <\
    \ n - 1) t += '$';\n    }\n    vector<int> m1 = manacher(s), m2 = manacher(t);\n\
    \    for(int i = 0; i < 2 * n - 1; i++){\n        int ans;\n        if(i % 2 ==\
    \ 0){\n            ans = 2 * m1[i / 2] - 1;\n        }else{\n            ans =\
    \ m2[i] / 2 * 2;\n        }\n        if(i >= 1) cout << \" \";\n        cout <<\
    \ ans;\n    }\n    cout << \"\\n\";\n}"
  dependsOn:
  - lib/string/manacher.hpp
  isVerificationFile: true
  path: test/library_checker/string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2022-11-10 09:23:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/string/enumerate_palindromes.test.cpp
- /verify/test/library_checker/string/enumerate_palindromes.test.cpp.html
title: test/library_checker/string/enumerate_palindromes.test.cpp
---
