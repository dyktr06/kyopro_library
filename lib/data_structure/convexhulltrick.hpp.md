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
    links: []
  bundledCode: "#line 2 \"lib/data_structure/convexhulltrick.hpp\"\n\n// \u3042\u308B\
    \ x \u306B\u5BFE\u3057\u3001\u76F4\u7DDA\u96C6\u5408\u306E\u4E2D\u3067\u6700\u5C0F\
    \u5024\u3092\u3068\u308B\u3088\u3046\u306A\u76F4\u7DDA\u306E\u5024\u3092\u6C42\
    \u3081\u307E\u3059\u3002\n// \u8FFD\u52A0\u3055\u308C\u308B\u76F4\u7DDA\u306E\u50BE\
    \u304D\u304C\u5358\u8ABF\u5897\u52A0\u3001\u8A08\u7B97\u3059\u308B\u6700\u5C0F\
    \u5024\u306E\u5EA7\u6A19\u304C\u5358\u8ABF\u5897\u52A0\u3067\u3042\u308B\u5FC5\
    \u8981\u304C\u3042\u308A\u307E\u3059\u3002\n// N\u672C\u306E\u76F4\u7DDA\u8FFD\
    \u52A0 : O(N)\u3001Q\u56DE\u306E\u30AF\u30A8\u30EA : O(Q)\ntemplate <typename\
    \ T>\nstruct ConvexHullTrick{\n    deque<pair<T, T>> deq;\n\n    ConvexHullTrick():\
    \ deq(){\n    }\n\n    bool check(pair<T, T> line1, pair<T, T> line2, pair<T,\
    \ T> line3){\n        return (line2.first - line1.first) * (line3.second - line2.second)\
    \ >= (line2.second - line1.second) * (line3.first - line2.first);\n    }\n\n \
    \   T f(pair<T, T> line, T x){\n        return line.first * x + line.second;\n\
    \    }\n\n    void add(T a, T b){\n        pair<T, T> p = {a, b};\n        while((int)\
    \ deq.size() >= 2 && check(deq.at((int) deq.size() - 2), deq.at((int) deq.size()\
    \ - 1), p)){\n            deq.pop_back();\n        }\n        deq.push_back(p);\n\
    \    }\n\n    T query(T x){\n        while((int) deq.size() >= 2 && f(deq.at(0),\
    \ x) >= f(deq.at(1), x)){\n            deq.pop_front();\n        }\n        return\
    \ f(deq.at(0), x);\n    }\n};\n"
  code: "#pragma once\n\n// \u3042\u308B x \u306B\u5BFE\u3057\u3001\u76F4\u7DDA\u96C6\
    \u5408\u306E\u4E2D\u3067\u6700\u5C0F\u5024\u3092\u3068\u308B\u3088\u3046\u306A\
    \u76F4\u7DDA\u306E\u5024\u3092\u6C42\u3081\u307E\u3059\u3002\n// \u8FFD\u52A0\u3055\
    \u308C\u308B\u76F4\u7DDA\u306E\u50BE\u304D\u304C\u5358\u8ABF\u5897\u52A0\u3001\
    \u8A08\u7B97\u3059\u308B\u6700\u5C0F\u5024\u306E\u5EA7\u6A19\u304C\u5358\u8ABF\
    \u5897\u52A0\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308A\u307E\u3059\u3002\
    \n// N\u672C\u306E\u76F4\u7DDA\u8FFD\u52A0 : O(N)\u3001Q\u56DE\u306E\u30AF\u30A8\
    \u30EA : O(Q)\ntemplate <typename T>\nstruct ConvexHullTrick{\n    deque<pair<T,\
    \ T>> deq;\n\n    ConvexHullTrick(): deq(){\n    }\n\n    bool check(pair<T, T>\
    \ line1, pair<T, T> line2, pair<T, T> line3){\n        return (line2.first - line1.first)\
    \ * (line3.second - line2.second) >= (line2.second - line1.second) * (line3.first\
    \ - line2.first);\n    }\n\n    T f(pair<T, T> line, T x){\n        return line.first\
    \ * x + line.second;\n    }\n\n    void add(T a, T b){\n        pair<T, T> p =\
    \ {a, b};\n        while((int) deq.size() >= 2 && check(deq.at((int) deq.size()\
    \ - 2), deq.at((int) deq.size() - 1), p)){\n            deq.pop_back();\n    \
    \    }\n        deq.push_back(p);\n    }\n\n    T query(T x){\n        while((int)\
    \ deq.size() >= 2 && f(deq.at(0), x) >= f(deq.at(1), x)){\n            deq.pop_front();\n\
    \        }\n        return f(deq.at(0), x);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/convexhulltrick.hpp
  requiredBy: []
  timestamp: '2022-11-11 04:34:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_2078.test.cpp
documentation_of: lib/data_structure/convexhulltrick.hpp
layout: document
redirect_from:
- /library/lib/data_structure/convexhulltrick.hpp
- /library/lib/data_structure/convexhulltrick.hpp.html
title: lib/data_structure/convexhulltrick.hpp
---
