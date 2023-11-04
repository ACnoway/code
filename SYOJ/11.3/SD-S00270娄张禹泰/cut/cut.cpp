#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
int a[N];
bool check(int x){
    long long res=0;
    for(int i=1;i<=n;++i) res+=max(0ll,a[i]-x);
    return res>=m;
}
signed main()
{
    freopen("cut.in","r",stdin);
    freopen("cut.out","w",stdout);
    n=read();
    m=read();
    int l=1,r=0,mid,ans=1;
    for(int i=1;i<=n;++i){
        a[i]=read();
        r=max(r,a[i]);
    }
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}