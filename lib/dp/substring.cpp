#include <bits/stdc++.h>

using namespace std;

// |S| における、連続しない部分文字列の種類を m で割った余りを返します。O(|S|)
long long substring(const string &s, long long m){
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