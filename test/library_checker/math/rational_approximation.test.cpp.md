---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/math/fraction.hpp
    title: Fraction
  - icon: ':heavy_check_mark:'
    path: lib/math/stern_brocot_tree.hpp
    title: lib/math/stern_brocot_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rational_approximation
    links:
    - https://judge.yosupo.jp/problem/rational_approximation
  bundledCode: "#line 1 \"test/library_checker/math/rational_approximation.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rational_approximation\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lib/math/stern_brocot_tree.hpp\"\
    \n\n#line 2 \"lib/math/fraction.hpp\"\n\n/**\n * @brief Fraction\n * @docs docs/math/fraction.md\n\
    \ */\n\ntemplate <typename T>\nstruct fraction{\n    T p, q; // long long or BigInt\n\
    \    fraction(T P = 0, T Q = 1) : p(P), q(Q){\n        normalize();\n    }\n \
    \   void normalize(){\n        T g = __gcd(p, q);\n        p /= g, q /= g;\n \
    \       if(q < 0) p *= -1, q *= -1;\n    }\n    inline bool operator==(const fraction\
    \ &other) const {\n        return p * other.q == other.p * q;\n    }\n    inline\
    \ bool operator!=(const fraction &other) const {\n        return p * other.q !=\
    \ other.p * q;\n    }\n    inline bool operator<(const fraction &other) const\
    \ {\n        return p * other.q < other.p * q;\n    }\n    inline bool operator<=(const\
    \ fraction &other) const {\n        return p * other.q <= other.p * q;\n    }\n\
    \    inline bool operator>(const fraction &other) const {\n        return p *\
    \ other.q > other.p * q;\n    }\n    inline bool operator>=(const fraction &other)\
    \ const {\n        return p * other.q >= other.p * q;\n    }\n    inline fraction\
    \ operator+(const fraction &other) const { return fraction(p * other.q + q * other.p,\
    \ q * other.q); }\n    inline fraction operator-(const fraction &other) const\
    \ { return fraction(p * other.q - q * other.p, q * other.q); }\n    inline fraction\
    \ operator*(const fraction &other) const { return fraction(p * other.p, q * other.q);\
    \ }\n    inline fraction operator/(const fraction &other) const { return fraction(p\
    \ * other.q, q * other.p); }\n    inline fraction &operator+=(const fraction &rhs)\
    \ noexcept {\n        *this = *this + rhs;\n        return *this;\n    }\n   \
    \ inline fraction &operator-=(const fraction &rhs) noexcept {\n        *this =\
    \ *this - rhs;\n        return *this;\n    }\n    inline fraction &operator*=(const\
    \ fraction &rhs) noexcept {\n        *this = *this * rhs;\n        return *this;\n\
    \    }\n    inline fraction &operator/=(const fraction &rhs) noexcept {\n    \
    \    *this = *this / rhs;\n        return *this;\n    }\n    friend inline istream\
    \ &operator>>(istream &is, fraction &x) noexcept {\n        is >> x.p;\n     \
    \   x.q = 1;\n        return is;\n    }\n    friend inline ostream &operator<<(ostream\
    \ &os, const fraction &x) noexcept { return os << x.p << \"/\" << x.q; }\n};\n\
    #line 4 \"lib/math/stern_brocot_tree.hpp\"\n\ntemplate <typename T>\npair<fraction<T>,\
    \ fraction<T>> SternBrocot(T n, fraction<T> p){\n    fraction<T> a(0, 1), b(1,\
    \ 0);\n    fraction<T> x(0, 1), y(1, 0);\n    bool ok_left = true, ok_right =\
    \ true;\n    while(ok_left && ok_right){\n        fraction<T> m(a.p + b.p, a.q\
    \ + b.q);\n        if(p < m){\n            T ok = 0, ng = n;\n            while(ng\
    \ - ok > 1){\n                T mid = (ok + ng) / 2;\n                fraction<T>\
    \ m2(a.p * mid + b.p, a.q * mid + b.q);\n                if(p < m2 && m2.p <=\
    \ n && m2.q <= n){\n                    ok = mid;\n                    m = m2;\n\
    \                } else{\n                    ng = mid;\n                }\n \
    \           }\n            b = m;\n            if(m.p <= n && m.q <= n){\n   \
    \             y = m;\n            } else{\n                ok_left = false;\n\
    \            }\n        } else{\n            T ok = 0, ng = n;\n            while(ng\
    \ - ok > 1){\n                T mid = (ok + ng) / 2;\n                fraction<T>\
    \ m2(a.p + b.p * mid, a.q + b.q * mid);\n                if(p >= m2 && m2.p <=\
    \ n && m2.q <= n){\n                    ok = mid;\n                    m = m2;\n\
    \                } else{\n                    ng = mid;\n                }\n \
    \           }\n            a = m;\n            if(m.p <= n && m.q <= n){\n   \
    \             x = m;\n            } else{\n                ok_right = false;\n\
    \            }\n        }\n    }\n    return make_pair(x, y);\n}\n#line 6 \"test/library_checker/math/rational_approximation.test.cpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int T; cin >> T;\n    while(T--){\n        long long n, x, y; cin >> n >>\
    \ x >> y;\n        fraction<long long> f(x, y);\n        auto [l, r] = SternBrocot(n,\
    \ f);\n        if(f == l) r = l;\n        cout << l.p << \" \" << l.q << \" \"\
    \ << r.p << \" \" << r.q << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rational_approximation\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/stern_brocot_tree.hpp\"\
    \n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int T; cin >> T;\n    while(T--){\n        long long n, x, y; cin >> n >>\
    \ x >> y;\n        fraction<long long> f(x, y);\n        auto [l, r] = SternBrocot(n,\
    \ f);\n        if(f == l) r = l;\n        cout << l.p << \" \" << l.q << \" \"\
    \ << r.p << \" \" << r.q << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/math/stern_brocot_tree.hpp
  - lib/math/fraction.hpp
  isVerificationFile: true
  path: test/library_checker/math/rational_approximation.test.cpp
  requiredBy: []
  timestamp: '2024-03-20 02:40:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/math/rational_approximation.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/rational_approximation.test.cpp
- /verify/test/library_checker/math/rational_approximation.test.cpp.html
title: test/library_checker/math/rational_approximation.test.cpp
---
