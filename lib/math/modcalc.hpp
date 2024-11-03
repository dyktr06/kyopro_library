#pragma once

/**
 * @brief Mod Calculation
 * @docs docs/math/modcalc.md
 */

namespace modcalc{
    using i64 = long long;

    i64 modpow(i64 x, i64 n, const i64 &m){
        i64 ret = 1 % m;
        x %= m;
        while(n > 0){
            if(n & 1) (ret *= x) %= m;
            (x *= x) %= m;
            n >>= 1;
        }
        return ret;
    }

    i64 modinv(i64 a, const i64 m){
        i64 b = m, u = 1, v = 0;
        while(b){
            i64 t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        u %= m;
        if(u < 0) u += m;
        return u;
    }

    i64 modarithmeticsum(i64 a, i64 d, i64 n, const i64 m){
        i64 m2 = m * 2;
        a %= m2, n %= m2, d %= m2;
        i64 b = (n + m2 - 1) * d % m2;
        return ((n * (a * 2 + b) % m2) / 2) % m;
    }

    i64 modgeometricsum(i64 a, i64 r, i64 n, const i64 m){
        a %= m;
        if(r == 1){
            n %= m;
            return a * n % m;
        }
        return a * (modpow(r, n, m) + m - 1) % m * modinv(r - 1, m) % m;
    }

    i64 modgeometricsum2(i64 a, i64 r, i64 n, const i64 m){
        a %= m;
        if(r == 1){
            n %= m;
            return a * n % m;
        }
        i64 ret = 0;
        i64 x = 1 % m;
        i64 sum = 0;
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

    // https://37zigen.com/tonelli-shanks-algorithm/
    i64 modsqrt(i64 a, const i64 p){
        a %= p;
        if(a <= 1) return a;
        // オイラーの規準
        if(modpow(a, (p - 1) / 2, p) != 1) return -1;
        i64 b = 1;
        while(modpow(b, (p - 1) / 2, p) == 1) b++;
        // p - 1 = m 2^e
        i64 m = p - 1, e = 0;
        while(m % 2 == 0) m >>= 1, e++;
        // x = a^((m + 1) / 2) (mod p)
        i64 x = modpow(a, (m - 1) / 2, p);
        // y = a^{-1} x^2 (mod p)
        i64 y = a * x % p * x % p;
        (x *= a) %= p;
        i64 z = modpow(b, m, p);
        while(y != 1){
            i64 j = 0, t = y;
            while(t != 1){
                (t *= t) %= p;
                j++;
            }
            // e - j ビット目が 1
            z = modpow(z, 1LL << (e - j - 1), p);
            (x *= z) %= p;
            (z *= z) %= p;
            (y *= z) %= p;
            e = j;
        }
        return x;
    }
}
