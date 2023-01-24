## Prime Sieve (エラトステネスの篩)

#### 概要

エラトステネスの篩により素数判定などを行うライブラリです。

$2$ の倍数は省略するといった高速化を行っています。

#### 使い方

- `PrimeSieve(N)`: $N$ 以下の正整数について、エラトステネスの篩を行います。
- `isPrime(x)`: $x$ について素数判定を行います。
- `getPrimeCount()`: $N$ 以下の素数の個数を求めます。
- `getKthPrime()`: $K$ 番目の素数を求めます。(0-indexed なことに注意)

#### 計算量

- `PrimeSieve(N)`: $\mathrm{O}(N \log \log N)$
- `isPrime(x)`: $\mathrm{O}(1)$
- `getPrimeCount()`: $\mathrm{O}(1)$
- `getKthPrime()`: $\mathrm{O}(1)$