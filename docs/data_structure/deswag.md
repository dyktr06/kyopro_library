## DESWAG

#### 使い方

- `DESWAG<T>(op)`: 両端 SWAG を構築します。
- `fold()`: 要素全てに op を適用させた値を計算します。
- `push_front(x)`: x を先頭に追加します。
- `push_back(x)`: x を末尾に追加します。
- `pop_front()`: 先頭の要素を削除します。
- `pop_back()`: 末尾の要素を削除します。

#### 計算量

- `fold()`: $\mathrm{O}(1)$
- `push_front(x)`: $\mathrm{O}(1)$
- `push_back(x)`: $\mathrm{O}(1)$
- `pop_front()`: 償却 $\mathrm{O}(1)$
- `pop_back()`: 償却 $\mathrm{O}(1)$