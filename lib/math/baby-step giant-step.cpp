#include <bits/stdc++.h>

using namespace std;

// x^k ≡ y (mod m) となる最小の k を求めます : O(√M log M)
long long BabyStepGiantStep(long long x, long long y, long long m){
    map<long long, long long> mp;

    // Baby Step
    long long z = 1, sq = sqrtl(m) + 1;
    for(int i = 0; i < sq; i++){
        z *= x;
        z %= m;
        mp[z] = i + 1;
        if(mp.count(y) != 0) return mp[y];
    }

    // Giant Step
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = z / b;
        z -= t * b; swap(z, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;

    for(int i = 1; i <= sq; i++){
        y *= u;
        y %= m;
        if(mp.count(y) != 0) return mp[y] + i * sq;
    }
    return -1;
}