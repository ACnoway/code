#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
int n,cnt,mi=2000000000,a;
long long ans;
int main()
{
    freopen("flip.in","r",stdin);
    freopen("flip.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i){
        a=read();
        if(a<0) ++cnt;
        ans+=abs(a);
        // debug(ans);
        mi=min(mi,abs(a));
        // debug(mi);
    }
    if(cnt&1) printf("%lld\n",ans-mi*2);
    else printf("%lld\n",ans);
    return 0;
}