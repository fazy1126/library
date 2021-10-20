---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-a.test.cpp
    title: test/aoj-grl-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\ntemplate<typename T>\nvector<T> dijkstra(const\
    \ vector<vector<pair<int,T>>>& g,int s){\n    using P=pair<T,int>;\n    const\
    \ auto inf=numeric_limits<T>::max();\n    vector<T> d(g.size(),inf);\n    d[s]=0;\n\
    \    priority_queue<P,vector<P>,greater<P>> que;\n    que.emplace(P(0,s));\n \
    \   while(!que.empty()){\n        int idx;\n        T cost;\n        tie(cost,idx)=que.top();\
    \ que.pop();\n        if(d[idx]<cost) continue;\n        for(const auto& e:g[idx]){\n\
    \            T ncost=cost+e.second;\n            if(d[e.first]<=ncost) continue;\n\
    \            d[e.first]=ncost;\n            que.emplace(ncost,e.first);\n    \
    \    }\n    }\n    return d;\n}\n\n"
  code: "template<typename T>\nvector<T> dijkstra(const vector<vector<pair<int,T>>>&\
    \ g,int s){\n    using P=pair<T,int>;\n    const auto inf=numeric_limits<T>::max();\n\
    \    vector<T> d(g.size(),inf);\n    d[s]=0;\n    priority_queue<P,vector<P>,greater<P>>\
    \ que;\n    que.emplace(P(0,s));\n    while(!que.empty()){\n        int idx;\n\
    \        T cost;\n        tie(cost,idx)=que.top(); que.pop();\n        if(d[idx]<cost)\
    \ continue;\n        for(const auto& e:g[idx]){\n            T ncost=cost+e.second;\n\
    \            if(d[e.first]<=ncost) continue;\n            d[e.first]=ncost;\n\
    \            que.emplace(ncost,e.first);\n        }\n    }\n    return d;\n}\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-10-21 00:56:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-grl-1-a.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
