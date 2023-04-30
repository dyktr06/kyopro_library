#pragma once

/**
 * @brief Strongly Connected Component (強連結成分分解)
 * @docs docs/graph/scc.md
 */

template <typename T>
struct SCC{
    int siz;
    vector<vector<T>> G_reverse;
    vector<bool> check;
    vector<int> memo;
    vector<T> s;
    vector<vector<T>> result;
 
    SCC(const vector<vector<T>> &G) : G_reverse((int) G.size()), check((int) G.size()){
        siz = (int) G.size();
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
                result.emplace_back(s);
            }
        }
    }
 
    void dfs(const vector<vector<T>> &G, int curr){
        check[curr] = true;
        for(const auto &x : G[curr]){
            if(check[x]){
                continue;
            }
            dfs(G, x);
        }
        memo.emplace_back(curr);
    }
 
    void dfs2(const vector<vector<T>> &G, int curr){
        s.emplace_back(curr);
        check[curr] = true;
        for(const auto &x : G[curr]){
            if(check[x]){
                continue;
            }
            dfs2(G, x);
        }
    }
 
    vector<vector<T>> get() const {
        return result;
    }
};