## Compression (座標圧縮)

#### 使い方

- `compress<T>(vec)`: vec を座標圧縮します。
- `get(x)`: x の座標圧縮後の値を取得します。
- `inv(x)`: x の座標圧縮前の値を取得します。
- `getCompressed()`: 座標圧縮後の配列を取得します。

#### 計算量

- `compress<T>(vec)`: $\mathrm{O}(N \log N)$
- `get(x)`: $\mathrm{O}(\log N)$
- `inv(x)`: $\mathrm{O}(1)$
- `getCompressed()`: $\mathrm{O}(N)$