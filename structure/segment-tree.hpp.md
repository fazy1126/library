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
  bundledCode: "#line 1 \"structure/segment-tree.hpp\"\ntemplate <typename T>\nstruct\
    \ SegmentTree{\n    using F=function<T(T,T)>;\n\n    int sz;\n    vector<T> data;\n\
    \n    const F f;\n    const T e;\n    \n    SegmentTree()=default;\n\n    explicit\
    \ SegmentTree(int n,const F& f,const T& e):f(f),e(e){\n        sz=1;\n       \
    \ while(sz<n) sz<<=1;\n        data.assign(2*sz,e);\n    }\n\n    void set(int\
    \ k,const T& x){\n        data[k+sz]=x;\n    }\n\n    void build(){\n        for(int\
    \ k=sz-1;k>0;--k) data[k]=f(data[2*k],data[2*k+1]);\n    }\n\n    void update(int\
    \ k,const T& x){\n        k+=sz;\n        data[k]=x;\n        while(k>>=1) data[k]=f(data[2*k],data[2*k+1]);\n\
    \    }\n\n    T query(int a,int b){\n        T L=e,R=e;\n        for(a+=sz,b+=sz;a<b;a>>=1,b>>=1){\n\
    \            if(a&1) L=f(L,data[a++]);\n            if(b&1) R=f(R,data[--b]);\n\
    \        }\n        return f(L,R);\n    }\n\n    T operator[](const int& k) const{\n\
    \        return data[k+sz];\n    }\n};\n\n"
  code: "template <typename T>\nstruct SegmentTree{\n    using F=function<T(T,T)>;\n\
    \n    int sz;\n    vector<T> data;\n\n    const F f;\n    const T e;\n    \n \
    \   SegmentTree()=default;\n\n    explicit SegmentTree(int n,const F& f,const\
    \ T& e):f(f),e(e){\n        sz=1;\n        while(sz<n) sz<<=1;\n        data.assign(2*sz,e);\n\
    \    }\n\n    void set(int k,const T& x){\n        data[k+sz]=x;\n    }\n\n  \
    \  void build(){\n        for(int k=sz-1;k>0;--k) data[k]=f(data[2*k],data[2*k+1]);\n\
    \    }\n\n    void update(int k,const T& x){\n        k+=sz;\n        data[k]=x;\n\
    \        while(k>>=1) data[k]=f(data[2*k],data[2*k+1]);\n    }\n\n    T query(int\
    \ a,int b){\n        T L=e,R=e;\n        for(a+=sz,b+=sz;a<b;a>>=1,b>>=1){\n \
    \           if(a&1) L=f(L,data[a++]);\n            if(b&1) R=f(R,data[--b]);\n\
    \        }\n        return f(L,R);\n    }\n\n    T operator[](const int& k) const{\n\
    \        return data[k+sz];\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/segment-tree.hpp
  requiredBy: []
  timestamp: '2021-10-26 21:45:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/segment-tree.hpp
layout: document
title: Segment Tree
---

## 概要
セグ木。

## 使い方
* `SegmentTree(n,f,e)`: サイズ`n`で初期化する。`f`は要素同士をマージする演算。`e`はモノイドの単位元。$O(n)$
* `set(k,x)`: `k`番目の要素を`x`にする(更新はされない)。$O(1)$
* `build()`: 木を構築する。初期化が終わったら呼ぶ必要がある。$O(n)$
* `update(k,x)`: `k`番目の要素を`x`にする(一点更新)。$O(\log n)$
* `query(a,b)`: 半開区間$[a,b)$に演算`f`を適用した結果を返す。$O(\log n)$
