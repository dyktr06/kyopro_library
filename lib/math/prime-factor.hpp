#pragma once

/**
 * @brief Smallest Prime Factor
 * @docs docs/math/prime-factor.md
 */

#include <vector>

template <typename T>
struct PrimeFactor{
    std::vector<T> spf;
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

    std::vector<T> get(T n){
        std::vector<T> res;
        while(n != 1){
            res.push_back(spf[n]);
            n /= spf[n];
        }
        return res;
    }

    std::vector<std::pair<T, int>> getPair(T n){
        std::vector<std::pair<T, int>> res;
        while(n != 1){
            T p = spf[n];
            int cnt = 0;
            while(n % p == 0){
                n /= p;
                cnt++;
            }
            res.push_back({p, cnt});
        }
        return res;
    }
};
