#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,m,k,x,y,ans,tmp;
int f[2502][2502],ff[2502][2502];
int a[2502];
bool v[2502];
void dfs(int x,int t,int tmp){
    if(t==5){
        if(ff[x][1]<=k) ans=max(ans,tmp);
        return;
    }
    for(int i=2;i<=n;++i){
        if(!v[i]&&ff[x][i]<=k){
            v[i]=1;
            dfs(i,t+1,tmp+a[i]);
            v[i]=0;
        }
    }
}
signed main()
{
    cin>>n>>m>>k;
    for(int i=2;i<=n;++i) cin>>a[i];
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            ff[i][j]=10000000;
        }
    }
    //sort(a+2,a+n+1,cmp);
    for(int i=0;i<m;++i){
        cin>>x>>y;
        f[x][y]=f[y][x]=1;
        ff[x][y]=ff[y][x]=0;
    }
    if(k==0){
        dfs(1,1,0);
        cout<<ans<<endl;
        return 0;
    }
    for(int kk=1;kk<=n;++kk){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(f[i][j]==1||f[i][kk]==0||f[kk][j]==0) continue;
                f[i][j]=f[j][i]=2;
                ff[j][i]=ff[i][j]=min(ff[i][j],ff[i][kk]+1+ff[kk][j]);
            }
        }
    }
    dfs(1,1,0);
    cout<<ans<<endl;
    return 0;
}