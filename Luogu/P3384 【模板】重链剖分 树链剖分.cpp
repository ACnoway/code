#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define lson x<<1
#define rson x<<1|1
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
const int maxn=200005;

int n,m,r,mod;
//链式前向星存边，w和wn是权值
int e,to[maxn],nxt[maxn],head[maxn],w[maxn],wn[maxn];
//线段树
struct node{
    int l,r,lt,v;
}t[maxn<<2];
//树剖
//son重儿子编号 id新编号 fa父亲编号 dfs序 dep深度  siz子树大小 top当前链顶端节点
int son[maxn],id[maxn],fa[maxn],cnt,dep[maxn],siz[maxn],top[maxn];
int ans;

//A*存边
inline void addedge(int u,int v){
    to[++e]=v;
    nxt[e]=head[u];
    head[u]=e;
}

//线段树
inline void pushdown(int x){
    if(t[x].lt){
        t[lson].lt+=t[x].lt;
        t[rson].lt+=t[x].lt;
        int mid=(t[x].l+t[x].r)>>1;
        t[lson].v+=(mid-t[lson].l+1)*t[x].lt;
        t[rson].v+=(t[rson].r-mid)*t[x].lt;
        t[lson].v%=mod;t[rson].v%=mod;
        t[x].lt=0;
    }
}
void build(int x,int l,int r){
    t[x].l=l;t[x].r=r;
    t[x].lt=0;
    if(l==r){
        t[x].v=wn[l];
        t[x].v%=mod;
        return;
    }
    int mid=(l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    t[x].v=(t[lson].v+t[rson].v)%mod;
    return;
}
void add(int x,int l,int r,int k){
    if(t[x].r<l||t[x].l>r) return;
    if(t[x].l>=l&&t[x].r<=r){
        t[x].v+=(t[x].r-t[x].l+1)*k;
        t[x].lt+=k;
        return;
    }
    pushdown(x);
    if(t[lson].r>=l) add(lson,l,r,k);
    if(t[rson].l<=r) add(rson,l,r,k);
    t[x].v=(t[lson].v+t[rson].v)%mod;
    return;
}
int search(int x,int l,int r){
    if(t[x].l>r||t[x].r<l) return 0;
    if(t[x].l>=l&&t[x].r<=r) return t[x].v%mod;
    pushdown(x);
    int s=0;
    if(t[lson].r>=l) s+=search(lson,l,r);
    if(t[rson].l<=r) s+=search(rson,l,r);
    return s%mod;
}

//树剖
void dfs1(int x,int f,int deep){
    dep[x]=deep;
    fa[x]=f;
    siz[x]=1;
    //maxson记录儿子里的最大儿子数，用来找重儿子
    int maxson=-1,y;
    for(int i=head[x];i;i=nxt[i]){
        y=to[i];
        if(y==f) continue;
        dfs1(y,x,deep+1);
        siz[x]+=siz[y];
        //如果y的儿子数大于目前最大儿子数
        if(siz[y]>maxson) son[x]=y,maxson=siz[y];
    }
}
//x当前节点，topf当前链的最顶端的节点 
void dfs2(int x,int topf){
    id[x]=++cnt;
    wn[cnt]=w[x];
    top[x]=topf;
    if(!son[x]) return;
    dfs2(son[x],topf);
    int y;
    for(int i=head[x];i;i=nxt[i]){
        y=to[i];
        if(y==fa[x]||y==son[x]) continue;
        dfs2(y,y);
    }
}
//处理任意两点间路径上的点权和
inline int qrange(int x,int y){
    ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans+=search(1,id[top[x]],id[x]);
        ans%=mod;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans+=search(1,id[x],id[y]);
    return ans%mod;
}
//修改任意两点间路径上的点权
inline void updrange(int x,int y,int k){
    k%=mod;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        add(1,id[top[x]],id[x],k);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    add(1,id[x],id[y],k);
}
//处理一点及其子树的点权和
inline int qson(int x){
    return search(1,id[x],id[x]+siz[x]-1);
}
//更改一点及其子树的点权
inline void updson(int x,int k){
    add(1,id[x],id[x]+siz[x]-1,k);
}
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
int main()
{
    n=read();m=read();r=read();mod=read();
    for(int i=1;i<=n;++i) w[i]=read();
    int k,u,v,z;
    for(int i=1;i<=n;++i){
        u=read();v=read();
        addedge(u,v);addedge(v,u);
    }
    dfs1(r,0,1);
    dfs2(r,r);
    build(1,1,n);
    while(m--){
        k=read();
        switch(k){
            case 1:{
                u=read();v=read();z=read();
                updrange(u,v,z);
                break;
            }
            case 2:{
                u=read();v=read();
                write(qrange(u,v));
                putchar('\n');
                break;
            }
            case 3:{
                u=read();v=read();
                updson(u,v);
                break;
            }
            default:{
                u=read();
                write(qson(u));
                putchar('\n');
                break;
            }
        }
    }
    return 0;
}
