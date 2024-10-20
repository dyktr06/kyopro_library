#pragma once

namespace MathTable{
    // トーシェント関数
    template <typename T>
    vector<T> totient_table(T n){
        vector<T> r(n + 1);
        for(int i = 0; i <= n; i++){
            r[i] = i;
        }
        for(int i = 2; i <= n; i++){
            if(r[i] != i) continue;
            for(int j = i; j <= n; j += i){
                r[j] -= r[j] / i;
            }
        }
        return r;
    }

    // 素因数の個数
    template <typename T>
    vector<T> prime_factor_table(T n){
        vector<T> c(n + 1);
        for(int i = 2; i <= n; i++){
            if(c[i] != 0) continue;
            for(int j = i; j <= n; j += i){
                c[j] += 1;
            }
        }
        return c;
    }

    // 約数
    template <typename T>
    vector<vector<T>> divisor_table(T n){
        vector<vector<T>> div(n + 1);
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j += i){
                div[j].push_back(i);
            }
        }
    }

    // 累乗
    template <typename T>
    vector<T> power_table(int n, T p){
        vector<T> power(n + 1);
        power[0] = (T) 1;
        for(int i = 1; i <= n; i++){
            power[i] = power[i - 1] * p;
        }
        return power;
    }
}
