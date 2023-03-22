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
int n,k,q,c;
int a[100005],f[100005];
signed main()
{
    n=read();
    k=read();
    q=read();
    for(int i=1;i<=n;++i) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) f[i]=f[i-1]+a[i];
    while(q--){
        c=read();
        printf("%lld\n",f[c]);
    }
    return 0;
}