#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/geometry/geometry.hpp"

int main(){
    int n; cin >> n;
    vector<Geometry::Point> xy(n);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        xy[i] = Geometry::Point(x, y);
    }
    sort(xy.begin(), xy.end());
    for(auto p : xy){
        cout << p << "\n";
    }
}