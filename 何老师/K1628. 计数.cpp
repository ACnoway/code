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
const int N=1e7+10,mod=1e9+7;
int n,m,ans,tmp;
int a[20],jc[N];
signed main()
{
    n=read();
    m=read();
    jc[0]=1;
    for(int i=1;i<=n;++i) jc[i]=(jc[i-1]*i)%mod;
    for(int i=1;i<=m;++i){
        
    }
    return 0;
}