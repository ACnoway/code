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
ll a,b,p,ans;
int main()
{
    a=read();
    b=read();
    p=read();
    do{
        if(b&1) ans=(ans+a)%p;
        a=(a+a)%p;
    }while(b>>=1);
    return 0;
}