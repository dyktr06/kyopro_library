#pragma once

/**
 * @brief Partly Persistent Union-Find
 * @docs docs/data_structure/partly_persistent_union_find.md
 */

#include <vector>
#include <algorithm>

struct PersistentUnionFind{
    int now;
    std::vector<int> par, rank, time;
    std::vector<std::vector<std::pair<int, int>>> num;
    const int INF = 1 << 30;

    PersistentUnionFind(const int N) : par(N), rank(N), time(N), num(N){
        now = 0;
        for(int i = 0; i < N; ++i){
            par[i] = i;
            num[i].emplace_back(0, 1);
        }
        std::fill(rank.begin(), rank.begin() + N, 0);
        std::fill(time.begin(), time.begin() + N, INF);
    }

    int root(const int x, const int t){
        if(t < time[x]) return x;
        return root(par[x], t);
    }

    void unite(const int x, const int y){
        ++now;

        int rx = root(x, now);
        int ry = root(y, now);
        if(rx == ry) return;

        if(rank[rx] < rank[ry]) std::swap(rx, ry);
        num[rx].emplace_back(now, size(rx, now) + size(ry, now));

        par[ry] = rx;
        time[ry] = now;
        if(rank[rx] == rank[ry]) ++rank[rx];
    }

    bool same(const int x, const int y, const int t){
        int rx = root(x, t);
        int ry = root(y, t);
        return rx == ry;
    }

    int size(const int x, const int t){
        int rx = root(x, t);

        int ok = 0, ng = num[rx].size();
        while(abs(ok - ng) > 1){
            int mid = (ok + ng) / 2;
            if(num[rx][mid].first <= t){
                ok = mid;
            } else{
                ng = mid;
            }
        }
        return num[rx][ok].second;
    }
};
