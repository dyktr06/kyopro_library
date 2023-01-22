## SWAG

#### 使い方

- `SWAG<T>(op)`: SWAG を構築します。
- `fold()`: 要素全てに op を適用させた値を計算します。
- `push(x)`: x を先頭に追加します。
- `pop()`: 先頭の要素を削除します。

#### 計算量

- `fold()`: $\mathrm{O}(1)$
- `push(x)`: $\mathrm{O}(1)$
- `pop()`: 償却 $\mathrm{O}(1)$