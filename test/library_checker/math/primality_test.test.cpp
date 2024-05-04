#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/rho.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        long long n; cin >> n;
        if(Rho::rabin_miller(n)){
            cout << "Yes" << "\n";
        }else{
            cout << "No" << "\n";
        }
    }
}
