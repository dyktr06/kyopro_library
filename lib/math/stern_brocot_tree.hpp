#pragma once

#include <bits/stdc++.h>
#include "../math/bigint.hpp"

using namespace std;

using bint = BigInt<1000000LL, 6>;

struct fraction{
    bint p, q;
    fraction(bint P = 0, bint Q = 1): p(P), q(Q){ }
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
    inline fraction& operator+=(const fraction& rhs) noexcept {
        *this = *this + rhs;
        return *this;
    }
    inline fraction& operator-=(const fraction& rhs) noexcept {
        *this = *this - rhs;
        return *this;
    }
    inline fraction& operator*=(const fraction& rhs) noexcept {
        *this = *this * rhs;
        return *this;
    }
    inline fraction& operator/=(const fraction& rhs) noexcept {
        *this = *this / rhs;
        return *this;
    }
    friend inline istream& operator>>(istream& is, fraction& x) noexcept {
        is >> x.p;
        x.q = 1;
        return is;
    }
    friend inline ostream& operator<<(ostream& os, const fraction& x) noexcept { return os << x.p << "/" << x.q; }
};

pair<fraction, fraction> SternBrocot(bint n, fraction p){
    fraction a(0, 1), b(1, 0);
    fraction x(0, 1), y(1, 0);
    bool ok_left = true, ok_right = true;
    while(ok_left && ok_right){
        fraction m(a.p + b.p, a.q + b.q);
        if(p < m){
            bint ok = 0, ng = n;
            while(ng - ok > 1){
                bint mid = (ok + ng) / 2;
                fraction m2(a.p * mid + b.p, a.q * mid + b.q);
                if(p < m2 && m2.p <= n && m2.q <= n){
                    ok = mid;
                    m = m2;
                }else{
                    ng = mid;
                }
            }
            b = m;
            if(m.p <= n && m.q <= n){
                y = m;
            }else{
                ok_left = false;
            }
        }else{
            bint ok = 0, ng = n;
            while(ng - ok > 1){
                bint mid = (ok + ng) / 2;
                fraction m2(a.p + b.p * mid, a.q + b.q * mid);
                if(p >= m2 && m2.p <= n && m2.q <= n){
                    ok = mid;
                    m = m2;
                }else{
                    ng = mid;
                }
            }
            a = m;
            if(m.p <= n && m.q <= n){
                x = m;
            }else{
                ok_right = false;
            }
        }
    }
    return make_pair(x, y);
}