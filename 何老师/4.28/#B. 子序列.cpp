#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
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
const int N=50;
int n,m;
int a[N];
int f[2][1000010];
void dfs(int x,int r,int sum,int d){
    if(x>r){
        f[d][++f[d][0]]=sum%m;
        return;
    }
    dfs(x+1,r,sum,d);
    dfs(x+1,r,sum+a[x],d);
}
signed main()
{
    n=read(); m=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int mid=n>>1;
    dfs(1,mid,0,0);
    dfs(mid+1,n,0,1);
    sort(f[0]+1,f[0]+f[0][0]+1);
    sort(f[1]+1,f[1]+f[1][0]+1);
    int ans=0,j=f[1][0];
    for(int i=1;i<=f[0][0];++i){
        while(f[0][i]+f[1][j]>=m&&j>1){
            --j;
        }
        ans=max(ans,max((f[0][i]+f[1][f[1][0]])%m,(f[0][i]+f[1][j])%m));
    }
    cout<<ans<<endl;
    return 0;
}