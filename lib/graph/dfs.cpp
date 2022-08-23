#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> G;

// DFS
void dfs(int curr, int prev = -1) {

    if(prev == -1){

    }else{

    }

    for(auto x : G[curr]){
        if(x == prev){
            continue;
        }
        dfs(x, curr);
    }
}

vector<int> depth;

// スタートを基準とする他の頂点の深さを求めます (グラフが木でないと使えない) : O(N)
template <typename T>
void getDepth(T curr, T prev = -1) {
    if(prev == -1){
        depth[curr] = 0;
    }
 
    for(auto x : G[curr]){
        if(x == prev){
            continue;
        }
        depth[x] = depth[curr] + 1;
        getDepth(x, curr);
    }
    return;
}

// example
int main(){
    cin >> n;
    G = vector<vector<int>>(n);

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    return;
}