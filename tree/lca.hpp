struct LCA{
    int LOG;
    vector<int> dep;
    const vector<vector<int>>& g;
    vector<vector<int>> table;

    LCA(const vector<vector<int>>& g):g(g),dep(g.size()){
        LOG=1;
        while((1<<LOG)<g.size()) LOG++;
        table.assign(LOG,vector<int>(g.size(),-1));
    }

    void build(int root=0){
        dfs(root,-1,0);
        for(int k=0;k+1<LOG;++k){
            for(int i=0;i<table[k].size();++i){
                if(table[k][i]==-1) table[k+1][i]=-1;
                else table[k+1][i]=table[k][table[k][i]];
            }
        }
    }

    int query(int u,int v){
        if(dep[u]>dep[v]) swap(u,v);
        for(int i=LOG-1;i>=0;--i){
            if((1<<i)&(dep[v]-dep[u])) v=table[i][v];
        }
        if(u==v) return u;
        for(int i=LOG-1;i>=0;--i){
            if(table[i][u]!=table[i][v]){
                u=table[i][u];
                v=table[i][v];
            }
        }
        return table[0][u];
    }

    int dist(int u,int v){
        return dep[u]+dep[v]-2*dep[query(u,v)];
    }

    private:
    void dfs(int id,int par,int d){
        table[0][id]=par;
        dep[id]=d;
        for(auto& to:g[id]){
            if(to!=par) dfs(to,id,d+1);
        }
    }
};

