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
const int N=10004,M=100005;
int n,m;
int top,st[N];
int du[N],nxt[N];
vector<int> e[N];
void dfs(int x){
    for(int i=nxt[x];i<e[x].size();i=nxt[i]){
        nxt[x]=i+1;
        dfs(e[x][i]);
    }
    st[++top]=x;
}
// -----并查集
int p[N];
int find(int x){
    while(p[x]!=x) x=p[x]=p[p[x]];
    return p[x];
}
void merge(int x,int y){
    p[find(x)]=find(y);
}
int main()
{
    n=read();
    debug(n);
    m=read();
    for(int i=0;i<=n;++i) p[i]=i;
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        int uu=find(u),vv=find(v);
        if(uu==vv) continue;
        p[uu]=vv;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        sort(e[i].begin(),e[i].end());
    }
    dfs(1);
    int tmp=top;
    while(top){
        printf("%d\n",st[top]);
        top--;
    }
    for(int i=1;i<=tmp;++i) printf("%d\n",st[i]);
    return 0;
}