#pragma once

/**
 * @brief Exhaustive Search (bit 全探索)
 * @docs docs/others/exhaustive_search.md
 */

template<typename T>
vector<long long> sum_subsets(T a){
    vector<long long> res;
    int n = a.size();
    for(int bit = 0; bit < (1 << n); bit++){
        long long sum = 0;
        for(int i = 0; i < n; i++){
            int mask = 1 << i;
            if(bit & mask){
                sum += a[i];
            }
        }
        res.emplace_back(sum);
    }
    return res;
}