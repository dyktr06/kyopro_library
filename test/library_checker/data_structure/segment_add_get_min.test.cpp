#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/dynamic_li_chao_tree.hpp"

const long long INF = 0x1fffffffffffffff;

int main(){
    int n, q; cin >> n >> q;
    const long long P = 1e9;
    DynamicLiChaoTree<long long, -P, P, INF> lct;
    for(int i = 0; i < n; i++){
        long long l, r, a, b; cin >> l >> r >> a >> b;
        lct.add_segment(l, r, a, b);
    }
    while(q--){
        int t; cin >> t;
        if(t == 0){
            long long l, r, a, b; cin >> l >> r >> a >> b;
            lct.add_segment(l, r, a, b);
        }else{
            long long p; cin >> p;
            long long res = lct.query(p);
            if(res == INF) cout << "INFINITY" << "\n";
            else cout << res << "\n";
        }
    }
}