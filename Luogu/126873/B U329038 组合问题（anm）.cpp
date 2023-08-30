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
const int N=5e6+10,mod=998244353;
int T,n;
long long a[N];
int main()
{
    a[2]=1;
    for(int i=3;i<=5000000;++i){
        a[i]=(long long)(i-1ll)*(a[i-1]+a[i-2])%mod;
    }
    T=read();
    while(T--){
        n=read();
        printf("%lld\n",a[n]);
    }
    return 0;
}