---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/cumulative_sum_2d.hpp
    title: lib/data_structure/cumulative_sum_2d.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
  bundledCode: "#line 1 \"test/aoj/dsl/dsl_5_b_cs2d.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/cumulative_sum_2d.hpp\"\
    \n\n/* \n    CumulativeSum2D<T>(H, W) : CumulativeSum2D\u3092\u30B5\u30A4\u30BA\
    \ H * W \u3067\u69CB\u7BC9\n    add(i, j, z) : (i, j) \u306B z \u3092\u52A0\u7B97\
    \u3057\u307E\u3059\u3002 O(1)\n    imos(i1, j1, i2, j2, v) : \u3044\u3082\u3059\
    \u6CD5\u306B\u304A\u3044\u3066\u3001[(i1, j1), (i2, j2) ) \u306B z \u3092\u52A0\
    \u7B97\u3057\u307E\u3059\u3002O(1)\n    build() : \u52A0\u7B97\u3055\u308C\u305F\
    \u914D\u5217\u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002O(HW)\n    sum(i1, j1, i2,\
    \ j2) : [(x1, y1), (x2, y2) ) \u306E\u548C\u3092\u53D6\u5F97\u3057\u307E\u3059\
    \u3002O(1)\n*/\n\ntemplate <typename T>\nstruct CumulativeSum2D{\n    vector<vector<T>>\
    \ data;\n\n    CumulativeSum2D(const int &H, const int &W) : data(H + 3, vector<T>(W\
    \ + 3, 0)) {}\n\n    void add(int i, int j, const T &z){\n        ++i, ++j;\n\
    \        if(i >= (int) data.size() || j >= (int) data[0].size()) return;\n   \
    \     data[i][j] += z;\n    }\n\n    void imos(const int &i1, const int &j1, const\
    \ int &i2, const int &j2, const T &z = 1) {\n        add(i1, j1, z);\n       \
    \ add(i1, j2, -z);\n        add(i2, j1, -z);\n        add(i2, j2, z);\n    }\n\
    \n    void build(){\n        for(int i = 1; i < (int) data.size(); ++i){\n   \
    \         for(int j = 1; j < (int) data[i].size(); ++j){\n                data[i][j]\
    \ += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n            }\n  \
    \      }\n    }\n\n    inline T imos_get(const int &i, const int &j) const{\n\
    \        return data[i + 1][j + 1];\n    }\n\n    inline T sum(const int &i1,\
    \ const int &j1, const int &i2, const int &j2) const {\n        return (data[i2][j2]\
    \ - data[i1][j2] - data[i2][j1] + data[i1][j1]);\n    }\n};\n#line 6 \"test/aoj/dsl/dsl_5_b_cs2d.test.cpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    CumulativeSum2D<long long> s(1002,\
    \ 1002);\n    for(int i = 0; i < n; i++){\n        int x1, y1, x2, y2; cin >>\
    \ x1 >> y1 >> x2 >> y2;\n        s.imos(x1, y1, x2, y2, 1);\n    }\n    s.build();\n\
    \    long long ans = 0;\n    for(int i = 0; i <= 1000; i++){\n        for(int\
    \ j = 0; j <= 1000; j++){\n            ans = max(ans, s.sum(0, 0, i, j));\n  \
    \      }\n    }\n    cout << ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/cumulative_sum_2d.hpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    CumulativeSum2D<long long> s(1002,\
    \ 1002);\n    for(int i = 0; i < n; i++){\n        int x1, y1, x2, y2; cin >>\
    \ x1 >> y1 >> x2 >> y2;\n        s.imos(x1, y1, x2, y2, 1);\n    }\n    s.build();\n\
    \    long long ans = 0;\n    for(int i = 0; i <= 1000; i++){\n        for(int\
    \ j = 0; j <= 1000; j++){\n            ans = max(ans, s.sum(0, 0, i, j));\n  \
    \      }\n    }\n    cout << ans << \"\\n\";\n}"
  dependsOn:
  - lib/data_structure/cumulative_sum_2d.hpp
  isVerificationFile: true
  path: test/aoj/dsl/dsl_5_b_cs2d.test.cpp
  requiredBy: []
  timestamp: '2022-11-24 20:00:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl/dsl_5_b_cs2d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl/dsl_5_b_cs2d.test.cpp
- /verify/test/aoj/dsl/dsl_5_b_cs2d.test.cpp.html
title: test/aoj/dsl/dsl_5_b_cs2d.test.cpp
---
