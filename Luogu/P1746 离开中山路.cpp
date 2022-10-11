#include<iostream>
#include<queue>
using namespace std;
int n,x1,y1,x2,y2;
char a[1010][1010];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
struct node{
    int x,y,num;
};
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i]+1;
    cin>>x1>>y1>>x2>>y2;
    node p;
    int nx,ny;
    queue<node> q;
    q.push({x1,y1,0});
    a[x1][y1]='1';
    int ans=999999999;
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            nx=p.x+dx[i];
            ny=p.y+dy[i];
            if(nx<1||nx>n||ny<1||ny>n) continue;
            if(nx==x2&&ny==y2){
                ans=min(ans,p.num+1);
                continue;
            }
            if(a[nx][ny]=='0'){
                q.push({nx,ny,p.num+1});
                a[nx][ny]='1';
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}