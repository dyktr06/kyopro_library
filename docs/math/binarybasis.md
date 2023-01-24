## Binary Basis

#### 概要

数の集合に対する XOR 基底を求めます。

#### 使い方

- `BinaryBasis(vec)`: 集合 vec について、XOR 基底を求めます。
- `add(x)`: $x$ を基底の集合に追加します。
- `exist(x)`: 基底の集合の中から XOR を繰り返して $x$ を作れるかどうかを判定します。
- `normalize()`: 基底の集合を整理します。
- `kth_element(k)`: 基底から生成できる数の集合の $k$ 番目を取得します。(0-indexed なことに注意)
- `size(x)`: 基底の集合の大きさを取得します。

#### 計算量

集合の中の最大値を $A$ とします。

- `BinaryBasis(vec)`: vec の要素数を $N$ とすると、$\mathrm{O}(N \log A)$
- `add(x)`: $\mathrm{O}(\log A)$
- `exist(x)`: $\mathrm{O}(\log A)$
- `normalize()`: $\mathrm{O}(\log^2 A)$
- `kth_element(k)`: $\mathrm{O}(\log A)$
- `size(x)`: $\mathrm{O}(1)$