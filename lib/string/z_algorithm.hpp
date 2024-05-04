#pragma once

/**
 * @brief Z Algorithm
 * @docs docs/string/z_algorithm.md
 */

template <typename T>
vector<int> z_algorithm(const T &s) {
    int n = s.size();
    vector<int> res(n, 0);
    for(int i = 1, j = 0; i < n; ++i){
        if(i + res[i - j] < j + res[j]){
            res[i] = res[i - j];
        } else{
            res[i] = max(j + res[j] - i, 0);
            while(i + res[i] < n && s[i + res[i]] == s[res[i]]) ++res[i];
            j = i;
        }
    }
    res[0] = n;
    return res;
}
