#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/geometry/geometry.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<Geometry::Point> p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i].x >> p[i].y;
        }
        vector<Geometry::Point> ch = Geometry::convexHull(p);
        cout << (int) ch.size() << "\n";
        for(auto q : ch){
            cout << q.x << " " << q.y << "\n";
        }
    }
}
