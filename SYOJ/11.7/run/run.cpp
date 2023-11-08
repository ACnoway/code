#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
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
const int N=4000006,M=8000006,inf=1<<28;
int n,m,d,r;
string s[1003];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int idx,head[N],nxt[M],to[M];
inline int id(int x,int y){return (x-1)*m+y;}
inline void add(int u,int v){
    to[++idx]=v;
    nxt[idx]=head[u];
    head[u]=idx;
}
int dis[N],lu[N];
bool vis[N];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
void dij(int x){
    for(int i=0;i<=n*m*2;++i) dis[i]=inf;
    q.emplace(0,x);
    dis[x]=0;
    pii p;
    int u,v;
    while(q.size()){
        p=q.top();
        q.pop();
        u=p.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i]){
            v=to[i];
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                lu[v]=u;
                if(!vis[v]) q.emplace(dis[v],v);
            }
        }
    }
}
int main()
{
    // freopen("run.in","r",stdin);
    // freopen("run.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>d>>r;
    getchar();
    for(int i=1;i<=n;++i){
        getline(cin,s[i]);
        s[i]='#'+s[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<s[i].size();++j){
            if(s[i][j]=='#') continue;
            int nx=i,ny=j;
            for(int k=0;k<4;++k){
                nx=i+dx[k],ny=j+dy[k];
                if(nx<1||nx>n||ny<1||ny>m||s[nx][ny]=='#') continue;
                add(id(i,j),id(nx,ny));
                add(id(i,j)+n*m,id(nx,ny)+n*m);
            }
            nx=i+d,ny=j+r;
            if(nx<1||nx>n||ny<1||ny>m||s[nx][ny]=='#') continue;
            add(id(i,j),id(nx,ny)+n*m);
        }
    }
    dij(id(1,1));
    if(dis[id(n,m)]!=inf||dis[id(n,m)+n*m]!=inf) printf("%d\n",min(dis[id(n,m)],dis[id(n,m)+n*m]));
    else printf("-1\n");
    return 0;
}