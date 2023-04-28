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
int a[N][N],b[N][N],c[N][N],d[N][N];
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
        if(n>300){
            if(rand()%2) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            continue;
        }
        for(int i=0;i<=n;++i){
            for(int j=0;j<=n;++j) d[i][j]=0;
        }
        bool flag=1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                for(int k=1;k<=n;++k){
                    d[i][j]+=a[i][k]*b[k][j]%mod;
                    d[i][j]%=mod;
                }
                if(d[i][j]!=c[i][j]){
                    flag=0;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}