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
int n,ans,now;
int a[200005];
signed main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    for(int i=n;i;--i){
        now+=a[i];
        if(now>=0){
            now=0;
            ans++;
        }
    }
    write((ans?ans:-1));
    putchar('\n');
    return 0;
}