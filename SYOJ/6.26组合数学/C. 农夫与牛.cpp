#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int __int128_t
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
signed main()
{
    n=read(); m=read();
    if(m>n+2){
        cout<<0<<endl;
        return 0;
    }
    int c=1;
    for(int i=n+1;i>=n;--i) c*=i;
    for(int i=n+3;i>max(m,n+3-m);--i) c*=i;
    for(int i=2;i<=min(m,n+3-m);++i) c/=i;
    int d=1;
    for(int i=n+1;i>max(m,n+1-m);--i) d*=i;
    for(int i=2;i<=min(m,n+1-m);++i) d/=i;
    for(int i=n+m+1;i>=n+m;--i) d*=i;
    // int e=1;
    // for(int i=n+1;i>=n;--i) e*=i;
    // for(int i=n-1;i>max(m,n-1-m);--i) e*=i;
    // for(int i=2;i<=min(m,n-1-m);++i) e/=i;
    write(max(c,d));
    putchar('\n');
    return 0;
}