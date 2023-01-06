## Segment Tree

#### 使い方

- `SegTree<X>(N, fx, ex)`: モノイド(集合 X, 二項演算 fx, 単位元 ex) について Segment Tree をサイズ N で構築します。
- `get(i)`: i 番目の要素を取得します。
- `update(i, x)`: i 番目の要素を x に更新します。
- `query(a, b)`: 区間 `[a, b)` の全てに fx を作用させた値を取得します。

#### 計算量

- `get(i)`: $\mathrm{O}(1)$
- `update(i, x)`: $\mathrm{O}(\log N)$
- `query(a, b)`: $\mathrm{O}(\log N)$