#pragma once

/**
 * @brief Heavy Light Decomposition (重軽分解)
 * @docs docs/graph/heavy_light_decomposition.md
 */

class HeavyLightDecomposition{
    int V;
    vector<vector<int>> G;
    vector<int> stsize, parent, pathtop, depth, in, reverse_in, out;
    int root;

private:
    // Subtree Size
    void buildStsize(int curr, int prev){
        stsize[curr] = 1, parent[curr] = prev;
        for(int &v : G[curr]){
            if(v == prev){
                if(v == G[curr].back()) break;
                else swap(v, G[curr].back());
            }
            buildStsize(v, curr);
            stsize[curr] += stsize[v];
            if(stsize[v] > stsize[G[curr][0]]){
                swap(v, G[curr][0]);
            }
        }
    }

    void buildPath(int curr, int prev, int &t){
        in[curr] = t++;
        reverse_in[in[curr]] = curr;
        for(int v : G[curr]){
            if(v == prev) continue;
            
            if(v == G[curr][0]){
                pathtop[v] = pathtop[curr];
            }else{
                pathtop[v] = v;
            }
            depth[v] = depth[curr] + 1;
            buildPath(v, curr, t);
        }
        out[curr] = t;
    }

public:
    HeavyLightDecomposition(int node_size) : V(node_size), G(V), stsize(V, 0), parent(V, -1),
    pathtop(V, -1), depth(V, 0), in(V, -1), reverse_in(V, -1), out(V, -1){}

    void add_edge(int u, int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void build(int _root = 0){
        root = _root;
        int t = 0;
        buildStsize(root, -1);
        pathtop[root] = root;
        buildPath(root, -1, t);
    }

    inline int get(int a){
        return in[a];
    }

    int la(int a, int k) {
        while(true){
            int u = pathtop[a];
            if(in[a] - k >= in[u]) return reverse_in[in[a] - k];
            k -= in[a] - in[u] + 1;
            a = parent[u];
        }
    }

    int lca(int a, int b){
        int pa = pathtop[a], pb = pathtop[b];
        while(pathtop[a] != pathtop[b]){
            if(in[pa] > in[pb]){
                a = parent[pa], pa = pathtop[a];
            }else{
                b = parent[pb], pb = pathtop[b];
            }
        }
        if(in[a] > in[b]) swap(a, b);
        return a;
    }

    int dist(int a, int b){ return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }

    int jump(int from, int to, int k) {
        if(!k) return from;
        int l = lca(from, to);
        int d = dist(from, to);
        if(d < k) return -1;
        if(depth[from] - depth[l] >= k) return la(from, k);
        k -= depth[from] - depth[l];
        return la(to, depth[to] - depth[l] - k);
    }

    void subtree_query(int a, const function<void(int, int)> &func){
        func(in[a], out[a]);
    }

    void path_query(int a, int b, const function<void(int, int)> &func, bool include_root = true, bool reverse_path = false){
        vector<pair<int, int>> path;
        int pa = pathtop[a], pb = pathtop[b];
        while(pathtop[a] != pathtop[b]){
            if(in[pa] > in[pb]){
                path.emplace_back(in[pa], in[a] + 1);
                a = parent[pa], pa = pathtop[a];
            }else{
                path.emplace_back(in[pb], in[b] + 1);
                b = parent[pb], pb = pathtop[b];
            }
        }
        if(in[a] > in[b]) swap(a, b);

        if(include_root) path.emplace_back(in[a], in[b] + 1);
        else path.emplace_back(in[a] + 1, in[b] + 1);
        
        if(!reverse_path) reverse(path.begin(), path.end());
        else for(auto& p : path) p = make_pair(V - p.second, V - p.first);

        for(auto [u, v] : path){
            func(u, v);
        }
    }

    void path_noncommutative_query(int a, int b, const function<void(int, int)> &func, const function<void(int, int)> &func2){
        int l = lca(a, b);
        path_query(a, l, func2, false, true);
        path_query(l, b, func, true, false);
    }
};