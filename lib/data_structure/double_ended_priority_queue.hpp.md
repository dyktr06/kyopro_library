---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/double_ended_priority_queue.test.cpp
    title: test/library_checker/data_structure/double_ended_priority_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/double_ended_priority_queue.hpp\"\n\n\
    template <typename T>\nstruct DoubleEndedPriorityQueue{\n    multiset<T> q;\n\
    \    DoubleEndedPriorityQueue(){ }\n    \n    void push(const T &x){\n       \
    \ q.insert(x);\n    }\n    \n    void pop_min(){\n        assert(!q.empty());\n\
    \        q.erase(q.begin());\n    }\n    \n    void pop_max(){\n        assert(!q.empty());\n\
    \        q.erase(--q.end());\n    }\n    \n    T get_min() const{\n        return\
    \ *q.begin();\n    }\n    \n    T get_max() const{\n        return *(--q.end());\n\
    \    }\n    \n    size_t size() const{\n        return q.size();\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct DoubleEndedPriorityQueue{\n\
    \    multiset<T> q;\n    DoubleEndedPriorityQueue(){ }\n    \n    void push(const\
    \ T &x){\n        q.insert(x);\n    }\n    \n    void pop_min(){\n        assert(!q.empty());\n\
    \        q.erase(q.begin());\n    }\n    \n    void pop_max(){\n        assert(!q.empty());\n\
    \        q.erase(--q.end());\n    }\n    \n    T get_min() const{\n        return\
    \ *q.begin();\n    }\n    \n    T get_max() const{\n        return *(--q.end());\n\
    \    }\n    \n    size_t size() const{\n        return q.size();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/double_ended_priority_queue.hpp
  requiredBy: []
  timestamp: '2022-11-10 09:23:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/double_ended_priority_queue.test.cpp
documentation_of: lib/data_structure/double_ended_priority_queue.hpp
layout: document
redirect_from:
- /library/lib/data_structure/double_ended_priority_queue.hpp
- /library/lib/data_structure/double_ended_priority_queue.hpp.html
title: lib/data_structure/double_ended_priority_queue.hpp
---
