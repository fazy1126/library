template<typename T>
vector<T> dijkstra(const vector<vector<pair<int,T>>>& g,int s){
    using P=pair<T,int>;
    const auto inf=numeric_limits<T>::max();
    vector<T> d(g.size(),inf);
    d[s]=0;
    priority_queue<P,vector<P>,greater<P>> que;
    que.emplace(P(0,s));
    while(!que.empty()){
        int idx;
        T cost;
        tie(cost,idx)=que.top(); que.pop();
        if(d[idx]<cost) continue;
        for(const auto& e:g[idx]){
            T ncost=cost+e.second;
            if(d[e.first]<=ncost) continue;
            d[e.first]=ncost;
            que.emplace(ncost,e.first);
        }
    }
    return d;
}

