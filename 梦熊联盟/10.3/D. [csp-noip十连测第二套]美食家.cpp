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
const int N=100005;
int n,m,x,cnt;
int a[N],w[N];
int main()
{
    freopen("foodie.in","r",stdin);
    freopen("foodie.out","w",stdout);
    n=read();m=read();x=read();
    for(int i=1;i<=n;++i) w[i]=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(w[j]+a[j]*cnt<=x){
                ++cnt;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}