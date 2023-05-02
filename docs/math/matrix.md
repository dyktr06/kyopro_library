## Matrix

#### 概要

行列の構造体です。

#### 使い方

- `Matrix<T>(n, m)`: $n \times m$ の行列を作成します。
- `inv()`: 逆行列を求めます。
- `pow(r)`: $r$ 乗した行列を求めます。
- `det()`: 行列式の値を求めます。
- `rotate()`: $90$ 度回転します。

#### 計算量

- `Matrix<T>(n, m)`: $\mathrm{O}(nm)$

行列のサイズを $N \times M$ とします。

- `inv()`: $\mathrm{O}(N^3)$
- `pow(r)`: $\mathrm{O}(NM^2 \log r)$
- `det()`: $\mathrm{O}(N^3)$
- `rotate()`: $\mathrm{O}(NM)$