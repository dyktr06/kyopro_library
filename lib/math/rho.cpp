#include <bits/stdc++.h>

using namespace std;

namespace Rho{
    unsigned long long mul(unsigned long long a, unsigned long long b, const unsigned long long mod) {
        long long ret = a * b - mod * (unsigned long long)(1.0L / mod * a * b);
        return ret + mod * (ret < 0) - mod * (ret >= (long long) mod);
    }

    bool rabin_miller(unsigned long long n){
        switch(n){
            case 0: // fall-through
            case 1: return false;
            case 2: return true;
        }

        if(n % 2 == 0) return false;
        vector<long long> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
        unsigned long long s = 0, d = n - 1;
        while(d % 2 == 0){
            s++;
            d >>= 1;
        }

        auto modpow = [](unsigned long long x, unsigned long long e, const unsigned long long mod) -> unsigned long long {
            unsigned long long ret = 1 % mod;
            x %= mod;
            while(e > 0){
                if(e & 1) ret = mul(ret, x, mod);
                x = mul(x, x, mod);
                e >>= 1;
            }
            return ret;
        };

        for(auto a : A){
            if(a % n == 0) return true;
            unsigned long long t, x = modpow(a, d, n);
            if(x != 1){
                for(t = 0; t < s; ++t){
                    if(x == n - 1) break;
                    x = mul(x, x, n);
                }
                if(t == s) return false;
            }
        }
        return true;
    }

    mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
    unsigned long long FindFactor(unsigned long long n) {
        if(n == 1 || rabin_miller(n)) return n;
        if(n % 2 == 0) return 2;
        unsigned long long c = 1, x = 0, y = 0, t = 0, prod = 2, x0 = 1, q;
        auto f = [&](unsigned long long X) { return mul(X, X, n) + c;};

        while (t++ % 128 or __gcd(prod, n) == 1) {
            if(x == y) c = rng() % (n-1) + 1, x = x0, y = f(x);
            if((q = mul(prod, max(x, y) - min(x, y), n))) prod = q;
            x = f(x), y = f(f(y));
        }
        return __gcd(prod, n);
    }

    vector<unsigned long long> factorize(unsigned long long x) {
        if(x == 1) return {};
        unsigned long long a = FindFactor(x), b = x / a;
        if(a == x) return {a};
        vector<unsigned long long> L = factorize(a), R = factorize(b);
        L.insert(L.end(), R.begin(), R.end());
        return L;
    }

    vector<unsigned long long> divisor(unsigned long long x){
        vector<unsigned long long> factor = Rho::factorize(x);
        map<unsigned long long, int> countFactor;
        for(auto x : factor){
            if(countFactor.count(x) == 0) countFactor[x] = 0;
            countFactor[x]++;
        }
        vector<unsigned long long> ret = {1};
        for(auto [x, cnt] : countFactor){
            vector<unsigned long long> tmp;
            for(auto y : ret){
                unsigned long long z = y;
                for(int i = 0; i < cnt + 1; i++){
                    tmp.push_back(z);
                    z *= x;
                }
            }
            ret = tmp;
        }
        return ret;
    }
}

// example (Factorize (Library Checker))
int main(){
    int q; cin >> q;
    while(q--){
        long long a; cin >> a;
        vector<unsigned long> factor = Rho::factorize(a);
        sort(factor.begin(), factor.end());
        int n = factor.size();
        cout << n;
        for(int i = 0; i < n; i++){
            cout << " " << factor[i];
        }
        cout << "\n";
    }
}