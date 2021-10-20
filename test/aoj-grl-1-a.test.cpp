#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../template/template.cpp"
#include "../graph/dijkstra.hpp"

void Main(){
    int V,E,r;
    cin>>V>>E>>r;
    graph<ll> g(V);
    REP(i,V){
        int s,t,d;
        cin>>s>>t>>d,s--,t--;
        g[s].eb(t);
    }
    auto d=dijkstra(g,r);
    REP(i,V){
        if(d[i]>=LINF) cout<<"INF"<<newl;
        else cout<<d[i]<<newl;
    }
}
