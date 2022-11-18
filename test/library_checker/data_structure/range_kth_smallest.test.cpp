#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/mo.hpp"
#include "../../../lib/data_structure/binary_indexed_tree.hpp"
#include "../../../lib/others/compression.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<int> a(n), k(q);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Mo mo(n);
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r >> k[i];
        mo.add(l, r);
    }

    compress<int> comp(a);
    vector<int> compressed = comp.getCompressed();
    vector<long long> res(q);
    BinaryIndexedTree<int> BIT(200000);
    long long now = 0;
    auto add = [&](int i){
        BIT.add(compressed[i], 1);
    };
    auto erase = [&](int i){
        BIT.add(compressed[i], -1);
    };
    auto output = [&](int q){
        int idx = BIT.lower_bound(k[q] + 1);
        res[q] = comp.sorted[idx];
    };
    mo.build(add, erase, output);
 
    for(auto ans : res){
        cout << ans << "\n";
    }
}