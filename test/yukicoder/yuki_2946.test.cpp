#define PROBLEM "https://yukicoder.me/problems/no/2946"
#include <iostream>
#include <vector>

#include "../../lib/data_structure/grid_unionfind.hpp"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w; cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; ++i){
        cin >> s[i];
    }
    GridUnionFind guf(s);
    guf.build();
    vector<string> ans = s;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(guf.size(i, j) >= 4) ans[i][j] = '.';
        }
    }
    for(auto &x : ans){
        cout << x << endl;
    }
}
