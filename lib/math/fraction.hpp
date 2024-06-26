#pragma once

/**
 * @brief Fraction
 * @docs docs/math/fraction.md
 */

template <typename T>
struct fraction{
    T p, q; // long long or BigInt
    fraction(T P = 0, T Q = 1) : p(P), q(Q){
        normalize();
    }
    void normalize(){
        T g = __gcd(p, q);
        p /= g, q /= g;
        if(q < 0) p *= -1, q *= -1;
    }
    inline bool operator==(const fraction &other) const {
        return p * other.q == other.p * q;
    }
    inline bool operator!=(const fraction &other) const {
        return p * other.q != other.p * q;
    }
    inline bool operator<(const fraction &other) const {
        return p * other.q < other.p * q;
    }
    inline bool operator<=(const fraction &other) const {
        return p * other.q <= other.p * q;
    }
    inline bool operator>(const fraction &other) const {
        return p * other.q > other.p * q;
    }
    inline bool operator>=(const fraction &other) const {
        return p * other.q >= other.p * q;
    }
    inline fraction operator+(const fraction &other) const { return fraction(p * other.q + q * other.p, q * other.q); }
    inline fraction operator-(const fraction &other) const { return fraction(p * other.q - q * other.p, q * other.q); }
    inline fraction operator*(const fraction &other) const { return fraction(p * other.p, q * other.q); }
    inline fraction operator/(const fraction &other) const { return fraction(p * other.q, q * other.p); }
    inline fraction &operator+=(const fraction &rhs) noexcept {
        *this = *this + rhs;
        return *this;
    }
    inline fraction &operator-=(const fraction &rhs) noexcept {
        *this = *this - rhs;
        return *this;
    }
    inline fraction &operator*=(const fraction &rhs) noexcept {
        *this = *this * rhs;
        return *this;
    }
    inline fraction &operator/=(const fraction &rhs) noexcept {
        *this = *this / rhs;
        return *this;
    }
    friend inline istream &operator>>(istream &is, fraction &x) noexcept {
        is >> x.p;
        x.q = 1;
        return is;
    }
    friend inline ostream &operator<<(ostream &os, const fraction &x) noexcept { return os << x.p << "/" << x.q; }
};
