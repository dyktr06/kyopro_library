#define PROBLEM "https://yukicoder.me/problems/no/901"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/graph/auxiliary_tree.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    AuxiliaryTree G(n);
    vector<int> u(n - 1), v(n - 1), w(n - 1);
    for(int i = 0; i < n - 1; i++){
        cin >> u[i] >> v[i] >> w[i];
        G.add_edge(u[i], v[i]);
    }
    G.build();

    vector<long long> a(n);
    for(int i = 0; i < n - 1; i++){
        int idx = max(G.get(u[i]), G.get(v[i]));
        a[idx] = w[i];
    }
    vector<long long> cs(n + 1);
    for(int i = 0; i < n; i++){
        cs[i + 1] = cs[i] + a[i];
    }

    long long ans = 0;
    auto query = [&](int l, int r){
        ans += cs[r] - cs[l];
    };
    auto dfs = [&](auto self, int curr, int prev) -> void {
        for(auto v : G.T[curr]){
            if(v == prev) continue;
            G.path_query(curr, v, query, false, false);
            self(self, v, curr);
        }
    };

    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        vector<int> x(k);
        for(int i = 0; i < k; i++) cin >> x[i];
        G.query(x);
        ans = 0;
        dfs(dfs, x[0], -1);
        G.clear(x);
        cout << ans << "\n";
    }
}
