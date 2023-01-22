## Dijkstra's Algorithm (ダイクストラ法)

#### 概要

単一始点最短経路問題を解くことができるアルゴリズムです。

#### 使い方

- `dijkstra(G, x)`: グラフ G における x を始点とするそれぞれの頂点への最短距離を求めます。
- `shortest_path(G, s, t)`: グラフ G における s から t への最短パスを求めます。

#### 計算量

頂点数を $V$、辺の数を $E$ とすると、
- `dijkstra(G, x)`: $\mathrm{O}((E + V) \log V)$
- `shortest_path(G, s, t)`: $\mathrm{O}((E + V) \log V)$