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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n,m;
int a[3];
signed main()
{
    freopen("fib.in","r",stdin);
    freopen("fib.out","w",stdout);
    a[0]=read(); a[1]=read();
    m=read(); n=read();
    for(int i=2;i<=n;++i){
        int tmp=sqrt((int)(3+a[1]*a[0]));
        a[2]=a[1]+a[0]+tmp+tmp;
    }
    printf("%lld\n",a[2]);
    return 0;
}