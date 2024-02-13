## Rolling Hash

#### 使い方

- `RollingHash(s, base)`: 文字列 s について、基数を base としたハッシュテーブルを構築します。
- `get(l, r)`: [l, r) のハッシュ値を取得します。
- `connect(h1, h2, h2len)`: ハッシュ値 h1 と長さ h2len のハッシュ値 h2 を結合します。
- `LCP(b, l1, r1, l2, r2)`: 区間 [l1, r1) と ハッシュテーブルが b となる区間 [l2, r2) の文字列の最長接頭辞を求めます。

#### 計算量

- `RollingHash(s, base)`: $\mathrm{O}(\lvert S\lvert)$
- `get(l, r)`: $\mathrm{O}(1)$
- `connect(h1, h2, h2len)`: $\mathrm{O}(1)$
- `LCP(b, l1, r1, l2, r2)`: $\mathrm{O}(\log \lvert S\lvert)$