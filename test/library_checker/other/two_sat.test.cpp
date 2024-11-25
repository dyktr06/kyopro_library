
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include <iostream>
#include <vector>

#include "../../../lib/graph/two_sat.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string p, cnf; cin >> p >> cnf;
    int n, m; cin >> n >> m;
    TwoSAT SAT(n);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        SAT.add_clause(abs(a) - 1, a > 0, abs(b) - 1, b > 0);
    }
    SAT.build();
    vector<bool> ans = SAT.getAnswer();
    if(ans.empty()){
        cout << "s UNSATISFIABLE" << '\n';
    }else{
        cout << "s SATISFIABLE" << '\n';
        cout << "v ";
        for(int i = 0; i < n; i++){
            if(i) cout << ' ';
            cout << (ans[i] ? i + 1 : -i - 1);
        }
        cout << " 0" << '\n';
    }
    return 0;
}
