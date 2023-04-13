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
const int N=5e5+10;
int n,m,l,r,s,e,ans;
int a[N],f[N];
signed main()
{
    n=read(); m=read();
    if(n<=1000){
        while(m--){
            l=read(); r=read();
            s=read(); e=read();
            int d=(e-s)/(r-l);
            for(int i=l;i<=r;++i){
                a[i]+=(i-l)*d+s;
            }
        }
        for(int i=1;i<=n;++i) ans^=a[i];
        printf("%lld\n",ans);
        return 0;
    }
    while(m--){
        l=read(); r=read();
        s=read(); e=read();
        if(s==e) a[l]+=s,a[r+1]-=s;
    }
    for(int i=1;i<=n;++i){
        a[i]+=a[i-1];
        ans^=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}