#pragma once

template<typename T>
struct Dinic{
private:
    int V;
    vector<int> level, iter;

    void bfs(int s, int t){
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while(!(q.empty())){
            int f = q.front();
            q.pop();
            for(auto &e : G[f]){
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[f] + 1;
                    if(e.to == t) return;
                    q.push(e.to);
                }
            }
        }
    }

    T dfs(int v, int t, T f){
        if(v == t){
            return f;
        }
        for(int &i = iter[v]; i < (int) G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                T d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    e.flow += d;
                    G[e.to][e.rev].cap += d;
                    G[e.to][e.rev].flow -= d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    struct edge{
        int to, rev;
        T cap, flow = 0;
    };
    vector<vector<edge>> G;

    Dinic(const int n) : V(n), level(n), iter(n), G(n){}

    void add_edge(int from, int to, T cap){
        G[from].push_back({to, (int) G[to].size(), cap});
        G[to].push_back({from, (int) G[from].size() - 1, (T) 0});
    }

    T flow(int s, int t){
        T flow = 0;
        while(true){
            bfs(s, t);
            if(level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            T f;
            while((f = dfs(s, t, numeric_limits<T>::max())) > 0){
                flow += f;
            }
        }
    }
};
