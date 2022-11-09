#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/mo.hpp"
#include "../../../lib/others/compression.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<int> a;
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
        a.push_back(c[i]);
    }
    Mo mo(n);
    vector<int> x(q);
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r >> x[i];
        mo.add(l, r);
        a.push_back(x[i]);
    }
    compress<int> comp(a);
    vector<int> compressed = comp.getCompressed();
    vector<int> cnt(n + q);
    vector<int> res(q);
    auto add = [&](int i){
        ++cnt[compressed[i]];
    };
    auto erase = [&](int i){
        --cnt[compressed[i]];
    };
    auto output = [&](int q){
        res[q] = cnt[compressed[n + q]];
    };
    mo.build(add, erase, output);
 
    for(auto ans : res){
        cout << ans << "\n";
    }
}