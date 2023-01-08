#pragma once

/**
 * @brief Manacher
 * @docs docs/string/manacher.md
 */

template <typename T>
vector<int> manacher(const T &s){
    int n = s.size();
    vector<int> rad(n);
    int i = 0, j = 0;
    while(i < n){
        while(i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]){
            j++;
        }
        rad[i] = j;
        int k = 1;
        while(i - k >= 0 && i + k < n && k + rad[i - k] < j){
            rad[i + k] = rad[i - k];
            k++;
        }
        i += k;
        j -= k;
    }
    return rad;
}