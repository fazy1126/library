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
    \n    const F op;\n    const T e;\n    \n    SegmentTree()=default;\n\n    explicit\
    \ SegmentTree(int n,const F& op,const T& e):op(op),e(e){\n        sz=1;\n    \
    \    while(sz<n) sz<<=1;\n        data.assign(2*sz,e);\n    }\n\n    void set(int\
    \ k,const T& x){\n        data[k+sz]=x;\n    }\n\n    void build(){\n        for(int\
    \ k=sz-1;k>0;--k) data[k]=op(data[2*k],data[2*k+1]);\n    }\n\n    void update(int\
    \ k,const T& x){\n        k+=sz;\n        data[k]=x;\n        while(k>>=1) data[k]=op(data[2*k],data[2*k+1]);\n\
    \    }\n\n    T query(int l,int r){\n        T L=e,R=e;\n        for(l+=sz,r+=sz;l<r;l>>=1,r>>=1){\n\
    \            if(l&1) L=op(L,data[l++]);\n            if(r&1) R=op(R,data[--r]);\n\
    \        }\n        return op(L,R);\n    }\n\n    T operator[](const int& k) const{\n\
    \        return data[k+sz];\n    }\n};\n\n"
  code: "template <typename T>\nstruct SegmentTree{\n    using F=function<T(T,T)>;\n\
    \n    int sz;\n    vector<T> data;\n\n    const F op;\n    const T e;\n    \n\
    \    SegmentTree()=default;\n\n    explicit SegmentTree(int n,const F& op,const\
    \ T& e):op(op),e(e){\n        sz=1;\n        while(sz<n) sz<<=1;\n        data.assign(2*sz,e);\n\
    \    }\n\n    void set(int k,const T& x){\n        data[k+sz]=x;\n    }\n\n  \
    \  void build(){\n        for(int k=sz-1;k>0;--k) data[k]=op(data[2*k],data[2*k+1]);\n\
    \    }\n\n    void update(int k,const T& x){\n        k+=sz;\n        data[k]=x;\n\
    \        while(k>>=1) data[k]=op(data[2*k],data[2*k+1]);\n    }\n\n    T query(int\
    \ l,int r){\n        T L=e,R=e;\n        for(l+=sz,r+=sz;l<r;l>>=1,r>>=1){\n \
    \           if(l&1) L=op(L,data[l++]);\n            if(r&1) R=op(R,data[--r]);\n\
    \        }\n        return op(L,R);\n    }\n\n    T operator[](const int& k) const{\n\
    \        return data[k+sz];\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/segment-tree.hpp
  requiredBy: []
  timestamp: '2021-10-26 21:10:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/segment-tree.hpp
layout: document
redirect_from:
- /library/structure/segment-tree.hpp
- /library/structure/segment-tree.hpp.html
title: structure/segment-tree.hpp
---
