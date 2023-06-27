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
const int mod=5000011;
int n,m,k,ans=0;
int f[100005];
signed main()
{
    n=read();
    m=read();
    k=1;
    for(int i=1;i<=n;++i) f[i]=i;
    int lt=0;
    for(int i=m;i<=m;++i){
        lt=n-(i-1)*(k+1);
        ans+=f[lt];
        for(int j=1;j<=lt;++j) f[j]+=f[j-1];
    }
    cout<<ans<<endl;
    return 0;
}