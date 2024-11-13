#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"

#include <iostream>
#include <vector>
#include <tuple>

#include "../../../lib/data_structure/segment_tree_func.hpp"
#include "../../../lib/math/modint.hpp"
#include "../../../lib/others/compression.hpp"

using namespace std;

using mint = ModInt<998244353>;
using F = pair<mint, mint>;

F op(F a, F b){
    return {a.first * b.first, a.second * b.first + b.second};
}

F e(){
    return {1, 0};
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    using T = tuple<int, int, int, int>;
    vector<T> query(q);
    vector<int> c;
    for(int i = 0; i < q; i++){
        int t, x, y, z; cin >> t >> x >> y >> z;
        query[i] = {t, x, y, z};
        if(t == 0){
            c.push_back(x);
        }else{
            c.push_back(x);
            c.push_back(y);
        }
    }
    compress<int> comp(c);
    SegTree<F, op, e> seg(comp.size());
    for(int i = 0; i < q; i++){
        auto [t, x, y, z] = query[i];
        if(t == 0){
            seg.update(comp.get(x), {y, z});
        }else{
            F res = seg.query(comp.get(x), comp.get(y));
            cout << res.first * z + res.second << "\n";
        }
    }
}
