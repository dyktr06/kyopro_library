---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/data_structure/segment_tree.hpp
    title: Segment Tree
  - icon: ':x:'
    path: lib/graph/heavy_light_decomposition.hpp
    title: "Heavy Light Decomposition (\u91CD\u8EFD\u5206\u89E3)"
  - icon: ':question:'
    path: lib/math/modint.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/library_checker/data_structure/vertex_set_path_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/segment_tree.hpp\"\
    \n\n/**\n * @brief Segment Tree\n * @docs docs/data_structure/segment_tree.md\n\
    \ */\n\ntemplate <typename X>\nstruct SegTree{\n    using FX = function<X(X, X)>;\
    \ // X\u2022X -> X \u3068\u306A\u308B\u95A2\u6570\u306E\u578B\n    int n;\n  \
    \  FX fx;\n    const X ex;\n    vector<X> dat;\n\n    SegTree(int n_, const FX\
    \ &fx_, const X &ex_) : n(), fx(fx_), ex(ex_){\n        int x = 1;\n        while(n_\
    \ > x){\n            x *= 2;\n        }\n        n = x;\n        dat.assign(n\
    \ * 2, ex);\n    }\n\n    X get(int i) const {\n        return dat[i + n];\n \
    \   }\n\n    void set(int i, const X &x){ dat[i + n] = x; }\n\n    void build(){\n\
    \        for(int k = n - 1; k >= 1; k--) dat[k] = fx(dat[k * 2], dat[k * 2 + 1]);\n\
    \    }\n\n    void update(int i, const X &x){\n        i += n;\n        dat[i]\
    \ = x;\n        while(i > 0){\n            i >>= 1;  // parent\n            dat[i]\
    \ = fx(dat[i * 2], dat[i * 2 + 1]);\n        }\n    }\n\n    X query(int a, int\
    \ b){\n        X vl = ex;\n        X vr = ex;\n        int l = a + n;\n      \
    \  int r = b + n;\n        while(l < r){\n            if(l & 1) vl = fx(vl, dat[l++]);\n\
    \            if(r & 1) vr = fx(dat[--r], vr);\n            l >>= 1;\n        \
    \    r >>= 1;\n        }\n        return fx(vl, vr);\n    }\n\n    X operator\
    \ [](int i) const {\n        return dat[i + n];\n    }\n};\n#line 2 \"lib/graph/heavy_light_decomposition.hpp\"\
    \n\n/**\n * @brief Heavy Light Decomposition (\u91CD\u8EFD\u5206\u89E3)\n * @docs\
    \ docs/graph/heavy_light_decomposition.md\n */\n\nclass HeavyLightDecomposition{\n\
    protected:\n    int V;\n    vector<vector<int>> G;\n    vector<int> stsize, parent,\
    \ pathtop, depth, in, reverse_in, out;\n    int root;\n\nprivate:\n    // Subtree\
    \ Size\n    void buildStsize(int curr, int prev){\n        stsize[curr] = 1, parent[curr]\
    \ = prev;\n        for(int &v : G[curr]){\n            if(v == prev){\n      \
    \          if(v == G[curr].back()) break;\n                else swap(v, G[curr].back());\n\
    \            }\n            buildStsize(v, curr);\n            stsize[curr] +=\
    \ stsize[v];\n            if(stsize[v] > stsize[G[curr][0]]){\n              \
    \  swap(v, G[curr][0]);\n            }\n        }\n    }\n\n    void buildPath(int\
    \ curr, int prev, int &t){\n        in[curr] = t++;\n        reverse_in[in[curr]]\
    \ = curr;\n        for(int v : G[curr]){\n            if(v == prev) continue;\n\
    \n            if(v == G[curr][0]){\n                pathtop[v] = pathtop[curr];\n\
    \            } else{\n                pathtop[v] = v;\n            }\n       \
    \     depth[v] = depth[curr] + 1;\n            buildPath(v, curr, t);\n      \
    \  }\n        out[curr] = t;\n    }\n\npublic:\n    HeavyLightDecomposition(int\
    \ node_size) : V(node_size), G(V), stsize(V, 0), parent(V, -1),\n        pathtop(V,\
    \ -1), depth(V, 0), in(V, -1), reverse_in(V, -1), out(V, -1){}\n\n    void add_edge(int\
    \ u, int v){\n        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n\
    \    void build(int _root = 0){\n        root = _root;\n        int t = 0;\n \
    \       buildStsize(root, -1);\n        pathtop[root] = root;\n        buildPath(root,\
    \ -1, t);\n    }\n\n    inline int get(int a){\n        return in[a];\n    }\n\
    \n    int la(int a, int k) {\n        while(true){\n            int u = pathtop[a];\n\
    \            if(in[a] - k >= in[u]) return reverse_in[in[a] - k];\n          \
    \  k -= in[a] - in[u] + 1;\n            a = parent[u];\n        }\n    }\n\n \
    \   int lca(int a, int b){\n        int pa = pathtop[a], pb = pathtop[b];\n  \
    \      while(pathtop[a] != pathtop[b]){\n            if(in[pa] > in[pb]){\n  \
    \              a = parent[pa], pa = pathtop[a];\n            } else{\n       \
    \         b = parent[pb], pb = pathtop[b];\n            }\n        }\n       \
    \ if(in[a] > in[b]) swap(a, b);\n        return a;\n    }\n\n    int dist(int\
    \ a, int b){ return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }\n\n    int jump(int\
    \ from, int to, int k) {\n        if(!k) return from;\n        int l = lca(from,\
    \ to);\n        int d = dist(from, to);\n        if(d < k) return -1;\n      \
    \  if(depth[from] - depth[l] >= k) return la(from, k);\n        k -= depth[from]\
    \ - depth[l];\n        return la(to, depth[to] - depth[l] - k);\n    }\n\n   \
    \ void subtree_query(int a, const function<void(int, int)> &func){\n        func(in[a],\
    \ out[a]);\n    }\n\n    void path_query(int a, int b, const function<void(int,\
    \ int)> &func, bool include_root = true, bool reverse_path = false){\n       \
    \ vector<pair<int, int>> path;\n        int pa = pathtop[a], pb = pathtop[b];\n\
    \        while(pathtop[a] != pathtop[b]){\n            if(in[pa] > in[pb]){\n\
    \                path.emplace_back(in[pa], in[a] + 1);\n                a = parent[pa],\
    \ pa = pathtop[a];\n            } else{\n                path.emplace_back(in[pb],\
    \ in[b] + 1);\n                b = parent[pb], pb = pathtop[b];\n            }\n\
    \        }\n        if(in[a] > in[b]) swap(a, b);\n\n        if(include_root)\
    \ path.emplace_back(in[a], in[b] + 1);\n        else path.emplace_back(in[a] +\
    \ 1, in[b] + 1);\n\n        if(!reverse_path) reverse(path.begin(), path.end());\n\
    \        else for(auto &p : path) p = make_pair(V - p.second, V - p.first);\n\n\
    \        for(auto [u, v] : path){\n            func(u, v);\n        }\n    }\n\
    \n    void path_noncommutative_query(int a, int b, const function<void(int, int)>\
    \ &func, const function<void(int, int)> &func2){\n        int l = lca(a, b);\n\
    \        path_query(a, l, func2, false, true);\n        path_query(l, b, func,\
    \ true, false);\n    }\n};\n#line 2 \"lib/math/modint.hpp\"\n\n/**\n * @brief\
    \ ModInt\n * @docs docs/math/modint.md\n */\n\ntemplate <long long Modulus>\n\
    struct ModInt{\n    long long val;\n    constexpr ModInt(const long long _val\
    \ = 0) noexcept : val(_val) {\n        normalize();\n    }\n    void normalize(){\n\
    \        val = (val % Modulus + Modulus) % Modulus;\n    }\n    inline ModInt\
    \ &operator+=(const ModInt &rhs) noexcept {\n        if(val += rhs.val, val >=\
    \ Modulus) val -= Modulus;\n        return *this;\n    }\n    inline ModInt &operator-=(const\
    \ ModInt &rhs) noexcept {\n        if(val -= rhs.val, val < 0) val += Modulus;\n\
    \        return *this;\n    }\n    inline ModInt &operator*=(const ModInt &rhs)\
    \ noexcept {\n        val = val * rhs.val % Modulus;\n        return *this;\n\
    \    }\n    inline ModInt &operator/=(const ModInt &rhs) noexcept {\n        val\
    \ = val * inv(rhs.val).val % Modulus;\n        return *this;\n    }\n    inline\
    \ ModInt &operator++() noexcept {\n        if(++val >= Modulus) val -= Modulus;\n\
    \        return *this;\n    }\n    inline ModInt operator++(int) noexcept {\n\
    \        ModInt t = val;\n        if(++val >= Modulus) val -= Modulus;\n     \
    \   return t;\n    }\n    inline ModInt &operator--() noexcept {\n        if(--val\
    \ < 0) val += Modulus;\n        return *this;\n    }\n    inline ModInt operator--(int)\
    \ noexcept {\n        ModInt t = val;\n        if(--val < 0) val += Modulus;\n\
    \        return t;\n    }\n    inline ModInt operator-() const noexcept { return\
    \ (Modulus - val) % Modulus; }\n    inline ModInt inv(void) const { return inv(val);\
    \ }\n    ModInt pow(long long n){\n        assert(0 <= n);\n        ModInt x =\
    \ *this, r = 1;\n        while(n){\n            if(n & 1) r *= x;\n          \
    \  x *= x;\n            n >>= 1;\n        }\n        return r;\n    }\n    ModInt\
    \ inv(const long long n) const {\n        long long a = n, b = Modulus, u = 1,\
    \ v = 0;\n        while(b){\n            long long t = a / b;\n            a -=\
    \ t * b; swap(a, b);\n            u -= t * v; swap(u, v);\n        }\n       \
    \ u %= Modulus;\n        if(u < 0) u += Modulus;\n        return u;\n    }\n \
    \   friend inline ModInt operator+(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return ModInt(lhs) += rhs; }\n    friend inline ModInt operator-(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) -= rhs; }\n    friend\
    \ inline ModInt operator*(const ModInt &lhs, const ModInt &rhs) noexcept { return\
    \ ModInt(lhs) *= rhs; }\n    friend inline ModInt operator/(const ModInt &lhs,\
    \ const ModInt &rhs) noexcept { return ModInt(lhs) /= rhs; }\n    friend inline\
    \ bool operator==(const ModInt &lhs, const ModInt &rhs) noexcept { return lhs.val\
    \ == rhs.val; }\n    friend inline bool operator!=(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept { return lhs.val != rhs.val; }\n    friend inline istream &operator>>(istream\
    \ &is, ModInt &x) noexcept {\n        is >> x.val;\n        x.normalize();\n \
    \       return is;\n    }\n    friend inline ostream &operator<<(ostream &os,\
    \ const ModInt &x) noexcept { return os << x.val; }\n};\n#line 8 \"test/library_checker/data_structure/vertex_set_path_composite.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nint main(){\n    int n, q; cin >> n >>\
    \ q;\n    using T = pair<mint, mint>;\n    vector<T> f(n);\n    for(int i = 0;\
    \ i < n; i++){\n        cin >> f[i].first >> f[i].second;\n    }\n    HeavyLightDecomposition\
    \ hl(n);\n    for(int i = 1; i < n; i++){\n        int u, v; cin >> u >> v;\n\
    \        hl.add_edge(u, v);\n    }\n    hl.build();\n    \n    auto op = [](T\
    \ x1, T x2) -> T { \n        return {x1.first * x2.first, (x2.first * x1.second\
    \ + x2.second)};\n    };\n    T ex = {1, 0};\n    SegTree<T> seg(n, op, ex), seg2(n,\
    \ op, ex);\n    for(int i = 0; i < n; i++){\n        seg.update(hl.get(i), {f[i].first,\
    \ f[i].second});\n        seg2.update(n - hl.get(i) - 1, {f[i].first, f[i].second});\n\
    \    }\n    mint ans = 0;\n    T g = ex;\n    auto query = [&](int l, int r){\n\
    \        g = op(g, seg.query(l, r));\n    };\n    auto query2 = [&](int l, int\
    \ r){\n        g = op(g, seg2.query(l, r));\n    };\n    while(q--){\n       \
    \ int t; cin >> t;\n        if(t == 0){\n            int p, c, d; cin >> p >>\
    \ c >> d;\n            seg.update(hl.get(p), {c, d});\n            seg2.update(n\
    \ - hl.get(p) - 1, {c, d});\n        }else{\n            int u, v, x; cin >> u\
    \ >> v >> x;\n            g = ex;\n            hl.path_noncommutative_query(u,\
    \ v, query, query2);\n            ans = g.first * x + g.second;\n            cout\
    \ << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/segment_tree.hpp\"\
    \n#include \"../../../lib/graph/heavy_light_decomposition.hpp\"\n#include \"../../../lib/math/modint.hpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nint main(){\n    int n, q; cin >> n >>\
    \ q;\n    using T = pair<mint, mint>;\n    vector<T> f(n);\n    for(int i = 0;\
    \ i < n; i++){\n        cin >> f[i].first >> f[i].second;\n    }\n    HeavyLightDecomposition\
    \ hl(n);\n    for(int i = 1; i < n; i++){\n        int u, v; cin >> u >> v;\n\
    \        hl.add_edge(u, v);\n    }\n    hl.build();\n    \n    auto op = [](T\
    \ x1, T x2) -> T { \n        return {x1.first * x2.first, (x2.first * x1.second\
    \ + x2.second)};\n    };\n    T ex = {1, 0};\n    SegTree<T> seg(n, op, ex), seg2(n,\
    \ op, ex);\n    for(int i = 0; i < n; i++){\n        seg.update(hl.get(i), {f[i].first,\
    \ f[i].second});\n        seg2.update(n - hl.get(i) - 1, {f[i].first, f[i].second});\n\
    \    }\n    mint ans = 0;\n    T g = ex;\n    auto query = [&](int l, int r){\n\
    \        g = op(g, seg.query(l, r));\n    };\n    auto query2 = [&](int l, int\
    \ r){\n        g = op(g, seg2.query(l, r));\n    };\n    while(q--){\n       \
    \ int t; cin >> t;\n        if(t == 0){\n            int p, c, d; cin >> p >>\
    \ c >> d;\n            seg.update(hl.get(p), {c, d});\n            seg2.update(n\
    \ - hl.get(p) - 1, {c, d});\n        }else{\n            int u, v, x; cin >> u\
    \ >> v >> x;\n            g = ex;\n            hl.path_noncommutative_query(u,\
    \ v, query, query2);\n            ans = g.first * x + g.second;\n            cout\
    \ << ans << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - lib/data_structure/segment_tree.hpp
  - lib/graph/heavy_light_decomposition.hpp
  - lib/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/data_structure/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/vertex_set_path_composite.test.cpp
- /verify/test/library_checker/data_structure/vertex_set_path_composite.test.cpp.html
title: test/library_checker/data_structure/vertex_set_path_composite.test.cpp
---
