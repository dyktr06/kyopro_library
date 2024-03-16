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
  bundledCode: "#line 2 \"lib/others/zorbrist_hash.hpp\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\ntemplate <typename T>\nstruct ZorbristHash{\n    map<T,\
    \ int> rnd, cnt;\n    int h = 0;\n\n    ZorbristHash(){}\n\n    void insert(T\
    \ x){\n        if(rnd.count(x) == 0){\n            rnd[x] = rand();\n        }\n\
    \        if(cnt[x]) return;\n        h ^= rnd[x];\n        cnt[x]++;\n    }\n\n\
    \    void erase(T x){\n        if(cnt[x] == 0) return;\n        h ^= rnd[x];\n\
    \        cnt[x]--;\n    }\n\n    int get(){\n        return h;\n    }\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\ntemplate\
    \ <typename T>\nstruct ZorbristHash{\n    map<T, int> rnd, cnt;\n    int h = 0;\n\
    \n    ZorbristHash(){}\n\n    void insert(T x){\n        if(rnd.count(x) == 0){\n\
    \            rnd[x] = rand();\n        }\n        if(cnt[x]) return;\n       \
    \ h ^= rnd[x];\n        cnt[x]++;\n    }\n\n    void erase(T x){\n        if(cnt[x]\
    \ == 0) return;\n        h ^= rnd[x];\n        cnt[x]--;\n    }\n\n    int get(){\n\
    \        return h;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/others/zorbrist_hash.hpp
  requiredBy: []
  timestamp: '2024-03-17 05:01:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/others/zorbrist_hash.hpp
layout: document
redirect_from:
- /library/lib/others/zorbrist_hash.hpp
- /library/lib/others/zorbrist_hash.hpp.html
title: lib/others/zorbrist_hash.hpp
---
