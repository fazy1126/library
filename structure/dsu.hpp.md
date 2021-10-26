---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/dsu.hpp\"\nstruct DSU{\n    vector<int> data;\n\
    \n    DSU(int n):data(n,-1){}\n\n    int leader(int x){\n        if(data[x]<0)\
    \ return x;\n        else return data[x]=leader(data[x]);\n    }\n\n    int size(int\
    \ x){\n        return -data[leader(x)];\n    }\n\n    void merge(int x,int y){\n\
    \        x=leader(x),y=leader(y);\n        if(x==y) return;\n        if(data[x]>data[y])\
    \ swap(x,y);\n        data[x]+=data[y];\n        data[y]=x;\n    }\n\n    bool\
    \ same(int x,int y){\n        return leader(x)==leader(y);\n    }\n};\n"
  code: "struct DSU{\n    vector<int> data;\n\n    DSU(int n):data(n,-1){}\n\n   \
    \ int leader(int x){\n        if(data[x]<0) return x;\n        else return data[x]=leader(data[x]);\n\
    \    }\n\n    int size(int x){\n        return -data[leader(x)];\n    }\n\n  \
    \  void merge(int x,int y){\n        x=leader(x),y=leader(y);\n        if(x==y)\
    \ return;\n        if(data[x]>data[y]) swap(x,y);\n        data[x]+=data[y];\n\
    \        data[y]=x;\n    }\n\n    bool same(int x,int y){\n        return leader(x)==leader(y);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/dsu.hpp
  requiredBy: []
  timestamp: '2021-10-21 00:56:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/dsu.hpp
layout: document
title: Disjoint Set Union
---

## 概要
別名Union-Find。素集合データ構造。無向グラフについて、二頂点を連結させる、また連結かどうかの判定を高速で行う。ならし計算量$O(\alpha (n))?(詳しくないです)

## 使い方
* `DSU(n)`: サイズ`n`で初期化する。
* `size(x)`: `x`が属する集合のサイズを返す。$O(1)$
* `merge(x,y)`: `x`と`y`を連結にする。
* `same(x,y)`: `x`と`y`が連結(同じ集合に属する)なら`true`、そうでなければ`false`を返す。
