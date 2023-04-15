#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl
#endif
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
template<typename T>
struct MatriX{
    T n=_N,m=_M;
    T vector<vector<int> > a;
    MatriX(int _v=0){
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j) a[i][j]=_v;
        }
    }
    void operator =(MatriX y){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j) a[i][j]=y.a[i][j];
        }
    }
    MatriX operator +(MatriX y){
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j) y.a[i][j]+=a[i][j];
        }
        return y;
    }
    MatriX operator -(MatriX y){
        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j) y.a[i][j]-=a[i][j];
        }
        return y;
    }
    MatriX operator *(MatriX y){
        MatriX<int,this->n,this->m> c;
        int nn=n,mm=y.m;
        for(int i=1;i<=nn;++i){
            for(int j=1;j<=mm;++j){
                for(int k=1;k<=m;++k) c[i][j]+=a[i][k]*y.a[k][j];
            }
        }
        return c;
    }
};
int main()
{
    
    return 0;
}