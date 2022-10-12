#include<iostream>
#include<queue>
using namespace std;
int n,m,gr,lz,x,y;
int a[2010][2010],b[2010][2010];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
struct node{
    int x,y,num;
};
int main()
{
    cin>>n>>m>>gr>>lz;
    node p;
    int nx,ny;
    queue<node> q;
    int ans=999999999;
    for(int i=1;i<=gr;++i){
        cin>>x>>y;
        q.push({x,y,0});
        a[x][y]=1;
    }
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            nx=p.x+dx[i];
            ny=p.y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m) continue;
            if(!a[nx][ny]){
                q.push({nx,ny,p.num+1});
                a[nx][ny]=1;
                b[nx][ny]=p.num+1;
            }
        }
    }
    for(int i=1;i<=lz;++i){
        cin>>x>>y;
        cout<<b[x][y]<<endl;
    }
    return 0;
}