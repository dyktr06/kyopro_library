#pragma once

/**
 * @brief Divisor Zeta/Mobius Transform
 */

#include <vector>

#include "../math/prime_sieve.hpp"

template <typename T>
void divisor_zeta_transform(std::vector<T> &a){
    int n = a.size() - 1;
    PrimeSieve<int> sieve(n);
    for(int d = 2; d <= n; d++){
        if(sieve.isPrime(d)){
            for(int i = 1; i * d <= n; i++){
                a[i * d] += a[i];
            }
        }
    }
}

template <typename T>
void divisor_reversed_zeta_transform(std::vector<T> &a){
    int n = a.size() - 1;
    PrimeSieve<int> sieve(n);
    for(int d = 2; d <= n; d++){
        if(sieve.isPrime(d)){
            for(int i = n / d; i >= 1; i--){
                a[i] += a[i * d];
            }
        }
    }
}

template <typename T>
void divisor_mobius_transform(std::vector<T> &a){
    int n = a.size() - 1;
    PrimeSieve<int> sieve(n);
    for(int d = 2; d <= n; d++){
        if(sieve.isPrime(d)){
            for(int i = n / d; i >= 1; i--){
                a[i * d] -= a[i];
            }
        }
    }
}

template <typename T>
void divisor_reversed_mobius_transform(std::vector<T> &a){
    int n = a.size() - 1;
    PrimeSieve<int> sieve(n);
    for(int d = 2; d <= n; d++){
        if(sieve.isPrime(d)){
            for(int i = 1; i * d <= n; i++){
                a[i] -= a[i * d];
            }
        }
    }
}
