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
int n,m;
string tmp;
int a[105][105];
int x[4]={1,0,-1,0},y[4]={0,1,0,-1};
struct node{
    int x,y;
};
void bfs(int xx,int yy){
    queue<node> q;
    q.push({xx,yy});
    int nx,ny;
    node b;
    while(!q.empty()){
        b=q.front();
        nx=b.x;ny=b.y;
        q.pop();
        a[nx][ny]=0;
        for(int i=0;i<4;++i){
            nx=b.x+x[i];
            ny=b.y+y[i];
            if(a[nx][ny]) q.push({nx,ny}),a[nx][ny]=0;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>tmp;
        for(int j=1;j<=m;++j){
            a[i][j]=tmp[j-1]-'0';
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]) ans++,bfs(i,j);
        }
    }
    cout<<ans<<endl;
    return 0;
}