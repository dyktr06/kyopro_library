#pragma once

// 文字列 s と文字列 t の最長共通部分列を求めます : O(|s||t|)
string LCS(const string &s, const string &t){
    int n = s.size(), m = t.size();
    vector<vector<int>> memo(n + 1, vector<int>(m + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i] == t[j]){
                memo[i + 1][j + 1] = memo[i][j] + 1;
            }else{
                memo[i + 1][j + 1] = max(memo[i][j + 1], memo[i + 1][j]);
            }
        }
    }

    // 復元
    string res = "";
    int i = n - 1, j = m - 1;
    while(0 <= i && 0 <= j){
        if(s[i] == t[j]){
            res += s[i];
            i--; j--;
        }else if(memo[i + 1][j + 1] == memo[i][j + 1]){
            i--;
        }else if(memo[i + 1][j + 1] == memo[i + 1][j]){
            j--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}