#include <bits/stdc++.h>

using namespace std;

/* 
    BinaryIndexedTree2D<T>(n) : BIT2Dをサイズnで構築
    add(x, y, v) : (x, y) に v を加算します。 O(log(H) * log(W))
    imos(x1, x2, y1, y2, v) : いもす法において、[(x1, y1), (x2, y2)] に v を加算します。O(log(H) * log(W))
    sum(x1, y1, x2, y2) : [(x1, y1), (x2, y2)] の和を取得します。O(log(H) * log(W))
*/

template <typename T>
struct BinaryIndexedTree2D{
    int H, W;
    vector<vector<T>> BIT;
    BinaryIndexedTree2D(const int &_H, const int &_W) : H(_H + 1), W(_W + 1){
        BIT.resize(H + 3, vector<T>(W + 3, 0));
    }

    void add(const int &x, const int &y, const T &v){
        assert(0 <= x && x < H && 0 <= y && y < W);
        for(int a = x + 1; a <= H; a += a & -a){
            for(int b = y + 1; b <= W; b += b & -b){
                BIT[a][b] += v;
            }
        }
    }

    void imos(const int &x1, const int &y1, const int &x2, const int &y2, const T &v){
        add(x1, y1, v);
        add(x1, y2 + 1, -v);
        add(x2 + 1, y1, -v);
        add(x2 + 1, y2 + 1, v);
    }

    T sum(const int &x, const int &y){
        assert(x < H && y < W);
        if(x < 0 || y < 0) return 0;
        T res = 0;
        for(int a = x + 1; a > 0; a -= a & -a){
            for(int b = y + 1; b > 0; b -= b & -b){
                res += BIT[a][b];
            }
        }
        return res;
    }

    T sum(const int &x1, const int &y1, const int &x2, const int &y2){
        if(x1 > x2 || y1 > y2) return T(0);
        return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
    }
};

//example
int main(){
    int n, a, b; cin >> n >> a >> b;
    BinaryIndexedTree2D<long long> BIT(n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            long long v; cin >> v;
            BIT.add(i, j, v);
        }
    }
    long long ans = 0;
    for(int i = 0; i < n - a + 1; i++){
        for(int j = 0; j < n - b + 1; j++){
            ans = max(ans, BIT.sum(i, j, i + a - 1, j + b - 1));
        }
    }
    cout << ans << "\n";
}