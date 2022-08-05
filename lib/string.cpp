#include <bits/stdc++.h>

using namespace std;

// 文字列 s において、ある地点からある文字が次にどの地点に出てくるかを計算します。: O(|S|)
vector<vector<int>> calc_next(const string &s) {
    int n = (int) s.size();

    vector<vector<int>> res(n + 1, vector<int>(26, n));

    for(int i = n - 1; i >= 0; i--){
        res[i] = res[i + 1];

        res[i][s[i] - 'a'] = i;
    }
    return res;
}