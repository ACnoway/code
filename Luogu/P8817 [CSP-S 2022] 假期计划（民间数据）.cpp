#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,m,k,x,y,ans,tmp;
int f[2502][2502];
bool v[2502];
struct node{
    int p,v;
}a[100005];
bool cmp(node a,node b){
    return a.v>b.v;
}
void dfs(int x,int t,int tmp){
    if(t==5){
        if(f[a[x].p][1]<=k) ans=max(ans,tmp);
        return;
    }
    for(int i=2;i<=n;++i){
        if(!v[i]&&f[a[x].p][a[i].p]<=k){
            v[i]=1;
            dfs(i,t+1,tmp+a[i].v);
            v[i]=0;
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    for(int i=2;i<=n;++i) cin>>a[i].v,a[i].p=i;
    a[1].p=1;
    sort(a+2,a+n+1,cmp);
    for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) f[i][j]=1047483647;
    for(int i=0;i<m;++i){
        cin>>x>>y;
        f[x][y]=f[y][x]=1;
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) cout<<f[i][j]<<' ';
        cout<<endl;
    }
    dfs(1,1,0);
    cout<<ans<<endl;
    return 0;
}