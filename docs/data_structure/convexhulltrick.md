## Convex Hull Trick

#### 使い方

注意: 追加される直線の傾きが単調増加、計算する最小値の座標が単調増加である必要があります。(単調でない場合は Dynamic Li Chao Tree を使う。)

- `ConvexHullTrick<T>()`: ConvexHullTrick を構築します。
- `add(a, b)`: 直線集合に ax + b の直線を追加します。
- `query(x)`: x で最小値をとるような値を求めます。

#### 計算量

- `add(a, b)`: $\mathrm{O}(1)$
- `query(x)`: $\mathrm{O}(1)$