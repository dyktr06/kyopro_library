## Partly Persistent Union Find

#### 使い方

- `PersistentUnionFind(N)`: コンストラクタ (N は要素数)
- `root(x, t)`: 時刻 t において集合 x の根を取得します。
- `unite(x, y)`: 集合 x と y を併合します。
- `same(x, y, t)`: 時刻 t において x と y の属する集合が等しいかどうかを判定します。
- `size(x, t)`:  時刻 t において x の属する集合の大きさを取得します。

#### 計算量

- `PersistentUnionFind(N)`: $\mathrm{O}(N)$
- `root(x, t)`: $\alpha(\log N)$
- `unite(x, y)`: $\alpha(\log N)$
- `same(x, y)`: $\alpha(\log N)$
- `size(x)`: $\alpha(\log N)$
