---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_2078.test.cpp
    title: test/yukicoder/yuki_2078.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/convex_hull_trick.md
    document_title: Convex Hull Trick
    links: []
  bundledCode: "#line 2 \"lib/data_structure/convex_hull_trick.hpp\"\n\n/**\n * @brief\
    \ Convex Hull Trick\n * @docs docs/data_structure/convex_hull_trick.md\n */\n\n\
    template <typename T>\nstruct ConvexHullTrick{\n    deque<pair<T, T>> deq;\n\n\
    \    ConvexHullTrick(): deq(){\n    }\n\n    bool check(pair<T, T> line1, pair<T,\
    \ T> line2, pair<T, T> line3){\n        return (line2.first - line1.first) * (line3.second\
    \ - line2.second) >= (line2.second - line1.second) * (line3.first - line2.first);\n\
    \    }\n\n    T f(pair<T, T> line, T x){\n        return line.first * x + line.second;\n\
    \    }\n\n    // ax + b\n    void add(T a, T b){\n        pair<T, T> p = {a, b};\n\
    \        while((int) deq.size() >= 2 && check(deq.at((int) deq.size() - 2), deq.at((int)\
    \ deq.size() - 1), p)){\n            deq.pop_back();\n        }\n        deq.push_back(p);\n\
    \    }\n\n    T query(T x){\n        while((int) deq.size() >= 2 && f(deq.at(0),\
    \ x) >= f(deq.at(1), x)){\n            deq.pop_front();\n        }\n        return\
    \ f(deq.at(0), x);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Convex Hull Trick\n * @docs docs/data_structure/convex_hull_trick.md\n\
    \ */\n\ntemplate <typename T>\nstruct ConvexHullTrick{\n    deque<pair<T, T>>\
    \ deq;\n\n    ConvexHullTrick(): deq(){\n    }\n\n    bool check(pair<T, T> line1,\
    \ pair<T, T> line2, pair<T, T> line3){\n        return (line2.first - line1.first)\
    \ * (line3.second - line2.second) >= (line2.second - line1.second) * (line3.first\
    \ - line2.first);\n    }\n\n    T f(pair<T, T> line, T x){\n        return line.first\
    \ * x + line.second;\n    }\n\n    // ax + b\n    void add(T a, T b){\n      \
    \  pair<T, T> p = {a, b};\n        while((int) deq.size() >= 2 && check(deq.at((int)\
    \ deq.size() - 2), deq.at((int) deq.size() - 1), p)){\n            deq.pop_back();\n\
    \        }\n        deq.push_back(p);\n    }\n\n    T query(T x){\n        while((int)\
    \ deq.size() >= 2 && f(deq.at(0), x) >= f(deq.at(1), x)){\n            deq.pop_front();\n\
    \        }\n        return f(deq.at(0), x);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/convex_hull_trick.hpp
  requiredBy: []
  timestamp: '2024-02-14 05:31:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_2078.test.cpp
documentation_of: lib/data_structure/convex_hull_trick.hpp
layout: document
redirect_from:
- /library/lib/data_structure/convex_hull_trick.hpp
- /library/lib/data_structure/convex_hull_trick.hpp.html
title: Convex Hull Trick
---
## Convex Hull Trick

#### 使い方

注意: 追加される直線の傾きが単調増加、計算する最小値の座標が単調増加である必要があります。(単調でない場合は Dynamic Li Chao Tree を使う。)

- `ConvexHullTrick<T>()`: ConvexHullTrick を構築します。
- `add(a, b)`: 直線集合に ax + b の直線を追加します。
- `query(x)`: x で最小値をとるような値を求めます。

#### 計算量

- `add(a, b)`: $\mathrm{O}(1)$
- `query(x)`: $\mathrm{O}(1)$