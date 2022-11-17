#pragma once

/* 
    PersistentUnionFind(n) : 部分永続 Union-Find 木をサイズnで構築
    計算量 : O(log(n))
    root(x, t) : 時刻 t における集合 x の根を取得します。
    unite(x, y) : 集合 x と y を併合します。
    same(x, y, t) : 時刻 t における集合 x と 集合 y が等しいかどうかを判定します。
    size(x, t) : 時刻 t における x を含む集合の大きさを取得します。
*/

struct PersistentUnionFind{
    int now;
    vector<int> par, rank, time;
    vector<vector<pair<int, int>>> num;
    const int INF = 1 << 30;

    PersistentUnionFind(const int &N) : par(N), rank(N), time(N), num(N){
        now = 0;
        for(int i = 0; i < N; ++i){
            par[i] = i;
            num[i].emplace_back(0, 1);
        }
        fill(rank.begin(), rank.begin() + N, 0);
        fill(time.begin(), time.begin() + N, INF);
    }

    int root(const int &x, const int &t){
        if(t < time[x]) return x;
        return root(par[x], t);
    }

    void unite(const int &x, const int &y){
        ++now;

        int rx = root(x, now);
        int ry = root(y, now);
        if(rx == ry) return;

        if(rank[rx] < rank[ry]) swap(rx, ry);
        num[rx].emplace_back(now, size(rx, now) + size(ry, now));

        par[ry] = rx;
        time[ry] = now;
        if(rank[rx] == rank[ry]) ++rank[rx];
    }

    bool same(const int &x, const int &y, const int &t){
        int rx = root(x, t);
        int ry = root(y, t);
        return rx == ry;
    }

    int size(const int &x, const int &t){
        int rx = root(x, t);

        int ok = 0, ng = num[rx].size();
        while(abs(ok - ng) > 1){
            int mid = (ok + ng) / 2;
            if(num[rx][mid].first <= t){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        return num[rx][ok].second;
    }
};