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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=200005,mod=998244353;
int n;
int a[maxn][2];
int f[maxn][2];
signed main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i][0]=read();
        a[i][1]=read();
    }
    f[1][0]=1;
    f[1][1]=1;
    for(int i=2;i<=n;++i){
        if(a[i][0]!=a[i-1][0]) f[i][0]+=f[i-1][0];
        if(a[i][0]!=a[i-1][1]) f[i][0]+=f[i-1][1];
        f[i][0]%=mod;
        if(a[i][1]!=a[i-1][0]) f[i][1]+=f[i-1][0];
        if(a[i][1]!=a[i-1][1]) f[i][1]+=f[i-1][1];
        f[i][1]%=mod;
    }
    write((f[n][0]+f[n][1])%mod);
    return 0;
}