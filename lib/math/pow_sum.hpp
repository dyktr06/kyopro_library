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
    inline T fact(const int n) const {
        return memo[n];
    }
    inline T factinv(const int n) const {
        return memoinv[n];
    }
    inline T ncr(const int n, const int r) const {
        if(n < r || r < 0) return 0;
        return (memo[n] * memoinv[r]) * memoinv[n - r];
    }
    inline T npr(const int n, const int r) const {
        if(n < r || r < 0) return 0;
        return memo[n] * memoinv[n - r];
    }
    // 重複組み合わせ
    inline T nhr(const int n, const int r) const {
        if(n == 0 && r == 0) return 1;
        return ncr(n + r - 1, r);
    }
    // ボールの数、一個以上必要な箱の数、制限がない箱の数 (箱区別あり)
    // a = 0 の場合は重複組み合わせ
    inline T choose(const int n, const int a, const int b = 0) const {
        if(n == 0) return !a;
        return ncr(n + b - 1, a + b - 1);
    }
    // +1 n 個, -1 m 個, 累積和 >= 0
    inline T cataran(const int n, const int m) const {
        return ncr(n + m, n) - ncr(n + m, n - 1);
    }
    // +1 n 個, -1 m 個, 累積和 > -k
    inline T cataran(const int n, const int m, const int k) const {
        if(m < k) return ncr(n + m, n);
        if(m < n + k) return ncr(n + m, n) - ncr(n + m, m - k);
        return 0;
    }
    // +1 n 個, -1 m 個, 累積和 < +k
    inline T cataran2(const int n, const int m, const int k) const {
        return cataran(m, n, k);
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
