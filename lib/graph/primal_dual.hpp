#pragma once

template <typename flow_t, typename cost_t>
struct PrimalDual{
    struct Edge{
        int from, to;
        flow_t cap, flow;
        cost_t cost;
        int rev;
        bool is_rev;
    };
    int V;
    vector<vector<Edge>> G;
    vector<cost_t> potential, min_cost;
    vector<int> prev_v, prev_e;
    const cost_t INF;
    PrimalDual(int n) : V(n), G(n), INF(numeric_limits<cost_t>::max() / 3) {}

    void add_edge(int from, int to, flow_t cap, cost_t cost){
        G[from].push_back(Edge{from, to, cap, 0, cost, (int) G[to].size(), false});
        G[to].push_back(Edge{to, from, 0, cap, -cost, (int) G[from].size() - 1, true});
    }

    cost_t flow(int s, int t, flow_t f){
        assert(0 <= s && s < V && 0 <= t && t < V);
        assert(0 <= f);
        cost_t ret = 0;
        using P = pair<cost_t, int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        potential.assign(V, 0);
        prev_v.assign(V, -1);
        prev_e.assign(V, -1);
        while(f > 0){
            // s-t パスをダイクストラ法で探索
            min_cost.assign(V, INF);
            pq.emplace(0, s);
            min_cost[s] = 0;
            while(pq.size()){
                auto [c, at] = pq.top();
                pq.pop();
                if(min_cost[at] < c) continue;
                for(int i = 0; i < (int) G[at].size(); i++){
                    auto &e = G[at][i];
                    // 非負にするために、cost'(at, e.to) = cost(at, e.to) + potential[at] - potential[e.to] とする
                    // min_cost'[at] + cost'(at, e.to) >= min_cost'[e.to]
                    // <=> (min_cost'[at] + potential[at]) + cost(at, e.to) >= (min_cost[e.to] + potential[e.to])
                    cost_t next_cost = min_cost[at] + e.cost + potential[at] - potential[e.to];
                    if(e.cap > 0 && next_cost < min_cost[e.to]){
                        min_cost[e.to] = next_cost;
                        prev_v[e.to] = at;
                        prev_e[e.to] = i;
                        pq.emplace(min_cost[e.to], e.to);
                    }
                }
            }
            if(min_cost[t] == INF){
                return -1;
            }
            // フローを流す
            flow_t addflow = f;
            for(int i = t; i != s; i = prev_v[i]){
                addflow = min(addflow, G[prev_v[i]][prev_e[i]].cap);
            }
            f -= addflow;
            ret += addflow * (min_cost[t] + potential[t]);
            for(int i = t; i != s; i = prev_v[i]){
                auto &e = G[prev_v[i]][prev_e[i]];
                e.cap -= addflow;
                e.flow += addflow;
                G[i][e.rev].cap += addflow;
                G[i][e.rev].flow -= addflow;
            }

            // ポテンシャルの更新
            for(int i = 0; i < V; i++){
                potential[i] += min_cost[i];
            }
        }
        return ret;
    }

    vector<Edge> edges(){
        vector<Edge> ret;
        for(int i = 0; i < V; i++){
            for(auto &e : G[i]){
                if(e.is_rev) continue;
                ret.push_back(e);
            }
        }
        return ret;
    }
};
