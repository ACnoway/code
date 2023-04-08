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
const int N=10004;
int n,m,query[102];
int maxp[N],siz[N],rt,cnt=0,sum,d[N],bl[N],a[N];
bool vis[N],ans[102];
typedef pair<int,int> pii;
vector<pii> e[N];
void getrt(int x,int die){
    siz[x]=1;
    maxp[x]=0;
    for(auto i:e[x]){
        int v=i.first;
        if(v==die||vis[v]) continue;
        getrt(v,x);
        siz[x]+=siz[v];
        maxp[x]=max(maxp[x],siz[v]);
    }
    maxp[x]=max(maxp[x],sum-siz[x]);
    if(!rt||maxp[x]<maxp[rt]) rt=x;
}
bool cmp(int x,int y){
    return d[x]<d[y];
}
void getdis(int x,int die,int dis,int from){
    a[++cnt]=x;
    d[x]=dis;
    bl[x]=from;
    for(auto i:e[x]){
        int v=i.first,w=i.second;
        if(v==die||vis[v]) continue;
        getdis(v,x,dis+w,from);
    }
}
void calc(int x){
    cnt=0;
    a[++cnt]=x;
    bl[x]=x;
    d[x]=0;
    for(auto i:e[x]){
        int v=i.first,w=i.second;
        if(vis[v]) continue;
        getdis(v,x,w,v);
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=m;++i){
        if(ans[i]) continue;
        int l=1,r=cnt;
        while(l<r){
            if(d[a[l]]+d[a[r]]>query[i]) --r;
            else if(d[a[l]]+d[a[r]]<query[i]) ++l;
            else if(bl[a[l]]==bl[a[r]]){
                if(d[a[r]]==d[a[r-1]]) --r;
                else ++l;
            }
            else{
                ans[i]=1;
                break;
            }
        }
    }
}
void solve(int x){
    vis[x]=1;
    calc(x);
    
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<n;++i){
        int u=read(),v=read(),w=read();
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=m;++i){
        query[i]=read();
    }
    maxp[0]=sum=n;
    getrt(1,0);
    solve(rt);
    return 0;
}