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
  bundledCode: "#line 1 \"structure/lazy-segment-tree.hpp\"\ntemplate <typename T,typename\
    \ U=T>\nstruct LazySegmentTree{\n    using F=function<T(T,T)>;\n    using G=function<T(T,U)>;\n\
    \    using H=function<U(U,U)>;\n\n    int sz,height;\n    vector<T> data;\n  \
    \  vector<U> lazy;\n\n    const F f;\n    const G g;\n    const H h;\n    const\
    \ T et;\n    const U eu;\n\n    LazySegmentTree(int n,const F f,const G g,const\
    \ H h,const T& et,const U& eu)\n        :f(f),g(g),h(h),et(et),eu(eu){\n     \
    \   sz=1;\n        height=0;\n        while(sz<n) sz<<=1,height++;\n        data.assign(2*sz,et);\n\
    \        lazy.assign(2*sz,eu);\n    }\n\n    void set(int k,const T& x){\n   \
    \     data[k+sz]=x;\n    }\n\n    void build(){\n        for(int k=sz-1;k>0;--k)\
    \ data[k]=f(data[2*k],data[2*k+1]);\n    }\n\n    inline void propagate(int k){\n\
    \        if(lazy[k]!=eu){\n            lazy[2*k]=h(lazy[2*k],lazy[k]);\n     \
    \       lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);\n            data[k]=apply(k);\n \
    \           lazy[k]=eu;\n        }\n    }\n\n    inline T apply(int k){\n    \
    \    return lazy[k]==eu?data[k]:g(data[k],lazy[k]);\n    }\n\n    inline void\
    \ recalc(int k){\n        while(k>>=1) data[k]=f(apply(2*k),apply(2*k+1));\n \
    \   }\n\n    inline void thrust(int k){\n        for(int i=height-1;i>0;--i) propagate(k>>i);\n\
    \    }\n\n    void update(int a,int b,const U& x){\n        if(a>=b) return;\n\
    \        thrust(a+=sz);\n        thrust(b+=(sz-1));\n        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\n\
    \            if(l&1) lazy[l]=h(lazy[l],x),++l;\n            if(r&1) --r,lazy[r]=h(lazy[r],x);\n\
    \        }\n        recalc(a);\n        recalc(b);\n    }\n\n    T query(int a,int\
    \ b){\n        if(a>=b) return et;\n        thrust(a+=sz);\n        thrust(b+=(sz-1));\n\
    \        T L=et,R=et;\n        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\n         \
    \   if(l&1) L=f(L,apply(l++));\n            if(r&1) R=f(R,apply(--r));\n     \
    \   }\n        return f(L,R);\n    }\n};\n\n"
  code: "template <typename T,typename U=T>\nstruct LazySegmentTree{\n    using F=function<T(T,T)>;\n\
    \    using G=function<T(T,U)>;\n    using H=function<U(U,U)>;\n\n    int sz,height;\n\
    \    vector<T> data;\n    vector<U> lazy;\n\n    const F f;\n    const G g;\n\
    \    const H h;\n    const T et;\n    const U eu;\n\n    LazySegmentTree(int n,const\
    \ F f,const G g,const H h,const T& et,const U& eu)\n        :f(f),g(g),h(h),et(et),eu(eu){\n\
    \        sz=1;\n        height=0;\n        while(sz<n) sz<<=1,height++;\n    \
    \    data.assign(2*sz,et);\n        lazy.assign(2*sz,eu);\n    }\n\n    void set(int\
    \ k,const T& x){\n        data[k+sz]=x;\n    }\n\n    void build(){\n        for(int\
    \ k=sz-1;k>0;--k) data[k]=f(data[2*k],data[2*k+1]);\n    }\n\n    inline void\
    \ propagate(int k){\n        if(lazy[k]!=eu){\n            lazy[2*k]=h(lazy[2*k],lazy[k]);\n\
    \            lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);\n            data[k]=apply(k);\n\
    \            lazy[k]=eu;\n        }\n    }\n\n    inline T apply(int k){\n   \
    \     return lazy[k]==eu?data[k]:g(data[k],lazy[k]);\n    }\n\n    inline void\
    \ recalc(int k){\n        while(k>>=1) data[k]=f(apply(2*k),apply(2*k+1));\n \
    \   }\n\n    inline void thrust(int k){\n        for(int i=height-1;i>0;--i) propagate(k>>i);\n\
    \    }\n\n    void update(int a,int b,const U& x){\n        if(a>=b) return;\n\
    \        thrust(a+=sz);\n        thrust(b+=(sz-1));\n        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\n\
    \            if(l&1) lazy[l]=h(lazy[l],x),++l;\n            if(r&1) --r,lazy[r]=h(lazy[r],x);\n\
    \        }\n        recalc(a);\n        recalc(b);\n    }\n\n    T query(int a,int\
    \ b){\n        if(a>=b) return et;\n        thrust(a+=sz);\n        thrust(b+=(sz-1));\n\
    \        T L=et,R=et;\n        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){\n         \
    \   if(l&1) L=f(L,apply(l++));\n            if(r&1) R=f(R,apply(--r));\n     \
    \   }\n        return f(L,R);\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2021-10-26 21:10:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/lazy-segment-tree.hpp
layout: document
title: Lazy Segment Tree
---

## 概要
遅延セグ木。

## 使い方
* `LazySegmentTree(n,f,g,h,et,eu)`: サイズ`n`で初期化する。`f`は要素同士をマージする演算、`g`は要素と作用素をマージする演算、`h`は作用素同士をマージする演算。`et`はモノイドの単位元。`eu`は作用素の単位元。$O(n)$
* `set(k,x)`: `k`番目の要素を`x`にする(更新はされない)。$O(1)$
* `build()`: 木を構築する。初期化が終わったら呼ぶ必要がある。$O(n)$
* `update(a,b,x)`: 半開区間$[a,b)$の要素に作用素`x`を適用する。$O(\log n)$
* `query(a,b)`: 半開区間$[a,b)$に演算`f`を適用した結果を返す。$O(\log n)$