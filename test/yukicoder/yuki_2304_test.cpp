#define PROBLEM "https://yukicoder.me/problems/no/2304"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/data_structure/slope_trick.hpp"

int main(){
    int n; cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    SlopeTrick st;
    for(int i = 0; i < n; i++){
        st.chmin_right();
        st.add_abs_xma(a[i] - i);
    }
    cout << st.get_min().second << "\n";
}