#pragma once

/**
 * @brief Lyndon Factorization
 * @docs docs/string/lyndon_factorization.md
 * @see https://qiita.com/nakashi18/items/66882bd6e0127174267a
 */

template <typename T>
vector<int> lyndon_factorization(const T &s){
    int n = s.size();
    vector<int> ans = {0};
    int l = 0;
    while(l < n){
        // [l, ?) の最長の Lyndon 文字列を見つける
        int i = l, j = l + 1;
        while(s[i] <= s[j] && j < n){
            if(s[i] == s[j]) i++;
            else i = l;
            j++;
        }
        // (j - i) が周期で、[l, j) がその周期の繰り返し
        int repet = (j - l) / (j - i);
        for(int d = 0; d < repet; d++){
            l += j - i;
            ans.push_back(l);
        }
    }
    return ans;
}
