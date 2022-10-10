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
int x,y;
int rx[2][2]={{-2,2},{0,0}},ry[2][2]={{0,0},{-2,2}};
int rx1[2][2]={{0,0},{-1,1}},ry1[2][2]={{-1,1},{0,0}};
int tx[2]={-2,2},ty[2]={-2,2};
bool v[30][30];
struct node{
    int x,y,num;
};
int main()
{
    for(int tt=0;tt<2;++tt){
        cin>>x>>y;
        for(int i=0;i<30;++i) for(int j=0;j<30;++j) v[i][j]=0;
        for(int i=0;i<30;++i) v[0][i]=v[i][0]=1;
        int ans=999999999;
        node p;
        int nx,ny;
        queue<node> q;
        q.push({x,y,0});
        while(!q.empty()){
            p=q.front();
            q.pop();
            for(int i=0;i<2;++i){
                for(int j=0;j<2;++j){
                    for(int k=0;k<2;++k){
                        nx=p.x+rx[i][j]+rx1[i][k];
                        ny=p.y+ry[i][j]+ry1[i][k];
                        if(nx<1||nx>20||ny<1||ny>20) continue;
                        if(nx==1&&ny==1){
                            ans=min(ans,p.num+1);
                            continue;
                        }
                        if(!v[nx][ny]){
                            q.push({nx,ny,p.num+1});
                            v[nx][ny]=1;
                        }
                    }
                }
            }
            for(int i=0;i<2;++i){
                for(int j=0;j<2;++j){
                    nx=p.x+tx[i];
                    ny=p.y+ty[j];
                    if(nx<1||nx>20||ny<1||ny>20) continue;
                    if(nx==1&&ny==1){
                        ans=min(ans,p.num+1);
                        continue;
                    }
                    if(!v[nx][ny]){
                        q.push({nx,ny,p.num+1});
                        v[nx][ny]=1;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}