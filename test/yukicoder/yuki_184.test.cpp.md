---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/binarybasis.hpp
    title: Binary Basis
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
    \n\n/**\n * @brief Binary Basis\n * @docs docs/math/binarybasis.md\n */\n\ntemplate\
    \ <typename T>\nstruct BinaryBasis{\n\n    vector<T> basis, original, inds;\n\
    \    int cnt = 0;\n    BinaryBasis(const vector<T> &vec){\n        for(auto x\
    \ : vec){\n            T v = (T) 1 << (cnt++);\n            T y = x;\n       \
    \     int len = basis.size();\n            for(int i = 0; i < len; i++){\n   \
    \             if((y ^ basis[i]) < y){\n                    y ^= basis[i];\n  \
    \                  v ^= inds[i];\n                }\n            }\n         \
    \   if(y > 0){\n                basis.push_back(y);\n                original.push_back(x);\n\
    \                inds.push_back(v);\n            }\n        }\n        normalize();\n\
    \    }\n\n    pair<T, T> add(const T &x){\n        T v = (T) 1 << (cnt++);\n \
    \       T y = x;\n        int len = basis.size();\n        for(int i = 0; i <\
    \ len; i++){\n            if((y ^ basis[i]) < y){\n                y ^= basis[i];\n\
    \                v ^= inds[i];\n            }\n        }\n        if(y > 0){\n\
    \            basis.push_back(y);\n            original.push_back(x);\n       \
    \     inds.push_back(v);\n        }\n        return make_pair(y, v);\n    }\n\n\
    \    void normalize(){\n        int len = basis.size();\n        for(int i = 0;\
    \ i < len; i++){\n            for(int j = i + 1; j < len; j++){\n            \
    \    if(basis[j] < basis[i]){\n                    swap(basis[i], basis[j]);\n\
    \                    swap(original[i], original[j]);\n                    swap(inds[i],\
    \ inds[j]);\n                }\n            }\n        }\n        for(int i =\
    \ 0; i < (int) basis.size(); ++i){\n            for(int j = 0; j < i; ++j){\n\
    \                if((basis[i] ^ basis[j]) < basis[i]){\n                    basis[i]\
    \ ^= basis[j];\n                    inds[i] ^= inds[j];\n                }\n \
    \           }\n        }\n    }\n\n    bool exist(const T &x){\n        T y =\
    \ x;\n        for(auto z : basis){\n            y = min(y, y ^ z);\n        }\n\
    \        return y == 0;\n    }\n\n    T kth_element(const long long &k){\n   \
    \     T res = 0;\n        for(int i = 0; i < (int) basis.size(); ++i){\n     \
    \       if(k & (1LL << i)){\n                res ^= basis[i];\n            }\n\
    \        }\n        return res;\n    }\n\n    size_t size(){\n        return basis.size();\n\
    \    }\n};\n#line 6 \"test/yukicoder/yuki_184.test.cpp\"\n\nint main(){\n    int\
    \ n; cin >> n;\n    vector<long long> a(n);\n    for(int i = 0; i < n; i++){\n\
    \        cin >> a[i];\n    }\n    BinaryBasis<long long> basis(a);\n    cout <<\
    \ (1LL << (basis.size())) << \"\\n\";\n}\n"
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
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/yuki_184.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/yuki_184.test.cpp
- /verify/test/yukicoder/yuki_184.test.cpp.html
title: test/yukicoder/yuki_184.test.cpp
---
