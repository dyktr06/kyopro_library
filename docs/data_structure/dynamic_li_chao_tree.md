## Dynamic Li Chao Tree

#### 使い方

- `DynamicLiChaoTree<T, x_low, x_high, id>()`: Dynamic Li Chao Tree を構築します。x_low に $x$ の最小値、x_high に $x$ の最大値、id に十分大きい値 (単位元) を設定します。
- `add_line(a, b)`: ax + b の直線を追加します。
- `add_segment(l, r, a, b)`: `[l, r)` に ax + b の直線を追加します。
- `query(x)`: x で最小値をとるような値を求めます。

#### 計算量

$R$ を $x$ の範囲とすると

- `add(a, b)`: $\mathrm{O}(\log R)$
- `add_segment(l, r, a, b)`: $\mathrm{O}(\log^2 R)$
- `query(x)`: $\mathrm{O}(\log R)$