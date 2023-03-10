#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<climits>
#include<queue>
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
const int N=1000005,M=2000005;
int n,m,k,l,cnt,nwei;
int a[N],b[N],ans[N];
vector<int> color[N];
vector<int> bits[70][2];
struct Node{
    int to,w;
};
vector<Node> e[N<<1];

//* -----迪杰斯特拉
struct dnode{
    int pos,dis;
    bool operator <(const dnode b)const{
        return dis<b.dis;
    }
};
priority_queue<dnode> q;
int dis[N];
bool vis[N];
inline void dij(int s){
    for(int i=1;i<=n;++i) dis[i]=LONG_LONG_MAX>>1,vis[i]=0;
    dis[s]=0;
    priority_queue<dnode>().swap(q);
    dnode tmp;
    int x,ds;
    q.push({s,0});
    while(!q.empty()){
        tmp=q.top();
        q.pop();
        x=tmp.pos;ds=tmp.dis;
        if(vis[x]) continue;
        vis[x]=1;
        for(auto now:e[x]){
            int y=now.to;
            if(dis[y]>dis[x]+now.w){
                dis[y]=dis[x]+now.w;
                if(!vis[y]){
                    q.push({y,dis[y]});
                }
            }
        }
    }
}

signed main()
{
    n=read();
    m=read();
    k=read();
    l=read();
    cnt=n;
    for(int i=1;i<=n;++i) ans[i]=LONG_LONG_MAX>>1;
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    for(int i=1;i<=l;++i){
        b[i]=read();
        color[a[b[i]]].push_back(b[i]);
    }
    for(int i=1;i<=m;++i){
        int x=read(),y=read(),c=read();
        if(x==y) continue;
        e[x].push_back({y,c});
        e[y].push_back({x,c});
    }
    //处理二进制
    for(int i=1;i<=k;++i){
        int tmp=i,wei=0;
        while(tmp){
            for(auto j:color[i])
                bits[wei][tmp&1].push_back(j);
            wei++;
            tmp>>=1;
        }
        nwei=max(nwei,wei);
    }
    for(int i=0;i<nwei;++i){
        for(int j=0;j<2;++j){
            ++cnt;
            for(auto now:bits[i][j]){
                e[cnt].push_back({now,0});
            }
            dij(cnt);
            for(int now=1;now<=n;++now){
                if(((a[now]>>i)&1)!=j)
                    ans[now]=min(ans[now],dis[now]);
            }
        }
    }
    for(int i=1;i<=n;++i){
        if(ans[i]==LONG_LONG_MAX>>1) printf("-1 ");
        else printf("%lld ",ans[i]);
    }
    return 0;
}