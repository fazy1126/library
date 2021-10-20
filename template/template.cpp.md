---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-grl-1-a.test.cpp
    title: test/aoj-grl-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "//#pragma GCC optimize(\"O3\")\n//#pragma GCC target(\"avx2\")\n//#pragma\
    \ GCC optimize(\"unroll-loops\")\n#include \"bits/stdc++.h\"\nusing namespace\
    \ std;\n\n#define REP(i,n) for(int i=0;i<(int)n;++i)\n#define RREP(i,n) for(int\
    \ i=(int)n-1;i>=0;--i)\n#define FOR(i,m,n) for(int i=(int)m;i<(int)n;++i)\n#define\
    \ RFOR(i,m,n) for(int i=(int)m-1;i>=(int)n;--i)\n#define ALL(x) x.begin(),x.end()\n\
    #define RALL(x) x.rbegin(),x.rend()\n#define SIZE(x) (int)x.size()\n#define UNIQUE(x)\
    \ x.erase(unique(x.begin(),x.end()),x.end());\n#define BIT(x) (1LL<<(x))\n#define\
    \ eb emplace_back\n#define ef emplace_front\n#define fs first\n#define sc second\n\
    \nusing ll=long long;\nusing ld=long double;\nusing ull=unsigned long long;\n\
    using pll=pair<ll,ll>;\nusing pii=pair<int,int>;\ntemplate <typename T> using\
    \ pque=priority_queue<T>;\ntemplate <typename T> using rpque=priority_queue<T,vector<T>,greater<T>>;\n\
    template <typename T> using VV=vector<vector<T>>;\ntemplate <typename T> using\
    \ graph=vector<vector<pair<int,T>>>;\ntemplate <typename T,typename U> void chmax(T&x,U\
    \ y){if(x<y) x=y;}\ntemplate <typename T,typename U> void chmin(T&x,U y){if(x>y)\
    \ x=y;}\n\n// Vec<T>(size, size, ... , size, value)\ntemplate <typename T>\ninline\
    \ vector<T> Vec(const int& a,const T& x){\n    return vector<T>(a,x);\n}\ntemplate\
    \ <typename T,typename... Ts>\ninline auto Vec(const int& a,const Ts&... ts){\n\
    \    return vector<decltype(Vec<T>(ts...))>(a,Vec<T>(ts...));\n}\n\ntemplate <typename\
    \ T,typename U>\nostream& operator<<(ostream& os,const pair<T,U>& p){\n    os<<p.first<<\"\
    \ \"<<p.second;\n    return os;\n}\ntemplate <typename T,typename U>\nistream&\
    \ operator>>(istream& is,pair<T,U>& p){\n    is>>p.first>>p.second;\n    return\
    \ is;\n}\n\ntemplate <typename T>\nostream& operator<<(ostream& os,const vector<T>&\
    \ v){\n    for(int i=0;i<(int)v.size();++i) os<<(i?\" \":\"\")<<v[i];\n    return\
    \ os;\n}\ntemplate <typename T>\nistream& operator>>(istream& is,vector<T>& v){\n\
    \    for(auto& x:v) is>>x;\n    return is;\n}\n\ntemplate <typename T,typename\
    \ U>\nvoid fill(T& x,const U& y){\n    x=y;\n}\ntemplate <typename T,typename\
    \ U>\nvoid fill(vector<T>& x,const U& y){\n    for(auto& v:x) fill(x,y);\n}\n\n\
    void debug_out(){\n    cout<<\"\\n\";\n}\ntemplate <typename T,typename... Ts>\n\
    void debug_out(T&& a,Ts&&... ts){\n    cout<<a;\n    if(sizeof...(Ts)>0) cout<<\"\
    , \";\n    debug_out(move(ts)...);\n}\n\n#ifdef _DEBUG\n#define debug(...) debug_out(__VA_ARGS__)\n\
    #else \n#define debug(...)\n#endif\n\nconstexpr char newl='\\n';\nconstexpr int\
    \ INF=1<<30;\nconstexpr ll LINF=1LL<<60;\nconstexpr ld pi=3.1415926535897932;\n\
    \nvoid Main();\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    Main();\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.cpp
  requiredBy: []
  timestamp: '2021-10-21 08:09:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-grl-1-a.test.cpp
documentation_of: template/template.cpp
layout: document
redirect_from:
- /library/template/template.cpp
- /library/template/template.cpp.html
title: template/template.cpp
---
