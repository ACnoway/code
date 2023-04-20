#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=1000006;
int n,k;
int a[N];
int main()
{
    n=read(); k=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j) ans=max(ans,__gcd(a[i],a[j]));
    }
    cout<<ans<<endl;
    return 0;
}