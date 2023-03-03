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
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int maxn=100005,B=52;
int n,ans;
int cf[maxn];
int f[B],tmp[B];
signed main()
{
    n=read();
    for(int i=1;i<=n;++i) cf[i]=read();
    for(int i=1;i<=n;++i){
        cf[i]-=read();
    }
    for(int i=n;i;--i){
        cf[i]-=cf[i-1];
    }
    for(int i=1;i<B;++i) f[i]=1e9;
    int jia,jian;
    for(int i=1;i<=n;++i){
        cf[i]=(cf[i]+100)%4;
        jia=(4-cf[i])%4;
        jian=cf[i];
        for(int j=0;j<B;++j) tmp[j]=1e9;
        for(int j=0;j<B;++j){
            if(j-jia>=0){
                tmp[j]=min(tmp[j],f[j-jia]);
            }
            if(j+jian<B){
                tmp[j]=min(tmp[j],f[j+jian]+jian);
            }
        }
        for(int j=0;j<B;++j) f[j]=tmp[j];
    }
    int ans=1e9;
    for(int i=0;i<B;++i){
        ans=min(ans,i+f[i]);
    }
    write(ans);
    putchar('\n');
    return 0;
}