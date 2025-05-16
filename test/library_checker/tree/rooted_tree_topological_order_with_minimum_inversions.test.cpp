#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions"
#include <iostream>

#include "../../../lib/graph/rooted_tree_topological_order_with_minimum_inversions.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> par(n, -1);
    vector<long long> c(n), d(n);
    for(int i = 1; i < n; ++i){
        cin >> par[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> d[i];
    }
    auto [x, p] = rootedTreeTopologicalOrderWithMinimumInversions(par, c, d);
    cout << x << "\n";
    for(int i = 0; i < n; ++i){
        cout << p[i] << " \n"[i == n - 1];
    }
}
