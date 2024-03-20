---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/inverse_matrix.test.cpp
    title: test/library_checker/matrix/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_det.test.cpp
    title: test/library_checker/matrix/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_product.test.cpp
    title: test/library_checker/matrix/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_rank.test.cpp
    title: test/library_checker/matrix/matrix_rank.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/pow_of_matrix.test.cpp
    title: test/library_checker/matrix/pow_of_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/matrix.md
    document_title: Matrix
    links: []
  bundledCode: "#line 2 \"lib/math/matrix.hpp\"\n\n/**\n * @brief Matrix\n * @docs\
    \ docs/math/matrix.md\n */\n\ntemplate <typename T>\nstruct Matrix{\n    int n,\
    \ m;\n    vector<T> val;\n    Matrix(int _n, int _m): n(_n), m(_m), val(_n * _m){}\n\
    \    Matrix(const vector<vector<T>>& mat){\n        n = mat.size();\n        m\
    \ = mat[0].size();\n        val.resize(n * m);\n        for(int i = 0; i < n;\
    \ ++i){\n            for(int j = 0; j < m; ++j){\n                val[i * m +\
    \ j] = mat[i][j];\n            }\n        }\n    }\n    static Matrix e(int _n){\n\
    \        Matrix res(_n, _n);\n        for(int i = 0; i < _n; ++i){\n         \
    \   res[i][i] = T{1};\n        }\n        return res;\n    }\n    auto operator[](int\
    \ i){ return val.begin() + i * m; }\n    auto operator[](int i) const { return\
    \ val.begin() + i * m; }\n    inline Matrix& operator+=(const Matrix &rhs){\n\
    \        for(int i = 0; i < n * m; ++i){\n            val[i] += rhs[i];\n    \
    \    }\n        return *this;\n    }\n    inline Matrix& operator-=(const Matrix\
    \ &rhs){\n        for(int i = 0; i < n * m; ++i){\n            val[i] -= rhs[i];\n\
    \        }\n        return *this;\n    }\n    inline Matrix operator*(const Matrix\
    \ &rhs){\n        assert(m == rhs.n);\n        const int l = rhs.m;\n        Matrix\
    \ res(n, l);\n        for(int i = 0; i < n; ++i){\n            for(int j = 0;\
    \ j < m; ++j){\n                for(int k = 0; k < l; ++k){\n                \
    \    res[i][k] += val[i * m + j] * rhs[j][k];\n                }\n           \
    \ }\n        }\n        return res;\n    }\n    inline Matrix& operator*=(const\
    \ Matrix &rhs){\n        return *this = *this * rhs;\n    }\n    friend inline\
    \ Matrix operator+(const Matrix& lhs, const Matrix& rhs) noexcept { return Matrix(lhs)\
    \ += rhs; }\n    friend inline Matrix operator-(const Matrix& lhs, const Matrix&\
    \ rhs) noexcept { return Matrix(lhs) -= rhs; }\n    friend inline bool operator==(const\
    \ Matrix& lhs, const Matrix& rhs) noexcept { return lhs.val == rhs.val; }\n  \
    \  friend inline bool operator!=(const Matrix& lhs, const Matrix& rhs) noexcept\
    \ { return lhs.val != rhs.val; }\n    friend inline ostream& operator<<(ostream&\
    \ os, const Matrix& mat) noexcept {\n        const int _n = mat.n;\n        const\
    \ int _m = mat.m;\n        for(int i = 0; i < _n; ++i){\n            for(int j\
    \ = 0; j < _m; ++j){\n                os << mat[i][j] << \" \\n\"[j == _m - 1];\n\
    \            }\n        }\n        return os;\n    }\n    Matrix inv() const {\n\
    \        Matrix a = *this, b = e(n);\n        for(int i = 0; i < n; ++i){\n  \
    \          if(a[i][i] == 0){\n                for(int j = i + 1; j < n; ++j){\n\
    \                    if(a[j][i] != 0){\n                        for(int k = i;\
    \ k < n; ++k) swap(a[i][k], a[j][k]);\n                        for(int k = 0;\
    \ k < n; ++k) swap(b[i][k], b[j][k]);\n                        break;\n      \
    \              }\n                }\n            }\n            if(a[i][i] ==\
    \ 0) throw \"Inverse does not exist.\";\n            const T x = T{1} / a[i][i];\n\
    \            for(int k = i; k < n; ++k) a[i][k] *= x;\n            for(int k =\
    \ 0; k < n; ++k) b[i][k] *= x;\n            for(int j = 0; j < n; ++j){\n    \
    \            if(i != j){\n                    const T x = a[j][i];\n         \
    \           for(int k = i; k < n; ++k) a[j][k] -= a[i][k] * x;\n             \
    \       for(int k = 0; k < n; ++k) b[j][k] -= b[i][k] * x;\n                }\n\
    \            }\n        }\n        return b;\n    }\n    Matrix pow(long long\
    \ r) const {\n        if(r == 0) return e(n);\n        if(r < 0) return inv().pow(-r);\n\
    \        Matrix res = e(n), a = *this;\n        while(r > 0){\n            if(r\
    \ & 1) res *= a;\n            a *= a;\n            r >>= 1;\n        }\n     \
    \   return res;\n    }\n    Matrix pow2(string &r) const {\n        if(r == \"\
    0\") return e(n);\n        Matrix res = e(n), a = *this;\n        int siz = r.size();\n\
    \        for(int i = siz - 1; i >= 0; i--){\n            if(r[i] == '1') res *=\
    \ a;\n            a *= a;\n        }\n        return res;\n    }\n    T det()\
    \ const {\n        Matrix a = *this;\n        T res = 1;\n        for(int i =\
    \ 0; i < n; ++i){\n            if(a[i][i] == 0){\n                for(int j =\
    \ i + 1; j < n; ++j){\n                    if(a[j][i] != 0){\n               \
    \         for(int k = i; k < n; ++k){\n                            swap(a[i][k],\
    \ a[j][k]);\n                        }\n                        res = -res;\n\
    \                        break;\n                    }\n                }\n  \
    \          }\n            if(a[i][i] == 0) return 0;\n            res *= a[i][i];\n\
    \            const T x = T{1} / a[i][i];\n            for(int k = i; k < n; ++k){\n\
    \                a[i][k] *= x;\n            }\n            for(int j = i + 1;\
    \ j < n; ++j){\n                const T x = a[j][i];\n                for(int\
    \ k = i; k < n; ++k){\n                    a[j][k] -= a[i][k] * x;\n         \
    \       }\n            }\n        }\n        return res;\n    }\n    Matrix transpose()\
    \ const {\n        Matrix res(m, n), a = *this;\n        for(int i = 0; i < n;\
    \ ++i){\n            for(int j = 0; j < m; ++j){\n                res[j][i] =\
    \ a[i][j];\n            }\n        }\n        return res;\n    }\n    Matrix gauss()\
    \ const {\n        Matrix a = *this;\n        int r = 0;\n        for(int i =\
    \ 0; i < m; ++i){\n            int pivot = -1;\n            for(int j = r; j <\
    \ n; ++j){\n                if(a[j][i] != 0){\n                    pivot = j;\n\
    \                    break;\n                }\n            }\n            if(pivot\
    \ == -1) continue;\n            for(int j = 0; j < m; ++j){\n                swap(a[pivot][j],\
    \ a[r][j]);\n            }\n            const T s = a[r][i];\n            for(int\
    \ j = i; j < m; ++j){\n                a[r][j] /= s;\n            }\n        \
    \    for(int j = 0; j < n; ++j){\n                if(j == r) continue;\n     \
    \           const T s = a[j][i];\n                if (s == 0) continue;\n    \
    \            for(int k = i; k < m; ++k){\n                    a[j][k] -= a[r][k]\
    \ * s;\n                }\n            }\n            ++r;\n        }\n      \
    \  return a;\n    }\n    int rank(bool is_gaussed = false) const {\n        Matrix\
    \ a = *this;\n        if(!is_gaussed){\n            return (n >= m ? a : a.transpose()).gauss().rank(true);\n\
    \        }\n        int r = 0;\n        for(int i = 0; i < n; ++i){\n        \
    \    while(r < m && a[i][r] == 0) ++r;\n            if(r == m){\n            \
    \    return i;\n            }\n            ++r;\n        }\n        return n;\n\
    \    }\n    // Rotate 90 degrees clockwise\n    Matrix rotate() const {\n    \
    \    Matrix res(m, n), a = *this;\n        for(int i = 0; i < m; ++i){\n     \
    \       for(int j = 0; j < n; ++j){\n                res[i][j] = a[n - j - 1][i];\n\
    \            }\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Matrix\n * @docs docs/math/matrix.md\n */\n\
    \ntemplate <typename T>\nstruct Matrix{\n    int n, m;\n    vector<T> val;\n \
    \   Matrix(int _n, int _m): n(_n), m(_m), val(_n * _m){}\n    Matrix(const vector<vector<T>>&\
    \ mat){\n        n = mat.size();\n        m = mat[0].size();\n        val.resize(n\
    \ * m);\n        for(int i = 0; i < n; ++i){\n            for(int j = 0; j < m;\
    \ ++j){\n                val[i * m + j] = mat[i][j];\n            }\n        }\n\
    \    }\n    static Matrix e(int _n){\n        Matrix res(_n, _n);\n        for(int\
    \ i = 0; i < _n; ++i){\n            res[i][i] = T{1};\n        }\n        return\
    \ res;\n    }\n    auto operator[](int i){ return val.begin() + i * m; }\n   \
    \ auto operator[](int i) const { return val.begin() + i * m; }\n    inline Matrix&\
    \ operator+=(const Matrix &rhs){\n        for(int i = 0; i < n * m; ++i){\n  \
    \          val[i] += rhs[i];\n        }\n        return *this;\n    }\n    inline\
    \ Matrix& operator-=(const Matrix &rhs){\n        for(int i = 0; i < n * m; ++i){\n\
    \            val[i] -= rhs[i];\n        }\n        return *this;\n    }\n    inline\
    \ Matrix operator*(const Matrix &rhs){\n        assert(m == rhs.n);\n        const\
    \ int l = rhs.m;\n        Matrix res(n, l);\n        for(int i = 0; i < n; ++i){\n\
    \            for(int j = 0; j < m; ++j){\n                for(int k = 0; k < l;\
    \ ++k){\n                    res[i][k] += val[i * m + j] * rhs[j][k];\n      \
    \          }\n            }\n        }\n        return res;\n    }\n    inline\
    \ Matrix& operator*=(const Matrix &rhs){\n        return *this = *this * rhs;\n\
    \    }\n    friend inline Matrix operator+(const Matrix& lhs, const Matrix& rhs)\
    \ noexcept { return Matrix(lhs) += rhs; }\n    friend inline Matrix operator-(const\
    \ Matrix& lhs, const Matrix& rhs) noexcept { return Matrix(lhs) -= rhs; }\n  \
    \  friend inline bool operator==(const Matrix& lhs, const Matrix& rhs) noexcept\
    \ { return lhs.val == rhs.val; }\n    friend inline bool operator!=(const Matrix&\
    \ lhs, const Matrix& rhs) noexcept { return lhs.val != rhs.val; }\n    friend\
    \ inline ostream& operator<<(ostream& os, const Matrix& mat) noexcept {\n    \
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
    \ T s = a[j][i];\n                if (s == 0) continue;\n                for(int\
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
    \            }\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/matrix.hpp
  requiredBy: []
  timestamp: '2024-02-18 18:38:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/matrix/pow_of_matrix.test.cpp
  - test/library_checker/matrix/matrix_product.test.cpp
  - test/library_checker/matrix/inverse_matrix.test.cpp
  - test/library_checker/matrix/matrix_det.test.cpp
  - test/library_checker/matrix/matrix_rank.test.cpp
documentation_of: lib/math/matrix.hpp
layout: document
redirect_from:
- /library/lib/math/matrix.hpp
- /library/lib/math/matrix.hpp.html
title: Matrix
---
## Matrix

#### 概要

行列の構造体です。

#### 使い方

- `Matrix<T>(n, m)`: $n \times m$ の行列を作成します。
- `inv()`: 逆行列を求めます。
- `pow(r)`: $r$ 乗した行列を求めます。
- `det()`: 行列式の値を求めます。
- `transpose()`: 転置した行列を求めます。
- `gauss()`: ガウスの消去法を行った行列を求めます。
- `rank()`: 行列の階数を求めます。
- `rotate()`: $90$ 度回転します。

#### 計算量

- `Matrix<T>(n, m)`: $\mathrm{O}(nm)$

行列のサイズを $N \times M$ とします。

- `inv()`: $\mathrm{O}(N^3)$
- `pow(r)`: $\mathrm{O}(NM^2 \log r)$
- `det()`: $\mathrm{O}(N^3)$
- `transpose()`: $\mathrm{O}(NM)$
- `gauss()`: $O(NM^2)$
- `rank()`: $O(NM\cdot \min(N, M))$
- `rotate()`: $\mathrm{O}(NM)$