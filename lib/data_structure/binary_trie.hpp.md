---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/set_xor_min.test.cpp
    title: test/library_checker/data_structure/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/binary_trie.hpp\"\n\ntemplate <typename\
    \ T, int MAX_LOG, int NODES = 1 << 24>\nstruct BinaryTrie{\n    struct Node{\n\
    \        Node *nxt[2];\n        int exist;\n        vector<int> accept;\n    \
    \    Node() {}\n    };\n    Node *pool;\n    int pid;\n    T lazy;\n    Node *nil;\n\
    \    Node *root;\n\n    BinaryTrie() : pid(0), lazy(0), nil(nullptr){\n      \
    \  pool = new Node[NODES];\n        nil = _new();\n        nil->nxt[0] = nil->nxt[1]\
    \ = root = nil;\n    }\n\n    Node *_new(const int exist_ = 0, const int id =\
    \ -1){\n        pool[pid].nxt[0] = pool[pid].nxt[1] = nil;\n        pool[pid].exist\
    \ = exist_;\n        if(id != -1) pool[pid].accept.push_back(id);\n        return\
    \ &(pool[pid++]);\n    }\n\n    Node *merge(Node *l, Node *r){\n        pool[pid].nxt[0]\
    \ = l;\n        pool[pid].nxt[1] = r;\n        pool[pid].exist = l->exist + r->exist;\n\
    \        return &(pool[pid++]);\n    }\n\nprivate:\n    Node *insert_(const T\
    \ &x, const int id, Node *n, const int bit_idx){\n        if(bit_idx == -1) {\n\
    \            if(n == nil){\n                return _new(1, id);\n            }\n\
    \            n->exist++;\n            n->accept.push_back(id);\n            return\
    \ n;\n        }\n        if(((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1)){\n\
    \            return merge(insert_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);\n\
    \        }else{\n            return merge(n->nxt[0], insert_(x, id, n->nxt[1],\
    \ bit_idx - 1));\n        }\n    }\n\n    Node *erase_(const T &x, const int id,\
    \ Node *n, const int bit_idx){\n        if(bit_idx == -1){\n            n->exist--;\n\
    \            return n;\n        }\n        if(((lazy >> bit_idx) & 1) == ((x >>\
    \ bit_idx) & 1)){\n            return merge(erase_(x, id, n->nxt[0], bit_idx -\
    \ 1), n->nxt[1]);\n        }else{\n            return merge(n->nxt[0], erase_(x,\
    \ id, n->nxt[1], bit_idx - 1));\n        }\n    }\n\n    pair<int, vector<int>&>\
    \ find_(const T &x, Node *n, const int bit_idx){\n        if(bit_idx == -1){\n\
    \            return pair<int, vector<int>&>(n->exist, n->accept);\n        }\n\
    \        if(((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1)){\n            return\
    \ find_(x, n->nxt[0], bit_idx - 1);\n        }else{\n            return find_(x,\
    \ n->nxt[1], bit_idx - 1);\n        }\n    }\n\n    pair<T, vector<int>&> max_element_(Node\
    \ *n, const int bit_idx) {\n        if(bit_idx == -1){\n            return pair<T,\
    \ vector<int>&>(0, n->accept);\n        }\n        if(n->nxt[~(lazy >> bit_idx)\
    \ & 1]->exist){\n            auto ret = max_element_(n->nxt[~(lazy >> bit_idx)\
    \ & 1], bit_idx - 1);\n            ret.first |= T(1) << bit_idx;\n           \
    \ return ret;\n        }\n        return max_element_(n->nxt[(lazy >> bit_idx)\
    \ & 1], bit_idx - 1);\n    }\n\n    pair<T, vector<int>&> min_element_(Node *n,\
    \ const int bit_idx){\n        if(bit_idx == -1){\n            return pair<T,\
    \ vector<int>&>(0, n->accept);\n        }\n\n        if(n->nxt[(lazy >> bit_idx)\
    \ & 1]->exist){\n            return min_element_(n->nxt[(lazy >> bit_idx) & 1],\
    \ bit_idx - 1);\n        }\n\n        auto ret = min_element_(n->nxt[~(lazy >>\
    \ bit_idx) & 1], bit_idx - 1);\n        ret.first |= T(1) << bit_idx;\n      \
    \  return ret;\n    }\n\n    // 1-indexed, minimum-kth\n    pair<T, vector<int>&>\
    \ kth_element_(Node *n, const int k, const int bit_idx){\n        if(bit_idx ==\
    \ -1){\n            return pair<T, vector<int>&>(0, n->accept);\n        }\n\n\
    \        int ex0 = n->nxt[(lazy >> bit_idx) & 1]->exist;\n        if(ex0 < k){\n\
    \            auto ret = kth_element_(n->nxt[~(lazy >> bit_idx) & 1], k - ex0,\
    \ bit_idx - 1);\n            ret.first |= T(1) << bit_idx;\n            return\
    \ ret;\n        }\n        return kth_element_(n->nxt[(lazy >> bit_idx) & 1],\
    \ k, bit_idx - 1);\n    }\n\n    int count_less_(Node *n, const T &x, const int\
    \ bit_idx) {\n        if(bit_idx == -1){\n            return 0;\n        }\n\n\
    \        int ret = 0;\n        bool f = (lazy >> bit_idx) & 1;\n        if((x\
    \ >> bit_idx & 1) && n->nxt[f]){\n            ret += n->nxt[f]->exist;\n     \
    \   }\n        if(n->nxt[f ^ (x >> bit_idx & 1)]){\n            ret += count_less_(n->nxt[f\
    \ ^ (x >> bit_idx & 1)], x, bit_idx - 1);\n        }\n        return ret;\n  \
    \  }\n\npublic:\n    void insert(const T &x, const int id = -1){\n        root\
    \ = insert_(x, id, root, MAX_LOG);\n    }\n\n    void erase(const T &x, const\
    \ int id = -1){ \n        root = erase_(x, id, root, MAX_LOG);\n    }\n\n    pair<int,\
    \ vector<int>&> find(const T &x){\n        return find_(x, root, MAX_LOG);\n \
    \   }\n\n    pair<T, vector<int>&> max_element(){\n        return max_element_(root,\
    \ MAX_LOG);\n    }\n\n    pair<T, vector<int>&> min_element(){\n        return\
    \ min_element_(root, MAX_LOG);\n    }\n\n    pair<T, vector<int>&> kth_element(const\
    \ int k){\n        return kth_element_(root, k, MAX_LOG);\n    }\n\n    int count_less(const\
    \ T &x){\n        return count_less_(root, x, MAX_LOG);\n    }\n\n    size_t size()\
    \ const {\n        if(root->exist <= 0){\n            return 0;\n        }\n \
    \       return root->exist;\n    }\n\n    bool empty() const {\n        return\
    \ size() == 0;\n    }\n\n    void operate_xor(const T &x){\n        lazy ^= x;\n\
    \    }\n};\n"
  code: "#pragma once\n\ntemplate <typename T, int MAX_LOG, int NODES = 1 << 24>\n\
    struct BinaryTrie{\n    struct Node{\n        Node *nxt[2];\n        int exist;\n\
    \        vector<int> accept;\n        Node() {}\n    };\n    Node *pool;\n   \
    \ int pid;\n    T lazy;\n    Node *nil;\n    Node *root;\n\n    BinaryTrie() :\
    \ pid(0), lazy(0), nil(nullptr){\n        pool = new Node[NODES];\n        nil\
    \ = _new();\n        nil->nxt[0] = nil->nxt[1] = root = nil;\n    }\n\n    Node\
    \ *_new(const int exist_ = 0, const int id = -1){\n        pool[pid].nxt[0] =\
    \ pool[pid].nxt[1] = nil;\n        pool[pid].exist = exist_;\n        if(id !=\
    \ -1) pool[pid].accept.push_back(id);\n        return &(pool[pid++]);\n    }\n\
    \n    Node *merge(Node *l, Node *r){\n        pool[pid].nxt[0] = l;\n        pool[pid].nxt[1]\
    \ = r;\n        pool[pid].exist = l->exist + r->exist;\n        return &(pool[pid++]);\n\
    \    }\n\nprivate:\n    Node *insert_(const T &x, const int id, Node *n, const\
    \ int bit_idx){\n        if(bit_idx == -1) {\n            if(n == nil){\n    \
    \            return _new(1, id);\n            }\n            n->exist++;\n   \
    \         n->accept.push_back(id);\n            return n;\n        }\n       \
    \ if(((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1)){\n            return merge(insert_(x,\
    \ id, n->nxt[0], bit_idx - 1), n->nxt[1]);\n        }else{\n            return\
    \ merge(n->nxt[0], insert_(x, id, n->nxt[1], bit_idx - 1));\n        }\n    }\n\
    \n    Node *erase_(const T &x, const int id, Node *n, const int bit_idx){\n  \
    \      if(bit_idx == -1){\n            n->exist--;\n            return n;\n  \
    \      }\n        if(((lazy >> bit_idx) & 1) == ((x >> bit_idx) & 1)){\n     \
    \       return merge(erase_(x, id, n->nxt[0], bit_idx - 1), n->nxt[1]);\n    \
    \    }else{\n            return merge(n->nxt[0], erase_(x, id, n->nxt[1], bit_idx\
    \ - 1));\n        }\n    }\n\n    pair<int, vector<int>&> find_(const T &x, Node\
    \ *n, const int bit_idx){\n        if(bit_idx == -1){\n            return pair<int,\
    \ vector<int>&>(n->exist, n->accept);\n        }\n        if(((lazy >> bit_idx)\
    \ & 1) == ((x >> bit_idx) & 1)){\n            return find_(x, n->nxt[0], bit_idx\
    \ - 1);\n        }else{\n            return find_(x, n->nxt[1], bit_idx - 1);\n\
    \        }\n    }\n\n    pair<T, vector<int>&> max_element_(Node *n, const int\
    \ bit_idx) {\n        if(bit_idx == -1){\n            return pair<T, vector<int>&>(0,\
    \ n->accept);\n        }\n        if(n->nxt[~(lazy >> bit_idx) & 1]->exist){\n\
    \            auto ret = max_element_(n->nxt[~(lazy >> bit_idx) & 1], bit_idx -\
    \ 1);\n            ret.first |= T(1) << bit_idx;\n            return ret;\n  \
    \      }\n        return max_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx -\
    \ 1);\n    }\n\n    pair<T, vector<int>&> min_element_(Node *n, const int bit_idx){\n\
    \        if(bit_idx == -1){\n            return pair<T, vector<int>&>(0, n->accept);\n\
    \        }\n\n        if(n->nxt[(lazy >> bit_idx) & 1]->exist){\n            return\
    \ min_element_(n->nxt[(lazy >> bit_idx) & 1], bit_idx - 1);\n        }\n\n   \
    \     auto ret = min_element_(n->nxt[~(lazy >> bit_idx) & 1], bit_idx - 1);\n\
    \        ret.first |= T(1) << bit_idx;\n        return ret;\n    }\n\n    // 1-indexed,\
    \ minimum-kth\n    pair<T, vector<int>&> kth_element_(Node *n, const int k, const\
    \ int bit_idx){\n        if(bit_idx == -1){\n            return pair<T, vector<int>&>(0,\
    \ n->accept);\n        }\n\n        int ex0 = n->nxt[(lazy >> bit_idx) & 1]->exist;\n\
    \        if(ex0 < k){\n            auto ret = kth_element_(n->nxt[~(lazy >> bit_idx)\
    \ & 1], k - ex0, bit_idx - 1);\n            ret.first |= T(1) << bit_idx;\n  \
    \          return ret;\n        }\n        return kth_element_(n->nxt[(lazy >>\
    \ bit_idx) & 1], k, bit_idx - 1);\n    }\n\n    int count_less_(Node *n, const\
    \ T &x, const int bit_idx) {\n        if(bit_idx == -1){\n            return 0;\n\
    \        }\n\n        int ret = 0;\n        bool f = (lazy >> bit_idx) & 1;\n\
    \        if((x >> bit_idx & 1) && n->nxt[f]){\n            ret += n->nxt[f]->exist;\n\
    \        }\n        if(n->nxt[f ^ (x >> bit_idx & 1)]){\n            ret += count_less_(n->nxt[f\
    \ ^ (x >> bit_idx & 1)], x, bit_idx - 1);\n        }\n        return ret;\n  \
    \  }\n\npublic:\n    void insert(const T &x, const int id = -1){\n        root\
    \ = insert_(x, id, root, MAX_LOG);\n    }\n\n    void erase(const T &x, const\
    \ int id = -1){ \n        root = erase_(x, id, root, MAX_LOG);\n    }\n\n    pair<int,\
    \ vector<int>&> find(const T &x){\n        return find_(x, root, MAX_LOG);\n \
    \   }\n\n    pair<T, vector<int>&> max_element(){\n        return max_element_(root,\
    \ MAX_LOG);\n    }\n\n    pair<T, vector<int>&> min_element(){\n        return\
    \ min_element_(root, MAX_LOG);\n    }\n\n    pair<T, vector<int>&> kth_element(const\
    \ int k){\n        return kth_element_(root, k, MAX_LOG);\n    }\n\n    int count_less(const\
    \ T &x){\n        return count_less_(root, x, MAX_LOG);\n    }\n\n    size_t size()\
    \ const {\n        if(root->exist <= 0){\n            return 0;\n        }\n \
    \       return root->exist;\n    }\n\n    bool empty() const {\n        return\
    \ size() == 0;\n    }\n\n    void operate_xor(const T &x){\n        lazy ^= x;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2024-01-29 20:46:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/set_xor_min.test.cpp
documentation_of: lib/data_structure/binary_trie.hpp
layout: document
redirect_from:
- /library/lib/data_structure/binary_trie.hpp
- /library/lib/data_structure/binary_trie.hpp.html
title: lib/data_structure/binary_trie.hpp
---
