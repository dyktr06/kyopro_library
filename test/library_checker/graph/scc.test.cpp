#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include <iostream>

#include "../../../lib/graph/scc.hpp"

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    SCC scc(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        scc.add_edge(a, b);
    }
    scc.build();
    vector<vector<int>> v = scc.get();
    cout << (int) v.size() << "\n";
    for(auto s : v){
        cout << (int) s.size() << " ";
        for(auto x : s){
            cout << x << " ";
        }
        cout << "\n";
    }
}
