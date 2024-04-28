---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/kth_root_integer.test.cpp
    title: test/library_checker/math/kth_root_integer.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/kth_root_integer.hpp\"\n\nunsigned long long kthRoot(unsigned\
    \ long long a, unsigned long long k){\n    unsigned long long tmp = powl(a, (long\
    \ double) 1 / (long double) k);\n    unsigned long long res = 0;\n    vector<unsigned\
    \ long long> border = {tmp - 1, tmp, tmp + 1};\n    for(auto x : border){\n  \
    \      if(x == 0) continue;\n        unsigned long long curr = a;\n        for(int\
    \ i = 0; i < (int) k; i++){\n            curr /= x;\n        }\n        if(curr\
    \ >= 1) res = max(res, x);\n    }\n    return res;\n}\n"
  code: "#pragma once\n\nunsigned long long kthRoot(unsigned long long a, unsigned\
    \ long long k){\n    unsigned long long tmp = powl(a, (long double) 1 / (long\
    \ double) k);\n    unsigned long long res = 0;\n    vector<unsigned long long>\
    \ border = {tmp - 1, tmp, tmp + 1};\n    for(auto x : border){\n        if(x ==\
    \ 0) continue;\n        unsigned long long curr = a;\n        for(int i = 0; i\
    \ < (int) k; i++){\n            curr /= x;\n        }\n        if(curr >= 1) res\
    \ = max(res, x);\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/kth_root_integer.hpp
  requiredBy: []
  timestamp: '2024-04-29 04:13:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/kth_root_integer.test.cpp
documentation_of: lib/math/kth_root_integer.hpp
layout: document
redirect_from:
- /library/lib/math/kth_root_integer.hpp
- /library/lib/math/kth_root_integer.hpp.html
title: lib/math/kth_root_integer.hpp
---
