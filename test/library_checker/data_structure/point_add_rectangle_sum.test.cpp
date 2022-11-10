#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/dynamic_binary_indexed_tree_2d.hpp"
#include "../../../lib/others/compression.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<int> xl, yl;
    vector<tuple<int, int, int>> point;
    vector<tuple<int, int, int, int, int>> query;
    for(int i = 0; i < n; i++){
        int x, y, w; cin >> x >> y >> w;
        point.emplace_back(x, y, w);
        xl.push_back(x);
        yl.push_back(y);
    }
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 0){
            int x, y, w; cin >> x >> y >> w;
            xl.push_back(x);
            yl.push_back(y);
            query.emplace_back(t, x, y, w, 0);
        }else{
            int l, d, r, u; cin >> l >> d >> r >> u;
            xl.push_back(l);
            xl.push_back(r);
            yl.push_back(d);
            yl.push_back(u);
            query.emplace_back(t, l, d, r, u);
        }
    }
    compress<int> xc(xl), yc(yl);
    DynamicBinaryIndexedTree2D<long long> BIT(xc.size(), yc.size());
    for(int i = 0; i < n; i++){
        auto [x, y, w] = point[i];
        BIT.add(xc.get(x), yc.get(y), w);
    }
    for(int i = 0; i < q; i++){
        auto [t, a, b, c, d] = query[i];
        if(t == 0){
            BIT.add(xc.get(a), yc.get(b), c);
        }else{
            cout << BIT.sum(xc.get(a), yc.get(b), xc.get(c), yc.get(d)) << "\n";
        }
    }
}