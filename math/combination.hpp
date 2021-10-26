// Use ModInt
template <typename T>
struct Combination{
    vector<T> fact,finv,inv;

    Combination(size_t sz):fact(sz+1),finv(sz+1),inv(sz+1){
        fact[0]=finv[sz]=inv[0]=1;
        for(int i=1;i<=sz;++i) fact[i]=fact[i-1]*i;
        finv[sz]/=fact[sz];
        for(int i=sz-1;i>=0;--i) finv[i]=finv[i+1]*(i+1);
    }

    T P(int n,int r) const{
        if(r<0||n<r) return 0;
        return fact[n]*finv[n-r];
    }

    T C(int n,int r) const{
        if(r<0||n<r) return 0;
        return fact[n]*finv[n-r]*finv[r];
    }
    
    T H(int n,int r) const{
        if(n<0||r<0) return 0;
        return C(n+r-1,r);
    }
};
