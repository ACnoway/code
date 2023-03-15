#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
const int N=100005,M=1000006;
int n,m,sum;
int dfid,cnt,dfn[N],low[N],siz[N];
ll ans[N];
bool ge[N];
vector<int> e[N];
void tarjan(int x,int die){
    dfn[x]=low[x]=++dfid;
    siz[x]=1;
    int ch=0;
    sum=0;
    for(int v:e[x]){
        if(!dfn[v]){
            tarjan(v,x);
            siz[x]+=siz[v];
            low[x]=min(low[x],low[v]);
            if(low[v]>=dfn[x]){
                cnt+=(!ge[x]);
                ge[x]=1;
                ans[x]+=(ll)siz[v]*(n-siz[v]);
                sum+=siz[v];
            }
            if(x==die) ch++;
        }
        else low[x]=min(low[x],dfn[v]);
    }
    if(ch>=2&&x==die) cnt+=(!ge[x]),ge[x]=1;
    if(!ge[x]) ans[x]=2*(n-1);
    else ans[x]+=(ll)(n-sum-1)*(sum+1)+(n-1);
}
int main()
{
    n=read(); m=read();
    for(int i=1;i<=m;++i){
        int x=read(),y=read();
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i]) tarjan(i,i);
    }
    for(int i=1;i<=n;++i) printf("%lld\n",ans[i]);
    return 0;
}