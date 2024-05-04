#pragma once

struct IntervalGraph{
    int n;
    vector<vector<int>> G;

    IntervalGraph(int n_) : n(){
        int x = 1;
        while(n_ > x){
            x *= 2;
        }
        n = x;
        G.resize(n * 2);

        for(int i = n - 1; i > 0; i--){
            G[i].push_back(i * 2);
            G[i].push_back(i * 2 + 1);
        }
    }

    int get(int x){
        return x + n;
    }

    int inv(int x){
        return x - n;
    }

    // [a, b)
    void add_edge(int x, int a, int b){
        int l = a + n;
        int r = b + n;
        while(l < r){
            if(l & 1) G[x + n].push_back(l++);
            if(r & 1) G[x + n].push_back(--r);
            l >>= 1;
            r >>= 1;
        }
    }
};
