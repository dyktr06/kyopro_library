#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"
#include <iostream>
#include <vector>
#include "../../../lib/math/modint.hpp"
#include "../../../lib/polynomial/bostan_mori.hpp"

using namespace std;

using mint = ModInt<998244353>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int d; long long k;
    cin >> d >> k;
    vector<mint> init(d), c(d + 1);
    for(int i = 0; i < d; i++){
        cin >> init[i];
    }
    for(int i = 1; i <= d; i++){
        cin >> c[i];
    }
    cout << findKthTerm(init, c, k) << endl;
}
