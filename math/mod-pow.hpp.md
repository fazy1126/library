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
  bundledCode: "#line 1 \"math/mod-pow.hpp\"\n// x^n mod p\ntemplate <typename T>\n\
    T mod_pow(T x, long long n, const T &p){\n    T res = 1;\n    while(n > 0){\n\
    \        if(n & 1) (res *= x) %= p;\n        (x *= x) %= p;\n        n >>= 1;\n\
    \    }\n    return res % p;\n}\n"
  code: "// x^n mod p\ntemplate <typename T>\nT mod_pow(T x, long long n, const T\
    \ &p){\n    T res = 1;\n    while(n > 0){\n        if(n & 1) (res *= x) %= p;\n\
    \        (x *= x) %= p;\n        n >>= 1;\n    }\n    return res % p;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod-pow.hpp
  requiredBy: []
  timestamp: '2021-10-22 22:21:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod-pow.hpp
layout: document
redirect_from:
- /library/math/mod-pow.hpp
- /library/math/mod-pow.hpp.html
title: math/mod-pow.hpp
---
