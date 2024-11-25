#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"
#include <iostream>

#include "../../../lib/enumerative_combinatorics/montmort_number.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    auto res = montmortNumber(n, m);
    for(int i = 1; i <= n; i++){
        cout << res[i] << (i == n ? '\n' : ' ');
    }
}
