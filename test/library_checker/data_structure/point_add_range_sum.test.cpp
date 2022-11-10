#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/binary_indexed_tree.hpp"

int main(){
    int n, q; cin >> n >> q;
    BinaryIndexedTree<long long> BIT(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        BIT.add(i, a);
    }
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int p, x; cin >> p >> x;
            BIT.add(p, x);
        }else{
            int l, r; cin >> l >> r;
            cout << BIT.sum(l, r) << "\n";
        }
    }
}