---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/point_set_range_composite_large_array_1.test.cpp
    title: test/library_checker/data_structure/point_set_range_composite_large_array_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Dynamic Segment Tree
    links:
    - https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644
  bundledCode: "#line 2 \"lib/data_structure/dynamic_segment_tree.hpp\"\n\n/**\n *\
    \ @brief Dynamic Segment Tree\n * @see https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644\n\
    \ */\n\n#include <cassert>\n#include <memory>\n\ntemplate <typename T, T (*op)(T,\
    \ T), T(*e)()>\nstruct DynamicSegTree{\n    DynamicSegTree(int n) : n(n), root(nullptr)\
    \ {}\nprivate:\n    struct node;\n    using node_ptr = std::unique_ptr<node>;\n\
    \n    struct node{\n        int index;\n        T value, product;\n        node_ptr\
    \ left, right;\n\n        node(int index, T value)\n            : index(index),\n\
    \                value(value),\n                product(value),\n            \
    \    left(nullptr),\n                right(nullptr) {}\n\n        void refresh()\
    \ {\n            product = op(op(left ? left->product : e(), value), right ? right->product\
    \ : e());\n        }\n    };\n\n    const int n;\n    node_ptr root;\n\n    void\
    \ update(node_ptr& t, int a, int b, int i, T x) const {\n        if(!t){\n   \
    \         t = std::make_unique<node>(i, x);\n            return;\n        }\n\
    \        if(t->index == i){\n            t->value = x;\n            t->refresh();\n\
    \            return;\n        }\n        int c = (a + b) >> 1;\n        if(i <\
    \ c){\n            if(t->index < i) std::swap(t->index, i), std::swap(t->value,\
    \ x);\n            update(t->left, a, c, i, x);\n        } else {\n          \
    \  if(i < t->index) std::swap(i, t->index), std::swap(x, t->value);\n        \
    \    update(t->right, c, b, i, x);\n        }\n        t->refresh();\n    }\n\n\
    \    T get(const node_ptr& t, int a, int b, int i) const {\n        if(!t) return\
    \ e();\n        if(t->index == i) return t->value;\n        int c = (a + b) >>\
    \ 1;\n        if(i < c) return get(t->left, a, c, i);\n        else return get(t->right,\
    \ c, b, i);\n    }\n\n    T query(const node_ptr& t, int a, int b, int l, int\
    \ r) const {\n        if(!t || b <= l || r <= a) return e();\n        if(l <=\
    \ a && b <= r) return t->product;\n        int c = (a + b) >> 1;\n        T result\
    \ = query(t->left, a, c, l, r);\n        if(l <= t->index && t->index < r) result\
    \ = op(result, t->value);\n        return op(result, query(t->right, c, b, l,\
    \ r));\n    }\n\n    void reset(node_ptr& t, int a, int b, int l, int r) const\
    \ {\n        if(!t || b <= l || r <= a) return;\n        if(l <= a && b <= r){\n\
    \            t.reset();\n            return;\n        }\n        int c = (a +\
    \ b) >> 1;\n        reset(t->left, a, c, l, r);\n        reset(t->right, c, b,\
    \ l, r);\n        t->refresh();\n    }\n\n    template <class F>\n    int max_right(const\
    \ node_ptr& t, int a, int b, int l, const F& f, T& product) const {\n        if(!t\
    \ || b <= l) return n;\n        if(f(op(product, t->product))){\n            product\
    \ = op(product, t->product);\n            return n;\n        }\n        int c\
    \ = (a + b) >> 1;\n        int result = max_right(t->left, a, c, l, f, product);\n\
    \        if(result != n) return result;\n        if(l <= t->index) {\n       \
    \     product = op(product, t->value);\n            if(!f(product)) return t->index;\n\
    \        }\n        return max_right(t->right, c, b, l, f, product);\n    }\n\n\
    \    template <class F>\n    int min_left(const node_ptr& t, int a, int b, int\
    \ r, const F& f, T& product) const {\n        if(!t || r <= a) return 0;\n   \
    \     if(f(op(t->product, product))){\n            product = op(t->product, product);\n\
    \            return 0;\n        }\n        int c = (a + b) >> 1;\n        int\
    \ result = min_left(t->right, c, b, r, f, product);\n        if(result != 0) return\
    \ result;\n        if(t->index < r){\n            product = op(t->value, product);\n\
    \            if(!f(product)) return t->index + 1;\n        }\n        return min_left(t->left,\
    \ a, c, r, f, product);\n    }\n\npublic:\n    void update(int i, T x) {\n   \
    \     assert(i < n);\n        update(root, 0, n, i, x);\n    }\n\n    T get(int\
    \ i) const {\n        assert(i < n);\n        return get(root, 0, n, i);\n   \
    \ }\n\n    T query(int l, int r) const {\n        assert(l <= r && r <= n);\n\
    \        return query(root, 0, n, l, r);\n    }\n\n    T all_query() const {\n\
    \        return root ? root->product : e();\n    }\n\n    void reset(int l, int\
    \ r) {\n        assert(l <= r && r <= n);\n        return reset(root, 0, n, l,\
    \ r);\n    }\n\n    template <bool (*f)(T)>\n    int max_right(int l) const {\n\
    \        return max_right(l, [](T x) { return f(x); });\n    }\n\n    template\
    \ <class F>\n    int max_right(int l, const F& f) const {\n        assert(l <=\
    \ n);\n        T product = e();\n        assert(f(product));\n        return max_right(root,\
    \ 0, n, l, f, product);\n    }\n\n    template <bool (*f)(T)>\n    int min_left(int\
    \ r) const {\n        return min_left(r, [](T x) { return f(x); });\n    }\n\n\
    \    template <class F>\n    int min_left(int r, const F& f) const {\n       \
    \ assert(r <= n);\n        T product = e();\n        assert(f(product));\n   \
    \     return min_left(root, 0, n, r, f, product);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Dynamic Segment Tree\n * @see https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644\n\
    \ */\n\n#include <cassert>\n#include <memory>\n\ntemplate <typename T, T (*op)(T,\
    \ T), T(*e)()>\nstruct DynamicSegTree{\n    DynamicSegTree(int n) : n(n), root(nullptr)\
    \ {}\nprivate:\n    struct node;\n    using node_ptr = std::unique_ptr<node>;\n\
    \n    struct node{\n        int index;\n        T value, product;\n        node_ptr\
    \ left, right;\n\n        node(int index, T value)\n            : index(index),\n\
    \                value(value),\n                product(value),\n            \
    \    left(nullptr),\n                right(nullptr) {}\n\n        void refresh()\
    \ {\n            product = op(op(left ? left->product : e(), value), right ? right->product\
    \ : e());\n        }\n    };\n\n    const int n;\n    node_ptr root;\n\n    void\
    \ update(node_ptr& t, int a, int b, int i, T x) const {\n        if(!t){\n   \
    \         t = std::make_unique<node>(i, x);\n            return;\n        }\n\
    \        if(t->index == i){\n            t->value = x;\n            t->refresh();\n\
    \            return;\n        }\n        int c = (a + b) >> 1;\n        if(i <\
    \ c){\n            if(t->index < i) std::swap(t->index, i), std::swap(t->value,\
    \ x);\n            update(t->left, a, c, i, x);\n        } else {\n          \
    \  if(i < t->index) std::swap(i, t->index), std::swap(x, t->value);\n        \
    \    update(t->right, c, b, i, x);\n        }\n        t->refresh();\n    }\n\n\
    \    T get(const node_ptr& t, int a, int b, int i) const {\n        if(!t) return\
    \ e();\n        if(t->index == i) return t->value;\n        int c = (a + b) >>\
    \ 1;\n        if(i < c) return get(t->left, a, c, i);\n        else return get(t->right,\
    \ c, b, i);\n    }\n\n    T query(const node_ptr& t, int a, int b, int l, int\
    \ r) const {\n        if(!t || b <= l || r <= a) return e();\n        if(l <=\
    \ a && b <= r) return t->product;\n        int c = (a + b) >> 1;\n        T result\
    \ = query(t->left, a, c, l, r);\n        if(l <= t->index && t->index < r) result\
    \ = op(result, t->value);\n        return op(result, query(t->right, c, b, l,\
    \ r));\n    }\n\n    void reset(node_ptr& t, int a, int b, int l, int r) const\
    \ {\n        if(!t || b <= l || r <= a) return;\n        if(l <= a && b <= r){\n\
    \            t.reset();\n            return;\n        }\n        int c = (a +\
    \ b) >> 1;\n        reset(t->left, a, c, l, r);\n        reset(t->right, c, b,\
    \ l, r);\n        t->refresh();\n    }\n\n    template <class F>\n    int max_right(const\
    \ node_ptr& t, int a, int b, int l, const F& f, T& product) const {\n        if(!t\
    \ || b <= l) return n;\n        if(f(op(product, t->product))){\n            product\
    \ = op(product, t->product);\n            return n;\n        }\n        int c\
    \ = (a + b) >> 1;\n        int result = max_right(t->left, a, c, l, f, product);\n\
    \        if(result != n) return result;\n        if(l <= t->index) {\n       \
    \     product = op(product, t->value);\n            if(!f(product)) return t->index;\n\
    \        }\n        return max_right(t->right, c, b, l, f, product);\n    }\n\n\
    \    template <class F>\n    int min_left(const node_ptr& t, int a, int b, int\
    \ r, const F& f, T& product) const {\n        if(!t || r <= a) return 0;\n   \
    \     if(f(op(t->product, product))){\n            product = op(t->product, product);\n\
    \            return 0;\n        }\n        int c = (a + b) >> 1;\n        int\
    \ result = min_left(t->right, c, b, r, f, product);\n        if(result != 0) return\
    \ result;\n        if(t->index < r){\n            product = op(t->value, product);\n\
    \            if(!f(product)) return t->index + 1;\n        }\n        return min_left(t->left,\
    \ a, c, r, f, product);\n    }\n\npublic:\n    void update(int i, T x) {\n   \
    \     assert(i < n);\n        update(root, 0, n, i, x);\n    }\n\n    T get(int\
    \ i) const {\n        assert(i < n);\n        return get(root, 0, n, i);\n   \
    \ }\n\n    T query(int l, int r) const {\n        assert(l <= r && r <= n);\n\
    \        return query(root, 0, n, l, r);\n    }\n\n    T all_query() const {\n\
    \        return root ? root->product : e();\n    }\n\n    void reset(int l, int\
    \ r) {\n        assert(l <= r && r <= n);\n        return reset(root, 0, n, l,\
    \ r);\n    }\n\n    template <bool (*f)(T)>\n    int max_right(int l) const {\n\
    \        return max_right(l, [](T x) { return f(x); });\n    }\n\n    template\
    \ <class F>\n    int max_right(int l, const F& f) const {\n        assert(l <=\
    \ n);\n        T product = e();\n        assert(f(product));\n        return max_right(root,\
    \ 0, n, l, f, product);\n    }\n\n    template <bool (*f)(T)>\n    int min_left(int\
    \ r) const {\n        return min_left(r, [](T x) { return f(x); });\n    }\n\n\
    \    template <class F>\n    int min_left(int r, const F& f) const {\n       \
    \ assert(r <= n);\n        T product = e();\n        assert(f(product));\n   \
    \     return min_left(root, 0, n, r, f, product);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/dynamic_segment_tree.hpp
  requiredBy: []
  timestamp: '2025-04-28 02:32:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/data_structure/point_set_range_composite_large_array_1.test.cpp
documentation_of: lib/data_structure/dynamic_segment_tree.hpp
layout: document
redirect_from:
- /library/lib/data_structure/dynamic_segment_tree.hpp
- /library/lib/data_structure/dynamic_segment_tree.hpp.html
title: Dynamic Segment Tree
---
