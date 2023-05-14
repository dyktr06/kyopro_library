---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/enumerate_quotients.test.cpp
    title: test/library_checker/math/enumerate_quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/enumerate_quotients.hpp\"\n\ntemplate <typename\
    \ T>\nvector<tuple<T, T, T>> enumerate_quotients(const T &n){\n    vector<tuple<T,\
    \ T, T>> res;\n    for(T l = 1; l <= n;){\n        const T quotient = n / l;\n\
    \        const T r = n / quotient + 1;\n\n        // [l, r)\n        res.emplace_back(l,\
    \ r, quotient);\n        l = r;\n    }\n    return res;\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nvector<tuple<T, T, T>> enumerate_quotients(const\
    \ T &n){\n    vector<tuple<T, T, T>> res;\n    for(T l = 1; l <= n;){\n      \
    \  const T quotient = n / l;\n        const T r = n / quotient + 1;\n\n      \
    \  // [l, r)\n        res.emplace_back(l, r, quotient);\n        l = r;\n    }\n\
    \    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/enumerate_quotients.hpp
  requiredBy: []
  timestamp: '2023-05-14 14:52:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/enumerate_quotients.test.cpp
documentation_of: lib/math/enumerate_quotients.hpp
layout: document
redirect_from:
- /library/lib/math/enumerate_quotients.hpp
- /library/lib/math/enumerate_quotients.hpp.html
title: lib/math/enumerate_quotients.hpp
---
