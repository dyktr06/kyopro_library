#pragma once

/**
 * @brief Chinese Remainder Theorem (中国剰余定理)
 * @docs docs/math/crt.md
 */

namespace CRT{
    inline long long mod(long long a, long long m){
        return (a % m + m) % m;
    }

    long long extGCD(long long a, long long b, long long &x, long long &y){
        if(b == 0){
            x = 1;
            y = 0;
            return a;
        }
        long long d = extGCD(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }

    pair<long long, long long> chineseRem(const vector<long long> &b, const vector<long long> &m) {
        long long r = 0, M = 1;
        for(int i = 0; i < (int) b.size(); i++){
            long long p, q;
            long long d = extGCD(M, m[i], p, q);
            if((b[i] - r) % d != 0) return {0, -1};
            long long tmp = (b[i] - r) / d * p % (m[i] / d);
            r += M * tmp;
            M *= m[i] / d;
        }
        r %= M;
        if(r < 0) r += M;
        return {r, M};
    }

    // not coprime
    long long preGarner(vector<long long> &b, vector<long long> &m, const long long MOD){
        long long res = 1;
        int n = b.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                long long g = gcd(m[i], m[j]);
                if((b[i] - b[j]) % g != 0) return -1;
                m[i] /= g, m[j] /= g;
                // gcd の分だけ被ってるので振り分ける
                long long gi = gcd(m[i], g), gj = g / gi;
                do{
                    g = gcd(gi, gj);
                    gi *= g, gj /= g;
                }while(g != 1);
                m[i] *= gi, m[j] *= gj;
                b[i] %= m[i], b[j] %= m[j];
            }
        }
        for(auto x : m) (res *= x) %= MOD;
        return res;
    }

    long long garner(const vector<long long> &b, const vector<long long> &m, const long long MOD){
        vector<long long> tm = m;
        tm.push_back(MOD);
        auto inv = [&](long long a, long long m) -> long long {
            long long x, y;
            extGCD(a, m, x, y);
            return mod(x, m);
        };
        int n = b.size();
        vector<long long> coeffs(n + 1, 1), constants(n + 1, 0);
        for(int i = 0; i < n; i++){
            // solve "coeffs[i] * t[i] + constants[i] = b[i] (mod. m[i])
            long long t = mod((b[i] - constants[i]) * inv(coeffs[i], tm[i]), tm[i]);
            for(int j = i + 1; j < n + 1; j++){
                (constants[j] += t * coeffs[j]) %= tm[j];
                (coeffs[j] *= tm[i]) %= tm[j];
            }
        }
        return constants[n];
    }
}
