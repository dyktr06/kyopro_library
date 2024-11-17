---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/persistent_array.hpp
    title: "Persistent Array (\u6C38\u7D9A\u914D\u5217)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/persistent_queue.test.cpp
    title: test/library_checker/data_structure/persistent_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Persistent Queue (\u6C38\u7D9A\u30AD\u30E5\u30FC)"
    links: []
  bundledCode: "#line 2 \"lib/data_structure/persistent_queue.hpp\"\n\n/**\n * @brief\
    \ Persistent Queue (\u6C38\u7D9A\u30AD\u30E5\u30FC)\n */\n\n#include <vector>\n\
    \n#line 2 \"lib/data_structure/persistent_array.hpp\"\n\n/**\n * @brief Persistent\
    \ Array (\u6C38\u7D9A\u914D\u5217)\n */\n\n#include <cstring>\n\ntemplate<typename\
    \ T>\nstruct PersistentArray{\n    struct Node{\n        T data;\n        Node\
    \ *ch[20] = {};\n    };\n    Node *root = nullptr;\n\n    PersistentArray() {}\n\
    \n    Node *get_root(){\n        return root;\n    }\n\n    void destructive_set(const\
    \ int i, const T &val, Node *&t){\n        if(!t) t = new Node();\n        if(i\
    \ == 0){\n            t->data = val;\n        } else{\n            destructive_set(i\
    \ / 20, val, t->ch[i % 20]);\n        }\n    }\n\n    Node *set(const int i, const\
    \ T &val, Node *&t){\n        Node *res = new Node();\n        if(t){\n      \
    \      std::memcpy(res->ch, t->ch, sizeof(t->ch));\n            res->data = t->data;\n\
    \        }\n        if(i == 0){\n            res->data = val;\n        } else{\n\
    \            res->ch[i % 20] = set(i / 20, val, res->ch[i % 20]);\n        }\n\
    \        return res;\n    }\n\n    T get(const int i, Node *t){\n        if(!t)\
    \ return T();\n        if(i == 0){\n            return t->data;\n        } else{\n\
    \            return get(i / 20, t->ch[i % 20]);\n        }\n    }\n};\n#line 10\
    \ \"lib/data_structure/persistent_queue.hpp\"\n\ntemplate<typename T>\nstruct\
    \ PersistentQueue{\n    PersistentArray<T> data;\n    using node = typename PersistentArray<T>::Node\
    \ *;\n    std::vector<node> nodes;\n    std::vector<int> front, back;\n    int\
    \ nxt = 1;\n\n    PersistentQueue(int N) : nodes(N), front(N), back(N){\n    \
    \    nodes[0] = data.get_root();\n    }\n\n    int size(const int t) const {\n\
    \        return back[t] - front[t];\n    }\n\n    bool empty(const int t) const\
    \ {\n        return size(t) == 0;\n    }\n\n    T top(const int t) {\n       \
    \ return data.get(front[t], nodes[t]);\n    }\n\n    int pop(const int t){\n \
    \       nodes[nxt] = nodes[t];\n        front[nxt] = front[t] + 1;\n        back[nxt]\
    \ = back[t];\n        return nxt++;\n    }\n\n    int push(const T &x, const int\
    \ t){\n        nodes[nxt] = data.set(back[t], x, nodes[t]);\n        front[nxt]\
    \ = front[t];\n        back[nxt] = back[t] + 1;\n        return nxt++;\n    }\n\
    };\n"
  code: "#pragma once\n\n/**\n * @brief Persistent Queue (\u6C38\u7D9A\u30AD\u30E5\
    \u30FC)\n */\n\n#include <vector>\n\n#include \"../data_structure/persistent_array.hpp\"\
    \n\ntemplate<typename T>\nstruct PersistentQueue{\n    PersistentArray<T> data;\n\
    \    using node = typename PersistentArray<T>::Node *;\n    std::vector<node>\
    \ nodes;\n    std::vector<int> front, back;\n    int nxt = 1;\n\n    PersistentQueue(int\
    \ N) : nodes(N), front(N), back(N){\n        nodes[0] = data.get_root();\n   \
    \ }\n\n    int size(const int t) const {\n        return back[t] - front[t];\n\
    \    }\n\n    bool empty(const int t) const {\n        return size(t) == 0;\n\
    \    }\n\n    T top(const int t) {\n        return data.get(front[t], nodes[t]);\n\
    \    }\n\n    int pop(const int t){\n        nodes[nxt] = nodes[t];\n        front[nxt]\
    \ = front[t] + 1;\n        back[nxt] = back[t];\n        return nxt++;\n    }\n\
    \n    int push(const T &x, const int t){\n        nodes[nxt] = data.set(back[t],\
    \ x, nodes[t]);\n        front[nxt] = front[t];\n        back[nxt] = back[t] +\
    \ 1;\n        return nxt++;\n    }\n};\n"
  dependsOn:
  - lib/data_structure/persistent_array.hpp
  isVerificationFile: false
  path: lib/data_structure/persistent_queue.hpp
  requiredBy: []
  timestamp: '2024-11-18 03:54:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/persistent_queue.test.cpp
documentation_of: lib/data_structure/persistent_queue.hpp
layout: document
redirect_from:
- /library/lib/data_structure/persistent_queue.hpp
- /library/lib/data_structure/persistent_queue.hpp.html
title: "Persistent Queue (\u6C38\u7D9A\u30AD\u30E5\u30FC)"
---
