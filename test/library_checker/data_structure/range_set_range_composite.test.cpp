#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/math/modint.hpp"
#include "../../../lib/data_structure/lazy_segment_tree.hpp"

using mint = ModInt<998244353>;

struct S{
    mint a, b;
    long long size;
};

struct F{
    mint a, b;
    bool id = false;
};

F ID = {1, 0, true};

S op(S l, S r){
    return{l.a * r.a, r.a * l.b + r.b, l.size + r.size};
}

S e(){
    return S{1, 0};
}

S mapping(F f, S x){
    if(f.id){
        return x;
    }
    auto spow = [](S a, long long n){
        S ret = {1, 0, 0};
        while(n > 0){
            if(n & 1) ret = op(ret, a);
            a = op(a, a);
            n >>= 1;
        }
        return ret;
    };
    S pr = spow(S{f.a, f.b, 0}, x.size);
    return S{pr.a, pr.b, x.size};
}

F composition(F f, F g){
    if(f.id){
        return g;
    }
    return f;
}

F id(){
    return ID;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<S> p(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        p[i] = S{a, b, 1};
    }
    LazySegTree<S, op, e, F, mapping, composition, id> seg(p);
    while(q--){
        int t;
        cin >> t;
        if(t == 0){
            int l, r, c, d;
            cin >> l >> r >> c >> d;
            seg.apply(l, r, F{c, d, false});
        } else{
            int l, r;
            mint x;
            cin >> l >> r >> x;
            S pr = seg.query(l, r);
            cout << pr.a * x + pr.b << "\n";
        }
    }
}