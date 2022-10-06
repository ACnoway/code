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
int n,m,x,y;
int a[404][404];
int dx[2][2]={{-2,2},{0,0}},dy[2][2]={{0,0},{-2,2}};
int dx1[2][2]={{0,0},{-1,1}},dy1[2][2]={{-1,1},{0,0}};
struct node{
    int x,y;
};

int main()
{
    cin>>n>>m>>x>>y;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j) a[i][j]=-1;
    }
    queue<node> q;
    q.push({x,y});
    a[x][y]=0;
    node p;
    int nx,ny;
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int i=0;i<2;++i){
            for(int j=0;j<2;++j){
                for(int k=0;k<2;++k){
                    nx=p.x+dx[i][j]+dx1[i][k];
                    ny=p.y+dy[i][j]+dy1[i][k];
                    debug(nx);debug(ny);
                    if(nx>0&&nx<=n&&ny>0&&ny<=m&&a[nx][ny]==-1){
                        a[nx][ny]=a[p.x][p.y]+1;
                        q.push({nx,ny});
                    }
                    if(nx>0&&nx<=n&&ny>0&&ny<=m) a[nx][ny]=min(a[nx][ny],a[p.x][p.y]+1);
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cout<<a[i][j]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}