## Heavy Light Decomposition (重軽分解)

#### 概要

木の重軽分解を行います。

#### 使い方

- `HeavyLightDecomposition(node_size)`: コンストラクタ (node_size は頂点数)
- `add_edge(u, v)`: 頂点 $u$ から 頂点 $v$ に無向辺を追加します。
- `build()`: 重軽分解を行います。
- `get(a)`: $a$ の重軽分解後の index を返します。
- `la(a, k)`: $a$ から根に向かって $k$ 移動した頂点を求めます。
- `lca(a, b)`: $a$ と $b$ の LCA を求めます。
- `dist(a, b)`: $a, b$ の距離を求めます。
- `jump(from, to, k)`: from から to に向かって $k$ だけ移動した頂点を求めます。
- `subtree_query(a, f)`: $a$ の部分木に対して $f$ を処理します。
- `path_query(a, b, f)`: $a$ と $b$ のパスに対して $f$ を処理します。
- `path_noncommutative_query(a, b, f, f2)`: $a$ と $b$ のパスに対して非可換な場合の f を処理します。(反転させた関数を f2 に渡します)

詳しい使い方などは verify のコードを参照してください。

#### 計算量

頂点数を $V$ とします。
- `HeavyLightDecomposition(node_size)`: $\mathrm{O}(V)$
- `add_edge(u, v)`: $\mathrm{O}(1)$
- `build()`: $\mathrm{O}(V \log V)$
- `get(a)`: $\mathrm{O}(1)$
- `la(a, k)`: $\mathrm{O}(\log V)$
- `lca(a, b)`: $\mathrm{O}(\log V)$
- `dist(a, b)`: $\mathrm{O}(\log V)$
- `jump(from, to, k)`: $\mathrm{O}(\log V)$
- `subtree_query(a, f)`: $\mathrm{O}(1)$
- `path_query(a, b, f)`: $\mathrm{O}(\log V)$
- `path_noncommutative_query(a, b, f, f2)`: $\mathrm{O}(\log V)$

subtree_query, path_query, path_noncommutative_query については、$f$ の計算量が $\mathrm{O}(f(n))$ である場合には実際の計算量は $\mathrm{O}(f(n))$ 倍になります。