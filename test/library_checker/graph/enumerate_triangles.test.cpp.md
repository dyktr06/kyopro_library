---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/enumerate_triangles.hpp
    title: Enumerate Triangles
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_triangles
    links:
    - https://judge.yosupo.jp/problem/enumerate_triangles
  bundledCode: "#line 1 \"test/library_checker/graph/enumerate_triangles.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/graph/enumerate_triangles.hpp\"\
    \n\n/**\n * @brief Enumerate Triangles\n * @see https://www.slideshare.net/slideshow/trianguler/38443802\n\
    \ */\n\nvector<array<int, 3>> enumerateTriangles(vector<vector<int>> &G){\n  \
    \  int n = G.size();\n    vector<vector<int>> DAG(n);\n    for(int i = 0; i <\
    \ n; i++){\n        for(auto &j : G[i]){\n            pair<int, int> p = {(int)\
    \ G[i].size(), i}, q = {(int) G[j].size(), j};\n            if(p < q){\n     \
    \           DAG[i].push_back(j);\n            }\n        }\n    }\n\n    vector<array<int,\
    \ 3>> res;\n    vector<int> edge(n);\n    for(int i = 0; i < n; i++){\n      \
    \  for(auto j : DAG[i]){\n            for(auto k : DAG[i]){\n                edge[k]++;\n\
    \            }\n            for(auto k : DAG[j]){\n                if(edge[k]){\n\
    \                    res.push_back({i, j, k});\n                }\n          \
    \  }\n            for(auto k : DAG[i]){\n                edge[k]--;\n        \
    \    }\n        }\n    }\n    return res;\n}\n#line 2 \"lib/math/modint.hpp\"\n\
    \n#line 5 \"lib/math/modint.hpp\"\n\n/**\n * @brief ModInt\n * @docs docs/math/modint.md\n\
    \ */\n\ntemplate <long long Modulus>\nstruct ModInt{\n    long long val;\n   \
    \ static constexpr int mod() { return Modulus; }\n    constexpr ModInt(const long\
    \ long _val = 0) noexcept : val(_val) {\n        normalize();\n    }\n    void\
    \ normalize(){\n        val = (val % Modulus + Modulus) % Modulus;\n    }\n  \
    \  inline ModInt &operator+=(const ModInt &rhs) noexcept {\n        if(val +=\
    \ rhs.val, val >= Modulus) val -= Modulus;\n        return *this;\n    }\n   \
    \ inline ModInt &operator-=(const ModInt &rhs) noexcept {\n        if(val -= rhs.val,\
    \ val < 0) val += Modulus;\n        return *this;\n    }\n    inline ModInt &operator*=(const\
    \ ModInt &rhs) noexcept {\n        val = val * rhs.val % Modulus;\n        return\
    \ *this;\n    }\n    inline ModInt &operator/=(const ModInt &rhs) noexcept {\n\
    \        val = val * inv(rhs.val).val % Modulus;\n        return *this;\n    }\n\
    \    inline ModInt &operator++() noexcept {\n        if(++val >= Modulus) val\
    \ -= Modulus;\n        return *this;\n    }\n    inline ModInt operator++(int)\
    \ noexcept {\n        ModInt t = val;\n        if(++val >= Modulus) val -= Modulus;\n\
    \        return t;\n    }\n    inline ModInt &operator--() noexcept {\n      \
    \  if(--val < 0) val += Modulus;\n        return *this;\n    }\n    inline ModInt\
    \ operator--(int) noexcept {\n        ModInt t = val;\n        if(--val < 0) val\
    \ += Modulus;\n        return t;\n    }\n    inline ModInt operator-() const noexcept\
    \ { return (Modulus - val) % Modulus; }\n    inline ModInt inv(void) const { return\
    \ inv(val); }\n    ModInt pow(long long n) const {\n        assert(0 <= n);\n\
    \        ModInt x = *this, r = 1;\n        while(n){\n            if(n & 1) r\
    \ *= x;\n            x *= x;\n            n >>= 1;\n        }\n        return\
    \ r;\n    }\n    ModInt inv(const long long n) const {\n        long long a =\
    \ n, b = Modulus, u = 1, v = 0;\n        while(b){\n            long long t =\
    \ a / b;\n            a -= t * b; std::swap(a, b);\n            u -= t * v; std::swap(u,\
    \ v);\n        }\n        u %= Modulus;\n        if(u < 0) u += Modulus;\n   \
    \     return u;\n    }\n    friend inline ModInt operator+(const ModInt &lhs,\
    \ const ModInt &rhs) noexcept { return ModInt(lhs) += rhs; }\n    friend inline\
    \ ModInt operator-(const ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs)\
    \ -= rhs; }\n    friend inline ModInt operator*(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept { return ModInt(lhs) *= rhs; }\n    friend inline ModInt operator/(const\
    \ ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) /= rhs; }\n  \
    \  friend inline bool operator==(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return lhs.val == rhs.val; }\n    friend inline bool operator!=(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return lhs.val != rhs.val; }\n    friend\
    \ inline std::istream &operator>>(std::istream &is, ModInt &x) noexcept {\n  \
    \      is >> x.val;\n        x.normalize();\n        return is;\n    }\n    friend\
    \ inline std::ostream &operator<<(std::ostream &os, const ModInt &x) noexcept\
    \ { return os << x.val; }\n};\n#line 7 \"test/library_checker/graph/enumerate_triangles.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, m; cin >> n >> m;\n    vector<mint> x(n);\n\
    \    for(int i = 0; i < n; i++){\n        cin >> x[i];\n    }\n    vector<vector<int>>\
    \ G(n);\n    for(int i = 0; i < m; i++) {\n        int u, v; cin >> u >> v;\n\
    \        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n    mint ans\
    \ = 0;\n    for(auto &s : enumerateTriangles(G)){\n        mint mul = 1;\n   \
    \     for(auto &i : s){\n            mul *= x[i];\n        }\n        ans += mul;\n\
    \    }\n    cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/graph/enumerate_triangles.hpp\"\
    \n#include \"../../../lib/math/modint.hpp\"\n\nusing mint = ModInt<998244353>;\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n  \
    \  int n, m; cin >> n >> m;\n    vector<mint> x(n);\n    for(int i = 0; i < n;\
    \ i++){\n        cin >> x[i];\n    }\n    vector<vector<int>> G(n);\n    for(int\
    \ i = 0; i < m; i++) {\n        int u, v; cin >> u >> v;\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n\n    mint ans = 0;\n    for(auto &s : enumerateTriangles(G)){\n\
    \        mint mul = 1;\n        for(auto &i : s){\n            mul *= x[i];\n\
    \        }\n        ans += mul;\n    }\n    cout << ans << '\\n';\n}\n"
  dependsOn:
  - lib/graph/enumerate_triangles.hpp
  - lib/math/modint.hpp
  isVerificationFile: true
  path: test/library_checker/graph/enumerate_triangles.test.cpp
  requiredBy: []
  timestamp: '2024-11-03 21:58:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/graph/enumerate_triangles.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/enumerate_triangles.test.cpp
- /verify/test/library_checker/graph/enumerate_triangles.test.cpp.html
title: test/library_checker/graph/enumerate_triangles.test.cpp
---
