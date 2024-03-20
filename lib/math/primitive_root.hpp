#pragma once

/**
 * @brief Primitive Root (原子根)
 * @docs docs/math/primitive_root.md
 */

#include "../math/rho.hpp"
#include "../others/random.hpp"

long long primitiveRoot(long long p){
    auto modpow = [](__int128_t x, long long n, const long long &m){
        __int128_t ret = 1 % m;
        x %= m;
        while(n > 0){
            if(n & 1) (ret *= x) %= m;
            (x *= x) %= m;
            n >>= 1;
        }
        return ret;
    };

    RandomNumber rnd(1, p - 1);
    vector<unsigned long long> f = Rho::factorize(p - 1);
    while(true){
        long long a = rnd.get();
        bool is_ok = true;
        for(auto x : f){
            if(modpow(a, (p - 1) / x, p) == 1){
                is_ok = false;
                break;
            }
        }
        if(is_ok){
            return a;
        }
    }
}