#pragma once

#include "../enumerative_combinatorics/combination_modint.hpp"

template <typename T>
T pow_sum(long long n, long long k){
    long long d = k + 1;
    vector<vector<T>> f(d + 1, vector<T>(2));
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < d + 1; i++){
            if(i > 0 && j == 0){
                f[i][0] = i;
                f[i][0] = f[i][0].pow(k);
            }
            if(i > 0 && j > 0){
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
    }

    Combination<T> comb;
    vector<T> l(d + 1, 1), r(d + 1, 1);
    for(int i = 0; i < d; i++){
        l[i + 1] = l[i] * (n - i);
        r[i + 1] = r[i] * (n - (d - i));
    }
    T ans = 0;
    for(int i = 0; i < d + 1; i++){
        T s = f[i][1];
        // mul(n - x_j) (j != i)
        s *= l[i];
        s *= r[d - i];
        // i! * (d - i)! * (-1)^{d - i}
        s *= comb.factinv(i);
        s *= comb.factinv(d - i);
        if((d - i) % 2) s *= -1;
        ans += s;
    }
    return ans;
}
