#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/segment_tree.hpp"

const long long INF = 0x1fffffffffffffff;

int main(){
    int n, q; cin >> n >> q;
    auto fx = [](long long x1, long long x2) -> long long { return min(x1, x2); };
    long long ex = INF;
    SegTree<long long> rmq(n, fx, ex);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        rmq.update(i, a);
    }
    while(q--){
        int l, r; cin >> l >> r;
        cout << rmq.query(l, r) << "\n";
    }
}