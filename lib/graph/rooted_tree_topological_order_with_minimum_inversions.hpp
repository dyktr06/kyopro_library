#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include "../data_structure/union_find.hpp"
#include "../data_structure/priority_queue.hpp"

template <typename T>
struct fraction{
    T p, q; // long long or BigInt
    fraction(T P = 0, T Q = 1) : p(P), q(Q){}
    inline bool operator==(const fraction &other) const {
        return p * other.q == other.p * q;
    }
    inline bool operator<(const fraction &other) const {
        if(p == 0 && q == 0) return true;
        if(other.p == 0 && other.q == 0) return false;
        return p * other.q < other.p * q;
    }
};

template <typename T>
std::pair<T, std::vector<int>> rootedTreeTopologicalOrderWithMinimumInversions(const std::vector<int> &par, const std::vector<T> &zero, const std::vector<T> &one){
    std::vector<int> G = par;
    int n = G.size();
    UnionFind uf(n);
    PriorityQueue<std::pair<fraction<T>, int>> pq;
    std::vector<T> inv(n);
    std::vector<fraction<T>> fv(n);
    std::vector<std::deque<int>> p(n);
    for(int i = 0; i < n; ++i){
        fv[i] = {zero[i], one[i]};
        p[i].push_back(i);
        if(i >= 1) pq.push({fv[i], i});
    }
    while(pq.size()){
        auto [f, idx] = pq.top();
        pq.erase(pq.top());
        int r = uf.root(idx);
        if(G[r] == -1) continue;
        int prv = uf.root(G[r]);
        int nxt = uf.unite(r, prv);
        G[nxt] = G[prv];
        inv[nxt] += fv[prv].q * fv[r].p;
        {
            if(p[r].size() < p[prv].size()){
                while(!p[r].empty()){
                    int x = p[r].front();
                    p[r].pop_front();
                    p[prv].push_back(x);
                }
                if(prv != nxt) std::swap(p[prv], p[nxt]);
            }else{
                while(!p[prv].empty()){
                    int x = p[prv].back();
                    p[prv].pop_back();
                    p[r].push_front(x);
                }
                if(r != nxt) std::swap(p[r], p[nxt]);
            }
        }
        std::pair<fraction<T>, int> nf = {fv[prv], prv};
        int from = prv;
        if(nxt == prv) from = r;
        inv[nxt] += inv[from];
        fv[nxt].p += fv[from].p;
        fv[nxt].q += fv[from].q;
        if(G[nxt] != -1){
            pq.erase(nf);
            pq.push({fv[nxt], nxt});
        }
    }
    std::vector<int> res;
    while(!p[uf.root(0)].empty()){
        int x = p[uf.root(0)].front();
        p[uf.root(0)].pop_front();
        res.push_back(x);
    }
    return {inv[uf.root(0)], res};
}
