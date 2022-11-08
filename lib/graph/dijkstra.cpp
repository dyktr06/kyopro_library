#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<array<long long, 2>>> G;

// ダイクストラ法 : O(ElogV)
template <typename T>
vector<long long> dijkstra(T x){
    const long long INF = 0x1fffffffffffffff;
    vector<long long> cost((int) G.size(), INF);
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

// s から t への最短パスを求めます : O(ElogV)
pair<long long, vector<pair<int, int>>> shortestPath(int s, int t){
    const long long INF = 0x1fffffffffffffff;
    vector<long long> cost((int) G.size(), INF);
    vector<int> par((int) G.size(), -1);
    using P = pair<long long, long long>;
    priority_queue<P, vector<P>, greater<>> q;
    cost[s] = 0;
    par[s] = -1;
    q.emplace(0, s);

    while(q.size()){
        auto [c, at] = q.top();
        q.pop();
        if(c > cost[at]) continue;
        for(auto& [to, t] : G[at]){
            if(cost[to] > c + t){
                par[to] = at;
                cost[to] = c + t;
                q.emplace(cost[to], to);
            }
        }
    }

    if(cost[t] == INF){
        return {-1, {}};
    }
    vector<pair<int, int>> path;
    int now = t;
    while(par[now] != -1){
        path.push_back({par[now], now});
        now = par[now];
    }
    reverse(path.begin(), path.end());

    return {cost[t], path};
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