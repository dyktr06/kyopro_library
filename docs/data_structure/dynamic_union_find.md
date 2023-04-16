## Dynamic Union Find

#### 概要

内部実装に連想配列を用いた Union Find です。

大きい頂点番号が出てくる場合にも使用できます。

#### 使い方

- `DynamicUnionFind(N)`: 要素数 N の Union Find を構築します。
- `root(x)`: 集合 x の根を取得します。
- `unite(x, y)`: 集合 x と y を併合します。
- `same(x, y)`: x と y の属する集合が等しいかどうかを判定します。
- `size(x)`: x の属する集合の大きさを取得します。
- `edge(x)`: x の属する集合に張られている辺の本数を取得します。

#### 計算量

- `root(x)`: 償却 $\alpha(N)$ (アッカーマンの逆関数)
- `unite(x, y)`: 償却 $\alpha(N)$
- `same(x, y)`: 償却 $\alpha(N)$
- `size(x)`: 償却 $\alpha(N)$
- `edge(x)`: 償却 $\alpha(N)$