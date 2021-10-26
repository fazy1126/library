template <typename T>
struct SegmentTree{
    using F=function<T(T,T)>;

    int sz;
    vector<T> data;

    const F op;
    const T e;
    
    SegmentTree()=default;

    explicit SegmentTree(int n,const F& op,const T& e):op(op),e(e){
        sz=1;
        while(sz<n) sz<<=1;
        data.assign(2*sz,e);
    }

    void set(int k,const T& x){
        data[k+sz]=x;
    }

    void build(){
        for(int k=sz-1;k>0;--k) data[k]=op(data[2*k],data[2*k+1]);
    }

    void update(int k,const T& x){
        k+=sz;
        data[k]=x;
        while(k>>=1) data[k]=op(data[2*k],data[2*k+1]);
    }

    T query(int l,int r){
        T L=e,R=e;
        for(l+=sz,r+=sz;l<r;l>>=1,r>>=1){
            if(l&1) L=op(L,data[l++]);
            if(r&1) R=op(R,data[--r]);
        }
        return op(L,R);
    }

    T operator[](const int& k) const{
        return data[k+sz];
    }
};

