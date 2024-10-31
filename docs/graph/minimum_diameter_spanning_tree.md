## Minimum Diameter Spanning Tree (最小直径全域木)

#### 概要

グラフについて、最小直径全域木を求めます。

#### 使い方

- `MinimumDiameterSpanningTree(n)`: コンストラクタ (n は頂点数)
- `add_edge(u, v, cost)`: 頂点 $u$ から 頂点 $v$ にコスト cost の無向辺を追加します。
- `build()`: 最小直径全域木の計算を行います。
- `get()`: 最小直径全域木の辺を返します。（辺を追加した順番で番号が振られたものが返ってきます）
- `getTreeDiamater()`: 最小直径全域木の直径を返します。

#### 計算量

- `MinimumDiameterSpanningTree(n)`: $\mathrm{O}(n)$
- `add_edge(u, v, cost)`: $\mathrm{O}(1)$

以降は、頂点数を $V$、追加された辺の数を $E$ とします。

- `build()`: $\mathrm{O}(EV \log V)$
- `get()`: $\mathrm{O}(V)$
- `getTreeDiamater()`: $\mathrm{O}(1)$
