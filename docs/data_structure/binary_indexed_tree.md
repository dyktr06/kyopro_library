## Binary Indexed Tree

#### 使い方

- `BinaryIndexedTree<T>(N)`: 要素数 $N$ のBITを構築します。
- `add(i, x)`: i 番目の要素に x を加算します。
- `get(i)`: i 番目の要素を取得します。
- `sum(i)`: 区間 `[0, i)`の和を取得します。
- `sum(l, r)`: 区間 `[l, r)` の和を取得します。
- `lower_bound(x)`: 要素が全て非負である時、`[0, k)`の区間和が x 以上となるような最小の k を求めます。
- `upper_bound(x)`: 要素が全て非負である時、`[0, k)`の区間和が x より大きくなるような最小の k を求めます。

#### 計算量

- `add(i, x)`: $\mathrm{O}(\log N)$
- `get(i)`: $\mathrm{O}(\log N)$
- `sum(i)`: $\mathrm{O}(\log N)$
- `sum(l, r)`: $\mathrm{O}(\log N)$
- `lower_bound(x)`: $\mathrm{O}(\log N)$
- `upper_bound(x)`: $\mathrm{O}(\log N)$