---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/priority_queue.hpp\"\n\ntemplate <typename\
    \ T>\nstruct PriorityQueue{\n    priority_queue<T> q, removed_q;\n\n    PriorityQueue(){\
    \ }\n\n    void normalize(){\n        while(!q.empty() && !removed_q.empty()){\n\
    \            if(q.top() == removed_q.top()){\n                q.pop();\n     \
    \           removed_q.pop();\n            }else{\n                break;\n   \
    \         }\n        }\n    }\n\n    void push(const T &x){\n        q.push(x);\n\
    \    }\n    \n    void erase(const T &x){\n        removed_q.push(x);\n    }\n\
    \    \n    size_t size(){\n        return q.size() - removed_q.size();\n    }\n\
    \n    bool empty(){\n        return (size() == 0);\n    }\n\n    T top(){\n  \
    \      normalize();\n        assert(!q.empty());\n        return q.top();\n  \
    \  }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct PriorityQueue{\n    priority_queue<T>\
    \ q, removed_q;\n\n    PriorityQueue(){ }\n\n    void normalize(){\n        while(!q.empty()\
    \ && !removed_q.empty()){\n            if(q.top() == removed_q.top()){\n     \
    \           q.pop();\n                removed_q.pop();\n            }else{\n \
    \               break;\n            }\n        }\n    }\n\n    void push(const\
    \ T &x){\n        q.push(x);\n    }\n    \n    void erase(const T &x){\n     \
    \   removed_q.push(x);\n    }\n    \n    size_t size(){\n        return q.size()\
    \ - removed_q.size();\n    }\n\n    bool empty(){\n        return (size() == 0);\n\
    \    }\n\n    T top(){\n        normalize();\n        assert(!q.empty());\n  \
    \      return q.top();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/priority_queue.hpp
  requiredBy: []
  timestamp: '2024-03-17 05:00:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/priority_queue.hpp
layout: document
redirect_from:
- /library/lib/data_structure/priority_queue.hpp
- /library/lib/data_structure/priority_queue.hpp.html
title: lib/data_structure/priority_queue.hpp
---
