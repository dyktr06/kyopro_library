## Biconnected Components (二重頂点連結成分分解)

#### 概要

グラフについて、二重頂点連結成分分解を行います。

#### 使い方

- `BiconnectedComponents(node_size)`: コンストラクタ (node_size は頂点数)
- `add_edge(u, v)`: 頂点 $u$ から 頂点 $v$ に無向辺を追加します。
- `build()`: 二重頂点連結成分分解の計算を行います。
- `get()`: 二重頂点連結成分分解のそれぞれの連結成分を返します。

#### 計算量

頂点数を $V$、辺の数を $E$ とすると、$\mathrm{O}(E + V)$
