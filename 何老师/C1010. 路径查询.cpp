#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<array>
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
}bian[maxn];
set<int> e[maxn];
set<array<int,2>> qs[maxn];
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
            if(it==qs[y].end()||)
        }
    }
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