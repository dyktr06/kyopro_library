#include <bits/stdc++.h>

using namespace std;

const long long INF = 0x1fffffffffffffff;

typedef long long int ll;

int n, m;
vector<vector<ll>> d;

// ワ―シャルフロイド法 (O(n^3))
template <typename T>
void warshall_floyd(T n) { // nは頂点数
  for (int i = 0; i < n; i++)      // 経由する頂点
    for (int j = 0; j < n; j++)    // 開始頂点
      for (int k = 0; k < n; k++)  // 終端
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

void inputGraph() {
    cin >> n >> m;
    d = vector<vector<ll>>(n, vector<ll>(n, INF));

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    return;
}