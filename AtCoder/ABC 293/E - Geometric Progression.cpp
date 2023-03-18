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
int a,x,m;
int power(int a,int x){
    int ans=1;
    while(x){
        if(x&1) ans*=a,ans%=m;
        a*=a,a%=m;
        x>>=1;
    }
    return ans;
}
signed main()
{
    a=read();
    x=read();
    m=read();
    int Len=sqrt(x),num=x/Len,sum=0;
    for(int i=0;i<Len;++i) sum+=power(a,i),sum%=m;
    int l,r,ans=0;
    for(int i=1;i<=num;++i){
        l=(i-1)*Len;
        r=i*Len-1;
        ans+=power(a,l)*sum;
        ans%=m;
    }
    if(x%Len){
        for(int i=r+1;i<x;++i){
            ans+=power(a,i);
            ans%=m;
        }
    }
    printf("%lld\n",ans);
    return 0;
}