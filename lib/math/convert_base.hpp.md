---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/yuki_2087.test.cpp
    title: test/yukicoder/yuki_2087.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/convert_base.hpp\"\n\n// 10\u9032\u6570\u3067\u306E\
    \ x \u3092 b \u9032\u6570\u306B\u5909\u63DB\u3057\u307E\u3059\u3002: O(logx)\n\
    template<typename T>\nstring convert_base(T x, T b) {\n    string res;\n    T\
    \ t = 1, k = abs(b);\n    while(x){\n        T num = (x * t) % k;\n        if(num\
    \ < 0) num += k;\n        res += num + (num < 10 ? 48 : 87);\n        x -= num\
    \ * t;\n        x /= k;\n        t *= b / k;\n    }\n    if(res.empty()) res =\
    \ '0';\n    reverse(res.begin(), res.end());\n    return res;\n}\n"
  code: "#pragma once\n\n// 10\u9032\u6570\u3067\u306E x \u3092 b \u9032\u6570\u306B\
    \u5909\u63DB\u3057\u307E\u3059\u3002: O(logx)\ntemplate<typename T>\nstring convert_base(T\
    \ x, T b) {\n    string res;\n    T t = 1, k = abs(b);\n    while(x){\n      \
    \  T num = (x * t) % k;\n        if(num < 0) num += k;\n        res += num + (num\
    \ < 10 ? 48 : 87);\n        x -= num * t;\n        x /= k;\n        t *= b / k;\n\
    \    }\n    if(res.empty()) res = '0';\n    reverse(res.begin(), res.end());\n\
    \    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/convert_base.hpp
  requiredBy: []
  timestamp: '2022-11-11 02:31:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/yuki_2087.test.cpp
documentation_of: lib/math/convert_base.hpp
layout: document
redirect_from:
- /library/lib/math/convert_base.hpp
- /library/lib/math/convert_base.hpp.html
title: lib/math/convert_base.hpp
---
