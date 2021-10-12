template <typename T>
pair<T,int> dfs(const vector<vector<pair<int,T>>> &G,int idx,int par){
    pair<T,int> res(0,idx);
    for(const auto &e:G[idx]){
        if(e.first==par) continue;
        auto p=dfs(G,e.first,idx);
        p.first+=e.second;
        res=max(res,p);
    }
    return res;
}

template <typename T>
T diameter(const vector<vector<pair<int,T>>> &G){
    auto p=dfs(G,0,-1);
    auto q=dfs(G,p.second,-1);
    return q.first;
}

int diameter(const vector<vector<int>> &G){
    vector<vector<pair<int,int>>> H(G.size());
    for(int i=0;i<G.size();++i) for(const auto &e:G[i]) H[i].emplace_back(make_pair(e,1));
    return diameter(H);
}
