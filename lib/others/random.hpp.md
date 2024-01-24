---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/math/primitive_root.hpp
    title: lib/math/primitive_root.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/primitive_root.test.cpp
    title: test/library_checker/math/primitive_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/others/random.hpp\"\n\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\nstruct RandomNumber{\n    int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    \    uniform_int_distribution<long long> p;\n    mt19937_64 rnd;\n\n\tRandomNumber(long\
    \ long l = 0, long long r = 0){\n        rnd = mt19937_64(seed);\n        p =\
    \ uniform_int_distribution<long long>(l, r);\n    }\n\n\tlong long get(){\n  \
    \      return p(rnd);\n    }\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nstruct\
    \ RandomNumber{\n    int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    \    uniform_int_distribution<long long> p;\n    mt19937_64 rnd;\n\n\tRandomNumber(long\
    \ long l = 0, long long r = 0){\n        rnd = mt19937_64(seed);\n        p =\
    \ uniform_int_distribution<long long>(l, r);\n    }\n\n\tlong long get(){\n  \
    \      return p(rnd);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/random.hpp
  requiredBy:
  - lib/math/primitive_root.hpp
  timestamp: '2024-01-24 14:02:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/primitive_root.test.cpp
documentation_of: lib/others/random.hpp
layout: document
redirect_from:
- /library/lib/others/random.hpp
- /library/lib/others/random.hpp.html
title: lib/others/random.hpp
---
