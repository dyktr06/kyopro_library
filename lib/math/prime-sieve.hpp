#pragma once

/**
 * @brief Prime Sieve (エラトステネスの篩)
 * @docs docs/math/prime-sieve.md
 */

template <typename T>
struct PrimeSieve{
    int n, half;
    vector<bool> sieve;
    vector<T> prime_list;
    // sieve[i] ... 2 * i + 1

    PrimeSieve(T _n) : n(_n){
        init();
    }

    void init(){
        if(n < 2){
            return;
        }
        half = (n + 1) / 2;
        sieve.assign(half, true);
        sieve[0] = false;
        prime_list.emplace_back(2);
        for(long long i = 1; 2 * i + 1 <= n; ++i){
            if(!sieve[i]) continue;
            T p = 2 * i + 1;
            prime_list.emplace_back(p);
            for(long long j = 2 * i * (i + 1); j < half; j += p){
                sieve[j] = false;
            }
        }
    }

    bool isPrime(T x){
        if(x == 2) return true;
        if(x % 2 == 0) return false;
        return sieve[x / 2];
    }

    T getPrimeCount(){
        return prime_list.size();
    }

    T getKthPrime(int k){
        return prime_list[k];
    }
};