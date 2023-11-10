#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
int T,n;
int a[N];
bool vis[N];
int main()
{
    // freopen("num.in","r",stdin);
    // freopen("num.out","w",stdout);
    T=read();
    while(T--){
        n=read();
        int d=0,ma=0;
        for(int i=1;i<=n;++i){
            a[i]=read();
            if(i==1) d=a[i];
            else d=__gcd(d,a[i]);
            ma=max(ma,a[i]);
        }
        printf("%d\n",ma/d);
    }
    return 0;
}