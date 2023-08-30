#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<climits>
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
const int N=60,inf=INT_MAX>>1;
int n,m;
int a[N][N];
bool f[N][N][65];
int main()
{
    n=read();
    m=read();
    //初始化以及读入边
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) a[i][j]=inf;
    for(int i=0;i<m;++i){
        int u=read(),v=read();
        a[u][v]=1;
        //u到v有长度为1的路径
        f[u][v][0]=1;
    }
    //枚举k的大小以及三个点
    //起点、中间点、终点
    //k不用太大64就够了
    for(int k=1;k<64;++k)
        for(int i=1;i<=n;++i)
            for(int o=1;o<=n;++o)
                for(int j=1;j<=n;++j)
                    if(f[i][o][k-1]&&f[o][j][k-1]){
                        //如果两边都存在长度为2^k-1的
                        //路径那么就存在长度为2^k的路径
                        f[i][j][k]=1;
                        a[i][j]=1;
                    }
    //直接跑floyd
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    printf("%d\n",a[1][n]);
    return 0;
}