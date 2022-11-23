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
  bundledCode: "#line 2 \"lib/data_structure/persistent_stack.hpp\"\n\ntemplate<typename\
    \ T>\nstruct PersistentStack{\n    T val;\n    PersistentStack *next = nullptr;\n\
    \    int exist = 0;\n\n    PersistentStack(const T &_val, PersistentStack *_next)\
    \ : val(_val), next(_next){\n        exist = _next->exist + 1;\n    }\n\n    PersistentStack(){\n\
    \    }\n\n    int size() const {\n        return exist;\n    }\n\n    bool empty()\
    \ const {\n        return size() == 0;\n    }\n\n    T top() const {\n       \
    \ return val;\n    }\n\n    PersistentStack *pop() const {\n        return next;\n\
    \    }\n    \n    PersistentStack *push(const T &x){\n        return new PersistentStack(x,\
    \ this);\n    }\n};\n"
  code: "#pragma once\n\ntemplate<typename T>\nstruct PersistentStack{\n    T val;\n\
    \    PersistentStack *next = nullptr;\n    int exist = 0;\n\n    PersistentStack(const\
    \ T &_val, PersistentStack *_next) : val(_val), next(_next){\n        exist =\
    \ _next->exist + 1;\n    }\n\n    PersistentStack(){\n    }\n\n    int size()\
    \ const {\n        return exist;\n    }\n\n    bool empty() const {\n        return\
    \ size() == 0;\n    }\n\n    T top() const {\n        return val;\n    }\n\n \
    \   PersistentStack *pop() const {\n        return next;\n    }\n    \n    PersistentStack\
    \ *push(const T &x){\n        return new PersistentStack(x, this);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/persistent_stack.hpp
  requiredBy: []
  timestamp: '2022-11-23 22:11:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/persistent_stack.hpp
layout: document
redirect_from:
- /library/lib/data_structure/persistent_stack.hpp
- /library/lib/data_structure/persistent_stack.hpp.html
title: lib/data_structure/persistent_stack.hpp
---
