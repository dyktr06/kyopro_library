#pragma once

/**
 * @brief Mod Calculation
 * @docs docs/math/modcalc.md
 */

namespace modcalc{

    template <typename T>
    T modpow(T x, T n, const T &m){
        T ret = 1 % m;
        x %= m;
        while(n > 0){
            if(n & 1) (ret *= x) %= m;
            (x *= x) %= m;
            n >>= 1;
        }
        return ret;
    }

    template <typename T>
    T modinv(T a, T m){
        T b = m, u = 1, v = 0;
        while(b){
            T t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= m;
        if (u < 0) u += m;
        return u;
    }

    template <typename T>
    T modarithmeticsum(T a, T d, T n, T m){
        T m2 = m * 2;
        a %= m2, n %= m2, d %= m2;
        T b = (n - 1) * d % m2;
        return ((n * (a * 2 + b) % m2) / 2) % m;
    }

    template <typename T>
    T modgeometricsum(T a, T r, T n, T m){
        a %= m;
        if(r == 1){
            n %= m;
            return a * n % m;
        }
        return a * (modpow(r, n, m) + m - 1) % m * modinv(r - 1, m) % m;
    }

    template <typename T>
    T modgeometricsum2(T a, T r, T n, T m){
        a %= m;
        if(r == 1){
            n %= m;
            return a * n % m;
        }
        T ret = 0;
        T x = 1 % m;
        T sum = 0;
        for(int i = 0; n > 0; ++i){
            if(n & 1){
                (ret += x * modpow(r, sum, m) % m) %= m;
                sum |= 1LL << i;
            }
            (x += x * modpow(r, 1LL << i, m) % m) %= m;
            n >>= 1;
        }
        return a * ret % m;
    }
}