#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/others/compression.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    using T = tuple<int, long long, long long>;
    vector<T> query(q);
    vector<long long> x(q);
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        long long k = -1, v = -1;
        if(t == 0){
            cin >> k >> v;
        }else{
            cin >> k;
        }
        query[i] = {t, k, v};
        x[i] = k;
    }
    compress<long long> cp(x);
    vector<long long> a(cp.size(), 0);
    for(int i = 0; i < q; i++){
        auto [t, k, v] = query[i];
        if(t == 0){
            a[cp.get(k)] = v;
        }else{
            cout << a[cp.get(k)] << "\n";
        }
    }
}
