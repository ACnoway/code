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
const int N=1000006,mod=1000000007;
int T,n,m;
int f[N],jc[N];
string a,b,c,tmp;
signed main()
{
    freopen("zood.in","r",stdin);
    freopen("zood.out","w",stdout);
    T=read();
    jc[1]=1;
    for(int i=2;i<N;++i) jc[i]=(jc[i-1]*i)%mod;
    f[1]=1;
    for(int i=2;i<N;++i) f[i]=(((i*f[i-1])%mod+jc[i])%mod-i+mod)%mod;
    while(T--){
        n=read(); m=read();
        if(n==m) printf("%lld\n",f[n]);
        else printf("%lld\n",(f[m]+(jc[m]*((jc[n-m]*n)%mod-m+mod)%mod)%mod)%mod);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}