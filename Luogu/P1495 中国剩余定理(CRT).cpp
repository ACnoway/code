#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll read(){
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
void write(ll x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
//扩欧求逆元
void exgcd(ll &x,ll &y,ll a,ll b){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(x,y,b,a%b);
    int z=x;
    x=y;
    y=z-y*(a/b);
}
ll n;
ll m=1,x,mi,mp;
ll a[15][2];
/*
x===b1(mod m1)
x===b2(mod m2)
x===b3(mod m3)
...
x===bn(mod mn)
M=m1m2m3...mn
M1=M/m1
M2=M/m2
...
Mn=M/Mn
M'1M1===1(mod m1)
...
M'iMi===1(mod mi)
M'i是Mi在模mi意义下的逆元
x=b1M'1M1+b2M'2M2+b3M'3M3+...+bnM'nMn
*/
int main()
{
    n=read();
    for(int i=1;i<=n;++i){
        a[i][1]=read();
        a[i][0]=read();
        m*=a[i][1];
    }
    for(int i=1;i<=n;++i){
        mi=m/a[i][1];
        ll xx=0,y=0;
        exgcd(xx,y,mi,a[i][1]);
        x+=a[i][0]*mi*(xx<0?xx+a[i][1]:xx);
    }
    write(x%m);
    return 0;
}