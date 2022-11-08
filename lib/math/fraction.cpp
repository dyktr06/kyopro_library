#include <bits/stdc++.h>

using namespace std;

// 分数(p/q) の構造体
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
};

void example(){
    int n; cin >> n;
    vector<fraction> k(n);
    k[0] = fraction(10, 3); // 10/3
    k[1] = fraction(24, 7); // 24/7
    if(k[0] < k[1]){
        // 
    }
}