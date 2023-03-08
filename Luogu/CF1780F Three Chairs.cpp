#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
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
const int N=300005;
int n,cnt;
int a[N],mu[N],p[N],f[N],pos[N];
bool vis[N];
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    int ma=a[n];
    mu[1]=1;
    for(int i=2;i<=ma;++i){
        if(!vis[i]){
            mu[i]=-1;
            p[++cnt]=i;
        }
        for(int j=1;j<=cnt&&i*p[j]<=ma;++j){
            vis[p[j]*i]=1;
            if(i%p[j]==0) break;
            mu[i*p[j]]=-mu[i];
        }
    }
    for(int i=1;i<=n;++i) f[a[i]]=i;
    ll sum=0,ans=0;
    for(int i=1;i<=ma;++i){
        cnt=0;
        for(int j=i;j<=ma;j+=i){
            if(f[j]) pos[++cnt]=f[j];
        }
        sum=(-1ll*cnt*(cnt-1)>>1);
        for(int j=1;j<=cnt;++j) sum+=(ll)(j+j-cnt-1)*pos[j];
        ans+=sum*mu[i];
    }
    printf("%lld\n",ans);
    return 0;
}