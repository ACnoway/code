#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define int __int128_t
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
const int maxn=90;
int n,m,ans;
int a[maxn],mi[maxn],f[maxn][maxn];
signed main()
{
    n=read();m=read();
    mi[0]=1;
    for(int i=1;i<=m+2;++i) mi[i]=mi[i-1]<<1;
    while(n--){
        memset(f,0,sizeof(f));
        for(int i=1;i<=m;++i) a[i]=read();
        for(int i=1;i<=m;++i){
            for(int j=m;j>=i;--j){
                f[i][j]=max(f[i][j],f[i-1][j]+mi[m-j+i-1]*a[i-1]);
                f[i][j]=max(f[i][j],f[i][j+1]+mi[m-j+i-1]*a[j+1]);
            }
        }
        int ma=0;
        for(int i=1;i<=m;++i) ma=max(ma,f[i][i]+mi[m]*a[i]);
        ans+=ma;
    }
    write(ans);
    return 0;
}