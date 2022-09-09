#include <bits/stdc++.h>

using namespace std;

// 素数かどうかを判定します(n <= 2^64 なら必ず成功します) : O(logn)
bool rabin_miller(long long n){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: return true;
    }

    if(n % 2 == 0) return false;
    vector<long long> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    long long s = 0, d = n - 1;
    while(d % 2 == 0){
        s++;
        d >>= 1;
    }

    auto modpow = [](__int128_t x, __int128_t e, const __int128_t m) -> __int128_t {
        __int128_t ret = 1 % m;
        x %= m;
        while(e > 0){
            if(e & 1) (ret *= x) %= m;
            (x *= x) %= m;
            e >>= 1;
        }
        return ret;
    };

    for(auto a : A){
        if(a % n == 0) return true;
        long long t, x = modpow(a, d, n);
        if(x != 1){
            for(t = 0; t < s; ++t){
                if (x == n - 1) break;
                x = __int128_t(x) * x % n;
            }
            if(t == s) return false;
        }
    }
    return true;
}

int main(){
    int n; cin >> n;
    while(n--){
        long long x; cin >> x;
        cout << x << " " << 0 + rabin_miller(x) << "\n";
    }
}