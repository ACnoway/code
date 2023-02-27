#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=100005,mod=1000000007;
int n;
struct node{
    int a,b;
    int er,san;
    int id;
}a[maxn];
bool cmp1(node x,node y){
    return x.b<y.b;
}
bool cmp2(node x,node y){
    return x.a<y.a;
}
inline int ksm(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans*=a,ans%=mod;
        a*=a;
        a%=mod;
        b>>=1;
    }
    return ans;
}

struct segt{
    int l,r,sum,tot,lt;
}t[maxn<<2];
void pushdown(int x){
    if(t[x].lt>1){
        t[x<<1].sum=t[x<<1].sum*t[x].lt%mod;
        t[x<<1|1].sum=t[x<<1|1].sum*t[x].lt%mod;
        t[x<<1].lt=t[x<<1].lt*t[x].lt%mod;
        t[x<<1|1].lt=t[x<<1|1].lt*t[x].lt%mod;
        t[x].lt=1;
    }
}
void build(int x,int l,int r){
    t[x].l=l;
    t[x].r=r;
    t[x].sum=0;
    t[x].tot=0;
    t[x].lt=1;
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
}
int searchtot(int x,int l,int r){
    if(l<=t[x].l==t[x].r<=r){
        return t[x].tot;
    }
    pushdown(x);
    int s=0;
    if(t[x<<1].r>=l) s+=searchtot(x<<1,l,r);
    if(t[x<<1|1].l<=r) s+=searchtot(x<<1|1,l,r);
    return s;
}
void addtot(int x,int p){
    if(t[x].l==t[x].r){
        t[x].tot=1;
        return;
    }
    pushdown(x);
    if(t[x<<1].r>=p) addtot(x<<1,p)
    else addtot(x<<1|1,p);
    t[x].tot=t[x<<1].tot+t[x<<1|1].tot;
}
int searchsum(int x,int l,int r){
    if(l<=t[x].l&&t[x].r<=r){
        return t[x].sum;
    }
    pushdown(x);
    int s=0;
    if(t[x<<1].r>=l) s+=searchsum(x<<1,l,r);
    if(t[x<<1|1].l<=r) s+=searchsum(x<<1|1,l,r);
    return s;
}
void addsum(int x,int p,int k){
    if(t[x].l==t[x].r){
        t[x].sum=k;
        return;
    }
    pushdown(x);
    if(t[x<<1].r>=p) addsum(x<<1,p,k);
    else addsum(x<<1|1,p,k);
    t[x].sum=(t[x<<1].sum+t[x<<1|1].sum)%mod;
}
void cheng(int x,int l,int r){
    if(l>r) return;
    if(l<=t[x].l&&t[x].r<=r){
        t[x].sum=(t[x].sum<<1)%mod;
        t[x].lt=(t[x].lt<<1)%mod;
        return;
    }
    pushdown(x);
    if(t[x<<1].r>=l) cheng(x<<1,l,r);
    if(t[x<<1|1].l<=r) cheng(x<<1|1,l,r);
    t[x].sum=(t[x<<1].sum+t[x<<1|1].sum)%mod;
}
signed main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i].a=read();
        a[i].b=read();
        a[i].er=ksm(2,a[i].a);
        a[i].san=ksm(3,a[i].b);
    }
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;++i){
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp2);
    build(1,1,n);
    int cnt,ans=0;
    for(int i=1;i<=n;++i){
        cnt=searchtot(1,1,r[i].id);
        addsum(1,r[i].id,ksm(2,cnt)*a[i].san%mod);
        ans=(ans+searchsum(1,r[i].id,n)*r[i].er%mod)%mod;
        cheng(1,r[i].id+1,n);
        addtot(1,r[i].id);
    }
    write(ans);
    return 0;
}