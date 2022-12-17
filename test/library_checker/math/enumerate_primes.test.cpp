#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/prime-sieve.hpp"

int main(){
    int n, a, b; cin >> n >> a >> b;
    PrimeSieve<int> s(n);
    int cnt = s.getPrimeCount();
    vector<int> res;
    for(int i = b; i < cnt; i += a){
        res.push_back(s.getKthPrime(i));
    }
    int cnt2 = res.size();
    cout << cnt << " " << cnt2 << "\n";
    for(int i = 0; i < cnt2; i++){
        if(i >= 1) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}