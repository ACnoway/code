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
int n,m,ans,f[(1<<10)][(1<<10)][3],a[105],sum[(1<<10)];
char x;
int getsum(int S){
    int tot=0;
    while(S){if(S&1) ++tot;S>>=1;}
    return tot;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>x;
            a[i]<<=1;
            a[i]+=(x=='H'?1:0);
        }
    }
    for(int i=0;i<(1<<m);++i)
        sum[i]=getsum(i);
    for(int S=0;S<(1<<m);++S)
        if(!(S&a[0]||(S&(S<<1))||(S&(S<<2))))
            f[0][S][0]=sum[S];
    for(int L=0;L<(1<<m);++L){
        for(int S=0;S<(1<<m);++S){
            if(!(L&S||L&a[0]||S&a[1]||(L&(L<<1))||(L&(L<<2))||(S&(S<<1))||(S&(S<<2))))
                f[L][S][1]=sum[S]+sum[L];
        }
    }
    for(int i=2;i<n;++i){
        for(int L=0;L<(1<<m);++L){
            if(L&a[i-1]||(L&(L<<1))||(L&(L<<2))) continue;
            for(int S=0;S<(1<<m);++S){
                if(S&a[i]||L&S||(S&(S<<1))||(S&(S<<2))) continue;
                for(int FL=0;FL<(1<<m);++FL){
                    if(FL&L||FL&S||FL&a[i-2]||(FL&(FL<<1))||(FL&(FL<<2))) continue;
                    f[L][S][i%3]=max(f[L][S][i%3],f[FL][L][(i-1)%3]+sum[S]);
                }
            }
        }
    }
    for(int L=0;L<(1<<m);++L){
        for(int S=0;S<(1<<m);++S){
            ans=max(ans,f[L][S][(n-1)%3]);
        }
    }
    cout<<ans<<endl;
    return 0;
}