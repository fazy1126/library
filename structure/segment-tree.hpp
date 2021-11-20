template <typename T>
struct SegmentTree{
    using F=function<T(T,T)>;

    int n,sz;
    vector<T> data;

    const F f;
    const T e;

    SegmentTree()=default;

    explicit SegmentTree(int n,const F& f,const T& e):n(n),f(f),e(e){
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

    template <typename C>
    int find_first(int l,const C& check) const{
        if(l>=n) return n;
        l+=sz;
        T now=e;
        do{
            while((l&1)==0) l>>=1;
            if(check(f(now,data[l]))){
                while(l<sz){
                    l<<=1;
                    T next=f(now,data[l]);
                    if(!check(next)){
                        now=next;
                        l++;
                    }
                }
                return l-sz+1;
            }
            now=f(now,data[l++]);
        } while((l&-l)!=l);
        return n;
    }

    T operator[](const int& k) const{
        return data[k+sz];
    }
};

