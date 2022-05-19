#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
inline ll read(){
    ll x=0,f=1;
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
inline void write(ll x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
ll a,b,p;
ll mul(ll a,ll b,ll p){
    a%=p;
    b%=p;
    ll c=(long double)a*b/p;
    unsigned ll x=a*b,y=c*p;
    ll ans=(ll)(x%p)-(ll)(y%p);
    if(ans<0) ans+=p;
    return ans;
}
int main()
{
    a=read();
    b=read();
    p=read();
    write(mul(a,b,p));
    return 0;
}