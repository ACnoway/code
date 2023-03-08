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
const int N=200005;
int t,n,cnt,mid,fch,fch2,rt;
vector<int> e[N];
int dep[N],minch[N];
bool dfs(int u,int die){
    int minx=INT_MAX,dinx=INT_MAX,dinch=-1;
    for(auto v:e[u]){
        if(v!=die){
            if(!dfs(v,u)) return 0;
            if(dep[v]<minx){
                dinx=minx;
                dinch=minch[u];
                minx=dep[v];
                minch[u]=minch[v];
            }
            else if(dep[v]<dinx){
                dinx=dep[v];
                dinch=minch[v];
            }
        }
    }
    dep[u]=(minx==INT_MAX?0:minx)+1;
    if(minx==INT_MAX) minch[u]=u;
    if(dinx<mid){
        fch=minch[u];
        fch2=dinch;
        return 0;
    }
    if(u==rt&&dep[u]<mid){
        fch=minch[u];
        fch2=dinch;
        return 0;
    }
    return 1;
}
bool check(int mid){
    rt=1;
    if(dfs(rt,0)) return 1;
    rt=fch;
    int tmp=fch2;
    if(rt!=-1&&dfs(rt,0)) return 1;
    rt=tmp;
    if(rt!=-1&&dfs(rt,0)) return 1;
    return 0;
}
int main()
{
    t=read();
    while(t--){
        n=read();
        for(int i=1;i<=n;++i) e[i].clear(),minch[i]=-1;
        int u,v;
        for(int i=1;i<n;++i){
            u=read();
            v=read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int l=0,r=N,ans;
        while(l<=r){
            mid=(l+r)>>1;
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}