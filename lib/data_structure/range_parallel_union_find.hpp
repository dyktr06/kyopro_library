#pragma once

/**
 * @brief Range Parallel Union-Find
 */

#include "../data_structure/union_find.hpp"
#include "../data_structure/segment_tree_func.hpp"

#include <vector>
#include <cassert>

namespace internal_unionfind{
    using i128 = __int128_t;
    constexpr i128 mod = (1LL << 61) - 1;
    constexpr i128 base = 1000003;
    using T = std::pair<i128, i128>;

    T op(T a, T b){
        auto [hash1, len1] = a;
        auto [hash2, len2] = b;
        return std::make_pair((hash1 + hash2 * len1) % mod, (len1 * len2) % mod);
    }

    // {hash, len}
    T e(){
        return std::make_pair(0, 1);
    }
}

struct RangeParallelUnionFind{
    int V;
    std::vector<std::vector<int>> v;
    UnionFind uf;
    SegTree<internal_unionfind::T, internal_unionfind::op, internal_unionfind::e> seg;

private:
    template <typename F>
    void merge(int a, int b, const F &f){
        int ra = uf.root(a), rb = uf.root(b);
        if(ra == rb) return;
        if(uf.unite(ra, rb) == rb) std::swap(ra, rb);
        for(auto e : v[rb]){
            v[ra].push_back(e);
            seg.update(e, std::make_pair(ra, internal_unionfind::base));
        }
        f(ra, rb);
    }

public:
    RangeParallelUnionFind(int n) : V(n), v(n), uf(n), seg(n){
        for(int i = 0; i < n; ++i){
            seg.update(i, std::make_pair(i, internal_unionfind::base));
            v[i].push_back(i);
        }
    }

    // [a, a + k) と [b, b + k) をマージ
    template <typename F>
    void unite(int k, int a, int b, const F &f){
        assert(0 <= a && a + k <= V);
        assert(0 <= b && b + k <= V);
        int prev = 0;
        while(seg.query(a, a + k).first != seg.query(b, b + k).first){
            int ok = k, ng = prev;
            while(abs(ok - ng) > 1){
                int mid = (ok + ng) / 2;
                if(seg.query(a, a + mid).first != seg.query(b, b + mid).first){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }
            merge(a + ok - 1, b + ok - 1, f);
            prev = ok;
        }
    }

    template <typename F>
    void unite(int a, int b, const F &f){
        unite(1, a, b, f);
    }

    int root(int a){
        return uf.root(a);
    }

    bool same(int a, int b){
        return uf.same(a, b);
    }

    long long size(int a){
        return uf.size(a);
    }
};
