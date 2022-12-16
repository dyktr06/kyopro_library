---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/grid_unionfind.hpp\"\n\nstruct GridUnionFind{\n\
    \    struct UnionFind{\n        vector<int> par;\n        vector<int> siz;\n\n\
    \        UnionFind(){}\n\n        void init(int N){\n            par.resize(N),\
    \ siz.resize(N);\n            for(int i = 0; i < N; ++i){\n                par[i]\
    \ = i;\n                siz[i] = 1;\n            }\n        }\n\n        int root(int\
    \ x) {\n            if (par[x] == x) return x;\n            return par[x] = root(par[x]);\n\
    \        }\n\n        void unite(int x, int y) {\n            int rx = root(x);\n\
    \            int ry = root(y);\n            par[rx] = ry;\n            siz[ry]\
    \ += siz[rx];\n        }\n\n        bool same(int x, int y){\n            int\
    \ rx = root(x);\n            int ry = root(y);\n            return rx == ry;\n\
    \        }\n\n        long long size(int x){\n            return siz[root(x)];\n\
    \        }\n    };\n\n    vector<string> grid;\n    int h, w;\n    UnionFind uf;\n\
    \    vector<int> dx = {0, 1};\n    vector<int> dy = {1, 0};\n\n    GridUnionFind(vector<string>\
    \ &s){\n        grid = s;\n        h = s.size(), w = s[0].size();\n        uf.init(h\
    \ * w);\n    }\n\n    int id(int x, int y){\n        return x * w + y;\n    }\n\
    \n    bool check(int x, int y){\n        return (clamp(x, 0, h - 1) == x && clamp(y,\
    \ 0, w - 1) == y);\n    }\n\n    void build(){\n        for(int i = 0; i < h;\
    \ i++){\n            for(int j = 0; j < w; j++){\n                for(int k =\
    \ 0; k < 2; k++){\n                    int tx = i + dx[k], ty = j + dy[k];\n \
    \                   if(clamp(tx, 0, h - 1) == tx && clamp(ty, 0, w - 1) == ty){\n\
    \                        if(grid[i][j] == grid[tx][ty]){\n                   \
    \         uf.unite(id(i, j), id(tx, ty));\n                        }\n       \
    \             }\n                }\n            }\n        }\n    }\n\n    pair<int,\
    \ int> root(int x, int y){\n        int r = uf.root(id(x, y));\n        return\
    \ {r / w, r % w};\n    }\n\n    bool same(int x1, int y1, int x2, int y2){\n \
    \       if(!check(x1, y1) || !check(x2, y2)){\n            return false;\n   \
    \     }\n        return uf.same(id(x1, y1), id(x2, y2));\n    }\n\n    long long\
    \ size(int x, int y){\n        return uf.size(id(x, y));\n    }\n};\n"
  code: "#pragma once\n\nstruct GridUnionFind{\n    struct UnionFind{\n        vector<int>\
    \ par;\n        vector<int> siz;\n\n        UnionFind(){}\n\n        void init(int\
    \ N){\n            par.resize(N), siz.resize(N);\n            for(int i = 0; i\
    \ < N; ++i){\n                par[i] = i;\n                siz[i] = 1;\n     \
    \       }\n        }\n\n        int root(int x) {\n            if (par[x] == x)\
    \ return x;\n            return par[x] = root(par[x]);\n        }\n\n        void\
    \ unite(int x, int y) {\n            int rx = root(x);\n            int ry = root(y);\n\
    \            par[rx] = ry;\n            siz[ry] += siz[rx];\n        }\n\n   \
    \     bool same(int x, int y){\n            int rx = root(x);\n            int\
    \ ry = root(y);\n            return rx == ry;\n        }\n\n        long long\
    \ size(int x){\n            return siz[root(x)];\n        }\n    };\n\n    vector<string>\
    \ grid;\n    int h, w;\n    UnionFind uf;\n    vector<int> dx = {0, 1};\n    vector<int>\
    \ dy = {1, 0};\n\n    GridUnionFind(vector<string> &s){\n        grid = s;\n \
    \       h = s.size(), w = s[0].size();\n        uf.init(h * w);\n    }\n\n   \
    \ int id(int x, int y){\n        return x * w + y;\n    }\n\n    bool check(int\
    \ x, int y){\n        return (clamp(x, 0, h - 1) == x && clamp(y, 0, w - 1) ==\
    \ y);\n    }\n\n    void build(){\n        for(int i = 0; i < h; i++){\n     \
    \       for(int j = 0; j < w; j++){\n                for(int k = 0; k < 2; k++){\n\
    \                    int tx = i + dx[k], ty = j + dy[k];\n                   \
    \ if(clamp(tx, 0, h - 1) == tx && clamp(ty, 0, w - 1) == ty){\n              \
    \          if(grid[i][j] == grid[tx][ty]){\n                            uf.unite(id(i,\
    \ j), id(tx, ty));\n                        }\n                    }\n       \
    \         }\n            }\n        }\n    }\n\n    pair<int, int> root(int x,\
    \ int y){\n        int r = uf.root(id(x, y));\n        return {r / w, r % w};\n\
    \    }\n\n    bool same(int x1, int y1, int x2, int y2){\n        if(!check(x1,\
    \ y1) || !check(x2, y2)){\n            return false;\n        }\n        return\
    \ uf.same(id(x1, y1), id(x2, y2));\n    }\n\n    long long size(int x, int y){\n\
    \        return uf.size(id(x, y));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/grid_unionfind.hpp
  requiredBy: []
  timestamp: '2022-12-16 23:31:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/grid_unionfind.hpp
layout: document
redirect_from:
- /library/lib/data_structure/grid_unionfind.hpp
- /library/lib/data_structure/grid_unionfind.hpp.html
title: lib/data_structure/grid_unionfind.hpp
---
