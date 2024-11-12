#define PROBLEM "https://judge.yosupo.jp/problem/bell_number"
#include <iostream>
using namespace std;

#include "../../../lib/math/modint.hpp"
#include "../../../lib/math/bell_number.hpp"

using namespace std;

using mint = ModInt<998244353>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    auto ans = bellNumber<mint>(n);
    for(int i = 0; i <= n; i++){
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
}
