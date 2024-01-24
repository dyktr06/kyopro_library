#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/primitive_root.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while(q--){
        long long p; cin >> p;
        cout << primitiveRoot(p) << "\n";
    }
}