#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
const int mod=1e9+7;
int n,m;
int a[2003],b[2003];
int f[2003][2003];
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
int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=m;++i) b[i]=read();
    for(int i=0;i<=n;++i) f[i][0]=1;
    for(int i=0;i<=m;++i) f[0][i]=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
            if(a[i]==b[j]) f[i][j]+=f[i-1][j-1];
            f[i][j]%=mod;
        }
    }
    write(f[n][m]%mod);
    putchar('\n');
    return 0;
}