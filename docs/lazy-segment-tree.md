---
title: Lazy Segment Tree
documentation_of: //structure/lazy-segment-tree.hpp
---

## 概要
遅延セグ木。

## 使い方
* `LazySegmentTree(n,f,g,h,et,eu)`: サイズ`n`で初期化する。`f`は要素同士をマージする演算、`g`は要素と作用素をマージする演算、`h`は作用素同士をマージする演算。`et`はモノイドの単位元。`eu`は作用素の単位元。$O(n)$
* `set(k,x)`: `k`番目の要素を`x`にする(更新はされない)。$O(1)$
* `build()`: 木を構築する。初期化が終わったら呼ぶ必要がある。$O(n)$
* `update(a,b,x)`: 半開区間$[a,b)$の要素に作用素`x`を適用する。$O(\log n)$
* `query(a,b)`: 半開区間$[a,b)$に演算`f`を適用した結果を返す。$O(\log n)$
