template <class T>
struct Matrix{
    vector<vector<T>> A;

    Matrix(size_t n,size_t m,T x=0):A(n,vector<T>(m,x)){}

    size_t size() const{
        if(A.empty()) return 0;
        assert(A.size()==A[0].size());
        return A.size();
    }

    size_t height() const{
        return A.size();
    }

    size_t width() const{
        return A[0].size();
    }
    
    inline const vector<T> &operator[](int k) const{
        return A[k];
    }

    inline vector<T> &operator[](int k){
        return A[k];
    }

    static Matrix E(size_t n){
        Matrix mat(n,n);
        for(int i=0;i<n;++i) mat[i][i]=1;
        return mat;
    }

    Matrix &operator+=(const Matrix& B){
        size_t h=height(),w=width();
        assert(h==B.height()&&w==B.width());
        for(int i=0;i<h;++i) for(int j=0;j<w;++j) (*this)[i][j]+=B[i][j];
        return *this;
    }

    Matrix &operator-=(const Matrix& B){
        size_t h=height(),w=width();
        assert(h==B.height()&&w==B.width());
        for(int i=0;i<h;++i) for(int j=0;j<w;++j) (*this)[i][j]-=B[i][j];
        return *this;
    }

    Matrix &operator*=(const Matrix& B){
        size_t h=height(),w=B.width(),p=width();
        assert(p==B.height());
        vector<vector<T>> C(h,vector<T>(w,0));
        for(int i=0;i<h;++i) for(int j=0;j<w;++j) for(int k=0;k<p;++k)
            C[i][j]+=(*this)[i][k]*B[k][j];
        A.swap(C);
        return *this;
    }
    
    Matrix operator+(const Matrix& B) const{return Matrix(*this)+=B;}
    Matrix operator-(const Matrix& B) const{return Matrix(*this)-=B;}
    Matrix operator*(const Matrix& B) const{return Matrix(*this)*=B;}

    //ToDo べき乗などを書く
};
