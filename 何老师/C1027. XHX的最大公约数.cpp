#include<iostream>
#include<cmath>
#include<cstring>
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
const int mod=1000000007;
int n,m,l,r,ans;
int f[1000006];
inline int power(int a,int b){
    int sum=1;
    while(b){
        if(b&1) sum*=a,sum%=mod;
        a*=a;
        a%=mod;
        b>>=1;
    }
    return sum%mod;
}
signed main()
{
    n=read();m=read();
    l=read();r=read();
    for(int i=m;i;--i){
        f[i]=power(m/i,n);
        for(int j=i+i;j<=m;j+=i){
            f[i]=(f[i]-f[j]+mod)%mod;
        }
        if(l<=i&&i<=r) ans=(ans+f[i])%mod;
    }
    write(ans%mod);
    putchar('\n');
    return 0;
}