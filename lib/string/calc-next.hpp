#pragma once

/**
 * @brief calc-next
 * @docs docs/string/calc-next.md
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