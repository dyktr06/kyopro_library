#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<array<long long, 2>>> G;

// ダイクストラ法 : O(ElogV)
template <typename T>
vector<long long> dijkstra(T x){
    const long long INF = 0x1fffffffffffffff;
    vector<long long> cost(n, INF);
    using P = pair<long long, long long>;
    priority_queue<P, vector<P>, greater<>> q;
    cost[x] = 0;
    q.emplace(0, x);
    
    while(q.size()){
        auto [c, at] = q.top();
        q.pop();
        if(c > cost[at]) continue;
        for(auto& [to, t] : G[at]){
            if(cost[to] > c + t){
                cost[to] = c + t;
                q.emplace(cost[to], to);
            }
        }
    }
    return cost;
}

// example
int main(){
    cin >> n >> m;
    G = vector<vector<array<long long, 2>>>(n);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
}