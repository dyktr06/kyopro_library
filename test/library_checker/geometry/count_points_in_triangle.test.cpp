#define PROBLEM "https://judge.yosupo.jp/problem/count_points_in_triangle"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/geometry/geometry.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Geometry::Point> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i].x >> d[i].y;
    }
    int m; cin >> m;
    vector<Geometry::Point> e(m);
    for(int i = 0; i < m; i++){
        cin >> e[i].x >> e[i].y;
    }
    int q; cin >> q;
    while(q--){
        int a, b, c; cin >> a >> b >> c;
        vector<Geometry::Point> conv = Geometry::convexHull({d[a], d[b], d[c]});
        if((int) conv.size() <= 2){
            cout << 0 << "\n";
            continue;
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            if(Geometry::cross(conv[1] - conv[0], e[i] - conv[0]) <= 0){
                continue;
            }
            if(Geometry::cross(conv[2] - conv[1], e[i] - conv[1]) <= 0){
                continue;
            }
            if(Geometry::cross(conv[0] - conv[2], e[i] - conv[2]) <= 0){
                continue;
            }
            ans++;
        }
        cout << ans << "\n";
    }
}