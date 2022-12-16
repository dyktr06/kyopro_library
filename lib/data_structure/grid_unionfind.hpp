#pragma once

struct GridUnionFind{
    struct UnionFind{
        vector<int> par;
        vector<int> siz;

        UnionFind(){}

        void init(int N){
            par.resize(N), siz.resize(N);
            for(int i = 0; i < N; ++i){
                par[i] = i;
                siz[i] = 1;
            }
        }

        int root(int x) {
            if (par[x] == x) return x;
            return par[x] = root(par[x]);
        }

        void unite(int x, int y) {
            int rx = root(x);
            int ry = root(y);
            par[rx] = ry;
            siz[ry] += siz[rx];
        }

        bool same(int x, int y){
            int rx = root(x);
            int ry = root(y);
            return rx == ry;
        }

        long long size(int x){
            return siz[root(x)];
        }
    };

    vector<string> grid;
    int h, w;
    UnionFind uf;
    vector<int> dx = {0, 1};
    vector<int> dy = {1, 0};

    GridUnionFind(vector<string> &s){
        grid = s;
        h = s.size(), w = s[0].size();
        uf.init(h * w);
    }

    int id(int x, int y){
        return x * w + y;
    }

    bool check(int x, int y){
        return (clamp(x, 0, h - 1) == x && clamp(y, 0, w - 1) == y);
    }

    void build(){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                for(int k = 0; k < 2; k++){
                    int tx = i + dx[k], ty = j + dy[k];
                    if(clamp(tx, 0, h - 1) == tx && clamp(ty, 0, w - 1) == ty){
                        if(grid[i][j] == grid[tx][ty]){
                            uf.unite(id(i, j), id(tx, ty));
                        }
                    }
                }
            }
        }
    }

    pair<int, int> root(int x, int y){
        int r = uf.root(id(x, y));
        return {r / w, r % w};
    }

    bool same(int x1, int y1, int x2, int y2){
        if(!check(x1, y1) || !check(x2, y2)){
            return false;
        }
        return uf.same(id(x1, y1), id(x2, y2));
    }

    long long size(int x, int y){
        return uf.size(id(x, y));
    }
};