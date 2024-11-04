#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"
#include <iostream>

#include "../../../lib/math/modint.hpp"
#include "../../../lib/math/partition_function.hpp"

using namespace std;

using mint = ModInt<998244353>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    auto f = partitionFunction<mint>(n);
    for(int i = 0; i <= n; i++){
        cout << f[i] << (i == n ? '\n' : ' ');
    }
}
