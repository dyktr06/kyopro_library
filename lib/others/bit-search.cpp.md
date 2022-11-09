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
  bundledCode: "#line 1 \"lib/others/bit-search.cpp\"\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\n// a\u306E\u90E8\u5206\u96C6\u5408\u306E\u548C\u306E\u7D44\
    \u307F\u5408\u308F\u305B\u3092\u3059\u3079\u3066\u5217\u6319\u3057\u307E\u3059\
    \u3002: O(2^N)\ntemplate<typename T>\nvector<long long> getSumOfSubsets(T a){\n\
    \    vector<long long> res;\n    int n = a.size();\n    for(int bit = 0; bit <\
    \ (1 << n); bit++){\n        long long sum = 0;\n        for(int i = 0; i < n;\
    \ i++){\n            int mask = 1 << i;\n            if(bit & mask){\n       \
    \         sum += a[i];\n            }\n        }\n        res.emplace_back(sum);\n\
    \    }\n    return res;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// a\u306E\u90E8\u5206\
    \u96C6\u5408\u306E\u548C\u306E\u7D44\u307F\u5408\u308F\u305B\u3092\u3059\u3079\
    \u3066\u5217\u6319\u3057\u307E\u3059\u3002: O(2^N)\ntemplate<typename T>\nvector<long\
    \ long> getSumOfSubsets(T a){\n    vector<long long> res;\n    int n = a.size();\n\
    \    for(int bit = 0; bit < (1 << n); bit++){\n        long long sum = 0;\n  \
    \      for(int i = 0; i < n; i++){\n            int mask = 1 << i;\n         \
    \   if(bit & mask){\n                sum += a[i];\n            }\n        }\n\
    \        res.emplace_back(sum);\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/bit-search.cpp
  requiredBy: []
  timestamp: '2022-08-06 17:42:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/bit-search.cpp
layout: document
redirect_from:
- /library/lib/others/bit-search.cpp
- /library/lib/others/bit-search.cpp.html
title: lib/others/bit-search.cpp
---
