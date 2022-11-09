#include <bits/stdc++.h>

using namespace std;

// mod. m での x^n を計算します : O(logn)
template <typename T>
T modpow(T x, T n, const T &m){
    T ret = 1 % m;
    x %= m;
    while(n > 0){
        if(n & 1) (ret *= x) %= m;
        (x *= x) %= m;
        n >>= 1;
    }
    return ret;
}

// mod. m での a の逆元 a^{-1} を計算します : O(logm)
template <typename T>
T modinv(T a, T m){
    T b = m, u = 1, v = 0;
    while(b){
        T t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

// mod. m での初項 a, 公差 d, 項数 n の等差数列の和を計算します : O(logm)
template <typename T>
T modarithmeticsum(T a, T d, T n, T m){
    a %= m, n %= m, d %= m;
    T b = (n - 1) * d % m;
    return n * (a * 2 + b) % m * modinv((T) 2, m) % m;
}

// mod. m での初項 a, 公比 r, 項数 n の等比数列の和を計算します : O(log(nm))
template <typename T>
T modgeometricsum(T a, T r, T n, T m){
    a %= m;
    if(r == 1){
        n %= m;
        return a * n % m;
    }
    return a * (modpow(r, n, m) + m - 1) % m * modinv(r - 1, m) % m;
}

// mod. m での二項係数などを高速で計算します : O(N)
struct Combination{
    vector<long long> memo, memoinv, inv;
    long long mod;

    Combination(int N, long long m) : memo(N + 1), memoinv(N + 1), inv(N + 1){
        mod = m;
        memo[0] = memo[1] = 1;
        memoinv[0] = memoinv[1] = 1;
        inv[1] = 1;
        for(int i = 2; i <= N; i++){
            memo[i] = memo[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (m / i) % mod;
            memoinv[i] = memoinv[i - 1] * inv[i] % mod;
        }
    }

    long long fact(long long n){
        return memo[n];
    }

    long long factinv(long long n){
        return memoinv[n];
    }

    long long ncr(long long n, long long r){
        if(n < r || r < 0) return 0;
        return (memo[n] * memoinv[r] % mod) * memoinv[n - r] % mod;
    }

    long long npr(long long n, long long r){
        if(n < r || r < 0) return 0;
        return (memo[n] % mod) * memoinv[n - r] % mod;
    }
};
