#pragma once

/**
 * @brief 2-SAT
 * @see https://zenn.dev/magurofly/articles/9d8417a17231db https://noshi91.hatenablog.com/entry/2019/10/03/184812
 */

#include "../graph/scc.hpp"

#include <vector>
#include <cassert>

struct TwoSAT{
    int N;
    SCC scc;
    std::vector<bool> ans;
    TwoSAT(const int N) : N(N), scc(2 * N){ }

    // ((x = f) or (y = g))
    void add_clause(int x, bool f, int y, bool g){
        assert(0 <= x && x < N);
        assert(0 <= y && y < N);
        int px = x * 2 + f, py = y * 2 + g;
        int nx = x * 2 + !f, ny = y * 2 + !g;
        scc.add_edge(nx, py);
        scc.add_edge(ny, px);
    }

    void build(){
        scc.build();
        for(int i = 0; i < N; i++){
            // x -> !x と !x -> x のパスが存在する場合は解なし
            if(scc.getId(i * 2) == scc.getId(i * 2 + 1)){
                return;
            }
        }
        int len = (int) scc.result.size();
        ans.resize(N);
        std::vector<bool> used(2 * N);
        for(int i = 0; i < len; i++){
            for(auto x : scc.result[i]){
                used[x] = 1;
                // x が 真 かつ !x が訪問済み -> !x -> x のパスが存在する可能性があるため 真 を割り当てる
                if(x % 2 == 1 && used[x ^ 1]){
                    ans[x / 2] = 1;
                    continue;
                }
            }
        }
    }

    std::vector<bool> getAnswer() const {
        return ans;
    }

};
