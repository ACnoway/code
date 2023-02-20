#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#define lson x<<1
#define rson x<<1|1
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
const int maxn=100005;
int n,m;
int a[maxn];
struct node{
    double sum,psum,lt;
    int l,r;
}t[maxn<<2];
void pushdown(int x){
    if(t[x].lt){
        t[lson].lt+=t[x].lt;
        t[rson].lt+=t[x].lt;
        int mid=(t[x].l+t[x].r)>>1;
        t[lson].psum+=2*t[lson].sum*t[x].lt+(mid-t[x].l+1)*t[x].lt*t[x].lt;
        t[lson].sum+=(mid-t[x].l+1)*t[x].lt;
        t[rson].psum+=2*t[rson].sum*t[x].lt+(t[x].r-mid)*t[x].lt*t[x].lt;
        t[rson].sum+=(t[x].r-mid)*t[x].lt;
        t[x].lt=0;
    }
}
void build(int x,int l,int r){
    t[x].l=l;t[x].r=r;
    t[x].sum=t[x].psum=0;
    if(l==r){
        scanf("%lf",&t[x].sum);
        t[x].psum=t[x].sum*t[x].sum;
        return;
    }
    int mid=(l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    t[x].sum=t[lson].sum+t[rson].sum;
    t[x].psum=t[lson].psum+t[rson].psum;
}
void add(int x,int l,int r,double k){
    if(t[x].r<l||t[x].l>r) return;
    if(l<=t[x].l&&t[x].r<=r){
        t[x].lt+=k;
        t[x].psum+=2*t[x].sum*k+(t[x].r-t[x].l+1)*k*k;
        t[x].sum+=(t[x].r-t[x].l+1)*k;
        return;
    }
    pushdown(x);
    if(t[lson].r>=l) add(lson,l,r,k);
    if(t[rson].l<=r) add(rson,l,r,k);
    t[x].sum=t[lson].sum+t[rson].sum;
    t[x].psum=t[lson].psum+t[rson].psum;
}
double query1(int x,int l,int r){
    if(t[x].r<l||t[x].l>r) return 0;
    if(l<=t[x].l&&t[x].r<=r) return t[x].sum;
    pushdown(x);
    int mid=(l+r)>>1;
    double s=0;
    if(t[lson].r>=l) s+=query1(lson,l,r);
    if(t[rson].l<=r) s+=query1(rson,l,r);
    return s;
}
double query2(int x,int l,int r){
    if(t[x].r<l||t[x].l>r) return 0;
    if(l<=t[x].l&&t[x].r<=r) return t[x].psum;
    pushdown(x);
    int mid=(l+r)>>1;
    double s=0;
    if(t[lson].r>=l) s+=query1(lson,l,r);
    if(t[rson].l<=r) s+=query1(rson,l,r);
    return s;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    build(1,1,n);
    int op,x,y;
    double k;
    while(m--){
        scanf("%lld%lld%lld",&op,&x,&y);
        if(op==1){
            scanf("%lf",&k);
            add(1,(int)x,(int)y,k);
        }
        else if(op==2){
            double ans=query1(1,x,y)/(double)(y-x+1);
            printf("%.4lf\n",ans);
        }
        else{
            double nn=y-x+1,aver=query1(1,x,y)/nn;
            double fang=query2(1,x,y)/nn,zhong=query1(1,x,y)*2.0*aver/nn;
            printf("%.4lf\n",fang-zhong+aver*aver);
        }
    }
    return 0;
}