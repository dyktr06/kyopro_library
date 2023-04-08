---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/segment_tree_beats.hpp
    title: lib/data_structure/segment_tree_beats.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/segment_tree_beats.hpp\"\
    \n\ntemplate<typename T, T INF>\nstruct SegmentTreeBeats{\n    int n, n0;\n  \
    \  vector<T> max_v, smax_v, max_c;\n    vector<T> min_v, smin_v, min_c;\n    vector<T>\
    \ sum;\n    vector<T> len, ladd, lval;\n\n    void update_node_max(int k, T x)\
    \ {\n        sum[k] += (x - max_v[k]) * max_c[k];\n\n        if(max_v[k] == min_v[k]){\n\
    \            max_v[k] = min_v[k] = x;\n        }else if(max_v[k] == smin_v[k]){\n\
    \            max_v[k] = smin_v[k] = x;\n        }else{\n            max_v[k] =\
    \ x;\n        }\n\n        if(lval[k] != INF && x < lval[k]){\n            lval[k]\
    \ = x;\n        }\n    }\n\n    void update_node_min(int k, T x) {\n        sum[k]\
    \ += (x - min_v[k]) * min_c[k];\n\n        if(max_v[k] == min_v[k]){\n       \
    \     max_v[k] = min_v[k] = x;\n        }else if(smax_v[k] == min_v[k]){\n   \
    \         min_v[k] = smax_v[k] = x;\n        }else{\n            min_v[k] = x;\n\
    \        }\n\n        if(lval[k] != INF && lval[k] < x){\n            lval[k]\
    \ = x;\n        }\n    }\n\n    void push(int k){\n        if(n0 - 1 <= k) return;\n\
    \n        if(lval[k] != INF){\n            updateall(2 * k + 1, lval[k]);\n  \
    \          updateall(2 * k + 2, lval[k]);\n            lval[k] = INF;\n      \
    \      return;\n        }\n\n        if(ladd[k] != 0){\n            addall(2 *\
    \ k + 1, ladd[k]);\n            addall(2 * k + 2, ladd[k]);\n            ladd[k]\
    \ = 0;\n        }\n\n        if(max_v[k] < max_v[2 * k + 1]){\n            update_node_max(2\
    \ * k + 1, max_v[k]);\n        }\n        if(min_v[2 * k + 1] < min_v[k]){\n \
    \           update_node_min(2 * k + 1, min_v[k]);\n        }\n\n        if(max_v[k]\
    \ < max_v[2 * k + 2]){\n            update_node_max(2 * k + 2, max_v[k]);\n  \
    \      }\n        if(min_v[2 * k + 2] < min_v[k]){\n            update_node_min(2\
    \ * k + 2, min_v[k]);\n        }\n    }\n\n    void update(int k){\n        sum[k]\
    \ = sum[2 * k + 1] + sum[2 * k + 2];\n\n        if(max_v[2 * k + 1] < max_v[2\
    \ * k + 2]){\n            max_v[k] = max_v[2 * k + 2];\n            max_c[k] =\
    \ max_c[2 * k + 2];\n            smax_v[k] = max(max_v[2 * k + 1], smax_v[2 *\
    \ k + 2]);\n        }else if(max_v[2 * k + 1] > max_v[2 * k + 2]){\n         \
    \   max_v[k] = max_v[2 * k + 1];\n            max_c[k] = max_c[2 * k + 1];\n \
    \           smax_v[k] = max(smax_v[2 * k + 1], max_v[2 * k + 2]);\n        }else{\n\
    \            max_v[k] = max_v[2 * k + 1];\n            max_c[k] = max_c[2 * k\
    \ + 1] + max_c[2 * k + 2];\n            smax_v[k] = max(smax_v[2 * k + 1], smax_v[2\
    \ * k + 2]);\n        }\n\n        if(min_v[2 * k + 1] < min_v[2 * k + 2]){\n\
    \            min_v[k] = min_v[2 * k + 1];\n            min_c[k] = min_c[2 * k\
    \ + 1];\n            smin_v[k] = min(smin_v[2 * k + 1], min_v[2 * k + 2]);\n \
    \       }else if(min_v[2 * k + 1] > min_v[2 * k + 2]){\n            min_v[k] =\
    \ min_v[2 * k + 2];\n            min_c[k] = min_c[2 * k + 2];\n            smin_v[k]\
    \ = min(min_v[2 * k + 1], smin_v[2 * k + 2]);\n        }else{\n            min_v[k]\
    \ = min_v[2 * k + 1];\n            min_c[k] = min_c[2 * k + 1] + min_c[2 * k +\
    \ 2];\n            smin_v[k] = min(smin_v[2 * k + 1], smin_v[2 * k + 2]);\n  \
    \      }\n    }\n\n    void _query_chmin(T x, int a, int b, int k, int l, int\
    \ r) {\n        if(b <= l || r <= a || max_v[k] <= x){\n            return;\n\
    \        }\n        if(a <= l && r <= b && smax_v[k] < x){\n            update_node_max(k,\
    \ x);\n            return;\n        }\n\n        push(k);\n        _query_chmin(x,\
    \ a, b, 2 * k + 1, l, (l + r) / 2);\n        _query_chmin(x, a, b, 2 * k + 2,\
    \ (l + r) / 2, r);\n        update(k);\n    }\n\n    void _query_chmax(T x, int\
    \ a, int b, int k, int l, int r) {\n        if(b <= l || r <= a || x <= min_v[k]){\n\
    \            return;\n        }\n        if(a <= l && r <= b && x < smin_v[k]){\n\
    \            update_node_min(k, x);\n            return;\n        }\n\n      \
    \  push(k);\n        _query_chmax(x, a, b, 2 * k + 1, l, (l + r) / 2);\n     \
    \   _query_chmax(x, a, b, 2 * k + 2, (l + r) / 2, r);\n        update(k);\n  \
    \  }\n\n    void addall(int k, T x) {\n        max_v[k] += x;\n        if(smax_v[k]\
    \ != -INF) smax_v[k] += x;\n        min_v[k] += x;\n        if(smin_v[k] != INF)\
    \ smin_v[k] += x;\n\n        sum[k] += len[k] * x;\n        if(lval[k] != INF){\n\
    \            lval[k] += x;\n        }else{\n            ladd[k] += x;\n      \
    \  }\n    }\n\n    void updateall(int k, T x) {\n        max_v[k] = x; smax_v[k]\
    \ = -INF;\n        min_v[k] = x; smin_v[k] = INF;\n        max_c[k] = min_c[k]\
    \ = len[k];\n\n        sum[k] = x * len[k];\n        lval[k] = x; ladd[k] = 0;\n\
    \    }\n\n    void _query_add(T x, int a, int b, int k, int l, int r) {\n    \
    \    if(b <= l || r <= a){\n            return;\n        }\n        if(a <= l\
    \ && r <= b){\n            addall(k, x);\n            return;\n        }\n\n \
    \       push(k);\n        _query_add(x, a, b, 2 * k + 1, l, (l + r) / 2);\n  \
    \      _query_add(x, a, b, 2 * k + 2, (l + r) / 2, r);\n        update(k);\n \
    \   }\n\n    void _query_update(T x, int a, int b, int k, int l, int r) {\n  \
    \      if(b <= l || r <= a){\n            return;\n        }\n        if(a <=\
    \ l && r <= b){\n            updateall(k, x);\n            return;\n        }\n\
    \n        push(k);\n        _query_update(x, a, b, 2 * k + 1, l, (l + r) / 2);\n\
    \        _query_update(x, a, b, 2 * k + 2, (l + r) / 2, r);\n        update(k);\n\
    \    }\n\n    T _query_max(int a, int b, int k, int l, int r) {\n        if(b\
    \ <= l || r <= a){\n            return -INF;\n        }\n        if(a <= l &&\
    \ r <= b){\n            return max_v[k];\n        }\n        push(k);\n      \
    \  T lv = _query_max(a, b, 2 * k + 1, l, (l + r) / 2);\n        T rv = _query_max(a,\
    \ b, 2 * k + 2, (l + r) / 2, r);\n        return max(lv, rv);\n    }\n\n    T\
    \ _query_min(int a, int b, int k, int l, int r) {\n        if(b <= l || r <= a){\n\
    \            return INF;\n        }\n        if(a <= l && r <= b){\n         \
    \   return min_v[k];\n        }\n        push(k);\n        T lv = _query_min(a,\
    \ b, 2 * k + 1, l, (l + r) / 2);\n        T rv = _query_min(a, b, 2 * k + 2, (l\
    \ + r) / 2, r);\n        return min(lv, rv);\n    }\n\n    T _query_sum(int a,\
    \ int b, int k, int l, int r) {\n        if(b <= l || r <= a){\n            return\
    \ 0;\n        }\n        if(a <= l && r <= b){\n            return sum[k];\n \
    \       }\n        push(k);\n        T lv = _query_sum(a, b, 2 * k + 1, l, (l\
    \ + r) / 2);\n        T rv = _query_sum(a, b, 2 * k + 2, (l + r) / 2, r);\n  \
    \      return lv + rv;\n    }\n\npublic:\n    SegmentTreeBeats(int n) : n(n){\n\
    \        vector<T> a;\n        init(n, a);\n    }\n\n    SegmentTreeBeats(int\
    \ n, vector<T> &a) : n(n){\n        init(n, a);\n    }\n\n    void init(int n,\
    \ vector<T> &a){\n        max_v.assign(4 * n, 0), smax_v.assign(4 * n, 0), max_c.assign(4\
    \ * n, 0);\n        min_v.assign(4 * n, 0), smin_v.assign(4 * n, 0), min_c.assign(4\
    \ * n, 0);\n        sum.assign(4 * n, 0);\n        len.assign(4 * n, 0), ladd.assign(4\
    \ * n, 0); lval.assign(4 * n, 0);\n\n        n0 = 1;\n        while(n0 < n) n0\
    \ <<= 1;\n\n        for(int i = 0; i < 2 * n0; ++i) ladd[i] = 0, lval[i] = INF;\n\
    \        len[0] = n0;\n        for(int i = 0; i < n0 - 1; ++i) len[2 * i + 1]\
    \ = len[2 * i + 2] = (len[i] >> 1);\n\n        for(int i = 0; i < n; ++i){\n \
    \           max_v[n0 - 1 + i] = min_v[n0 - 1 + i] = sum[n0 - 1 + i] = (!a.empty()\
    \ ? a[i] : 0);\n            smax_v[n0 - 1 + i] = -INF;\n            smin_v[n0\
    \ - 1 + i] = INF;\n            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 1;\n  \
    \      }\n\n        for(int i = n; i < n0; ++i){\n            max_v[n0 - 1 + i]\
    \ = smax_v[n0 - 1 + i] = -INF;\n            min_v[n0 - 1 + i] = smin_v[n0 - 1\
    \ + i] = INF;\n            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;\n      \
    \  }\n        for(int i = n0 - 2; i >= 0; --i){\n            update(i);\n    \
    \    }\n    }\n\n    // range minimize query\n    void query_chmin(int a, int\
    \ b, T x){\n        _query_chmin(x, a, b, 0, 0, n0);\n    }\n\n    // range maximize\
    \ query\n    void query_chmax(int a, int b, T x){\n        _query_chmax(x, a,\
    \ b, 0, 0, n0);\n    }\n\n    // range add query\n    void query_add(int a, int\
    \ b, T x){\n        _query_add(x, a, b, 0, 0, n0);\n    }\n\n    // range update\
    \ query\n    void query_update(int a, int b, T x){\n        _query_update(x, a,\
    \ b, 0, 0, n0);\n    }\n\n    // range minimum query\n    T query_max(int a, int\
    \ b){\n        return _query_max(a, b, 0, 0, n0);\n    }\n\n    // range maximum\
    \ query\n    T query_min(int a, int b){\n        return _query_min(a, b, 0, 0,\
    \ n0);\n    }\n\n    // range sum query\n    T query_sum(int a, int b){\n    \
    \    return _query_sum(a, b, 0, 0, n0);\n    }\n\n    T get(int x){\n        return\
    \ _query_sum(x, x + 1, 0, 0, n0);\n    }\n};\n#line 6 \"test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n\nconst long long INF = 1LL << 60;\n\nint main(){\n    cin.tie(nullptr);\n \
    \   ios::sync_with_stdio(false);\n\n    int n, q; cin >> n >> q;\n    vector<long\
    \ long> a(n);\n    for(int i = 0; i < n; i++){\n        cin >> a[i];\n    }\n\
    \    SegmentTreeBeats<long long, INF> seg(n, a);\n    while(q--){\n        int\
    \ t; cin >> t;\n        if(t == 0){\n            int l, r; long long b; cin >>\
    \ l >> r >> b;\n            seg.query_chmin(l, r, b);\n        }else if(t == 1){\n\
    \            int l, r; long long b; cin >> l >> r >> b;\n            seg.query_chmax(l,\
    \ r, b);\n        }else if(t == 2){\n            int l, r; long long b; cin >>\
    \ l >> r >> b;\n            seg.query_add(l, r, b);\n        }else{\n        \
    \    int l, r; cin >> l >> r;\n            cout << seg.query_sum(l, r) << \"\\\
    n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/segment_tree_beats.hpp\"\
    \n\nconst long long INF = 1LL << 60;\n\nint main(){\n    cin.tie(nullptr);\n \
    \   ios::sync_with_stdio(false);\n\n    int n, q; cin >> n >> q;\n    vector<long\
    \ long> a(n);\n    for(int i = 0; i < n; i++){\n        cin >> a[i];\n    }\n\
    \    SegmentTreeBeats<long long, INF> seg(n, a);\n    while(q--){\n        int\
    \ t; cin >> t;\n        if(t == 0){\n            int l, r; long long b; cin >>\
    \ l >> r >> b;\n            seg.query_chmin(l, r, b);\n        }else if(t == 1){\n\
    \            int l, r; long long b; cin >> l >> r >> b;\n            seg.query_chmax(l,\
    \ r, b);\n        }else if(t == 2){\n            int l, r; long long b; cin >>\
    \ l >> r >> b;\n            seg.query_add(l, r, b);\n        }else{\n        \
    \    int l, r; cin >> l >> r;\n            cout << seg.query_sum(l, r) << \"\\\
    n\";\n        }\n    }\n}"
  dependsOn:
  - lib/data_structure/segment_tree_beats.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-04-09 03:29:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
---
