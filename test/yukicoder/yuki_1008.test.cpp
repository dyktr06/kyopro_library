#define PROBLEM "https://yukicoder.me/problems/no/1008"
#include <bits/stdc++.h>
using namespace std;

#include "../../lib/data_structure/imos_linear.hpp"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<long long> x(m), w(m);
    for(int i = 0; i < m; i++){
        cin >> x[i] >> w[i];
        x[i]--;
    }
    long long ok = 1LL << 20, ng = -1;
    while(abs(ok - ng) > 1){
        long long mid = (ok + ng) / 2;
        imos_linear<long long> imos(n);
        for(int i = 0; i < m; i++){
            {
                long long ok2 = x[i], ng2 = n;
                while(abs(ok2 - ng2) > 1){
                    long long mid2 = (ok2 + ng2) / 2;
                    if((mid2 - x[i]) * mid <= w[i]){
                        ok2 = mid2;
                    }else{
                        ng2 = mid2;
                    }
                }
                imos.add(x[i], ok2 + 1, w[i], -mid);
            }
            {
                long long ok2 = x[i], ng2 = -1;
                while(abs(ok2 - ng2) > 1){
                    long long mid2 = (ok2 + ng2) / 2;
                    if((x[i] - mid2) * mid <= w[i]){
                        ok2 = mid2;
                    }else{
                        ng2 = mid2;
                    }
                }
                imos.add(ok2, x[i], w[i] - (x[i] - ok2) * mid, mid);
            }
        }
        imos.build();
        int is_ok = 1;
        for(int i = 0; i < n; i++){
            if(imos[i] >= a[i]) is_ok = 0;
        }
        if(is_ok) ok = mid;
        else ng = mid;
    }
    if(ok == 1LL << 20) cout << -1 << "\n";
    else cout << ok << "\n";
}
