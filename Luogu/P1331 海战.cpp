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
char a[1003][1003];
int ck[4][2]={{0,0},{1,0},{0,1},{1,1}};
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y){
    a[x][y]='.';
    for(int i=0;i<4;++i){
        if(x+dx[i]>0&&x+dx[i]<=n&&y+dy[i]>0&&y+dy[i]<=m&&a[x+dx[i]][y+dy[i]]=='#') dfs(x+dx[i],y+dy[i]);
    }
}
int main()
{
    for(int i=0;i<4;++i) {debug(ck[i][0]);debug(ck[i][1]);}
    cin>>n>>m;
    int tmp;
    for(int i=1;i<=n;++i) cin>>a[i]+1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            tmp=0;
            for(int k=0;k<4;++k){
                if(a[i+ck[k][0]][j+ck[k][1]]=='#') tmp++;
            }
            if(tmp==3){
                cout<<"Bad placement."<<endl;
                return 0;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]=='#'){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<"There are "<<ans<<" ships."<<endl;
    return 0;
}