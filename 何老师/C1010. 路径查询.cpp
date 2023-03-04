#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<array>
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=100005;
int n,m,q;
int p[maxn],ans[maxn];
struct node{
    int u,v,w;
}bian[maxn<<2];
set<int> e[maxn];
set<array<int,2> > qs[maxn];
bool cmp(node a,node b){
    return a.w<b.w;
}
inline int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void work(int x,int y,int val){
    for(auto u:e[x]){
        while(1){
            auto it=qs[y].lower_bound({u,-1});
            if(it==qs[y].end()||(*it)[0]!=u) break;
            int id=(*it)[1];
            ans[id]=val;
            qs[y].erase({u,id});
            qs[u].erase({y,id});
        }
    }
    vector<array<int,3> > shan;
    for(auto u:qs[x]){
        if(e[y].count(u[0])){
            ans[u[1]]=val;
            shan.push_back({x,u[0],u[1]});
        }
    }
    for(auto u:shan){
        qs[u[0]].erase({u[1],u[2]});
        qs[u[1]].erase({u[0],u[2]});
    }
    shan.clear();
    for(auto u:e[x]){
        if(u!=y){
            e[y].insert(u);
            e[u].insert(y);
        }
        e[u].erase(x);
    }
    e[x].clear();
    for(auto u:qs[x]){
        qs[y].insert(u);
        qs[u[0]].insert({y,u[1]});
        qs[u[0]].erase({x,u[1]});
    }
    qs[x].clear();
    p[x]=y;
}
int main()
{
    n=read();
    m=read();
    q=read();
    for(int i=1;i<=n;++i) p[i]=i;
    for(int i=1;i<=q;++i) ans[i]=-1;
    for(int i=1;i<=m;++i){
        bian[i].u=read();
        bian[i].v=read();
        bian[i].w=read();
        e[bian[i].u].insert(bian[i].v);
        e[bian[i].v].insert(bian[i].u);
    }
    int u,v;
    for(int i=1;i<=q;++i){
        u=read();
        v=read();
        if(e[u].count(v)){
            ans[i]=0;
        }
        else{
            qs[u].insert({v,i});
            qs[v].insert({u,i});
        }
    }
    sort(bian+1,bian+m+1,cmp);
    for(int i=1;i<=m;++i){
        bian[i].u=find(bian[i].u);
        bian[i].v=find(bian[i].v);
        if(bian[i].u!=bian[i].v){
            if(qs[bian[i].u].size()+e[bian[i].u].size()>qs[bian[i].v].size()+e[bian[i].v].size()){
                swap(bian[i].u,bian[i].v);
            }
            work(bian[i].u,bian[i].v,bian[i].w);
        }
    }
    for(int i=1;i<=q;++i) write(ans[i]),putchar('\n');
    return 0;
}