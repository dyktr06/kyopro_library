#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k"
#include <iostream>

#include "../../../lib/enumerative_combinatorics/stirling_number_2nd.hpp"
#include "../../../lib/math/modint.hpp"

using namespace std;

using mint = ModInt<998244353>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    auto f = stirling_number_2nd_fixed_k<mint>(n, k);
    for(int i = k; i <= n; i++){
        cout << f[i] << " \n"[i == n];
    }
}
