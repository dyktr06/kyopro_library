#include <bits/stdc++.h>

using namespace std;

// aからbまでの和をもとめます : O(1)
template <typename T>
long long sum(T a, T b){
    long long res = ((b - a + 1) * (a + b)) / 2;
    return res;
}

// x^nをもとめます : O(logN)
template <typename T>
T intpow(T x, T n){
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x);
        (x *= x);
        n >>= 1;
    }
    return ret;
}

// a を b で割った正のあまりを求めます : O(1)
template <typename T>
T getReminder(T a, T b){
    if(b == 0) return -1;
    if(a >= 0 && b > 0){
        return a % b;
    }else if(a < 0 && b > 0){
        return ((a % b) + b) % b;
    }else if(a >= 0 && b < 0){
        return a % b;
    }else{
        return (abs(b) - abs(a % b)) % b;
    }
}