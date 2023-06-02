#pragma once

/**
 * @brief Matrix
 * @docs docs/math/matrix.md
 */

template <typename T>
struct Matrix{
    int n, m;
    vector<T> val;
    Matrix(int _n, int _m): n(_n), m(_m), val(_n * _m){}
    Matrix(const vector<vector<T>>& mat){
        n = mat.size();
        m = mat[0].size();
        val.resize(n * m);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                val[i * m + j] = mat[i][j];
            }
        }
    }
    static Matrix e(int _n){
        Matrix res(_n, _n);
        for(int i = 0; i < _n; ++i){
            res[i][i] = T{1};
        }
        return res;
    }
    auto operator[](int i){ return val.begin() + i * m; }
    auto operator[](int i) const { return val.begin() + i * m; }
    inline Matrix& operator+=(const Matrix &rhs){
        for(int i = 0; i < n * m; ++i){
            val[i] += rhs[i];
        }
        return *this;
    }
    inline Matrix& operator-=(const Matrix &rhs){
        for(int i = 0; i < n * m; ++i){
            val[i] -= rhs[i];
        }
        return *this;
    }
    inline Matrix operator*(const Matrix &rhs){
        assert(m == rhs.n);
        const int l = rhs.m;
        Matrix res(n, l);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                for(int k = 0; k < l; ++k){
                    res[i][k] += val[i * m + j] * rhs[j][k];
                }
            }
        }
        return res;
    }
    inline Matrix& operator*=(const Matrix &rhs){
        return *this = *this * rhs;
    }
    friend inline Matrix operator+(const Matrix& lhs, const Matrix& rhs) noexcept { return Matrix(lhs) += rhs; }
    friend inline Matrix operator-(const Matrix& lhs, const Matrix& rhs) noexcept { return Matrix(lhs) -= rhs; }
    friend inline bool operator==(const Matrix& lhs, const Matrix& rhs) noexcept { return lhs.val == rhs.val; }
    friend inline bool operator!=(const Matrix& lhs, const Matrix& rhs) noexcept { return lhs.val != rhs.val; }
    friend inline ostream& operator<<(ostream& os, const Matrix& mat) noexcept {
        const int _n = mat.n;
        const int _m = mat.m;
        for(int i = 0; i < _n; ++i){
            for(int j = 0; j < _m; ++j){
                os << mat[i][j] << " \n"[j == _m - 1];
            }
        }
        return os;
    }
    Matrix inv() const {
        Matrix a = *this, b = e(n);
        for(int i = 0; i < n; ++i){
            if(a[i][i] == 0){
                for(int j = i + 1; j < n; ++j){
                    if(a[j][i] != 0){
                        for(int k = i; k < n; ++k) swap(a[i][k], a[j][k]);
                        for(int k = 0; k < n; ++k) swap(b[i][k], b[j][k]);
                        break;
                    }
                }
            }
            if(a[i][i] == 0) throw "Inverse does not exist.";
            const T x = T{1} / a[i][i];
            for(int k = i; k < n; ++k) a[i][k] *= x;
            for(int k = 0; k < n; ++k) b[i][k] *= x;
            for(int j = 0; j < n; ++j){
                if(i != j){
                    const T x = a[j][i];
                    for(int k = i; k < n; ++k) a[j][k] -= a[i][k] * x;
                    for(int k = 0; k < n; ++k) b[j][k] -= b[i][k] * x;
                }
            }
        }
        return b;
    }
    Matrix pow(long long r) const {
        if(r == 0) return e(n);
        if(r < 0) return inv().pow(-r);
        Matrix res = e(n), a = *this;
        while(r > 0){
            if(r & 1) res *= a;
            a *= a;
            r >>= 1;
        }
        return res;
    }
    T det() const {
        Matrix a = *this;
        T res = 1;
        for(int i = 0; i < n; ++i){
            if(a[i][i] == 0){
                for(int j = i + 1; j < n; ++j){
                    if(a[j][i] != 0){
                        for(int k = i; k < n; ++k){
                            swap(a[i][k], a[j][k]);
                        }
                        res = -res;
                        break;
                    }
                }
            }
            if(a[i][i] == 0) return 0;
            res *= a[i][i];
            const T x = T{1} / a[i][i];
            for(int k = i; k < n; ++k){
                a[i][k] *= x;
            }
            for(int j = i + 1; j < n; ++j){
                const T x = a[j][i];
                for(int k = i; k < n; ++k){
                    a[j][k] -= a[i][k] * x;
                }
            }
        }
        return res;
    }
    // Rotate 90 degrees clockwise
    Matrix rotate() const {
        Matrix res(m, n), a = *this;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                res[i][j] = a[n - j - 1][i];
            }
        }
        return res;
    }
};