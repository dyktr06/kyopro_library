#pragma once

// 座標圧縮した配列を返します(0-indexed) : O(NlogN)
template <typename T>
T compression(T vec){
    int n = vec.size();
    T tmp = vec;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    T res(n);
    for(int i = 0; i < n; i++){
        res[i] = lower_bound(tmp.begin(), tmp.end(), vec[i]) - tmp.begin();
    }
    return res;
}
