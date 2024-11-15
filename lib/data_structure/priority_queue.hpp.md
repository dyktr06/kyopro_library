---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Eraseable\u3000Priority Queue (\u524A\u9664\u53EF\u80FD\u512A\
      \u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)"
    links: []
  bundledCode: "#line 2 \"lib/data_structure/priority_queue.hpp\"\n\n/**\n * @brief\
    \ Eraseable\u3000Priority Queue (\u524A\u9664\u53EF\u80FD\u512A\u5148\u5EA6\u4ED8\
    \u304D\u30AD\u30E5\u30FC)\n */\n\n#include <queue>\n#include <cassert>\n\ntemplate\
    \ <typename T>\nstruct PriorityQueue{\n    std::priority_queue<T> q, removed_q;\n\
    \n    PriorityQueue(){ }\n\n    void normalize(){\n        while(!q.empty() &&\
    \ !removed_q.empty()){\n            if(q.top() == removed_q.top()){\n        \
    \        q.pop();\n                removed_q.pop();\n            } else{\n   \
    \             break;\n            }\n        }\n    }\n\n    void push(const T\
    \ &x){\n        q.push(x);\n    }\n\n    void erase(const T &x){\n        removed_q.push(x);\n\
    \    }\n\n    size_t size(){\n        return q.size() - removed_q.size();\n  \
    \  }\n\n    bool empty(){\n        return (size() == 0);\n    }\n\n    T top(){\n\
    \        normalize();\n        assert(!q.empty());\n        return q.top();\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Eraseable\u3000Priority Queue (\u524A\u9664\
    \u53EF\u80FD\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC)\n */\n\n#include\
    \ <queue>\n#include <cassert>\n\ntemplate <typename T>\nstruct PriorityQueue{\n\
    \    std::priority_queue<T> q, removed_q;\n\n    PriorityQueue(){ }\n\n    void\
    \ normalize(){\n        while(!q.empty() && !removed_q.empty()){\n           \
    \ if(q.top() == removed_q.top()){\n                q.pop();\n                removed_q.pop();\n\
    \            } else{\n                break;\n            }\n        }\n    }\n\
    \n    void push(const T &x){\n        q.push(x);\n    }\n\n    void erase(const\
    \ T &x){\n        removed_q.push(x);\n    }\n\n    size_t size(){\n        return\
    \ q.size() - removed_q.size();\n    }\n\n    bool empty(){\n        return (size()\
    \ == 0);\n    }\n\n    T top(){\n        normalize();\n        assert(!q.empty());\n\
    \        return q.top();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/priority_queue.hpp
  requiredBy: []
  timestamp: '2024-11-15 16:27:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/priority_queue.hpp
layout: document
redirect_from:
- /library/lib/data_structure/priority_queue.hpp
- /library/lib/data_structure/priority_queue.hpp.html
title: "Eraseable\u3000Priority Queue (\u524A\u9664\u53EF\u80FD\u512A\u5148\u5EA6\u4ED8\
  \u304D\u30AD\u30E5\u30FC)"
---
