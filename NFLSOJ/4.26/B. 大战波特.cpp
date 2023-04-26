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
int n,x,r,p,k,rc,pc;
string s;
signed main()
{
    freopen("bot.in","r",stdin);
    freopen("bot.out","w",stdout);
    cin>>n>>x>>r>>p>>k>>s;
    if(r==0){
        int ans=0;
        for(int i=0;i<n;++i){
            if(pc<k) ++pc;
            ans+=x+pc*p;
        }
        cout<<ans<<endl;
    }
    else if(p==0){
        int ans=0;
        for(int i=0;i<n;++i){
            if(s[i]=='1'){
                ++rc;
                if(pc<k) ++pc,--rc;
            }
            ans+=x+pc*p-rc*r;
        }
        cout<<ans<<endl;
    }
    return 0;
}