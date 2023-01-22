#pragma once

/**
 * @brief Chinese Remainder Theorem (中国剰余定理)
 * @docs docs/math/crt.md
 */

namespace CRT{
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
}