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
int n,m,l,r;
int f[50004];
int a[32][50004];
string _in;
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>_in;
        for(int j=0;j<m;++j){
            a[i][j+1]=_in[j]-'0';
            a[i][j+1]+=a[i-1][j+1];
        }
    }
    cin>>l>>r;
    long long ans=0;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            long long x=0,y=0;
            for(int k=1;k<=m;++k){
                f[k]=f[k-1]+a[j][k]-a[i-1][k];
            }
            for(int k=1;k<=m;++k){
                while(f[k]-f[x]>=l&&x<k) ++x;
                while(f[k]-f[y]>r&&y<k) ++y;
                ans+=x-y;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}