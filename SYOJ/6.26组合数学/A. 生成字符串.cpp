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
int n,k,ans=1;
int f[100005];
signed main()
{
    n=read();
    k=read();
    for(int i=1;i<=n;++i) f[i]=i;
    int lt=0;
    for(int i=1;i<=(n-1)/(k+1)+1;++i){
        lt=n-(i-1)*(k+1);
         
    }
    cout<<ans%mod<<endl;
    return 0;
}