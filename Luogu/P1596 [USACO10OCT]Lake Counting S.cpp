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
int n,m;
char a[103][103];
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={0,-1,1,-1,1,0,-1,1};
void dfs(int x,int y){
    a[x][y]='.';
    for(int i=0;i<8;++i){
        if(x+dx[i]<1||x+dx[i]>n||y+dy[i]<1||y+dy[i]>m||a[x+dx[i]][y+dy[i]]=='.') continue;
        dfs(x+dx[i],y+dy[i]);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i]+1;
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]=='W'){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}