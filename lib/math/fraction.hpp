#pragma once

/**
 * @brief Fraction
 * @docs docs/math/fraction.md
 */

struct fraction{
    long long p, q; // long long or __int128_t
    fraction(long long P = 0, long long Q = 1): p(P), q(Q){
        normalize();
    }
    void normalize(){
        long long g = __gcd(p, q);
        p /= g, q /= g;
        if(q < 0) p *= -1, q *= -1;
    }
    inline bool operator<(const fraction &other) const {
        return p * other.q < other.p * q;
    }
    inline bool operator<=(const fraction &other) const {
        return p * other.q <= other.p * q;
    }
    inline fraction operator+(const fraction &other) const { return fraction(p * other.q + q * other.p, q * other.q); }
    inline fraction operator-(const fraction &other) const { return fraction(p * other.q - q * other.p, q * other.q); }
    inline fraction operator*(const fraction &other) const { return fraction(p * other.p, q * other.q); }
    inline fraction operator/(const fraction &other) const { return fraction(p * other.q, q * other.p); }
    friend inline ostream& operator<<(ostream& os, const fraction& x) noexcept { return os << x.p << "/" << x.q; }
};