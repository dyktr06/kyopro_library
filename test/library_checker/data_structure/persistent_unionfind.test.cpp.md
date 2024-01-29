---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/persistent_array.hpp
    title: lib/data_structure/persistent_array.hpp
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/persistent_union_find.hpp
    title: lib/data_structure/persistent_union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/library_checker/data_structure/persistent_unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/persistent_union_find.hpp\"\
    \n\n#line 2 \"lib/data_structure/persistent_array.hpp\"\n\ntemplate<typename T>\n\
    struct PersistentArray{\n    struct Node{\n        T data;\n        Node *ch[20]\
    \ = {};\n    };\n    Node *root = nullptr;\n\n    PersistentArray() {}\n    \n\
    \    Node *get_root(){\n        return root;\n    }\n\n    void destructive_set(const\
    \ int i, const T &val, Node *&t){\n        if(!t) t = new Node();\n        if(i\
    \ == 0){\n            t->data = val;\n        }else{\n            destructive_set(i\
    \ / 20, val, t->ch[i % 20]);\n        }\n    }\n\n    Node *set(const int i, const\
    \ T &val, Node *&t){\n        Node *res = new Node();\n        if(t){\n      \
    \      memcpy(res->ch, t->ch, sizeof(t->ch));\n            res->data = t->data;\n\
    \        }\n        if(i == 0){\n            res->data = val;\n        }else{\n\
    \            res->ch[i % 20] = set(i / 20, val, res->ch[i % 20]);\n        }\n\
    \        return res;\n    }\n\n    T get(const int i, Node *t){\n        if(!t)\
    \ return T();\n        if(i == 0){\n            return t->data;\n        }else{\n\
    \            return get(i / 20, t->ch[i % 20]);\n        }\n    }\n};\n#line 4\
    \ \"lib/data_structure/persistent_union_find.hpp\"\n\nstruct PersistentUnionFind{\n\
    \    PersistentArray<int> data;\n    using node = PersistentArray<int>::Node*;\n\
    \n    PersistentUnionFind() {}\n\n    node init(const int n){\n        node res\
    \ = data.get_root();\n        for(int i = 0; i < n; ++i){\n            data.destructive_set(i,\
    \ -1, res);\n        }\n        return res;\n    }\n\n    pair<bool, node> unite(const\
    \ int x, const int y, node t){\n        int rx = root(x, t), ry = root(y, t);\n\
    \        if(rx == ry) return {false, t};\n\n        if(data.get(ry, t) < data.get(rx,\
    \ t)) swap(rx, ry);\n\n        node n = data.set(rx, data.get(rx, t) + data.get(ry,\
    \ t), t);\n        node res = data.set(ry, rx, n);\n        return {true, res};\n\
    \    }\n\n    int root(const int x, node t){\n        if(data.get(x, t) < 0){\n\
    \            return x;\n        }\n        int res = root(data.get(x, t), t);\n\
    \        return res;\n    }\n\n    inline bool same(const int x, const int y,\
    \ node t){\n        return root(x, t) == root(y, t);\n    }\n\n    inline int\
    \ size(const int x, node t){\n        return -data.get(root(x, t), t);\n    }\n\
    };\n\nstruct PersistentUnionFindv2{\n    int n;\n    PersistentArray<int> data;\n\
    \    using node = PersistentArray<int>::Node*;\n\n    PersistentUnionFindv2()\
    \ {}\n\n    node init(const int &_n){\n        n = _n;\n        node res = data.get_root();\n\
    \        for(int i = 0; i < n; ++i){\n            data.destructive_set(i, -1,\
    \ res);\n            data.destructive_set(i + n, 0, res);\n        }\n       \
    \ return res;\n    }\n\n    pair<bool, node> unite(const int x, const int y, node\
    \ t){\n        int rx = root(x, t), ry = root(y, t);\n        if(rx == ry){\n\
    \            node res = data.set(rx + n, edge(rx, t) + 1, t);\n            return\
    \ {false, res};\n        }\n\n        if(data.get(ry, t) < data.get(rx, t)) swap(rx,\
    \ ry);\n\n        node res = data.set(rx, data.get(rx, t) + data.get(ry, t), t);\n\
    \        res = data.set(ry, rx, res);\n        res = data.set(rx + n, data.get(rx\
    \ + n, t) + data.get(ry + n, t) + 1, res);\n        return {true, res};\n    }\n\
    \n    int root(const int x, node t){\n        if(data.get(x, t) < 0){\n      \
    \      return x;\n        }\n        int res = root(data.get(x, t), t);\n    \
    \    return res;\n    }\n\n    inline bool same(const int x, const int y, node\
    \ t){\n        return root(x, t) == root(y, t);\n    }\n\n    inline int size(const\
    \ int x, node t){\n        return -data.get(root(x, t), t);\n    }\n\n    inline\
    \ int edge(const int x, node t){\n        return data.get(root(x, t) + n, t);\n\
    \    }\n};\n#line 6 \"test/library_checker/data_structure/persistent_unionfind.test.cpp\"\
    \n\nusing pa = PersistentArray<int>::Node*;\n\nint main(){\n    int n, q; cin\
    \ >> n >> q;\n    PersistentUnionFind tree;\n    vector<pa> p(q + 1);\n    p[0]\
    \ = tree.init(n);\n    int nxt = 1;\n    while(q--){\n        int t, k, u, v;\
    \ cin >> t >> k >> u >> v;\n        k++;\n        if(t == 0){\n            p[nxt]\
    \ = tree.unite(u, v, p[k]).second;\n        }else{\n            cout << (int)\
    \ tree.same(u, v, p[k]) << \"\\n\";\n        }\n        nxt++;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/persistent_union_find.hpp\"\
    \n\nusing pa = PersistentArray<int>::Node*;\n\nint main(){\n    int n, q; cin\
    \ >> n >> q;\n    PersistentUnionFind tree;\n    vector<pa> p(q + 1);\n    p[0]\
    \ = tree.init(n);\n    int nxt = 1;\n    while(q--){\n        int t, k, u, v;\
    \ cin >> t >> k >> u >> v;\n        k++;\n        if(t == 0){\n            p[nxt]\
    \ = tree.unite(u, v, p[k]).second;\n        }else{\n            cout << (int)\
    \ tree.same(u, v, p[k]) << \"\\n\";\n        }\n        nxt++;\n    }\n}"
  dependsOn:
  - lib/data_structure/persistent_union_find.hpp
  - lib/data_structure/persistent_array.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-01-29 20:46:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/persistent_unionfind.test.cpp
- /verify/test/library_checker/data_structure/persistent_unionfind.test.cpp.html
title: test/library_checker/data_structure/persistent_unionfind.test.cpp
---
