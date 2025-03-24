---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/segment_tree_func.hpp
    title: lib/data_structure/segment_tree_func.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/modint.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: lib/others/compression.hpp
    title: "Compression (\u5EA7\u6A19\u5727\u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite_large_array
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite_large_array
  bundledCode: "#line 1 \"test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
    \n\n#include <iostream>\n#include <vector>\n#include <tuple>\n\n#line 2 \"lib/data_structure/segment_tree_func.hpp\"\
    \n\n#line 4 \"lib/data_structure/segment_tree_func.hpp\"\n#include <cassert>\n\
    \ntemplate <typename T, T (*op)(T, T), T(*e)()>\nstruct SegTree{\n    int _n,\
    \ n;\n    std::vector<T> dat;\n\n    SegTree(int _n) : _n(_n) {\n        int x\
    \ = 1;\n        while(_n > x){\n            x *= 2;\n        }\n        n = x;\n\
    \        dat.resize(n * 2);\n        for(int i = 0; i < n * 2; ++i){\n       \
    \     dat[i] = e();\n        }\n    }\n    SegTree(std::vector<T> &v) : _n((int)\
    \ v.size()) {\n        int x = 1;\n        while((int) v.size() > x){\n      \
    \      x *= 2;\n        }\n        n = x;\n        dat.resize(n * 2);\n      \
    \  for(int i = 0; i < n; ++i){\n            set(i, (i < (int) v.size() ? v[i]\
    \ : e()));\n        }\n        build();\n    }\n\nprivate:\n    void set(int i,\
    \ const T &x){ dat[i + n] = x; }\n\n    void build(){\n        for(int k = n -\
    \ 1; k >= 1; k--) dat[k] = op(dat[k * 2], dat[k * 2 + 1]);\n    }\n\npublic:\n\
    \    T get(int i) const {\n        assert(0 <= i && i < n);\n        return dat[i\
    \ + n];\n    }\n\n    void update(int i, const T &x){\n        assert(0 <= i &&\
    \ i < n);\n        i += n;\n        dat[i] = x;\n        while(i > 0){\n     \
    \       i >>= 1;  // parent\n            dat[i] = op(dat[i * 2], dat[i * 2 + 1]);\n\
    \        }\n    }\n\n    T query(int a, int b){\n        assert(0 <= a && a <=\
    \ b && b <= n);\n        T vl = e();\n        T vr = e();\n        int l = a +\
    \ n;\n        int r = b + n;\n        while(l < r){\n            if(l & 1) vl\
    \ = op(vl, dat[l++]);\n            if(r & 1) vr = op(dat[--r], vr);\n        \
    \    l >>= 1;\n            r >>= 1;\n        }\n        return op(vl, vr);\n \
    \   }\n\n    template <class F>\n    int max_right(int l, F f) const {\n     \
    \   assert(0 <= l && l <= _n);\n        assert(f(e()));\n        if(l == _n) return\
    \ _n;\n        l += n;\n        T sm = e();\n        do{\n            while(l\
    \ % 2 == 0) l >>= 1;\n            if(!f(op(sm, dat[l]))){\n                while(l\
    \ < n){\n                    l = (2 * l);\n                    if(f(op(sm, dat[l]))){\n\
    \                        sm = op(sm, dat[l]);\n                        l++;\n\
    \                    }\n                }\n                return l - n;\n   \
    \         }\n            sm = op(sm, dat[l]);\n            l++;\n        }while((l\
    \ & -l) != l);\n        return _n;\n    }\n\n    template <class F>\n    int min_left(int\
    \ r, F f) const {\n        assert(0 <= r && r <= _n);\n        assert(f(e()));\n\
    \        if(r == 0) return 0;\n        r += n;\n        T sm = e();\n        do{\n\
    \            r--;\n            while(r > 1 && (r % 2)) r >>= 1;\n            if(!f(op(dat[r],\
    \ sm))){\n                while(r < n){\n                    r = (2 * r + 1);\n\
    \                    if(f(op(dat[r], sm))){\n                        sm = op(dat[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - n;\n            }\n            sm = op(dat[r],\
    \ sm);\n        }while((r & -r) != r);\n        return 0;\n    }\n};\n#line 2\
    \ \"lib/math/modint.hpp\"\n\n#line 5 \"lib/math/modint.hpp\"\n\n/**\n * @brief\
    \ ModInt\n * @docs docs/math/modint.md\n */\n\ntemplate <long long Modulus>\n\
    struct ModInt{\n    long long val;\n    static constexpr int mod() { return Modulus;\
    \ }\n    constexpr ModInt(const long long _val = 0) noexcept : val(_val) {\n \
    \       normalize();\n    }\n    void normalize(){\n        val = (val % Modulus\
    \ + Modulus) % Modulus;\n    }\n    inline ModInt &operator+=(const ModInt &rhs)\
    \ noexcept {\n        if(val += rhs.val, val >= Modulus) val -= Modulus;\n   \
    \     return *this;\n    }\n    inline ModInt &operator-=(const ModInt &rhs) noexcept\
    \ {\n        if(val -= rhs.val, val < 0) val += Modulus;\n        return *this;\n\
    \    }\n    inline ModInt &operator*=(const ModInt &rhs) noexcept {\n        val\
    \ = val * rhs.val % Modulus;\n        return *this;\n    }\n    inline ModInt\
    \ &operator/=(const ModInt &rhs) noexcept {\n        val = val * inv(rhs.val).val\
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
    \ }\n};\n#line 2 \"lib/others/compression.hpp\"\n\n/**\n * @brief Compression\
    \ (\u5EA7\u6A19\u5727\u7E2E)\n * @docs docs/others/compression.md\n */\n\n#line\
    \ 9 \"lib/others/compression.hpp\"\n#include <algorithm>\n\ntemplate <typename\
    \ T>\nstruct compress{\n    std::vector<T> sorted;\n    std::vector<int> compressed;\n\
    \n    compress(const std::vector<T> &vec){\n        int n = vec.size();\n    \
    \    compressed.resize(n);\n        for(T x : vec){\n            sorted.emplace_back(x);\n\
    \        }\n        std::sort(sorted.begin(), sorted.end());\n        sorted.erase(std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n        for(int i = 0; i < n; ++i){\n       \
    \     compressed[i] = std::lower_bound(sorted.begin(), sorted.end(), vec[i]) -\
    \ sorted.begin();\n        }\n    }\n\n    int get(const T &x) const{\n      \
    \  return std::lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();\n\
    \    }\n\n    T inv(const int x) const{\n        return sorted[x];\n    }\n\n\
    \    size_t size() const{\n        return sorted.size();\n    }\n\n    std::vector<int>\
    \ getCompressed() const{\n        return compressed;\n    }\n};\n#line 10 \"test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp\"\
    \n\nusing namespace std;\n\nusing mint = ModInt<998244353>;\nusing F = pair<mint,\
    \ mint>;\n\nF op(F a, F b){\n    return {a.first * b.first, a.second * b.first\
    \ + b.second};\n}\n\nF e(){\n    return {1, 0};\n}\n\nint main(){\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int n, q; cin >> n >> q;\n    using T\
    \ = tuple<int, int, int, int>;\n    vector<T> query(q);\n    vector<int> c;\n\
    \    for(int i = 0; i < q; i++){\n        int t, x, y, z; cin >> t >> x >> y >>\
    \ z;\n        query[i] = {t, x, y, z};\n        if(t == 0){\n            c.push_back(x);\n\
    \        }else{\n            c.push_back(x);\n            c.push_back(y);\n  \
    \      }\n    }\n    compress<int> comp(c);\n    SegTree<F, op, e> seg(comp.size());\n\
    \    for(int i = 0; i < q; i++){\n        auto [t, x, y, z] = query[i];\n    \
    \    if(t == 0){\n            seg.update(comp.get(x), {y, z});\n        }else{\n\
    \            F res = seg.query(comp.get(x), comp.get(y));\n            cout <<\
    \ res.first * z + res.second << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite_large_array\"\
    \n\n#include <iostream>\n#include <vector>\n#include <tuple>\n\n#include \"../../../lib/data_structure/segment_tree_func.hpp\"\
    \n#include \"../../../lib/math/modint.hpp\"\n#include \"../../../lib/others/compression.hpp\"\
    \n\nusing namespace std;\n\nusing mint = ModInt<998244353>;\nusing F = pair<mint,\
    \ mint>;\n\nF op(F a, F b){\n    return {a.first * b.first, a.second * b.first\
    \ + b.second};\n}\n\nF e(){\n    return {1, 0};\n}\n\nint main(){\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int n, q; cin >> n >> q;\n    using T\
    \ = tuple<int, int, int, int>;\n    vector<T> query(q);\n    vector<int> c;\n\
    \    for(int i = 0; i < q; i++){\n        int t, x, y, z; cin >> t >> x >> y >>\
    \ z;\n        query[i] = {t, x, y, z};\n        if(t == 0){\n            c.push_back(x);\n\
    \        }else{\n            c.push_back(x);\n            c.push_back(y);\n  \
    \      }\n    }\n    compress<int> comp(c);\n    SegTree<F, op, e> seg(comp.size());\n\
    \    for(int i = 0; i < q; i++){\n        auto [t, x, y, z] = query[i];\n    \
    \    if(t == 0){\n            seg.update(comp.get(x), {y, z});\n        }else{\n\
    \            F res = seg.query(comp.get(x), comp.get(y));\n            cout <<\
    \ res.first * z + res.second << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - lib/data_structure/segment_tree_func.hpp
  - lib/math/modint.hpp
  - lib/others/compression.hpp
  isVerificationFile: true
  path: test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
  requiredBy: []
  timestamp: '2025-01-09 22:07:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
- /verify/test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp.html
title: test/library_checker/data_structure/point_set_range_composite_large_array.test.cpp
---
