## Combination (二項係数)

#### 概要

二項係数を求めるライブラリです。

#### 使い方

$m$ が素数でないと使えないため注意。

- `Combination(N, m)`: $N$ までの二項係数 (mod. m) を前計算します。
- `fact(n)`: $n!$ を求めます。
- `factinv(n)`: $n!$ の逆元を求めます。
- `ncr(n, r)`: $nCr$ を求めます。
- `npr(n, r)`: $nPr$ を求めます。
- `nhr(n, r)`: $nHr$ を求めます。

以下のものは $m$ が素数でなくても使えますが、上述のものよりも計算量が悪いです。

- `CombinationByPascal(N, m)`: $N$ までの二項係数 (mod. m) を前計算します。
- `ncr(n, r)`: $nCr$ を求めます。

#### 計算量

- `Combination(N, m)`: $\mathrm{O}(N)$
- `fact(n)`: $\mathrm{O}(1)$
- `factinv(n)`: $\mathrm{O}(1)$
- `ncr(n, r)`: $\mathrm{O}(1)$
- `npr(n, r)`: $\mathrm{O}(1)$
- `nhr(n, r)`: $\mathrm{O}(1)$

CombinationByPascal についての計算量

- `CombinationByPascal(N, m)`: $\mathrm{O}(N^2)$
- `ncr(n, r)`: $\mathrm{O}(1)$