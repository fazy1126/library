// x^n mod p
template <typename T>
T mod_pow(T x, long long n, const T &p){
    T res = 1;
    while(n > 0){
        if(n & 1) (res *= x) %= p;
        (x *= x) %= p;
        n >>= 1;
    }
    return res % p;
}
