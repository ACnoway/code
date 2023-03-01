#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=500005,mod=1000000007;
int d,d1,n,f;
int a[maxn],num[maxn],tot[2];
int t[maxn][2],g[maxn][2];
char s[maxn];
signed main()
{
    cin>>s+1>>d;
    n=strlen(s+1);
    d1=1;
    while(d%2==0){
        d>>=1;
        d1<<=1;
    }
    while(d%5==0){
        d/=5;
        d1*=5;
    }
    for(int i=1;i<=n;++i){
        //转成数字串
        num[i]=s[i]-'0';
        //前缀数对d取模的余数
        a[i]=(a[i-1]*10+s[i]-'0')%d;
    }
    f=1;
    for(int i=n;i;--i){
        a[i]=a[i]*f%d;
        f=f*10%d;
    }
    tot[1]=1;
    t[0][1]=1;
    g[0][1]=1;
    int tmp,k,x,y;
    for(int i=1;i<=n;++i){
        tmp=0;
        k=1;
        //暴力枚举后20位找余数
        for(int j=i;j>=i-20&&j;--j){
            tmp=(tmp+num[j]*k%d1)%d1;
            k=k*10%d1;
        }
        x=0;
        y=0;
        //一个找整除的一个找不整除的
        if(!tmp){
            //如果能被d1整除
            tmp=0;
            k=1;
            //一个整除的方案数一个不整除的方案数
            x=t[a[i]][1];
            y=t[a[i]][0];
            for(int j=i;j>=i-20&&j;--j){
                tmp=(tmp+num[j]*k%d1)%d1;
                if(tmp&&a[i]==a[j-1]){
                    x=((x-g[j-1][1])%mod+mod)%mod;
                    y=((y-g[j-1][0])%mod+mod)%mod;
                }
                k=k*10%d1;
            }
        }
        else{
            tmp=0;
            k=1;
            for(int j=i;j>=i-20&&j;--j){
                tmp=(tmp+num[j]*k%d1)%d1;
                if(tmp==0&&a[i]==a[j-1]){
                    x=(x+g[j-1][1])%mod;
                    y=(y+g[j-1][0])%mod;
                }
                k=k*10%d1;
            }
        }
        //因为是至少一个被整除，所以整除和不整除的方案数都要考虑
        g[i][0]=((tot[1]-x)%mod+mod)%mod;
        g[i][1]=(x+y)%mod;
        tot[0]=(tot[0]+g[i][0])%mod;
        tot[1]=(tot[1]+g[i][1])%mod;
        t[a[i]][0]=(t[a[i]][0]+g[i][0])%mod;
        t[a[i]][1]=(t[a[i]][1]+g[i][1])%mod;
    }
    cout<<(g[n][0]+g[n][1])%mod<<endl;
    return 0;
}