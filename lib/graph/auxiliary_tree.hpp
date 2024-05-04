#pragma once

#include "../graph/heavy_light_decomposition.hpp"

struct AuxiliaryTree : HeavyLightDecomposition{
    using super = HeavyLightDecomposition;

private:
    void add_aux_edge(int u, int v){
        T[u].emplace_back(v);
        T[v].emplace_back(u);
    }

public:
    vector<vector<int>> T;
    AuxiliaryTree(int n) : super(n), T(n){}

    void build(int _root = 0){
        super::build(_root);
    }

    void query(vector<int> &vs){
        assert(!vs.empty());
        sort(vs.begin(), vs.end(),
            [&](int a, int b){ return in[a] < in[b]; });
        vs.erase(unique(vs.begin(), vs.end()), vs.end());

        int k = vs.size();
        vector<int> st;
        st.emplace_back(vs[0]);
        for(int i = 0; i + 1 < k; i++){
            int p = lca(vs[i], vs[i + 1]);
            if(p != vs[i]){
                int l = st.back(); st.pop_back();
                while(!st.empty() && depth[p] < depth[st.back()]){
                    add_aux_edge(st.back(), l);
                    l = st.back(); st.pop_back();
                }
                if(st.empty() || st.back() != p){
                    st.emplace_back(p);
                    vs.emplace_back(p);
                }
                add_aux_edge(p, l);
            }
            st.emplace_back(vs[i + 1]);
        }

        while(st.size() > 1){
            int c = st.back(); st.pop_back();
            add_aux_edge(st.back(), c);
        }
    }

    void clear(const vector<int> &ws){
        for(int w : ws){
            T[w].clear();
        }
    }
};
