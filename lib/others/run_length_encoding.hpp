#pragma once

template <typename T>
vector<pair<T, int>> runLengthEncoding(const vector<T> &a){
    vector<pair<T, int>> res;
    int n = a.size();
    for(int i = 0; i < n; ++i){
        if(res.empty() || res.back().first != a[i]){
            res.emplace_back(a[i], 1);
        } else{
            res.back().second++;
        }
    }
    return res;
}
