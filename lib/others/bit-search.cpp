#include <bits/stdc++.h>

using namespace std;

// aの部分集合の和の組み合わせをすべて列挙します。: O(2^N)
template<typename T>
vector<long long> getSumOfSubsets(T a){
    vector<long long> res;
    int n = a.size();
    for(int bit = 0; bit < (1 << n); bit++){
        long long sum = 0;
        for(int i = 0; i < n; i++){
            int mask = 1 << i;
            if(bit & mask){
                sum += a[i];
            }
        }
        res.emplace_back(sum);
    }
    return res;
}