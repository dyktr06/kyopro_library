---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/string/manacher.cpp\"\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\n// \u305D\u308C\u305E\u308C\u306E i (1 <= i <= |S|) \u306B\
    \u3064\u3044\u3066\u3001S[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u56DE\
    \u6587\u306E\u534A\u5F84\u3092\u6C42\u3081\u307E\u3059\u3002 : O(|S|) \ntemplate\
    \ <typename T>\nvector<int> manacher(const T &s){\n    int n = s.size();\n   \
    \ vector<int> rad(n);\n    int i = 0, j = 0;\n    while(i < n){\n        while(i\
    \ - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]){\n            j++;\n \
    \       }\n        rad[i] = j;\n        int k = 1;\n        while(i - k >= 0 &&\
    \ i + k < n && k + rad[i - k] < j){\n            rad[i + k] = rad[i - k];\n  \
    \          k++;\n        }\n        i += k;\n        j -= k;\n    }\n    return\
    \ rad;\n}\n\n// example (Library Checker: Enumerate Palindromes)\nint main(){\n\
    \    string s; cin >> s;\n    int n = s.size();\n    string t = \"\";\n    for(int\
    \ i = 0; i < n; i++){\n        t += s[i];\n        if(i < n - 1) t += '$';\n \
    \   }\n    vector<int> m1 = manacher(s), m2 = manacher(t);\n    for(int i = 0;\
    \ i < 2 * n - 1; i++){\n        int ans;\n        if(i % 2 == 0){\n          \
    \  ans = 2 * m1[i / 2] - 1;\n        }else{\n            ans = m2[i] / 2 * 2;\n\
    \        }\n        if(i >= 1) cout << \" \";\n        cout << ans;\n    }\n \
    \   cout << \"\\n\";\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// \u305D\u308C\u305E\
    \u308C\u306E i (1 <= i <= |S|) \u306B\u3064\u3044\u3066\u3001S[i] \u3092\u4E2D\
    \u5FC3\u3068\u3059\u308B\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84\u3092\u6C42\
    \u3081\u307E\u3059\u3002 : O(|S|) \ntemplate <typename T>\nvector<int> manacher(const\
    \ T &s){\n    int n = s.size();\n    vector<int> rad(n);\n    int i = 0, j = 0;\n\
    \    while(i < n){\n        while(i - j >= 0 && i + j < s.size() && s[i - j] ==\
    \ s[i + j]){\n            j++;\n        }\n        rad[i] = j;\n        int k\
    \ = 1;\n        while(i - k >= 0 && i + k < n && k + rad[i - k] < j){\n      \
    \      rad[i + k] = rad[i - k];\n            k++;\n        }\n        i += k;\n\
    \        j -= k;\n    }\n    return rad;\n}\n\n// example (Library Checker: Enumerate\
    \ Palindromes)\nint main(){\n    string s; cin >> s;\n    int n = s.size();\n\
    \    string t = \"\";\n    for(int i = 0; i < n; i++){\n        t += s[i];\n \
    \       if(i < n - 1) t += '$';\n    }\n    vector<int> m1 = manacher(s), m2 =\
    \ manacher(t);\n    for(int i = 0; i < 2 * n - 1; i++){\n        int ans;\n  \
    \      if(i % 2 == 0){\n            ans = 2 * m1[i / 2] - 1;\n        }else{\n\
    \            ans = m2[i] / 2 * 2;\n        }\n        if(i >= 1) cout << \" \"\
    ;\n        cout << ans;\n    }\n    cout << \"\\n\";\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/manacher.cpp
  requiredBy: []
  timestamp: '2022-11-10 01:07:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/string/manacher.cpp
layout: document
redirect_from:
- /library/lib/string/manacher.cpp
- /library/lib/string/manacher.cpp.html
title: lib/string/manacher.cpp
---
