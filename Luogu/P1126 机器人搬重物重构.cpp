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
int n,m,xa,ya,xb,yb,face;
int a[55][55];
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int ck[4][2]={{0,0},{1,0},{0,1},{1,1}};
char facest,way[4]={'N','E','S','W'};
bool v[55][55][5];
struct node{
    int x,y,num,fa;
};
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) cin>>a[i][j];
    }
    cin>>xa>>ya>>xb>>yb>>facest;
    for(int i=0;i<4;++i) if(way[i]==facest) face=i;
    
    return 0;
}