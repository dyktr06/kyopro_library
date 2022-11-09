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
  bundledCode: "#line 1 \"lib/string/permutation.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n// \u4E26\u3073\u5909\u3048\u3066\u3067\u304D\u308B\u6587\
    \u5B57\u5217\u3068\u3057\u3066\u3042\u308A\u3048\u308B\u3082\u306E\u3092\u8F9E\
    \u66F8\u9806\u3067\u3059\u3079\u3066\u5217\u6319\u3057\u307E\u3059 : O(N*N!)\n\
    vector<string> getPermutation(const string &s){\n    int n = s.size();\n    vector<int>\
    \ array(n);\n    iota(array.begin(), array.end(), 0);\n    vector<string> res;\n\
    \    do{\n        string t = \"\";\n        for(int i = 0; i < n; i++){\n    \
    \        t.push_back(s[array[i]]);\n        }\n        res.push_back(t);\n   \
    \ }while(next_permutation(array.begin(), array.end()));\n    sort(res.begin(),\
    \ res.end());\n    res.erase(unique(res.begin(), res.end()), res.end());\n   \
    \ return res;\n}\n\n// example (ABC225A)\nint main(){\n    string s; cin >> s;\n\
    \    vector<string> p = getPermutation(s);\n    cout << (int) p.size() << \"\\\
    n\";\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// \u4E26\u3073\u5909\
    \u3048\u3066\u3067\u304D\u308B\u6587\u5B57\u5217\u3068\u3057\u3066\u3042\u308A\
    \u3048\u308B\u3082\u306E\u3092\u8F9E\u66F8\u9806\u3067\u3059\u3079\u3066\u5217\
    \u6319\u3057\u307E\u3059 : O(N*N!)\nvector<string> getPermutation(const string\
    \ &s){\n    int n = s.size();\n    vector<int> array(n);\n    iota(array.begin(),\
    \ array.end(), 0);\n    vector<string> res;\n    do{\n        string t = \"\"\
    ;\n        for(int i = 0; i < n; i++){\n            t.push_back(s[array[i]]);\n\
    \        }\n        res.push_back(t);\n    }while(next_permutation(array.begin(),\
    \ array.end()));\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n\n// example (ABC225A)\nint main(){\n\
    \    string s; cin >> s;\n    vector<string> p = getPermutation(s);\n    cout\
    \ << (int) p.size() << \"\\n\";\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/permutation.cpp
  requiredBy: []
  timestamp: '2022-09-21 23:58:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/string/permutation.cpp
layout: document
redirect_from:
- /library/lib/string/permutation.cpp
- /library/lib/string/permutation.cpp.html
title: lib/string/permutation.cpp
---
