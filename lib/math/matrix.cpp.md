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
  bundledCode: "#line 1 \"lib/math/matrix.cpp\"\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\n// \u884C\u5217 ... \u3053\u3053\u3067\u306F\u3001vector<vector<long\
    \ long>> \u306E\u4E8C\u6B21\u5143\u914D\u5217\u3067\u5B9A\u7FA9\u3055\u308C\u307E\
    \u3059\u3002\n\n// \u884C\u5217\u306E\u7D2F\u4E57 (mod. m) \u3092\u8A08\u7B97\u3057\
    \u307E\u3059\u3002: O(N^3 log n)\nvector<vector<long long>> matrixpow(vector<vector<long\
    \ long>> a, long long n, long long m){\n\n    int siz = a.size();\n    vector<vector<long\
    \ long>> b(siz, vector<long long>(siz, 0));\n    for(int i = 0; i < siz; i++)\
    \ b[i][i] = 1;\n\n    auto mul = [](vector<vector<long long>> a, vector<vector<long\
    \ long>> b, long long m) -> vector<vector<long long>> {\n        vector<vector<long\
    \ long>> res((int) a.size(), vector<long long>(b[0].size()));\n        for(int\
    \ i = 0; i < (int) a.size(); i++){\n            for(int k = 0; k < (int) b.size();\
    \ k++){\n                for(int j = 0; j < (int) b[0].size(); j++){\n       \
    \             res[i][j] += a[i][k] * b[k][j];\n                    res[i][j] %=\
    \ m;\n                }\n            }\n        }\n        return res;\n    };\n\
    \n    while(n > 0){\n        if(n & 1) b = mul(b, a, m);\n        a = mul(a, a,\
    \ m);\n        n >>= 1;\n    }\n    return b;\n}\n\n// \u884C\u5217\u306E\u7A4D\
    \ (mod. m) \u3092\u8A08\u7B97\u3057\u307E\u3059\u3002: O(N^3)\nvector<vector<long\
    \ long>> mul(vector<vector<long long>> a, vector<vector<long long>> b, long long\
    \ m){\n    vector<vector<long long>> res((int) a.size(), vector<long long>(b[0].size()));\n\
    \    for(int i = 0; i < (int) a.size(); i++){\n        for(int k = 0; k < (int)\
    \ b.size(); k++){\n            for(int j = 0; j < (int) b[0].size(); j++){\n \
    \               res[i][j] += a[i][k] * b[k][j];\n                res[i][j] %=\
    \ m;\n            }\n        }\n    }\n    return res;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n// \u884C\u5217 ... \u3053\
    \u3053\u3067\u306F\u3001vector<vector<long long>> \u306E\u4E8C\u6B21\u5143\u914D\
    \u5217\u3067\u5B9A\u7FA9\u3055\u308C\u307E\u3059\u3002\n\n// \u884C\u5217\u306E\
    \u7D2F\u4E57 (mod. m) \u3092\u8A08\u7B97\u3057\u307E\u3059\u3002: O(N^3 log n)\n\
    vector<vector<long long>> matrixpow(vector<vector<long long>> a, long long n,\
    \ long long m){\n\n    int siz = a.size();\n    vector<vector<long long>> b(siz,\
    \ vector<long long>(siz, 0));\n    for(int i = 0; i < siz; i++) b[i][i] = 1;\n\
    \n    auto mul = [](vector<vector<long long>> a, vector<vector<long long>> b,\
    \ long long m) -> vector<vector<long long>> {\n        vector<vector<long long>>\
    \ res((int) a.size(), vector<long long>(b[0].size()));\n        for(int i = 0;\
    \ i < (int) a.size(); i++){\n            for(int k = 0; k < (int) b.size(); k++){\n\
    \                for(int j = 0; j < (int) b[0].size(); j++){\n               \
    \     res[i][j] += a[i][k] * b[k][j];\n                    res[i][j] %= m;\n \
    \               }\n            }\n        }\n        return res;\n    };\n\n \
    \   while(n > 0){\n        if(n & 1) b = mul(b, a, m);\n        a = mul(a, a,\
    \ m);\n        n >>= 1;\n    }\n    return b;\n}\n\n// \u884C\u5217\u306E\u7A4D\
    \ (mod. m) \u3092\u8A08\u7B97\u3057\u307E\u3059\u3002: O(N^3)\nvector<vector<long\
    \ long>> mul(vector<vector<long long>> a, vector<vector<long long>> b, long long\
    \ m){\n    vector<vector<long long>> res((int) a.size(), vector<long long>(b[0].size()));\n\
    \    for(int i = 0; i < (int) a.size(); i++){\n        for(int k = 0; k < (int)\
    \ b.size(); k++){\n            for(int j = 0; j < (int) b[0].size(); j++){\n \
    \               res[i][j] += a[i][k] * b[k][j];\n                res[i][j] %=\
    \ m;\n            }\n        }\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/matrix.cpp
  requiredBy: []
  timestamp: '2022-09-04 03:09:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/matrix.cpp
layout: document
redirect_from:
- /library/lib/math/matrix.cpp
- /library/lib/math/matrix.cpp.html
title: lib/math/matrix.cpp
---
