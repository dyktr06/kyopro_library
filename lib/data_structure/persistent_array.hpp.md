---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/persistent_queue.hpp
    title: lib/data_structure/persistent_queue.hpp
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/persistent_union_find.hpp
    title: lib/data_structure/persistent_union_find.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/persistent_queue.test.cpp
    title: test/library_checker/data_structure/persistent_queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/persistent_unionfind.test.cpp
    title: test/library_checker/data_structure/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/persistent_array.hpp\"\n\ntemplate<typename\
    \ T>\nstruct PersistentArray{\n    struct Node{\n        T data;\n        Node\
    \ *ch[20] = {};\n    };\n    Node *root = nullptr;\n\n    PersistentArray() {}\n\
    \    \n    Node *get_root(){\n        return root;\n    }\n\n    void destructive_set(const\
    \ int &i, const T &val, Node *&t){\n        if(!t) t = new Node();\n        if(i\
    \ == 0){\n            t->data = val;\n        }else{\n            destructive_set(i\
    \ / 20, val, t->ch[i % 20]);\n        }\n    }\n\n    Node *set(const int &i,\
    \ const T &val, Node *&t){\n        Node *res = new Node();\n        if(t){\n\
    \            memcpy(res->ch, t->ch, sizeof(t->ch));\n            res->data = t->data;\n\
    \        }\n        if(i == 0){\n            res->data = val;\n        }else{\n\
    \            res->ch[i % 20] = set(i / 20, val, res->ch[i % 20]);\n        }\n\
    \        return res;\n    }\n\n    T get(const int &i, Node *t){\n        if(!t)\
    \ return T();\n        if(i == 0){\n            return t->data;\n        }else{\n\
    \            return get(i / 20, t->ch[i % 20]);\n        }\n    }\n};\n"
  code: "#pragma once\n\ntemplate<typename T>\nstruct PersistentArray{\n    struct\
    \ Node{\n        T data;\n        Node *ch[20] = {};\n    };\n    Node *root =\
    \ nullptr;\n\n    PersistentArray() {}\n    \n    Node *get_root(){\n        return\
    \ root;\n    }\n\n    void destructive_set(const int &i, const T &val, Node *&t){\n\
    \        if(!t) t = new Node();\n        if(i == 0){\n            t->data = val;\n\
    \        }else{\n            destructive_set(i / 20, val, t->ch[i % 20]);\n  \
    \      }\n    }\n\n    Node *set(const int &i, const T &val, Node *&t){\n    \
    \    Node *res = new Node();\n        if(t){\n            memcpy(res->ch, t->ch,\
    \ sizeof(t->ch));\n            res->data = t->data;\n        }\n        if(i ==\
    \ 0){\n            res->data = val;\n        }else{\n            res->ch[i % 20]\
    \ = set(i / 20, val, res->ch[i % 20]);\n        }\n        return res;\n    }\n\
    \n    T get(const int &i, Node *t){\n        if(!t) return T();\n        if(i\
    \ == 0){\n            return t->data;\n        }else{\n            return get(i\
    \ / 20, t->ch[i % 20]);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/persistent_array.hpp
  requiredBy:
  - lib/data_structure/persistent_queue.hpp
  - lib/data_structure/persistent_union_find.hpp
  timestamp: '2022-11-23 22:11:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/persistent_unionfind.test.cpp
  - test/library_checker/data_structure/persistent_queue.test.cpp
documentation_of: lib/data_structure/persistent_array.hpp
layout: document
redirect_from:
- /library/lib/data_structure/persistent_array.hpp
- /library/lib/data_structure/persistent_array.hpp.html
title: lib/data_structure/persistent_array.hpp
---
