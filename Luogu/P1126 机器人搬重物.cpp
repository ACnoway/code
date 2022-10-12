#include<iostream>
#include<cstdio>
#include<queue>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,m,x1,y1,x2,y2;
int a[55][55];
//0东右 1南下 2西左 3北上
int face;
int cf[3]={1,2,-1},dx[4][3]={{1,2,3},{0,0,0},{-1,-2,-3},{0,0,0}},dy[4][3]={{0,0,0},{1,2,3},{0,0,0},{-1,-2,-3}};
int near[4][2]={{0,0},{1,0},{0,1},{1,1}};
bool v[55][55][5];
int abs(int a){ return (a>0?a:-a);}
struct node{
    int x,y,num,fa;
};
inline bool check(int x,int y){
    for(int i=0;i<4;++i){
        if(x+near[i][0]<1||x+near[i][0]>n||y+near[i][1]<1||y+near[i][1]>m) return 1;
        if(a[x+near[i][0]][y+near[i][1]]){
            return 1;
        }
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
            if(a[i][j])
                for(int k=0;k<4;++k)
                    v[i][j][k]=a[i][j];
        }
    }
    cin>>x1>>y1>>x2>>y2;
    char facest;
    cin>>facest;
    switch (facest)
    {
    case 'E':
        face=0;
        break;
    case 'S':
        face=1;
        break;
    case 'W':
        face=2;
        break;
    case 'N':
        face=3;
        break;
    }
    queue<node> q;
    node p;
    int nx,ny,cx,cy;
    int ans=999999999;
    bool flag=1;
    q.push({x1,y1,0,face});
    v[x1][y1][face]=1;
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int i=0;i<3;++i){
            nx=p.x+dx[p.fa][i];
            ny=p.y+dy[p.fa][i];
            //if(check(nx,ny)) continue;
            if(nx!=p.x){
                flag=1;
                for(int j=min(p.x,nx);j<=max(p.x,nx);++j){
                    if(check(j,ny)){
                        flag=0;
                        break;
                    }
                }
                if(!flag) continue;
            }
            else{
                flag=1;
                for(int j=min(p.y,ny);j<=max(p.y,ny);++j){
                    if(check(nx,j)){
                        flag=0;
                        break;
                    }
                }
                if(!flag) continue;
            }
            if(nx==x2&&ny==y2){
                ans=min(ans,p.num+1);
                continue;
            }
            if(!v[nx][ny][p.fa]){
                if(check(nx,ny)) continue;
                q.push({nx,ny,p.num+1,p.fa});
                v[nx][ny][p.fa]=1;
            }
        }
        for(int i=0;i<2;++i){
            face=(p.fa+cf[i]+4)%4;
            if(!v[p.x][p.y][face]){
                q.push({p.x,p.y,p.num+abs(cf[i]),face});
                v[p.x][p.y][face]=1;
            }
        }
    }
    if(ans!=999999999) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}