---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/gauss-jordan.hpp
    title: "Gauss-Jordan\u306E\u6383\u304D\u51FA\u3057\u6CD5(mod p)"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix.hpp\"\ntemplate <class T>\nstruct Matrix{\n\
    \    vector<vector<T>> A;\n\n    Matrix(size_t n,size_t m,T x=0):A(n,vector<T>(m,x)){}\n\
    \n    size_t size() const{\n        if(A.empty()) return 0;\n        assert(A.size()==A[0].size());\n\
    \        return A.size();\n    }\n\n    size_t height() const{\n        return\
    \ A.size();\n    }\n\n    size_t width() const{\n        return A[0].size();\n\
    \    }\n    \n    inline const vector<T> &operator[](int k) const{\n        return\
    \ A[k];\n    }\n\n    inline vector<T> &operator[](int k){\n        return A[k];\n\
    \    }\n\n    static Matrix E(size_t n){\n        Matrix mat(n,n);\n        for(int\
    \ i=0;i<n;++i) mat[i][i]=1;\n        return mat;\n    }\n\n    Matrix &operator+=(const\
    \ Matrix& B){\n        size_t h=height(),w=width();\n        assert(h==B.height()&&w==B.width());\n\
    \        for(int i=0;i<h;++i) for(int j=0;j<w;++j) (*this)[i][j]+=B[i][j];\n \
    \       return *this;\n    }\n\n    Matrix &operator-=(const Matrix& B){\n   \
    \     size_t h=height(),w=width();\n        assert(h==B.height()&&w==B.width());\n\
    \        for(int i=0;i<h;++i) for(int j=0;j<w;++j) (*this)[i][j]-=B[i][j];\n \
    \       return *this;\n    }\n\n    Matrix &operator*=(const Matrix& B){\n   \
    \     size_t h=height(),w=B.width(),p=width();\n        assert(p==B.height());\n\
    \        vector<vector<T>> C(h,vector<T>(w,0));\n        for(int i=0;i<h;++i)\
    \ for(int j=0;j<w;++j) for(int k=0;k<p;++k)\n            C[i][j]+=(*this)[i][k]*B[k][j];\n\
    \        A.swap(C);\n        return *this;\n    }\n    \n    Matrix operator+(const\
    \ Matrix& B) const{return Matrix(*this)+=B;}\n    Matrix operator-(const Matrix&\
    \ B) const{return Matrix(*this)-=B;}\n    Matrix operator*(const Matrix& B) const{return\
    \ Matrix(*this)*=B;}\n\n    //ToDo \u3079\u304D\u4E57\u306A\u3069\u3092\u66F8\u304F\
    \n};\n"
  code: "template <class T>\nstruct Matrix{\n    vector<vector<T>> A;\n\n    Matrix(size_t\
    \ n,size_t m,T x=0):A(n,vector<T>(m,x)){}\n\n    size_t size() const{\n      \
    \  if(A.empty()) return 0;\n        assert(A.size()==A[0].size());\n        return\
    \ A.size();\n    }\n\n    size_t height() const{\n        return A.size();\n \
    \   }\n\n    size_t width() const{\n        return A[0].size();\n    }\n    \n\
    \    inline const vector<T> &operator[](int k) const{\n        return A[k];\n\
    \    }\n\n    inline vector<T> &operator[](int k){\n        return A[k];\n   \
    \ }\n\n    static Matrix E(size_t n){\n        Matrix mat(n,n);\n        for(int\
    \ i=0;i<n;++i) mat[i][i]=1;\n        return mat;\n    }\n\n    Matrix &operator+=(const\
    \ Matrix& B){\n        size_t h=height(),w=width();\n        assert(h==B.height()&&w==B.width());\n\
    \        for(int i=0;i<h;++i) for(int j=0;j<w;++j) (*this)[i][j]+=B[i][j];\n \
    \       return *this;\n    }\n\n    Matrix &operator-=(const Matrix& B){\n   \
    \     size_t h=height(),w=width();\n        assert(h==B.height()&&w==B.width());\n\
    \        for(int i=0;i<h;++i) for(int j=0;j<w;++j) (*this)[i][j]-=B[i][j];\n \
    \       return *this;\n    }\n\n    Matrix &operator*=(const Matrix& B){\n   \
    \     size_t h=height(),w=B.width(),p=width();\n        assert(p==B.height());\n\
    \        vector<vector<T>> C(h,vector<T>(w,0));\n        for(int i=0;i<h;++i)\
    \ for(int j=0;j<w;++j) for(int k=0;k<p;++k)\n            C[i][j]+=(*this)[i][k]*B[k][j];\n\
    \        A.swap(C);\n        return *this;\n    }\n    \n    Matrix operator+(const\
    \ Matrix& B) const{return Matrix(*this)+=B;}\n    Matrix operator-(const Matrix&\
    \ B) const{return Matrix(*this)-=B;}\n    Matrix operator*(const Matrix& B) const{return\
    \ Matrix(*this)*=B;}\n\n    //ToDo \u3079\u304D\u4E57\u306A\u3069\u3092\u66F8\u304F\
    \n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy:
  - math/gauss-jordan.hpp
  timestamp: '2021-11-01 18:09:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.hpp
layout: document
title: Matrix
---

## 概要
行列。
