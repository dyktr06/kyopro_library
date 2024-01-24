#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_add_point_get"
#include <bits/stdc++.h>
using namespace std;

#include "../../../lib/data_structure/range_tree.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> l(n), d(n), r(n), u(n);
    vector<long long> w(n);
    RangeTree<int, long long> rt;
    for(int i = 0; i < n; i++){
        cin >> l[i] >> d[i] >> r[i] >> u[i] >> w[i];
        rt.add_point(l[i], d[i]);
        rt.add_point(l[i], u[i]);
        rt.add_point(r[i], d[i]);
        rt.add_point(r[i], u[i]);
    }
    using T = tuple<int, int, int, int, int, long long>;
    vector<T> query(q);
    for(int i = 0; i < q; i++){
        int T; cin >> T;
        if(T == 0){
            int L, D, R, U;
            long long W;
            cin >> L >> D >> R >> U >> W;
            rt.add_point(L, D);
            rt.add_point(L, U);
            rt.add_point(R, D);
            rt.add_point(R, U);
            query[i] = {T, L, D, R, U, W};
        }else{
            int X, Y; cin >> X >> Y;
            query[i] = {T, X, Y, 0, 0, 0};
        }
    }
    rt.build();
    for(int i = 0; i < n; i++){
        rt.add(l[i], d[i], w[i]);
        rt.add(l[i], u[i], -w[i]);
        rt.add(r[i], d[i], -w[i]);
        rt.add(r[i], u[i], w[i]);
    }
    for(int i = 0; i < q; i++){
        auto [T, A, B, C, D, E] = query[i];
        if(T == 0){
            rt.add(A, B, E);
            rt.add(A, D, -E);
            rt.add(C, B, -E);
            rt.add(C, D, E);
        }else{
            cout << rt.sum(A + 1, B + 1) << "\n";
        }
    }
}