---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/persistent_array.hpp
    title: lib/data_structure/persistent_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/persistent_unionfind.test.cpp
    title: test/library_checker/data_structure/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/persistent_union_find.hpp\"\n\n#line\
    \ 2 \"lib/data_structure/persistent_array.hpp\"\n\ntemplate<typename T>\nstruct\
    \ PersistentArray{\n    struct Node{\n        T data;\n        Node *ch[20] =\
    \ {};\n    };\n    Node *root = nullptr;\n\n    PersistentArray() {}\n    \n \
    \   Node *get_root(){\n        return root;\n    }\n\n    void destructive_set(const\
    \ int &i, const T &val, Node *&t){\n        if(!t) t = new Node();\n        if(i\
    \ == 0){\n            t->data = val;\n        }else{\n            destructive_set(i\
    \ / 20, val, t->ch[i % 20]);\n        }\n    }\n\n    Node *set(const int &i,\
    \ const T &val, Node *&t){\n        Node *res = new Node();\n        if(t){\n\
    \            memcpy(res->ch, t->ch, sizeof(t->ch));\n            res->data = t->data;\n\
    \        }\n        if(i == 0){\n            res->data = val;\n        }else{\n\
    \            res->ch[i % 20] = set(i / 20, val, res->ch[i % 20]);\n        }\n\
    \        return res;\n    }\n\n    T get(const int &i, Node *t){\n        if(!t)\
    \ return T();\n        if(i == 0){\n            return t->data;\n        }else{\n\
    \            return get(i / 20, t->ch[i % 20]);\n        }\n    }\n};\n#line 4\
    \ \"lib/data_structure/persistent_union_find.hpp\"\n\nstruct PersistentUnionFind{\n\
    \    PersistentArray<int> data;\n    using node = PersistentArray<int>::Node*;\n\
    \n    PersistentUnionFind() {}\n\n    node init(const int &n){\n        node res\
    \ = data.get_root();\n        for(int i = 0; i < n; ++i){\n            data.destructive_set(i,\
    \ -1, res);\n        }\n        return res;\n    }\n\n    pair<bool, node> unite(const\
    \ int &x, const int &y, node t){\n        int rx = root(x, t), ry = root(y, t);\n\
    \        if(rx == ry) return {false, t};\n\n        if(data.get(ry, t) < data.get(rx,\
    \ t)) swap(rx, ry);\n\n        node n = data.set(rx, data.get(rx, t) + data.get(ry,\
    \ t), t);\n        node res = data.set(ry, rx, n);\n        return {true, res};\n\
    \    }\n\n    int root(const int &x, node t){\n        if(data.get(x, t) < 0){\n\
    \            return x;\n        }\n        int res = root(data.get(x, t), t);\n\
    \        return res;\n    }\n\n    inline bool same(const int &x, const int &y,\
    \ node t){\n        return root(x, t) == root(y, t);\n    }\n\n    inline int\
    \ size(const int &x, node t){\n        return -data.get(root(x, t), t);\n    }\n\
    };\n\nstruct PersistentUnionFindv2{\n    int n;\n    PersistentArray<int> data;\n\
    \    using node = PersistentArray<int>::Node*;\n\n    PersistentUnionFindv2()\
    \ {}\n\n    node init(const int &_n){\n        n = _n;\n        node res = data.get_root();\n\
    \        for(int i = 0; i < n; ++i){\n            data.destructive_set(i, -1,\
    \ res);\n            data.destructive_set(i + n, 0, res);\n        }\n       \
    \ return res;\n    }\n\n    pair<bool, node> unite(const int &x, const int &y,\
    \ node t){\n        int rx = root(x, t), ry = root(y, t);\n        if(rx == ry){\n\
    \            node res = data.set(rx + n, edge(rx, t) + 1, t);\n            return\
    \ {false, res};\n        }\n\n        if(data.get(ry, t) < data.get(rx, t)) swap(rx,\
    \ ry);\n\n        node res = data.set(rx, data.get(rx, t) + data.get(ry, t), t);\n\
    \        res = data.set(ry, rx, res);\n        res = data.set(rx + n, data.get(rx\
    \ + n, t) + data.get(ry + n, t) + 1, res);\n        return {true, res};\n    }\n\
    \n    int root(const int &x, node t){\n        if(data.get(x, t) < 0){\n     \
    \       return x;\n        }\n        int res = root(data.get(x, t), t);\n   \
    \     return res;\n    }\n\n    inline bool same(const int &x, const int &y, node\
    \ t){\n        return root(x, t) == root(y, t);\n    }\n\n    inline int size(const\
    \ int &x, node t){\n        return -data.get(root(x, t), t);\n    }\n\n    inline\
    \ int edge(const int &x, node t){\n        return data.get(root(x, t) + n, t);\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include \"../data_structure/persistent_array.hpp\"\n\nstruct\
    \ PersistentUnionFind{\n    PersistentArray<int> data;\n    using node = PersistentArray<int>::Node*;\n\
    \n    PersistentUnionFind() {}\n\n    node init(const int &n){\n        node res\
    \ = data.get_root();\n        for(int i = 0; i < n; ++i){\n            data.destructive_set(i,\
    \ -1, res);\n        }\n        return res;\n    }\n\n    pair<bool, node> unite(const\
    \ int &x, const int &y, node t){\n        int rx = root(x, t), ry = root(y, t);\n\
    \        if(rx == ry) return {false, t};\n\n        if(data.get(ry, t) < data.get(rx,\
    \ t)) swap(rx, ry);\n\n        node n = data.set(rx, data.get(rx, t) + data.get(ry,\
    \ t), t);\n        node res = data.set(ry, rx, n);\n        return {true, res};\n\
    \    }\n\n    int root(const int &x, node t){\n        if(data.get(x, t) < 0){\n\
    \            return x;\n        }\n        int res = root(data.get(x, t), t);\n\
    \        return res;\n    }\n\n    inline bool same(const int &x, const int &y,\
    \ node t){\n        return root(x, t) == root(y, t);\n    }\n\n    inline int\
    \ size(const int &x, node t){\n        return -data.get(root(x, t), t);\n    }\n\
    };\n\nstruct PersistentUnionFindv2{\n    int n;\n    PersistentArray<int> data;\n\
    \    using node = PersistentArray<int>::Node*;\n\n    PersistentUnionFindv2()\
    \ {}\n\n    node init(const int &_n){\n        n = _n;\n        node res = data.get_root();\n\
    \        for(int i = 0; i < n; ++i){\n            data.destructive_set(i, -1,\
    \ res);\n            data.destructive_set(i + n, 0, res);\n        }\n       \
    \ return res;\n    }\n\n    pair<bool, node> unite(const int &x, const int &y,\
    \ node t){\n        int rx = root(x, t), ry = root(y, t);\n        if(rx == ry){\n\
    \            node res = data.set(rx + n, edge(rx, t) + 1, t);\n            return\
    \ {false, res};\n        }\n\n        if(data.get(ry, t) < data.get(rx, t)) swap(rx,\
    \ ry);\n\n        node res = data.set(rx, data.get(rx, t) + data.get(ry, t), t);\n\
    \        res = data.set(ry, rx, res);\n        res = data.set(rx + n, data.get(rx\
    \ + n, t) + data.get(ry + n, t) + 1, res);\n        return {true, res};\n    }\n\
    \n    int root(const int &x, node t){\n        if(data.get(x, t) < 0){\n     \
    \       return x;\n        }\n        int res = root(data.get(x, t), t);\n   \
    \     return res;\n    }\n\n    inline bool same(const int &x, const int &y, node\
    \ t){\n        return root(x, t) == root(y, t);\n    }\n\n    inline int size(const\
    \ int &x, node t){\n        return -data.get(root(x, t), t);\n    }\n\n    inline\
    \ int edge(const int &x, node t){\n        return data.get(root(x, t) + n, t);\n\
    \    }\n};"
  dependsOn:
  - lib/data_structure/persistent_array.hpp
  isVerificationFile: false
  path: lib/data_structure/persistent_union_find.hpp
  requiredBy: []
  timestamp: '2023-05-21 04:04:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/persistent_unionfind.test.cpp
documentation_of: lib/data_structure/persistent_union_find.hpp
layout: document
redirect_from:
- /library/lib/data_structure/persistent_union_find.hpp
- /library/lib/data_structure/persistent_union_find.hpp.html
title: lib/data_structure/persistent_union_find.hpp
---
