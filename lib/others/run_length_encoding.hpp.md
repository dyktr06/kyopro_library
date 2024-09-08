---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/others/run_length_encoding.hpp\"\n\ntemplate <typename\
    \ T>\nvector<pair<T, int>> runLengthEncoding(const vector<T> &a){\n    vector<pair<T,\
    \ int>> res;\n    int n = a.size();\n    for(int i = 0; i < n; ++i){\n       \
    \ if(res.empty() || res.back().first != a[i]){\n            res.emplace_back(a[i],\
    \ 1);\n        } else{\n            res.back().second++;\n        }\n    }\n \
    \   return res;\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nvector<pair<T, int>> runLengthEncoding(const\
    \ vector<T> &a){\n    vector<pair<T, int>> res;\n    int n = a.size();\n    for(int\
    \ i = 0; i < n; ++i){\n        if(res.empty() || res.back().first != a[i]){\n\
    \            res.emplace_back(a[i], 1);\n        } else{\n            res.back().second++;\n\
    \        }\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2024-09-08 16:34:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/run_length_encoding.hpp
layout: document
redirect_from:
- /library/lib/others/run_length_encoding.hpp
- /library/lib/others/run_length_encoding.hpp.html
title: lib/others/run_length_encoding.hpp
---
