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
  bundledCode: "#line 1 \"graph/scc.hpp\"\nstruct SCC{\n    vector<int> comp,order;\n\
    \    vector<bool> used;\n    vector<vector<int>> G,rG;\n\n    SCC(int n=0):comp(n,-1),used(n,false),G(n),rG(n){}\n\
    \n    void add_edge(int from,int to){\n        G[from].emplace_back(to);\n   \
    \     rG[to].emplace_back(from);\n    }\n\n    //\u5F37\u9023\u7D50\u6210\u5206\
    \u306E\u6570\u3092\u8FD4\u3059\n    int build(){\n        for(int i=0;i<G.size();++i)\
    \ if(!used[i]) dfs(i);\n        int k=0;\n        for(int i=G.size()-1;i>=0;--i)\
    \ if(comp[order[i]]==-1) rdfs(order[i],k++);\n        return k;\n    }\n\n   \
    \ int operator[](int k){\n        return comp[k];\n    }\n\nprivate:\n    void\
    \ dfs(int v){\n        used[v]=true;\n        for(auto to:G[v]){\n           \
    \ if(!used[to]) dfs(to);\n        }\n        order.emplace_back(v);\n    }\n\n\
    \    void rdfs(int v,int k){\n        comp[v]=k;\n        for(auto to:rG[v]){\n\
    \            if(comp[to]==-1) rdfs(to,k);\n        }\n    }\n};\n"
  code: "struct SCC{\n    vector<int> comp,order;\n    vector<bool> used;\n    vector<vector<int>>\
    \ G,rG;\n\n    SCC(int n=0):comp(n,-1),used(n,false),G(n),rG(n){}\n\n    void\
    \ add_edge(int from,int to){\n        G[from].emplace_back(to);\n        rG[to].emplace_back(from);\n\
    \    }\n\n    //\u5F37\u9023\u7D50\u6210\u5206\u306E\u6570\u3092\u8FD4\u3059\n\
    \    int build(){\n        for(int i=0;i<G.size();++i) if(!used[i]) dfs(i);\n\
    \        int k=0;\n        for(int i=G.size()-1;i>=0;--i) if(comp[order[i]]==-1)\
    \ rdfs(order[i],k++);\n        return k;\n    }\n\n    int operator[](int k){\n\
    \        return comp[k];\n    }\n\nprivate:\n    void dfs(int v){\n        used[v]=true;\n\
    \        for(auto to:G[v]){\n            if(!used[to]) dfs(to);\n        }\n \
    \       order.emplace_back(v);\n    }\n\n    void rdfs(int v,int k){\n       \
    \ comp[v]=k;\n        for(auto to:rG[v]){\n            if(comp[to]==-1) rdfs(to,k);\n\
    \        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2021-10-21 00:56:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
