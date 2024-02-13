#pragma once

/**
 * @brief calc-next
 * @docs docs/string/calc_next.md
 */

vector<vector<int>> calc_next(const string &s) {
    int n = (int) s.size();

    vector<vector<int>> res(n + 1, vector<int>(26, n));

    for(int i = n - 1; i >= 0; i--){
        res[i] = res[i + 1];
        res[i][s[i] - 'a'] = i;
    }
    return res;
}

vector<vector<int>> calc_prev(const string &s) {
    int n = (int) s.size();

    vector<vector<int>> res(n + 1, vector<int>(26, -1));

    for(int i = 0; i < n; i++){
        if(i >= 1) res[i] = res[i - 1];
        res[i][s[i] - 'a'] = i;
    }
    return res;
}