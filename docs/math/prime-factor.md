## Smallest Prime Factor

#### 概要

各数に対する最小の素因数を前計算しておくことによって、素因数分解を高速に行います。

#### 使い方

- `PrimeFactor(N)`: $N$ までの前計算を行います。
- `get(n)`: $n$ について素因数分解を行います。
- `getPair(n)`: $n$ について素因数分解を行います。(素因数と個数の組が返ってきます)

#### 計算量

- `PrimeFactor(N)`: $\mathrm{O}(N \log \log N)$
- `get(n)`: $\mathrm{O}(\log N)$
- `getPair(n)`: $\mathrm{O}(\log N)$
