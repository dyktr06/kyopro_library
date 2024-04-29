#define PROBLEM "https://yukicoder.me/problems/no/206"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/data_structure/mergeable_set.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));

    int l, m, n; cin >> l >> m >> n;
    vector<int> a(l), b(m);
    for(int i = 0; i < l; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int q; cin >> q;
    MergeableSet<250> ms(2, n + q);
    for(auto x : a) ms.insert(0, x);
    for(auto x : b) ms.insert(1, x);
    for(int i = 0; i < q; i++){
        cout << ms.intersectCount(0, 1) << "\n";
        ms.shift(1, 1);
    }
}