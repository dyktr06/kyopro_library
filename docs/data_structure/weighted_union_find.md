## Weighted Union Find

#### 使い方

- `WeightedUnionFind(N)`: 要素数 N の Weighted Union Find を構築します。
- `root(x)`: 集合 x の根を取得します。
- `diff(x, y)`: x と y の重みの差を取得します。
- `unite(x, y, w)`: 集合 x と y について、重みが w として併合します。
- `same(x, y)`: x と y の属する集合が等しいかどうかを判定します。
- `size(x)`: x の属する集合の大きさを取得します。

#### 計算量

- `WeightedUnionFind(N)`: $\mathrm{O}(N)$
- `root(x)`: $\mathrm{O}(\log N)$
- `diff(x, y)`: $\mathrm{O}(\log N)$
- `unite(x, y, w)`: $\mathrm{O}(\log N)$
- `same(x, y)`: $\mathrm{O}(\log N)$
- `size(x)`: $\mathrm{O}(\log N)$
