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
const int N=500005,mod=998244353;
int n;
int a[N],p[N];
long long ans;
long long sum[N];
typedef pair<int,int> pii;
pii b[N];
bool vis[N];
inline int find(int x){
    while(x!=p[x]) x=p[x]=p[p[x]];
    return p[x];
}
void dfs(int x){
    if(x>=n){
        long long res=1;
        for(int i=1;i<=n;++i) sum[i]=a[i],p[i]=i;
        for(int i=1;i<n;++i){
            if(vis[i]) continue;
            int u=find(b[i].first),v=find(b[i].second);
            if(u!=v){
                p[v]=u;
                sum[u]^=sum[v];
            }
        }
        for(int i=1;i<=n;++i) if(p[i]==i) res*=sum[i],res%=mod;
        ans+=res;
        ans%=mod;
        return;
    }
    dfs(x+1);
    vis[x]=1;
    dfs(x+1);
    vis[x]=0;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<n;++i){
        b[i].first=i+1;
        b[i].second=read();
    }
    dfs(1);
    printf("%lld\n",ans%mod);
    return 0;
}