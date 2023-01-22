## Chinese Remainder Theorem (中国剰余定理)

#### 使い方

- `CRT::extGCD(a, b, x, y)`: $ax + by =$ gcd($a, b$) となる $x, y$ を求めます。
- `CRT::ChineseRem(b, m)`: 中国剰余定理の計算を行います。返り値を (r, m) とすると解は x ≡ r (mod. m)、解なしの場合は (0, -1) を返します。

注意: lcmのオーバーフローに注意する。

#### 計算量

- `CRT::extGCD(a, b, x, y)`: $\mathrm{O}(\log a)$
- `CRT::ChineseRem(b, m)`: $\mathrm{O}(N \log \mathrm{lcm}(m))$ (配列の長さを $N$ とする)