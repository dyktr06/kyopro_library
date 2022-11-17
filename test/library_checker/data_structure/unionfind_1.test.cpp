#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/dynamic_union_find.hpp"

int main(){
    int n, q; cin >> n >> q;
    DynamicUnionFind<int> tree;
    while(q--){
        int t, u, v; cin >> t >> u >> v;
        if(t == 0){
            tree.unite(u, v);
        }else{
            if(tree.same(u, v)){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        }
    }
}