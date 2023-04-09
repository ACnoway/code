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
int t,n;
int a[2][100005];
int main()
{
    t=read();
    while(t--){
        n=read();
        a[0][1]=n*2;
        a[1][n]=n*2-1;
        for(int i=1;i<=n;++i){
            a[i&1][i]=i;
        }
        for(int j=n+2;j<=n*2-1;++j){
            a[!(j&1)][j-n]=j-1;
        }
        for(int i=1;i<=n;++i) printf("%d ",a[0][i]);
        putchar('\n');
        for(int i=1;i<=n;++i) printf("%d ",a[1][i]);
        putchar('\n');
    }
    return 0;
}