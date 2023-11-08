#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=200005,M=200005;
int n,m,k,z;
struct edge{
    int u,v,w;
    bool operator <(const edge &x)const{
        return w<x.w;
    }
}e[M];
int p[N];
inline int find(int x){
    while(x!=p[x]) x=p[x]=p[p[x]];
    return p[x];
}
int main()
{
    freopen("constructure.in","r",stdin);
    freopen("constructure.out","w",stdout);
    n=read(); m=read();
    k=read(); z=read();
    for(int i=0;i<=n;++i) p[i]=i;
    for(int i=1;i<=m;++i){
        e[i].u=read(); e[i].v=read();
        e[i].w=read();
    }
    sort(e+1,e+m+1);
    int ans=0,cnt=0;
    for(int i=1;i<=m;++i){
        int u=find(e[i].u),v=find(e[i].v);
        if(u==v) continue;
        if(e[i].w>z&&n-1-cnt<=k){
            ans+=z*(n-1-cnt);
            break;
        }
        else{
            ans+=e[i].w,p[v]=u;
            ++cnt;
        }
    }
    printf("%d\n",ans);
    return 0;
}