#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include <iostream>

#include "../../../lib/math/modint.hpp"
#include "../../../lib/data_structure/swag.hpp"

using namespace std;

using mint = ModInt<998244353>;

using T = pair<mint, mint>;
T op(T x1, T x2){
    return {x1.first * x2.first, x2.first * x1.second + x2.second};
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    SWAG<T, op> swag;

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 0){
            long long a, b; cin >> a >> b;
            swag.push({a, b});
        }else if(t == 1){
            swag.pop();
        }else{
            long long x; cin >> x;
            if(swag.empty()){
                cout << x << "\n";
                continue;
            }
            T k = swag.fold();
            mint ans = k.first * x + k.second;
            cout << ans << "\n";
        }
    }
}
