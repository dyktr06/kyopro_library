#include <bits/stdc++.h>

using namespace std;

// mod. m での x^n を計算します : O(logn)
template< typename T >
T modpow(T x, T n, const T &m){
  T ret = 1;
  x %= m;
  while(n > 0) {
    if(n & 1) (ret *= x) %= m;
    (x *= x) %= m;
    n >>= 1;
  }
  return ret;
}

// mod. m での a の逆元 a^{-1} を計算します : O(logN)
template<class T>
T modinv(T a, T m){
    T b = m, u = 1, v = 0;
    while (b) {
        T t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

// mod. m での二項係数などを高速で計算します : O(NlogN)
struct Combination{
    vector<long long> memo;
    vector<long long> memoinv;
    long long mod;

    Combination(int N, long long m) : memo(N+1), memoinv(N+1){
        mod = m;
        memo[0] = 1;
        for(int i = 1; i <= N; i++){
            memo[i] = memo[i-1] * i;
            memo[i] %= mod;
        }
        memoinv[0] = inv(1LL, mod);
        for(int i = 1; i <= N; i++){
            memoinv[i] = inv(1LL * memo[i], mod);
            memoinv[i] %= mod;
        }
    }

    long long inv(long long a, long long m){
        long long b = m, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= m;
        if (u < 0) u += m;
        return u;
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