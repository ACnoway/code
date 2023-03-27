#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<endl<<#x<<'='<<x<<endl
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
const int N=500005;
int T,n,ans,now,top;
int a[N],Ans[N],st[N],pl[N];
struct node{
    int v,p;
    bool operator <(const node &x)const{
        return v<x.v;
    }
}b[N];
vector<int> e[N],E[N];
//* -----并查集
int p[N];
int find(int x){
    while(p[x]!=x) x=p[x]=p[p[x]];
    return p[x];
}
void merge(int x,int y){
    p[find(x)]=y;
}
bool cmp(int x,int y){
    return a[x]<a[y];
}
void dfs(int x){
    for(int v:E[x]){
        Ans[v]=Ans[x]+1;
        dfs(v);
    }
}
//并查集yyds
//从小到大枚举节点u，将其的点权作为目前的最大点权
//然后和比它小的点所构成的连通块中的最大值连边
//最后新建一个图，将上述的点连边，依照点权大小连成一棵树
//这样的话每个点的答案就是在树上的深度
int main()
{
    freopen("ltc.in","r",stdin);
    freopen("ltc.out","w",stdout);
    bool flag1,flag2;
    T=read();
    while(T--){
        n=read();
        for(int i=0;i<=n;++i) e[i].clear(),E[i].clear();
        for(int i=1;i<n;++i){
            int u=read(),v=read();
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1;i<=n;++i) a[i]=read(),p[i]=pl[i]=i;
        sort(pl+1,pl+1+n,cmp);
        for(int i=1;i<=n;++i){
            for(int v:e[pl[i]]){
                if(a[v]<a[pl[i]]){
                    E[pl[i]].push_back(find(v));
                    merge(v,pl[i]);
                }
            }
        }
        Ans[pl[n]]=1;
        dfs(pl[n]);
        for(int i=1;i<=n;++i) printf("%d ",Ans[i]);
        putchar('\n');
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}