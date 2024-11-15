---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/weighted_union_find.hpp
    title: Weighted Union Find
  - icon: ':question:'
    path: lib/math/modint.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
  bundledCode: "#line 1 \"test/library_checker/data_structure/unionfind_with_potential_non_commutative_group.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/data_structure/weighted_union_find.hpp\"\
    \n\n/**\n * @brief Weighted Union Find\n * @docs docs/data_structure/weighted_union_find.md\n\
    \ */\n\n#line 10 \"lib/data_structure/weighted_union_find.hpp\"\n\ntemplate <typename\
    \ T>\nstruct WeightedUnionFind{\n    int V;\n    std::vector<int> par;\n    std::vector<T>\
    \ diff_weight;\n    T ex;\n\n    WeightedUnionFind(const int N, const T &e = 0)\
    \ : V(N), par(N), diff_weight(N), ex(e){\n        for(int i = 0; i < N; ++i){\n\
    \            par[i] = -1;\n            diff_weight[i] = e;\n        }\n    }\n\
    \n    int root(const int x){\n        assert(0 <= x && x < V);\n        if(par[x]\
    \ < 0){\n            return x;\n        }\n        int px = par[x];\n        int\
    \ rx = root(par[x]);\n        diff_weight[x] = diff_weight[x] + diff_weight[px];\n\
    \        return par[x] = rx;\n    }\n\n    T weight(const int x){\n        root(x);\n\
    \        return diff_weight[x];\n    }\n\n    T diff(const int x, const int y){\n\
    \        return weight(x) - weight(y);\n    }\n\n    void unite(const int x, const\
    \ int y, const T &w){\n        int tx = x, ty = y;\n        T tw = w;\n      \
    \  int rx = root(x), ry = root(y);\n        if(rx == ry) return;\n\n        if(par[rx]\
    \ < par[ry]){\n            std::swap(rx, ry);\n            std::swap(tx, ty);\n\
    \            tw = ex - tw;\n        }\n\n        par[ry] = par[rx] + par[ry];\n\
    \        par[rx] = ry;\n        diff_weight[rx] = ex - diff_weight[tx] + tw +\
    \ diff_weight[ty];\n    }\n\n    bool same(const int x, const int y){\n      \
    \  return root(x) == root(y);\n    }\n\n    int size(const int x){\n        return\
    \ -par[root(x)];\n    }\n};\n#line 2 \"lib/math/modint.hpp\"\n\n#line 5 \"lib/math/modint.hpp\"\
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
    \ }\n};\n#line 7 \"test/library_checker/data_structure/unionfind_with_potential_non_commutative_group.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nstruct Potential{\n    mint A[2][2];\n\
    };\nPotential operator+(Potential r, Potential l){\n    Potential res;\n    for(int\
    \ i = 0; i < 2; i++){\n        for(int j = 0; j < 2; j++){\n            for(int\
    \ k = 0; k < 2; k++){\n                res.A[i][k] += l.A[i][j] * r.A[j][k];\n\
    \            }\n        }\n    }\n    return res;\n}\nPotential operator-(Potential\
    \ r){\n    swap(r.A[0][0], r.A[1][1]);\n    r.A[0][1] = -r.A[0][1];\n    r.A[1][0]\
    \ = -r.A[1][0];\n    return r;\n}\nPotential operator-(Potential l, Potential\
    \ r){\n    return l + (-r);\n}\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, q; cin >> n >> q;\n    WeightedUnionFind<Potential>\
    \ uf(n, {{{1,0},{0,1}}});\n    while(q--){\n        int t; cin >> t;\n       \
    \ if(t == 0){\n            int u, v; cin >> u >> v;\n            Potential x;\n\
    \            for(int i = 0; i < 2; i++){\n                for(int j = 0; j < 2;\
    \ j++){\n                    cin >> x.A[i][j];\n                }\n          \
    \  }\n            if(uf.same(u, v)){\n                Potential y = uf.diff(u,\
    \ v);\n                int is_ok = 1;\n                for(int i = 0; i < 2; i++){\n\
    \                    for(int j = 0; j < 2; j++){\n                        if(x.A[i][j]\
    \ != y.A[i][j]){\n                            is_ok = 0;\n                   \
    \     }\n                    }\n                }\n                cout << is_ok\
    \ << \"\\n\";\n            } else{\n                uf.unite(u, v, x);\n     \
    \           cout << 1 << \"\\n\";\n            }\n        } else{\n          \
    \  int u, v; cin >> u >> v;\n            if(uf.same(u, v)){\n                Potential\
    \ x = uf.diff(u, v);\n                cout << x.A[0][0] << \" \" << x.A[0][1]\
    \ << \" \" << x.A[1][0] << \" \" << x.A[1][1] << \"\\n\";\n            } else{\n\
    \                cout << -1 << \"\\n\";\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/data_structure/weighted_union_find.hpp\"\
    \n#include \"../../../lib/math/modint.hpp\"\n\nusing mint = ModInt<998244353>;\n\
    \nstruct Potential{\n    mint A[2][2];\n};\nPotential operator+(Potential r, Potential\
    \ l){\n    Potential res;\n    for(int i = 0; i < 2; i++){\n        for(int j\
    \ = 0; j < 2; j++){\n            for(int k = 0; k < 2; k++){\n               \
    \ res.A[i][k] += l.A[i][j] * r.A[j][k];\n            }\n        }\n    }\n   \
    \ return res;\n}\nPotential operator-(Potential r){\n    swap(r.A[0][0], r.A[1][1]);\n\
    \    r.A[0][1] = -r.A[0][1];\n    r.A[1][0] = -r.A[1][0];\n    return r;\n}\n\
    Potential operator-(Potential l, Potential r){\n    return l + (-r);\n}\n\nint\
    \ main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int\
    \ n, q; cin >> n >> q;\n    WeightedUnionFind<Potential> uf(n, {{{1,0},{0,1}}});\n\
    \    while(q--){\n        int t; cin >> t;\n        if(t == 0){\n            int\
    \ u, v; cin >> u >> v;\n            Potential x;\n            for(int i = 0; i\
    \ < 2; i++){\n                for(int j = 0; j < 2; j++){\n                  \
    \  cin >> x.A[i][j];\n                }\n            }\n            if(uf.same(u,\
    \ v)){\n                Potential y = uf.diff(u, v);\n                int is_ok\
    \ = 1;\n                for(int i = 0; i < 2; i++){\n                    for(int\
    \ j = 0; j < 2; j++){\n                        if(x.A[i][j] != y.A[i][j]){\n \
    \                           is_ok = 0;\n                        }\n          \
    \          }\n                }\n                cout << is_ok << \"\\n\";\n \
    \           } else{\n                uf.unite(u, v, x);\n                cout\
    \ << 1 << \"\\n\";\n            }\n        } else{\n            int u, v; cin\
    \ >> u >> v;\n            if(uf.same(u, v)){\n                Potential x = uf.diff(u,\
    \ v);\n                cout << x.A[0][0] << \" \" << x.A[0][1] << \" \" << x.A[1][0]\
    \ << \" \" << x.A[1][1] << \"\\n\";\n            } else{\n                cout\
    \ << -1 << \"\\n\";\n            }\n        }\n    }\n}\n"
  dependsOn:
  - lib/data_structure/weighted_union_find.hpp
  - lib/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/unionfind_with_potential_non_commutative_group.test.cpp
  requiredBy: []
  timestamp: '2024-11-15 16:06:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/unionfind_with_potential_non_commutative_group.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/unionfind_with_potential_non_commutative_group.test.cpp
- /verify/test/library_checker/data_structure/unionfind_with_potential_non_commutative_group.test.cpp.html
title: test/library_checker/data_structure/unionfind_with_potential_non_commutative_group.test.cpp
---
