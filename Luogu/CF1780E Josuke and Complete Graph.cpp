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
int t,l,r,ans,n;
signed main()
{
    t=read();
    while(t--){
        l=read();
        r=read();
        ans=0;
        n=l-1;
        for(int L=1,R;L<=n;L=R+1){
            R=n/(n/L);
            ans+=max(0ll,min(R,r/(n/L+2))-L+1);
        }
        cout<<ans+max(0ll,r/2-n)<<endl;
    }
    return 0;
}