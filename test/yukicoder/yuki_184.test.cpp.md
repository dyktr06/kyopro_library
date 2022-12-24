---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/binarybasis.hpp
    title: lib/math/binarybasis.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/184
    links:
    - https://yukicoder.me/problems/no/184
  bundledCode: "#line 1 \"test/yukicoder/yuki_184.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/184\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/binarybasis.hpp\"\
    \n\n/*\n    \u914D\u5217 vec \u306E xor \u57FA\u5E95\u3092\u6C42\u3081\u307E\u3059\
    \u3002\n\n    add(x): x \u3092\u57FA\u5E95\u306E\u96C6\u5408\u306B\u8FFD\u52A0\
    \u3057\u307E\u3059\u3002\n    exist(x): \u57FA\u5E95\u306E\u96C6\u5408\u306E\u4E2D\
    \u304B\u3089 XOR \u3092\u7E70\u308A\u8FD4\u3057\u3066 x \u3092\u4F5C\u308C\u308B\
    \u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3057\u307E\u3059\u3002\n    normalize():\
    \ \u57FA\u5E95\u306E\u96C6\u5408\u3092\u6574\u7406\u3057\u307E\u3059\u3002\n \
    \   kth_element(k): \u57FA\u5E95\u304B\u3089\u751F\u6210\u3067\u304D\u308B\u6570\
    \u306E\u96C6\u5408\u306E k \u756A\u76EE\u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\
    (0-indexed)\n    size(x): \u57FA\u5E95\u306E\u96C6\u5408\u306E\u5927\u304D\u3055\
    \u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\n*/\n\ntemplate <typename T>\nstruct\
    \ BinaryBasis{\n\n    vector<T> basis, original;\n    BinaryBasis(const vector<T>&\
    \ vec){\n        for(auto x : vec){\n            T y = x;\n            for(auto\
    \ z : basis){\n                y = min(y, y ^ z);\n            }\n           \
    \ if(y > 0){\n                basis.push_back(y);\n                original.push_back(x);\n\
    \            }\n        }\n        normalize();\n    }\n\n    void add(const T\
    \ &x){\n        T y = x;\n        for(auto z : basis){\n            y = min(y,\
    \ y ^ z);\n        }\n        if(y > 0){\n            basis.push_back(y);\n  \
    \          original.push_back(x);\n        }\n    }\n\n    void normalize(){\n\
    \        sort(basis.begin(), basis.end());\n        for(int i = 0; i < (int) basis.size();\
    \ ++i){\n            for(int j = 0; j < i; ++j){\n                basis[i] = min(basis[i],\
    \ basis[i] ^ basis[j]);\n            }\n        }\n    }\n\n    bool exist(const\
    \ T &x){\n        T y = x;\n        for(auto z : basis){\n            y = min(y,\
    \ y ^ z);\n        }\n        return y > 0;\n    }\n\n    T kth_element(const\
    \ long long &k){\n        T res = 0;\n        for(int i = 0; i < (int) basis.size();\
    \ ++i){\n            if(k & (1LL << i)){\n                res ^= basis[i];\n \
    \           }\n        }\n        return res;\n    }\n\n    size_t size(){\n \
    \       return basis.size();\n    }\n};\n#line 6 \"test/yukicoder/yuki_184.test.cpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    vector<long long> a(n);\n    for(int\
    \ i = 0; i < n; i++){\n        cin >> a[i];\n    }\n    BinaryBasis<long long>\
    \ basis(a);\n    cout << (1LL << (basis.size())) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/184\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../lib/math/binarybasis.hpp\"\n\nint main(){\n\
    \    int n; cin >> n;\n    vector<long long> a(n);\n    for(int i = 0; i < n;\
    \ i++){\n        cin >> a[i];\n    }\n    BinaryBasis<long long> basis(a);\n \
    \   cout << (1LL << (basis.size())) << \"\\n\";\n}"
  dependsOn:
  - lib/math/binarybasis.hpp
  isVerificationFile: true
  path: test/yukicoder/yuki_184.test.cpp
  requiredBy: []
  timestamp: '2022-12-25 05:08:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/yuki_184.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki_184.test.cpp
- /verify/test/yukicoder/yuki_184.test.cpp.html
title: test/yukicoder/yuki_184.test.cpp
---
