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
  bundledCode: "#line 1 \"math/mod-int.hpp\"\ntemplate <int mod>\nstruct ModInt{\n\
    \    int x;\n\n    ModInt():x(0){}\n\n    ModInt(int64_t y):x(y>=0?y%mod:(mod-(-y)%mod)%mod){}\n\
    \n    ModInt &operator+=(const ModInt& p){\n        if((x+=p.x)>=mod) x-=mod;\n\
    \        return *this;\n    }\n\n    ModInt &operator-=(const ModInt& p){\n  \
    \      if((x+=mod-p.x)>=mod) x-=mod;\n        return *this;\n    }\n\n    ModInt\
    \ &operator*=(const ModInt& p){\n        x=(int)(1LL*x*p.x%mod);\n        return\
    \ *this;\n    }\n\n    ModInt &operator/=(const ModInt& p){\n        *this*=p.inverse();\n\
    \        return *this;\n    }\n\n    ModInt operator-() const{return ModInt(-x);}\n\
    \    ModInt operator+(const ModInt& p) const {return ModInt(*this)+=p;}\n    ModInt\
    \ operator-(const ModInt& p) const {return ModInt(*this)-=p;}\n    ModInt operator*(const\
    \ ModInt& p) const {return ModInt(*this)*=p;}\n    ModInt operator/(const ModInt&\
    \ p) const {return ModInt(*this)/=p;}\n\n    bool operator==(const ModInt& p)\
    \ const {return x==p.x;}\n    bool operator!=(const ModInt& p) const {return x!=p.x;}\n\
    \n    ModInt inverse() const{\n        int a=x,b=mod,u=1,v=0,t;\n        while(b>0){\n\
    \            t=a/b;\n            swap(a-=t*b,b);\n            swap(u-=t*v,v);\n\
    \        }\n        return ModInt(u);\n    }\n\n    friend ostream &operator<<(ostream&\
    \ os,const ModInt& p){\n        return os<<p.x;\n    }\n\n    friend istream &operator>>(istream&\
    \ is,ModInt& p){\n        int64_t t;\n        is>>t;\n        p=ModInt<mod>(t);\n\
    \        return (is);\n    }\n};\n\nusing mint=ModInt<MOD>;\n"
  code: "template <int mod>\nstruct ModInt{\n    int x;\n\n    ModInt():x(0){}\n\n\
    \    ModInt(int64_t y):x(y>=0?y%mod:(mod-(-y)%mod)%mod){}\n\n    ModInt &operator+=(const\
    \ ModInt& p){\n        if((x+=p.x)>=mod) x-=mod;\n        return *this;\n    }\n\
    \n    ModInt &operator-=(const ModInt& p){\n        if((x+=mod-p.x)>=mod) x-=mod;\n\
    \        return *this;\n    }\n\n    ModInt &operator*=(const ModInt& p){\n  \
    \      x=(int)(1LL*x*p.x%mod);\n        return *this;\n    }\n\n    ModInt &operator/=(const\
    \ ModInt& p){\n        *this*=p.inverse();\n        return *this;\n    }\n\n \
    \   ModInt operator-() const{return ModInt(-x);}\n    ModInt operator+(const ModInt&\
    \ p) const {return ModInt(*this)+=p;}\n    ModInt operator-(const ModInt& p) const\
    \ {return ModInt(*this)-=p;}\n    ModInt operator*(const ModInt& p) const {return\
    \ ModInt(*this)*=p;}\n    ModInt operator/(const ModInt& p) const {return ModInt(*this)/=p;}\n\
    \n    bool operator==(const ModInt& p) const {return x==p.x;}\n    bool operator!=(const\
    \ ModInt& p) const {return x!=p.x;}\n\n    ModInt inverse() const{\n        int\
    \ a=x,b=mod,u=1,v=0,t;\n        while(b>0){\n            t=a/b;\n            swap(a-=t*b,b);\n\
    \            swap(u-=t*v,v);\n        }\n        return ModInt(u);\n    }\n\n\
    \    friend ostream &operator<<(ostream& os,const ModInt& p){\n        return\
    \ os<<p.x;\n    }\n\n    friend istream &operator>>(istream& is,ModInt& p){\n\
    \        int64_t t;\n        is>>t;\n        p=ModInt<mod>(t);\n        return\
    \ (is);\n    }\n};\n\nusing mint=ModInt<MOD>;\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod-int.hpp
  requiredBy: []
  timestamp: '2021-10-22 22:21:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod-int.hpp
layout: document
redirect_from:
- /library/math/mod-int.hpp
- /library/math/mod-int.hpp.html
title: math/mod-int.hpp
---
