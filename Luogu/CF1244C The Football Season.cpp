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
int n,p,d,w;
signed main()
{
    n=read();
    p=read();
    w=read();
    d=read();
    int x,y=0;
    while(y<w&&(p-1ll*d*y)%w) ++y;
    if(y==w){
        cout<<"-1"<<endl;
        return 0;
    }
    x=(p-1ll*d*y)/w;
    if(x<0||x+y>n){
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<x<<' '<<y<<' '<<n-x-y<<endl;
    return 0;
}