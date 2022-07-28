#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
#define lc i<<1
#define rc i<<1|1
using namespace std;
int read(){
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
ll readl(){
    ll x=0,f=1;
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
void write(ll x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
struct node
{
    int l,r,flag;
    ll sum;
}t[1000005];
ll a[100005];
int n,m;
void order(int i){
	if(i>n) return;
	order(lc);
	if(t[i].l==t[i].r) cout<<t[i].sum<<' ';
	order(rc);
}
inline void build(int i,int l,int r){
    t[i].l=l;t[i].r=r;
    if(l==r){
        t[i].sum=a[l];
        if(a[l]==1||a[l]==0) t[i].flag=1;
        else t[i].flag=0;
        return;
    }
    int mid=(l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    t[i].sum=t[lc].sum+t[rc].sum;
    t[i].flag=t[lc].flag&t[rc].flag;
    return;
}
inline void change(int i,int l,int r){
    if(l<=t[i].l&&t[i].r<=r&&t[i].l==t[i].r&&!t[i].flag){
        t[i].sum=(ll)sqrt(t[i].sum);
        if(t[i].sum==1||t[i].sum==0) t[i].flag=1;
        return;
    }
    if(t[lc].r>=l&&t[lc].flag==0) change(lc,l,r);
    if(t[rc].l<=r&&t[rc].flag==0) change(rc,l,r);
    t[i].sum=t[lc].sum+t[rc].sum;
    t[i].flag=t[lc].flag&t[rc].flag;
    return;
}
inline ll search(int i,int l,int r){
    if(t[i].l>r||t[i].r<l) return 0;
    if(t[i].l>=l&&t[i].r<=r) return t[i].sum;
    ll s=0;
    if(t[lc].r>=l) s+=search(lc,l,r);
    if(t[rc].l<=r) s+=search(rc,l,r);
    return s;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=readl();
    build(1,1,n);
    m=read();
    for(int i=0;i<m;++i){
        int op=read(),l=read(),r=read();
        if(l>r) swap(l,r);
        if(op==0){
            change(1,l,r);
        }
        else{
            write(search(1,l,r));
            putchar('\n');
        }
    }
    return 0;
}