#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/range_tree.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    RangeTree<int, long long> tree;
    vector<tuple<int, int, int>> point;
    vector<tuple<int, int, int, int, int>> query;
    for(int i = 0; i < n; i++){
        int x, y, w; cin >> x >> y >> w;
        point.emplace_back(x, y, w);
        tree.add_point(x, y);
    }
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 0){
            int x, y, w; cin >> x >> y >> w;
            tree.add_point(x, y);
            query.emplace_back(t, x, y, w, 0);
        }else{
            int l, d, r, u; cin >> l >> d >> r >> u;
            query.emplace_back(t, l, d, r, u);
        }
    }
    tree.build();
    for(int i = 0; i < n; i++){
        auto [x, y, w] = point[i];
        tree.add(x, y, w);
    }
    for(int i = 0; i < q; i++){
        auto [t, a, b, c, d] = query[i];
        if(t == 0){
            tree.add(a, b, c);
        }else{
            cout << tree.sum(a, b, c, d) << "\n";
        }
    }
}