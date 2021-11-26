---
title: LCA
documentation_of: //tree/lca.hpp
---

## 概要
最小共通祖先。ダブリングを用いる。

## 使い方

* `LCA(g)`: 無向グラフ(木)`g`で初期化する。
* `build(root=0)`: `root`を根とした木を構築する。頂点数を$N$として、計算量は$O(N \log N)$
* `query(u,v)`: `u`,`v`の最小共通祖先を返す。計算量は$O(\log N)$
* `dist(u,v)`: `u`,`v`の間の距離を返す。計算量は$O(\log N)$
