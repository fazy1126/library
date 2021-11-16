template <typename T>
struct RangeSet{
    set<pair<T,T>> data;
    T inf;

    RangeSet(){
        inf=numeric_limits<T>::max();
        data.emplace(-inf,-inf);
        data.emplace(inf,inf);
    }
    
    bool covered(T l,T r){
        auto itr=prev(data.lower_bound({l+1,l+1}));
        return r<=itr->second;
    }
    bool covered(T x){
        return covered(x,x);
    }
    
    // insert [l,r]
    T insert(T l,T r){
        auto itr=prev(data.lower_bound({l+1,l+1}));
        if(r<=itr->second) return T(0);
        T erased=0;
        if(l-1<=itr->second){
            l=itr->first;
            erased+=itr->second-itr->first+1;
            itr=data.erase(itr);
        }
        else itr=next(itr);
        while(r>itr->second){
            erased+=itr->second-itr->first+1;
            itr=data.erase(itr);
        }
        if(itr->first<=r+1){
            r=itr->second;
            erased+=itr->second-itr->first+1;
            data.erase(itr);
        }
        data.emplace(l,r);
        return r-l+1-erased;
    }
    T insert(T x){
        return insert(x,x);
    }
    
    // erase [l,r]
    T erase(T l,T r){
        auto itr=prev(data.lower_bound({l+1,l+1}));
        if(r<=itr->second){
            if(itr->first<l) data.emplace(itr->first,l-1);
            if(r<itr->second) data.emplace(r+1,itr->second);
            data.erase(itr);
            return r-l+1;
        }
        T erased=0;
        if(l<=itr->second){
            erased+=itr->second-l+1;
            if(itr->first<l) data.emplace(itr->first,l-1);
            itr=erase(itr);
        }
        else itr=next(itr);
        while(itr->second<=r){
            erased+=itr->second-itr->first+1;
            itr=data.erase(itr);
        }
        if(itr->first<=r){
            erased+=r-itr->first+1;
            if(r<itr->second) data.emplace(r+1,itr->second);
            data.erase(itr);
        }
        return erased;
    }
    T erase(T x){
        return erase(x,x);
    }

    size_t size(){
        return data.size()-2;
    }
    
    // mex [x,inf)
    T mex(T x){
        auto itr=prev(data.lower_bound({x+1,x+1}));
        if(x<=itr->second) return itr->second+1;
        else return x;
    }
};

