#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/modint.hpp"
#include "../../../lib/data_structure/lazy_segment_tree.hpp"

using mint = ModInt<998244353>;

struct S{
    mint a;
    int size;
};

struct F{
    mint a, b;
};

S op(S l, S r){ return S{l.a + r.a, l.size + r.size}; }

S e(){ return S{0, 0}; }

S mapping(F l, S r){ return S{r.a * l.a + r.size * l.b, r.size}; }

F composition(F l, F r){ return F{r.a * l.a, r.b * l.a + l.b}; }

F id(){ return F{1, 0}; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<S> a(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = {x, 1};
    }
    LazySegTree<S, op, e, F, mapping, composition, id> seg(a);
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int l, r, b, c; cin >> l >> r >> b >> c;
            seg.apply(l, r, F{b, c});
        } else{
            int i; cin >> i;
            cout << seg.get(i).a << "\n";
        }
    }
}