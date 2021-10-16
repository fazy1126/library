template <typename T,typename U=T>
struct LazySegmentTree{
    using F=function<T(T,T)>;
    using G=function<T(T,U)>;
    using H=function<U(U,U)>;

    int sz,height;
    vector<T> data;
    vector<U> lazy;

    const F f;
    const G g;
    const H h;
    const T et;
    const U eu;

    LazySegmentTree(int n,const F f,const G g,const H h,const T& et,const U& eu)
        :f(f),g(g),h(h),et(et),eu(eu){
        sz=1;
        height=0;
        while(sz<n) sz<<=1,height++;
        data.assign(2*sz,et);
        lazy.assign(2*sz,eu);
    }

    void set(int k,const T& x){
        data[k+sz]=x;
    }

    void build(){
        for(int k=sz-1;k>0;--k) data[k]=f(data[2*k],data[2*k+1]);
    }

    inline void propagate(int k){
        if(lazy[k]!=eu){
            lazy[2*k]=h(lazy[2*k],lazy[k]);
            lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);
            data[k]=apply(k);
            lazy[k]=eu;
        }
    }

    inline T apply(int k){
        return lazy[k]==eu?data[k]:g(data[k],lazy[k]);
    }

    inline void recalc(int k){
        while(k>>=1) data[k]=f(apply(2*k),apply(2*k+1));
    }

    inline void thrust(int k){
        for(int i=height-1;i>0;--i) propagate(k>>i);
    }

    void update(int a,int b,const U& x){
        if(a>=b) return;
        thrust(a+=sz);
        thrust(b+=(sz-1));
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1) lazy[l]=h(lazy[l],x),++l;
            if(r&1) --r,lazy[r]=h(lazy[r],x);
        }
        recalc(a);
        recalc(b);
    }

    T query(int a,int b){
        if(a>=b) return et;
        thrust(a+=sz);
        thrust(b+=(sz-1));
        T L=et,R=et;
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1) L=f(L,apply(l++));
            if(r&1) R=f(R,apply(--r));
        }
        return f(L,R);
    }
};

