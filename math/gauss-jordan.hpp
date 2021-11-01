#include "matrix.hpp"

template <typename T>
int GaussJordan(Matrix<T> &A,bool is_extended=false){
    int h=A.height(),w=A.width();
    int rank=0;
    for(int j=0;j<w;++j){
        if(is_extended&&j==w-1) break;
        int pivot=-1;
        for(int i=rank;i<h;++i){
            if(A[i][j]!=0){
                pivot=i;
                break;
            }
        }
        if(pivot==-1) continue;
        swap(A[pivot],A[rank]);
        T t=A[rank][j];
        for(int j2=j;j2<w;++j2) A[rank][j2]/=t;
        for(int i=0;i<h;++i){
            if(i!=rank&&A[i][j]!=0){
                t=A[i][j];
                for(int j2=j;j2<w;++j2) A[i][j2]-=A[rank][j2]*t;
            }
        }
        ++rank;
    }
    return rank;
}
