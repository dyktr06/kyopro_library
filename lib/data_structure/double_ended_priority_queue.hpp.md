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
    template <typename T>\nstruct DoubleEndedPriorityQueue{\n    priority_queue<T,\
    \ vector<T>, greater<T>> min_q, removed_min;\n    priority_queue<T> max_q, removed_max;\n\
    \    DoubleEndedPriorityQueue(){ }\n    \n    void normalize(){\n        while(!removed_min.empty()\
    \ && min_q.top() == removed_min.top()) {\n            removed_min.pop();\n   \
    \         min_q.pop();\n        }\n        while(!removed_max.empty() && max_q.top()\
    \ == removed_max.top()) {\n            removed_max.pop();\n            max_q.pop();\n\
    \        }\n    }\n\n    void push(const T &x){\n        min_q.push(x);\n    \
    \    max_q.push(x);\n    }\n    \n    void pop_min(){\n        assert(!min_q.empty());\n\
    \        normalize();\n        removed_max.push(min_q.top());\n        min_q.pop();\n\
    \    }\n    \n    void pop_max(){\n        assert(!max_q.empty());\n        normalize();\n\
    \        removed_min.push(max_q.top());\n        max_q.pop();\n    }\n    \n \
    \   T get_min(){\n        assert(!min_q.empty());\n        normalize();\n    \
    \    return min_q.top();\n    }\n    \n    T get_max(){\n        assert(!max_q.empty());\n\
    \        normalize();\n        return max_q.top();\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct DoubleEndedPriorityQueue{\n\
    \    priority_queue<T, vector<T>, greater<T>> min_q, removed_min;\n    priority_queue<T>\
    \ max_q, removed_max;\n    DoubleEndedPriorityQueue(){ }\n    \n    void normalize(){\n\
    \        while(!removed_min.empty() && min_q.top() == removed_min.top()) {\n \
    \           removed_min.pop();\n            min_q.pop();\n        }\n        while(!removed_max.empty()\
    \ && max_q.top() == removed_max.top()) {\n            removed_max.pop();\n   \
    \         max_q.pop();\n        }\n    }\n\n    void push(const T &x){\n     \
    \   min_q.push(x);\n        max_q.push(x);\n    }\n    \n    void pop_min(){\n\
    \        assert(!min_q.empty());\n        normalize();\n        removed_max.push(min_q.top());\n\
    \        min_q.pop();\n    }\n    \n    void pop_max(){\n        assert(!max_q.empty());\n\
    \        normalize();\n        removed_min.push(max_q.top());\n        max_q.pop();\n\
    \    }\n    \n    T get_min(){\n        assert(!min_q.empty());\n        normalize();\n\
    \        return min_q.top();\n    }\n    \n    T get_max(){\n        assert(!max_q.empty());\n\
    \        normalize();\n        return max_q.top();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/double_ended_priority_queue.hpp
  requiredBy: []
  timestamp: '2023-04-13 08:33:52+09:00'
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
