---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/data_structure/lazy_segment_tree.hpp
    title: lib/data_structure/lazy_segment_tree.hpp
  - icon: ':x:'
    path: lib/math/modint.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/library_checker/data_structure/range_affine_point_get.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/modint.hpp\"\
    \n\n/**\n * @brief ModInt\n * @docs docs/math/modint.md\n */\n\ntemplate <long\
    \ long Modulus>\nstruct ModInt{\n    long long val;\n    constexpr ModInt(const\
    \ long long _val = 0) noexcept : val(_val) {\n        normalize();\n    }\n  \
    \  void normalize(){\n        val = (val % Modulus + Modulus) % Modulus;\n   \
    \ }\n    inline ModInt &operator+=(const ModInt &rhs) noexcept {\n        if(val\
    \ += rhs.val, val >= Modulus) val -= Modulus;\n        return *this;\n    }\n\
    \    inline ModInt &operator-=(const ModInt &rhs) noexcept {\n        if(val -=\
    \ rhs.val, val < 0) val += Modulus;\n        return *this;\n    }\n    inline\
    \ ModInt &operator*=(const ModInt &rhs) noexcept {\n        val = val * rhs.val\
    \ % Modulus;\n        return *this;\n    }\n    inline ModInt &operator/=(const\
    \ ModInt &rhs) noexcept {\n        val = val * inv(rhs.val).val % Modulus;\n \
    \       return *this;\n    }\n    inline ModInt &operator++() noexcept {\n   \
    \     if(++val >= Modulus) val -= Modulus;\n        return *this;\n    }\n   \
    \ inline ModInt operator++(int) noexcept {\n        ModInt t = val;\n        if(++val\
    \ >= Modulus) val -= Modulus;\n        return t;\n    }\n    inline ModInt &operator--()\
    \ noexcept {\n        if(--val < 0) val += Modulus;\n        return *this;\n \
    \   }\n    inline ModInt operator--(int) noexcept {\n        ModInt t = val;\n\
    \        if(--val < 0) val += Modulus;\n        return t;\n    }\n    inline ModInt\
    \ operator-() const noexcept { return (Modulus - val) % Modulus; }\n    inline\
    \ ModInt inv(void) const { return inv(val); }\n    ModInt pow(long long n){\n\
    \        assert(0 <= n);\n        ModInt x = *this, r = 1;\n        while(n){\n\
    \            if(n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n  \
    \      }\n        return r;\n    }\n    ModInt inv(const long long n) const {\n\
    \        long long a = n, b = Modulus, u = 1, v = 0;\n        while(b){\n    \
    \        long long t = a / b;\n            a -= t * b; swap(a, b);\n         \
    \   u -= t * v; swap(u, v);\n        }\n        u %= Modulus;\n        if(u <\
    \ 0) u += Modulus;\n        return u;\n    }\n    friend inline ModInt operator+(const\
    \ ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) += rhs; }\n  \
    \  friend inline ModInt operator-(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return ModInt(lhs) -= rhs; }\n    friend inline ModInt operator*(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) *= rhs; }\n    friend\
    \ inline ModInt operator/(const ModInt &lhs, const ModInt &rhs) noexcept { return\
    \ ModInt(lhs) /= rhs; }\n    friend inline bool operator==(const ModInt &lhs,\
    \ const ModInt &rhs) noexcept { return lhs.val == rhs.val; }\n    friend inline\
    \ bool operator!=(const ModInt &lhs, const ModInt &rhs) noexcept { return lhs.val\
    \ != rhs.val; }\n    friend inline istream &operator>>(istream &is, ModInt &x)\
    \ noexcept {\n        is >> x.val;\n        x.normalize();\n        return is;\n\
    \    }\n    friend inline ostream &operator<<(ostream &os, const ModInt &x) noexcept\
    \ { return os << x.val; }\n};\n#line 2 \"lib/data_structure/lazy_segment_tree.hpp\"\
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
    \        } while((r & -r) != r);\n        return 0;\n    }\n};\n#line 7 \"test/library_checker/data_structure/range_affine_point_get.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nstruct S{\n    mint a;\n    int size;\n\
    };\n\nstruct F{\n    mint a, b;\n};\n\nS op(S l, S r){ return S{l.a + r.a, l.size\
    \ + r.size}; }\n\nS e(){ return S{0, 0}; }\n\nS mapping(F l, S r){ return S{r.a\
    \ * l.a + r.size * l.b, r.size}; }\n\nF composition(F l, F r){ return F{r.a *\
    \ l.a, r.b * l.a + l.b}; }\n\nF id(){ return F{1, 0}; }\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, q; cin >> n >> q;\n    vector<S> a(n);\n\
    \    for(int i = 0; i < n; i++){\n        int x; cin >> x;\n        a[i] = {x,\
    \ 1};\n    }\n    LazySegTree<S, op, e, F, mapping, composition, id> seg(a);\n\
    \    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n            int\
    \ l, r, b, c; cin >> l >> r >> b >> c;\n            seg.apply(l, r, F{b, c});\n\
    \        } else{\n            int i; cin >> i;\n            cout << seg.get(i).a\
    \ << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/modint.hpp\"\
    \n#include \"../../../lib/data_structure/lazy_segment_tree.hpp\"\n\nusing mint\
    \ = ModInt<998244353>;\n\nstruct S{\n    mint a;\n    int size;\n};\n\nstruct\
    \ F{\n    mint a, b;\n};\n\nS op(S l, S r){ return S{l.a + r.a, l.size + r.size};\
    \ }\n\nS e(){ return S{0, 0}; }\n\nS mapping(F l, S r){ return S{r.a * l.a + r.size\
    \ * l.b, r.size}; }\n\nF composition(F l, F r){ return F{r.a * l.a, r.b * l.a\
    \ + l.b}; }\n\nF id(){ return F{1, 0}; }\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, q; cin >> n >> q;\n    vector<S> a(n);\n\
    \    for(int i = 0; i < n; i++){\n        int x; cin >> x;\n        a[i] = {x,\
    \ 1};\n    }\n    LazySegTree<S, op, e, F, mapping, composition, id> seg(a);\n\
    \    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n            int\
    \ l, r, b, c; cin >> l >> r >> b >> c;\n            seg.apply(l, r, F{b, c});\n\
    \        } else{\n            int i; cin >> i;\n            cout << seg.get(i).a\
    \ << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - lib/math/modint.hpp
  - lib/data_structure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/range_affine_point_get.test.cpp
  requiredBy: []
  timestamp: '2024-05-04 18:06:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/data_structure/range_affine_point_get.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/range_affine_point_get.test.cpp
- /verify/test/library_checker/data_structure/range_affine_point_get.test.cpp.html
title: test/library_checker/data_structure/range_affine_point_get.test.cpp
---
