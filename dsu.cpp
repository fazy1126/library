struct DSU{
    vector<int> data;

    DSU(int n):data(n,-1){}

    int leader(int x){
        if(data[x]<0) return x;
        else return data[x]=leader(data[x]);
    }

    int size(int x){
        return -data[leader(x)];
    }

    void merge(int x,int y){
        x=leader(x),y=leader(y);
        if(x==y) return;
        if(data[x]>data[y]) swap(x,y);
        data[x]+=data[y];
        data[y]=x;
    }

    bool same(int x,int y){
        return leader(x)==leader(y);
    }
};
