## Tree Diameter (木の直径)

#### 概要

木の直径を求めます。

最初は直径のパスを全て求める設計にしようと思いましたが、端点のみで妥協しています。

#### 使い方

- `TreeDiamiter(n)`: コンストラクタ (n は頂点数)
- `add_edge(u, v)`: 頂点 $u$ から 頂点 $v$ に無向辺を追加します。
- `build()`: 重軽分解を行います。
- `diameter()`: 木の直径の長さを求めます（辺の本数）
- `endpoint()`: 木の直径の端の頂点を求めます。

#### 計算量

頂点数を $V$ とします。
- `TreeDiamiter(n)`: $\mathrm{O}(V)$
- `add_edge(u, v)`: $\mathrm{O}(1)$
- `build()`: $\mathrm{O}(V)$
- `diameter()`: $\mathrm{O}(1)$
- `endpoint()`: $\mathrm{O}(1)$
