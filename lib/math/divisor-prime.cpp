#include <bits/stdc++.h>

using namespace std;

// 約数を昇順にして配列にして出力します : O(√n)
template <typename T>
vector<T> getDivisor(T n){
    T rt = sqrt(n);
    vector<T> res, resB;
    for(T i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            T j = n / i;
            if(j != rt){
                resB.push_back(j);
            }
        }
    }
    for(int i = (int) resB.size() - 1; i >= 0; i--){
        res.push_back(resB[i]);
    }
    return res;
}

// 素数かどうかを判定します : O(√n)
template <typename T>
bool isPrime(T n){
    switch(n) {
        case 0: // fall-through
        case 1: return false;
        case 2: return true;
    }

    if(n % 2 == 0) return false;

    for(T i = 3; i*i <= n; i += 2){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

// N について素因数分解をします : O(√N)
template <typename T>
vector<pair<T, T>> prime_factor(T n) {
    vector<pair<T, T>> ret;
    for (T i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        T tmp = 0;
        while (n % i == 0) {
            tmp++;
            n /= i;
        }
        ret.push_back(make_pair(i, tmp));
    }
    if (n != 1) ret.push_back(make_pair(n, 1));
    return ret;
}

// N について素因数分解をします : 構築: O(NloglogN) 取得: O(logN)
template <typename T>
struct PrimeFact{
    vector<T> spf;
    PrimeFact(T N){ init(N); }
    void init(T N){
        spf.assign(N + 1, 0);
        for(T i = 0; i <= N; i++) spf[i] = i;
        for(T i = 2; i * i <= N; i++) {
            if(spf[i] == i) {
                for(T j = i * i; j <= N; j += i){
                    if(spf[j] == j){
                        spf[j] = i;
                    }
                }
            }
        }
    }

    map<T, T> get(T n){
        map<T, T> m;
        while(n != 1){
            if(m.count(spf[n]) == 0){
                m[spf[n]] = 1;
            }else{
                m[spf[n]]++;
            }
            n /= spf[n];
        }
        return m;
    }
};

// 2からNまでの素因数の個数を返します (エラトステネスのふるい) : O(NloglogN)
template <typename T>
vector<T> getSieve(T n){
    vector<T> c(n+1);
    for(int i = 2; i <= n; i++){
        if(c[i] != 0) continue;
        for(int j = i; j <= n; j += i){
            c[j] += 1;
        }
    }
    return c;
}