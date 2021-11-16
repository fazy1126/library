---
title: Range Set
documentation_of: //structure/range-set.hpp
---

## 概要
区間をsetで管理するやつ。操作を行う区間の数を$n$とすると、区間の挿入、削除、包含判定、mexなどが(ならし計算量で?)$O(\log n)$で処理できる。

## 使い方
* `RangeSet()`: コンストラクタ
* `covered(l,r)`, `covered(x)`: 区間`[l,r]`、あるいは点`x`が、ある区間に含まれているかを返す。
* `insert(l,r)`, `insert(x)`: 区間`[l,r]`、あるいは点`x`を挿入する。区間の増加量を返す。
* `erase(l,r)`, `erase(x)`: 区間`[l,r]`、あるいは点`x`を削除する。区間の減少量を返す。
* `size()`: 区間の数を返す。
* `mex(x)`: 区間`[x,inf)`におけるmexを返す。
