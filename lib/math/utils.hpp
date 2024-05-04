#pragma once

// aからbまでの和をもとめます : O(1)
template <typename T>
long long sum(T a, T b){
    long long res = ((b - a + 1) * (a + b)) / 2;
    return res;
}

// x^nをもとめます : O(logN)
template <typename T>
T intpow(T x, int n){
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x);
        (x *= x);
        n >>= 1;
    }
    return ret;
}

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

// a を b で割った正のあまりを求めます : O(1)
template <typename T>
T getReminder(T a, T b){
    if(b == 0) return -1;
    if(a >= 0 && b > 0){
        return a % b;
    } else if(a < 0 && b > 0){
        return ((a % b) + b) % b;
    } else if(a >= 0 && b < 0){
        return a % b;
    } else{
        return (abs(b) - abs(a % b)) % b;
    }
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
