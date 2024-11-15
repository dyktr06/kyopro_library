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
    #include <deque>\n#include <utility>\n\n// ax + by + c = 0 -> y = -b/a x - c/a\n\
    template <typename T>\nstruct Line{\n    T a, b, c;\n    Line(T A = 0, T B = 0,\
    \ T C = 0) : a(A), b(B), c(C) {}\n    // \u50BE\u304D\n    inline bool operator<(const\
    \ Line &other) const {\n        return -a * other.b < -other.a * b;\n    }\n \
    \   inline bool operator>(const Line &other) const {\n        return -a * other.b\
    \ > -other.a * b;\n    }\n    inline bool operator<=(const Line &other) const\
    \ {\n        return -a * other.b <= -other.a * b;\n    }\n    inline bool operator>=(const\
    \ Line &other) const {\n        return -a * other.b >= -other.a * b;\n    }\n\
    };\n\ntemplate <typename T>\nstruct ConvexHullTrick{\n    std::deque<Line<T>>\
    \ deq;\n\n    ConvexHullTrick() : deq(){\n    }\n\n    bool check(Line<T> l1,\
    \ Line<T> l2, Line<T> l3){\n        T a = ((-l3.c * l2.b) - (-l2.c * l3.b)) *\
    \ ((-l2.a * l1.b) - (-l1.a * l2.b));\n        T b = ((-l2.c * l1.b) - (-l1.c *\
    \ l2.b)) * ((-l3.a * l2.b) - (-l2.a * l3.b));\n        return a >= b;\n    }\n\
    \n    // l1(x) < l2(x)\n    bool comp(Line<T> l1, Line<T> l2, T x){\n        //\
    \ -(ax + c)/b < -(dx + f)/e\n        return -(l1.a * x + l1.c) * l2.b < -(l2.a\
    \ * x + l2.c) * l1.b;\n    };\n\n    // first/second\n    std::pair<T, T> f(Line<T>\
    \ l, T x){\n        T a = -l.a * x - l.c;\n        T b = l.b;\n        if(b <\
    \ 0) a *= -1, b *= -1;\n        return std::make_pair(a, b);\n    };\n\n    //\
    \ y = ax + b\n    void add(T a, T b){\n        Line<T> p(a, -1, b);\n        while((int)\
    \ deq.size() >= 2 && check(deq.at((int) deq.size() - 2), deq.at((int) deq.size()\
    \ - 1), p)){\n            deq.pop_back();\n        }\n        deq.push_back(p);\n\
    \    }\n\n    // ax + by + c = 0\n    void add(T a, T b, T c){\n        Line<T>\
    \ p(a, b, c);\n        while((int) deq.size() >= 2 && check(deq.at((int) deq.size()\
    \ - 2), deq.at((int) deq.size() - 1), p)){\n            deq.pop_back();\n    \
    \    }\n        deq.push_back(p);\n    }\n\n    std::pair<T, T> query(T x){\n\
    \        while((int) deq.size() >= 2 && !comp(deq.at(0), deq.at(1), x)){\n   \
    \         deq.pop_front();\n        }\n        return f(deq.at(0), x);\n    }\n\
    };\n"
  code: "#pragma once\n\n/**\n * @brief Convex Hull Trick\n * @docs docs/data_structure/convex_hull_trick.md\n\
    \ */\n\n#include <deque>\n#include <utility>\n\n// ax + by + c = 0 -> y = -b/a\
    \ x - c/a\ntemplate <typename T>\nstruct Line{\n    T a, b, c;\n    Line(T A =\
    \ 0, T B = 0, T C = 0) : a(A), b(B), c(C) {}\n    // \u50BE\u304D\n    inline\
    \ bool operator<(const Line &other) const {\n        return -a * other.b < -other.a\
    \ * b;\n    }\n    inline bool operator>(const Line &other) const {\n        return\
    \ -a * other.b > -other.a * b;\n    }\n    inline bool operator<=(const Line &other)\
    \ const {\n        return -a * other.b <= -other.a * b;\n    }\n    inline bool\
    \ operator>=(const Line &other) const {\n        return -a * other.b >= -other.a\
    \ * b;\n    }\n};\n\ntemplate <typename T>\nstruct ConvexHullTrick{\n    std::deque<Line<T>>\
    \ deq;\n\n    ConvexHullTrick() : deq(){\n    }\n\n    bool check(Line<T> l1,\
    \ Line<T> l2, Line<T> l3){\n        T a = ((-l3.c * l2.b) - (-l2.c * l3.b)) *\
    \ ((-l2.a * l1.b) - (-l1.a * l2.b));\n        T b = ((-l2.c * l1.b) - (-l1.c *\
    \ l2.b)) * ((-l3.a * l2.b) - (-l2.a * l3.b));\n        return a >= b;\n    }\n\
    \n    // l1(x) < l2(x)\n    bool comp(Line<T> l1, Line<T> l2, T x){\n        //\
    \ -(ax + c)/b < -(dx + f)/e\n        return -(l1.a * x + l1.c) * l2.b < -(l2.a\
    \ * x + l2.c) * l1.b;\n    };\n\n    // first/second\n    std::pair<T, T> f(Line<T>\
    \ l, T x){\n        T a = -l.a * x - l.c;\n        T b = l.b;\n        if(b <\
    \ 0) a *= -1, b *= -1;\n        return std::make_pair(a, b);\n    };\n\n    //\
    \ y = ax + b\n    void add(T a, T b){\n        Line<T> p(a, -1, b);\n        while((int)\
    \ deq.size() >= 2 && check(deq.at((int) deq.size() - 2), deq.at((int) deq.size()\
    \ - 1), p)){\n            deq.pop_back();\n        }\n        deq.push_back(p);\n\
    \    }\n\n    // ax + by + c = 0\n    void add(T a, T b, T c){\n        Line<T>\
    \ p(a, b, c);\n        while((int) deq.size() >= 2 && check(deq.at((int) deq.size()\
    \ - 2), deq.at((int) deq.size() - 1), p)){\n            deq.pop_back();\n    \
    \    }\n        deq.push_back(p);\n    }\n\n    std::pair<T, T> query(T x){\n\
    \        while((int) deq.size() >= 2 && !comp(deq.at(0), deq.at(1), x)){\n   \
    \         deq.pop_front();\n        }\n        return f(deq.at(0), x);\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/convex_hull_trick.hpp
  requiredBy: []
  timestamp: '2024-11-15 16:06:01+09:00'
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