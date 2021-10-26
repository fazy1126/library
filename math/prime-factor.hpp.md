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
  bundledCode: "#line 1 \"math/prime-factor.hpp\"\ntemplate <typename T>\nmap<T, int>\
    \ prime_factor(T n){\n    map<T, int> res;\n    for(T i = 2; i * i <= n; ++i){\n\
    \        while(n % i == 0){\n            res[i]++;\n            n /= i;\n    \
    \    }\n    }\n    if(n != 1) res[n] = 1;\n    return res;\n}\n"
  code: "template <typename T>\nmap<T, int> prime_factor(T n){\n    map<T, int> res;\n\
    \    for(T i = 2; i * i <= n; ++i){\n        while(n % i == 0){\n            res[i]++;\n\
    \            n /= i;\n        }\n    }\n    if(n != 1) res[n] = 1;\n    return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime-factor.hpp
  requiredBy: []
  timestamp: '2021-10-22 22:21:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime-factor.hpp
layout: document
redirect_from:
- /library/math/prime-factor.hpp
- /library/math/prime-factor.hpp.html
title: math/prime-factor.hpp
---