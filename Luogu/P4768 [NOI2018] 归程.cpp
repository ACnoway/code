#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<climits>
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
const int N=800005,M=1600010;
int T,n,m;
int dep[N];
int fa[N][25],Min[N][25];
//---输入图---
struct node{
    int u,v,hb;
    bool operator <(const node b)const{
        return hb>b.hb;
    }
}edge[M];
//---新图---
struct Node{
    int to,nxt,hb;
}e[M<<1];
int idx,head[N];
void addedge(int x,int y){
    e[++idx].to=y;
    e[idx].nxt=head[x];
    head[x]=idx;
}
//-----并查集-----
int p[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
//-----迪杰斯特拉-----
struct dnode{
    int pos,dis;
    bool operator <(const dnode b)const{
        return dis>b.dis;
    }
};
priority_queue<dnode> q;
typedef pair<int,int> pii;
pii val[N];
int cnt;
struct bian{
    int to,nxt,dis;
}E[M<<1];
int didx,dh[N];
inline void dadd(int u,int v,int w){
    E[++didx].to=v;
    E[didx].nxt=dh[u];
    E[didx].dis=w;
    dh[u]=didx;
}
inline void dij(int s){
    for(int i=1;i<=n;++i) val[i].second=INT_MAX;
    val[s].second=0;
    priority_queue<dnode>().swap(q);
    q.push((dnode){s,val[s].second});
    int x,y,d;
    while(!q.empty()){
        auto tmp=q.top();
        q.pop();
        x=tmp.pos;d=tmp.dis;
        if(val[x].second!=d) continue;
        for(int i=dh[x];i;i=E[i].nxt){
            y=E[i].to;d=E[i].dis;
            if(val[y].second>val[x].second+d){
                val[y].second=val[x].second+d;
                q.push({y,val[y].second});
            }
        }
    }
}
//-----克鲁斯卡尔-----
inline void kruskal(){
    for(int i=1;i<=2*n;++i) val[i].first=INT_MAX,p[i]=i;
    sort(edge+1,edge+1+m);
    int x,y,h;
    cnt=n;
    for(int i=1;i<=m;++i){
        x=find(edge[i].u);
        y=find(edge[i].v);
        h=edge[i].hb;
        if(x!=y){
            val[++cnt]=make_pair(h,min(val[x].second,val[y].second));
            p[cnt]=p[x]=p[y]=cnt;
            addedge(cnt,x);
            addedge(x,cnt);
            addedge(cnt,y);
            addedge(y,cnt);
        }
    }
}
void dfs(int x,int die){
    fa[x][0]=die;
    Min[x][0]=min(val[x].first,val[die].first);
    dep[x]=dep[die]+1;
    debug(x);
    for(int i=1;i<=__lg(dep[x]);++i){
        fa[x][i]=fa[fa[x][i-1]][i-1];
        Min[x][i]=min(Min[x][i-1],Min[fa[x][i-1]][i-1]);
    }
    for(int i=head[x];i;i=e[i].nxt){
        if(e[i].to==die) continue;
        dfs(e[i].to,x);
    }
}
int main()
{
    T=read();
    while(T--){
        n=read();
        m=read();
        //初始化
        idx=didx=cnt=0;
        for(int i=0;i<=2*n;++i){
            dh[i]=head[i]=0;
            val[i].first=val[i].second=0;
        }
        for(int i=0;i<=2*m;++i){
            E[i].dis=E[i].nxt=E[i].to=0;
            e[i].nxt=e[i].to=0;
            edge[i].u=edge[i].v=edge[i].hb=0;
        }
        for(int i=0;i<=2*n;++i){
            for(int j=0;j<25;++j){
                fa[i][j]=Min[i][j]=0;
            }
            dep[i]=0;
        }
        int u,v,cd,hb;
        for(int i=1;i<=m;++i){
            u=read();v=read();
            cd=read();hb=read();
            //dij边
            dadd(u,v,cd);
            dadd(v,u,cd);
            //存图
            edge[i].u=u;
            edge[i].v=v;
            edge[i].hb=hb;
        }
        dij(1);
        kruskal();
        dfs(find(1),0);
        int q=read(),k=read(),S=read(),ls=0;
        while(q--){
            int ss=read(),pp=read();
            ss=(ss+k*ls-1)%n+1;
            pp=(pp+k*ls)%(S+1);
            for(int i=22;i>=0;--i){
                if(Min[ss][i]>pp) ss=fa[ss][i];
            }
            printf("%d\n",ls=val[ss].second);
        }
    }
    return 0;
}