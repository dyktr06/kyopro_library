#define PROBLEM "https://yukicoder.me/problems/no/2712"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/graph/bellman_ford.hpp"

const long long INF = 0x1fffffffffffffff;

int main(){
    int n, m; cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    using T = tuple<long long, long long, long long>;
    vector<T> e;
    for(int i = 0; i < n; i++){
        e.emplace_back(i, i + n, -a[i]);
    }
    for(int i = 0; i < m; i++){
        long long a, b, c; cin >> a >> b >> c;
        a--, b--;
        e.emplace_back(a + n, b, c);
    }
    vector<long long> cost = bellman_ford(e, 2 * n, 0);
    if(cost[2 * n - 1] == -INF){
        cout << "inf" << "\n";
    }else{
        cout << -cost[2 * n - 1] << "\n";
    }
}
