---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/string/number_of_substrings_1.test.cpp
    title: test/library_checker/string/number_of_substrings_1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/string/lcp_array.hpp\"\n\n#include <vector>\n\n// Kasai's\
    \ Algorithm\ntemplate <typename T>\nstd::vector<int> LCPArray(const T &s, const\
    \ std::vector<int> &sa){\n    const int n = s.size();\n    std::vector<int> rank(n);\n\
    \    for(int i = 0; i < n; ++i){\n        rank[sa[i]] = i;\n    }\n\n    std::vector<int>\
    \ lcp(n - 1);\n    for(int i = 0, h = 0; i < (int) sa.size(); ++i){\n        if(rank[i]\
    \ + 1 < (int) sa.size()){\n            for(int j = sa[rank[i] + 1]; std::max(i,\
    \ j) + h < (int) sa.size() && s[i + h] == s[j + h]; ++h);\n            lcp[rank[i]\
    \ + 1] = h;\n            if(h > 0) --h;\n        }\n    }\n    return lcp;\n}\n"
  code: "#pragma once\n\n#include <vector>\n\n// Kasai's Algorithm\ntemplate <typename\
    \ T>\nstd::vector<int> LCPArray(const T &s, const std::vector<int> &sa){\n   \
    \ const int n = s.size();\n    std::vector<int> rank(n);\n    for(int i = 0; i\
    \ < n; ++i){\n        rank[sa[i]] = i;\n    }\n\n    std::vector<int> lcp(n -\
    \ 1);\n    for(int i = 0, h = 0; i < (int) sa.size(); ++i){\n        if(rank[i]\
    \ + 1 < (int) sa.size()){\n            for(int j = sa[rank[i] + 1]; std::max(i,\
    \ j) + h < (int) sa.size() && s[i + h] == s[j + h]; ++h);\n            lcp[rank[i]\
    \ + 1] = h;\n            if(h > 0) --h;\n        }\n    }\n    return lcp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/string/lcp_array.hpp
  requiredBy: []
  timestamp: '2024-10-31 17:21:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/string/number_of_substrings_1.test.cpp
documentation_of: lib/string/lcp_array.hpp
layout: document
redirect_from:
- /library/lib/string/lcp_array.hpp
- /library/lib/string/lcp_array.hpp.html
title: lib/string/lcp_array.hpp
---
