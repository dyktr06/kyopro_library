#include <bits/stdc++.h>

using namespace std;

/* 
    DynamicBinaryIndexedTree<S, T>(n) : BITをサイズnで構築
    add(i, x) : i 番目の要素に加算します。 O(log(n)^2)
    sum(l, r) : [l, r) の区間和を取得します。O(log(n)^2)
    
    (以下の機能を使うには、0 <= i < N において、A_i >= 0 である必要があります。)
    lower_bound(x) : A_0 + A_1 + ... + A_y >= x となる最小の y を求めます。O(log(n))
*/

template <typename S, typename T>
struct DynamicBinaryIndexedTree{
    S N;
    unordered_map<S, T> data;
    DynamicBinaryIndexedTree(S _N): N(_N + 1){
    }

    void add(S i, const T &x){
        for(++i; i < N; i += i & -i) data[i] += x;
    }

    T sum(int i){
        if(i < 0){
            return 0;
        }
        T ans = 0;
        while(i > 0){
            const auto iter = data.find(i);
            if(iter != data.end()){
                ans += iter->second;
            }
            i -= i & -i;
        }
        return ans;
    }

    T sum(int L, int R){
        return sum(R) - sum(L);
    }

    T operator[](S i) const{
        return sum(i + 1) - sum(i);
    }

    S lower_bound(T x){
        if(x <= 0){
            return 0;
        }
        S v = 0, r = 1;
        while(r < N) r = r << 1;
        for(S len = r; len > 0; len = len >> 1){
            if(v + len < N && data[v + len] < x){
                x -= data[v + len];
                v += len;
            }
        }
        return v;
    }
};

// example (ALDS1_5_D)
int main(){
    int n; cin >> n;
    long long N = 1 << 30;
    DynamicBinaryIndexedTree<long long, long long> BIT(N);
    long long ans = 0;
    for(int i = 0; i < n; i++){
        long long a; cin >> a;
        ans += BIT.sum(a + 1, N);
        BIT.add(a, 1);
    }
    cout << ans << "\n";
}