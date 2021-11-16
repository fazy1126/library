---
title: Diameter(木の直径)
documentation_of: //graph/diameter.hpp
---

## 概要
木の直径を求める。
まずある頂点から最も遠い頂点をdfsで求める。次にその頂点から最も遠い頂点をdfsで求めると、その頂点との距離が木の直径である。計算量は頂点数を$V$として$O(V)$。

## 使い方
* `diameter(G)`: `G`は木。重み付きでも重みなしでも良い。
