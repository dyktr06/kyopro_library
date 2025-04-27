#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"

#include <iostream>

#include "../../../lib/data_structure/dynamic_segment_tree.hpp"
#include "../../../lib/math/modint.hpp"

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    DynamicSegTree<F, op, e> seg(n);
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 0){
            int p, c, d; cin >> p >> c >> d;
            seg.update(p, {c, d});
        }else{
            int l, r;
            mint x;
            cin >> l >> r >> x;
            F res = seg.query(l, r);
            cout << res.first * x + res.second << "\n";
        }
    }
}
