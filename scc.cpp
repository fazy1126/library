struct SCC{
    vector<int> comp,order;
    vector<bool> used;
    vector<vector<int>> G,rG;

    SCC(int n=0):comp(n,-1),used(n,false),G(n),rG(n){}

    void add_edge(int from,int to){
        G[from].emplace_back(to);
        rG[to].emplace_back(from);
    }

    //強連結成分の数を返す
    int build(){
        for(int i=0;i<G.size();++i) if(!used[i]) dfs(i);
        int k=0;
        for(int i=G.size()-1;i>=0;--i) if(comp[order[i]]==-1) rdfs(order[i],k++);
        return k;
    }

    int operator[](int k){
        return comp[k];
    }

private:
    void dfs(int v){
        used[v]=true;
        for(auto to:G[v]){
            if(!used[to]) dfs(to);
        }
        order.emplace_back(v);
    }

    void rdfs(int v,int k){
        comp[v]=k;
        for(auto to:rG[v]){
            if(comp[to]==-1) rdfs(to,k);
        }
    }
};
