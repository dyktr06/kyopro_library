## Cumulative Sum 2D (二次元累積和)

#### 使い方

- `CumulativeSum2D<T>(H, W)`: コンストラクタ
- `add(x, y, z)`: (x, y) に z を加算します。
- `imos(x1, y1, x2, y2, z)`: いもす法において、[(x1, y1), (x2, y2)) に v を加算します。
- `build()`: 加算された配列を構築します。
- `sum(x1, y1, x2, y2)`: [(x1, y1), (x2, y2)) の和を取得します。

#### 計算量

- `CumulativeSum2D<T>(H, W)`: $\mathrm{O}(HW)$
- `add(x, y, z)`: $\mathrm{O}(1)$
- `imos(x1, y1, x2, y2, z)`: $\mathrm{O}(1)$
- `build()`: $\mathrm{O}(HW)$
- `sum(x1, y1, x2, y2)`: $\mathrm{O}(1)$
