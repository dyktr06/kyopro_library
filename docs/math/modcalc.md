## Mod Calculation

### 概要

Mod に関する計算のアルゴリズムの詰め合わせです。

#### 使い方

- `modcalc::modpow(x, n, m)`: $x^n$ (mod. m) を計算します。
- `modcalc::modinv(a, m)`: $a$ の逆元 (mod. m) を計算します。
- `modcalc::modarithmeticsum(a, d, n, m)`: 初項 $a$, 公差 $d$, 項数 $n$ の等差数列の和 (mod. m) を計算します。（任意 mod で計算できます）
- `modcalc::modgeometricsum(a, r, n, m)`: 初項 $a$, 公比 $r$, 項数 $n$ の等比数列の和 (mod. m) を計算します。（素数 mod のみで計算できます）
- `modcalc::modgeometricsum2(a, r, n, m)`: 初項 $a$, 公比 $r$, 項数 $n$ の等比数列の和 (mod. m) を計算します。（任意 mod で計算できます）

#### 計算量

- `modcalc::modpow(x, n, m)`: $\mathrm{O}(\log n)$
- `modcalc::modinv(a, m)`: $\mathrm{O}(\log m)$
- `modcalc::modarithmeticsum(a, d, n, m)`: $\mathrm{O}(1)$
- `modcalc::modgeometricsum(a, r, n, m)`: $\mathrm{O}(\log nm)$
- `modcalc::modgeometricsum2(a, r, n, m)`: $\mathrm{O}(\log n^2)$