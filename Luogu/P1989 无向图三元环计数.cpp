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
const int N=100005;
int n,m;
long long ans;
int du[N],vis[N],a[N],rk[N];
vector<int> e[N];
vector<pair<int,int> > bian;
bool cmp(int a,int b){
    if(du[a]==du[b]) return a<b;
    return du[a]<du[b];
}
void dfs(int x){
    for(int v:e[x]) vis[v]=x;
    for(int v:e[x]){
        for(int to:e[v]){
            if(vis[to]==x) ans++;
        }
    }
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i) a[i]=i;
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        ++du[u]; ++du[v];
        bian.push_back({u,v});
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;++i) rk[a[i]]=i;
    for(auto i:bian){
        int u=i.first,v=i.second;
        if(rk[u]<rk[v]) e[u].push_back(v);
        else e[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        dfs(a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}