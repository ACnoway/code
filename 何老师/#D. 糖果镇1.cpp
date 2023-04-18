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
const int N=100005;
int n,m,p,sum;
int a[5][N],f[5][N];
signed main()
{
    m=read(); n=read();
    p=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) a[i][j]=read(),sum+=a[i][j];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            f[i][j]=max((f[i-1][j]+a[i][j])%p,(f[i][j-1]+a[i][j])%p);
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
    return 0;
}