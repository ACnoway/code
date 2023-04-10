#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int N=1000006,mod=998244353;
int n,m,k;
int jc[N],jcinv[N];
int ksm(int a,int b){
    a%=mod;
    int res=1;
    while(b){
        if(b&1) res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}
void init(int u){
    jc[1]=jcinv[1]=1;
    for(int i=2;i<=u;++i){
        jc[i]=1ll*jc[i-1]*i%mod;
        jcinv[i]=1ll*jcinv[i-1]*ksm(i,mod-2)%mod;
    }
}
int C(int x,int y){
    if(x<y) return 0;
    if(y==0||x==y) return 1;
    return 1ll*jc[x]*jcinv[x-y]%mod*jcinv[y]%mod;
}
int calc(int i,int j,int k){
    int cnt=i*j;
    if(cnt==k) return 1;
    int all=C(cnt,k);
    int a=(1ll*C(cnt-i,k)*2%mod+1ll*C(cnt-j,k)*2%mod)%mod;
    int b=(1ll*C(cnt-i-j+1,k)*4%mod+C(cnt-2*i,k)+C(cnt-2*j,k))%mod;
    int c=(1ll*C(cnt-2*i-j+2,k)*2%mod+1ll*C(cnt-2*j-i+2,k)*2%mod)%mod;
    int d=C(cnt-2*i-2*j+4,k);
    return ((1ll*all-a+b-c+d)%mod+mod)%mod;
}
int main()
{
    n=read();
    m=read();
    k=read();
    if(k==1){
        cout<<1<<endl;
        return 0;
    }
    init(n*m);
    int all=0,p=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(i*j<k) continue;
            int cnt=1ll*calc(i,j,k)*(n-i+1)%mod*(m-j+1)%mod;
            p=(p+cnt)%mod;
            all=(all+1ll*cnt*i%mod*j%mod)%mod;
        }
    }
    cout<<1ll*all*ksm(p,mod-2)%mod<<endl;
    return 0;
}