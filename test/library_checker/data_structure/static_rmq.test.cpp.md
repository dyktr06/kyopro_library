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
    template <typename X>\nstruct SegTree{\n    using FX = function<X(X, X)>; // X\u2022\
    X -> X \u3068\u306A\u308B\u95A2\u6570\u306E\u578B\n    int n;\n    FX fx;\n  \
    \  const X ex;\n    vector<X> dat;\n\n    SegTree(int n_, FX fx_, X ex_) : n(),\
    \ fx(fx_), ex(ex_), dat(n_ * 4, ex_){\n        int x = 1;\n        while(n_ >\
    \ x){\n            x *= 2;\n        }\n        n = x;\n    }\n\n    X get(int\
    \ i){\n        return dat[i + n - 1];\n    }\n    \n    void set(int i, X x){\
    \ dat[i + n - 1] = x; }\n\n    void build(){\n        for(int k = n - 2; k >=\
    \ 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);\n    }\n\n    void update(int\
    \ i, X x){\n        i += n - 1;\n        dat[i] = x;\n        while(i > 0){\n\
    \            i = (i - 1) / 2;  // parent\n            dat[i] = fx(dat[i * 2 +\
    \ 1], dat[i * 2 + 2]);\n        }\n    }\n\n    X query(int a, int b){ return\
    \ query_sub(a, b, 0, 0, n); }\n\n    X query_sub(int a, int b, int k, int l, int\
    \ r){\n        if(r <= a || b <= l){\n            return ex;\n        }else if(a\
    \ <= l && r <= b){\n            return dat[k];\n        }else{\n            X\
    \ vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);\n            X vr = query_sub(a,\
    \ b, k * 2 + 2, (l + r) / 2, r);\n            return fx(vl, vr);\n        }\n\
    \    }\n};\n#line 6 \"test/library_checker/data_structure/static_rmq.test.cpp\"\
    \n\nconst long long INF = 0x1fffffffffffffff;\n\nint main(){\n    int n, q; cin\
    \ >> n >> q;\n    auto fx = [](long long x1, long long x2) -> long long { return\
    \ min(x1, x2); };\n    long long ex = INF;\n    SegTree<long long> rmq(n, fx,\
    \ ex);\n    for(int i = 0; i < n; i++){\n        int a; cin >> a;\n        rmq.update(i,\
    \ a);\n    }\n    while(q--){\n        int l, r; cin >> l >> r;\n        cout\
    \ << rmq.query(l, r) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../../lib/data_structure/segment_tree.hpp\"\
    \n\nconst long long INF = 0x1fffffffffffffff;\n\nint main(){\n    int n, q; cin\
    \ >> n >> q;\n    auto fx = [](long long x1, long long x2) -> long long { return\
    \ min(x1, x2); };\n    long long ex = INF;\n    SegTree<long long> rmq(n, fx,\
    \ ex);\n    for(int i = 0; i < n; i++){\n        int a; cin >> a;\n        rmq.update(i,\
    \ a);\n    }\n    while(q--){\n        int l, r; cin >> l >> r;\n        cout\
    \ << rmq.query(l, r) << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/data_structure/segment_tree.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2023-01-06 16:06:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/static_rmq.test.cpp
- /verify/test/library_checker/data_structure/static_rmq.test.cpp.html
title: test/library_checker/data_structure/static_rmq.test.cpp
---
