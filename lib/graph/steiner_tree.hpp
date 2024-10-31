#pragma once

/**
 * @brief Steiner Tree (シュタイナー木)
 * @docs docs/graph/steiner_tree.md
 * @see https://www.slideshare.net/wata_orz/ss-12131479
 */

template <typename T>
struct SteinerTree{
private:
    int V, t;
    vector<int> last_terminal;
    vector<vector<array<T, 2>>> G;
    vector<vector<T>> dp;
    const T INF = numeric_limits<T>::max() / 3;
    using PP = pair<T, int>;

public:
    SteinerTree(int node_size) : V(node_size), G(V){}

    void add_edge(int u, int v, T cost){
        G[u].push_back({v, cost}), G[v].push_back({u, cost});
    }

    void build(vector<int> &terminal){
        t = (int) terminal.size();
        last_terminal = terminal;
        if(t == 0) return;
        dp.resize((1 << t), vector<T>(V, INF));
        for(int i = 0; i < t; i++){
            dp[(1 << i)][terminal[i]] = 0;
        }
        for(int i = 1; i < (1 << t); i++){
            for(int j = 0; j < V; j++){
                // subset
                for(int k = i; k > 0; k = (k - 1) & i){
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i ^ k][j]);
                }
            }

            priority_queue<PP, vector<PP>, greater<PP>> que;
            for(int j = 0; j < V; j++){
                que.emplace(dp[i][j], j);
            }

            while(!que.empty()){
                PP p = que.top();
                que.pop();
                int v = p.second;
                if(dp[i][v] < p.first) continue;
                for(auto &[to, cost] : G[v]){
                    if(dp[i][to] > dp[i][v] + cost){
                        dp[i][to] = dp[i][v] + cost;
                        que.emplace(dp[i][to], to);
                    }
                }
            }
        }
    }

    T get(int i = -1){
        if(i == -1) return dp[(1 << t) - 1][last_terminal[0]];
        return dp[(1 << t) - 1][i];
    }
};
