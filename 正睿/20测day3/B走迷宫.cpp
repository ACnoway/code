#include<iostream>
#include<cstdlib>
using namespace std;
int n,m,ans;
int a[1003][1003],f[1003][1003];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool v[1003][1003];
typedef pair<int,int> pii;
const int P=1000000007;
int dfs(int x,int y,int t){
    v[x][y]=1;
    if(f[x][y]) return f[x][y]%P;
    bool flag=0;
    int nx,ny;
    for(int i=0;i<4;++i){
        nx=x+dx[i];
        ny=y+dy[i];
        if(a[nx][ny]-a[x][y]==2){
            flag=1;
            f[x][y]=(f[x][y]%P+dfs(nx,ny,t+1)%P)%P;
        }
    }
    if(!flag) return (int)(t>=4);
    else return f[x][y]%P;
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
            ans=(ans%P+dfs(i,j,1)%P)%P;
        }
    }
    cout<<ans<<endl;
    return 0;
}