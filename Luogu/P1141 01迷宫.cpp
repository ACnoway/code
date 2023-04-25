#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,m,cnt;
int a[1003][1003],vis[1003][1003];
int ans[1000006];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
struct node{
    int x, y;
};
int bfs(int x,int y,int d){
    queue<node> q;
    q.push({x,y});
    int nx,ny;
    node p;
    int ans=1;
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            nx=p.x+dx[i];
            ny=p.y+dy[i];
            if(nx>0&&nx<=n&&ny>0&&ny<=n&&a[p.x][p.y]+a[nx][ny]==1&&vis[nx][ny]!=d){
                q.push({nx,ny});
                vis[nx][ny]=d;
                ans++;
            }
        }
        vis[p.x][p.y]=d;
    }
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            scanf("%1d",&a[i][j]);
    cnt=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(vis[i][j]==0){
                ans[cnt]=bfs(i,j,cnt);
                ++cnt;
            }
        }
    }
    int x,y;
    for(int i=0;i<m;++i){
        cin>>x>>y;
        cout<<ans[vis[x][y]]<<endl;
    }
    return 0;
}