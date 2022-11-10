#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/graph/warshall_floyd.hpp"

const long long INF = 0x1fffffffffffffff;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<long long>> d(n, vector<long long>(n, INF));

    for(int i = 0; i < n; i++){
        d[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
    }

    warshall_floyd(d, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j >= 1) cout << " ";
            if(d[i][j] == INF){
                cout << "INF";
            }else{
                cout << d[i][j];
            }
        }
        cout << "\n";
    }
}