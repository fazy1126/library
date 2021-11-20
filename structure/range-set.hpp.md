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
  bundledCode: "#line 1 \"structure/range-set.hpp\"\ntemplate <typename T>\nstruct\
    \ RangeSet{\n    set<pair<T,T>> data;\n    T inf;\n\n    RangeSet(){\n       \
    \ inf=numeric_limits<T>::max();\n        data.emplace(-inf,-inf);\n        data.emplace(inf,inf);\n\
    \    }\n    \n    bool covered(T l,T r){\n        auto itr=prev(data.lower_bound({l+1,l+1}));\n\
    \        return r<=itr->second;\n    }\n    bool covered(T x){\n        return\
    \ covered(x,x);\n    }\n    \n    // insert [l,r]\n    T insert(T l,T r){\n  \
    \      auto itr=prev(data.lower_bound({l+1,l+1}));\n        if(r<=itr->second)\
    \ return T(0);\n        T erased=0;\n        if(l-1<=itr->second){\n         \
    \   l=itr->first;\n            erased+=itr->second-itr->first+1;\n           \
    \ itr=data.erase(itr);\n        }\n        else itr=next(itr);\n        while(r>itr->second){\n\
    \            erased+=itr->second-itr->first+1;\n            itr=data.erase(itr);\n\
    \        }\n        if(itr->first<=r+1){\n            r=itr->second;\n       \
    \     erased+=itr->second-itr->first+1;\n            data.erase(itr);\n      \
    \  }\n        data.emplace(l,r);\n        return r-l+1-erased;\n    }\n    T insert(T\
    \ x){\n        return insert(x,x);\n    }\n    \n    // erase [l,r]\n    T erase(T\
    \ l,T r){\n        auto itr=prev(data.lower_bound({l+1,l+1}));\n        if(r<=itr->second){\n\
    \            if(itr->first<l) data.emplace(itr->first,l-1);\n            if(r<itr->second)\
    \ data.emplace(r+1,itr->second);\n            data.erase(itr);\n            return\
    \ r-l+1;\n        }\n        T erased=0;\n        if(l<=itr->second){\n      \
    \      erased+=itr->second-l+1;\n            if(itr->first<l) data.emplace(itr->first,l-1);\n\
    \            itr=erase(itr);\n        }\n        else itr=next(itr);\n       \
    \ while(itr->second<=r){\n            erased+=itr->second-itr->first+1;\n    \
    \        itr=data.erase(itr);\n        }\n        if(itr->first<=r){\n       \
    \     erased+=r-itr->first+1;\n            if(r<itr->second) data.emplace(r+1,itr->second);\n\
    \            data.erase(itr);\n        }\n        return erased;\n    }\n    T\
    \ erase(T x){\n        return erase(x,x);\n    }\n\n    size_t size(){\n     \
    \   return data.size()-2;\n    }\n    \n    // mex [x,inf)\n    T mex(T x){\n\
    \        auto itr=prev(data.lower_bound({x+1,x+1}));\n        if(x<=itr->second)\
    \ return itr->second+1;\n        else return x;\n    }\n};\n\n"
  code: "template <typename T>\nstruct RangeSet{\n    set<pair<T,T>> data;\n    T\
    \ inf;\n\n    RangeSet(){\n        inf=numeric_limits<T>::max();\n        data.emplace(-inf,-inf);\n\
    \        data.emplace(inf,inf);\n    }\n    \n    bool covered(T l,T r){\n   \
    \     auto itr=prev(data.lower_bound({l+1,l+1}));\n        return r<=itr->second;\n\
    \    }\n    bool covered(T x){\n        return covered(x,x);\n    }\n    \n  \
    \  // insert [l,r]\n    T insert(T l,T r){\n        auto itr=prev(data.lower_bound({l+1,l+1}));\n\
    \        if(r<=itr->second) return T(0);\n        T erased=0;\n        if(l-1<=itr->second){\n\
    \            l=itr->first;\n            erased+=itr->second-itr->first+1;\n  \
    \          itr=data.erase(itr);\n        }\n        else itr=next(itr);\n    \
    \    while(r>itr->second){\n            erased+=itr->second-itr->first+1;\n  \
    \          itr=data.erase(itr);\n        }\n        if(itr->first<=r+1){\n   \
    \         r=itr->second;\n            erased+=itr->second-itr->first+1;\n    \
    \        data.erase(itr);\n        }\n        data.emplace(l,r);\n        return\
    \ r-l+1-erased;\n    }\n    T insert(T x){\n        return insert(x,x);\n    }\n\
    \    \n    // erase [l,r]\n    T erase(T l,T r){\n        auto itr=prev(data.lower_bound({l+1,l+1}));\n\
    \        if(r<=itr->second){\n            if(itr->first<l) data.emplace(itr->first,l-1);\n\
    \            if(r<itr->second) data.emplace(r+1,itr->second);\n            data.erase(itr);\n\
    \            return r-l+1;\n        }\n        T erased=0;\n        if(l<=itr->second){\n\
    \            erased+=itr->second-l+1;\n            if(itr->first<l) data.emplace(itr->first,l-1);\n\
    \            itr=erase(itr);\n        }\n        else itr=next(itr);\n       \
    \ while(itr->second<=r){\n            erased+=itr->second-itr->first+1;\n    \
    \        itr=data.erase(itr);\n        }\n        if(itr->first<=r){\n       \
    \     erased+=r-itr->first+1;\n            if(r<itr->second) data.emplace(r+1,itr->second);\n\
    \            data.erase(itr);\n        }\n        return erased;\n    }\n    T\
    \ erase(T x){\n        return erase(x,x);\n    }\n\n    size_t size(){\n     \
    \   return data.size()-2;\n    }\n    \n    // mex [x,inf)\n    T mex(T x){\n\
    \        auto itr=prev(data.lower_bound({x+1,x+1}));\n        if(x<=itr->second)\
    \ return itr->second+1;\n        else return x;\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/range-set.hpp
  requiredBy: []
  timestamp: '2021-11-16 19:17:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/range-set.hpp
layout: document
title: Range Set
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
