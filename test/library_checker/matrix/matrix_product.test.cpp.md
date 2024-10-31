---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/math/matrix.hpp
    title: Matrix
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/library_checker/matrix/matrix_product.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/math/modint.hpp\"\n\n#line 4 \"lib/math/modint.hpp\"\
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
    \ pow(long long n){\n        assert(0 <= n);\n        ModInt x = *this, r = 1;\n\
    \        while(n){\n            if(n & 1) r *= x;\n            x *= x;\n     \
    \       n >>= 1;\n        }\n        return r;\n    }\n    ModInt inv(const long\
    \ long n) const {\n        long long a = n, b = Modulus, u = 1, v = 0;\n     \
    \   while(b){\n            long long t = a / b;\n            a -= t * b; std::swap(a,\
    \ b);\n            u -= t * v; std::swap(u, v);\n        }\n        u %= Modulus;\n\
    \        if(u < 0) u += Modulus;\n        return u;\n    }\n    friend inline\
    \ ModInt operator+(const ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs)\
    \ += rhs; }\n    friend inline ModInt operator-(const ModInt &lhs, const ModInt\
    \ &rhs) noexcept { return ModInt(lhs) -= rhs; }\n    friend inline ModInt operator*(const\
    \ ModInt &lhs, const ModInt &rhs) noexcept { return ModInt(lhs) *= rhs; }\n  \
    \  friend inline ModInt operator/(const ModInt &lhs, const ModInt &rhs) noexcept\
    \ { return ModInt(lhs) /= rhs; }\n    friend inline bool operator==(const ModInt\
    \ &lhs, const ModInt &rhs) noexcept { return lhs.val == rhs.val; }\n    friend\
    \ inline bool operator!=(const ModInt &lhs, const ModInt &rhs) noexcept { return\
    \ lhs.val != rhs.val; }\n    friend inline std::istream &operator>>(std::istream\
    \ &is, ModInt &x) noexcept {\n        is >> x.val;\n        x.normalize();\n \
    \       return is;\n    }\n    friend inline std::ostream &operator<<(std::ostream\
    \ &os, const ModInt &x) noexcept { return os << x.val; }\n};\n#line 2 \"lib/math/matrix.hpp\"\
    \n\n/**\n * @brief Matrix\n * @docs docs/math/matrix.md\n */\n\ntemplate <typename\
    \ T>\nstruct Matrix{\n    int n, m;\n    vector<T> val;\n    Matrix(int _n, int\
    \ _m) : n(_n), m(_m), val(_n *_m){}\n    Matrix(const vector<vector<T>> &mat){\n\
    \        n = mat.size();\n        m = mat[0].size();\n        val.resize(n * m);\n\
    \        for(int i = 0; i < n; ++i){\n            for(int j = 0; j < m; ++j){\n\
    \                val[i * m + j] = mat[i][j];\n            }\n        }\n    }\n\
    \    static Matrix e(int _n){\n        Matrix res(_n, _n);\n        for(int i\
    \ = 0; i < _n; ++i){\n            res[i][i] = T{1};\n        }\n        return\
    \ res;\n    }\n    auto operator[](int i){ return val.begin() + i * m; }\n   \
    \ auto operator[](int i) const { return val.begin() + i * m; }\n    inline Matrix\
    \ &operator+=(const Matrix &rhs){\n        for(int i = 0; i < n * m; ++i){\n \
    \           val[i] += rhs[i];\n        }\n        return *this;\n    }\n    inline\
    \ Matrix &operator-=(const Matrix &rhs){\n        for(int i = 0; i < n * m; ++i){\n\
    \            val[i] -= rhs[i];\n        }\n        return *this;\n    }\n    inline\
    \ Matrix operator*(const Matrix &rhs){\n        assert(m == rhs.n);\n        const\
    \ int l = rhs.m;\n        Matrix res(n, l);\n        for(int i = 0; i < n; ++i){\n\
    \            for(int j = 0; j < m; ++j){\n                for(int k = 0; k < l;\
    \ ++k){\n                    res[i][k] += val[i * m + j] * rhs[j][k];\n      \
    \          }\n            }\n        }\n        return res;\n    }\n    inline\
    \ Matrix &operator*=(const Matrix &rhs){\n        return *this = *this * rhs;\n\
    \    }\n    friend inline Matrix operator+(const Matrix &lhs, const Matrix &rhs)\
    \ noexcept { return Matrix(lhs) += rhs; }\n    friend inline Matrix operator-(const\
    \ Matrix &lhs, const Matrix &rhs) noexcept { return Matrix(lhs) -= rhs; }\n  \
    \  friend inline bool operator==(const Matrix &lhs, const Matrix &rhs) noexcept\
    \ { return lhs.val == rhs.val; }\n    friend inline bool operator!=(const Matrix\
    \ &lhs, const Matrix &rhs) noexcept { return lhs.val != rhs.val; }\n    friend\
    \ inline ostream &operator<<(ostream &os, const Matrix &mat) noexcept {\n    \
    \    const int _n = mat.n;\n        const int _m = mat.m;\n        for(int i =\
    \ 0; i < _n; ++i){\n            for(int j = 0; j < _m; ++j){\n               \
    \ os << mat[i][j] << \" \\n\"[j == _m - 1];\n            }\n        }\n      \
    \  return os;\n    }\n    Matrix inv() const {\n        Matrix a = *this, b =\
    \ e(n);\n        for(int i = 0; i < n; ++i){\n            if(a[i][i] == 0){\n\
    \                for(int j = i + 1; j < n; ++j){\n                    if(a[j][i]\
    \ != 0){\n                        for(int k = i; k < n; ++k) swap(a[i][k], a[j][k]);\n\
    \                        for(int k = 0; k < n; ++k) swap(b[i][k], b[j][k]);\n\
    \                        break;\n                    }\n                }\n  \
    \          }\n            if(a[i][i] == 0) throw \"Inverse does not exist.\";\n\
    \            const T x = T{1} / a[i][i];\n            for(int k = i; k < n; ++k)\
    \ a[i][k] *= x;\n            for(int k = 0; k < n; ++k) b[i][k] *= x;\n      \
    \      for(int j = 0; j < n; ++j){\n                if(i != j){\n            \
    \        const T x = a[j][i];\n                    for(int k = i; k < n; ++k)\
    \ a[j][k] -= a[i][k] * x;\n                    for(int k = 0; k < n; ++k) b[j][k]\
    \ -= b[i][k] * x;\n                }\n            }\n        }\n        return\
    \ b;\n    }\n    Matrix pow(long long r) const {\n        if(r == 0) return e(n);\n\
    \        if(r < 0) return inv().pow(-r);\n        Matrix res = e(n), a = *this;\n\
    \        while(r > 0){\n            if(r & 1) res *= a;\n            a *= a;\n\
    \            r >>= 1;\n        }\n        return res;\n    }\n    Matrix pow2(string\
    \ &r) const {\n        if(r == \"0\") return e(n);\n        Matrix res = e(n),\
    \ a = *this;\n        int siz = r.size();\n        for(int i = siz - 1; i >= 0;\
    \ i--){\n            if(r[i] == '1') res *= a;\n            a *= a;\n        }\n\
    \        return res;\n    }\n    T det() const {\n        Matrix a = *this;\n\
    \        T res = 1;\n        for(int i = 0; i < n; ++i){\n            if(a[i][i]\
    \ == 0){\n                for(int j = i + 1; j < n; ++j){\n                  \
    \  if(a[j][i] != 0){\n                        for(int k = i; k < n; ++k){\n  \
    \                          swap(a[i][k], a[j][k]);\n                        }\n\
    \                        res = -res;\n                        break;\n       \
    \             }\n                }\n            }\n            if(a[i][i] == 0)\
    \ return 0;\n            res *= a[i][i];\n            const T x = T{1} / a[i][i];\n\
    \            for(int k = i; k < n; ++k){\n                a[i][k] *= x;\n    \
    \        }\n            for(int j = i + 1; j < n; ++j){\n                const\
    \ T x = a[j][i];\n                for(int k = i; k < n; ++k){\n              \
    \      a[j][k] -= a[i][k] * x;\n                }\n            }\n        }\n\
    \        return res;\n    }\n    Matrix transpose() const {\n        Matrix res(m,\
    \ n), a = *this;\n        for(int i = 0; i < n; ++i){\n            for(int j =\
    \ 0; j < m; ++j){\n                res[j][i] = a[i][j];\n            }\n     \
    \   }\n        return res;\n    }\n    Matrix gauss() const {\n        Matrix\
    \ a = *this;\n        int r = 0;\n        for(int i = 0; i < m; ++i){\n      \
    \      int pivot = -1;\n            for(int j = r; j < n; ++j){\n            \
    \    if(a[j][i] != 0){\n                    pivot = j;\n                    break;\n\
    \                }\n            }\n            if(pivot == -1) continue;\n   \
    \         for(int j = 0; j < m; ++j){\n                swap(a[pivot][j], a[r][j]);\n\
    \            }\n            const T s = a[r][i];\n            for(int j = i; j\
    \ < m; ++j){\n                a[r][j] /= s;\n            }\n            for(int\
    \ j = 0; j < n; ++j){\n                if(j == r) continue;\n                const\
    \ T s = a[j][i];\n                if(s == 0) continue;\n                for(int\
    \ k = i; k < m; ++k){\n                    a[j][k] -= a[r][k] * s;\n         \
    \       }\n            }\n            ++r;\n        }\n        return a;\n   \
    \ }\n    int rank(bool is_gaussed = false) const {\n        Matrix a = *this;\n\
    \        if(!is_gaussed){\n            return (n >= m ? a : a.transpose()).gauss().rank(true);\n\
    \        }\n        int r = 0;\n        for(int i = 0; i < n; ++i){\n        \
    \    while(r < m && a[i][r] == 0) ++r;\n            if(r == m){\n            \
    \    return i;\n            }\n            ++r;\n        }\n        return n;\n\
    \    }\n    // Rotate 90 degrees clockwise\n    Matrix rotate() const {\n    \
    \    Matrix res(m, n), a = *this;\n        for(int i = 0; i < m; ++i){\n     \
    \       for(int j = 0; j < n; ++j){\n                res[i][j] = a[n - j - 1][i];\n\
    \            }\n        }\n        return res;\n    }\n};\n#line 7 \"test/library_checker/matrix/matrix_product.test.cpp\"\
    \n\nusing mint = ModInt<998244353>;\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, m, k; cin >> n >> m >> k;\n    Matrix<mint>\
    \ a(n, m), b(m, k);\n    int scan;\n    for(int i = 0; i < n; i++){\n        for(int\
    \ j = 0; j < m; j++){\n            cin >> a[i][j];\n        }\n    }\n    for(int\
    \ i = 0; i < m; i++){\n        for(int j = 0; j < k; j++){\n            cin >>\
    \ b[i][j];\n        }\n    }\n    a *= b;\n    cout << a;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/modint.hpp\"\
    \n#include \"../../../lib/math/matrix.hpp\"\n\nusing mint = ModInt<998244353>;\n\
    \nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n   \
    \ int n, m, k; cin >> n >> m >> k;\n    Matrix<mint> a(n, m), b(m, k);\n    int\
    \ scan;\n    for(int i = 0; i < n; i++){\n        for(int j = 0; j < m; j++){\n\
    \            cin >> a[i][j];\n        }\n    }\n    for(int i = 0; i < m; i++){\n\
    \        for(int j = 0; j < k; j++){\n            cin >> b[i][j];\n        }\n\
    \    }\n    a *= b;\n    cout << a;\n}"
  dependsOn:
  - lib/math/modint.hpp
  - lib/math/matrix.hpp
  isVerificationFile: true
  path: test/library_checker/matrix/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2024-10-31 17:18:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/matrix/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/matrix/matrix_product.test.cpp
- /verify/test/library_checker/matrix/matrix_product.test.cpp.html
title: test/library_checker/matrix/matrix_product.test.cpp
---
