#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_frequency"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/range_tree.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> c(n);
    vector<tuple<int, int, int, int>> query(q);
    RangeTree<int, int> tree;
    for(int i = 0; i < n; i++){
        cin >> c[i];
        tree.add_point(i, c[i]);
    }
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 0){
            int k, x; cin >> k >> x;
            query[i] = {t, k, x, 0};
            tree.add_point(k, x);
        }else{
            int l, r, x; cin >> l >> r >> x;
            query[i] = {t, l, r, x};
        }
    }
    tree.build();
    for(int i = 0; i < n; i++){
        tree.add(i, c[i], 1);
    }
    for(int i = 0; i < q; i++){
        auto [t, x, y, z] = query[i];
        if(t == 0){
            tree.add(x, c[x], -1);
            tree.add(x, y, 1);
            c[x] = y;
        }else{
            cout << tree.sum(x, z, y, z + 1) << "\n";
        }
    }
}
