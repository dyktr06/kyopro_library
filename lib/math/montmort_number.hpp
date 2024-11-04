#pragma once

/**
 * @brief Montmort Number (モンモール数)
 */

#include <vector>
#include <cassert>

std::vector<long long> montmortNumber(const int n, const int m){
    // n 番目に置く値は 1 - n - 1
    // i を置いたとして、i 番目が n かどうかで場合分け
    // i 番目が n -> dp_{n - 2} 通り
    // i 番目が n でない -> dp_{n - 1} 通り
    // dp_n = (n - 1) * (dp_{n - 1} + dp_{n - 2}) を得る
    assert(n >= 1);
    if(n == 1) return {0, 1 % m};
    std::vector<long long> dp(n + 1);
    dp[1] = 0;
    dp[2] = 1 % m;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
        (dp[i] *= i - 1) %= m;
    }
    return dp;
}
