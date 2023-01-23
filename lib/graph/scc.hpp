#pragma once

/**
 * @brief Strongly Connected Component (強連結成分分解)
 * @docs docs/graph/scc.md
 */

template <typename T>
struct SCC{
    int siz;
    vector<vector<T>> G1, G2;
    vector<int> check;
    vector<int> memo;
    vector<T> s;
    vector<vector<T>> result;
 
    SCC(const vector<vector<T>> &G) : G2((int) G.size()), check((int) G.size()){
        siz = (int) G.size();
        G1 = G;
        for(int i = 0; i < siz; i++){
            for(auto x : G1[i]){
                G2[x].emplace_back(i);
            }
        }
 
        for(int i = 0; i < siz; i++){
            if(!check[i]){
                dfs(i);
            }
        }
        reverse(memo.begin(), memo.end());
 
        for(int i = 0; i < siz; i++) check[i] = 0;
        for(auto x : memo){
            if(!check[x]){
                s = {};
                dfs2(x);
                sort(s.rbegin(), s.rend());
                result.emplace_back(s);
            }
        }
    }
 
    void dfs(int curr){
        check[curr] = 1;
        for(auto x : G1[curr]){
            if(check[x]){
                continue;
            }
            dfs(x);
        }
        memo.emplace_back(curr);
    }
 
    void dfs2(int curr){
        s.push_back(curr);
        check[curr] = 1;
        for(auto x : G2[curr]){
            if(check[x]){
                continue;
            }
            dfs2(x);
        }
    }
 
    vector<vector<T>> get(){
        return result;
    }
};