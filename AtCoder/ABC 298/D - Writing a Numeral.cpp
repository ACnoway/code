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
const int mod=998244353;
int q,ans=1,len=1,t;
vector<int> a;
int ksm(int a,int b){
    int res=1;
    while(b){
        if(b&1) res*=a,res%=mod;
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}
signed main()
{
    q=read();
    a.emplace_back(1);
    while(q--){
        int op=read();
        if(op==1){
            int x=read();
            a.emplace_back(x);
            ans=ans*10%mod+x;
            ans%=mod;
            ++len;
        }
        else if(op==2){
            --len;
            int to=ksm(10,len),x=a[t];
            ++t;
            to=to*x%mod;
            ans-=to;
            ans=(ans+mod)%mod;
        }
        else{
            cout<<ans%mod<<endl;
        }
    }
    return 0;
}