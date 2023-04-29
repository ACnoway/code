#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<time.h>
#define int long long
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
const int N=3003,mod=998244353;
int T,n;
int a[N][N],b[N][N],c[N][N];
int d[N],sa[N],sb[N],sc[N];
signed main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    srand(time(0));
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j) a[i][j]=read();
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j) b[i][j]=read();
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j) c[i][j]=read();
        }
        for(int i=1;i<=n;++i){
            d[i]=rand()%mod+1;
            sa[i]=sb[i]=sc[i]=0;
        }
        for(int i=1;i<=n;++i){
            for(int k=1;k<=n;++k){
                sa[i]+=d[k]*a[k][i]%mod;
                sa[i]%=mod;
            }
        }
        for(int i=1;i<=n;++i){
            for(int k=1;k<=n;++k){
                sb[i]+=sa[k]*b[k][i]%mod;
                sb[i]%=mod;
            }
        }
        for(int i=1;i<=n;++i){
            for(int k=1;k<=n;++k){
                sc[i]+=d[k]*c[k][i]%mod;
                sc[i]%=mod;
            }
        }
        bool flag=1;
        for(int i=1;i<=n;++i){
            if(sc[i]!=sb[i]){
                flag=0;
                break;
            }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}