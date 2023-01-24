## 素数判定、約数列挙

### 概要

素数判定、約数列挙などのアルゴリズムの詰め合わせです。

数が大きい場合には Pollard's Rho の使用を推奨します。

#### 使い方

- `prime::isPrime(N)`: $N$ が素数かどうかを判定します。
- `prime::factrize(N)`: $N$ について素因数分解をします。
- `prime::divisor(N)`: $N$ の約数を昇順に列挙します。
- `prime::sieve(N)`: $2$ から $N$ までの素因数の個数を返します。(エラトステネスのふるい)

#### 計算量

- `prime::isPrime(N)`: $\mathrm{O}(\sqrt N)$
- `prime::factrize(N)`: $\mathrm{O}(\sqrt N)$
- `prime::divisor(N)`: $\mathrm{O}(\sqrt N)$
- `prime::sieve(N)`: $\mathrm{O}(N \log \log N)$