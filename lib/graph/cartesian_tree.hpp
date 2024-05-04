#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
pair<vector<vector<int>>, int> CartesianTree(vector<T> &a){
    int n = a.size();
    vector<vector<int>> G(n);
    vector<int> par(n, -1), st;
    for(int i = 0; i < n; ++i){
        int prev = -1;
        while(!st.empty() && a[i] < a[st.back()]){
            prev = st.back();
            st.pop_back();
        }
        if(prev != -1){
            par[prev] = i;
        }
        if(!st.empty()){
            par[i] = st.back();
        }
        st.emplace_back(i);
    }
    int root = -1;
    for(int i = 0; i < n; ++i){
        if(par[i] != -1){
            G[par[i]].emplace_back(i);
        } else{
            root = i;
        }
    }
    return make_pair(G, root);
}
