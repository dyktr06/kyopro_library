## Matrix

#### 概要

行列についての関数をまとめています。

#### 使い方

- `matrixpow(a, n, m)`: 行列 $a$ の $n$ 乗 (mod. m) を求めます。
- `mul(a, b, m)`: 行列 $a$ と $b$ の行列積 (mod. m) を求めます。

#### 計算量

行列のサイズを $N \times N$ とします。

- `matrixpow(a, n, m)`: $\mathrm{O}(N^3 \log n)$
- `mul(a, b, m)`: $\mathrm{O}(N^3)$