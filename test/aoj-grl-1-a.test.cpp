#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../template/template.cpp"
#include "../graph/dijkstra.hpp"

int main(){
    int V,E,r;
    cin>>V>>E>>r;
    graph<ll> g(V);
    REP(i,E){
        int s,t,d;
        cin>>s>>t>>d;
        g[s].eb(t,d);
    }
    auto d=dijkstra(g,r);
    REP(i,V){
        if(d[i]>=LINF) cout<<"INF"<<newl;
        else cout<<d[i]<<newl;
    }
}
