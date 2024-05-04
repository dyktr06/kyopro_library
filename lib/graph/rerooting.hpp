#pragma once

template<typename E, typename V>
struct Rerooting{
    struct edge{
        int from, to, idx, rev_idx;
    };
    int n, root;
    vector<vector<edge>> edges;
    vector<int> visited;
    vector<vector<E>> out;
    vector<E> reverse_edge;
    vector<V> ans;
    function<E(E, E)> merge;
    E e;
    function<E(V, int)> put_edge;
    function<V(E, int)> put_vertex;
    Rerooting(int _n, const function<E(E, E)> &_merge, const E &_e, const function<E(V, int)> &_put_edge, const function<V(E, int)> &_put_vertex) : n(_n), merge(_merge), e(_e), put_edge(_put_edge), put_vertex(_put_vertex){
        edges.resize(n);
    }

private:
    V dfs(int v){
        visited[v]++;
        E val = e;
        for(auto &p : edges[v]){
            if(visited[p.to] > 0 && p.to != edges[v].back().to){
                swap(p, edges[v].back());
            }
            if(visited[p.to] > 0) continue;
            E nval = put_edge(dfs(p.to), p.idx);
            out[v].emplace_back(nval);
            val = merge(val, nval);
        }
        return put_vertex(val, v);
    }

    void bfs(int v){
        int siz = out[v].size();
        vector<E> left(siz + 1), right(siz + 1);
        left[0] = e, right[siz] = e;
        for(int i = 0; i < siz; i++){
            left[i + 1] = merge(left[i], out[v][i]);
        }
        for(int i = siz - 1; i >= 0; i--){
            right[i] = merge(out[v][i], right[i + 1]);
        }
        for(int i = 0; i < siz; i++){
            reverse_edge[edges[v][i].to] = put_edge(put_vertex(merge(merge(left[i], right[i + 1]), reverse_edge[v]), v), edges[v][i].rev_idx);
            bfs(edges[v][i].to);
        }
        ans[v] = put_vertex(merge(left[siz], reverse_edge[v]), v);
    }

public:
    void add_edge(int u, int v, int idx1, int idx2){
        edges[u].push_back({u, v, idx1, idx2});
        edges[v].push_back({v, u, idx2, idx1});
    }

    V build(int v = 0){
        root = v;
        out.resize(n);
        visited.assign(n, 0);
        return dfs(root);
    }

    vector<V> reroot(){
        reverse_edge.resize(n);
        reverse_edge[root] = e;
        ans.resize(n);
        bfs(root);
        return ans;
    }
};
