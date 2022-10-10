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
int l,r,c,x,y,z;
int dx[6]={1,0,-1,0,0,0},dy[6]={0,1,0,-1,0,0},dz[6]={0,0,0,0,1,-1};
char a[30][30][30];
struct node{
    int x,y,z,sum;
};
int main()
{
    cin>>l>>r>>c;
    for(int i=1;i<=l;++i){
        for(int j=1;j<=r;++j) cin>>a[i][j]+1;
    }
    for(int i=1;i<=l;++i){
        for(int j=1;j<=r;++j){
            for(int k=1;k<=c;++k){
                if(a[i][j][k]=='S'){
                    z=i;x=j;y=k;
                    break;
                }
            }
            if(z) break;
        }
        if(z) break;
    }
    node p;
    queue<node> q;
    int nx,ny,nz;
    q.push({x,y,z,0});
    a[z][x][y]='#';
    int ans=999999999;
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int i=0;i<6;++i){
            nx=p.x+dx[i];
            ny=p.y+dy[i];
            nz=p.z+dz[i];
            if(a[nz][nx][ny]=='E'){
                ans=min(ans,p.sum+1);
                continue;
            }
            if(a[nz][nx][ny]=='.'){
                q.push({nx,ny,nz,p.sum+1});
                a[nz][nx][ny]='#';
            }
        }
    }
    if(ans!=999999999) cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
    else cout<<"Trapped!"<<endl;
    return 0;
}