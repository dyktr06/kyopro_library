---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/segment_tree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/library_checker/data_structure/static_rmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/data_structure/segment_tree.hpp\"\n\n/**\n\
    \ * @brief Segment Tree\n * @docs docs/data_structure/segment_tree.md\n */\n\n\
    template <typename T>\nstruct SegTree{\n    using FX = function<T(T, T)>; // T\u2022\
    T -> T \u3068\u306A\u308B\u95A2\u6570\u306E\u578B\n    int n;\n    const FX fx;\n\
    \    const T ex;\n    vector<T> dat;\n\n    SegTree(int n_, const FX &fx_, const\
    \ T &ex_) : n(), fx(fx_), ex(ex_){\n        int x = 1;\n        while(n_ > x){\n\
    \            x *= 2;\n        }\n        n = x;\n        dat.resize(n * 2);\n\
    \        for(int i = 0; i < n * 2; ++i){\n            dat[i] = ex;\n        }\n\
    \    }\n    SegTree(vector<T> &v, const FX &fx_, const T &ex_) : n(), fx(fx_),\
    \ ex(ex_){\n        int x = 1;\n        while((int) v.size() > x){\n         \
    \   x *= 2;\n        }\n        n = x;\n        dat.resize(n * 2);\n        for(int\
    \ i = 0; i < n; ++i){\n            set(i, (i < (int) v.size() ? v[i] : ex));\n\
    \        }\n        build();\n    }\n\n    void set(int i, const T &x){ dat[i\
    \ + n] = x; }\n\n    void build(){\n        for(int k = n - 1; k >= 1; k--) dat[k]\
    \ = fx(dat[k * 2], dat[k * 2 + 1]);\n    }\n\n    T get(int i) const {\n     \
    \   return dat[i + n];\n    }\n\n    void update(int i, const T &x){\n       \
    \ i += n;\n        dat[i] = x;\n        while(i > 0){\n            i >>= 1;  //\
    \ parent\n            dat[i] = fx(dat[i * 2], dat[i * 2 + 1]);\n        }\n  \
    \  }\n\n    T query(int a, int b){\n        T vl = ex;\n        T vr = ex;\n \
    \       int l = a + n;\n        int r = b + n;\n        while(l < r){\n      \
    \      if(l & 1) vl = fx(vl, dat[l++]);\n            if(r & 1) vr = fx(dat[--r],\
    \ vr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ fx(vl, vr);\n    }\n};\n#line 6 \"test/library_checker/data_structure/static_rmq.test.cpp\"\
    \n\nconst long long INF = 0x1fffffffffffffff;\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, q; cin >> n >> q;\n    auto fx = [](long\
    \ long x1, long long x2) -> long long { return min(x1, x2); };\n    long long\
    \ ex = INF;\n    SegTree<long long> rmq(n, fx, ex);\n    for(int i = 0; i < n;\
    \ i++){\n        int a; cin >> a;\n        rmq.update(i, a);\n    }\n    while(q--){\n\
    \        int l, r; cin >> l >> r;\n        cout << rmq.query(l, r) << \"\\n\"\
    ;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../../lib/data_structure/segment_tree.hpp\"\
    \n\nconst long long INF = 0x1fffffffffffffff;\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, q; cin >> n >> q;\n    auto fx = [](long\
    \ long x1, long long x2) -> long long { return min(x1, x2); };\n    long long\
    \ ex = INF;\n    SegTree<long long> rmq(n, fx, ex);\n    for(int i = 0; i < n;\
    \ i++){\n        int a; cin >> a;\n        rmq.update(i, a);\n    }\n    while(q--){\n\
    \        int l, r; cin >> l >> r;\n        cout << rmq.query(l, r) << \"\\n\"\
    ;\n    }\n}\n"
  dependsOn:
  - lib/data_structure/segment_tree.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2024-05-31 18:23:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/static_rmq.test.cpp
- /verify/test/library_checker/data_structure/static_rmq.test.cpp.html
title: test/library_checker/data_structure/static_rmq.test.cpp
---
