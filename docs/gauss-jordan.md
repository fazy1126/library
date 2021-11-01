---
title: Gauss Jordanの掃き出し法(mod p)
documentation_of: //math/gauss-jordan.hpp
---

## 概要
mod pにおける行列の掃き出し法を行う。

## 使い方
ModIntををテンプレート引数にすることを想定している。  
引数で渡された行列を掃き出し、階数を返す。行数を$R$、列数を$C$とすると、計算量は$O(RC^2)$。
* `is_extended=false`: 拡大係数行列のときは`true`
