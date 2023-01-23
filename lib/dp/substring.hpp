#pragma once

/**
 * @brief Count Substrings
 * @docs docs/dp/substring.md
 */

long long substrings(const string &s, const long long &m){
    int n = (int) s.size();

    vector<vector<int>> next(n + 1, vector<int>(26, n));
    for(int i = n - 1; i >= 0; i--){
        next[i] = next[i + 1];
        next[i][s[i] - 'a'] = i;
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 26; ++j){
            if(next[i][j] >= n) continue;
            dp[next[i][j] + 1] += dp[i];
            dp[next[i][j] + 1] %= m;
        }
    }

    long long res = 0;
    for(int i = 0; i <= n; ++i){
        res += dp[i]; res %= m;
    }
    return res;
}

template <typename T>
long long subsequences(const vector<T> &s, const long long &m){
    int n = (int) s.size();
    map<T, int> mp;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        if(mp.count(s[i]) != 0){
            dp[i + 1] = dp[i] * 2 + m - dp[mp[s[i]]];
        }else{
            dp[i + 1] = dp[i] * 2;
        }
        dp[i + 1] %= m;
        mp[s[i]] = i; 
    }
    return dp[n];
}