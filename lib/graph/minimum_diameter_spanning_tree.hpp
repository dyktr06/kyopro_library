#pragma once

// 参考: https://www.slideshare.net/slideshow/ss-17402143/17402143
struct MinimumDiameterSpanningTree{

    const long long INF = 0x1fffffffffffffff;

    struct Edge{
        int from, to;
        long long cost;
        int id;
    };

    int V, E;
    vector<vector<Edge>> G;
    long long tree_diameter = INF;
    vector<int> tree_edge;

    MinimumDiameterSpanningTree(int n) : V(n), E(0), G(n) { }

    void add_edge(int u, int v, long long cost){
        // 途中の計算で分母が 2 になるため 2 倍している
        G[u].push_back({u, v, cost * 2, E});
        G[v].push_back({v, u, cost * 2, E});
        E++;
    }

    void build(){
        if(V == 1){
            tree_diameter = 0;
            return;
        }

        using P = pair<long long, int>;

        // ダイクストラ法で全点対間の最短距離を求める
        vector<vector<long long>> dist(V, vector<long long>(V, INF));
        for(int i = 0; i < V; i++){
            priority_queue<P, vector<P>, greater<>> q;
            dist[i][i] = 0;
            q.emplace(0, i);
            while(q.size()){
                auto [c, at] = q.top();
                q.pop();
                if(c > dist[i][at]) continue;
                for(auto &[_, to, t, id] : G[at]){
                    if(dist[i][to] > c + t){
                        dist[i][to] = c + t;
                        q.emplace(dist[i][to], to);
                    }
                }
            }
        }

        vector<long long> midpoint(E, INF);
        Edge min_edge;
        for(int from = 0; from < V; from++){
            long long diameter = INF;
            for(auto &[_, to, cost, id] : G[from]){
                if(from > to) continue;

                vector<P> lines(V);
                for(int i = 0; i < V; i++){
                    lines[i] = {dist[from][i], i};
                }
                sort(lines.rbegin(), lines.rend());

                // 辺の間で、直径が最大値になる点
                vector<long long> mid(V);
                for(int i = 0; i < V; i++){
                    mid[i] = min(cost, max(0LL, (dist[to][i] - dist[from][i] + cost) / 2));
                }
                // 辺上の点 t と頂点 i との距離
                auto f = [&](int i, int t){
                    return min(dist[from][i] + t, dist[to][i] + (cost - t));
                };
                long long cur = 0;
                for(int i = 0; i < V; i++){
                    auto [d_i, at_i] = lines[i];
                    if(diameter > f(at_i, cur)){
                        diameter = f(at_i, cur);
                        midpoint[id] = cur;
                    }
                    bool found = false;
                    for(int j = i + 1; j < V; j++){
                        auto [d_j, at_j] = lines[j];
                        if(mid[at_i] < mid[at_j] && f(at_i, mid[at_j]) < f(at_j, mid[at_j])){
                            int nxt = mid[at_i] + (dist[from][at_i] - dist[from][at_j]) / 2;
                            cur = nxt;
                            found = true;
                            i = j - 1;
                            break;
                        }
                    }
                    if(!found){
                        if(diameter > f(at_i, cost)){
                            diameter = f(at_i, cost);
                            midpoint[id] = cost;
                        }
                        break;
                    }
                }
                if(tree_diameter > diameter){
                    tree_diameter = diameter;
                    min_edge = {from, to, cost, id};
                }
            }
        }

        // 最小直径全域木の構築
        {
            priority_queue<P, vector<P>, greater<>> q;
            vector<long long> ndist(V, INF);
            ndist[min_edge.from] = midpoint[min_edge.id];
            ndist[min_edge.to] = min_edge.cost - midpoint[min_edge.id];
            q.emplace(ndist[min_edge.from], min_edge.from);
            q.emplace(ndist[min_edge.to], min_edge.to);
            vector<int> edge_id(V, -1);
            edge_id[min_edge.from] = min_edge.id;
            while(q.size()){
                auto [c, at] = q.top();
                q.pop();
                if(c > ndist[at]) continue;
                if(edge_id[at] != -1){
                    tree_edge.push_back(edge_id[at]);
                }
                for(auto &[_, to, t, id] : G[at]){
                    if(ndist[to] > c + t){
                        ndist[to] = c + t;
                        edge_id[to] = id;
                        q.emplace(ndist[to], to);
                    }
                }
            }
        }
    }

    vector<int> get(){
        return tree_edge;
    }

    long long getTreeDiameter(){
        return tree_diameter;
    }
};
