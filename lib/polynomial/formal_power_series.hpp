#pragma once

/**
 * @brief Formal Power Series (形式的冪級数)
 */

#include <algorithm>
#include <cassert>
#include <vector>
#include "../convolution/ntt.hpp"

template <typename T>
struct FormalPowerSeries : std::vector<T> {
    using std::vector<T>::vector;
    using FPS = FormalPowerSeries;

    // deg 次として初期化
    FPS pre(int deg) const {
        FPS res(std::begin(*this), std::begin(*this) + std::min((int) this->size(), deg));
        if((int) res.size() < deg) res.resize(deg, T(0));
        return res;
    }

    // deg 次として反転
    FPS rev(int deg = -1) const {
        FPS res(*this);
        if(deg != -1) res.resize(deg, T(0));
        std::reverse(std::begin(res), std::end(res));
        return res;
    }

    int notZeroCount() const {
        int res = 0;
        for(auto x : *this){
            if(x != T(0)) res++;
        }
        return res;
    }

    int maxDeg() const {
        for(int i = (int) this->size() - 1; i >= 0; i--){
            if((*this)[i] != T(0)) return i;
        }
        return -1;
    }

    void shrink() {
        while(this->size() && this->back() == T(0)) this->pop_back();
    }

    std::vector<std::pair<int, T>> sparseFormat() const {
        std::vector<std::pair<int, T>> res;
        for(int i = 0; i < (int) this->size(); i++){
            if((*this)[i] != T(0)) res.emplace_back(i, (*this)[i]);
        }
        return res;
    }

    FPS operator+(const T &rhs) const { return FPS(*this) += rhs; }
    FPS operator+(const FPS &rhs) const { return FPS(*this) += rhs; }
    FPS operator-(const T &rhs) const { return FPS(*this) -= rhs; }
    FPS operator-(const FPS &rhs) const { return FPS(*this) -= rhs; }
    FPS operator*(const T &rhs) const { return FPS(*this) *= rhs; }
    FPS operator*(const FPS &rhs) const { return FPS(*this) *= rhs; }
    FPS operator/(const T &rhs) const { return FPS(*this) /= rhs; }
    FPS operator/(const FPS &rhs) const { return FPS(*this) /= rhs; }
    FPS operator%(const FPS &rhs) const { return FPS(*this) %= rhs; }
    FPS operator-() const {
        FPS res(this->size());
        for(int i = 0; i < (int) this->size(); i++) res[i] = -(*this)[i];
        return res;
    }

    FPS &operator+=(const T &rhs){
        if(this->empty()) this->resize(1);
        (*this)[0] += rhs;
        return *this;
    }

    FPS &operator-=(const T &rhs){
        if(this->empty()) this->resize(1);
        (*this)[0] -= rhs;
        return *this;
    }

    FPS &operator*=(const T &rhs){
        for(auto &x : *this) x *= rhs;
        return *this;
    }

    FPS &operator/=(const T &rhs){
        for(auto &x : *this) x /= rhs;
        return *this;
    }

    FPS &operator+=(const FPS &rhs) noexcept {
        if(this->size() < rhs.size()) this->resize(rhs.size());
        for(int i = 0; i < (int) rhs.size(); i++) (*this)[i] += rhs[i];
        return *this;
    }

    FPS &operator-=(const FPS &rhs) noexcept {
        if(this->size() < rhs.size()) this->resize(rhs.size());
        for(int i = 0; i < (int) rhs.size(); i++) (*this)[i] -= rhs[i];
        return *this;
    }

    FPS &operator*=(const FPS &rhs) noexcept {
        long long len1 = this->notZeroCount(), len2 = rhs.notZeroCount();
        // Sparse な場合
        if(len1 * len2 <= 60LL * (long long) std::max(this->size(), rhs.size())){
            std::vector<std::pair<int, T>> rhs_sparse = rhs.sparseFormat();
            return *this = this->multiply_naive(rhs_sparse);
        }
        auto res = NTT::convolution_mod(*this, rhs, T::mod());
        return *this = {std::begin(res), std::end(res)};
    }

    // f/g = f * (g.inv())
    FPS &operator/=(const FPS &rhs) noexcept {
        if(this->size() < rhs.size()) return *this = FPS();
        const int n = this->size() - rhs.size() + 1;
        return *this = (rev().pre(n) * rhs.rev().inv(n)).pre(n).rev(n);
    }

    FPS &operator%=(const FPS &rhs) noexcept {
        return *this -= (*this / rhs) * rhs;
    }

    FPS operator>>(int deg) const {
        if((int) this->size() <= deg) return {};
        FPS res(*this);
        res.erase(std::begin(res), std::begin(res) + deg);
        return res;
    }

    FPS operator<<(int deg) const {
        FPS res(*this);
        res.insert(std::begin(res), deg, T(0));
        return res;
    }

    // 微分
    FPS diff() const {
        const int n = this->size();
        FPS res(std::max(0, n - 1));
        for(int i = 1; i < n; i++) res[i - 1] = (*this)[i] * T(i);
        return res;
    }

    // 積分
    FPS integral() const {
        const int n = this->size();
        FPS res(n + 1);
        res[0] = T(0);
        for(int i = 0; i < n; i++) res[i + 1] = (*this)[i] / T(i + 1);
        return res;
    }

    // {lhs / rhs, lhs % rhs}
    std::pair<FPS, FPS> division(const FPS &rhs) const {
        FPS q = *this / rhs;
        FPS r = *this - q * rhs;
        q.shrink(), r.shrink();
        return {q, r};
    }

    FPS multiply_naive(const std::vector<std::pair<int, T>> &rhs, int deg = -1){
        if(deg == -1) deg = this->size() + (rhs.back().first + 1) - 1;
        FPS res(deg, T(0));
        for(auto &[i, x] : this->sparseFormat()){
            for(auto &[j, y] : rhs){
                if(i + j >= deg) break;
                res[i + j] += x * y;
            }
        }
        return *this = {std::begin(res), std::end(res)};
    }

    FPS divide_naive(const std::vector<std::pair<int, T>> &rhs){
        assert(!rhs.empty());
        if((int) this->size() < (rhs.back().first + 1)) return FPS();
        auto [i0, x0] = rhs[0];
        assert(i0 == 0 && x0 != T(0));
        T x0_inv = T(1) / x0;
        for(int i = 0; i < (int) this->size(); i++){
            for(int i2 = 1; i2 < (int) rhs.size(); i2++){
                auto &[j, y] = rhs[i2];
                if(i < j) break;
                (*this)[i] -= (*this)[i - j] * y;
            }
            (*this)[i] *= x0_inv;
        }
        return *this;
    }

    // fg = 1 (mod x^n) となる g
    FPS inv(int deg = -1) const {
        assert((*this)[0] != T(0));
        if(deg == -1) deg = this->size();
        // g_p mod x^k から g mod x^2k を求める
        // (g - g_p)^2 = g^2 - 2 g g_p + (g_p)^2 = 0 (mod x^2k)
        // fg^2 - 2fg g_p + f (g_p)^2
        // = g - 2(g_p) + f (g_p)^2 = 0 (mod x^2k)
        // g = 2(g_p) - f (g_p)^2 (mod x^2k)
        FPS res({T(1) / (*this)[0]});
        for(int i = 1; i < deg; i <<= 1) {
            res = (res + res - res * res * pre(i << 1)).pre(i << 1);
        }
        return res.pre(deg);
    }

    // g = log f となる g
    FPS log(int deg = -1) const {
        assert((*this)[0] == T(1));
        if(deg == -1) deg = this->size();
        // log f = integral((f' / f) dx)
        return (this->diff() * this->inv(deg)).pre(deg - 1).integral().pre(deg);
    }

    // g = exp(f) となる g
    FPS exp(int deg = -1) const {
        assert((*this)[0] == T(0));
        if(deg == -1) deg = this->size();
        // g_p mod x^k から g mod x^2k をニュートン法で求める
        // log g = f (mod x^n) であるから、
        // g = g_p - (log g_p - f)/(log' g_p)
        //   = g_p(1 - log g_p + f) (mod x^2k)
        FPS res({T(1)});
        for(int i = 1; i < deg; i <<= 1) {
            res = (res * (-res.log(i << 1) + pre(i << 1) + T(1))).pre(i << 1);
        }
        return res.pre(deg);
    }

    // g = f^k となる g
    FPS pow(long long k, int deg = -1) const {
        if(deg == -1) deg = this->size();
        if(k == 0){
            FPS res(deg, T(0));
            res[0] = T(1);
            return res;
        }
        // f^k = exp(log f)^k = exp(k log f)
        // log を計算するのに定数項が 1 である必要があるので調整する
        // 最も低次の項を a x^i として、(f / (a x^i))^k を計算してから (a x^i)^k を掛ける
        for(int i = 0; i < (int) this->size(); i++){
            if(k * i > deg) return FPS(deg, T(0));
            if((*this)[i] != T(0)){
                T inv_i = T(1) / (*this)[i];
                FPS res = ((((*this) * inv_i) >> i).log(deg) * k).exp(deg) * ((*this)[i].pow(k));
                res = (res << (k * i)).pre(deg);
                return res;
            }
        }
        return *this;
    }

    long long sqrtT(const T a) const {
        const long long p = T::mod();
        if(a == T(0) || a == T(1)) return a.val;
        if(a.pow((p - 1) / 2) != T(1)) return -1LL;
        T b = 1;
        while(b.pow((p - 1) / 2) == 1) b++;
        // p - 1 = m 2^e
        long long m = p - 1;
        int e = 0;
        while(m % 2 == 0) m >>= 1, e++;
        // x = a^((m + 1) / 2) (mod p)
        T x = a.pow((m - 1) / 2);
        // y = a^{-1} x^2 (mod p)
        T y = (a * x) * x;
        x *= a;
        T z = b.pow(m);
        while(y != 1){
            int j = 0;
            T t = y;
            while(t != 1){
                t *= t;
                j++;
            }
            z = z.pow(1LL << (e - j - 1));
            x *= z;
            z *= z;
            y *= z;
            e = j;
        }
        return x.val;
    }

    // g^2 = f となる g
    FPS sqrt(int deg = -1) const {
        if(this->empty()) return {};
        if(deg == -1) deg = this->size();
        // inv を計算するのに定数項が非零である必要があるので調整する
        if((*this)[0] == T(0)){
            for(int i = 1; i < (int) this->size(); i++){
                if((*this)[i] == T(0)) continue;
                if(i & 1) return {};
                FPS res = (*this >> i).sqrt();
                if(res.empty()) return {};
                res = res.pre(deg - i / 2) << (i / 2);
                return res;
            }
            FPS res(deg, T(0));
            return res;
        }
        // g_p mod x^k から g mod x^2k をニュートン法で求める
        // g^2 = f (mod x^n) であるから、
        // g = g_p - ((g_p)^2 - f)/((g_p^2)')
        //   = g_p - ((g_p)^2 - f)/(2 g_p)
        //   = 1/2 * (g_p + f/g_p (mod x^2k)
        long long sqrt0 = sqrtT((*this)[0]);
        if(sqrt0 == -1) return {};
        FPS res({T(sqrt0)});
        T inv2 = T(1) / T(2);
        for(int i = 1; i < deg; i <<= 1) {
            res = (res + pre(i << 1) * res.inv(i << 1)) * inv2;
        }
        return res.pre(deg);
    }
};
