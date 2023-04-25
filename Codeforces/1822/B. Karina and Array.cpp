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
int T,n,x,zd,cd,zx,cx;
signed main()
{
    T=read();
    while(T--){
        zd=cd=-1e9-10;
        zx=cx=1e9+10;
        n=read();
        for(int i=1;i<=n;++i){
            x=read();
            if(x>zd){
                cd=zd;
                zd=x;
            }
            else if(x>cd) cd=x;
            if(x<zx){
                cx=zx;
                zx=x;
            }
            else if(x<cx) cx=x;
        }
        cout<<max(zd*cd,zx*cx)<<endl;
    }
    return 0;
}