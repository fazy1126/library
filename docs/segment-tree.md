---
title: Segment Tree
documentation_of: //structure/segment-tree.hpp
---

## 概要
セグ木。

## 使い方
* `SegmentTree(n,f,e)`: サイズ`n`で初期化する。`f`は要素同士をマージする演算。`e`はモノイドの単位元。$O(n)$
* `set(k,x)`: `k`番目の要素を`x`にする(更新はされない)。$O(1)$
* `build()`: 木を構築する。初期化が終わったら呼ぶ必要がある。$O(n)$
* `update(k,x)`: `k`番目の要素を`x`にする(一点更新)。$O(\log n)$
* `query(a,b)`: 半開区間$[a,b)$に演算`f`を適用した結果を返す。$O(\log n)$
* `find_first(l,check)`: `check`はbool値を返す関数。$[l,x)$に`f`を適用した結果が`check`を満たす最小のxを返す。存在しないときは$n$を返す。
