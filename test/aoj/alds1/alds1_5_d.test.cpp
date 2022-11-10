#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/dynamic_binary_indexed_tree.hpp"

int main(){
    int n; cin >> n;
    long long N = 1 << 30;
    DynamicBinaryIndexedTree<long long, long long> BIT(N);
    long long ans = 0;
    for(int i = 0; i < n; i++){
        long long a; cin >> a;
        ans += BIT.sum(a + 1, N);
        BIT.add(a, 1);
    }
    cout << ans << "\n";
}