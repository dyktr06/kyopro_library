#pragma once

/**
 * @brief Rolling Hash
 * @docs docs/string/rollinghash.md
 */

struct RollingHash{
    vector<unsigned long long> hashed, power;
    const unsigned long long mod = (1uLL << 61) - 1;
	
    unsigned long long mul(unsigned long long a, unsigned long long b) const {
        long long ret = a * b - mod * (unsigned long long)(1.0L / mod * a * b);
        return ret + mod * (ret < 0) - mod * (ret >= (long long) mod);
    }

    RollingHash(const string &s, unsigned base = 10007){
        int siz = (int) s.size();
        hashed.assign(siz + 1, 0);
        power.assign(siz + 1, 0);
        power[0] = 1;
        for(int i = 0; i < siz; i++){
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }

    // [l, r)
    unsigned long long get(int l, int r) const {
        unsigned long long ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if(ret >= mod) ret -= mod;
        return ret;
    }

    unsigned long long connect(unsigned long long h1, unsigned long long h2, int h2len) const {
        unsigned long long ret = mul(h1, power[h2len]) + h2;
        if(ret >= mod) ret -= mod;
        return ret;
    }

    int LCP(const RollingHash &b, int l1, int r1, int l2, int r2){
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while(high - low > 1){
            int mid = (low + high) / 2;
            if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
            else high = mid;
        }
        return low;
    }
};