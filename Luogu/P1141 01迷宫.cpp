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
int a[1003][1003],b[1003][1003];
int an[1000006];
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
            if(nx>0&&nx<=n&&ny>0&&ny<=n&&b[p.x][p.y]+b[nx][ny]==1&&a[nx][ny]!=d){
                q.push({nx,ny});
                a[nx][ny]=d;
                ans++;
            }
        }
        a[p.x][p.y]=d;
    }
    return ans;
}
int main()
{
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) scanf("%1d",&a[i][j]),b[i][j]=a[i][j];
    cnt=-1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(a[i][j]>=0){
                ans=bfs(i,j,cnt);
                an[0-cnt--]=ans;
            }
        }
    }
    int xx,yy;
    for(int i=0;i<m;++i){
        cin>>xx>>yy;
        cout<<an[0-a[xx][yy]]<<endl;
    }
    return 0;
}