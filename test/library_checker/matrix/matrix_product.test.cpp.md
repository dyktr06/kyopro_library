---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/matrix.hpp
    title: lib/math/matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/library_checker/matrix/matrix_product.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/math/matrix.hpp\"\n\n// \u884C\u5217 ...\
    \ \u3053\u3053\u3067\u306F\u3001vector<vector<long long>> \u306E\u4E8C\u6B21\u5143\
    \u914D\u5217\u3067\u5B9A\u7FA9\u3055\u308C\u307E\u3059\u3002\n\n// \u884C\u5217\
    \u306E\u7D2F\u4E57 (mod. m) \u3092\u8A08\u7B97\u3057\u307E\u3059\u3002: O(N^3\
    \ log n)\nvector<vector<long long>> matrixpow(vector<vector<long long>> a, long\
    \ long n, long long m){\n\n    int siz = a.size();\n    vector<vector<long long>>\
    \ b(siz, vector<long long>(siz, 0));\n    for(int i = 0; i < siz; i++) b[i][i]\
    \ = 1;\n\n    auto mul = [](vector<vector<long long>> a, vector<vector<long long>>\
    \ b, long long m) -> vector<vector<long long>> {\n        vector<vector<long long>>\
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
    \ m;\n            }\n        }\n    }\n    return res;\n}\n#line 6 \"test/library_checker/matrix/matrix_product.test.cpp\"\
    \n\nconst long long MOD = 998244353;\n\nint main(){\n    int n, m, k; cin >> n\
    \ >> m >> k;\n    vector<vector<long long>> a(n, vector<long long>(m));\n    vector<vector<long\
    \ long>> b(m, vector<long long>(k));\n    for(int i = 0; i < n; i++){\n      \
    \  for(int j = 0; j < m; j++){\n            cin >> a[i][j];\n        }\n    }\n\
    \    for(int i = 0; i < m; i++){\n        for(int j = 0; j < k; j++){\n      \
    \      cin >> b[i][j];\n        }\n    }\n    vector<vector<long long>> c = mul(a,\
    \ b, MOD);\n    for(int i = 0; i < n; i++){\n        for(int j = 0; j < k; j++){\n\
    \            if(j >= 1) cout << \" \";\n            cout << c[i][j];\n       \
    \ }\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/matrix.hpp\"\
    \n\nconst long long MOD = 998244353;\n\nint main(){\n    int n, m, k; cin >> n\
    \ >> m >> k;\n    vector<vector<long long>> a(n, vector<long long>(m));\n    vector<vector<long\
    \ long>> b(m, vector<long long>(k));\n    for(int i = 0; i < n; i++){\n      \
    \  for(int j = 0; j < m; j++){\n            cin >> a[i][j];\n        }\n    }\n\
    \    for(int i = 0; i < m; i++){\n        for(int j = 0; j < k; j++){\n      \
    \      cin >> b[i][j];\n        }\n    }\n    vector<vector<long long>> c = mul(a,\
    \ b, MOD);\n    for(int i = 0; i < n; i++){\n        for(int j = 0; j < k; j++){\n\
    \            if(j >= 1) cout << \" \";\n            cout << c[i][j];\n       \
    \ }\n        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/math/matrix.hpp
  isVerificationFile: true
  path: test/library_checker/matrix/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2022-11-10 10:41:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/matrix/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/matrix/matrix_product.test.cpp
- /verify/test/library_checker/matrix/matrix_product.test.cpp.html
title: test/library_checker/matrix/matrix_product.test.cpp
---
