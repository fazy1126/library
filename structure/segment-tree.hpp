template <typename T>
struct SegmentTree{
    using F=function<T(T,T)>;

    int sz;
    vector<T> data;

    const F f;
    const T e;
    
    SegmentTree()=default;

    explicit SegmentTree(int n,const F& f,const T& e):f(f),e(e){
        sz=1;
        while(sz<n) sz<<=1;
        data.assign(2*sz,e);
    }

    void set(int k,const T& x){
        data[k+sz]=x;
    }

    void build(){
        for(int k=sz-1;k>0;--k) data[k]=f(data[2*k],data[2*k+1]);
    }

    void update(int k,const T& x){
        k+=sz;
        data[k]=x;
        while(k>>=1) data[k]=f(data[2*k],data[2*k+1]);
    }

    T query(int a,int b){
        T L=e,R=e;
        for(a+=sz,b+=sz;a<b;a>>=1,b>>=1){
            if(a&1) L=f(L,data[a++]);
            if(b&1) R=f(R,data[--b]);
        }
        return f(L,R);
    }

    T operator[](const int& k) const{
        return data[k+sz];
    }
};

