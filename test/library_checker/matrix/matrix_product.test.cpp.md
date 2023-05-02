---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/matrix.hpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/library_checker/matrix/matrix_product.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"lib/math/matrix.hpp\"\n\n/**\n * @brief Matrix\n\
    \ * @docs docs/math/matrix.md\n */\n\ntemplate <typename T>\nstruct Matrix{\n\
    \    int n, m;\n    vector<T> val;\n    Matrix(int _n, int _m): n(_n), m(_m),\
    \ val(_n * _m){}\n    Matrix(const vector<vector<T>>& mat){\n        n = mat.size();\n\
    \        m = mat[0].size();\n        val.resize(n * m);\n        for(int i = 0;\
    \ i < n; ++i){\n            for(int j = 0; j < m; ++j){\n                val[i\
    \ * m + j] = mat[i][j];\n            }\n        }\n    }\n    static Matrix e(int\
    \ _n){\n        Matrix res(_n, _n);\n        for(int i = 0; i < _n; ++i){\n  \
    \          res[i][i] = T{1};\n        }\n        return res;\n    }\n    auto\
    \ operator[](int i){ return val.begin() + i * m; }\n    auto operator[](int i)\
    \ const { return val.begin() + i * m; }\n    inline Matrix& operator+=(const Matrix\
    \ &rhs){\n        for(int i = 0; i < n * m; ++i){\n            val[i] += rhs[i];\n\
    \        }\n        return *this;\n    }\n    inline Matrix& operator-=(const\
    \ Matrix &rhs){\n        for(int i = 0; i < n * m; ++i){\n            val[i] -=\
    \ rhs[i];\n        }\n        return *this;\n    }\n    inline Matrix operator*(const\
    \ Matrix &rhs){\n        assert(m == rhs.n);\n        const int l = rhs.m;\n \
    \       Matrix res(n, l);\n        for(int i = 0; i < n; ++i){\n            for(int\
    \ j = 0; j < m; ++j){\n                for(int k = 0; k < l; ++k){\n         \
    \           res[i][k] += val[i * m + j] * rhs[j][k];\n                }\n    \
    \        }\n        }\n        return res;\n    }\n    inline Matrix& operator*=(const\
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
    \ 0) throw \"This matrix is not regular.\";\n            const T x = T{1} / a[i][i];\n\
    \            for(int k = i; k < n; ++k) a[i][k] *= x;\n            for(int k =\
    \ 0; k < n; ++k) b[i][k] *= x;\n            for(int j = 0; j < n; ++j){\n    \
    \            if(i != j){\n                    const T x = a[j][i];\n         \
    \           for(int k = i; k < n; ++k) a[j][k] -= a[i][k] * x;\n             \
    \       for(int k = 0; k < n; ++k) b[j][k] -= b[i][k] * x;\n                }\n\
    \            }\n        }\n        return b;\n    }\n    Matrix pow(long long\
    \ r) const {\n        if(r == 0) return e(n);\n        if(r < 0) return inv().pow(-r);\n\
    \        Matrix res = e(n), a = *this;\n        while(r > 0){\n            if(r\
    \ & 1) res *= a;\n            if(r == 1) return res;\n            res *= res;\n\
    \            r >>= 1;\n        }\n    }\n    // Rotate 90 degrees clockwise\n\
    \    Matrix rotate() const {\n        Matrix res(m, n), a = *this;\n        for(int\
    \ i = 0; i < m; ++i){\n            for(int j = 0; j < n; ++j){\n             \
    \   res[i][j] = a[n - j - 1][i];\n            }\n        }\n        return res;\n\
    \    }\n};\n\nvector<vector<long long>> matrixpow(vector<vector<long long>> a,\
    \ long long n, long long m){\n\n    int siz = a.size();\n    vector<vector<long\
    \ long>> b(siz, vector<long long>(siz, 0));\n    for(int i = 0; i < siz; i++)\
    \ b[i][i] = 1;\n\n    auto mul = [](vector<vector<long long>> a, vector<vector<long\
    \ long>> b, long long m) -> vector<vector<long long>> {\n        vector<vector<long\
    \ long>> res((int) a.size(), vector<long long>(b[0].size()));\n        for(int\
    \ i = 0; i < (int) a.size(); i++){\n            for(int k = 0; k < (int) b.size();\
    \ k++){\n                for(int j = 0; j < (int) b[0].size(); j++){\n       \
    \             res[i][j] += a[i][k] * b[k][j];\n                    res[i][j] %=\
    \ m;\n                }\n            }\n        }\n        return res;\n    };\n\
    \n    while(n > 0){\n        if(n & 1) b = mul(b, a, m);\n        a = mul(a, a,\
    \ m);\n        n >>= 1;\n    }\n    return b;\n}\n\n// \u884C\u5217\u306E\u7A4D\
    \ (mod. m) \u3092\u8A08\u7B97\u3057\u307E\u3059\u3002: O(N^3)\nvector<vector<long\
    \ long>> mul(vector<vector<long long>> a, vector<vector<long long>> b, long long\
    \ m){\n    vector<vector<long long>> res((int) a.size(), vector<long long>(b[0].size()));\n\
    \    for(int i = 0; i < (int) a.size(); i++){\n        for(int k = 0; k < (int)\
    \ b.size(); k++){\n            for(int j = 0; j < (int) b[0].size(); j++){\n \
    \               res[i][j] += a[i][k] * b[k][j];\n                res[i][j] %=\
    \ m;\n            }\n        }\n    }\n    return res;\n}\n#line 6 \"test/library_checker/matrix/matrix_product.test.cpp\"\
    \n\nconst long long MOD = 998244353;\n\nint main(){\n    int n, m, k; cin >> n\
    \ >> m >> k;\n    vector<vector<long long>> a(n, vector<long long>(m));\n    vector<vector<long\
    \ long>> b(m, vector<long long>(k));\n    for(int i = 0; i < n; i++){\n      \
    \  for(int j = 0; j < m; j++){\n            cin >> a[i][j];\n        }\n    }\n\
    \    for(int i = 0; i < m; i++){\n        for(int j = 0; j < k; j++){\n      \
    \      cin >> b[i][j];\n        }\n    }\n    vector<vector<long long>> c = mul(a,\
    \ b, MOD);\n    for(int i = 0; i < n; i++){\n        for(int j = 0; j < k; j++){\n\
    \            if(j >= 1) cout << \" \";\n            cout << c[i][j];\n       \
    \ }\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../../lib/math/matrix.hpp\"\
    \n\nconst long long MOD = 998244353;\n\nint main(){\n    int n, m, k; cin >> n\
    \ >> m >> k;\n    vector<vector<long long>> a(n, vector<long long>(m));\n    vector<vector<long\
    \ long>> b(m, vector<long long>(k));\n    for(int i = 0; i < n; i++){\n      \
    \  for(int j = 0; j < m; j++){\n            cin >> a[i][j];\n        }\n    }\n\
    \    for(int i = 0; i < m; i++){\n        for(int j = 0; j < k; j++){\n      \
    \      cin >> b[i][j];\n        }\n    }\n    vector<vector<long long>> c = mul(a,\
    \ b, MOD);\n    for(int i = 0; i < n; i++){\n        for(int j = 0; j < k; j++){\n\
    \            if(j >= 1) cout << \" \";\n            cout << c[i][j];\n       \
    \ }\n        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - lib/math/matrix.hpp
  isVerificationFile: true
  path: test/library_checker/matrix/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2023-05-02 12:33:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/matrix/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/matrix/matrix_product.test.cpp
- /verify/test/library_checker/matrix/matrix_product.test.cpp.html
title: test/library_checker/matrix/matrix_product.test.cpp
---
