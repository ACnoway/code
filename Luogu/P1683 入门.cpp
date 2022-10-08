#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,m;
char a[30][30];
typedef pair<int,int> pii;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]+1;
    }
    int x=0,y=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]=='@'){
                x=i;
                y=j;
                break;
            }
        }
        if(x) break;
    }
    queue<pii> q;
    q.push({x,y});
    int nx,ny;
    pii p;
    int ans=1;
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            nx=p.first+dx[i];
            ny=p.second+dy[i];
            if(nx>0&&nx<=n&&ny>0&&ny<=m&&a[nx][ny]=='.'){
                q.push({nx,ny});
                ans++;
                a[nx][ny]='#';
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}