#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
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
int t,n,ans;
int a[30],b[30];
signed main()
{
    t=read();
    while(t--){
        n=read();
        ans=0;
        for(int i=1;i<=n;++i) a[i]=read();
        for(int i=1;i<=n;++i) b[i]=read();
        for(int i=2;i<=n;++i){
            ans+=min(abs(a[i]-a[i-1])+abs(b[i]-b[i-1]),abs(a[i]-b[i-1])+abs(b[i]-a[i-1]));
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}