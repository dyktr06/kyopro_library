---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/data_structure/line_add_get_min.test.cpp
    title: test/library_checker/data_structure/line_add_get_min.test.cpp
  - icon: ':x:'
    path: test/library_checker/data_structure/segment_add_get_min.test.cpp
    title: test/library_checker/data_structure/segment_add_get_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/data_structure/dynamic_li_chao_tree.md
    document_title: Dynamic Li Chao Tree
    links: []
  bundledCode: "#line 2 \"lib/data_structure/dynamic_li_chao_tree.hpp\"\n\n/**\n *\
    \ @brief Dynamic Li Chao Tree\n * @docs docs/data_structure/dynamic_li_chao_tree.md\n\
    \ */\n\ntemplate<typename T, T x_low, T x_high, T id>\nstruct DynamicLiChaoTree{\n\
    \    struct Line{\n        T a, b;\n\n        Line(T _a, T _b) : a(_a), b(_b)\
    \ {}\n\n        inline T get(T x) const {\n            return a * x + b;\n   \
    \     }\n    };\n\n    struct Node{\n        Line x;\n        Node *l, *r;\n\n\
    \        Node(const Line &x) : x{x}, l{nullptr}, r{nullptr} {}\n    };\n\n   \
    \ Node *root = nullptr;\n\n    DynamicLiChaoTree() {}\n\nprivate:\n    Node *add_line_(Node\
    \ *t, Line &x, const T &l, const T &r, const T &x_l, const T &x_r){\n        if(!t){\n\
    \            return new Node(x);\n        }\n\n        T t_l = t->x.get(l), t_r\
    \ = t->x.get(r);\n\n        if(t_l <= x_l && t_r <= x_r){\n            return\
    \ t;\n        } else if(t_l >= x_l && t_r >= x_r){\n            t->x = x;\n  \
    \          return t;\n        } else{\n            T m = (l + r) / 2;\n      \
    \      if(m == r) --m;\n            T t_m = t->x.get(m), x_m = x.get(m);\n   \
    \         if(t_m > x_m){\n                swap(t->x, x);\n                if(t_l\
    \ <= x_l){\n                    t->l = add_line_(t->l, x, l, m, t_l, t_m);\n \
    \               } else{\n                    t->r = add_line_(t->r, x, m + 1,\
    \ r, t_m + x.a, t_r);\n                }\n            } else{\n              \
    \  if(x_l <= t_l){\n                    t->l = add_line_(t->l, x, l, m, x_l, x_m);\n\
    \                } else{\n                    t->r = add_line_(t->r, x, m + 1,\
    \ r, x_m + x.a, x_r);\n                }\n            }\n            return t;\n\
    \        }\n    }\n\n    Node *add_segment_(Node *t, Line &x, const T &a, const\
    \ T &b, const T &l, const T &r, const T &x_l, const T &x_r){\n        if(r < a\
    \ || b < l) return t;\n        if(a <= l && r <= b){\n            Line y{x};\n\
    \            return add_line_(t, y, l, r, x_l, x_r);\n        }\n        if(t){\n\
    \            T t_l = t->x.get(l), t_r = t->x.get(r);\n            if(t_l <= x_l\
    \ && t_r <= x_r) return t;\n        } else{\n            t = new Node(Line(0,\
    \ id));\n        }\n\n        T m = (l + r) / 2;\n        if(m == r) --m;\n  \
    \      T x_m = x.get(m);\n        t->l = add_segment_(t->l, x, a, b, l, m, x_l,\
    \ x_m);\n        t->r = add_segment_(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);\n\
    \        return t;\n    }\n\n    T query_(const Node *t, const T &l, const T &r,\
    \ const T &x_c) const {\n        if(!t) return id;\n        if(l == r) return\
    \ t->x.get(x_c);\n        T m = (l + r) / 2;\n        if(m == r) --m;\n      \
    \  if(x_c <= m){\n            return min(t->x.get(x_c), query_(t->l, l, m, x_c));\n\
    \        } else{\n            return min(t->x.get(x_c), query_(t->r, m + 1, r,\
    \ x_c));\n        }\n    }\n\npublic:\n    void add_line(const T &a, const T &b){\n\
    \        Line x(a, b);\n        root = add_line_(root, x, x_low, x_high, x.get(x_low),\
    \ x.get(x_high));\n    }\n\n    void add_segment(const T &l, const T &r, const\
    \ T &a, const T &b){\n        Line x(a, b);\n        root = add_segment_(root,\
    \ x, l, r - 1, x_low, x_high, x.get(x_low), x.get(x_high));\n    }\n\n    T query(const\
    \ T &x) const {\n        return query_(root, x_low, x_high, x);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Dynamic Li Chao Tree\n * @docs docs/data_structure/dynamic_li_chao_tree.md\n\
    \ */\n\ntemplate<typename T, T x_low, T x_high, T id>\nstruct DynamicLiChaoTree{\n\
    \    struct Line{\n        T a, b;\n\n        Line(T _a, T _b) : a(_a), b(_b)\
    \ {}\n\n        inline T get(T x) const {\n            return a * x + b;\n   \
    \     }\n    };\n\n    struct Node{\n        Line x;\n        Node *l, *r;\n\n\
    \        Node(const Line &x) : x{x}, l{nullptr}, r{nullptr} {}\n    };\n\n   \
    \ Node *root = nullptr;\n\n    DynamicLiChaoTree() {}\n\nprivate:\n    Node *add_line_(Node\
    \ *t, Line &x, const T &l, const T &r, const T &x_l, const T &x_r){\n        if(!t){\n\
    \            return new Node(x);\n        }\n\n        T t_l = t->x.get(l), t_r\
    \ = t->x.get(r);\n\n        if(t_l <= x_l && t_r <= x_r){\n            return\
    \ t;\n        } else if(t_l >= x_l && t_r >= x_r){\n            t->x = x;\n  \
    \          return t;\n        } else{\n            T m = (l + r) / 2;\n      \
    \      if(m == r) --m;\n            T t_m = t->x.get(m), x_m = x.get(m);\n   \
    \         if(t_m > x_m){\n                swap(t->x, x);\n                if(t_l\
    \ <= x_l){\n                    t->l = add_line_(t->l, x, l, m, t_l, t_m);\n \
    \               } else{\n                    t->r = add_line_(t->r, x, m + 1,\
    \ r, t_m + x.a, t_r);\n                }\n            } else{\n              \
    \  if(x_l <= t_l){\n                    t->l = add_line_(t->l, x, l, m, x_l, x_m);\n\
    \                } else{\n                    t->r = add_line_(t->r, x, m + 1,\
    \ r, x_m + x.a, x_r);\n                }\n            }\n            return t;\n\
    \        }\n    }\n\n    Node *add_segment_(Node *t, Line &x, const T &a, const\
    \ T &b, const T &l, const T &r, const T &x_l, const T &x_r){\n        if(r < a\
    \ || b < l) return t;\n        if(a <= l && r <= b){\n            Line y{x};\n\
    \            return add_line_(t, y, l, r, x_l, x_r);\n        }\n        if(t){\n\
    \            T t_l = t->x.get(l), t_r = t->x.get(r);\n            if(t_l <= x_l\
    \ && t_r <= x_r) return t;\n        } else{\n            t = new Node(Line(0,\
    \ id));\n        }\n\n        T m = (l + r) / 2;\n        if(m == r) --m;\n  \
    \      T x_m = x.get(m);\n        t->l = add_segment_(t->l, x, a, b, l, m, x_l,\
    \ x_m);\n        t->r = add_segment_(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);\n\
    \        return t;\n    }\n\n    T query_(const Node *t, const T &l, const T &r,\
    \ const T &x_c) const {\n        if(!t) return id;\n        if(l == r) return\
    \ t->x.get(x_c);\n        T m = (l + r) / 2;\n        if(m == r) --m;\n      \
    \  if(x_c <= m){\n            return min(t->x.get(x_c), query_(t->l, l, m, x_c));\n\
    \        } else{\n            return min(t->x.get(x_c), query_(t->r, m + 1, r,\
    \ x_c));\n        }\n    }\n\npublic:\n    void add_line(const T &a, const T &b){\n\
    \        Line x(a, b);\n        root = add_line_(root, x, x_low, x_high, x.get(x_low),\
    \ x.get(x_high));\n    }\n\n    void add_segment(const T &l, const T &r, const\
    \ T &a, const T &b){\n        Line x(a, b);\n        root = add_segment_(root,\
    \ x, l, r - 1, x_low, x_high, x.get(x_low), x.get(x_high));\n    }\n\n    T query(const\
    \ T &x) const {\n        return query_(root, x_low, x_high, x);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/dynamic_li_chao_tree.hpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/data_structure/segment_add_get_min.test.cpp
  - test/library_checker/data_structure/line_add_get_min.test.cpp
documentation_of: lib/data_structure/dynamic_li_chao_tree.hpp
layout: document
redirect_from:
- /library/lib/data_structure/dynamic_li_chao_tree.hpp
- /library/lib/data_structure/dynamic_li_chao_tree.hpp.html
title: Dynamic Li Chao Tree
---
## Dynamic Li Chao Tree

#### 使い方

- `DynamicLiChaoTree<T, x_low, x_high, id>()`: Dynamic Li Chao Tree を構築します。x_low に $x$ の最小値、x_high に $x$ の最大値、id に十分大きい値 (単位元) を設定します。
- `add_line(a, b)`: ax + b の直線を追加します。
- `add_segment(l, r, a, b)`: `[l, r)` に ax + b の直線を追加します。
- `query(x)`: x で最小値をとるような値を求めます。

#### 計算量

$R$ を $x$ の範囲とすると

- `add(a, b)`: $\mathrm{O}(\log R)$
- `add_segment(l, r, a, b)`: $\mathrm{O}(\log^2 R)$
- `query(x)`: $\mathrm{O}(\log R)$