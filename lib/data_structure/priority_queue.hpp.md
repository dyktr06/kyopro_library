---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp
    title: lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
    title: test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Eraseable Priority Queue (\u524A\u9664\u53EF\u80FD\u512A\u5148\
      \u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)"
    links: []
  bundledCode: "#line 2 \"lib/data_structure/priority_queue.hpp\"\n\n/**\n * @brief\
    \ Eraseable Priority Queue (\u524A\u9664\u53EF\u80FD\u512A\u5148\u5EA6\u4ED8\u304D\
    \u30AD\u30E5\u30FC)\n */\n\n#include <queue>\n#include <cassert>\n\ntemplate <typename\
    \ T>\nstruct PriorityQueue{\n    std::priority_queue<T> q, removed_q;\n\n    PriorityQueue(){\
    \ }\n\n    void normalize(){\n        while(!q.empty() && !removed_q.empty()){\n\
    \            if(q.top() == removed_q.top()){\n                q.pop();\n     \
    \           removed_q.pop();\n            } else{\n                break;\n  \
    \          }\n        }\n    }\n\n    void push(const T &x){\n        q.push(x);\n\
    \    }\n\n    void erase(const T &x){\n        removed_q.push(x);\n    }\n\n \
    \   size_t size(){\n        return q.size() - removed_q.size();\n    }\n\n   \
    \ bool empty(){\n        return (size() == 0);\n    }\n\n    T top(){\n      \
    \  normalize();\n        assert(!q.empty());\n        return q.top();\n    }\n\
    };\n"
  code: "#pragma once\n\n/**\n * @brief Eraseable Priority Queue (\u524A\u9664\u53EF\
    \u80FD\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)\n */\n\n#include <queue>\n\
    #include <cassert>\n\ntemplate <typename T>\nstruct PriorityQueue{\n    std::priority_queue<T>\
    \ q, removed_q;\n\n    PriorityQueue(){ }\n\n    void normalize(){\n        while(!q.empty()\
    \ && !removed_q.empty()){\n            if(q.top() == removed_q.top()){\n     \
    \           q.pop();\n                removed_q.pop();\n            } else{\n\
    \                break;\n            }\n        }\n    }\n\n    void push(const\
    \ T &x){\n        q.push(x);\n    }\n\n    void erase(const T &x){\n        removed_q.push(x);\n\
    \    }\n\n    size_t size(){\n        return q.size() - removed_q.size();\n  \
    \  }\n\n    bool empty(){\n        return (size() == 0);\n    }\n\n    T top(){\n\
    \        normalize();\n        assert(!q.empty());\n        return q.top();\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/priority_queue.hpp
  requiredBy:
  - lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp
  timestamp: '2024-11-18 03:25:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
documentation_of: lib/data_structure/priority_queue.hpp
layout: document
redirect_from:
- /library/lib/data_structure/priority_queue.hpp
- /library/lib/data_structure/priority_queue.hpp.html
title: "Eraseable Priority Queue (\u524A\u9664\u53EF\u80FD\u512A\u5148\u5EA6\u4ED8\
  \u304D\u30AD\u30E5\u30FC)"
---
