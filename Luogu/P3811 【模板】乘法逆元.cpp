#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int inv[3000006];
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
signed main()
{
    int n,p,x,y;
    n=read();p=read();
    inv[1]=1;
    write(1);putchar('\n');
    for(int i=2;i<=n;++i){
        inv[i]=(p-(p/i))*inv[p%i]%p;
        write(inv[i]);putchar('\n');
    }
    return 0;
}