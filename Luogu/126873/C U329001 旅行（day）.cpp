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
const int N=2e5+10;
int n,m,S,T;
int idx=1,head[N<<5],to[N<<5],nxt[N<<5];
bool vis[N<<3];
typedef pair<int,int> pii;
void addedge(int u,int v){
    to[++idx]=v;
    nxt[idx]=head[u];
    head[u]=idx;
}
void bfs(){
    queue<pii> q;
    pii p;
    q.emplace((pii){S,0});
    vis[S]=1;
    while(!q.empty()){
        p=q.front();
        q.pop();
        int x=p.first,d=p.second;
        for(int i=head[x];)
    }
}
int main()
{
    n=read();
    m=read();
    S=read();
    T=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<7;++j){
            addedge(i+(j-1)*n,i+j*n);
            addedge(i+j*n,i+(j-1)*n);
        }
    }
    int u,v,w;
    for(int i=1;i<=m;++i){
        u=read(); v=read();
        w=read(); --w;
        u+=w*n;
        v+=w*n;
        addedge(u,v);
        addedge(v,u);
    }
    bfs();
    return 0;
}