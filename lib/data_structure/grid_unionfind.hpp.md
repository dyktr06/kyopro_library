---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/yuki_2946.test.cpp
    title: test/yukicoder/yuki_2946.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Grid Union-Find
    links: []
  bundledCode: "#line 2 \"lib/data_structure/grid_unionfind.hpp\"\n\n/**\n * @brief\
    \ Grid Union-Find\n */\n\n#include <vector>\n#include <string>\n#include <algorithm>\n\
    \nstruct GridUnionFind{\n    struct UnionFind{\n        std::vector<int> par;\n\
    \n        UnionFind(){}\n\n        void init(int N){\n            par.resize(N);\n\
    \            for(int i = 0; i < N; ++i){\n                par[i] = -1;\n     \
    \       }\n        }\n\n        int root(int x){\n            if(par[x] < 0) return\
    \ x;\n            return par[x] = root(par[x]);\n        }\n\n        void unite(int\
    \ x, int y){\n            int rx = root(x);\n            int ry = root(y);\n \
    \           if(rx == ry){\n                return;\n            }\n          \
    \  if(-par[rx] < -par[ry]) std::swap(rx, ry);\n            par[rx] = par[rx] +\
    \ par[ry];\n            par[ry] = rx;\n        }\n\n        bool same(int x, int\
    \ y){\n            int rx = root(x);\n            int ry = root(y);\n        \
    \    return rx == ry;\n        }\n\n        long long size(int x){\n         \
    \   return -par[root(x)];\n        }\n    };\n\n    std::vector<std::string> grid;\n\
    \    int h, w;\n    UnionFind uf;\n    char empty = '$';\n\n    GridUnionFind(int\
    \ _h, int _w) : h(_h), w(_w){\n        grid = std::vector<std::string>(h, std::string(w,\
    \ empty));\n        uf.init(h * w);\n    }\n\n    GridUnionFind(std::vector<std::string>\
    \ &s){\n        grid = s;\n        h = s.size(), w = s[0].size();\n        uf.init(h\
    \ * w);\n    }\n\n    int id(int x, int y){\n        return x * w + y;\n    }\n\
    \n    bool check(int x, int y){\n        return (std::clamp(x, 0, h - 1) == x\
    \ && std::clamp(y, 0, w - 1) == y);\n    }\n\n    void build(){\n        std::vector<std::pair<int,\
    \ int>> d = {\n            {0, 1},\n            {1, 0}\n        };\n        for(int\
    \ i = 0; i < h; i++){\n            for(int j = 0; j < w; j++){\n             \
    \   for(auto &[dx, dy] : d){\n                    int tx = i + dx, ty = j + dy;\n\
    \                    if(check(tx, ty)){\n                        if(grid[i][j]\
    \ == grid[tx][ty] && grid[i][j] != empty){\n                            uf.unite(id(i,\
    \ j), id(tx, ty));\n                        }\n                    }\n       \
    \         }\n            }\n        }\n    }\n\n    std::pair<int, int> root(int\
    \ x, int y){\n        int r = uf.root(id(x, y));\n        return {r / w, r % w};\n\
    \    }\n\n    bool same(int x1, int y1, int x2, int y2){\n        if(!check(x1,\
    \ y1) || !check(x2, y2)){\n            return false;\n        }\n        return\
    \ uf.same(id(x1, y1), id(x2, y2));\n    }\n\n    void update(int x, int y, char\
    \ c){\n        if(!check(x, y) || grid[x][y] != empty){\n            return;\n\
    \        }\n\n        std::vector<std::pair<int, int>> d = {\n            {-1,\
    \ 0},\n            {1, 0},\n            {0, -1},\n            {0, 1}\n       \
    \ };\n        grid[x][y] = c;\n        for(auto &[dx, dy] : d){\n            int\
    \ tx = x + dx, ty = y + dy;\n            if(check(tx, ty)){\n                if(grid[x][y]\
    \ == grid[tx][ty] && grid[x][y] != empty){\n                    uf.unite(id(x,\
    \ y), id(tx, ty));\n                }\n            }\n        }\n    }\n\n   \
    \ long long size(int x, int y){\n        return uf.size(id(x, y));\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Grid Union-Find\n */\n\n#include <vector>\n\
    #include <string>\n#include <algorithm>\n\nstruct GridUnionFind{\n    struct UnionFind{\n\
    \        std::vector<int> par;\n\n        UnionFind(){}\n\n        void init(int\
    \ N){\n            par.resize(N);\n            for(int i = 0; i < N; ++i){\n \
    \               par[i] = -1;\n            }\n        }\n\n        int root(int\
    \ x){\n            if(par[x] < 0) return x;\n            return par[x] = root(par[x]);\n\
    \        }\n\n        void unite(int x, int y){\n            int rx = root(x);\n\
    \            int ry = root(y);\n            if(rx == ry){\n                return;\n\
    \            }\n            if(-par[rx] < -par[ry]) std::swap(rx, ry);\n     \
    \       par[rx] = par[rx] + par[ry];\n            par[ry] = rx;\n        }\n\n\
    \        bool same(int x, int y){\n            int rx = root(x);\n           \
    \ int ry = root(y);\n            return rx == ry;\n        }\n\n        long long\
    \ size(int x){\n            return -par[root(x)];\n        }\n    };\n\n    std::vector<std::string>\
    \ grid;\n    int h, w;\n    UnionFind uf;\n    char empty = '$';\n\n    GridUnionFind(int\
    \ _h, int _w) : h(_h), w(_w){\n        grid = std::vector<std::string>(h, std::string(w,\
    \ empty));\n        uf.init(h * w);\n    }\n\n    GridUnionFind(std::vector<std::string>\
    \ &s){\n        grid = s;\n        h = s.size(), w = s[0].size();\n        uf.init(h\
    \ * w);\n    }\n\n    int id(int x, int y){\n        return x * w + y;\n    }\n\
    \n    bool check(int x, int y){\n        return (std::clamp(x, 0, h - 1) == x\
    \ && std::clamp(y, 0, w - 1) == y);\n    }\n\n    void build(){\n        std::vector<std::pair<int,\
    \ int>> d = {\n            {0, 1},\n            {1, 0}\n        };\n        for(int\
    \ i = 0; i < h; i++){\n            for(int j = 0; j < w; j++){\n             \
    \   for(auto &[dx, dy] : d){\n                    int tx = i + dx, ty = j + dy;\n\
    \                    if(check(tx, ty)){\n                        if(grid[i][j]\
    \ == grid[tx][ty] && grid[i][j] != empty){\n                            uf.unite(id(i,\
    \ j), id(tx, ty));\n                        }\n                    }\n       \
    \         }\n            }\n        }\n    }\n\n    std::pair<int, int> root(int\
    \ x, int y){\n        int r = uf.root(id(x, y));\n        return {r / w, r % w};\n\
    \    }\n\n    bool same(int x1, int y1, int x2, int y2){\n        if(!check(x1,\
    \ y1) || !check(x2, y2)){\n            return false;\n        }\n        return\
    \ uf.same(id(x1, y1), id(x2, y2));\n    }\n\n    void update(int x, int y, char\
    \ c){\n        if(!check(x, y) || grid[x][y] != empty){\n            return;\n\
    \        }\n\n        std::vector<std::pair<int, int>> d = {\n            {-1,\
    \ 0},\n            {1, 0},\n            {0, -1},\n            {0, 1}\n       \
    \ };\n        grid[x][y] = c;\n        for(auto &[dx, dy] : d){\n            int\
    \ tx = x + dx, ty = y + dy;\n            if(check(tx, ty)){\n                if(grid[x][y]\
    \ == grid[tx][ty] && grid[x][y] != empty){\n                    uf.unite(id(x,\
    \ y), id(tx, ty));\n                }\n            }\n        }\n    }\n\n   \
    \ long long size(int x, int y){\n        return uf.size(id(x, y));\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/grid_unionfind.hpp
  requiredBy: []
  timestamp: '2024-11-18 04:07:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/yuki_2946.test.cpp
documentation_of: lib/data_structure/grid_unionfind.hpp
layout: document
redirect_from:
- /library/lib/data_structure/grid_unionfind.hpp
- /library/lib/data_structure/grid_unionfind.hpp.html
title: Grid Union-Find
---
