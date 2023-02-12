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
const int maxn=10000007;
long long ans;
int t,n,m,d,cnt,mu[maxn],prim[maxn],sum[maxn],f[maxn];
bool vis[maxn];
void init(){
    mu[1]=1;
    for(int i=2;i<=10000000;++i){
        if(!vis[i]) prim[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt&&i*prim[j]<=10000000;++j){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0){
                mu[i*prim[j]]=0;
                break;
            }
            mu[i*prim[j]]=-mu[i];
        }
    }
    for(int i=1;i<=cnt;++i){
        for(int j=1;prim[i]*j<=10000000;++j) f[prim[i]*j]+=mu[j];
    }
    for(int i=1;i<=10000000;++i) sum[i]=sum[i-1]+f[i];
}
int main()
{
    t=read();
    init();
    while(t--){
        ans=0;
        n=read();m=read();
        int r=0;
        if(n<m) swap(n,m);
        for(int l=1;l<=m;l=r+1){
            r=min(n/(n/l),m/(m/l));
            ans+=(sum[r]-sum[l-1])*(long long)(n/l)*(m/l);
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}