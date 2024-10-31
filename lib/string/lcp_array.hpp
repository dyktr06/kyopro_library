#pragma once

#include <vector>

// Kasai's Algorithm
template <typename T>
std::vector<int> LCPArray(const T &s, const std::vector<int> &sa){
    const int n = s.size();
    std::vector<int> rank(n);
    for(int i = 0; i < n; ++i){
        rank[sa[i]] = i;
    }

    std::vector<int> lcp(n);
    for(int i = 0, h = 0; i < (int) sa.size(); ++i){
        if(rank[i] + 1 < (int) sa.size()){
            for(int j = sa[rank[i] + 1]; std::max(i, j) + h < (int) sa.size() && s[i + h] == s[j + h]; ++h);
            lcp[rank[i] + 1] = h;
            if(h > 0) --h;
        }
    }
    return lcp;
}
