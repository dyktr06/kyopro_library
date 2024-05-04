---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/data_structure/lazy_segment_tree.hpp
    title: lib/data_structure/lazy_segment_tree.hpp
  - icon: ':x:'
    path: lib/others/compression.hpp
    title: "Compression (\u5EA7\u6A19\u5727\u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/area_of_union_of_rectangles
    links:
    - https://judge.yosupo.jp/problem/area_of_union_of_rectangles
  bundledCode: "#line 1 \"test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/lazy_segment_tree.hpp\"\
    \n\ntemplate <class S,\n    S(*op)(S, S),\n    S(*e)(),\n    class F,\n    S(*mapping)(F,\
    \ S),\n    F(*composition)(F, F),\n    F(*id)()>\nstruct LazySegTree{\nprivate:\n\
    \    int _n, size, log;\n    vector<S> d;\n    vector<F> lz;\n\n    void pull(int\
    \ k){ d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void all_apply(int k, F f){\n\
    \        d[k] = mapping(f, d[k]);\n        if(k < size) lz[k] = composition(f,\
    \ lz[k]);\n    }\n    void push(int k){\n        all_apply(2 * k, lz[k]);\n  \
    \      all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n    }\n\npublic:\n\
    \    LazySegTree() : LazySegTree(0){}\n    LazySegTree(int n) : LazySegTree(vector<S>(n,\
    \ e())){}\n    LazySegTree(const vector<S> &v) : _n(int(v.size())){\n        log\
    \ = 0;\n        size = 1;\n        while(size < _n) size <<= 1, log++;\n     \
    \   d = vector<S>(2 * size, e());\n        lz = vector<F>(size, id());\n     \
    \   for(int i = 0; i < _n; i++) d[size + i] = v[i];\n        for(int i = size\
    \ - 1; i >= 1; i--){\n            pull(i);\n        }\n    }\n\n    void update(int\
    \ p, S x){\n        assert(0 <= p && p < _n);\n        p += size;\n        for(int\
    \ i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for(int i =\
    \ 1; i <= log; i++) pull(p >> i);\n    }\n\n    S get(int p){\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for(int i = log; i >= 1; i--)\
    \ push(p >> i);\n        return d[p];\n    }\n\n    S query(int l, int r){\n \
    \       assert(0 <= l && l <= r && r <= _n);\n        if(l == r) return e();\n\
    \n        l += size;\n        r += size;\n\n        for(int i = log; i >= 1; i--){\n\
    \            if(((l >> i) << i) != l) push(l >> i);\n            if(((r >> i)\
    \ << i) != r) push(r >> i);\n        }\n\n        S sml = e(), smr = e();\n  \
    \      while(l < r){\n            if(l & 1) sml = op(sml, d[l++]);\n         \
    \   if(r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_query(){ return\
    \ d[1]; }\n\n    void apply(int p, F f){\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        for(int i = log; i >= 1; i--) push(p >> i);\n   \
    \     d[p] = mapping(f, d[p]);\n        for(int i = 1; i <= log; i++) pull(p >>\
    \ i);\n    }\n    void apply(int l, int r, F f){\n        assert(0 <= l && l <=\
    \ r && r <= _n);\n        if(l == r) return;\n\n        l += size;\n        r\
    \ += size;\n\n        for(int i = log; i >= 1; i--){\n            if(((l >> i)\
    \ << i) != l) push(l >> i);\n            if(((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n          \
    \  while(l < r){\n                if(l & 1) all_apply(l++, f);\n             \
    \   if(r & 1) all_apply(--r, f);\n                l >>= 1;\n                r\
    \ >>= 1;\n            }\n            l = l2;\n            r = r2;\n        }\n\
    \n        for(int i = 1; i <= log; i++){\n            if(((l >> i) << i) != l)\
    \ pull(l >> i);\n            if(((r >> i) << i) != r) pull((r - 1) >> i);\n  \
    \      }\n    }\n\n    template <bool (*g)(S)>\n    int max_right(int l){\n  \
    \      return max_right(l, [](S x){ return g(x); });\n    }\n    template <class\
    \ G>\n    int max_right(int l, G g){\n        assert(0 <= l && l <= _n);\n   \
    \     assert(g(e()));\n        if(l == _n) return _n;\n        l += size;\n  \
    \      for(int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n    \
    \    do{\n            while(l % 2 == 0) l >>= 1;\n            if(!g(op(sm, d[l]))){\n\
    \                while(l < size){\n                    push(l);\n            \
    \        l = (2 * l);\n                    if(g(op(sm, d[l]))){\n            \
    \            sm = op(sm, d[l]);\n                        l++;\n              \
    \      }\n                }\n                return l - size;\n            }\n\
    \            sm = op(sm, d[l]);\n            l++;\n        } while((l & -l) !=\
    \ l);\n        return _n;\n    }\n\n    template <bool (*g)(S)>\n    int min_left(int\
    \ r){\n        return min_left(r, [](S x){ return g(x); });\n    }\n    template\
    \ <class G>\n    int min_left(int r, G g){\n        assert(0 <= r && r <= _n);\n\
    \        assert(g(e()));\n        if(r == 0) return 0;\n        r += size;\n \
    \       for(int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = e();\n\
    \        do{\n            r--;\n            while(r > 1 && (r % 2)) r >>= 1;\n\
    \            if(!g(op(d[r], sm))){\n                while(r < size){\n       \
    \             push(r);\n                    r = (2 * r + 1);\n               \
    \     if(g(op(d[r], sm))){\n                        sm = op(d[r], sm);\n     \
    \                   r--;\n                    }\n                }\n         \
    \       return r + 1 - size;\n            }\n            sm = op(d[r], sm);\n\
    \        } while((r & -r) != r);\n        return 0;\n    }\n};\n#line 2 \"lib/others/compression.hpp\"\
    \n\n/**\n * @brief Compression (\u5EA7\u6A19\u5727\u7E2E)\n * @docs docs/others/compression.md\n\
    \ */\n\ntemplate <typename T>\nstruct compress{\n    vector<T> sorted;\n    vector<int>\
    \ compressed;\n\n    compress(const vector<T> &vec){\n        int n = vec.size();\n\
    \        compressed.resize(n);\n        for(T x : vec){\n            sorted.emplace_back(x);\n\
    \        }\n        sort(sorted.begin(), sorted.end());\n        sorted.erase(unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n        for(int i = 0; i < n; ++i){\n       \
    \     compressed[i] = lower_bound(sorted.begin(), sorted.end(), vec[i]) - sorted.begin();\n\
    \        }\n    }\n\n    int get(const T &x) const{\n        return lower_bound(sorted.begin(),\
    \ sorted.end(), x) - sorted.begin();\n    }\n\n    T inv(const int x) const{\n\
    \        return sorted[x];\n    }\n\n    size_t size() const{\n        return\
    \ sorted.size();\n    }\n\n    vector<T> getCompressed() const{\n        return\
    \ compressed;\n    }\n};\n#line 7 \"test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp\"\
    \n\nconst long long INF = 0x1fffffffffffffff;\n\nstruct S{\n    long long len,\
    \ mn;\n};\n\nstruct F{\n    long long add;\n};\n\nF ID = {0};\n\nS op(S l, S r){\n\
    \    if(l.mn < r.mn){\n        return l;\n    }\n    if(l.mn > r.mn){\n      \
    \  return r;\n    }\n    return S{l.len + r.len, l.mn};\n}\n\nS e(){\n    return\
    \ S{0, INF};\n}\n\nS mapping(F f, S x){\n    return S{x.len, x.mn + f.add};\n\
    }\n\nF composition(F f, F g){\n    return F{f.add + g.add};\n}\n\nF id(){\n  \
    \  return ID;\n}\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int n; cin >> n;\n    vector<long long> l(n), d(n), r(n), u(n);\n    vector<long\
    \ long> x, y;\n    for(int i = 0; i < n; i++){\n        cin >> l[i] >> d[i] >>\
    \ r[i] >> u[i];\n        x.push_back(l[i]);\n        x.push_back(r[i]);\n    \
    \    y.push_back(d[i]);\n        y.push_back(u[i]);\n    }\n    compress<long\
    \ long> xc(x), yc(y);\n    int xs = xc.size(), ys = yc.size();\n    LazySegTree<S,\
    \ op, e, F, mapping, composition, id> seg(xs - 1);\n    for(int i = 0; i < xs\
    \ - 1; i++){\n        seg.update(i, {xc.inv(i + 1) - xc.inv(i), 0});\n    }\n\
    \    vector<vector<tuple<int, int, int>>> q(ys);\n    for(int i = 0; i < n; i++){\n\
    \        int l_ = xc.compressed[2 * i], r_ = xc.compressed[2 * i + 1];\n     \
    \   q[yc.compressed[2 * i]].emplace_back(l_, r_, 1);\n        q[yc.compressed[2\
    \ * i + 1]].emplace_back(l_, r_, -1);\n    }\n    long long ans = 0;\n    long\
    \ long xlen = xc.inv(xs - 1) - xc.inv(0);\n    for(int i = 0; i < ys - 1; i++){\n\
    \        for(auto [l_, r_, w] : q[i]){\n            seg.apply(l_, r_, F{w});\n\
    \        }\n        S res = seg.all_query();\n        long long t = (res.mn ==\
    \ 0) ? (xlen - res.len) : (xlen); \n        ans += t * (yc.inv(i + 1) - yc.inv(i));\n\
    \    }\n    cout << ans << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/lazy_segment_tree.hpp\"\
    \n#include \"../../../lib/others/compression.hpp\"\n\nconst long long INF = 0x1fffffffffffffff;\n\
    \nstruct S{\n    long long len, mn;\n};\n\nstruct F{\n    long long add;\n};\n\
    \nF ID = {0};\n\nS op(S l, S r){\n    if(l.mn < r.mn){\n        return l;\n  \
    \  }\n    if(l.mn > r.mn){\n        return r;\n    }\n    return S{l.len + r.len,\
    \ l.mn};\n}\n\nS e(){\n    return S{0, INF};\n}\n\nS mapping(F f, S x){\n    return\
    \ S{x.len, x.mn + f.add};\n}\n\nF composition(F f, F g){\n    return F{f.add +\
    \ g.add};\n}\n\nF id(){\n    return ID;\n}\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n; cin >> n;\n    vector<long long> l(n), d(n),\
    \ r(n), u(n);\n    vector<long long> x, y;\n    for(int i = 0; i < n; i++){\n\
    \        cin >> l[i] >> d[i] >> r[i] >> u[i];\n        x.push_back(l[i]);\n  \
    \      x.push_back(r[i]);\n        y.push_back(d[i]);\n        y.push_back(u[i]);\n\
    \    }\n    compress<long long> xc(x), yc(y);\n    int xs = xc.size(), ys = yc.size();\n\
    \    LazySegTree<S, op, e, F, mapping, composition, id> seg(xs - 1);\n    for(int\
    \ i = 0; i < xs - 1; i++){\n        seg.update(i, {xc.inv(i + 1) - xc.inv(i),\
    \ 0});\n    }\n    vector<vector<tuple<int, int, int>>> q(ys);\n    for(int i\
    \ = 0; i < n; i++){\n        int l_ = xc.compressed[2 * i], r_ = xc.compressed[2\
    \ * i + 1];\n        q[yc.compressed[2 * i]].emplace_back(l_, r_, 1);\n      \
    \  q[yc.compressed[2 * i + 1]].emplace_back(l_, r_, -1);\n    }\n    long long\
    \ ans = 0;\n    long long xlen = xc.inv(xs - 1) - xc.inv(0);\n    for(int i =\
    \ 0; i < ys - 1; i++){\n        for(auto [l_, r_, w] : q[i]){\n            seg.apply(l_,\
    \ r_, F{w});\n        }\n        S res = seg.all_query();\n        long long t\
    \ = (res.mn == 0) ? (xlen - res.len) : (xlen); \n        ans += t * (yc.inv(i\
    \ + 1) - yc.inv(i));\n    }\n    cout << ans << \"\\n\";\n}\n"
  dependsOn:
  - lib/data_structure/lazy_segment_tree.hpp
  - lib/others/compression.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
- /verify/test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp.html
title: test/library_checker/data_structure/area_of_union_of_rectangles.test.cpp
---
