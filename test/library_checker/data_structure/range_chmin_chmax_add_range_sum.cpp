#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/segment_tree_beats.hpp"

const long long INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    SegmentTreeBeats<long long, INF> seg(n, a);
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int l, r; long long b; cin >> l >> r >> b;
            seg.query_chmin(l, r, b);
        }else if(t == 1){
            int l, r; long long b; cin >> l >> r >> b;
            seg.query_chmax(l, r, b);
        }else if(t == 2){
            int l, r; long long b; cin >> l >> r >> b;
            seg.query_add(l, r, b);
        }else{
            int l, r; cin >> l >> r;
            cout << seg.query_sum(l, r) << "\n";
        }
    }
}