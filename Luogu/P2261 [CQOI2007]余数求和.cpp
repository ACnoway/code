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
int n,k,ans,r;
signed main()
{
    n=read();k=read();
    ans=n*k;
    for(int i=1;i<=min(n,k);++i){
        if(!(k/i)) break;
        r=min(min(n,k),k/(k/i));
        ans-=(k/i)*(i+r)*(r-i+1)>>1;
        i=r;
    }
    write(ans);
    return 0;
}