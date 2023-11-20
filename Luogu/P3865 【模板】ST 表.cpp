#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=100005,M=18;
int n,m;
int a[N],LOG[M],f[M][N];
inline int query(int l,int r){
    int d=LOG[r-l+1];
    return max(f[d][l],f[d][r-(1<<d)+1]);
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i) f[0][i]=read();
    LOG[1]=0;
    for(int i=2;i<=n;++i) LOG[i]=LOG[i>>1]+1;
    for(int j=1;j<M;++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            f[j][i]=max(f[j-1][i],f[j-1][i+(1<<(j-1))]);
        }
    }
    while(m--){
        int l=read(),r=read();
        printf("%d\n",query(l,r));
    }
    return 0;
}