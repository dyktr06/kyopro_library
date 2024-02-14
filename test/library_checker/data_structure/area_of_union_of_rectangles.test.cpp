#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/lazy_segment_tree.hpp"
#include "../../../lib/others/compression.hpp"

const long long INF = 0x1fffffffffffffff;

struct S{
    long long len, mn;
};

struct F{
    long long add;
};

F ID = {0};

S op(S l, S r){
    if(l.mn < r.mn){
        return l;
    }
    if(l.mn > r.mn){
        return r;
    }
    return S{l.len + r.len, l.mn};
}

S e(){
    return S{0, INF};
}

S mapping(F f, S x){
    return S{x.len, x.mn + f.add};
}

F composition(F f, F g){
    return F{f.add + g.add};
}

F id(){
    return ID;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<long long> l(n), d(n), r(n), u(n);
    vector<long long> x, y;
    for(int i = 0; i < n; i++){
        cin >> l[i] >> d[i] >> r[i] >> u[i];
        x.push_back(l[i]);
        x.push_back(r[i]);
        y.push_back(d[i]);
        y.push_back(u[i]);
    }
    compress<long long> xc(x), yc(y);
    int xs = xc.size(), ys = yc.size();
    LazySegTree<S, op, e, F, mapping, composition, id> seg(xs - 1);
    for(int i = 0; i < xs - 1; i++){
        seg.update(i, {xc.inv(i + 1) - xc.inv(i), 0});
    }
    vector<vector<tuple<int, int, int>>> q(ys);
    for(int i = 0; i < n; i++){
        int l_ = xc.compressed[2 * i], r_ = yc.compressed[2 * i + 1];
        q[yc.compressed[2 * i]].emplace_back(l_, r_, 1);
        q[yc.compressed[2 * i + 1]].emplace_back(l_, r_, -1);
    }
    long long ans = 0;
    long long xlen = xc.inv(xs - 1) - xc.inv(0);
    for(int i = 0; i < ys - 1; i++){
        for(auto [l_, r_, w] : q[i]){
            seg.apply(l_, r_, F{w});
        }
        S res = seg.all_query();
        long long t = (res.mn == 0) ? (xlen - res.len) : (xlen); 
        ans += t * (yc.inv(i + 1) - yc.inv(i));
    }
    cout << ans << "\n";
}
