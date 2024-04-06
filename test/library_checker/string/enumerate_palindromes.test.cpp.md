---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/string/manacher.hpp
    title: Manacher
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
    \n\n/**\n * @brief Manacher\n * @docs docs/string/manacher.md\n */\n\ntemplate\
    \ <typename T>\nvector<int> manacher(const T &s){\n    int n = s.size();\n   \
    \ vector<int> rad(n);\n    int i = 0, j = 0;\n    while(i < n){\n        while(i\
    \ - j >= 0 && i + j < (int) s.size() && s[i - j] == s[i + j]){\n            j++;\n\
    \        }\n        rad[i] = j;\n        int k = 1;\n        while(i - k >= 0\
    \ && i + k < n && k + rad[i - k] < j){\n            rad[i + k] = rad[i - k];\n\
    \            k++;\n        }\n        i += k;\n        j -= k;\n    }\n    return\
    \ rad;\n}\n\nstruct PalindromeCheck{\n    const string s;\n    string t;\n   \
    \ int n;\n    vector<int> mana;\n\n    PalindromeCheck(const string &str) : s(str){\n\
    \        n = s.size();\n        t = \"$\";\n        for(int i = 0; i < n; i++){\n\
    \            t += s[i];\n            t += \"$\";\n        }\n        mana = manacher(t);\n\
    \    }\n\n    // [l, r)\n    bool isPalindrome(int l, int r) const {\n       \
    \ int mid = l + r;\n        return r * 2 - mid - 1 < mana[mid];\n    }\n};\n#line\
    \ 6 \"test/library_checker/string/enumerate_palindromes.test.cpp\"\n\nint main(){\n\
    \    string s; cin >> s;\n    int n = s.size();\n    string t = \"\";\n    for(int\
    \ i = 0; i < n; i++){\n        t += s[i];\n        if(i < n - 1) t += '$';\n \
    \   }\n    vector<int> m1 = manacher(s), m2 = manacher(t);\n    for(int i = 0;\
    \ i < 2 * n - 1; i++){\n        int ans;\n        if(i % 2 == 0){\n          \
    \  ans = 2 * m1[i / 2] - 1;\n        }else{\n            ans = m2[i] / 2 * 2;\n\
    \        }\n        if(i >= 1) cout << \" \";\n        cout << ans;\n    }\n \
    \   cout << \"\\n\";\n}\n"
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
  timestamp: '2024-04-07 03:10:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/string/enumerate_palindromes.test.cpp
- /verify/test/library_checker/string/enumerate_palindromes.test.cpp.html
title: test/library_checker/string/enumerate_palindromes.test.cpp
---
