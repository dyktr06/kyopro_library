---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/range_parallel_union_find.hpp
    title: lib/data_structure/range_parallel_union_find.hpp
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/segment_tree_func.hpp
    title: lib/data_structure/segment_tree_func.hpp
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/union_find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: lib/math/modint.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_parallel_unionfind
    links:
    - https://judge.yosupo.jp/problem/range_parallel_unionfind
  bundledCode: "#line 1 \"test/library_checker/data_structure/range_parallel_unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_parallel_unionfind\"\
    \n#include <iostream>\n\n#line 2 \"lib/data_structure/range_parallel_union_find.hpp\"\
    \n\n#line 2 \"lib/data_structure/union_find.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n\n/**\n * @brief Union Find\n * @docs docs/data_structure/union_find.md\n\
    \ */\n\nstruct UnionFind{\n    int V;\n    std::vector<int> par;\n    std::vector<int>\
    \ edg;\n\n    UnionFind(int N) : V(N), par(N), edg(N){\n        for(int i = 0;\
    \ i < N; ++i){\n            par[i] = -1;\n            edg[i] = 0;\n        }\n\
    \    }\n\n    int root(int x){\n        assert(0 <= x && x < V);\n        if(par[x]\
    \ < 0) return x;\n        return par[x] = root(par[x]);\n    }\n\n    int unite(int\
    \ x, int y){\n        int rx = root(x);\n        int ry = root(y);\n        if(rx\
    \ == ry){\n            edg[rx]++;\n            return rx;\n        }\n       \
    \ if(-par[rx] < -par[ry]) std::swap(rx, ry);\n        par[rx] = par[rx] + par[ry];\n\
    \        par[ry] = rx;\n        edg[rx] += edg[ry] + 1;\n        return rx;\n\
    \    }\n\n    bool same(int x, int y){\n        int rx = root(x);\n        int\
    \ ry = root(y);\n        return rx == ry;\n    }\n\n    long long size(int x){\n\
    \        return -par[root(x)];\n    }\n\n    long long edge(int x){\n        return\
    \ edg[root(x)];\n    }\n};\n#line 2 \"lib/data_structure/segment_tree_func.hpp\"\
    \n\n#line 5 \"lib/data_structure/segment_tree_func.hpp\"\n\ntemplate <typename\
    \ T, T (*op)(T, T), T(*e)()>\nstruct SegTree{\n    int n;\n    std::vector<T>\
    \ dat;\n\n    SegTree(int n_){\n        int x = 1;\n        while(n_ > x){\n \
    \           x *= 2;\n        }\n        n = x;\n        dat.resize(n * 2);\n \
    \       for(int i = 0; i < n * 2; ++i){\n            dat[i] = e();\n        }\n\
    \    }\n    SegTree(std::vector<T> &v){\n        int x = 1;\n        while((int)\
    \ v.size() > x){\n            x *= 2;\n        }\n        n = x;\n        dat.resize(n\
    \ * 2);\n        for(int i = 0; i < n; ++i){\n            set(i, (i < (int) v.size()\
    \ ? v[i] : e()));\n        }\n        build();\n    }\n\nprivate:\n    void set(int\
    \ i, const T &x){ dat[i + n] = x; }\n\n    void build(){\n        for(int k =\
    \ n - 1; k >= 1; k--) dat[k] = op(dat[k * 2], dat[k * 2 + 1]);\n    }\n\npublic:\n\
    \    T get(int i) const {\n        assert(0 <= i && i < n);\n        return dat[i\
    \ + n];\n    }\n\n    void update(int i, const T &x){\n        assert(0 <= i &&\
    \ i < n);\n        i += n;\n        dat[i] = x;\n        while(i > 0){\n     \
    \       i >>= 1;  // parent\n            dat[i] = op(dat[i * 2], dat[i * 2 + 1]);\n\
    \        }\n    }\n\n    T query(int a, int b){\n        assert(0 <= a && a <=\
    \ b && b <= n);\n        T vl = e();\n        T vr = e();\n        int l = a +\
    \ n;\n        int r = b + n;\n        while(l < r){\n            if(l & 1) vl\
    \ = op(vl, dat[l++]);\n            if(r & 1) vr = op(dat[--r], vr);\n        \
    \    l >>= 1;\n            r >>= 1;\n        }\n        return op(vl, vr);\n \
    \   }\n};\n#line 5 \"lib/data_structure/range_parallel_union_find.hpp\"\n\n#line\
    \ 8 \"lib/data_structure/range_parallel_union_find.hpp\"\n\nnamespace internal_unionfind{\n\
    \    using i128 = __int128_t;\n    constexpr i128 mod = (1LL << 61) - 1;\n   \
    \ constexpr i128 base = 1000003;\n    using T = std::pair<i128, i128>;\n\n   \
    \ T op(T a, T b){\n        auto [hash1, len1] = a;\n        auto [hash2, len2]\
    \ = b;\n        return std::make_pair((hash1 + hash2 * len1) % mod, (len1 * len2)\
    \ % mod);\n    }\n\n    // {hash, len}\n    T e(){\n        return std::make_pair(0,\
    \ 1);\n    }\n}\n\nstruct RangeParallelUnionFind{\n    int V;\n    std::vector<std::vector<int>>\
    \ v;\n    UnionFind uf;\n    SegTree<internal_unionfind::T, internal_unionfind::op,\
    \ internal_unionfind::e> seg;\n\nprivate:\n    template <typename F>\n    void\
    \ merge(int a, int b, const F &f){\n        int ra = uf.root(a), rb = uf.root(b);\n\
    \        if(ra == rb) return;\n        if(uf.unite(ra, rb) == rb) std::swap(ra,\
    \ rb);\n        for(auto e : v[rb]){\n            v[ra].push_back(e);\n      \
    \      seg.update(e, std::make_pair(ra, internal_unionfind::base));\n        }\n\
    \        f(ra, rb);\n    }\n\npublic:\n    RangeParallelUnionFind(int n) : V(n),\
    \ v(n), uf(n), seg(n){\n        for(int i = 0; i < n; ++i){\n            seg.update(i,\
    \ std::make_pair(i, internal_unionfind::base));\n            v[i].push_back(i);\n\
    \        }\n    }\n\n    // [a, a + k) \u3068 [b, b + k) \u3092\u30DE\u30FC\u30B8\
    \n    template <typename F>\n    void unite(int k, int a, int b, const F &f){\n\
    \        assert(0 <= a && a + k <= V);\n        assert(0 <= b && b + k <= V);\n\
    \        int prev = 0;\n        while(seg.query(a, a + k).first != seg.query(b,\
    \ b + k).first){\n            int ok = k, ng = prev;\n            while(abs(ok\
    \ - ng) > 1){\n                int mid = (ok + ng) / 2;\n                if(seg.query(a,\
    \ a + mid).first != seg.query(b, b + mid).first){\n                    ok = mid;\n\
    \                }else{\n                    ng = mid;\n                }\n  \
    \          }\n            merge(a + ok - 1, b + ok - 1, f);\n            prev\
    \ = ok;\n        }\n    }\n\n    template <typename F>\n    void unite(int a,\
    \ int b, const F &f){\n        unite(1, a, b, f);\n    }\n\n    int root(int a){\n\
    \        return uf.root(a);\n    }\n\n    bool same(int a, int b){\n        return\
    \ uf.same(a, b);\n    }\n\n    long long size(int a){\n        return uf.size(a);\n\
    \    }\n};\n#line 2 \"lib/math/modint.hpp\"\n\n#line 5 \"lib/math/modint.hpp\"\
    \n\n/**\n * @brief ModInt\n * @docs docs/math/modint.md\n */\n\ntemplate <long\
    \ long Modulus>\nstruct ModInt{\n    long long val;\n    static constexpr int\
    \ mod() { return Modulus; }\n    constexpr ModInt(const long long _val = 0) noexcept\
    \ : val(_val) {\n        normalize();\n    }\n    void normalize(){\n        val\
    \ = (val % Modulus + Modulus) % Modulus;\n    }\n    inline ModInt &operator+=(const\
    \ ModInt &rhs) noexcept {\n        if(val += rhs.val, val >= Modulus) val -= Modulus;\n\
    \        return *this;\n    }\n    inline ModInt &operator-=(const ModInt &rhs)\
    \ noexcept {\n        if(val -= rhs.val, val < 0) val += Modulus;\n        return\
    \ *this;\n    }\n    inline ModInt &operator*=(const ModInt &rhs) noexcept {\n\
    \        val = val * rhs.val % Modulus;\n        return *this;\n    }\n    inline\
    \ ModInt &operator/=(const ModInt &rhs) noexcept {\n        val = val * inv(rhs.val).val\
    \ % Modulus;\n        return *this;\n    }\n    inline ModInt &operator++() noexcept\
    \ {\n        if(++val >= Modulus) val -= Modulus;\n        return *this;\n   \
    \ }\n    inline ModInt operator++(int) noexcept {\n        ModInt t = val;\n \
    \       if(++val >= Modulus) val -= Modulus;\n        return t;\n    }\n    inline\
    \ ModInt &operator--() noexcept {\n        if(--val < 0) val += Modulus;\n   \
    \     return *this;\n    }\n    inline ModInt operator--(int) noexcept {\n   \
    \     ModInt t = val;\n        if(--val < 0) val += Modulus;\n        return t;\n\
    \    }\n    inline ModInt operator-() const noexcept { return (Modulus - val)\
    \ % Modulus; }\n    inline ModInt inv(void) const { return inv(val); }\n    ModInt\
    \ pow(long long n) const {\n        assert(0 <= n);\n        ModInt x = *this,\
    \ r = 1;\n        while(n){\n            if(n & 1) r *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return r;\n    }\n    ModInt inv(const\
    \ long long n) const {\n        long long a = n, b = Modulus, u = 1, v = 0;\n\
    \        while(b){\n            long long t = a / b;\n            a -= t * b;\
    \ std::swap(a, b);\n            u -= t * v; std::swap(u, v);\n        }\n    \
    \    u %= Modulus;\n        if(u < 0) u += Modulus;\n        return u;\n    }\n\
    \    friend inline ModInt operator+(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return ModInt(lhs) += rhs; }\n    friend inline ModInt operator-(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) -= rhs; }\n    friend\
    \ inline ModInt operator*(const ModInt &lhs, const ModInt &rhs) noexcept { return\
    \ ModInt(lhs) *= rhs; }\n    friend inline ModInt operator/(const ModInt &lhs,\
    \ const ModInt &rhs) noexcept { return ModInt(lhs) /= rhs; }\n    friend inline\
    \ bool operator==(const ModInt &lhs, const ModInt &rhs) noexcept { return lhs.val\
    \ == rhs.val; }\n    friend inline bool operator!=(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept { return lhs.val != rhs.val; }\n    friend inline std::istream\
    \ &operator>>(std::istream &is, ModInt &x) noexcept {\n        is >> x.val;\n\
    \        x.normalize();\n        return is;\n    }\n    friend inline std::ostream\
    \ &operator<<(std::ostream &os, const ModInt &x) noexcept { return os << x.val;\
    \ }\n};\n#line 6 \"test/library_checker/data_structure/range_parallel_unionfind.test.cpp\"\
    \n\nusing namespace std;\n\nusing mint = ModInt<998244353>;\n\nint main(){\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n, q; cin >>\
    \ n >> q;\n    vector<mint> x(n);\n    for(int i = 0; i < n; ++i){\n        cin\
    \ >> x[i];\n    }\n\n    RangeParallelUnionFind uf(n);\n    mint ans = 0;\n  \
    \  while(q--){\n        int k, a, b; cin >> k >> a >> b;\n        uf.unite(k,\
    \ a, b, [&](int ra, int rb){\n            ans += x[ra] * x[rb];\n            x[ra]\
    \ += x[rb];\n        });\n        cout << ans << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_parallel_unionfind\"\
    \n#include <iostream>\n\n#include \"../../../lib/data_structure/range_parallel_union_find.hpp\"\
    \n#include \"../../../lib/math/modint.hpp\"\n\nusing namespace std;\n\nusing mint\
    \ = ModInt<998244353>;\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int n, q; cin >> n >> q;\n    vector<mint> x(n);\n    for(int i = 0; i <\
    \ n; ++i){\n        cin >> x[i];\n    }\n\n    RangeParallelUnionFind uf(n);\n\
    \    mint ans = 0;\n    while(q--){\n        int k, a, b; cin >> k >> a >> b;\n\
    \        uf.unite(k, a, b, [&](int ra, int rb){\n            ans += x[ra] * x[rb];\n\
    \            x[ra] += x[rb];\n        });\n        cout << ans << '\\n';\n   \
    \ }\n}\n"
  dependsOn:
  - lib/data_structure/range_parallel_union_find.hpp
  - lib/data_structure/union_find.hpp
  - lib/data_structure/segment_tree_func.hpp
  - lib/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/range_parallel_unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-11-03 21:58:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/range_parallel_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/range_parallel_unionfind.test.cpp
- /verify/test/library_checker/data_structure/range_parallel_unionfind.test.cpp.html
title: test/library_checker/data_structure/range_parallel_unionfind.test.cpp
---
