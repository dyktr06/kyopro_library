#include <bits/stdc++.h>

using namespace std;

/* 
    binary_indexed_tree<T>(n) : BITをサイズnで構築
    get(i)    : i 番目の要素を取得します。 O(log(n))
    add(i, x) : i 番目の要素に加算します。 O(log(n))
    sum(l, r) : [l, r) の区間和を取得します。O(log(n))
    
    (以下の機能を使うには、0 <= i < N において、A_i >= 0 である必要があります。)
    lower_bound(x) : A_0 + A_1 + ... + A_y >= x となる最小の y を求めます。O(log(n))
    upper_bound(x) : A_0 + A_1 + ... + A_y > x となる最小の y を求めます。O(log(n))
*/

template <typename T>
struct BinaryIndexedTree{
    int N;
    vector<T> BIT;
    BinaryIndexedTree(int N): N(N), BIT(N + 1, 0){
    }

    T get(int i){
        return sum(i + 1) - sum(i);
    }

    void add(int i, T x){
        i++;
        while(i <= N){
            BIT[i] += x;
            i += i & -i;
        }
    }

    T sum(int i){
        T ans = 0;
        while(i > 0){
            ans += BIT[i];
            i -= i & -i;
        }
        return ans;
    }

    T sum(int L, int R){
        return sum(R) - sum(L);
    }

    int lower_bound(T x){
        if(x <= 0){
            return 0;
        }else{
            int v = 0, r = 1;
            while(r < N) r = r << 1;
            for(int len = r; len > 0; len = len >> 1){
                if(v + len < N && BIT[v + len] < x){
                    x -= BIT[v + len];
                    v += len;
                }
            }
            return v;
        }
    }

    int upper_bound(T x){
        if(x < 0){
            return 0;
        }else{
            int v = 0, r = 1;
            while(r <= N) r = r << 1;
            for(int len = r; len > 0; len = len >> 1){
                if(v + len <= N && BIT[v + len] <= x){
                    x -= BIT[v + len];
                    v += len;
                }
            }
            return v;
        }
    }
};

// 配列 p の転倒数を求めます : O(NlogN)
template <typename T>
long long getInvNum(T p){
    long long res = 0;
    BinaryIndexedTree<long long> BIT(n);
    for(int i = 0; i < (int) p.size(); i++){
      res += BIT.sum(p[i], n);
      BIT.add(p[i], 1);
    }
    return res;
}
