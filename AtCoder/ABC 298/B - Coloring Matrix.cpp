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
const int N=102;
int n;
int a[N][N],b[N][N],c[N][N];
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) a[i][j]=read();
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) b[i][j]=read();
    }
    for(int cs=1;cs<=4;++cs){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                c[i][j]=a[n+1-j][i];
            }
        }
        cout<<endl;
        bool flag=1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                a[i][j]=c[i][j];
                if(c[i][j]==1&&b[i][j]==0){
                    flag=0;
                }
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}