#pragma once

/**
 * @brief Smallest Prime Factor
 * @docs docs/math/prime-factor.md
 */

template <typename T>
struct PrimeFactor{
    vector<T> spf;
    PrimeFactor(T N){ init(N); }
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