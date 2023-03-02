#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=3003,mod=1000000007;
int n,m,k;
char s[maxn][maxn];
int a[maxn][maxn],f[maxn][maxn],sumf[maxn][maxn],g[maxn][maxn],sumg[maxn][maxn];
signed main()
{
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=n;++i){
        cin>>s[i]+1;
        for(int j=1;j<=m;++j) a[i][j]=s[i][j]-'0';
    }
    //初始化动规数组和前缀和数组
    for(int i=1;i<=m;++i){
        f[1][i]=1;
        sumf[1][i]=i;
    }
    for(int i=2;i<=m;++i){
        if(a[1][i]==a[1][i-1]) g[1][i]=1;
        sumg[1][i]=sumg[1][i-1]+g[1][i];
    }
    
    for(int i=2;i<=n;++i){
        for(int j=1;j<=m;++j){
            f[i][j]=((sumf[i-1][min(j+k,m)]-sumf[i-1][max(j-k-1,0ll)])-(sumg[i-1][min(j+k,m)]-sumg[i-1][max(j-k,0ll)])%mod+mod)%mod;
            sumf[i][j]=(sumf[i][j-1]+f[i][j])%mod;
            if(j>1&&a[i][j]==a[i][j-1]){
                g[i][j]=((sumf[i-1][min(j+k-1,m)]-sumf[i-1][max(j-k-1,0ll)])-(sumg[i-1][min(j+k-1,m)]-sumg[i-1][max(j-k,0ll)])%mod+mod)%mod;
            }
            sumg[i][j]=(sumg[i][j-1]+g[i][j])%mod;
        }
    }
    write((sumf[n][m]-sumg[n][m]+mod)%mod);
    putchar('\n');
    return 0;
}