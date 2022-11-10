#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
int n,m,ans;
int a[1003][1003];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool v[1003][1003];
typedef pair<int,int> pii;
void bfs(int x,int y){
	queue<pii> q;
    pii p;
    int nx,ny;
    q.push({x,y});
    while(!q.empty()){
        p=q.front();
        q.pop();
        
    }
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<=n;++i){
		a[i][0]=a[0][i]=2000006;
		a[i][n+1]=a[n+1][i]=2000006;
	}	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) cin>>a[i][j];
	}
	bool flag=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(v[i][j]) continue;
			flag=1;
			for(int k=0;k<4;++k){
				if(a[i][j]-a[i+dx[k]][j+dy[k]]==2){
					flag=0;
					v[i][j]=1;
					break;
				}
			}
			if(!flag) continue;
			bfs(i,j);
		}
	}
	return 0;
}
