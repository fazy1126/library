#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;++i)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
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
using pint=pair<int,int>;
template <typename T> using pque=priority_queue<T>;
template <typename T> using rpque=priority_queue<T,vector<T>,greater<T>>;
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
    for(auto& v:x) fill(v,y);
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

