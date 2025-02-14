#pragma once

/**
 * @brief Binary GCD
 */

template <typename T>
T binary_gcd(T a, T b) {
    unsigned long long x = a < 0 ? -a : a, y = b < 0 ? -b : b;
    if(!x || !y) return x + y;
    int n = __builtin_ctzll(x), m = __builtin_ctzll(y);
    x >>= n, y >>= m;
    while(x != y){
        if(x > y){
            x = (x - y) >> __builtin_ctzll(x - y);
        } else{
            y = (y - x) >> __builtin_ctzll(y - x);
        }
    }
    return x << (n > m ? m : n);
}
