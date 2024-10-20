#pragma once

int chromaticNumber(vector<vector<int>> &G) {
    int n = G.size();
    vector<int> adj(n);
    for(int i = 0; i < n; i++){
        for(auto &j : G[i]){
            adj[i] |= 1 << j;
        }
    }

    // dp[S] ... S の部分集合で独立なものの個数
    vector<int> dp(1 << n, 0);
    dp[0] = 1;
    for(int S = 1; S < (1 << n); S++){
        int i = __builtin_ctz(S);
        dp[S] = dp[S ^ (1 << i)] + dp[(S ^ (1 << i)) & (~adj[i])];
    }

    // 包除原理 (https://www.slideshare.net/wata_orz/ss-12131479)
    vector<int> cnt((1 << n) + 1, 0);
    for(int S = 0; S < (1 << n); S++){
        cnt[dp[S]] += __builtin_parity(S) ? 1 : -1;
    }

    vector<pair<long long, long long>> f;
    for(int i = 0; i <= (1 << n); i++){
        if(cnt[i] != 0){
            f.emplace_back(i, cnt[i]);
        }
    }

    int ans = n;
    constexpr long long MODS[] = {1000000007, 1000000009, 1000000021};
    for(int i = 0; i < 3; i++){
        auto nf = f;
        for(int k = 1; k <= n; k++){
            if(ans <= k) break;
            // k 彩色する通り数
            long long sum = 0;
            for(auto &[x, y] : nf){
                sum += (y = y * x % MODS[i]);
                sum %= MODS[i];
            }
            if(sum != 0) ans = min(ans, k);
        }
    }
    return ans;
}
