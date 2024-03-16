#pragma once

#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct ZorbristHash{
    map<T, int> rnd, cnt;
    int h = 0;

    ZorbristHash(){}

    void insert(T x){
        if(rnd.count(x) == 0){
            rnd[x] = rand();
        }
        if(cnt[x]) return;
        h ^= rnd[x];
        cnt[x]++;
    }

    void erase(T x){
        if(cnt[x] == 0) return;
        h ^= rnd[x];
        cnt[x]--;
    }

    int get(){
        return h;
    }
};
