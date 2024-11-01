#pragma once

#include <vector>
#include <cassert>
#include <limits>

template <typename T>
struct RadixHeap{
    using u64 = unsigned long long;
    using P = std::pair<u64, T>;
    std::vector<std::vector<P>> val;
    u64 N, last;

private:
    int bit_width(u64 x){
        if(x == 0) return 0;
        return 64 - __builtin_clzll(x);
    }

public:
    RadixHeap(){
        N = last = 0;
    }

    void push(P x){
        assert(last <= x.first);
        int i = bit_width(last ^ x.first);
        if((int) val.size() <= i) val.resize(i + 1);
        val[i].push_back(x);
        N++;
    }

    P pop(){
        assert(N > 0);
        if(val[0].empty()){
            int i = 1;
            while(val[i].empty()) i++;
            u64 nlast = std::numeric_limits<u64>::max();
            for(auto &v : val[i]){
                nlast = std::min(nlast, v.first);
            }
            for(auto &v : val[i]){
                val[bit_width(nlast ^ v.first)].push_back(v);
            }
            last = nlast;
            val[i].clear();
        }
        P ret = val[0].back();
        val[0].pop_back();
        N--;
        return ret;
    }

    size_t size(){
        return N;
    }
};
