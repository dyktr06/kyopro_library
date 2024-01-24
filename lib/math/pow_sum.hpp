#pragma once

template <typename T>
struct Combination{
    vector<T> memo, memoinv, inv;
    Combination(const int N) : memo(N + 1), memoinv(N + 1), inv(N + 1){
        T m = -1;
        long long mod = (m.val + 1LL);
        memo[0] = memo[1] = 1;
        memoinv[0] = memoinv[1] = 1;
        inv[1] = 1;
        for(int i = 2; i <= N; ++i){
            memo[i] = memo[i - 1] * i;
            inv[i] = mod - inv[mod % i] * (mod / i);
            memoinv[i] = memoinv[i - 1] * inv[i];
        }
    }
    inline T fact(const long long n) const {
        return memo[n];
    }
    inline T factinv(const long long n) const {
        return memoinv[n];
    }
    inline T ncr(const long long n, const long long r) const {
        if(n < r || r < 0) return 0;
        return (memo[n] * memoinv[r]) * memoinv[n - r];
    }
    inline T npr(const long long n, const long long r) const {
        if(n < r || r < 0) return 0;
        return memo[n] * memoinv[n - r];
    }
    inline T nhr(const long long n, const long long r) const {
        if(n == 0 && r == 0) return 1;
        return ncr(n + r - 1, r);
    }
};

template <typename T>
T pow_sum(long long n, long long k){
    long long d = k + 1;
    vector<vector<T>> f(d + 1, vector<T>(2));
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < d + 1; i++){
            if(i > 0 && j == 0){
                f[i][0] = i;
                f[i][0] = f[i][0].pow(k);
            }
            if(i > 0 && j > 0){
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
    }

    Combination<T> comb(d);
    vector<T> l(d + 1, 1), r(d + 1, 1);
    for(int i = 0; i < d; i++){
        l[i + 1] = l[i] * (n - i);
        r[i + 1] = r[i] * (n - (d - i)); 
    }
    T ans = 0;
    for(int i = 0; i < d + 1; i++){
        T s = f[i][1];
        // mul(n - x_j) (j != i)
        s *= l[i];
        s *= r[d - i];
        // i! * (d - i)! * (-1)^{d - i}
        s *= comb.factinv(i);
        s *= comb.factinv(d - i);
        if((d - i) % 2) s *= -1;
        ans += s;
    }
    return ans;
}