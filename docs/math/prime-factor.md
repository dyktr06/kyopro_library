## Smallest Prime Factor

#### 概要

各数に対する最小の素因数を前計算しておくことによって、素因数分解を高速に行います。

#### 使い方

- `PrimeFactor(N)`: $N$ までの前計算を行います。
- `get(n)`: $n$ について素因数分解を行います。

#### 計算量

- `PrimeFactor(N)`: $\mathrm{O}(N \log \log N)$
- `get(n)`: $\mathrm{O}(\log^2 N)$