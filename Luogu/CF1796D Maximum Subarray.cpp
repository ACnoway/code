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
int t,n,k,x;
int a[200005];
int f[200005][21];
signed main()
{
    t=read();
    while(t--){
        n=read();
        k=read();
        x=read();
        int ans=INT_MIN;
        for(int i=1;i<=n;++i){
            a[i]=read();
        }
        for(int i=0;i<=n;++i){
            for(int j=0;j<=k;++j) f[i][j]=INT_MIN;
        }
        for(int i=1;i<=n;++i){
            for(int j=0;j<=min(k,i);++j){
                if(i-1>=j) f[i][j]=max(f[i-1][j]+a[i]-x,a[i]-x);
                if(j>0){
                    f[i][j]=max(f[i][j],max(f[i-1][j-1]+a[i]+x,a[i]+x));
                }
                if(n-i>=k-j) ans=max(ans,f[i][j]);
            }
        }
        printf("%lld\n",max(ans,0ll));
    }
    return 0;
}