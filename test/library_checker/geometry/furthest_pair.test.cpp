#define PROBLEM "https://judge.yosupo.jp/problem/furthest_pair"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/geometry/geometry.hpp"

void solve(){
    int n; cin >> n;
    vector<Geometry::Point> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i];
    }

    auto [dist, p] = Geometry::furthestPair(points);
    cout << p.first << " " << p.second << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        solve();
    }
}
