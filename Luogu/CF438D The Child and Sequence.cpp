#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define lson i<<1
#define rson i<<1|1
#define int long long
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
const int N=100005;
int n,m;
int a[N],v[N<<2],da[N<<2];
void build(int i,int l,int r){
    if(l==r){
        v[i]=a[l];
        da[i]=v[i];
        return;
    }
    int mid=(l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    da[i]=max(da[lson],da[rson]);
    v[i]=v[lson]+v[rson];
}
int sum(int i,int l,int r,int L,int R){
    if(L<=l&&r<=R){
        return v[i];
    }
    int s=0,mid=(l+r)>>1;
    if(mid>=L) s+=sum(lson,l,mid,L,R);
    if(mid<R) s+=sum(rson,mid+1,r,L,R);
    return s;
}
void mo(int i,int l,int r,int L,int R,int k){
    if(da[i]<k) return;
    if(l==r){
        v[i]%=k;
        da[i]%=k;
        return;
    }
    int mid=(l+r)>>1;
    if(L<=mid) mo(lson,l,mid,L,R,k);
    if(mid<R) mo(rson,mid+1,r,L,R,k);
    v[i]=v[lson]+v[rson];
    da[i]=max(da[lson],da[rson]);
}
void gai(int i,int l,int r,int y,int k){
    if(l==y&&r==y){
        v[i]=k;
        da[i]=k;
        return;
    }
    int mid=(l+r)>>1;
    if(y<=mid) gai(lson,l,mid,y,k);
    if(mid<y) gai(rson,mid+1,r,y,k);
    v[i]=v[lson]+v[rson];
    da[i]=max(da[lson],da[rson]);
}
signed main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    build(1,1,n);
    int op,x,y,z;
    while(m--){
        op=read();
        x=read(); y=read();
        if(op==1){
            printf("%lld\n",sum(1,1,n,x,y));
        }
        else if(op==2){
            z=read();
            mo(1,1,n,x,y,z);
        }
        else{
            a[x]=y;
            gai(1,1,n,x,y);
        }
    }
    return 0;
}