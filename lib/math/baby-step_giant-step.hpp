#pragma once

/*
    x^k ≡ y (mod m) となる最小の非負整数 k を求めます : O(√M)
*/

long long babyStepGiantStep(long long x, long long y, long long m){
    auto inv = [](long long a, long long m) -> long long {
        long long b = m, u = 1, v = 0;
        while(b){
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= m;
        if (u < 0) u += m;
        return u;
    };

    if((x %= m) < 0) x += m;
    if((y %= m) < 0) y += m;

    long long offset, g, r = 1 % m;
    for(offset = 0; (g = gcd(x, m)) > 1; ++offset){
        if(y % g){
            if(r == y) return offset;
            return -1;
        }
        y /= g;
        m /= g;
        (r *= (x / g)) %= m;
    }

    if(m == 1) return offset;
    (y *= inv(r, m)) %= m;
    
    unordered_map<long long, long long> mp;
    // Baby Step
    long long z = 1, sq = sqrtl(m) + 1;
    for(int i = 0; i < sq; i++){
        mp[z] = i;
        if(mp.count(y) != 0) return offset + mp[y];
        z *= x;
        z %= m;
    }

    // Giant Step
    long long u = inv(z, m);
    for(int i = 1; i <= sq; i++){
        (y *= u) %= m;
        if(mp.count(y) != 0) return offset + mp[y] + i * sq;
    }
    return -1;
}