## Eulerian Trail (オイラー小道)

#### 概要

グラフについて、オイラー小道を求めます。

#### 使い方

- `EulerianTrail(n, directed)`: コンストラクタ (n は頂点数、directed は有向かどうか)
- `add_edge(u, v)`: 頂点 $u$ から 頂点 $v$ に辺を追加します。
- `build()`: オイラー小道の計算を行います。存在しない場合は false が返ってきます。
- `getVertex()`: オイラー小道の頂点列を返します。
- `getEdge()`: オイラー小道の辺の列を返します。

#### 計算量

- `EulerianTrail(n, directed)`: $\mathrm{O}(n)$
- `add_edge(u, v)`: $\mathrm{O}(1)$

以降は、頂点数を $V$、追加された辺の数を $E$ とします。

- `build()`: $\mathrm{O}(E + V)$
- `getVertex()`: $\mathrm{O}(V)$
- `getEdge()`: $\mathrm{O}(E)$
