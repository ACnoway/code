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
inline bool check(int x,int y){
    for(int i=0;i<4;++i){
        if(x+ck[i][0]<1||x+ck[i][0]>n||y+ck[i][1]<1||y+ck[i][1]>m) return 0;
        if(a[x+ck[i][0]][y+ck[i][1]]){
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) cin>>a[i][j];
    }
    cin>>xa>>ya>>xb>>yb>>facest;
    for(int i=0;i<4;++i) if(way[i]==facest) face=i;
    queue<node> q;
    node p;
    int nx,ny;
    q.push({xa,ya,0,face});
    v[xa][ya][face]=1;
    int ans=2147483647;
    if(!check(xa,ya)){
        cout<<-1<<endl;
        return 0;
    }
    while(!q.empty()){
        p=q.front();
        
    }
    return 0;
}