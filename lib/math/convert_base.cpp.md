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
  bundledCode: "#line 1 \"lib/math/convert_base.cpp\"\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\n// 10\u9032\u6570\u3067\u306E x \u3092 b \u9032\u6570\u306B\
    \u5909\u63DB\u3057\u307E\u3059\u3002: O(logx)\ntemplate<typename T>\nstring convert_base(T\
    \ x, T b) {\n    string res;\n    T t = 1, k = abs(b);\n    while(x){\n      \
    \  T num = (x * t) % k;\n        if(num < 0) num += k;\n        res += num + (num\
    \ < 10 ? 48 : 87);\n        x -= num * t;\n        x /= k;\n        t *= b / k;\n\
    \    }\n    if(res.empty()) res = '0';\n    reverse(res.begin(), res.end());\n\
    \    return res;\n}\n\n// example (ABC234C)\nint main(){\n    long long k; cin\
    \ >> k;\n    string s = convert_base(k, 2LL);\n    s = regex_replace(s, regex(\"\
    1\"), \"2\");\n    cout << s << \"\\n\";\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// 10\u9032\u6570\u3067\
    \u306E x \u3092 b \u9032\u6570\u306B\u5909\u63DB\u3057\u307E\u3059\u3002: O(logx)\n\
    template<typename T>\nstring convert_base(T x, T b) {\n    string res;\n    T\
    \ t = 1, k = abs(b);\n    while(x){\n        T num = (x * t) % k;\n        if(num\
    \ < 0) num += k;\n        res += num + (num < 10 ? 48 : 87);\n        x -= num\
    \ * t;\n        x /= k;\n        t *= b / k;\n    }\n    if(res.empty()) res =\
    \ '0';\n    reverse(res.begin(), res.end());\n    return res;\n}\n\n// example\
    \ (ABC234C)\nint main(){\n    long long k; cin >> k;\n    string s = convert_base(k,\
    \ 2LL);\n    s = regex_replace(s, regex(\"1\"), \"2\");\n    cout << s << \"\\\
    n\";\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/convert_base.cpp
  requiredBy: []
  timestamp: '2022-08-29 07:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/convert_base.cpp
layout: document
redirect_from:
- /library/lib/math/convert_base.cpp
- /library/lib/math/convert_base.cpp.html
title: lib/math/convert_base.cpp
---
