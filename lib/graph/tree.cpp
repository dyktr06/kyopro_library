#include <bits/stdc++.h>

using namespace std;

/*  
    TreeLibrary(G, root): 木 G に対する根を root 様々なものを求める構造体
    lca(u, v): u と v の LCA を求めます。計算量 O(logn)
    la(u, v): u と v の LA を求めます。計算量 O(logn)
    diameter(): 直径の長さを求めます。
    endpoint(): 直径の端の頂点を求めます。
    getDist(u, v): u と v の距離を求めます。計算量 O(logn)
    isOnPath(u, v, a): a が u と v のパス上にあるかどうかを求めます。計算量 O(logn)
    前処理 : O(nlogn), O(nlogn)空間
*/

template <typename T>
struct TreeLibrary{
    using Graph = vector<vector<T>>;
    vector<vector<int>> parent;  // parent[k][u]:= u の 2^k 先の親
    vector<int> dist, dist2;
    int V, root, diam = -1;
    pair<int, int> ep;
    TreeLibrary(const Graph &G, int root_ = 0): root(root_){ init(G); }

    void init(const Graph &G){
        V = G.size();
        int K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1); dist2.assign(V, -1);
        dfs(G, root, -1, 0);
        for(int k = 0; k + 1 < K; k++){
            for(int v = 0; v < V; v++){
                if(parent[k][v] < 0){
                    parent[k + 1][v] = -1;
                }else{
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }

        int mx = 0;
        for(int i = 0; i < V; i++){
            if(mx < dist[i]){
                mx = dist[i];
                ep.first = i;
            }
        }
 
        dfs2(G, ep.first, -1, 0);
        for(int i = 0; i < V; i++){
            if(diam < dist2[i]){
                diam = dist2[i];
                ep.second = i;
            }
        }
    }
    
    // 根からの距離と1つ先の頂点を求める
    void dfs(const Graph &G, int v, int p, int d){
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : G[v]){
            if(e != p) dfs(G, e, v, d + 1);
        }
    }
    
    void dfs2(const Graph &G, int v, int p, int d){
        dist2[v] = d;
        for(auto e : G[v]){
            if(e != p) dfs2(G, e, v, d + 1);
        }
    }

    int lca(int u, int v){
        if (dist[u] < dist[v]) swap(u, v);  // u の方が深いとする
        int K = parent.size();
        // LCA までの距離を同じにする
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        // 二分探索で LCA を求める
        if(u == v) return u;
        for(int k = K - 1; k >= 0; k--){
            if(parent[k][u] != parent[k][v]){
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    int la(int u, int d){
        if(getDist(u, root) < d){
            return -1;
        }
        // 二分探索で LA を求める
        int K = parent.size();
        for(int k = K - 1; k >= 0; k--){
            if(d & (1 << k)){
                u = parent[k][u];
            }
        }
        return u;
    }

    int diameter(){
        return diam;
    }
 
    pair<int, int> endpoint(){
        return ep;
    }

    int getDist(int u, int v){
        return dist[u] + dist[v] - 2 * dist[lca(u, v)];
    }

    bool isOnPath(int u, int v, int a){
        return getDist(u, a) + getDist(a, v) == getDist(u, v);
    }
};

// example (典型90 003)
int main(){
    int n; cin >> n;
    vector<vector<int>> G(n);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    TreeLibrary t(G);
    cout << t.diam + 1 << "\n";
}