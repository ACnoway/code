#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
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
inline void write(long long x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=50005;
long long ans;
int n,a,b,d,cnt,mu[maxn],prim[maxn],sum[maxn];
bool vis[maxn];
void init(){
    mu[1]=1;
    for(int i=2;i<=50000;++i){
        if(!vis[i]) prim[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt&&i*prim[j]<=50000;++j){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0){
                mu[i*prim[j]]=0;
                break;
            }
            mu[i*prim[j]]=-mu[i];
        }
    }
    for(int i=1;i<=50000;++i) sum[i]=sum[i-1]+mu[i];
}
int main()
{
    n=read();
    init();
    while(n--){
        ans=0;
        a=read();b=read();d=read();
        int r=0,N=a/d,M=b/d;
        if(N<M) swap(N,M);
        for(int l=1;l<=M;l=r+1){
            r=min(N/(N/l),M/(M/l));
            ans+=(sum[r]-sum[l-1])*(long long)(N/l)*(M/l);
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}