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
int a[N],f[N];
signed main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read(),f[i]=f[i-1]+a[i];
    int l,r,ma=0,ans=0;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            if(f[j]-f[i-1]>ma){
                ma=f[j]-f[i-1];
                l=i; r=j;
            }
        }
    }
    ans+=ma;
    ma=0;
    for(int i=1;i<l;++i){
        for(int j=i;j<l;++j){
            if(f[j]-f[i-1]>ma){
                ma=f[j]-f[i-1];
            }
        }
    }
    for(int i=r+1;i<=n;++i){
        for(int j=i;j<=n;++j){
            if(f[j]-f[i-1]>ma){
                ma=f[j]-f[i-1];
            }
        }
    }
    ans+=ma;
    printf("%lld\n",ans);
    return 0;
}