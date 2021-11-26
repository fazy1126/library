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
  bundledCode: "#line 1 \"tree/lca.hpp\"\nstruct LCA{\n    int LOG;\n    vector<int>\
    \ dep;\n    const vector<vector<int>>& g;\n    vector<vector<int>> table;\n\n\
    \    LCA(const vector<vector<int>>& g):g(g),dep(g.size()){\n        LOG=1;\n \
    \       while((1<<LOG)<g.size()) LOG++;\n        table.assign(LOG,vector<int>(g.size(),-1));\n\
    \    }\n\n    void build(int root=0){\n        dfs(root,-1,0);\n        for(int\
    \ k=0;k+1<LOG;++k){\n            for(int i=0;i<table[k].size();++i){\n       \
    \         if(table[k][i]==-1) table[k+1][i]=-1;\n                else table[k+1][i]=table[k][table[k][i]];\n\
    \            }\n        }\n    }\n\n    int query(int u,int v){\n        if(dep[u]>dep[v])\
    \ swap(u,v);\n        for(int i=LOG-1;i>=0;--i){\n            if((1<<i)&(dep[v]-dep[u]))\
    \ v=table[i][v];\n        }\n        if(u==v) return u;\n        for(int i=LOG-1;i>=0;--i){\n\
    \            if(table[i][u]!=table[i][v]){\n                u=table[i][u];\n \
    \               v=table[i][v];\n            }\n        }\n        return table[0][u];\n\
    \    }\n\n    int dist(int u,int v){\n        return dep[u]+dep[v]-2*dep[query(u,v)];\n\
    \    }\n\n    private:\n    void dfs(int id,int par,int d){\n        table[0][id]=par;\n\
    \        dep[id]=d;\n        for(auto& to:g[id]){\n            if(to!=par) dfs(to,id,d+1);\n\
    \        }\n    }\n};\n\n"
  code: "struct LCA{\n    int LOG;\n    vector<int> dep;\n    const vector<vector<int>>&\
    \ g;\n    vector<vector<int>> table;\n\n    LCA(const vector<vector<int>>& g):g(g),dep(g.size()){\n\
    \        LOG=1;\n        while((1<<LOG)<g.size()) LOG++;\n        table.assign(LOG,vector<int>(g.size(),-1));\n\
    \    }\n\n    void build(int root=0){\n        dfs(root,-1,0);\n        for(int\
    \ k=0;k+1<LOG;++k){\n            for(int i=0;i<table[k].size();++i){\n       \
    \         if(table[k][i]==-1) table[k+1][i]=-1;\n                else table[k+1][i]=table[k][table[k][i]];\n\
    \            }\n        }\n    }\n\n    int query(int u,int v){\n        if(dep[u]>dep[v])\
    \ swap(u,v);\n        for(int i=LOG-1;i>=0;--i){\n            if((1<<i)&(dep[v]-dep[u]))\
    \ v=table[i][v];\n        }\n        if(u==v) return u;\n        for(int i=LOG-1;i>=0;--i){\n\
    \            if(table[i][u]!=table[i][v]){\n                u=table[i][u];\n \
    \               v=table[i][v];\n            }\n        }\n        return table[0][u];\n\
    \    }\n\n    int dist(int u,int v){\n        return dep[u]+dep[v]-2*dep[query(u,v)];\n\
    \    }\n\n    private:\n    void dfs(int id,int par,int d){\n        table[0][id]=par;\n\
    \        dep[id]=d;\n        for(auto& to:g[id]){\n            if(to!=par) dfs(to,id,d+1);\n\
    \        }\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/lca.hpp
  requiredBy: []
  timestamp: '2021-11-26 11:20:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/lca.hpp
layout: document
title: LCA
---

## 概要
最小共通祖先。ダブリングを用いる。

## 使い方

* `LCA(g)`: 無向グラフ(木)`g`で初期化する。
* `build(root=0)`: `root`を根とした木を構築する。頂点数を$N$として、計算量は$O(N \log N)$
* `query(u,v)`: `u`,`v`の最小共通祖先を返す。計算量は$O(\log N)$
* `dist(u,v)`: `u`,`v`の間の距離を返す。計算量は$O(\log N)$
