#pragma once

/**
 * @brief Strongly Connected Component (強連結成分分解)
 * @docs docs/graph/scc.md
 */

#include <vector>
#include <cassert>
#include <algorithm>

struct SCC{
    int siz;
    std::vector<std::vector<int>> G, G_reverse, G_compress;
    std::vector<bool> check;
    std::vector<int> memo, id;
    std::vector<int> s;
    std::vector<std::vector<int>> result;

    SCC(const int N) : siz(N), G(N), G_reverse(N), check(N), id(N){ }

    void add_edge(int u, int v){
        assert(0 <= u && u < siz);
        assert(0 <= v && v < siz);
        G[u].emplace_back(v);
    }

    void build(){
        for(int i = 0; i < siz; ++i){
            for(const auto &x : G[i]){
                G_reverse[x].emplace_back(i);
            }
        }

        for(int i = 0; i < siz; ++i){
            if(!check[i]){
                dfs(G, i);
            }
        }
        reverse(memo.begin(), memo.end());

        for(int i = 0; i < siz; ++i) check[i] = false;
        for(const auto &x : memo){
            if(!check[x]){
                s = {};
                dfs2(G_reverse, x);
                for(const auto &y : s){
                    id[y] = (int) result.size();
                }
                result.emplace_back(s);
            }
        }

        G_compress.resize(result.size());
        for(int i = 0; i < siz; ++i){
            for(const auto &x : G[i]){
                if(id[i] != id[x]){
                    G_compress[id[i]].emplace_back(id[x]);
                }
            }
        }
    }

    void dfs(const std::vector<std::vector<int>> &G, int curr){
        check[curr] = true;
        for(const auto &x : G[curr]){
            if(check[x]){
                continue;
            }
            dfs(G, x);
        }
        memo.emplace_back(curr);
    }

    void dfs2(const std::vector<std::vector<int>> &G, int curr){
        s.emplace_back(curr);
        check[curr] = true;
        for(const auto &x : G[curr]){
            if(check[x]){
                continue;
            }
            dfs2(G, x);
        }
    }

    std::vector<std::vector<int>> get() const {
        return result;
    }

    std::vector<std::vector<int>> getCompressed() const {
        return G_compress;
    }

    int getId(int x) const {
        return id[x];
    }
};
