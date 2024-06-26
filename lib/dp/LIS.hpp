#pragma once

/**
 * @brief Longest Increasing Subsequence
 * @docs docs/dp/LIS.md
 */

template <typename T>
int LIS(vector<T> a, bool is_strong = true){
    const long long INF = 0x1fffffffffffffff;
    int n = (int) a.size();
    vector<long long> dp(n, INF);
    for(int i = 0; i < n; ++i){
        if(is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

template <typename T>
vector<int> construct_LIS(vector<T> a, bool is_strong = true){
    const long long INF = 0x1fffffffffffffff;
    int n = (int) a.size();
    vector<long long> dp(n, INF);
    vector<vector<int>> idx(n);
    for(int i = 0; i < n; ++i){
        if(is_strong){
            auto iter = lower_bound(dp.begin(), dp.end(), a[i]);
            *iter = a[i];
            idx[(int) (iter - dp.begin())].emplace_back(i);
        } else{
            auto iter = upper_bound(dp.begin(), dp.end(), a[i]);
            *iter = a[i];
            idx[(int) (iter - dp.begin())].emplace_back(i);
        }
    }
    int k = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
    vector<int> res;
    int now = n;
    for(int i = k - 1; i >= 0; --i){
        auto iter = upper_bound(idx[i].begin(), idx[i].end(), now);
        iter--;
        now = *iter;
        res.push_back(now);
    }
    reverse(res.begin(), res.end());
    return res;
}
