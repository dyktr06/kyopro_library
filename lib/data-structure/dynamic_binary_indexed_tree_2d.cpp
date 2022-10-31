#include <bits/stdc++.h>
#include "../data-structure/dynamic_binary_indexed_tree.cpp"
#include "../other/compression.cpp"

using namespace std;

/* 
    DynamicBinaryIndexedTree2D<S, T>(h, w) : BIT2Dをサイズh*wで構築
    add(x, y, v) : (x, y) に v を加算します。
    sum(x1, y1, x2, y2) : [(x1, y1), (x2, y2)] の和を取得します。
*/

template <typename T>
struct DynamicBinaryIndexedTree2D{
    using BIT = DynamicBinaryIndexedTree<int, T>;
    int H, W;
    vector<BIT*> bit;
    DynamicBinaryIndexedTree2D(int h, int w): H(h + 1), W(w){
        for(int i = 0; i < H; i++){
            bit.push_back(new BIT(W));
        }
    }

    void add(int i, int j, const T &x){
        for(++i; i < H; i += i & -i) (*bit[i]).add(j, x);
    }

    T sum(int x, int y){
        if(x < 0 || y < 0){
            return 0;
        }
        T res = 0;
        while(x > 0){
            res += (*bit[x]).sum(y);
            x -= x & -x;
        }
        return res;
    }

    T sum(int x1, int y1, int x2, int y2){
        T res = 0;
        while(x1 != x2){
            if(x1 < x2){
                res += (*bit[x2]).sum(y1, y2);
                x2 -= x2 & -x2;
            }else{
                res -= (*bit[x1]).sum(y1, y2);
                x1 -= x1 & -x1;
            }
        }
        return res;
    }
};

// example (Library Checker (Point Add Rectangle Sum))
int main(){
    int n, q; cin >> n >> q;
    vector<int> xl, yl;
    vector<tuple<int, int, int>> point;
    vector<tuple<int, int, int, int, int>> query;
    for(int i = 0; i < n; i++){
        int x, y, w; cin >> x >> y >> w;
        point.emplace_back(x, y, w);
        xl.push_back(x);
        yl.push_back(y);
    }
    for(int i = 0; i < q; i++){
        int t; cin >> t;
        if(t == 0){
            int x, y, w; cin >> x >> y >> w;
            xl.push_back(x);
            yl.push_back(y);
            query.emplace_back(t, x, y, w, 0);
        }else{
            int l, d, r, u; cin >> l >> d >> r >> u;
            xl.push_back(l);
            xl.push_back(r);
            yl.push_back(d);
            yl.push_back(u);
            query.emplace_back(t, l, d, r, u);
        }
    }
    compress<int> xc(xl), yc(yl);
    DynamicBinaryIndexedTree2D<long long> BIT(xc.size(), yc.size());
    for(int i = 0; i < n; i++){
        auto [x, y, w] = point[i];
        BIT.add(xc.get(x), yc.get(y), w);
    }
    for(int i = 0; i < q; i++){
        auto [t, a, b, c, d] = query[i];
        if(t == 0){
            BIT.add(xc.get(a), yc.get(b), c);
        }else{
            cout << BIT.sum(xc.get(a), yc.get(b), xc.get(c), yc.get(d)) << "\n";
        }
    }
}