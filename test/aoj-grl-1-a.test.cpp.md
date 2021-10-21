---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/aoj-grl-1-a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#line 1 \"template/template.cpp\"\n//#pragma GCC optimize(\"O3\")\n//#pragma\
    \ GCC target(\"avx2\")\n//#pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#define REP(i,n) for(int i=0;i<(int)n;++i)\n#define RREP(i,n)\
    \ for(int i=(int)n-1;i>=0;--i)\n#define FOR(i,m,n) for(int i=(int)m;i<(int)n;++i)\n\
    #define RFOR(i,m,n) for(int i=(int)m-1;i>=(int)n;--i)\n#define ALL(x) x.begin(),x.end()\n\
    #define RALL(x) x.rbegin(),x.rend()\n#define SIZE(x) (int)x.size()\n#define UNIQUE(x)\
    \ x.erase(unique(x.begin(),x.end()),x.end());\n#define BIT(x) (1LL<<(x))\n#define\
    \ eb emplace_back\n#define ef emplace_front\n#define fs first\n#define sc second\n\
    \nusing ll=long long;\nusing ld=long double;\nusing ull=unsigned long long;\n\
    using pll=pair<ll,ll>;\nusing pii=pair<int,int>;\ntemplate <typename T> using\
    \ pque=priority_queue<T>;\ntemplate <typename T> using rpque=priority_queue<T,vector<T>,greater<T>>;\n\
    template <typename T> using graph=vector<vector<pair<int,T>>>;\ntemplate <typename\
    \ T,typename U> void chmax(T&x,U y){if(x<y) x=y;}\ntemplate <typename T,typename\
    \ U> void chmin(T&x,U y){if(x>y) x=y;}\n\nstruct IOSetup{\n    IOSetup(){\n  \
    \      cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout<<fixed<<setprecision(10);\n\
    \        cerr<<fixed<<setprecision(10);\n    }\n} iosetup;\n\n// make_v<T>(size,\
    \ size, ... , size, value)\ntemplate <typename T>\ninline vector<T> make_v(const\
    \ int& a,const T& x){\n    return vector<T>(a,x);\n}\ntemplate <typename T,typename...\
    \ Ts>\ninline auto make_v(const int& a,const Ts&... ts){\n    return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));\n\
    }\n\ntemplate <typename T,typename U>\nostream& operator<<(ostream& os,const pair<T,U>&\
    \ p){\n    os<<p.first<<\" \"<<p.second;\n    return os;\n}\ntemplate <typename\
    \ T,typename U>\nistream& operator>>(istream& is,pair<T,U>& p){\n    is>>p.first>>p.second;\n\
    \    return is;\n}\n\ntemplate <typename T>\nostream& operator<<(ostream& os,const\
    \ vector<T>& v){\n    for(int i=0;i<(int)v.size();++i) os<<(i?\" \":\"\")<<v[i];\n\
    \    return os;\n}\ntemplate <typename T>\nistream& operator>>(istream& is,vector<T>&\
    \ v){\n    for(auto& x:v) is>>x;\n    return is;\n}\n\ntemplate <typename T,typename\
    \ U>\nvoid fill(T& x,const U& y){\n    x=y;\n}\ntemplate <typename T,typename\
    \ U>\nvoid fill(vector<T>& x,const U& y){\n    for(auto& v:x) fill(x,y);\n}\n\n\
    void debug_out(){\n    cout<<\"\\n\";\n}\ntemplate <typename T,typename... Ts>\n\
    void debug_out(T&& a,Ts&&... ts){\n    cout<<a;\n    if(sizeof...(Ts)>0) cout<<\"\
    , \";\n    debug_out(move(ts)...);\n}\n\n#ifdef _DEBUG\n#define debug(...) debug_out(__VA_ARGS__)\n\
    #else \n#define debug(...)\n#endif\n\nconstexpr char newl='\\n';\nconstexpr int\
    \ INF=1<<30;\nconstexpr ll LINF=1LL<<60;\nconstexpr ld pi=3.1415926535897932;\n\
    \n#line 1 \"graph/dijkstra.hpp\"\ntemplate<typename T>\nvector<T> dijkstra(const\
    \ vector<vector<pair<int,T>>>& g,int s){\n    using P=pair<T,int>;\n    const\
    \ auto inf=numeric_limits<T>::max();\n    vector<T> d(g.size(),inf);\n    d[s]=0;\n\
    \    priority_queue<P,vector<P>,greater<P>> que;\n    que.emplace(P(0,s));\n \
    \   while(!que.empty()){\n        int idx;\n        T cost;\n        tie(cost,idx)=que.top();\
    \ que.pop();\n        if(d[idx]<cost) continue;\n        for(const auto& e:g[idx]){\n\
    \            T ncost=cost+e.second;\n            if(d[e.first]<=ncost) continue;\n\
    \            d[e.first]=ncost;\n            que.emplace(ncost,e.first);\n    \
    \    }\n    }\n    return d;\n}\n\n#line 5 \"test/aoj-grl-1-a.test.cpp\"\n\nint\
    \ main(){\n    int V,E,r;\n    cin>>V>>E>>r;\n    graph<ll> g(V);\n    REP(i,E){\n\
    \        int s,t,d;\n        cin>>s>>t>>d;\n        g[s].eb(t,d);\n    }\n   \
    \ auto d=dijkstra(g,r);\n    REP(i,V){\n        if(d[i]>=LINF) cout<<\"INF\"<<newl;\n\
    \        else cout<<d[i]<<newl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include \"../template/template.cpp\"\n#include \"../graph/dijkstra.hpp\"\n\
    \nint main(){\n    int V,E,r;\n    cin>>V>>E>>r;\n    graph<ll> g(V);\n    REP(i,E){\n\
    \        int s,t,d;\n        cin>>s>>t>>d;\n        g[s].eb(t,d);\n    }\n   \
    \ auto d=dijkstra(g,r);\n    REP(i,V){\n        if(d[i]>=LINF) cout<<\"INF\"<<newl;\n\
    \        else cout<<d[i]<<newl;\n    }\n}\n"
  dependsOn:
  - template/template.cpp
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: test/aoj-grl-1-a.test.cpp
  requiredBy: []
  timestamp: '2021-10-21 11:00:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-grl-1-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-grl-1-a.test.cpp
- /verify/test/aoj-grl-1-a.test.cpp.html
title: test/aoj-grl-1-a.test.cpp
---
