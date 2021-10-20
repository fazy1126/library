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
  bundledCode: "#line 1 \"math/prime_table.hpp\"\nvector<bool> prime_table(int n){\n\
    \    vector<bool> res(n+1,true);\n    if(n>=0) res[0]=false;\n    if(n>=1) res[1]=false;\n\
    \    for(int i=2;i*i<=n;++i){\n        if(!res[i]) continue;\n        for(int\
    \ j=i*i;j<=n;j+=i) res[j]=false;\n    }\n    return res;\n}\n\n"
  code: "vector<bool> prime_table(int n){\n    vector<bool> res(n+1,true);\n    if(n>=0)\
    \ res[0]=false;\n    if(n>=1) res[1]=false;\n    for(int i=2;i*i<=n;++i){\n  \
    \      if(!res[i]) continue;\n        for(int j=i*i;j<=n;j+=i) res[j]=false;\n\
    \    }\n    return res;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_table.hpp
  requiredBy: []
  timestamp: '2021-10-21 00:56:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_table.hpp
layout: document
redirect_from:
- /library/math/prime_table.hpp
- /library/math/prime_table.hpp.html
title: math/prime_table.hpp
---
