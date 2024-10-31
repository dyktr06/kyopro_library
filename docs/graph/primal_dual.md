## Primal-Dual Algorithm

#### 概要

グラフについて、最小費用流を求めます。

#### 使い方

- `PrimalDual(n)`: コンストラクタ (n は頂点数)
- `add_edge(from, to, cap, cost)`: 頂点 from から 頂点 to に最大容量 cap、コスト cost の有向辺を追加します。
- `flow(s, t, f)`: 頂点 $s$ から 頂点 $t$ に流量 $f$ を流すのに必要な最小コストを求めます。
- `edges()`: 現在の内部のグラフの辺の状態をそれぞれ返します。

#### 計算量

- `PrimalDual(n)`: $\mathrm{O}(n)$
- `add_edge(from, to, cap, cost)`: $\mathrm{O}(1)$

以降は、頂点数を $V$、追加された辺の数を $E$ とします。

- `flow(s, t, f)`: $\mathrm{O}(f(V + E) \log (V + E))$
- `edges()`: $\mathrm{O}(E)$

