#include <bits/stdc++.h>

using namespace std;

/* 
    SegTree<X>(n,fx,ex) : モノイド(集合 X, 二項演算 fx, 単位元 ex)についてサイズnで構築します。
    set(int i, X x), build() : i 番目の要素を x にセット。まとめてセグ木を構築します。O(n)
    get(i,x) : i 番目の要素を取得します。O(1)
    update(i,x) : i 番目の要素を x に更新します。O(log(n))
    query(a,b) : [a, b) の全てにfxを作用させた値を取得します。O(log(n))
*/
template <typename X>
struct SegTree{
    using FX = function<X(X, X)>; // X•X -> X となる関数の型
    int n;
    FX fx;
    const X ex;
    vector<X> dat;
    vector<X> val;

    SegTree(int n_, FX fx_, X ex_) : n(), fx(fx_), ex(ex_), dat(n_ * 4, ex_), val(n_, ex_){
        int x = 1;
        while(n_ > x){
            x *= 2;
        }
        n = x;
    }

    X get(int i){
        return val[i];
    }
    
    void set(int i, X x){ dat[i + n - 1] = x; }

    void build(){
        for(int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    void update(int i, X x){
        val[i] = x;
        i += n - 1;
        dat[i] = x;
        while(i > 0){
            i = (i - 1) / 2;  // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    X query(int a, int b){ return query_sub(a, b, 0, 0, n); }

    X query_sub(int a, int b, int k, int l, int r){
        if(r <= a || b <= l){
            return ex;
        }else if(a <= l && r <= b){
            return dat[k];
        }else{
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
};

const long long INF = 0x1fffffffffffffff;

int n;

// example
int main(){
    cin >> n;
    auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
    int ex = INF;
    SegTree<int> rmq(n, fx, ex);
    rmq.update(0, 5);
    rmq.query(0, n);
}