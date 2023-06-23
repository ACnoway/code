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
const int mod=998244353;
int L,R,l=1,r=1,ans=1,sum,ok;
signed main()
{
    L=read();
    R=read();
    while(l*l<L) ++l;
    while(r*r<=R) ++r;
    --r;
    // if(l>r){
    //     cout<<0<<endl;
    //     return 0;
    // }
    int x;
    bool flag=1;
    for(int i=l;i<=r;++i){
        x=i*i;
        sum=0;
        while(x){
            sum+=x%10;
            x/=10;
        }
        if(sum==1) continue;
        flag=1;
        for(int j=2;j*j<=sum;++j){
            if(sum%j==0){
                flag=0;
                break;
            }
        }
        if(flag) ans=(ans%mod*i%mod*i%mod)%mod,ok=1;
    }
    if(ok) cout<<ans<<endl;
    else cout<<0<<endl;
    return 0;
}