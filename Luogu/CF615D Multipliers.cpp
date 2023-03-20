#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
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
const int mod=1e9+7;
int n,tmp,ma,ans=1,d=1;
int a[200005];
vector<pair<int,int> > b;
int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans*=a,ans%=mod;
        a*=a,a%=mod;
        b>>=1ll;
    }
    return ans;
}
signed main()
{
    n=read();
    for(int i=1;i<=n;++i) tmp=read(),ma=max(ma,tmp),a[tmp]++;
    for(int i=1;i<=ma;++i){
        d=d*(a[i]+1ll)%(mod-1ll);
        if(a[i]) b.push_back({a[i],i});
    }
    bool flag=1;
    for(auto i:b){
        if(i.first&1ll){
            flag=0;
            break;
        }
    }
    if(flag){
        for(auto &i:b) i.first>>=1ll;
        for(auto i:b) ans=ans*power(i.second,d*i.first%(mod-1ll))%mod;
    }
    else{
        d=1;
        flag=1;
        for(auto i:b){
            if((i.first&1ll)&&flag){
                flag=0;
                d=d*(i.first+1ll)/2ll%(mod-1ll);
            }
            else d=d*(i.first+1ll)%(mod-1ll);
        }
        for(auto i:b) ans=ans*power(i.second,d*i.first%(mod-1ll))%mod;
    }
    printf("%lld\n",ans);
    return 0;
}