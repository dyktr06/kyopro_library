#pragma once

/**
 * @brief Combination (二項係数)
 */

#include <vector>

template <typename T>
struct Combination{
    std::vector<T> memo, memoinv, inv;
    Combination() : memo(2, T(1)), memoinv(2, T(1)), inv(2, T(1)){}

    void init(const int N){
        if((int) memo.size() >= N + 1){
            return;
        }
        int prev_len = memo.size();
        memo.resize(N + 1);
        memoinv.resize(N + 1);
        inv.resize(N + 1);

        T m = -1;
        long long mod = (m.val + 1LL);
        for(int i = max(2, prev_len); i <= N; ++i){
            memo[i] = memo[i - 1] * i;
            inv[i] = mod - inv[mod % i] * (mod / i);
            memoinv[i] = memoinv[i - 1] * inv[i];
        }
    }

    inline T fact(const int n) {
        init(n);
        return memo[n];
    }
    inline T factinv(const int n) {
        init(n);
        return memoinv[n];
    }
    inline T ncr(const int n, const int r) {
        if(n < r || r < 0) return 0;
        init(n);
        return (memo[n] * memoinv[r]) * memoinv[n - r];
    }
    inline T npr(const int n, const int r) {
        if(n < r || r < 0) return 0;
        init(n);
        return memo[n] * memoinv[n - r];
    }
    // 重複組み合わせ
    inline T nhr(const int n, const int r) {
        if(n == 0 && r == 0) return 1;
        return ncr(n + r - 1, r);
    }
    // ボールの数、一個以上必要な箱の数、制限がない箱の数 (箱区別あり)
    // a = 0 の場合は重複組み合わせ
    inline T choose(const int n, const int a, const int b = 0) {
        if(n == 0) return !a;
        return ncr(n + b - 1, a + b - 1);
    }
    // +1 n 個, -1 m 個, 累積和 >= 0
    inline T cataran(const int n, const int m) {
        return ncr(n + m, n) - ncr(n + m, n - 1);
    }
    // +1 n 個, -1 m 個, 累積和 > -k
    inline T cataran(const int n, const int m, const int k) {
        if(m < k) return ncr(n + m, n);
        if(m < n + k) return ncr(n + m, n) - ncr(n + m, m - k);
        return 0;
    }
    // +1 n 個, -1 m 個, 累積和 < +k
    inline T cataran2(const int n, const int m, const int k) {
        return cataran(m, n, k);
    }
};
