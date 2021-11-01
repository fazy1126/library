//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define RREP(i,n) for(int i=(int)n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;++i)
#define RFOR(i,m,n) for(int i=(int)m-1;i>=(int)n;--i)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define SIZE(x) (int)x.size()
#define UNIQUE(x) x.erase(unique(x.begin(),x.end()),x.end());
#define BIT(x) (1LL<<(x))
#define eb emplace_back
#define ef emplace_front
#define fs first
#define sc second

using ll=long long;
using ld=long double;
using ull=unsigned long long;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
template <typename T> using pque=priority_queue<T>;
template <typename T> using rpque=priority_queue<T,vector<T>,greater<T>>;
template <typename T> using graph=vector<vector<pair<int,T>>>;
template <typename T,typename U> void chmax(T&x,U y){if(x<y) x=y;}
template <typename T,typename U> void chmin(T&x,U y){if(x>y) x=y;}

struct IOSetup{
    IOSetup(){
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout<<fixed<<setprecision(10);
        cerr<<fixed<<setprecision(10);
    }
} iosetup;

// make_v<T>(size, size, ... , size, value)
template <typename T>
inline vector<T> make_v(const int& a,const T& x){
    return vector<T>(a,x);
}
template <typename T,typename... Ts>
inline auto make_v(const int& a,const Ts&... ts){
    return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template <typename T,typename U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
    os<<p.first<<" "<<p.second;
    return os;
}
template <typename T,typename U>
istream& operator>>(istream& is,pair<T,U>& p){
    is>>p.first>>p.second;
    return is;
}

template <typename T>
ostream& operator<<(ostream& os,const vector<T>& v){
    for(int i=0;i<(int)v.size();++i) os<<(i?" ":"")<<v[i];
    return os;
}
template <typename T>
istream& operator>>(istream& is,vector<T>& v){
    for(auto& x:v) is>>x;
    return is;
}

template <typename T,typename U>
void fill(T& x,const U& y){
    x=y;
}
template <typename T,typename U>
void fill(vector<T>& x,const U& y){
    for(auto& v:x) fill(x,y);
}

void debug_out(){
    cout<<endl;
}
template <typename T,typename... Ts>
void debug_out(T&& a,Ts&&... ts){
    cout<<a;
    if(sizeof...(Ts)>0) cout<<", ";
    debug_out(move(ts)...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else 
#define debug(...)
#endif

constexpr char newl='\n';
constexpr int INF=1<<30;
constexpr ll LINF=1LL<<60;
constexpr int MOD=1e9+7;
//constexpr int MOD=998244353;

