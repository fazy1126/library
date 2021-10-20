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
redirect_from:
- /library/structure/dsu.hpp
- /library/structure/dsu.hpp.html
title: structure/dsu.hpp
---
