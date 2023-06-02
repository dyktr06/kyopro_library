#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"
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
    long double ans = Geometry::polygonArea(xy);
    ans /= 2;
    printf("%.1Lf\n", ans);
}