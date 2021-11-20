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
  bundledCode: "#line 1 \"graph/diameter.hpp\"\ntemplate <typename T>\npair<T,int>\
    \ dfs(const vector<vector<pair<int,T>>> &G,int idx,int par){\n    pair<T,int>\
    \ res(0,idx);\n    for(const auto &e:G[idx]){\n        if(e.first==par) continue;\n\
    \        auto p=dfs(G,e.first,idx);\n        p.first+=e.second;\n        res=max(res,p);\n\
    \    }\n    return res;\n}\n\ntemplate <typename T>\nT diameter(const vector<vector<pair<int,T>>>\
    \ &G){\n    auto p=dfs(G,0,-1);\n    auto q=dfs(G,p.second,-1);\n    return q.first;\n\
    }\n\nint diameter(const vector<vector<int>> &G){\n    vector<vector<pair<int,int>>>\
    \ H(G.size());\n    for(int i=0;i<G.size();++i) for(const auto &e:G[i]) H[i].emplace_back(make_pair(e,1));\n\
    \    return diameter(H);\n}\n"
  code: "template <typename T>\npair<T,int> dfs(const vector<vector<pair<int,T>>>\
    \ &G,int idx,int par){\n    pair<T,int> res(0,idx);\n    for(const auto &e:G[idx]){\n\
    \        if(e.first==par) continue;\n        auto p=dfs(G,e.first,idx);\n    \
    \    p.first+=e.second;\n        res=max(res,p);\n    }\n    return res;\n}\n\n\
    template <typename T>\nT diameter(const vector<vector<pair<int,T>>> &G){\n   \
    \ auto p=dfs(G,0,-1);\n    auto q=dfs(G,p.second,-1);\n    return q.first;\n}\n\
    \nint diameter(const vector<vector<int>> &G){\n    vector<vector<pair<int,int>>>\
    \ H(G.size());\n    for(int i=0;i<G.size();++i) for(const auto &e:G[i]) H[i].emplace_back(make_pair(e,1));\n\
    \    return diameter(H);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/diameter.hpp
  requiredBy: []
  timestamp: '2021-10-21 00:56:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/diameter.hpp
layout: document
title: "Diameter(\u6728\u306E\u76F4\u5F84)"
---

## 概要
木の直径を求める。
まずある頂点から最も遠い頂点をdfsで求める。次にその頂点から最も遠い頂点をdfsで求めると、その頂点との距離が木の直径である。計算量は頂点数を$V$として$O(V)$。

## 使い方
* `diameter(G)`: `G`は木。重み付きでも重みなしでも良い。
