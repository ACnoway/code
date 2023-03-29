#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=200005;
int n,m,q,cnt;
int a[N],b[N],t[N];
int sum[N<<5],L[N<<5],R[N<<5];
int build(int l,int r){
    //初始化线段树
    int rt=++cnt;
    sum[rt]=0;
    if(l<r){
        int mid=(l+r)>>1;
        L[rt]=build(l,mid);
        R[rt]=build(mid+1,r);
    }
    return rt;
}
int update(int pre,int l,int r,int x){
    //在值域上新开线段树
    int rt=++cnt;
    L[rt]=L[pre]; R[rt]=R[pre];
    sum[rt]=sum[pre]+1;
    if(l<r){
        int mid=(l+r)>>1;
        if(x<=mid) L[rt]=update(L[pre],l,mid,x);
        else R[rt]=update(R[pre],mid+1,r,x);
    }
    return rt;
}
// u，v是查询区间，l，r是范围
int query(int u,int v,int l,int r,int k){
    if(l>=r) return l;
    int x=sum[L[v]]-sum[L[u]];
    int mid=(l+r)>>1;
    //操作跟平衡树查第k大基本一样
    if(x>=k) return query(L[u],L[v],l,mid,k);
    else return query(R[u],R[v],mid+1,r,k-x);
}
int main()
{
    n=read(); q=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        b[i]=a[i];
    }
    //离散化+去重
    sort(b+1,b+1+n);
    m=unique(b+1,b+n+1)-b-1;
    t[0]=build(1,m);
    for(int i=1;i<=n;++i){
        int tmp=lower_bound(b+1,b+1+m,a[i])-b;
        t[i]=update(t[i-1],1,m,tmp);
    }
    while(q--){
        int x=read(),y=read(),z=read();
        int ans=query(t[x-1],t[y],1,m,z);
        printf("%d\n",b[ans]);
    }
    return 0;
}