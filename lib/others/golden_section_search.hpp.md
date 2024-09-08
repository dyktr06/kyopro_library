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
  bundledCode: "#line 2 \"lib/others/golden_section_search.hpp\"\n\n// l <= r, ret:\
    \ min\ntemplate <typename T>\npair<long long, long long> golden_section_search(long\
    \ long l, long long r, T check){\n    long long a = l - 1, x, b;\n    {\n    \
    \    // fibonacci\n        long long s = 1, t = 2;\n        while(t < r - l +\
    \ 2){\n            s += t;\n            swap(s, t);\n        }\n        x = a\
    \ + t - s;\n        b = a + t;\n    }\n    long long fx = check(x), fy;\n    while(a\
    \ + b != x * 2){\n        long long y = a + b - x;\n        if(r < y || fx < (fy\
    \ = check(y))){\n            b = a;\n            a = y;\n        }else{\n    \
    \        a = x;\n            x = y;\n            fx = fy;\n        }\n    }\n\
    \    return {x, fx};\n}\n"
  code: "#pragma once\n\n// l <= r, ret: min\ntemplate <typename T>\npair<long long,\
    \ long long> golden_section_search(long long l, long long r, T check){\n    long\
    \ long a = l - 1, x, b;\n    {\n        // fibonacci\n        long long s = 1,\
    \ t = 2;\n        while(t < r - l + 2){\n            s += t;\n            swap(s,\
    \ t);\n        }\n        x = a + t - s;\n        b = a + t;\n    }\n    long\
    \ long fx = check(x), fy;\n    while(a + b != x * 2){\n        long long y = a\
    \ + b - x;\n        if(r < y || fx < (fy = check(y))){\n            b = a;\n \
    \           a = y;\n        }else{\n            a = x;\n            x = y;\n \
    \           fx = fy;\n        }\n    }\n    return {x, fx};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/golden_section_search.hpp
  requiredBy: []
  timestamp: '2024-09-08 16:34:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/golden_section_search.hpp
layout: document
redirect_from:
- /library/lib/others/golden_section_search.hpp
- /library/lib/others/golden_section_search.hpp.html
title: lib/others/golden_section_search.hpp
---
