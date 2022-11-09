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
  bundledCode: "#line 2 \"lib/others/compression_old.hpp\"\n\n// \u5EA7\u6A19\u5727\
    \u7E2E\u3057\u305F\u914D\u5217\u3092\u8FD4\u3057\u307E\u3059(0-indexed) : O(NlogN)\n\
    template <typename T>\nT compression(T vec){\n    int n = vec.size();\n    T tmp\
    \ = vec;\n    sort(tmp.begin(), tmp.end());\n    tmp.erase(unique(tmp.begin(),\
    \ tmp.end()), tmp.end());\n    T res(n);\n    for(int i = 0; i < n; i++){\n  \
    \      res[i] = lower_bound(tmp.begin(), tmp.end(), vec[i]) - tmp.begin();\n \
    \   }\n    return res;\n}\n"
  code: "#pragma once\n\n// \u5EA7\u6A19\u5727\u7E2E\u3057\u305F\u914D\u5217\u3092\
    \u8FD4\u3057\u307E\u3059(0-indexed) : O(NlogN)\ntemplate <typename T>\nT compression(T\
    \ vec){\n    int n = vec.size();\n    T tmp = vec;\n    sort(tmp.begin(), tmp.end());\n\
    \    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());\n    T res(n);\n  \
    \  for(int i = 0; i < n; i++){\n        res[i] = lower_bound(tmp.begin(), tmp.end(),\
    \ vec[i]) - tmp.begin();\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/compression_old.hpp
  requiredBy: []
  timestamp: '2022-11-10 02:54:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/compression_old.hpp
layout: document
redirect_from:
- /library/lib/others/compression_old.hpp
- /library/lib/others/compression_old.hpp.html
title: lib/others/compression_old.hpp
---
