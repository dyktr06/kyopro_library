---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/cumulative_sum_2d.hpp
    title: Cumulative Sum 2D
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
    \ <iostream>\n\n#line 2 \"lib/data_structure/cumulative_sum_2d.hpp\"\n\n/**\n\
    \ * @brief Cumulative Sum 2D\n * @docs docs/data_structure/cumulative_sum_2d.md\n\
    \ */\n\n#include <vector>\n#include <cassert>\n\ntemplate <typename T>\nstruct\
    \ CumulativeSum2D{\n    int H, W;\n    std::vector<std::vector<T>> data;\n\n \
    \   CumulativeSum2D(const int _H, const int _W) : H(_H), W(_W), data(_H + 3, std::vector<T>(_W\
    \ + 3, 0)) {}\n\n    void add(int i, int j, const T &z){\n        ++i, ++j;\n\
    \        if(i >= (int) data.size() || j >= (int) data[0].size()) return;\n   \
    \     data[i][j] += z;\n    }\n\n    void imos(const int i1, const int j1, const\
    \ int i2, const int j2, const T &z = 1) {\n        assert(0 <= i1 && i1 <= i2\
    \ && i2 <= H);\n        assert(0 <= j1 && j1 <= j2 && j2 <= W);\n        add(i1,\
    \ j1, z);\n        add(i1, j2, -z);\n        add(i2, j1, -z);\n        add(i2,\
    \ j2, z);\n    }\n\n    void build(){\n        for(int i = 1; i < (int) data.size();\
    \ ++i){\n            for(int j = 1; j < (int) data[i].size(); ++j){\n        \
    \        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n\
    \            }\n        }\n    }\n\n    inline T imos_get(const int i, const int\
    \ j) const{\n        return data[i + 1][j + 1];\n    }\n\n    inline T sum(const\
    \ int i1, const int j1, const int i2, const int j2) const {\n        assert(0\
    \ <= i1 && i1 <= i2 && i2 <= H);\n        assert(0 <= j1 && j1 <= j2 && j2 <=\
    \ W);\n        return (data[i2][j2] - data[i1][j2] - data[i2][j1] + data[i1][j1]);\n\
    \    }\n};\n#line 5 \"test/aoj/dsl/dsl_5_b_cs2d.test.cpp\"\n\nusing namespace\
    \ std;\n\nint main(){\n    int n; cin >> n;\n    CumulativeSum2D<long long> s(1002,\
    \ 1002);\n    for(int i = 0; i < n; i++){\n        int x1, y1, x2, y2; cin >>\
    \ x1 >> y1 >> x2 >> y2;\n        s.imos(x1, y1, x2, y2, 1);\n    }\n    s.build();\n\
    \    long long ans = 0;\n    for(int i = 0; i <= 1000; i++){\n        for(int\
    \ j = 0; j <= 1000; j++){\n            ans = max(ans, s.sum(0, 0, i, j));\n  \
    \      }\n    }\n    cout << ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n#include <iostream>\n\n#include \"../../../lib/data_structure/cumulative_sum_2d.hpp\"\
    \n\nusing namespace std;\n\nint main(){\n    int n; cin >> n;\n    CumulativeSum2D<long\
    \ long> s(1002, 1002);\n    for(int i = 0; i < n; i++){\n        int x1, y1, x2,\
    \ y2; cin >> x1 >> y1 >> x2 >> y2;\n        s.imos(x1, y1, x2, y2, 1);\n    }\n\
    \    s.build();\n    long long ans = 0;\n    for(int i = 0; i <= 1000; i++){\n\
    \        for(int j = 0; j <= 1000; j++){\n            ans = max(ans, s.sum(0,\
    \ 0, i, j));\n        }\n    }\n    cout << ans << \"\\n\";\n}\n"
  dependsOn:
  - lib/data_structure/cumulative_sum_2d.hpp
  isVerificationFile: true
  path: test/aoj/dsl/dsl_5_b_cs2d.test.cpp
  requiredBy: []
  timestamp: '2024-11-15 16:06:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl/dsl_5_b_cs2d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl/dsl_5_b_cs2d.test.cpp
- /verify/test/aoj/dsl/dsl_5_b_cs2d.test.cpp.html
title: test/aoj/dsl/dsl_5_b_cs2d.test.cpp
---
