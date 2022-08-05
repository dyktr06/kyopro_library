#include <bits/stdc++.h>

using namespace std;

// トポロジカルソートで辞書順最小のものを求めます: O(E + VlogV)
template <typename T>
vector<T> topological_sort(vector<vector<T>> G){
    int siz = (int) G.size();
    vector<int> indegree(siz);
    for(int i = 0; i < siz; i++){
        for(auto x : G[i]){
            indegree[x]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < siz; i++){
        if(indegree[i] == 0){
            heap.push(i);
        }
    }

    vector<T> res;
    while(!heap.empty()){
        int node = heap.top();
        heap.pop();
        res.push_back(node);
        for(auto x : G[node]){
            indegree[x]--;
            if(indegree[x] == 0){
                heap.push(x);
            }
        }
    }
    return res;
}

int n, m;
vector<vector<int>> G;

// example
int main(){
    cin >> n >> m;
    G.resize(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
    }
    vector<int> tsort = topological_sort(G);
    for(auto x : tsort){
        cout << x << " ";
    }
}