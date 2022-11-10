#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/rho.hpp"

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