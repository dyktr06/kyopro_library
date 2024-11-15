#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#include <iostream>

#include "../../../lib/data_structure/weighted_union_find.hpp"

using namespace std;

int main(){
    int n, q; cin >> n >> q;
    WeightedUnionFind<int> tree(n);
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
