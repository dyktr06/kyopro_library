#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/union_find.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    using Edge = pair<int, int>;
    vector<Edge> e(m);
    vector<long long> c(m);
    for(int i = 0; i < m; i++){
        cin >> e[i].first >> e[i].second >> c[i];
    }

    vector<pair<long long, int>> sorted(m);
    for(int i = 0; i < m; i++){
        sorted[i] = {c[i], i};
    }
    UnionFind uf(n);
    sort(sorted.begin(), sorted.end());
    long long sum = 0;
    vector<int> ans;
    for(int i = 0; i < m; i++){
        auto [w, idx] = sorted[i];
        auto [u, v] = e[idx];
        if(!uf.same(u, v)){
            ans.push_back(idx);
            sum += w;
            uf.unite(u, v);
        }
    }
    cout << sum << "\n";
    for(int i = 0; i < n - 1; i++){
        if(i >= 1) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}