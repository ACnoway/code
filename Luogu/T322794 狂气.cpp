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
int n,m,teshu;
int a[200005],op[200005];
int main()
{
    n=read();
    getchar();
    for(int i=1;i<=n;++i){
        op[i]=getchar()-'0';
        if(op[i]==1) ++teshu;
        else --teshu;
    }
    if(!teshu){
        long long ans=2;
        for(int i=2;i<=n;++i){
            ans=(ans*i)%998244353;
        }
        printf("%lld\n",ans);
    }
    return 0;
}