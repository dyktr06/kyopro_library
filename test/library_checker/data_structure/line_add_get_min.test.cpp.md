---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/dynamic_li_chao_tree.hpp
    title: Dynamic Li Chao Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/library_checker/data_structure/line_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/dynamic_li_chao_tree.hpp\"\
    \n\n/**\n * @brief Dynamic Li Chao Tree\n * @docs docs/data_structure/dynamic_li_chao_tree.md\n\
    \ */\n\ntemplate<typename T, T x_low, T x_high, T id>\nstruct DynamicLiChaoTree{\n\
    \    struct Line{\n        T a, b;\n\n        Line(T _a, T _b) : a(_a), b(_b)\
    \ {}\n\n        inline T get(T x) const {\n            return a * x + b;\n   \
    \     }\n    };\n\n    struct Node{\n        Line x;\n        Node *l, *r;\n\n\
    \        Node(const Line &x) : x{x}, l{nullptr}, r{nullptr} {}\n    };\n\n   \
    \ Node *root = nullptr;\n\n    DynamicLiChaoTree() {}\n\nprivate:\n    Node *add_line_(Node\
    \ *t, Line &x, const T &l, const T &r, const T &x_l, const T &x_r){\n        if(!t){\n\
    \            return new Node(x);\n        }\n\n        T t_l = t->x.get(l), t_r\
    \ = t->x.get(r);\n\n        if(t_l <= x_l && t_r <= x_r){\n            return\
    \ t;\n        }else if(t_l >= x_l && t_r >= x_r){\n            t->x = x;\n   \
    \         return t;\n        }else{\n            T m = (l + r) / 2;\n        \
    \    if(m == r) --m;\n            T t_m = t->x.get(m), x_m = x.get(m);\n     \
    \       if(t_m > x_m){\n                swap(t->x, x);\n                if(t_l\
    \ <= x_l){\n                    t->l = add_line_(t->l, x, l, m, t_l, t_m);\n \
    \               }else{\n                    t->r = add_line_(t->r, x, m + 1, r,\
    \ t_m + x.a, t_r);\n                } \n            }else{\n                if(x_l\
    \ <= t_l){\n                    t->l = add_line_(t->l, x, l, m, x_l, x_m);\n \
    \               }else{\n                    t->r = add_line_(t->r, x, m + 1, r,\
    \ x_m + x.a, x_r);\n                } \n            }\n            return t;\n\
    \        }\n    }\n\n    Node *add_segment_(Node *t, Line &x, const T &a, const\
    \ T &b, const T &l, const T &r, const T &x_l, const T &x_r){\n        if(r < a\
    \ || b < l) return t;\n        if(a <= l && r <= b){\n            Line y{x};\n\
    \            return add_line_(t, y, l, r, x_l, x_r);\n        }\n        if(t){\n\
    \            T t_l = t->x.get(l), t_r = t->x.get(r);\n            if(t_l <= x_l\
    \ && t_r <= x_r) return t;\n        }else{\n            t = new Node(Line(0, id));\n\
    \        }\n\n        T m = (l + r) / 2;\n        if(m == r) --m;\n        T x_m\
    \ = x.get(m);\n        t->l = add_segment_(t->l, x, a, b, l, m, x_l, x_m);\n \
    \       t->r = add_segment_(t->r, x, a, b, m + 1, r, x_m + x.a, x_r);\n      \
    \  return t;\n    }\n\n    T query_(const Node *t, const T &l, const T &r, const\
    \ T &x_c) const {\n        if(!t) return id;\n        if(l == r) return t->x.get(x_c);\n\
    \        T m = (l + r) / 2;\n        if(m == r) --m;\n        if(x_c <= m){\n\
    \            return min(t->x.get(x_c), query_(t->l, l, m, x_c));\n        }else{\n\
    \            return min(t->x.get(x_c), query_(t->r, m + 1, r, x_c));\n       \
    \ }\n    }\n\npublic:\n    void add_line(const T &a, const T &b){\n        Line\
    \ x(a, b);\n        root = add_line_(root, x, x_low, x_high, x.get(x_low), x.get(x_high));\n\
    \    }\n\n    void add_segment(const T &l, const T &r, const T &a, const T &b){\n\
    \        Line x(a, b);\n        root = add_segment_(root, x, l, r - 1, x_low,\
    \ x_high, x.get(x_low), x.get(x_high));\n    }\n\n    T query(const T &x) const\
    \ {\n        return query_(root, x_low, x_high, x);\n    }\n};\n#line 6 \"test/library_checker/data_structure/line_add_get_min.test.cpp\"\
    \n\nconst long long INF = 0x1fffffffffffffff;\n\nint main(){\n    int n, q; cin\
    \ >> n >> q;\n    const long long P = 1e9;\n    DynamicLiChaoTree<long long, -P,\
    \ P, INF> lct;\n    for(int i = 0; i < n; i++){\n        long long a, b; cin >>\
    \ a >> b;\n        lct.add_line(a, b);\n    }\n    while(q--){\n        int t;\
    \ cin >> t;\n        if(t == 0){\n            long long a, b; cin >> a >> b;\n\
    \            lct.add_line(a, b);\n        }else{\n            long long p; cin\
    \ >> p;\n            cout << lct.query(p) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/dynamic_li_chao_tree.hpp\"\
    \n\nconst long long INF = 0x1fffffffffffffff;\n\nint main(){\n    int n, q; cin\
    \ >> n >> q;\n    const long long P = 1e9;\n    DynamicLiChaoTree<long long, -P,\
    \ P, INF> lct;\n    for(int i = 0; i < n; i++){\n        long long a, b; cin >>\
    \ a >> b;\n        lct.add_line(a, b);\n    }\n    while(q--){\n        int t;\
    \ cin >> t;\n        if(t == 0){\n            long long a, b; cin >> a >> b;\n\
    \            lct.add_line(a, b);\n        }else{\n            long long p; cin\
    \ >> p;\n            cout << lct.query(p) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - lib/data_structure/dynamic_li_chao_tree.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2023-01-22 11:23:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/line_add_get_min.test.cpp
- /verify/test/library_checker/data_structure/line_add_get_min.test.cpp.html
title: test/library_checker/data_structure/line_add_get_min.test.cpp
---
