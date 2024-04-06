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
        while(i - j >= 0 && i + j < (int) s.size() && s[i - j] == s[i + j]){
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

struct PalindromeCheck{
    const string s;
    string t;
    int n;
    vector<int> mana;

    PalindromeCheck(const string &str) : s(str){
        n = s.size();
        t = "$";
        for(int i = 0; i < n; i++){
            t += s[i];
            t += "$";
        }
        mana = manacher(t);
    }

    // [l, r)
    bool isPalindrome(int l, int r) const {
        int mid = l + r;
        return r * 2 - mid - 1 < mana[mid];
    }
};
