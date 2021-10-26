template <int mod>
struct ModInt{
    int x;

    constexpr ModInt(int64_t y=0) noexcept:x(y>=0?y%mod:(mod-(-y)%mod)%mod){}

    constexpr ModInt &operator+=(const ModInt& p) noexcept{
        if((x+=p.x)>=mod) x-=mod;
        return *this;
    }

    constexpr ModInt &operator-=(const ModInt& p) noexcept{
        if((x+=mod-p.x)>=mod) x-=mod;
        return *this;
    }

    constexpr ModInt &operator*=(const ModInt& p) noexcept{
        x=(int)(1LL*x*p.x%mod);
        return *this;
    }

    constexpr ModInt &operator/=(const ModInt& p) noexcept{
        *this*=p.inverse();
        return *this;
    }

    constexpr ModInt operator++() noexcept{
        x++;
        if(x==mod) x=0;
        return *this;
    }

    constexpr ModInt operator--() noexcept{
        if(x==0) x=mod;
        x--;
        return *this;
    }

    constexpr ModInt operator++(int) noexcept{
        ModInt res=*this;
        ++*this;
        return res;
    }

    constexpr ModInt operator--(int) noexcept{
        ModInt res=*this;
        --*this;
        return res;
    }

    constexpr ModInt operator-() const noexcept {return ModInt(-x);}
    constexpr ModInt operator+(const ModInt& p) const noexcept {return ModInt(*this)+=p;}
    constexpr ModInt operator-(const ModInt& p) const noexcept {return ModInt(*this)-=p;}
    constexpr ModInt operator*(const ModInt& p) const noexcept {return ModInt(*this)*=p;}
    constexpr ModInt operator/(const ModInt& p) const noexcept {return ModInt(*this)/=p;}

    constexpr bool operator==(const ModInt& p) const noexcept {return x==p.x;}
    constexpr bool operator!=(const ModInt& p) const noexcept {return x!=p.x;}

    ModInt inverse() const{
        int a=x,b=mod,u=1,v=0,t;
        while(b>0){
            t=a/b;
            swap(a-=t*b,b);
            swap(u-=t*v,v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const{
        ModInt res(1),mul(x);
        while(n>0){
            if(n&1) res*=mul;
            mul*=mul;
            n>>=1;
        }
        return res;
    }

    friend ostream &operator<<(ostream& os,const ModInt& p){
        return os<<p.x;
    }

    friend istream &operator>>(istream& is,ModInt& p){
        int64_t t;
        is>>t;
        p=ModInt<mod>(t);
        return (is);
    }
};

using mint=ModInt<MOD>;
