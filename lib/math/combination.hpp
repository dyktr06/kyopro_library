#pragma once

/**
 * @brief Combination (二項係数)
 * @docs docs/math/combination.md
 */

struct Combination{
    vector<long long> memo, memoinv, inv;
    const long long mod;
    Combination(const int &N, const long long &m) : memo(N + 1), memoinv(N + 1), inv(N + 1), mod(m){
        memo[0] = memo[1] = 1;
        memoinv[0] = memoinv[1] = 1;
        inv[1] = 1;
        for(int i = 2; i <= N; ++i){
            memo[i] = memo[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (m / i) % mod;
            memoinv[i] = memoinv[i - 1] * inv[i] % mod;
        }
    }
    inline long long fact(const long long &n) const {
        return memo[n];
    }
    inline long long factinv(const long long &n) const {
        return memoinv[n];
    }
    inline long long ncr(const long long &n, const long long &r) const {
        if(n < r || r < 0) return 0;
        return (memo[n] * memoinv[r] % mod) * memoinv[n - r] % mod;
    }
    inline long long npr(const long long &n, const long long &r) const {
        if(n < r || r < 0) return 0;
        return (memo[n] % mod) * memoinv[n - r] % mod;
    }
    inline long long nhr(const long long &n, const long long &r) const {
        if(n == 0 && r == 0) return 1;
        return ncr(n + r - 1, r);
    }
};

struct CombinationByPascal{
    vector<vector<long long>> memo;
    const long long mod;
    CombinationByPascal(const int &N, const long long &m) : mod(m){
        memo.assign(N + 1, vector<long long>(N + 1));
        memo[0][0] = 1;
        for(int i = 1; i <= N; ++i){
            memo[i][0] = 1;
            for(int j = 1; j <= N; ++j){
                memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j]);
                if(memo[i][j] >= mod) memo[i][j] -= mod;
            }
        }
    }
    inline long long ncr(const int &n, const int &r) const {
        if(n < r || r < 0) return 0;
        return memo[n][r];
    }
};
