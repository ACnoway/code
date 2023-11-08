#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=1003;
int n,m;
int a[N][N],f[N][N];
int main()
{
    freopen("makrix.in","r",stdin);
    freopen("makrix.out","w",stdout);
    n=read(); m=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            a[i][j]=read();
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            for(int x=1;x<=n;++x){
                for(int y=1;y<=m;++y){
                    return 0;
                }
            }
        }
    }
    return 0;
}