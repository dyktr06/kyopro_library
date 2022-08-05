#include <bits/stdc++.h>

using namespace std;

// 配列 a の最長増加部分列の長さを求めます : O(NlogN)

// dp[i] : = 長さが i の増加部分列として最後尾の要素のとりうる最小値
// is_strong = false のとき、同じ値が連続することを許す
template<class T>
int LIS(vector<T> a,  bool is_strong = true) {
    const long long INF = 0x1fffffffffffffff;
    int n = (int) a.size();
    vector<T> dp(n, INF);
    for(int i = 0; i < n; ++i){
        if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

// example
int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << LIS(a) << endl;
}