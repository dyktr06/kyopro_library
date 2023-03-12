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
  bundledCode: "#line 1 \"lib/data_structure/imos_linear.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n/* \n    imos_linear<T>(n) : \u30B5\u30A4\u30BAn\u3067\
    \u69CB\u7BC9\n    add(l, r, v, w) : [l, r) \u306B wX + v \u3092\u52A0\u7B97\u3057\
    \u307E\u3059\u3002 O(1)\n    build() : \u52A0\u7B97\u3055\u308C\u305F\u914D\u5217\
    \u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002O(n)\n*/\n\ntemplate <typename T>\n\
    struct imos_linear{\n    int N;\n    vector<T> imos1, imos0;\n    imos_linear(int\
    \ N) : N(N){ init(); }\n\n    void init(){\n        imos1.resize(N + 1);\n   \
    \     imos0.resize(N + 1);\n    }\n\n    // [l, r) \u306B wX + v \u3092\u52A0\u7B97\
    \ \n    // imos[l] += v, imos[l + 1] += v + w, ...\n    void add(int l, int r,\
    \ T v, T w){\n        l = clamp(l, 0, N), r = clamp(r, 0, N);\n        imos1[l]\
    \ += w;\n        imos1[r] -= w;\n        imos0[l] += v - w;\n        imos0[r]\
    \ -= v + w * (r - l - 1);\n    }\n\n    void build(){\n        for(int i = 0;\
    \ i < N - 1; i++){\n            imos1[i + 1] += imos1[i];\n            imos0[i]\
    \ += imos1[i];\n            imos0[i + 1] += imos0[i];\n        }\n    }\n    \n\
    \    T & operator [](int i){\n        return imos0[i];\n    }\n};\n\n// example\
    \ (ABC268E)\nint main(){\n    int n; cin >> n;\n    vector<int> p(n);\n    for(int\
    \ i = 0; i < n; i++){\n        cin >> p[i];\n    }\n\n    imos_linear<long long>\
    \ imos(n * 2 + 1);\n\n    int m = (n + 1) / 2, v = n / 2;\n    for(int i = 0;\
    \ i < n; i++){\n        int l = (p[i] - i + n) % n;\n        imos.add(l, l + m,\
    \ 0, 1);\n        imos.add(l + m, l + n, v, -1);\n    }\n    imos.build();\n\n\
    \    vector<long long> res(n);\n    for(int i = 0; i < 2 * n + 1; i++){\n    \
    \    res[i % n] += imos[i];\n    }\n\n    long long ans = 1LL << 60;\n    for(int\
    \ i = 0; i < n; i++){\n        ans = min(ans, res[i]);\n    }\n    cout << ans\
    \ << \"\\n\";\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n/* \n    imos_linear<T>(n)\
    \ : \u30B5\u30A4\u30BAn\u3067\u69CB\u7BC9\n    add(l, r, v, w) : [l, r) \u306B\
    \ wX + v \u3092\u52A0\u7B97\u3057\u307E\u3059\u3002 O(1)\n    build() : \u52A0\
    \u7B97\u3055\u308C\u305F\u914D\u5217\u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002\
    O(n)\n*/\n\ntemplate <typename T>\nstruct imos_linear{\n    int N;\n    vector<T>\
    \ imos1, imos0;\n    imos_linear(int N) : N(N){ init(); }\n\n    void init(){\n\
    \        imos1.resize(N + 1);\n        imos0.resize(N + 1);\n    }\n\n    // [l,\
    \ r) \u306B wX + v \u3092\u52A0\u7B97 \n    // imos[l] += v, imos[l + 1] += v\
    \ + w, ...\n    void add(int l, int r, T v, T w){\n        l = clamp(l, 0, N),\
    \ r = clamp(r, 0, N);\n        imos1[l] += w;\n        imos1[r] -= w;\n      \
    \  imos0[l] += v - w;\n        imos0[r] -= v + w * (r - l - 1);\n    }\n\n   \
    \ void build(){\n        for(int i = 0; i < N - 1; i++){\n            imos1[i\
    \ + 1] += imos1[i];\n            imos0[i] += imos1[i];\n            imos0[i +\
    \ 1] += imos0[i];\n        }\n    }\n    \n    T & operator [](int i){\n     \
    \   return imos0[i];\n    }\n};\n\n// example (ABC268E)\nint main(){\n    int\
    \ n; cin >> n;\n    vector<int> p(n);\n    for(int i = 0; i < n; i++){\n     \
    \   cin >> p[i];\n    }\n\n    imos_linear<long long> imos(n * 2 + 1);\n\n   \
    \ int m = (n + 1) / 2, v = n / 2;\n    for(int i = 0; i < n; i++){\n        int\
    \ l = (p[i] - i + n) % n;\n        imos.add(l, l + m, 0, 1);\n        imos.add(l\
    \ + m, l + n, v, -1);\n    }\n    imos.build();\n\n    vector<long long> res(n);\n\
    \    for(int i = 0; i < 2 * n + 1; i++){\n        res[i % n] += imos[i];\n   \
    \ }\n\n    long long ans = 1LL << 60;\n    for(int i = 0; i < n; i++){\n     \
    \   ans = min(ans, res[i]);\n    }\n    cout << ans << \"\\n\";\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/imos_linear.cpp
  requiredBy: []
  timestamp: '2023-03-01 02:13:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/imos_linear.cpp
layout: document
redirect_from:
- /library/lib/data_structure/imos_linear.cpp
- /library/lib/data_structure/imos_linear.cpp.html
title: lib/data_structure/imos_linear.cpp
---
