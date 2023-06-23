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
int a,b,c,d,e,f,k;
signed main()
{
    a=read(); b=read(); c=read();
    d=read(); e=read(); f=read();
    k=read();
    cout<<max(k/b*a*c,k/e*d*f)<<endl;
    return 0;
}