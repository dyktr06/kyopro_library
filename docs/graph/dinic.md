## Dinic's Algorithm

#### 概要

グラフについて、最大流を求めます。

#### 使い方

- `Dinic(n)`: コンストラクタ (n は頂点数)
- `add_edge(from, to, cap)`: 頂点 from から 頂点 to に最大容量 cap の有向辺を追加します。
- `flow(s, t)`: 頂点 $s$ から 頂点 $t$ の最大流の流量を求めます。

#### 計算量

- `Dinic(n)`: $\mathrm{O}(n)$
- `add_edge(from, to, cap)`: $\mathrm{O}(1)$

以降は、頂点数を $V$、追加された辺の数を $E$ とします。

- `flow(s, t, f)`: $\mathrm{O}(V^2 E)$
