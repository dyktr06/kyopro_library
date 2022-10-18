#include <bits/stdc++.h>

using namespace std;

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

// 配列 a の xor 基底を求めます。
template <typename T>
pair<vector<T>, vector<T>> getBasis(vector<T> a){
    vector<T> basis, original;
    for(auto x : a){
        T y = x;
        for(auto z : basis){
            y = min(y, y ^ z);
        }
        if(y > 0){
            basis.push_back(y);
            original.push_back(x);
        }
    }
    return {basis, original};
}