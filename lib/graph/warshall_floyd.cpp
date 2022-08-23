#include <bits/stdc++.h>

using namespace std;

const long long INF = 0x1fffffffffffffff;

int n, m;
vector<vector<long long>> d;

// ワ―シャルフロイド法で全頂点間の最短距離を求めます : (O(n^3))
template <typename T>
void warshall_floyd(T n) { // nは頂点数
    for(int i = 0; i < n; i++)          // 経由する頂点
        for(int j = 0; j < n; j++)      // 開始頂点
            for(int k = 0; k < n; k++)  // 終端
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

// example
int main(){
    cin >> n >> m;
    d = vector<vector<long long>>(n, vector<long long>(n, INF));

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    return;
}