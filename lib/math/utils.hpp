#pragma once

// 初項 a, 公差 d, 項数 n の等差数列の和を計算します : O(1)
template <typename T>
T arithmeticsum(T a, T d, T n){
    return n * (a * 2 + (n - 1) * d) / 2;
}

// 初項 a, 公比 r, 項数 n の等比数列の和を計算します : O(1)
template <typename T>
T geometricsum(T a, T r, T n){
    if(r == 1){
        return a * n;
    }
    return a * (intpow(r, n) - 1) / (r - 1);
}

// x の部分集合を列挙します。
template <typename T>
vector<T> getSubmask(T x){
    vector<T> submask;
    for(T i = x; ; i = (i - 1) & x){
        submask.push_back(i);
        if(i == 0) break;
    }
    sort(submask.begin(), submask.end());
    return submask;
}
