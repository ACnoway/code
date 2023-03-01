#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int mod=998244353;
int t,l,r;
signed main()
{
    t=read();
    int ans,cnt;
    while(t--){
        l=read();
        r=read();
        for(ans=0;l*(1ll<<ans)<=r;++ans);
        ans--;
        cnt=(r-l*(1ll<<ans))/(1ll<<ans)+1;
        cnt%=mod;
        if(r>=l*(1ll<<(ans-1ll))*3ll)
            cnt+=(1+(r-l*3ll*(1ll<<(ans-1ll)))/(1ll<<(ans-1ll))/3ll)*ans;
        cnt%=mod;
        cout<<(ans+1ll)%mod<<' '<<cnt<<endl;
    }
    return 0;
}