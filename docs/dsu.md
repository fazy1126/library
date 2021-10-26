---
title: Disjoint Set Union
documentation_of: //structure/dsu.hpp
---

## 概要
別名Union-Find。素集合データ構造。無向グラフについて、二頂点を連結させる、また連結かどうかの判定を高速で行う。ならし計算量$O(\alpha (n))?(詳しくないです)

## 使い方
* `DSU(n)`: サイズ`n`で初期化する。
* `size(x)`: `x`が属する集合のサイズを返す。$O(1)$
* `merge(x,y)`: `x`と`y`を連結にする。
* `same(x,y)`: `x`と`y`が連結(同じ集合に属する)なら`true`、そうでなければ`false`を返す。
