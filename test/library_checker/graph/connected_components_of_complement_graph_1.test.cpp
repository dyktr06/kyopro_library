#define PROBLEM "https://judge.yosupo.jp/problem/connected_components_of_complement_graph"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/fast_deque.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));

    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<vector<int>> ans;
    vector<bool> used(n), reach(n, true);
    vector<int> s(n);
    iota(s.begin(), s.end(), 0);
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        vector<int> v;
        FastDeque<int> q;
        q.push_back(i);
        while(!q.empty()){
            int x = q.front(); q.pop_front();
            if(used[x]) continue;
            used[x] = true;
            v.push_back(x);
            for(auto y : G[x]){
                reach[y] = false;
            }
            vector<int> ts;
            while(!s.empty()){
                if(reach[s.back()]){
                    q.push_back(s.back());
                } else{
                    ts.push_back(s.back());
                }
                s.pop_back();
            }
            swap(s, ts);
            for(auto y : G[x]){
                reach[y] = true;
            }
        }
        ans.push_back(v);
    }
    cout << ans.size() << "\n";
    for(auto &v : ans){
        cout << v.size() << " ";
        for(auto x : v){
            cout << x << " ";
        }
        cout << "\n";
    }
}
