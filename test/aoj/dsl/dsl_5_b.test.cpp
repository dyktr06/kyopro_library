#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/binary_indexed_tree_2d.hpp"

int main(){
    int n; cin >> n;
    BinaryIndexedTree2D<long long> BIT(1002, 1002);
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        BIT.imos(x1, y1, x2, y2, 1);
    }
    long long ans = 0;
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            ans = max(ans, BIT.sum(0, 0, i, j));
        }
    }
    cout << ans << "\n";
}