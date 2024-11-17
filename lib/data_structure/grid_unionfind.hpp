#pragma once

/**
 * @brief Grid Union-Find
 */

#include <vector>
#include <string>
#include <algorithm>

struct GridUnionFind{
    struct UnionFind{
        std::vector<int> par;

        UnionFind(){}

        void init(int N){
            par.resize(N);
            for(int i = 0; i < N; ++i){
                par[i] = -1;
            }
        }

        int root(int x){
            if(par[x] < 0) return x;
            return par[x] = root(par[x]);
        }

        void unite(int x, int y){
            int rx = root(x);
            int ry = root(y);
            if(rx == ry){
                return;
            }
            if(-par[rx] < -par[ry]) std::swap(rx, ry);
            par[rx] = par[rx] + par[ry];
            par[ry] = rx;
        }

        bool same(int x, int y){
            int rx = root(x);
            int ry = root(y);
            return rx == ry;
        }

        long long size(int x){
            return -par[root(x)];
        }
    };

    std::vector<std::string> grid;
    int h, w;
    UnionFind uf;
    char empty = '$';

    GridUnionFind(int _h, int _w) : h(_h), w(_w){
        grid = std::vector<std::string>(h, std::string(w, empty));
        uf.init(h * w);
    }

    GridUnionFind(std::vector<std::string> &s){
        grid = s;
        h = s.size(), w = s[0].size();
        uf.init(h * w);
    }

    int id(int x, int y){
        return x * w + y;
    }

    bool check(int x, int y){
        return (std::clamp(x, 0, h - 1) == x && std::clamp(y, 0, w - 1) == y);
    }

    void build(){
        std::vector<std::pair<int, int>> d = {
            {0, 1},
            {1, 0}
        };
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                for(auto &[dx, dy] : d){
                    int tx = i + dx, ty = j + dy;
                    if(check(tx, ty)){
                        if(grid[i][j] == grid[tx][ty] && grid[i][j] != empty){
                            uf.unite(id(i, j), id(tx, ty));
                        }
                    }
                }
            }
        }
    }

    std::pair<int, int> root(int x, int y){
        int r = uf.root(id(x, y));
        return {r / w, r % w};
    }

    bool same(int x1, int y1, int x2, int y2){
        if(!check(x1, y1) || !check(x2, y2)){
            return false;
        }
        return uf.same(id(x1, y1), id(x2, y2));
    }

    void update(int x, int y, char c){
        if(!check(x, y) || grid[x][y] != empty){
            return;
        }

        std::vector<std::pair<int, int>> d = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        grid[x][y] = c;
        for(auto &[dx, dy] : d){
            int tx = x + dx, ty = y + dy;
            if(check(tx, ty)){
                if(grid[x][y] == grid[tx][ty] && grid[x][y] != empty){
                    uf.unite(id(x, y), id(tx, ty));
                }
            }
        }
    }

    long long size(int x, int y){
        return uf.size(id(x, y));
    }
};
