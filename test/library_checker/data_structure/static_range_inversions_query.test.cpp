#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/mo.hpp"
#include "../../../lib/data_structure/binary_indexed_tree.hpp"
#include "../../../lib/others/compression.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Mo mo(n);
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        mo.add(l, r);
    }

    compress<int> comp(a);
    vector<int> compressed = comp.getCompressed();
    vector<long long> res(q);
    BinaryIndexedTree<int> BIT(100000);
    long long now = 0;
    auto add_left = [&](int i){
        now += BIT.sum(0, compressed[i]);
        BIT.add(compressed[i], 1);
    };
    auto add_right = [&](int i){
        now += BIT.sum(compressed[i] + 1, 100000);
        BIT.add(compressed[i], 1);
    };
    auto erase_left = [&](int i){
        BIT.add(compressed[i], -1);
        now -= BIT.sum(0, compressed[i]);
    };
    auto erase_right = [&](int i){
        BIT.add(compressed[i], -1);
        now -= BIT.sum(compressed[i] + 1, 100000);
    };
    auto output = [&](int q){
        res[q] = now;
    };
    mo.build(add_left, add_right, erase_left, erase_right, output);
 
    for(auto ans : res){
        cout << ans << "\n";
    }
}