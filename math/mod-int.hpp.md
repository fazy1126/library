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
    \    int x;\n\n    constexpr ModInt(int64_t y=0) noexcept:x(y>=0?y%mod:(mod-(-y)%mod)%mod){}\n\
    \n    constexpr ModInt &operator+=(const ModInt& p) noexcept{\n        if((x+=p.x)>=mod)\
    \ x-=mod;\n        return *this;\n    }\n\n    constexpr ModInt &operator-=(const\
    \ ModInt& p) noexcept{\n        if((x+=mod-p.x)>=mod) x-=mod;\n        return\
    \ *this;\n    }\n\n    constexpr ModInt &operator*=(const ModInt& p) noexcept{\n\
    \        x=(int)(1LL*x*p.x%mod);\n        return *this;\n    }\n\n    constexpr\
    \ ModInt &operator/=(const ModInt& p) noexcept{\n        *this*=p.inverse();\n\
    \        return *this;\n    }\n\n    constexpr ModInt operator++() noexcept{\n\
    \        x++;\n        if(x==mod) x=0;\n        return *this;\n    }\n\n    constexpr\
    \ ModInt operator--() noexcept{\n        if(x==0) x=mod;\n        x--;\n     \
    \   return *this;\n    }\n\n    constexpr ModInt operator++(int) noexcept{\n \
    \       ModInt res=*this;\n        ++*this;\n        return res;\n    }\n\n  \
    \  constexpr ModInt operator--(int) noexcept{\n        ModInt res=*this;\n   \
    \     --*this;\n        return res;\n    }\n\n    constexpr ModInt operator-()\
    \ const noexcept {return ModInt(-x);}\n    constexpr ModInt operator+(const ModInt&\
    \ p) const noexcept {return ModInt(*this)+=p;}\n    constexpr ModInt operator-(const\
    \ ModInt& p) const noexcept {return ModInt(*this)-=p;}\n    constexpr ModInt operator*(const\
    \ ModInt& p) const noexcept {return ModInt(*this)*=p;}\n    constexpr ModInt operator/(const\
    \ ModInt& p) const noexcept {return ModInt(*this)/=p;}\n\n    constexpr bool operator==(const\
    \ ModInt& p) const noexcept {return x==p.x;}\n    constexpr bool operator!=(const\
    \ ModInt& p) const noexcept {return x!=p.x;}\n\n    ModInt inverse() const{\n\
    \        int a=x,b=mod,u=1,v=0,t;\n        while(b>0){\n            t=a/b;\n \
    \           swap(a-=t*b,b);\n            swap(u-=t*v,v);\n        }\n        return\
    \ ModInt(u);\n    }\n\n    ModInt pow(int64_t n) const{\n        ModInt res(1),mul(x);\n\
    \        while(n>0){\n            if(n&1) res*=mul;\n            mul*=mul;\n \
    \           n>>=1;\n        }\n        return res;\n    }\n\n    friend ostream\
    \ &operator<<(ostream& os,const ModInt& p){\n        return os<<p.x;\n    }\n\n\
    \    friend istream &operator>>(istream& is,ModInt& p){\n        int64_t t;\n\
    \        is>>t;\n        p=ModInt<mod>(t);\n        return (is);\n    }\n};\n\n\
    using mint=ModInt<MOD>;\n"
  code: "template <int mod>\nstruct ModInt{\n    int x;\n\n    constexpr ModInt(int64_t\
    \ y=0) noexcept:x(y>=0?y%mod:(mod-(-y)%mod)%mod){}\n\n    constexpr ModInt &operator+=(const\
    \ ModInt& p) noexcept{\n        if((x+=p.x)>=mod) x-=mod;\n        return *this;\n\
    \    }\n\n    constexpr ModInt &operator-=(const ModInt& p) noexcept{\n      \
    \  if((x+=mod-p.x)>=mod) x-=mod;\n        return *this;\n    }\n\n    constexpr\
    \ ModInt &operator*=(const ModInt& p) noexcept{\n        x=(int)(1LL*x*p.x%mod);\n\
    \        return *this;\n    }\n\n    constexpr ModInt &operator/=(const ModInt&\
    \ p) noexcept{\n        *this*=p.inverse();\n        return *this;\n    }\n\n\
    \    constexpr ModInt operator++() noexcept{\n        x++;\n        if(x==mod)\
    \ x=0;\n        return *this;\n    }\n\n    constexpr ModInt operator--() noexcept{\n\
    \        if(x==0) x=mod;\n        x--;\n        return *this;\n    }\n\n    constexpr\
    \ ModInt operator++(int) noexcept{\n        ModInt res=*this;\n        ++*this;\n\
    \        return res;\n    }\n\n    constexpr ModInt operator--(int) noexcept{\n\
    \        ModInt res=*this;\n        --*this;\n        return res;\n    }\n\n \
    \   constexpr ModInt operator-() const noexcept {return ModInt(-x);}\n    constexpr\
    \ ModInt operator+(const ModInt& p) const noexcept {return ModInt(*this)+=p;}\n\
    \    constexpr ModInt operator-(const ModInt& p) const noexcept {return ModInt(*this)-=p;}\n\
    \    constexpr ModInt operator*(const ModInt& p) const noexcept {return ModInt(*this)*=p;}\n\
    \    constexpr ModInt operator/(const ModInt& p) const noexcept {return ModInt(*this)/=p;}\n\
    \n    constexpr bool operator==(const ModInt& p) const noexcept {return x==p.x;}\n\
    \    constexpr bool operator!=(const ModInt& p) const noexcept {return x!=p.x;}\n\
    \n    ModInt inverse() const{\n        int a=x,b=mod,u=1,v=0,t;\n        while(b>0){\n\
    \            t=a/b;\n            swap(a-=t*b,b);\n            swap(u-=t*v,v);\n\
    \        }\n        return ModInt(u);\n    }\n\n    ModInt pow(int64_t n) const{\n\
    \        ModInt res(1),mul(x);\n        while(n>0){\n            if(n&1) res*=mul;\n\
    \            mul*=mul;\n            n>>=1;\n        }\n        return res;\n \
    \   }\n\n    friend ostream &operator<<(ostream& os,const ModInt& p){\n      \
    \  return os<<p.x;\n    }\n\n    friend istream &operator>>(istream& is,ModInt&\
    \ p){\n        int64_t t;\n        is>>t;\n        p=ModInt<mod>(t);\n       \
    \ return (is);\n    }\n};\n\nusing mint=ModInt<MOD>;\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod-int.hpp
  requiredBy: []
  timestamp: '2021-10-26 14:43:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod-int.hpp
layout: document
redirect_from:
- /library/math/mod-int.hpp
- /library/math/mod-int.hpp.html
title: math/mod-int.hpp
---
