#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int read(){
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
void write(ll x){
    
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
ll max(ll a,ll b){
    return (a<b?b:a);
}
int a[1003][1003];
ll f[1003],u[1003],d[1003];
int n,m;
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) a[i][j]=read();
    }
    f[1]=a[1][1];
    for(int i=2;i<=n;++i) f[i]=f[i-1]+a[i][1];
    for(int j=2;j<m;++j){
        for(int i=0;i<=1002;++i) u[i]=0,d[i]=0;
        d[1]=f[1]+a[1][j];u[n]=f[n]+a[n][j];
        for(int i=2;i<=n;++i) d[i]=max(f[i],d[i-1])+a[i][j];
        for(int i=n-1;i>=1;--i) u[i]=max(f[i],u[i+1])+a[i][j];
        for(int i=1;i<=n;++i) f[i]=max(d[i],u[i]);
    }
    f[1]+=a[1][m];
    for(int i=2;i<=n;++i) f[i]=max(f[i],f[i-1])+a[i][m];
    write(f[n]);
    return 0;
}