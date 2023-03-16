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
int t,n,m,now;
int a[202][202];
signed main()
{
    t=read();
    while(t--){
        n=read(); m=read();
        cout<<n*m<<endl;
        a[1][1]=0;
        now=0;
        for(int i=1;i<=n;i+=2){
            if(i>=3) now=a[i-2][1]+1024;
            for(int j=1;j<m;j+=2){
                a[i][j]=now++;
                a[i][j+1]=now++;
                a[i+1][j]=now++;
                a[i+1][j+1]=now++;
            }
            if(m&1){
                a[i][m]=now++;
                a[i+1][m]=now+1;
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                printf("%d%c",a[i][j]," \n"[j==m]);
            }
        }
    }
    return 0;
}