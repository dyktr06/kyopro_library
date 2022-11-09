#include <bits/stdc++.h>
 
using namespace std;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

// 二次元グリッド上で、スタートから各マスへの最短距離を求めます : O(HW)
// '.' -> 移動可能、'#' -> 移動不可
vector<vector<int>> bfs(const vector<string> &s, int sx = 0, int sy = 0){
    int h = s.size(), w = s[0].size();
    deque<tuple<int, int, int>> dq;
    dq.push_back(make_tuple(0, sx, sy));
    vector<vector<int>> d(h, vector<int>(w, -1));
    while (!dq.empty()){
        int dd = get<0>(dq.front());
        int x = get<1>(dq.front());
        int y = get<2>(dq.front());
        dq.pop_front();
        if(d[x][y] == -1){
            d[x][y] = dd;
            for(int i = 0; i < 4; i++){
                int x2 = x + dx[i];
                int y2 = y + dy[i];
                if(0 <= x2 && x2 < h && 0 <= y2 && y2 < w){
                    if(s[x2][y2] == '.'){
                        // 優先的に見るかどうかで前に入れるか後ろに入れるかを決める
                        dq.push_back(make_tuple(dd + 1, x2, y2));
                    }
                }
            }
        }
    }
    return d;
}

// example
int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++){
        cin >> s[i];
    }
    vector<vector<int>> ans = bfs(s, 0, 0);
    cout << ans[h - 1][w - 1] << "\n";
}