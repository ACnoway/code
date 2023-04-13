#include<bits/stdc++.h>
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
const int N=50,mod=1000000007;
int ans,n;
int a[N];
int f[N][N][N*N][2];
signed main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    if(a[1]!=-1) f[1][a[1]][a[1]][0]=1;
    else for(int i=0;i<=40;++i) f[1][i][i][0]=1;
    for(int i=2;i<=n;++i){
        int l=0,r=40;
        if(a[i]!=-1) l=r=a[i];
        for(int p=l;p<=r;++p)
            //如果a[i]是-1就枚举它的可能性
            for(int j=p*(i-1);j<=2023;++j){
                for(int k=0;k<=p;++k)
                    f[i][p][j+p][0]=(f[i][p][j+p][0]+f[i-1][k][j][0]+f[i-1][k][j][1])%mod;
                for(int k=p+1;k<=40;++k)
                    f[i][p][j+p][1]=(f[i][p][j+p][1]+f[i-1][k][j][0])%mod;
            }
    }
    for(int i=0;i<=40;++i){
        for(int j=0;j<=40*n;++j){
            ans=(ans+f[n][i][j][0]+f[n][i][j][1])%mod;
        }
    }
    printf("%d\n",ans);
    return 0;
}
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO zyb txdy Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO xhx txde Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%
//%%%%%%%% stO lxy tqdl Orz %%%%%%%%