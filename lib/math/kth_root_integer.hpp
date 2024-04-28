#pragma once

unsigned long long kthRoot(unsigned long long a, unsigned long long k){
    unsigned long long tmp = powl(a, (long double) 1 / (long double) k);
    unsigned long long res = 0;
    vector<unsigned long long> border = {tmp - 1, tmp, tmp + 1};
    for(auto x : border){
        if(x == 0) continue;
        unsigned long long curr = a;
        for(int i = 0; i < (int) k; i++){
            curr /= x;
        }
        if(curr >= 1) res = max(res, x);
    }
    return res;
}
