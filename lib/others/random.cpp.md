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
  bundledCode: "#line 1 \"lib/others/random.cpp\"\n#include <bits/stdc++.h>\n#include\
    \ <windows.h>\n\nusing namespace std;\n\n// \u4E71\u6570\u751F\u6210\nstruct RandomNumber{\n\
    \    int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    \    uniform_int_distribution<long long> p;\n    mt19937_64 rnd;\n\n\tRandomNumber(long\
    \ long l = 0, long long r = 0){\n        rnd = mt19937_64(seed);\n        p =\
    \ uniform_int_distribution<long long>(l, r);\n        Sleep(1);\n    }\n\n\tlong\
    \ long get(){\n        return p(rnd);\n    }\n};\n\n// example (1\u304B\u3089\
    100\u306E\u4E71\u6570\u3092\u751F\u6210)\nint main(){\n    RandomNumber r(1, 100);\n\
    \    cout << r.get() << endl;\n}\n"
  code: "#include <bits/stdc++.h>\n#include <windows.h>\n\nusing namespace std;\n\n\
    // \u4E71\u6570\u751F\u6210\nstruct RandomNumber{\n    int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    \    uniform_int_distribution<long long> p;\n    mt19937_64 rnd;\n\n\tRandomNumber(long\
    \ long l = 0, long long r = 0){\n        rnd = mt19937_64(seed);\n        p =\
    \ uniform_int_distribution<long long>(l, r);\n        Sleep(1);\n    }\n\n\tlong\
    \ long get(){\n        return p(rnd);\n    }\n};\n\n// example (1\u304B\u3089\
    100\u306E\u4E71\u6570\u3092\u751F\u6210)\nint main(){\n    RandomNumber r(1, 100);\n\
    \    cout << r.get() << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/random.cpp
  requiredBy: []
  timestamp: '2022-08-24 05:59:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/random.cpp
layout: document
redirect_from:
- /library/lib/others/random.cpp
- /library/lib/others/random.cpp.html
title: lib/others/random.cpp
---
