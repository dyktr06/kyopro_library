---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1_5_a.test.cpp
    title: test/aoj/alds1/alds1_5_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/others/exhaustive_search.hpp\"\n\n// a\u306E\u90E8\u5206\
    \u96C6\u5408\u306E\u548C\u306E\u7D44\u307F\u5408\u308F\u305B\u3092\u3059\u3079\
    \u3066\u5217\u6319\u3057\u307E\u3059\u3002: O(2^N)\ntemplate<typename T>\nvector<long\
    \ long> sum_subsets(T a){\n    vector<long long> res;\n    int n = a.size();\n\
    \    for(int bit = 0; bit < (1 << n); bit++){\n        long long sum = 0;\n  \
    \      for(int i = 0; i < n; i++){\n            int mask = 1 << i;\n         \
    \   if(bit & mask){\n                sum += a[i];\n            }\n        }\n\
    \        res.emplace_back(sum);\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n// a\u306E\u90E8\u5206\u96C6\u5408\u306E\u548C\u306E\u7D44\
    \u307F\u5408\u308F\u305B\u3092\u3059\u3079\u3066\u5217\u6319\u3057\u307E\u3059\
    \u3002: O(2^N)\ntemplate<typename T>\nvector<long long> sum_subsets(T a){\n  \
    \  vector<long long> res;\n    int n = a.size();\n    for(int bit = 0; bit < (1\
    \ << n); bit++){\n        long long sum = 0;\n        for(int i = 0; i < n; i++){\n\
    \            int mask = 1 << i;\n            if(bit & mask){\n               \
    \ sum += a[i];\n            }\n        }\n        res.emplace_back(sum);\n   \
    \ }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/exhaustive_search.hpp
  requiredBy: []
  timestamp: '2022-11-11 03:58:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/alds1/alds1_5_a.test.cpp
documentation_of: lib/others/exhaustive_search.hpp
layout: document
redirect_from:
- /library/lib/others/exhaustive_search.hpp
- /library/lib/others/exhaustive_search.hpp.html
title: lib/others/exhaustive_search.hpp
---
