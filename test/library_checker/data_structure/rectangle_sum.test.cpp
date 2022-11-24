#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/range_tree.hpp"

int main(){
    int n, q; cin >> n >> q;
    RangeTree<int, long long> tree;
    vector<int> x(n), y(n);
    vector<long long> w(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> w[i];
        tree.add_point(x[i], y[i]);
    }
    tree.build();
    for(int i = 0; i < n; i++){
        tree.add(x[i], y[i], w[i]);
    }
    while(q--){
        int l, d, r, u; cin >> l >> d >> r >> u;
        cout << tree.sum(l, d, r, u) << "\n";
    }
}