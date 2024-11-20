#include <iostream>
#include <vector>
#include <array>

#include "../../../lib/data_structure/kd_tree.hpp"
#include "../../../lib/math/modint.hpp"

using namespace std;

using mint = ModInt<998244353>;

using S = mint;

struct F{
    mint a, b;
};

S op(S l, S r){ return l + r; }

S e(){ return S{0}; }

S mapping(F l, S r, int size){ return S{r * l.a + size * l.b}; }

F composition(F l, F r){ return F{r.a * l.a, r.b * l.a + l.b}; }

F id(){ return F{1, 0}; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<pair<long long, long long>> p(n);
    vector<S> w(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second >> w[i];
    }
    using T = array<long long, 7>;
    vector<T> query(q);
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        query[i][0] = t;
        if(t == 0){
            cin >> query[i][1] >> query[i][2] >> query[i][3];
            p.emplace_back(query[i][1], query[i][2]);
            w.emplace_back(query[i][3]);
        }else if(t == 1){
            cin >> query[i][1] >> query[i][2];
        }else if(t == 2){
            cin >> query[i][1] >> query[i][2] >> query[i][3] >> query[i][4];
        }else{
            cin >> query[i][1] >> query[i][2] >> query[i][3] >> query[i][4] >> query[i][5] >> query[i][6];
        }
    }
    KdTree<S, op, e, F, mapping, composition, id> tree(p, w);
    for(int i = n; i < (int) p.size(); i++){
        tree.off(i);
    }
    int cur = n;
    for(int i = 0; i < q; i++){
        int t = query[i][0];
        if(t == 0){
            tree.on(cur);
            tree.update(cur, S{query[i][3]});
            cur++;
        }else if(t == 1){
            tree.update(query[i][1], S{query[i][2]});
        }else if(t == 2){
            long long l = query[i][1], d = query[i][2], r = query[i][3], u = query[i][4];
            cout << tree.query(l, r - 1, d, u - 1) << '\n';
        }else{
            long long l = query[i][1], d = query[i][2], r = query[i][3], u = query[i][4];
            mint a = query[i][5], b = query[i][6];
            tree.apply(l, r - 1, d, u - 1, F{a, b});
        }
    }
}
