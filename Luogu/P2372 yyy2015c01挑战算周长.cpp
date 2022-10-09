#include<iostream>
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cstring>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,m,x,y;
char a[30][30];
int dx[8]={-1,0,1,0,-1,1,-1,1},dy[8]={0,-1,0,1,-1,-1,1,1};
typedef pair<int,int> pii;
int main()
{
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;++i) cin>>a[i]+1;
    int ans=0;
    queue<pii> q;
    pii p;
    int nx,ny;
    a[x][y]='Z';
    q.push({x,y});
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int i=0;i<4;++i) if(a[p.first+dx[i]][p.second+dy[i]]!='X'&&a[p.first+dx[i]][p.second+dy[i]]!='Z') ans++;
        for(int i=0;i<8;++i){
            nx=p.first+dx[i];
            ny=p.second+dy[i];
            if(a[nx][ny]=='X'){
                q.push({nx,ny});
                a[nx][ny]='Z';
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}