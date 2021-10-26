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
  bundledCode: "#line 1 \"math/combination.hpp\"\n// Use ModInt\ntemplate <typename\
    \ T>\nstruct Combination{\n    vector<T> fact,finv,inv;\n\n    Combination(size_t\
    \ sz):fact(sz+1),finv(sz+1),inv(sz+1){\n        fact[0]=finv[sz]=inv[0]=1;\n \
    \       for(int i=1;i<=sz;++i) fact[i]=fact[i-1]*i;\n        finv[sz]/=fact[sz];\n\
    \        for(int i=sz-1;i>=0;--i) finv[i]=finv[i+1]*(i+1);\n    }\n\n    T P(int\
    \ n,int r) const{\n        if(r<0||n<r) return 0;\n        return fact[n]*finv[n-r];\n\
    \    }\n\n    T C(int n,int r) const{\n        if(r<0||n<r) return 0;\n      \
    \  return fact[n]*finv[n-r]*finv[r];\n    }\n    \n    T H(int n,int r) const{\n\
    \        if(n<0||r<0) return 0;\n        return C(n+r-1,r);\n    }\n};\n"
  code: "// Use ModInt\ntemplate <typename T>\nstruct Combination{\n    vector<T>\
    \ fact,finv,inv;\n\n    Combination(size_t sz):fact(sz+1),finv(sz+1),inv(sz+1){\n\
    \        fact[0]=finv[sz]=inv[0]=1;\n        for(int i=1;i<=sz;++i) fact[i]=fact[i-1]*i;\n\
    \        finv[sz]/=fact[sz];\n        for(int i=sz-1;i>=0;--i) finv[i]=finv[i+1]*(i+1);\n\
    \    }\n\n    T P(int n,int r) const{\n        if(r<0||n<r) return 0;\n      \
    \  return fact[n]*finv[n-r];\n    }\n\n    T C(int n,int r) const{\n        if(r<0||n<r)\
    \ return 0;\n        return fact[n]*finv[n-r]*finv[r];\n    }\n    \n    T H(int\
    \ n,int r) const{\n        if(n<0||r<0) return 0;\n        return C(n+r-1,r);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/combination.hpp
  requiredBy: []
  timestamp: '2021-10-26 14:43:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.hpp
layout: document
redirect_from:
- /library/math/combination.hpp
- /library/math/combination.hpp.html
title: math/combination.hpp
---
