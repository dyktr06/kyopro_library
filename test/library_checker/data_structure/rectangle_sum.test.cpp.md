---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/data_structure/range_tree.hpp
    title: lib/data_structure/range_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/library_checker/data_structure/rectangle_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/range_tree.hpp\"\
    \n\ntemplate <typename S, typename T>\nstruct RangeTree{\n    struct BinaryIndexedTree{\n\
    \        int N;\n        vector<T> BIT;\n        BinaryIndexedTree() {}\n\n  \
    \      void init(int size){\n            N = size;\n            BIT.assign(N +\
    \ 1, 0);\n        }\n\n        T get(int i){\n            return sum(i + 1) -\
    \ sum(i);\n        }\n\n        void add(int i, T x){\n            ++i;\n    \
    \        while(i <= N){\n                BIT[i] += x;\n                i += i\
    \ & -i;\n            }\n        }\n\n        T sum(int i) const {\n          \
    \  T ans = 0;\n            while(i > 0){\n                ans += BIT[i];\n   \
    \             i -= i & -i;\n            }\n            return ans;\n        }\n\
    \n        T sum(int L, int R) const {\n            return sum(R) - sum(L);\n \
    \       }\n    };\n\n    using P = pair<S, S>;\n    S N, M;\n    vector<BinaryIndexedTree>\
    \ bit;\n    vector<vector<S>> ys;\n    vector<P> ps;\n\n    RangeTree() {}\n\n\
    \    void add_point(S x, S y){\n        ps.push_back(make_pair(x, y));\n    }\n\
    \n    void build(){\n        sort(ps.begin(), ps.end());\n        ps.erase(unique(ps.begin(),\
    \ ps.end()), ps.end());\n\n        N = ps.size();\n        bit.resize(N + 1);\n\
    \        ys.resize(N + 1);\n        for(int i = 0; i <= N; ++i){\n           \
    \ int j = i + 1;\n            while(j <= N){\n                ys[j].push_back(ps[i].second);\n\
    \                j += j & -j;\n            }\n\n            sort(ys[i].begin(),\
    \ ys[i].end());\n            ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());\n\
    \            bit[i].init(ys[i].size());\n        }\n    }\n\n    int id(S x) const\
    \ {\n        auto f = [](const P &a, const P &b){\n            return a.first\
    \ < b.first;\n        };\n        return lower_bound(ps.begin(), ps.end(), make_pair(x,\
    \ S()), f) - ps.begin();\n    }\n\n    int id(int i, S y) const {\n        return\
    \ lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();\n    }\n\n    void\
    \ add(S x, S y, T a){\n        int i = lower_bound(ps.begin(), ps.end(), make_pair(x,\
    \ y)) - ps.begin();\n        assert(ps[i] == make_pair(x, y));\n        ++i;\n\
    \        while(i <= N){\n            bit[i].add(id(i, y), a);\n            i +=\
    \ i & -i;\n        }\n    }\n\n    T sum(S x, S y) const {\n        T ret = T();\n\
    \        int a = id(x);\n        while(a > 0){\n            ret += bit[a].sum(id(a,\
    \ y));\n            a -= a & -a;\n        }\n        return ret;\n    }\n\n  \
    \  // [(xl, yl), (xr, yr))\n    T sum(S xl, S yl, S xr, S yr) const {\n      \
    \  T ret = T();\n        int a = id(xl), b = id(xr);\n        while(a != b) {\n\
    \            if(a < b){\n                ret += bit[b].sum(id(b, yl), id(b, yr));\n\
    \                b -= b & -b;\n            } else{\n                ret -= bit[a].sum(id(a,\
    \ yl), id(a, yr));\n                a -= a & -a;\n            }\n        }\n \
    \       return ret;\n    }\n};\n#line 6 \"test/library_checker/data_structure/rectangle_sum.test.cpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    RangeTree<int, long long> tree;\n\
    \    vector<int> x(n), y(n);\n    vector<long long> w(n);\n    for(int i = 0;\
    \ i < n; i++){\n        cin >> x[i] >> y[i] >> w[i];\n        tree.add_point(x[i],\
    \ y[i]);\n    }\n    tree.build();\n    for(int i = 0; i < n; i++){\n        tree.add(x[i],\
    \ y[i], w[i]);\n    }\n    while(q--){\n        int l, d, r, u; cin >> l >> d\
    \ >> r >> u;\n        cout << tree.sum(l, d, r, u) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/range_tree.hpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    RangeTree<int, long long> tree;\n\
    \    vector<int> x(n), y(n);\n    vector<long long> w(n);\n    for(int i = 0;\
    \ i < n; i++){\n        cin >> x[i] >> y[i] >> w[i];\n        tree.add_point(x[i],\
    \ y[i]);\n    }\n    tree.build();\n    for(int i = 0; i < n; i++){\n        tree.add(x[i],\
    \ y[i], w[i]);\n    }\n    while(q--){\n        int l, d, r, u; cin >> l >> d\
    \ >> r >> u;\n        cout << tree.sum(l, d, r, u) << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/data_structure/range_tree.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/data_structure/rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/rectangle_sum.test.cpp
- /verify/test/library_checker/data_structure/rectangle_sum.test.cpp.html
title: test/library_checker/data_structure/rectangle_sum.test.cpp
---
