#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
int n;
int a[N];
struct node{
    int l,r,v;
}f[N];
signed main()
{
    n=read();
    f[0]={0,0,0};
    for(int i=1;i<=n;++i){
        a[i]=read();
        f[i]={0,0,0};
    }
    for(int i=1;i<=n;++i){
        if(f[i-1].v+a[i]>a[i]){
            f[i].v=f[i-1].v+a[i];
            f[i].l=f[i-1].l;
            f[i].r=i;
        }
        else{
            f[i]={i,i,a[i]};
        }
    }
    int ans=0,l=0,r=0;
    for(int i=1;i<=n;++i){
        if(f[i].v>ans){
            ans=f[i].v;
            l=f[i].l;
            r=f[i].r;
        }
    }
    for(int i=0;i<=n;++i) f[i]={0,0,0};
    int aa=0;
    for(int i=1;i<l;++i){
        if(f[i-1].v+a[i]>a[i]){
            f[i].v=f[i-1].v+a[i];
            f[i].l=f[i-1].l;
            f[i].r=i;
        }
        else{
            f[i]={i,i,a[i]};
        }
        aa=max(aa,f[i].v);
    }
    for(int i=r+1;i<=n;++i){
        if(f[i-1].v+a[i]>a[i]){
            f[i].v=f[i-1].v+a[i];
            f[i].l=f[i-1].l;
            f[i].r=i;
        }
        else{
            f[i]={i,i,a[i]};
        }
        aa=max(aa,f[i].v);
    }
    printf("%lld\n",ans+aa);
    return 0;
}
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%