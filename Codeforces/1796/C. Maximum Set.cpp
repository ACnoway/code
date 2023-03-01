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
int L[1000006];
signed main()
{
    L[1]=0;
    for(int i=2;i<=1000000;++i){
        L[i]=L[i-1];
        if((i&(i-1))==0) L[i]++;
    }
    t=read();
    int ans,cnt;
    while(t--){
        l=read();
        r=read();
        for(ans=0;l*(1<<ans)<=r;++ans);
        ans--;
        cnt=(r-l*(1<<ans))/(1<<ans);
        cnt%=mod;
        if(r>=l*(1<<(ans-1))*3)
            cnt+=((r-l*(1<<(ans-1))*3)/(1<<(ans-1))/3)*ans;
        cnt%=mod;
        cout<<(ans+1)%mod<<' '<<cnt<<endl;
    }
    return 0;
}