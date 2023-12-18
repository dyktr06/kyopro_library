#pragma once

/**
 * @brief ModInt
 * @docs docs/math/modint.md
 */

template <long long Modulus>
struct ModInt{
    long long val;
    constexpr ModInt(const long long _val = 0) noexcept : val(_val) {
        normalize();
    }
    void normalize(){
        val = (val % Modulus + Modulus) % Modulus;
    }
    inline ModInt& operator+=(const ModInt& rhs) noexcept {
        if(val += rhs.val, val >= Modulus) val -= Modulus;
        return *this;
    }
    inline ModInt& operator-=(const ModInt& rhs) noexcept {
        if(val -= rhs.val, val < 0) val += Modulus;
        return *this;
    }
    inline ModInt& operator*=(const ModInt& rhs) noexcept {
        val = val * rhs.val % Modulus;
        return *this;
    }
    inline ModInt& operator/=(const ModInt& rhs) noexcept {
        val = val * inv(rhs.val).val % Modulus;
        return *this;
    }
    inline ModInt& operator++() noexcept {
        if(++val >= Modulus) val -= Modulus;
        return *this;
    }
    inline ModInt operator++(int) noexcept {
        ModInt t = val;
        if(++val >= Modulus) val -= Modulus;
        return t;
    }
    inline ModInt& operator--() noexcept {
        if(--val < 0) val += Modulus;
        return *this;
    }
    inline ModInt operator--(int) noexcept {
        ModInt t = val;
        if(--val < 0) val += Modulus;
        return t;
    }
    inline ModInt operator-() const noexcept { return (Modulus - val) % Modulus; }
    inline ModInt inv(void) const { return inv(val); }
    ModInt pow(long long n){
        assert(0 <= n);
        ModInt x = *this, r = 1;
        while(n){
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    ModInt inv(const long long n) const {
        long long a = n, b = Modulus, u = 1, v = 0;
        while(b){
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= Modulus;
        if(u < 0) u += Modulus;
        return u;
    }
    friend inline ModInt operator+(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) += rhs; }
    friend inline ModInt operator-(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) -= rhs; }
    friend inline ModInt operator*(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) *= rhs; }
    friend inline ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept { return ModInt(lhs) /= rhs; }
    friend inline bool operator==(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs.val == rhs.val; }
    friend inline bool operator!=(const ModInt& lhs, const ModInt& rhs) noexcept { return lhs.val != rhs.val; }
    friend inline istream& operator>>(istream& is, ModInt& x) noexcept {
        is >> x.val;
        x.normalize();
        return is;
    }
    friend inline ostream& operator<<(ostream& os, const ModInt& x) noexcept { return os << x.val; }
};