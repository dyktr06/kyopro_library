#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/dynamic_weighted_union_find.hpp"

int main(){
    int n, q; cin >> n >> q;
    DynamicWeightedUnionFind<int> tree;
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int x, y, z; cin >> x >> y >> z;
            tree.unite(x, y, z);
        }else{
            int x, y; cin >> x >> y;
            if(tree.same(x, y)){
                cout << tree.diff(x, y) << "\n";
            }else{
                cout << "?" << "\n";
            }
        }
    }
}