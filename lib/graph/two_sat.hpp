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
        ans.resize(N);
        for(int i = 0; i < N; i++){
            // !x -> x のパスが存在する可能性があるなら 真 を割り当てる
            ans[i] = scc.getId(i * 2) < scc.getId(i * 2 + 1);
        }
    }

    std::vector<bool> getAnswer() const {
        return ans;
    }
};
