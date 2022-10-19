#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#ifdef ONLINE_JUDGE
#define debug(x)
#else
#define debug(x) cout<<' '<<#x<<'='<<x<<endl;
#endif
using namespace std;
int n,m;
bool ans=0;
char a[1003][1003],b[1003][1003];
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={0,-1,1,-1,1,0,-1,1};
bool ck(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) if(a[i][j]!=b[i][j]) return 0;
    }
    ans=1;
    return 1;
}
void dfs(int x,int y){
    if(ck()||ans) return;
    if(x<2||x>=n||y<2||y>=m) return;
    int nx=x+1,ny=y;
    if(nx==n) ny++,nx=2;
    dfs(nx,ny);
    if(x<2||x>=n||y<2||y>=m) return;
    for(int i=0;i<8;++i){
        b[x+dx[i]][y+dy[i]]='#';
        if(a[x+dx[i]][y+dy[i]]=='.') return;
    }
    dfs(nx,ny);
    for(int i=0;i<8;++i){
        b[x+dx[i]][y+dy[i]]='.';
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i]+1;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) b[i][j]='.';
    dfs(2,2);
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}