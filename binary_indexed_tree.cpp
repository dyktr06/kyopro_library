#include <bits/stdc++.h>

using namespace std;

/* 
    binary_indexed_tree<T>(n) : BITをサイズnで構築
    add(i, x) : i 番目の要素に加算します。 O(log(n)
    sum(l, r) : [l, r) の区間和を取得します。O(log(n))
*/

template <typename T>
struct binary_indexed_tree{
    int N;
    vector<T> BIT;
    binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
    }
    void add(int i, T x){
        i++;
        while (i <= N){
            BIT[i] += x;
            i += i & -i;
        }
    }
    T sum(int i){
        T ans = 0;
        while (i > 0){
            ans += BIT[i];
            i -= i & -i;
        }
        return ans;
    }
    T sum(int L, int R){
        return sum(R) - sum(L);
    }
};

// 配列 p の転倒数を求めます : O(NlogN)
template <typename T>
long long getInvNum(T p){
    long long res = 0;
    binary_indexed_tree<long long> BIT(n);
    for(int i = 0; i < (int) p.size(); i++){
      res += BIT.sum(p[i], n);
      BIT.add(p[i], 1);
    }
    return res;
}
