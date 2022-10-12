#include<iostream>
#include<queue>
using namespace std;
int n,m,x,y;
char a[2010][2010];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
struct node{
    int x,y,num;
};
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i]+1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]=='m'){
                x=i;y=j;
                break;
            }
        }
        if(x) break;
    }
    node p;
    int nx,ny;
    queue<node> q;
    q.push({x,y,0});
    a[x][y]='#';
    int ans=999999999;
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            nx=p.x+dx[i];
            ny=p.y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m) continue;
            if(a[nx][ny]=='d'){
                ans=min(ans,p.num+1);
                continue;
            }
            if(a[nx][ny]=='.'){
                q.push({nx,ny,p.num+1});
                a[nx][ny]='#';
            }
        }
    }
    if(ans!=999999999) cout<<ans<<endl;
    else cout<<"No Way!"<<endl;
    return 0;
}