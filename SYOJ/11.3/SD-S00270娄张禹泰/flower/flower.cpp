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
const int N=200005;
int n,m;
int a[N];
signed main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    while(m--){
        int l=read(),r=read(),k=read(),ans=-1ll;
        for(int i=max(1ll,l);i<=min(n,r);++i){
            ans=max(ans,a[i]%k);
            if(ans==k-1) break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}